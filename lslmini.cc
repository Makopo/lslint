#include <stdio.h>
#include <string>
#include "lslmini.hh"
#include "logger.hh"

// Workaround for makeless builds
#ifndef VERSION
#define VERSION "0.4.3-xh"
#endif

extern FILE *yyin;
extern char *builtins_file;
//extern int yynerrs;
int yynwarns = 0;                // not defined by flex but named for consistency

int yyparse(void*);
//int yyerror(const char *fmt, ... );
//int yywarning(const char *fmt, ...);


YYLTYPE LLASTNode::glloc = {0,0,0,0};

const char *DEPRECATED_FUNCTIONS[][2] = {
   {"llSoundPreload",    "llPreloadSound"},
   {"llSound",           "llPlaySound, llLoopSound, or llTriggerSound"},
   {"llMakeExplosion",   "llParticleSystem"},
   {"llMakeFire",        "llParticleSystem"},
   {"llMakeFountain",    "llParticleSystem"},
   {"llMakeSmoke",       "llParticleSystem"},
   {"llRemoteLoadScript","llRemoteLoadScriptPin and llSetRemoteScriptAccessPin"},
   {"llPointAt",         NULL},
   {"llStopPointAt",     NULL},
   {NULL,                NULL},
};

int walklevel = 0;

void print_walk( char *str ) {
   int i;
   for ( i = 0; i < walklevel ; i++ )
      printf("  ");

   printf("%s\n", str);
}

void do_walk( LLASTNode *node ) {
   walklevel++;
   node->walk();
   walklevel--;
}


void LLASTNode::add_children( int num, va_list ap ) {
   LLASTNode *node;
   for ( ; num--; ) {
      node = va_arg(ap, LLASTNode*);
      if ( node == NULL )
         node = new LLASTNullNode();
      push_child( node );
   }
}

void LLASTNode::walk() {
   LLASTNode *child = children;
   char buf[256];
   sprintf(buf, "%s [%s] (cv=%s) (%d,%d)", get_node_name(), type ? type->get_node_name() : NULL, constant_value ? constant_value->get_node_name() : NULL, lloc.first_line, lloc.first_column );
   print_walk(buf);
   //print_walk(get_node_name());
   if ( child == NULL ) return;
   if ( child->get_prev() != NULL ) {
      printf("first child %s has non-null prev %s\n", child->get_node_name(), child->get_prev()->get_node_name() );
      exit(1);
   }
   while ( child ) {
      do_walk(child);
      child = child->get_next();
   }
}

// Lookup a symbol, propogating up the tree until it is found.
LLScriptSymbol *LLASTNode::lookup_symbol(char *name, LLSymbolType type, bool is_case_sensitive) {
   LLScriptSymbol *sym = NULL;

   // If we have a symbol table of our own, look for it there
   if ( symbol_table )
      sym = symbol_table->lookup( name, type, is_case_sensitive );

   // If we have no symbol table, or it wasn't in it, but we have a parent, ask them
   if ( sym == NULL && parent )
      sym = parent->lookup_symbol( name, type, is_case_sensitive );

   return sym;
}

// Define a symbol, propogating up the tree to the nearest scope level.
void LLASTNode::define_symbol(LLScriptSymbol *symbol) {

   // If we have a symbol table, define it there
   if ( symbol_table ) {
      LLScriptSymbol *shadow;

      DEBUG( LOG_DEBUG_SPAM, NULL, "symbol definition caught in %s\n", get_node_name() );

      // Check if already defined
      shadow = symbol_table->lookup( symbol->get_name() );
      if ( shadow ) {
         if (shadow->get_sub_type() == SYM_BUILTIN) {
            ERROR( IN(symbol), E_DUPLICATE_DECLARATION_EVENT, symbol->get_name() );
         }
         else {
            ERROR( IN(symbol), E_DUPLICATE_DECLARATION, symbol->get_name(), shadow->get_lloc()->first_line, shadow->get_lloc()->first_column );
         }
      } else {
         symbol_table->define(symbol);

         // Check for shadowed declarations
         if ( parent ) {
            shadow = parent->lookup_symbol(symbol->get_name(), symbol->get_symbol_type());
            if ( shadow!= NULL ) {
               if (shadow->get_sub_type() == SYM_BUILTIN) {
                  ERROR( IN(symbol), E_SHADOW_CONSTANT, symbol->get_name());
               }
               else {
                  ERROR( IN(symbol), W_SHADOW_DECLARATION, symbol->get_name(), LINECOL(shadow->get_lloc()) );
               }
            }
         }
      }

      // Otherwise, ask our parent to define it  
   } else if ( parent ) {

      parent->define_symbol(symbol);

      // .. but if we don't have a parent, we're in trouble.  
   } else {

      throw "nowhere to define symbol!";

   }
}

