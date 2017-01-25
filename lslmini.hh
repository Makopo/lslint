#ifndef _LSLMINI_HH
#define _LSLMINI_HH 1

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h> // isprint()
#include <cstdarg>

typedef int   S32;
typedef float F32;

#define BUFFER_SIZE     1024
#define UUID_STR_LENGTH 36
#define MAX_NODES       3

extern class LLScriptScript *script;
extern int walklevel;
void print_walk(char *str);
void do_walk(class LLASTNode *node);

#include "lslmini.tab.h"
#include "symtab.hh"
#include "ast.hh"
#include "types.hh"

#ifdef _MSC_VER
#define snprintf _snprintf
#define strdup _strdup
#pragma warning( disable : 4996 4100 4267 4127 4244 )
#endif

class LLVector {
  public:
    LLVector(float x, float y, float z) : x(x), y(y), z(z) {};
    float x, y, z;
};

class LLQuaternion {
  public:
    LLQuaternion(float x, float y, float z, float s) : x(x), y(y), z(z), s(s) {};
    float x, y, z, s;
};

    
class LLScriptScript : public LLASTNode {
  public:
    LLScriptScript( class LLScriptGlobalStorage *globals, class LLScriptState *states )
      : LLASTNode( 2, globals, states ) {
        symbol_table = new LLScriptSymbolTable();
    };
    virtual void define_symbols();
#ifdef COMPILE_ENABLED
    virtual void generate_cil();
#endif /* COMPILE_ENABLED */
    void define_builtins();
    virtual char *get_node_name() { return "script"; };
    virtual LLNodeType get_node_type() { return NODE_SCRIPT; };
};

class LLScriptGlobalStorage : public LLASTNode {
  public:
    LLScriptGlobalStorage( class LLScriptGlobalVariable *variables, class LLScriptGlobalFunction *functions ) 
      : LLASTNode( 2, variables, functions ) {};
    virtual char *get_node_name() { return "global storage"; }
    virtual LLNodeType get_node_type() { return NODE_GLOBAL_STORAGE; };
};

class LLScriptIdentifier : public LLASTNode {
  public:
    LLScriptIdentifier( char *name ) : LLASTNode(0), symbol(NULL), name(name), member(NULL) {};
    LLScriptIdentifier( char *name, char *member ) : LLASTNode(0), symbol(NULL), name(name), member(member) {};
    LLScriptIdentifier( class LLScriptType *_type, char *name ) : LLASTNode(0), symbol(NULL), name(name), member(NULL) { type = _type; };
    LLScriptIdentifier( class LLScriptType *_type, char *name, YYLTYPE *lloc ) : LLASTNode( lloc, 0), symbol(NULL), name(name), member(NULL) { type = _type; };
    LLScriptIdentifier( LLScriptIdentifier *other ) : LLASTNode(0), symbol(NULL), name(other->get_name()), member(other->get_member()) {};

    char    *get_name() { return name; }
    char    *get_member() { return member; }

    void determine_value();

    void resolve_symbol(LLSymbolType symbol_type);
    void set_symbol( LLScriptSymbol *_symbol ) { symbol = _symbol; };
    LLScriptSymbol *get_symbol() { return symbol; };

    virtual char *get_node_name() {
      static char buf[256];
      sprintf(buf, "identifier \"%s%s%s\"", name, member ? "." : "", member ? member : "" );
      return buf;
    }
    virtual LLNodeType get_node_type() { return NODE_IDENTIFIER; };
  private:
    LLScriptSymbol                  *symbol;
    char                            *name;
    char                            *member;
};

class LLScriptGlobalVariable : public LLASTNode {
  public:
    LLScriptGlobalVariable( class LLScriptIdentifier *identifier, class LLScriptSimpleAssignable *value )
      : LLASTNode(2, identifier, value) { DEBUG( LOG_DEBUG_SPAM, NULL, "made a global var\n"); };
    virtual void define_symbols();
    virtual char *get_node_name() { return "global var"; }
    virtual LLNodeType get_node_type() { return NODE_GLOBAL_VARIABLE; };
    virtual void determine_type();

    void cil_declare();
};

class LLScriptSimpleAssignable : public LLASTNode {
  public:
    LLScriptSimpleAssignable( class LLScriptConstant *constant ) : LLASTNode(1, constant) {};
    LLScriptSimpleAssignable( class LLScriptIdentifier *id ) : LLASTNode(1, id) {};
    virtual char *get_node_name() { return "assignable"; }
    virtual void determine_type();
    virtual void determine_value();
    virtual LLNodeType get_node_type() { return NODE_SIMPLE_ASSIGNABLE; };
};

