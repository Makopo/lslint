#ifndef _AST_HH
#define _AST_HH 1
#include <stdarg.h> // va_arg
#include "symtab.hh" // symbol table
#include "logger.hh"

// Base node types
enum LLNodeType {

  NODE_NODE,
  NODE_NULL,
  NODE_SCRIPT,
  NODE_GLOBAL_STORAGE,
  NODE_IDENTIFIER,
  NODE_GLOBAL_VARIABLE,
  NODE_SIMPLE_ASSIGNABLE,
  NODE_CONSTANT,
  NODE_GLOBAL_FUNCTION,
  NODE_FUNCTION_DEC,
  NODE_EVENT_DEC,
  NODE_STATE,
  NODE_EVENT_HANDLER,
  NODE_EVENT,
  NODE_STATEMENT,
  NODE_EXPRESSION,

};

// Node Sub-types
enum LLNodeSubType {

  NODE_NO_SUB_TYPE, 

  NODE_INTEGER_CONSTANT,
  NODE_FLOAT_CONSTANT,
  NODE_STRING_CONSTANT,
  NODE_VECTOR_CONSTANT,
  NODE_QUATERNION_CONSTANT,
  NODE_LIST_CONSTANT,

  NODE_COMPOUND_STATEMENT,
  NODE_RETURN_STATEMENT,
  NODE_LABEL,
  NODE_JUMP_STATEMENT,
  NODE_IF_STATEMENT,
  NODE_FOR_STATEMENT,
  NODE_DO_STATEMENT,
  NODE_WHILE_STATEMENT,
  NODE_DECLARATION,
  NODE_STATE_STATEMENT,

  NODE_TYPECAST_EXPRESSION,
  NODE_FUNCTION_EXPRESSION,
  NODE_VECTOR_EXPRESSION,
  NODE_QUATERNION_EXPRESSION,
  NODE_LIST_EXPRESSION,
  NODE_LVALUE_EXPRESSION

};


class LLASTNode {
  public:
    LLASTNode() : type(NULL), symbol_table(NULL), constant_value(NULL), children(NULL), parent(NULL), next(NULL), prev(NULL),  lloc(glloc) {};
    LLASTNode( YYLTYPE *lloc, int num, ... )
      : type(NULL), symbol_table(NULL), constant_value(NULL), children(NULL), parent(NULL), next(NULL), prev(NULL), lloc(*lloc) {
      va_list ap;
      va_start(ap, num);
      add_children( num, ap );
      va_end(ap);
    }


    LLASTNode( int num, ... ) : type(NULL), symbol_table(NULL), constant_value(NULL), children(NULL), parent(NULL), next(NULL), prev(NULL), lloc(glloc) {
      va_list ap;
      va_start(ap, num);
      add_children( num, ap );
      va_end(ap);
    }

    void add_children( int num, va_list vp );

    LLASTNode *get_next() { return next; }
    LLASTNode *get_prev() { return prev; }
    LLASTNode *get_children() { return children; }
    LLASTNode *get_parent() { return parent; }
    LLASTNode *get_child(int i) {
      LLASTNode *c = children;
      while ( i-- && c )
        c = c->get_next();
      return c;
    }

    void                set_type(LLScriptType *_type) { type = _type;   }
    class LLScriptType *get_type()                    { return type;    }

    
    // Add a child to beginning of list. Not sure if this will be used yet.
    void    add_child( LLASTNode *child ) {
      if ( child == NULL ) return;
      child->set_next(children);
      child->set_parent(this);
      children  = child;
    }
   

    // Add child to end of list.
    void    push_child( LLASTNode *child ) {
      if ( child == NULL ) return;
      if ( children == NULL ) {
        children = child;
      } else {
        children->add_next_sibling(child);
      }
      child->set_parent(this);
    }

    /* Set our parent, and make sure all our siblings do too. */
    void    set_parent( LLASTNode *newparent ) {
      parent    = newparent;
      if ( next && next->get_parent() != newparent )
        next->set_parent(newparent);
    }

    /* Set our next sibling, and ensure it links back to us. */
    void    set_next( LLASTNode *newnext ) {
      DEBUG( LOG_DEBUG_SPAM, NULL, "%s.set_next(%s)\n", get_node_name(), newnext ? newnext->get_node_name() : "NULL" );
      next = newnext;
      if ( newnext && newnext->get_prev() != this )
        newnext->set_prev(this);
    }

    /* Set our previous sibling, and ensure it links back to us. */
    void    set_prev( LLASTNode *newprev ) {
      DEBUG( LOG_DEBUG_SPAM, NULL, "%s.set_prev(%s)\n", get_node_name(), newprev ? newprev->get_node_name() : "NULL" );
      prev  = newprev;
      if ( newprev && newprev->get_next() != this )
        newprev->set_next(this);
    }

    void    add_next_sibling( LLASTNode *sibling ) {
      if ( sibling == NULL ) return;
      if ( next )
        next->add_next_sibling(sibling);
      else
        set_next(sibling);
    }

    void    add_prev_sibling( LLASTNode *sibling ) {
      if ( sibling == NULL ) return;
      if ( prev )
        prev->add_prev_sibling(sibling);
      else
        set_prev(sibling);
    }

    /// passes                  ///
    
    // walk through tree, printing out names
    void walk();

    // TODO: is there a way to make a general purpose tree-walking method? eg, walk_tree( ORDER_POST, define_symbols );
    // collect symbols from function/state/variable declarations
    void collect_symbols();
    virtual void define_symbols();

    // propogate types   TODO: rename to propogate_and_check_type / determine_and_check_type ?
    void propogate_types();
    virtual void determine_type();

    // propogate const values     TODO: come up with a better name?
    void propogate_values();
    virtual void determine_value();

    // final pre walk checks    TODO: come up with a better name?
    void final_pre_walk();
    virtual void final_pre_checks();

    // compile
    virtual void generate_cil() {};

    /// symbol functions        ///
    LLScriptSymbol *lookup_symbol( char *name, LLSymbolType type = SYM_ANY, bool is_case_sensitive = true );
    void            define_symbol( LLScriptSymbol *symbol );
    void            check_symbols(); // look for unused symbols, etc
    LLScriptSymbolTable *get_symbol_table() { return symbol_table; }


    YYLTYPE     *get_lloc()     { return &lloc; };
    static void set_glloc(YYLTYPE *yylloc) { glloc = *yylloc; };

    /// identification          ///
    virtual char       *get_node_name() { return "node";    };
    virtual LLNodeType  get_node_type() { return NODE_NODE; };
    virtual LLNodeSubType get_node_sub_type() { return NODE_NO_SUB_TYPE; }
    
    /// constants ///
    bool            is_constant()           { return constant_value != NULL; };
    class LLScriptConstant  *get_constant_value()    { return constant_value; };

  protected:
    class LLScriptType          *type;
    LLScriptSymbolTable         *symbol_table;
    LLScriptConstant            *constant_value;

  private:
    LLASTNode                   *children;
    LLASTNode                   *parent;
    LLASTNode                   *next;
    LLASTNode                   *prev;
    YYLTYPE                      lloc;
    static YYLTYPE               glloc;
};   

class LLASTNullNode : public LLASTNode {
  virtual LLNodeType get_node_type() { return NODE_NULL; };
};

#endif /* not AST_HH */