// Define any symbols we have, and ask our children to
void LLASTNode::collect_symbols() {
   LLASTNode *child = children;
   define_symbols();
   while ( child ) {
      child->collect_symbols();
      child = child->get_next();
   }
}

void LLASTNode::define_symbols() {
   /* nothing */
}

void LLScriptDeclaration::define_symbols() {
   LLScriptIdentifier *identifier = (LLScriptIdentifier *)get_children();
   identifier->set_symbol( new LLScriptSymbol(identifier->get_name(), identifier->get_type(), SYM_VARIABLE, SYM_LOCAL, get_lloc()) );
   define_symbol(identifier->get_symbol());
}

void LLScriptGlobalVariable::define_symbols() {
   LLScriptIdentifier *identifier = (LLScriptIdentifier *)get_children();
   identifier->set_symbol( new LLScriptSymbol(identifier->get_name(), identifier->get_type(), SYM_VARIABLE, SYM_GLOBAL, get_lloc()));
   define_symbol(identifier->get_symbol());

   // if it's initialized, set it's constant value
   if ( get_child(1)->get_node_type() == NODE_SIMPLE_ASSIGNABLE ) 
      identifier->get_symbol()->set_constant_value( get_child(1)->get_child(0)->get_constant_value() );
}

void LLScriptScript::define_symbols() {
   define_builtins();
}

void LLScriptState::define_symbols() {
   LLASTNode             *node = get_children();
   LLScriptIdentifier    *identifier;

   if ( node->get_node_type() == NODE_NULL ) // null identifier = default state, nothing to define
      return;

   identifier = (LLScriptIdentifier *)node;
   identifier->set_symbol( new LLScriptSymbol(identifier->get_name(), identifier->get_type(), SYM_STATE, SYM_GLOBAL, identifier->get_lloc()) );    
   define_symbol( identifier->get_symbol() );
}

void LLScriptGlobalFunction::define_symbols() {
   LLScriptIdentifier    *identifier = (LLScriptIdentifier *)get_child(0);

   // define function in parent scope since we have our own
   identifier->set_symbol(
         new LLScriptSymbol( identifier->get_name(), identifier->get_type(), SYM_FUNCTION, SYM_GLOBAL, get_lloc(), (LLScriptFunctionDec*)get_child(1) )
         );
   get_parent()->define_symbol(identifier->get_symbol());
}

void LLScriptFunctionDec::define_symbols() {
   LLScriptIdentifier    *identifier;
   LLASTNode             *node = get_children();
   while (node) {
      identifier = (LLScriptIdentifier *)node;
      identifier->set_symbol( new LLScriptSymbol( identifier->get_name(), identifier->get_type(), SYM_VARIABLE, SYM_FUNCTION_PARAMETER, node->get_lloc() ) );
      define_symbol( identifier->get_symbol() );
      node = node->get_next();
   }
}

void LLScriptEventDec::define_symbols() {
   LLScriptIdentifier    *identifier;
   LLASTNode             *node = get_children();
   while (node) {
      identifier = (LLScriptIdentifier *)node;
      identifier->set_symbol( new LLScriptSymbol( identifier->get_name(), identifier->get_type(), SYM_VARIABLE, SYM_EVENT_PARAMETER, node->get_lloc() ) );
      define_symbol( identifier->get_symbol() );
      node = node->get_next();
   }
}

void LLScriptEvent::define_symbols() {
   LLScriptIdentifier    *identifier;
   LLASTNode             *node = get_children();
   while (node) {
      identifier = (LLScriptIdentifier *)node;
      identifier->set_symbol( new LLScriptSymbol( identifier->get_name(), identifier->get_type(), SYM_VARIABLE, SYM_EVENT_PARAMETER, node->get_lloc() ) );
      define_symbol( identifier->get_symbol() );
      node = node->get_next();
   }
}