class LLScriptConstant : public LLASTNode {
  public:
    LLScriptConstant() : LLASTNode(0) { constant_value = this; }
    virtual char *get_node_name() { return "unknown constant"; }
    virtual LLNodeType get_node_type() { return NODE_CONSTANT; };
    virtual LLScriptConstant *operation(int op, LLScriptConstant *other_const, YYLTYPE *lloc) { return NULL; };
};


/////////////////////////////////////////////////////
// Integer Constant

class LLScriptIntegerConstant : public LLScriptConstant {
  public:
    LLScriptIntegerConstant( int v ) : LLScriptConstant(), value(v) { type = TYPE(LST_INTEGER); }

    virtual char *get_node_name() {
      static char buf[256];
      sprintf(buf, "integer constant: %d", value);
      return buf;
    }

    virtual LLNodeSubType get_node_sub_type() { return NODE_INTEGER_CONSTANT; }

    int get_value() { return value; }
    virtual LLScriptConstant *operation(int op, LLScriptConstant *other_const, YYLTYPE *lloc);

  private:
    int value;
};


/////////////////////////////////////////////////////
// Float Constant

class LLScriptFloatConstant : public LLScriptConstant {
  public:
    LLScriptFloatConstant( float v ) : LLScriptConstant(), value(v) { type = TYPE(LST_FLOATINGPOINT); }

    virtual char *get_node_name() {
      static char buf[256];
      sprintf(buf, "float constant: %f", value);
      return buf;
    }

    virtual LLNodeSubType get_node_sub_type() { return NODE_FLOAT_CONSTANT; }

    float get_value() { return value; }
    virtual LLScriptConstant *operation(int op, LLScriptConstant *other_const, YYLTYPE *lloc);

  private:
    float value;
};


/////////////////////////////////////////////////////
// String Constant

class LLScriptStringConstant : public LLScriptConstant {
  public:
    LLScriptStringConstant( char *v ) : LLScriptConstant(), value(v) { type = TYPE(LST_STRING); }

    virtual char *get_node_name() {
      static char buf[256];
      sprintf(buf, "string constant: `%s'", value);
      return buf;
    }

    virtual LLNodeSubType get_node_sub_type() { return NODE_STRING_CONSTANT; }

    char *get_value() { return value; }
    virtual LLScriptConstant *operation(int op, LLScriptConstant *other_const, YYLTYPE *lloc);

  private:
    char *value;
};


/////////////////////////////////////////////////////
// List Constant

class LLScriptListConstant : public LLScriptConstant {
  public:
    LLScriptListConstant( class LLScriptSimpleAssignable *v ) : LLScriptConstant(), value(v) { type = TYPE(LST_LIST); }

    virtual char *get_node_name() {
      static char buf[256];
      sprintf(buf, "list constant: `%p'", value);
      return buf;
    }

    virtual LLNodeSubType get_node_sub_type() { return NODE_LIST_CONSTANT; }

    class LLScriptSimpleAssignable *get_value() { return value; }

    int get_length() {
      LLASTNode *node = (LLASTNode*)value;
      int i = 0;
      for ( ; node; node = node->get_next() )
        ++i;
      return i;
    }

    virtual LLScriptConstant *operation(int op, LLScriptConstant *other_const, YYLTYPE *lloc);

  private:
    class LLScriptSimpleAssignable *value;
};

/////////////////////////////////////////////////////
// Vector Constant

class LLScriptVectorConstant : public LLScriptConstant {
  public:
    LLScriptVectorConstant( class LLScriptSimpleAssignable *v1, class LLScriptSimpleAssignable *v2, class LLScriptSimpleAssignable *v3)
        : LLScriptConstant(), value(NULL) { push_child(v1); push_child(v2); push_child(v3); type = TYPE(LST_VECTOR); };
    LLScriptVectorConstant( float v1, float v2, float v3 ) {
      value = new LLVector( v1, v2, v3 );
      type = TYPE(LST_VECTOR);
    };

    virtual char *get_node_name() {
      static char buf[256];
      if ( value )
        sprintf(buf, "vector constant: <%g, %g, %g>", value->x, value->y, value->z);
      else
        sprintf(buf, "vector constant: unknown value?" );
      return buf;
    }

    virtual void determine_value();
    virtual LLNodeSubType get_node_sub_type() { return NODE_VECTOR_CONSTANT; }

