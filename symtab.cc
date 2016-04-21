#include <string.h>     // strcmp
#include <vector>       // vector::iterator
#include "lslmini.hh"
#include "lslmini.tab.h"
#include "symtab.hh"

#ifdef _MSC_VER
#define strcasecmp _stricmp  // MSVC defines stricmp not strcasecmp
#endif // _MSC_VER

void LLScriptSymbolTable::define(LLScriptSymbol *symbol) {
   symbols.push_back(symbol);
   DEBUG( LOG_DEBUG_SPAM, NULL, "defined symbol: %d %s %s\n", symbol->get_symbol_type(), symbol->get_type() ? symbol->get_type()->get_node_name() : "!!!NULL!!!", symbol->get_name() );
}

LLScriptSymbol *LLScriptSymbolTable::lookup(char *name, LLSymbolType type, bool is_case_sensitive) {
   std::vector<LLScriptSymbol*>::const_iterator sym;
   int (*strcmpfunc)(const char *s1, const char *s2) = NULL;
   if ( is_case_sensitive )
      strcmpfunc = strcmp;
   else
      strcmpfunc = strcasecmp;

   for (sym = symbols.begin(); sym != symbols.end(); ++sym) {
      if ( !strcmpfunc(name, (*sym)->get_name()) && (type == SYM_ANY || type == (*sym)->get_symbol_type()) )
         return *sym;
   }
   return NULL;
}

void LLScriptSymbolTable::check_symbols() {
   std::vector<LLScriptSymbol*>::const_iterator sym;
   for (sym = symbols.begin(); sym != symbols.end(); ++sym) {
      if ( (*sym)->get_sub_type() != SYM_BUILTIN && (*sym)->get_sub_type() != SYM_EVENT_PARAMETER && (*sym)->get_references() == 0 ) {
         ERROR( IN(*sym), W_DECLARED_BUT_NOT_USED, LLScriptSymbol::get_type_name((*sym)->get_symbol_type()), (*sym)->get_name() );
      }
      if ( (*sym)->get_sub_type() != SYM_BUILTIN && (*sym)->get_sub_type() == SYM_EVENT_PARAMETER && (*sym)->get_references() == 0 ) {
         ERROR( IN(*sym), W_UNUSED_EVENT_PARAMETER, (*sym)->get_name() );
      }
   }
}