void LLScriptLabel::define_symbols() {
   LLScriptIdentifier    *identifier = (LLScriptIdentifier*)get_children();
   identifier->set_symbol( new LLScriptSymbol(identifier->get_name(), identifier->get_type(), SYM_LABEL, SYM_LOCAL, get_lloc()) );
   define_symbol( identifier->get_symbol() );
}

// walk tree post-order and propogate types
void LLASTNode::propogate_types() {
   LLASTNode             *node = get_children();
   while ( node ) {
      node->propogate_types();
      node = node->get_next();
   }

   determine_type();
}




void LLASTNode::determine_type() {
   if ( type == NULL ) type = LLScriptType::get( LST_NULL );
}

static char* operation_str(int operation) {
   static char buf[16+1];
   switch (operation) {
      case EQ:            return "==";
      case INC_OP:        return "++";
      case DEC_OP:        return "--";
      case BOOLEAN_AND:   return "&&";
      case BOOLEAN_OR:    return "||";
      case SHIFT_LEFT:    return "<<";
      case SHIFT_RIGHT:   return ">>";
      default:            
                          if ( isprint(operation) ) {
                             buf[0] = operation;
                             buf[1] = 0;
                          } else {
                             sprintf(buf, "%d", operation);
                          }
                          return buf;
   }
}

void LLScriptExpression::determine_type() {
   if ( operation == 0 ) type = get_child(0)->get_type();
   else {
      type = get_child(0)->get_type()->get_result_type( operation, get_child(1) ? get_child(1)->get_type() : NULL );
      if ( type == NULL ) {
         ERROR( HERE, E_INVALID_OPERATOR, get_child(0)->get_type()->get_node_name(), operation_str(operation), get_child(1) ? get_child(1)->get_type()->get_node_name() : "" );  
         type = get_child(0)->get_type();
      } else {
         if ( operation == '=' || operation == INC_OP || operation == DEC_OP ) {
            // unused variable // LLASTNode *last_node     = this;
            // unused variable // LLASTNode *node          = get_parent();

            // add assignment
            if ( get_child(0)->get_node_sub_type() == NODE_LVALUE_EXPRESSION && get_child(0)->get_child(0)->get_node_type() == NODE_IDENTIFIER ) {
               LLScriptIdentifier *id = (LLScriptIdentifier*)get_child(0)->get_child(0);
               if ( id->get_symbol() ) {
                  if (id->get_symbol()->get_sub_type() == SYM_BUILTIN) {
                     ERROR( HERE, E_BUILTIN_LVALUE, id->get_symbol()->get_name());
                  }
                  id->get_symbol()->add_assignment();
               }
            }
         }
      }
   }
}