    LLVector *get_value() { return value; }

    virtual LLScriptConstant *operation(int op, LLScriptConstant *other_const, YYLTYPE *lloc);

  private:
    LLVector *value;
};


/////////////////////////////////////////////////////
// Quaternion Constant

class LLScriptQuaternionConstant : public LLScriptConstant {
  public:
    LLScriptQuaternionConstant( class LLScriptSimpleAssignable *v1, class LLScriptSimpleAssignable *v2, class LLScriptSimpleAssignable *v3, class LLScriptSimpleAssignable *v4)
        : LLScriptConstant(), value(NULL) { push_child(v1); push_child(v2); push_child(v3); push_child(v4); type = TYPE(LST_QUATERNION); };
    LLScriptQuaternionConstant( float v1, float v2, float v3, float v4 ) {
      value = new LLQuaternion( v1, v2, v3, v4 );
      type = TYPE(LST_QUATERNION);
    };

    virtual char *get_node_name() {
      static char buf[256];
      if (value)
        sprintf(buf, "quaternion constant: <%g, %g, %g, %g>", value->x, value->y, value->z, value->s);
      else
        sprintf(buf, "quaternion constant: unknown value?" );
      return buf;
    }

    virtual LLNodeSubType get_node_sub_type() { return NODE_QUATERNION_CONSTANT; }

    LLQuaternion *get_value() { return value; }

    virtual LLScriptConstant *operation(int op, LLScriptConstant *other_const, YYLTYPE *lloc);

    virtual void determine_value();

  private:
    LLQuaternion *value;
};



class LLScriptGlobalFunction : public LLASTNode {
  public:
    LLScriptGlobalFunction( class LLScriptIdentifier *identifier, class LLScriptFunctionDec *decl, class LLScriptStatement *statement )
      : LLASTNode( 3, identifier, decl, statement ) {
        symbol_table = new LLScriptSymbolTable();
    };
    virtual void define_symbols();
    virtual char *get_node_name() { return "global func"; }
    virtual LLNodeType get_node_type() { return NODE_GLOBAL_FUNCTION; };
    virtual void final_pre_checks();
};

class LLScriptFunctionDec : public LLASTNode {
  public:
    LLScriptFunctionDec() : LLASTNode(0) {};
    LLScriptFunctionDec( class LLScriptIdentifier *identifier ) : LLASTNode(1, identifier) {};
    virtual void define_symbols();
    virtual char *get_node_name() { return "function decl"; }
    virtual LLNodeType get_node_type() { return NODE_FUNCTION_DEC; };
};

class LLScriptEventDec : public LLASTNode {
  public:
    LLScriptEventDec() : LLASTNode(0) {};
    LLScriptEventDec( class LLScriptIdentifier *identifier ) : LLASTNode(1, identifier) {};
    virtual void define_symbols();
    virtual char *get_node_name() { return "event decl"; }
    virtual LLNodeType get_node_type() { return NODE_EVENT_DEC; };
};

class LLScriptState : public LLASTNode {
  public:
    LLScriptState( class LLScriptIdentifier *identifier, class LLScriptEventHandler *state_body )
      : LLASTNode( 2, identifier, state_body ) {};
    virtual void define_symbols();
    virtual char *get_node_name() { return "state"; }
    virtual LLNodeType get_node_type() { return NODE_STATE; };
};

class LLScriptEventHandler : public LLASTNode {
  public:
    LLScriptEventHandler( class LLScriptIdentifier *identifier, class LLScriptEventDec *decl, class LLScriptStatement *body )
      : LLASTNode(3, identifier, decl, body) {
        symbol_table = new LLScriptSymbolTable();
    };
    virtual char *get_node_name() { return "event handler"; }
    virtual LLNodeType get_node_type() { return NODE_EVENT_HANDLER; };
    virtual void final_pre_checks();
};

class LLScriptEvent : public LLASTNode {
  public:
    LLScriptEvent(int num, ...) {
      va_list ap;
      va_start(ap, num);
      add_children(num, ap);
      va_end(ap);
     };

    virtual void define_symbols();
    virtual char *get_node_name() { return "event"; }
    virtual LLNodeType get_node_type() { return NODE_EVENT; };
};

class LLScriptStatement : public LLASTNode {
  public:
    LLScriptStatement( int num, ... ) {
      va_list ap;
      va_start(ap, num);
      add_children(num, ap);
      va_end(ap);
    };
    LLScriptStatement( class LLScriptExpression *expression ) : LLASTNode(1, expression) {};
    virtual char *get_node_name() { return "statement"; }
    virtual LLNodeType get_node_type() { return NODE_STATEMENT; };
};