/// Identifiers should have their type/symbol set by their parent node, because they don't know what
/// kind of symbol they represent by themselves. For example, this should work:
//    string test() { return "hi"; }
//    string func() {
//      integer test = 1;
//      llOwnerSay(test());
//    }
//  But if "test" looked itself up, it would think it is an integer. It's parent function
//  expression node can tell it what it needs to be before determining it's own type.
void LLScriptIdentifier::resolve_symbol(LLSymbolType symbol_type) {

   // If we already have a symbol, we don't need to look it up.
   if ( symbol != NULL ) {
      type = symbol->get_type();
      return;
   }

   // If it's a builtin, check for deprecation
   if ( symbol_type == SYM_FUNCTION ) {
      int i;
      for ( i = 0; DEPRECATED_FUNCTIONS[i][0]; ++i ) {
         if ( !strcmp(name, DEPRECATED_FUNCTIONS[i][0]) ) {
            if ( DEPRECATED_FUNCTIONS[i][1] == NULL ) {
               ERROR(HERE, E_DEPRECATED, name);
            } else {
               ERROR(HERE, E_DEPRECATED_WITH_REPLACEMENT, name, DEPRECATED_FUNCTIONS[i][1]);
            }
            symbol = NULL;
            type = TYPE(LST_ERROR);
            return;
         }
      }
   }

   // Look up the symbol with the requested type
   symbol = lookup_symbol( name, symbol_type );

   if ( symbol == NULL ) {                       // no symbol of the right type
      symbol = lookup_symbol( name, SYM_ANY );    // so try the wrong one, so we can have a more descriptive error message in that case.
      if (symbol != NULL) {
         ERROR( HERE, E_WRONG_TYPE, name,
               LLScriptSymbol::get_type_name(symbol_type),
               LLScriptSymbol::get_type_name(symbol->get_symbol_type())
              );
      } else {
         // look for typos
         // FIXME: this is mostly hacked together and unsafe (bp can overrun buffer, cur_sug can overrun suggestions)
         // maybe a better way would be to go through all the symtabs looking for names within a certain "string distance"
         char buffer[BUFFER_SIZE+1];
         char *bp;
         char *suggestions[16];
         int   cur_sug = 0;
         int   i;
         for ( i = 16; i--; )
            suggestions[i] = NULL;

         // try case insensitive
         symbol = lookup_symbol( name, SYM_ANY, false );
         if ( symbol != NULL )
            suggestions[cur_sug++] = symbol->get_name();

         if ( strstr(name, "To") ) {
            // try replacing "To" with "2"
            for (i = 0, bp = buffer; name[i]; i++) {
               if ( (name[i] == 'T' || name[i] == 't') && (name[i+1] == 'O' || name[i+1] == 'o')) {
                  *bp++ = '2'; i++;
               } else
                  *bp++ = name[i];
            }
            *bp = 0;
            symbol = lookup_symbol( buffer, SYM_ANY, false );
            if ( symbol != NULL )
               suggestions[cur_sug++] = symbol->get_name();
         }

         // try replacing "2" with "To"
         if ( strstr(name, "2") ) {
            for (i = 0, bp = buffer; name[i]; i++) {
               if ( name[i] == '2') {
                  *bp++ = 'T'; *bp++ = 'o';
               } else
                  *bp++ = name[i];
            }
            *bp = 0;
            symbol = lookup_symbol( buffer, SYM_ANY, false );
            if ( symbol != NULL )
               suggestions[cur_sug++] = symbol->get_name();
         }

         for (i = 0, buffer[0] = 0; suggestions[i] != NULL; i++ ) {
            // add comma if not first
            if ( i != 0 ) {
               strncat(buffer, ", ",         BUFFER_SIZE);
               // add "or" if not last
               if ( suggestions[i+1] == NULL )
                  strncat(buffer, "or ",        BUFFER_SIZE);
            }
            strncat(buffer, "`",            BUFFER_SIZE);
            strncat(buffer, suggestions[i], BUFFER_SIZE);
            strncat(buffer, "'",            BUFFER_SIZE);
         }
         if ( buffer[0] == 0 ) {
            ERROR( HERE, E_UNDECLARED, name );
         } else {
            ERROR( HERE, E_UNDECLARED_WITH_SUGGESTION, name, buffer );
         }
      }

      // Set our symbol to null and type to error since we don't know what they should be.
      symbol  = NULL;
      type    = TYPE(LST_ERROR);
      return;
   }

   /// If we're requesting a member, like var.x or var.y
   if ( member != NULL ) {

      // all members must be single letters
      if ( member[1] != 0 ) {
         ERROR( HERE, E_INVALID_MEMBER, name, member );
         type = TYPE(LST_ERROR);
         return;
      }

      /// Make sure it's a variable
      if ( symbol_type != SYM_VARIABLE ) {
         ERROR( HERE, E_MEMBER_NOT_VARIABLE, name, member, LLScriptSymbol::get_type_name(symbol_type));
         symbol = NULL;
         type = TYPE(LST_ERROR);
         return;
      }

      // Make sure it's a vector or quaternion. TODO: is there a better way to do this?
      switch ( symbol->get_type()->get_itype() ) {
         case LST_QUATERNION:
            if ( member[0] == 's' ) {
               type = TYPE(LST_FLOATINGPOINT);
               break;
            }
            // FALL THROUGH
         case LST_VECTOR:
            switch ( member[0] ) {
               case 'x':
               case 'y':
               case 'z':
                  type =TYPE(LST_FLOATINGPOINT);
                  break;
               default:
                  ERROR( HERE, E_INVALID_MEMBER, name, member );
                  type = TYPE(LST_ERROR);
                  break;
            }
            break;
         default:
            ERROR( HERE, E_MEMBER_WRONG_TYPE, name, member );
            type = TYPE(LST_ERROR);
            break;
      }
   } else {

      // Set our type to our symbol's type.
      type = symbol->get_type();

   }

   // Add a reference
   symbol->add_reference();

}

void LLScriptSimpleAssignable::determine_type() {
   LLASTNode *node = get_child(0);

   if ( node == NULL )
      return;

   if ( node->get_node_type() == NODE_IDENTIFIER ) {
      LLScriptIdentifier *id = (LLScriptIdentifier *) node;
      id->resolve_symbol( SYM_VARIABLE );
      type = id->get_type();
   } else if ( node->get_node_type() == NODE_CONSTANT ) {
      type = node->get_type();
   }

}

void LLScriptFunctionExpression::determine_type() {
   LLScriptIdentifier *id = (LLScriptIdentifier *) get_child(0);
   id->resolve_symbol( SYM_FUNCTION );
   type = id->get_type();

   // can't check types if function is undeclared
   if ( id->get_symbol() == NULL )
      return;

   // check argument types
   LLScriptFunctionDec       *function_decl;
   LLScriptIdentifier        *declared_param_id;
   LLScriptIdentifier        *passed_param_id;
   int                        param_num = 1;

   function_decl         = id->get_symbol()->get_function_decl();
   declared_param_id     = (LLScriptIdentifier*) function_decl->get_children();
   passed_param_id       = (LLScriptIdentifier*) get_child(1);

   while ( declared_param_id != NULL && passed_param_id != NULL ) {
      if ( !passed_param_id->get_type()->can_coerce(
               declared_param_id->get_type()) ) {
         ERROR( HERE, E_ARGUMENT_WRONG_TYPE,
               passed_param_id->get_type()->get_node_name(),
               param_num,
               id->get_name(),
               declared_param_id->get_type()->get_node_name(),
               declared_param_id->get_name()
              );
         return;
      }
      passed_param_id   = (LLScriptIdentifier*) passed_param_id->get_next();
      declared_param_id = (LLScriptIdentifier*) declared_param_id->get_next();
      ++param_num;
   }

   if ( passed_param_id != NULL ) {
      ERROR( HERE, E_TOO_MANY_ARGUMENTS, id->get_name() );
   } else if ( declared_param_id != NULL ) {
      ERROR( HERE, E_TOO_FEW_ARGUMENTS, id->get_name() );
   }

}

void LLScriptLValueExpression::determine_type() {
   LLScriptIdentifier *id = (LLScriptIdentifier *) get_child(0);
   id->resolve_symbol( SYM_VARIABLE );
   type = id->get_type();
}

void LLScriptStateStatement::determine_type() {
   LLScriptIdentifier *id = (LLScriptIdentifier *) get_child(0);
   type = TYPE(LST_NULL);
   if ( id != NULL )
      id->resolve_symbol( SYM_STATE );

   // see if we're in a state or function, and if we're inside of an if
   bool      is_in_if    = false;
   LLASTNode *node       = NULL;

   for ( node = get_parent(); node; node = node->get_parent() ) {
      switch (node->get_node_type()) {
         case NODE_STATEMENT:
            if ( node->get_node_sub_type() == NODE_IF_STATEMENT )
               is_in_if = true;
            break;
         case NODE_STATE:
            // we're in a state, see if it's the same one we're calling
            if (
                  // in default and calling state default
                  (node->get_child(0)->get_node_type() == NODE_NULL && id == NULL) ||
                  (
                   // make sure neither current nor target is default
                   (id != NULL && node->get_child(0)->get_node_type() ==
                    NODE_IDENTIFIER) &&
                   // in state x calling state x
                   !strcmp( ((LLScriptIdentifier*)node->get_child(0))->get_name(),
                      id->get_name() )
                  )
               ) {
               ERROR( HERE, W_CHANGE_TO_CURRENT_STATE );
            }
            return;
         case NODE_GLOBAL_FUNCTION:
            if ( is_in_if ) {
               // see what kind of function it is
               switch (node->get_child(0)->get_type()->get_itype()) {
                  case LST_LIST:
                  case LST_STRING:
                     ERROR( HERE, W_CHANGE_STATE_HACK_CORRUPT );
                     break;
                  default:
                     ERROR( HERE, W_CHANGE_STATE_HACK );
                     break;
               }
            } else {
               ERROR( HERE, E_CHANGE_STATE_IN_FUNCTION );
            }
            return;
         default:
            break;
      }
   }
   LOG( LOG_ERROR, HERE, "INTERNAL ERROR: encountered state change statement "
         "not in function or state!" );
}