class LLScriptCompoundStatement : public LLScriptStatement {
  public:
    LLScriptCompoundStatement( class LLScriptStatement *body ) : LLScriptStatement(1, body) { symbol_table = new LLScriptSymbolTable(); }
    virtual char *get_node_name() { return "compound statement"; };
    virtual LLNodeSubType get_node_sub_type() { return NODE_COMPOUND_STATEMENT; };
};

class LLScriptStateStatement : public LLScriptStatement {
  public:
    LLScriptStateStatement( ) : LLScriptStatement(0) {};
    LLScriptStateStatement( class LLScriptIdentifier *identifier ) : LLScriptStatement(1, identifier) {};
    virtual void determine_type();
    virtual char *get_node_name() { return "setstate"; };
    virtual LLNodeSubType get_node_sub_type() { return NODE_STATE_STATEMENT; };
};

class LLScriptJumpStatement : public LLScriptStatement {
  public:
    LLScriptJumpStatement( class LLScriptIdentifier *identifier ) : LLScriptStatement(1, identifier) {};
    virtual void determine_type();
    virtual char *get_node_name() { return "jump"; };
    virtual LLNodeSubType get_node_sub_type() { return NODE_JUMP_STATEMENT; };
};

class LLScriptLabel : public LLScriptStatement {
  public:
    LLScriptLabel( class LLScriptIdentifier *identifier ) : LLScriptStatement(1, identifier) {};
    virtual void define_symbols();
    virtual char *get_node_name() { return "label"; };
    virtual LLNodeSubType get_node_sub_type() { return NODE_LABEL; };
};

class LLScriptReturnStatement : public LLScriptStatement {
  public:
    LLScriptReturnStatement( class LLScriptExpression *expression ) : LLScriptStatement(1, expression) {};
    virtual char *get_node_name() { return "return"; };
    virtual void determine_type();
    virtual LLNodeSubType get_node_sub_type() { return NODE_RETURN_STATEMENT; };
};

class LLScriptIfStatement : public LLScriptStatement {
  public:
    LLScriptIfStatement( class LLScriptExpression *expression, class LLScriptStatement *true_branch, class LLScriptStatement *false_branch)
      : LLScriptStatement( 3, expression, true_branch, false_branch ) {};
    virtual void determine_type();
    virtual void final_pre_checks();
    virtual char *get_node_name() { return "if"; };
    virtual LLNodeSubType get_node_sub_type() { return NODE_IF_STATEMENT; };
};

class LLScriptForStatement : public LLScriptStatement {
  public:
    LLScriptForStatement( class LLScriptExpression *init, class LLScriptExpression *condition,
        class LLScriptExpression *cont, class LLScriptStatement *body)
      : LLScriptStatement( 4, init, condition, cont, body ) {};
    virtual char *get_node_name() { return "for"; };
    virtual LLNodeSubType get_node_sub_type() { return NODE_FOR_STATEMENT; };
};

class LLScriptDoStatement : public LLScriptStatement {
  public:
    LLScriptDoStatement( class LLScriptStatement *body, class LLScriptExpression *condition )
      : LLScriptStatement(2, body, condition) {};
    virtual char *get_node_name() { return "do"; };
    virtual LLNodeSubType get_node_sub_type() { return NODE_DO_STATEMENT; };
};

class LLScriptWhileStatement : public LLScriptStatement {
  public:
    LLScriptWhileStatement( class LLScriptExpression *condition, class LLScriptStatement *body )
      : LLScriptStatement(2, condition, body) {};
    virtual char *get_node_name() { return "while"; };
    virtual LLNodeSubType get_node_sub_type() { return NODE_WHILE_STATEMENT; };
};


class LLScriptDeclaration : public LLScriptStatement {
  public:
    LLScriptDeclaration(class LLScriptIdentifier *identifier, class LLScriptExpression *value)
      : LLScriptStatement(2, identifier, value) { };
    virtual void define_symbols();
    virtual void determine_type();
    virtual void determine_value();
    virtual char *get_node_name() { return "declaration"; }; 
    virtual LLNodeSubType get_node_sub_type() { return NODE_DECLARATION; };
};