void LLScriptJumpStatement::determine_type() {
   LLScriptIdentifier *id = (LLScriptIdentifier *) get_child(0);
   id->resolve_symbol( SYM_LABEL );
   type = id->get_type();
   if ( id->get_symbol() != NULL && id->get_symbol()->get_references() == 2 ) {
      ERROR( HERE, W_MULTIPLE_JUMPS_FOR_LABEL, id->get_symbol()->get_name() );
   }
}

void LLScriptGlobalVariable::determine_type() {
   LLScriptIdentifier *id = (LLScriptIdentifier *) get_child(0);
   LLASTNode *node = get_child(1);
   if ( node == NULL || node->get_node_type() == NODE_NULL ) return;
   if ( !node->get_type()->can_coerce(id->get_type()) ) {
      ERROR( HERE, E_WRONG_TYPE_IN_ASSIGNMENT, id->get_type()->get_node_name(),
            id->get_name(), node->get_type()->get_node_name() );
   }
}

void LLScriptDeclaration::determine_type() {
   LLScriptIdentifier *id = (LLScriptIdentifier *) get_child(0);
   LLASTNode *node = get_child(1);
   if ( node == NULL || node->get_node_type() == NODE_NULL ) return;
   if ( !node->get_type()->can_coerce(id->get_type()) ) {
      ERROR( HERE, E_WRONG_TYPE_IN_ASSIGNMENT, id->get_type()->get_node_name(),
            id->get_name(), node->get_type()->get_node_name() );
   }
}

void LLScriptVectorExpression::determine_type() {
   type = TYPE(LST_VECTOR);
   LLASTNode *node = get_children();
   for ( ; node ; node = node->get_next() ) {
      if ( !node->get_type()->can_coerce(TYPE(LST_FLOATINGPOINT)) ) {
         ERROR( HERE, E_WRONG_TYPE_IN_MEMBER_ASSIGNMENT, "vector",
               node->get_type()->get_node_name() );
         return;
      }
   }
}

void LLScriptQuaternionExpression::determine_type() {
   type = TYPE(LST_QUATERNION);
   LLASTNode *node = get_children();
   for ( ; node ; node = node->get_next() ) {
      if ( !node->get_type()->can_coerce(TYPE(LST_FLOATINGPOINT)) ) {
         ERROR( HERE, E_WRONG_TYPE_IN_MEMBER_ASSIGNMENT, "quaternion",
               node->get_type()->get_node_name() );
         return;
      }
   }
}

void LLScriptReturnStatement::determine_type() {
   LLASTNode *node = get_parent();

   // crawl up until we find an event handler or global func
   while ( node->get_node_type() != NODE_EVENT_HANDLER &&
         node->get_node_type() != NODE_GLOBAL_FUNCTION )
      node = node->get_parent();

   // if an event handler
   if ( node->get_node_type() == NODE_EVENT_HANDLER ) {
      // make sure we're not returning anything
      if ( get_child(0)->get_node_type() != NODE_NULL ) {
         ERROR( HERE, E_RETURN_VALUE_IN_EVENT_HANDLER );
      }
   } else {  // otherwise it's a function
      // the return type of the function is stored in the identifier which is
      // the first child
      if ( !get_child(0)->get_type()->can_coerce(
               node->get_child(0)->get_type()) ) {
         ERROR( HERE, E_BAD_RETURN_TYPE,
               get_child(0)->get_type()->get_node_name(),
               node->get_child(0)->get_type()->get_node_name() );
      }
   }
}

void LLScriptIfStatement::determine_type() {
   type = TYPE(LST_NULL);
   // warn if main branch is an empty statement and secondary branch is null
   // or empty
   if ( get_child(1)->get_node_type() == NODE_STATEMENT &&
         get_child(1)->get_node_sub_type() == NODE_NO_SUB_TYPE &&
         get_child(1)->get_children() == NULL &&
         (get_child(2)->get_node_type() == NODE_NULL ||
          (get_child(2)->get_node_type() == NODE_STATEMENT &&
           get_child(2)->get_node_sub_type() == NODE_NO_SUB_TYPE &&
           get_child(2)->get_children() == NULL
          )
         )
      ) {
      ERROR( IN(get_child(0)), W_EMPTY_IF );
      DEBUG( LOG_DEBUG_SPAM, NULL, "TYPE=%d SUBTYPE=%d CHILDREN=%p n=%s\n",
            get_child(1)->get_node_type(), get_child(1)->get_node_sub_type(),
            get_child(1)->get_children(), get_child(1)->get_node_name() );
      //    do_walk( this );
   }
}

void LLASTNode::check_symbols() {
   LLASTNode             *node;
   if ( get_symbol_table() != NULL )
      get_symbol_table()->check_symbols();

   for ( node = get_children(); node; node = node->get_next() )
      node->check_symbols();
}


void usage(char *name) {
   printf("Usage: %s [options] [input]\n", name);
   printf("Options: \n");
   printf("\t-b <file>\tLoad builtin functions from file.\n");
   printf("\t-t\t\tShow tree structure.\n");
   printf("\t-l\t\tShow line/column information as range\n");
   printf("\t-p\t\tAdd the file path to the result\n");
   printf("\t-v\t\tBe verbose\n");
   printf("\t-S\t\tDon't sort log messages\n");
   printf("\t-#\t\tShow error codes (for debugging/testing)\n");
   printf("\t-A\t\tCheck error assertions (for debugging/testing)\n");
#ifdef COMPILE_ENABLED
   printf("\t-c\t\tCompile.\t\t\t(default)\n");
   printf("\t-C\t\tDon't compile.\n");
#endif /* COMPILE_ENABLED */
   printf("\t-V\t\tPrint version and exit.\n");
   return;
}

void version() {
   /*
      fprintf(stderr, "lslint v" VERSION " by masa, built " BUILD_DATE "\n");
      fprintf(stderr, "by using this program you agree to smile :o)\n");
      */

   fprintf(stderr, "     lcllok         ;....;   ccc:\n");
   fprintf(stderr, "    ,dNWX0xolodddd:.','''..:OXWWX::\n");
   fprintf(stderr, "   ::WMMMMMMMMMMMN;.,'.....':xkxx:,       =] W-Hat KReW PreZentZ [=\n");
   fprintf(stderr, "   :,0WMMMMMMMMMMN;','...',,'...'..\n");
   fprintf(stderr, "    .cNMMMMMMMMMMMK:,,;;.',,'...,,',            lslint v %s\n", VERSION);
   fprintf(stderr, "   ,dWMMMMMMMMMMMMMMWWWMKdl,...''..\n");
   fprintf(stderr, "  ,lWMMMMMMMMMMMMMMMMMMMMMMNo,'':o                 CODiNG::\n");
   fprintf(stderr, "  .OMMMMMMMMMMMMMMMMMMMMMMMMMNXNMMx.                              ~masa~\n");
   fprintf(stderr, ",:.cxKMMWkxNMMMMMMMMMMMMMMXKWMMMKxc.,,                      Doran Zemlja\n");
   fprintf(stderr, "  ;c0XMMN;'OMMMMMWNWMMMMMX,.kMMMWKl.\n");
   fprintf(stderr, " ,:':XMMMWWMMMMMNllckMMMMMKKWMMMWo.::,             RELEaSE DaTE::\n");
   fprintf(stderr, "     ;lKMMMMMMMMMKkONMMMMMMMMMMOc.:                           %s\n", __DATE__);
   fprintf(stderr, "   ,::' ;KWMMMMMWKkONMMMMMMNNXk:: :,\n");
   fprintf(stderr, "        ,coollodll:odxkkkkxocc;O\n");
   fprintf(stderr, "       '0MMMNx;.,doOKKKKKKKk:d:                    GReeTz::\n");
   fprintf(stderr, "       ,kMMMMMWkc;l0kKKKK00KKod                             L0wNaGe L4bZ\n");
   fprintf(stderr, "     lc:clo0WMMMMo,Ox0xl0xxkl;llc:                          Pl4st1K DuCk\n");
   fprintf(stderr, "    :OWMMW0ocOMMMl'k00kxOk:cONMMWKl;                               Pet3y\n");
   fprintf(stderr, "   '0MMMMMMMO,dkl.,,ooddl'oWMMMMMMW:                               N3X15\n");
   fprintf(stderr, "   'KMMMMMMMMl.,,clcod00c'XMMMMMMMMc\n");
   fprintf(stderr, "   ,oWMMMMMMWc',,:OK0llc,'KMMMMMMM0,   ~ Cyber Terrorists Since 2004 ~\n");
   fprintf(stderr, "    :l0WMMMXo;oolcx00l;;l::0WMMWKd:\n");
   fprintf(stderr, "     klclollx     kxx    dolloollx\n");
   fprintf(stderr, " \n");
   fprintf(stderr, "     \"if you see an avatar with their lights off don't flash yor lights\n");
   fprintf(stderr, "        at them because they are goons in training and will run you off\n");
   fprintf(stderr, "                                         the road and crash your client\"\n");
   fprintf(stderr, " \n");
   fprintf(stderr, "Modified by: Makopoppo @ https://github.com/Makopo/lslint\n");
   fprintf(stderr, "VS 2015  by: Xenhat    @ https://github.com/Ociidii-Works/lslint\n");
}