class LLScriptExpression : public LLASTNode {
  public:
    LLScriptExpression() : LLASTNode(0) {};
	LLScriptExpression( int num, ... ) : LLASTNode(0), operation(0) {
      va_list ap;
      va_start(ap, num);
      add_children(num, ap);
      va_end(ap);
    };
    LLScriptExpression( class LLScriptConstant *constant )
      : LLASTNode(1, constant), operation(0) {};
    LLScriptExpression( LLScriptExpression *lvalue, int operation, LLScriptExpression *rvalue )
      : LLASTNode(2, lvalue, rvalue), operation(operation) {};
    LLScriptExpression( LLScriptExpression *lvalue, int operation )
      : LLASTNode(1, lvalue), operation(operation) {};

    virtual void determine_type();
    virtual void determine_value();

    virtual char *get_node_name() {
      static char buf[256];
      sprintf( buf, isprint(operation) ? "expression: '%c'" : "expression: =%d", operation );
      return buf;
    }; 
    virtual LLNodeType get_node_type() { return NODE_EXPRESSION; };
    int get_operation() { return operation; };
  private:
    int operation;
};


class LLScriptTypecastExpression : public LLScriptExpression {
  public:
    LLScriptTypecastExpression( LLScriptType *_type, LLScriptExpression *expression )
      : LLScriptExpression(1, expression) {type = _type;};
    LLScriptTypecastExpression( LLScriptType *_type, LLScriptConstant *constant )
      : LLScriptExpression(1, constant) {type = _type;};

    virtual void determine_type() {}; // type already determined
    virtual char *get_node_name() { return "typecast expression"; }
    virtual LLNodeSubType get_node_sub_type() { return NODE_TYPECAST_EXPRESSION; };
};

class LLScriptFunctionExpression : public LLScriptExpression {
  public:
    LLScriptFunctionExpression( LLScriptIdentifier *identifier )
      : LLScriptExpression( 1, identifier ) {};
    LLScriptFunctionExpression( LLScriptIdentifier *identifier, LLScriptExpression *arguments )
      : LLScriptExpression( 2, identifier, arguments) {};
    virtual void determine_type();
    virtual char *get_node_name() { return "function call"; }
    virtual LLNodeSubType get_node_sub_type() { return NODE_FUNCTION_EXPRESSION; };
};

class LLScriptVectorExpression : public LLScriptExpression {
  public:
    LLScriptVectorExpression( LLScriptExpression *v1, LLScriptExpression *v2, LLScriptExpression *v3 )
      : LLScriptExpression(3, v1, v2, v3) { type = TYPE(LST_VECTOR); }
    LLScriptVectorExpression( ) : LLScriptExpression(0) {
      constant_value = new LLScriptVectorConstant(0.0f,0.0f,0.0f);
      type = TYPE(LST_VECTOR);
    }
    virtual void determine_value();
    virtual void determine_type();
    virtual char *get_node_name() { return "vector expression"; }
    virtual LLNodeSubType get_node_sub_type() { return NODE_VECTOR_EXPRESSION; };
};

class LLScriptQuaternionExpression : public LLScriptExpression {
  public:
    LLScriptQuaternionExpression( LLScriptExpression *v1, LLScriptExpression *v2, LLScriptExpression *v3, LLScriptExpression *v4 ) 
      : LLScriptExpression(4, v1, v2, v3, v4) { type = TYPE(LST_QUATERNION); };
    LLScriptQuaternionExpression( ) : LLScriptExpression(0) {
      constant_value = new LLScriptQuaternionConstant(0.0f, 0.0f, 0.0f, 0.0f);
      type = TYPE(LST_QUATERNION);
    };
    virtual void determine_value();
    virtual void determine_type();
    virtual char *get_node_name() { return "quaternion expression"; };
    virtual LLNodeSubType get_node_sub_type() { return NODE_QUATERNION_EXPRESSION; };
};

class LLScriptListExpression : public LLScriptExpression {
  public:
    LLScriptListExpression( LLScriptExpression *c ) : LLScriptExpression( 1, c ) { type = TYPE(LST_LIST); };
    virtual void determine_type() {};
    virtual void determine_value();
    virtual char *get_node_name() { return "list expression"; };
    virtual LLNodeSubType get_node_sub_type() { return NODE_LIST_EXPRESSION; }
};

class LLScriptLValueExpression : public LLScriptExpression {
  public:
    LLScriptLValueExpression( LLScriptIdentifier *identifier )
      : LLScriptExpression(1, identifier) {};
    virtual void determine_type();
    virtual char *get_node_name() { return "lvalue expression"; };
    virtual LLNodeSubType get_node_sub_type() { return NODE_LVALUE_EXPRESSION; };
};

#endif /* not _LSLMINI_HH */