int yylex_init( void ** );
void yyset_in( FILE *, void *);
int yylex_destroy( void *) ;

int main(int argc, char **argv) {
   int i, j;
   FILE *yyin = NULL;
   bool show_tree = false;
   bool print_path = false;
   void *scanner;
   Logger *logger = Logger::get();

#ifdef COMPILE_ENABLED  
   bool compile   = true;
#endif

   for ( i = 1; i < argc; ++i ) {
      if ( argv[i][0] == '-' ) {
         for ( j = 1 ; argv[i][j]; ++j ) {
            switch( argv[i][j] ) {
               case 'b': builtins_file = argv[++i]; goto nextarg;
               case 't': show_tree = true; break;
               case 'l': logger->set_show_end(true);  break;
               case 'v': logger->set_show_info(true); break;
               case 'S': logger->set_sort(false);     break;
               case '#': logger->set_show_error_codes(true); break;
               case 'A': logger->set_check_assertions(true); break;
               case 'p': print_path = true; break;
               case 'V': version(); return 0;
#ifdef COMPILE_ENABLED                    
               case 'c': compile   = true; break;
               case 'C': compile   = false; break;
#endif /* COMPILE_ENABLED */
               default: usage(argv[0]); exit(1);
            }
         }
      } else {
         if ( yyin != NULL ) {
            fprintf(stderr,
                  "don't know what to do with multiple file arguments.\n");
            return -1;
         }
         if (print_path)
         {
            logger->set_file_path(argv[i]);
         }
         yyin = fopen( argv[i], "r" );
         if ( yyin == NULL ) {
            fprintf(stderr, "couldn't open %s\n", argv[i]);
            return -1;
         }
      }
nextarg:
      ;
   }

   // initialize flex
   yylex_init( &scanner );

   // set input file
   yyset_in( yyin, scanner );

   // parse
   yyparse( scanner );

   // clean up flex
   yylex_destroy( scanner );

   if ( script ) {
      LOG(LOG_INFO, NULL, "Script parsed, collecting symbols");
      script->collect_symbols();
      LOG(LOG_INFO, NULL, "Propogating types");
      script->propogate_types();
      script->propogate_values();
      script->check_symbols();
      script->final_pre_walk();
      Logger::get()->report();
      if ( show_tree ) {
         LOG(LOG_INFO, NULL, "Tree:");
         script->walk();
      }
#ifdef COMPILE_ENABLED
      if ( compile ) {
         if ( yynerrs > 0 ) {
            return -3;
         }

         script->generate_cil();
      }
#endif /* COMPILE_ENABLED */    
   } else {
      Logger::get()->report();
   }
   return Logger::get()->get_errors();
}
