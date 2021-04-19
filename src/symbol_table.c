#include "symbol_table.h"

symbolNode *symbolTable = NULL;

scopeStack *scopeStackHead = NULL;

void intchar_copy(void *_dst, const void *_src) {
  scopeStack *dst = (scopeStack*)_dst, *src = (scopeStack*)_src;
  dst->level = src->level;
  dst->name = src->name ? strdup(src->name) : NULL;
  dst->next = src->next;
}

void intchar_dtor(void *_elt) {
  scopeStack *elt = (scopeStack*)_elt;
  if (elt->name) free(elt->name);
  if (elt->next) free(elt->next);
}

UT_icd intchar_icd = {sizeof(scopeStack), NULL, intchar_copy, intchar_dtor};

void create_new_scope(int level, char *scopeName) {
  struct scopeStack *el;

  el = (scopeStack*)malloc(sizeof(scopeStack));

  el->level = level;
  el->name = scopeName;
  LL_APPEND(el, el);
  utarray_push_back(scopeList, el);
}

void print_scopes_list() {
  struct scopeStack *p;
  p = NULL;
  while((p=(scopeStack*)utarray_next(scopeList,p))) {
    printf("Level: %d, scope name: %s\n", p->level, (p->name ? p->name : "null"));
  }
}

void add_symbol_node(symbolParam symbol) {
  struct symbolNode *symbolPointer;
  char stringSType = symbol.symbolType;
  /* attempts to find entry on symbol table */
  HASH_FIND_INT(symbolTable, &symbol.symbolID, symbolPointer);
  if (symbolPointer == NULL) {
    symbolPointer = (symbolNode*)malloc(sizeof(symbolNode));
    symbolPointer -> symbolID = symbol.symbolID;
    symbolPointer -> type = symbol.type;
    symbolPointer -> symbolType = stringSType;
    symbolPointer -> name = symbol.name;
    HASH_ADD_INT(symbolTable, symbolID, symbolPointer);
  } else {
    printf("symbol %s already declared!\n", symbol.name);
  }
}

void print_symbols() {
  struct symbolNode *s;
  struct symbolNode *nullC = NULL;

  printf("\n=========================== Symbols table ===========================\n\n");
  printf("Symbol ID     Symbol Name                Type           Symbol Type\n\n");
  for (s = symbolTable; s != nullC; s = (struct symbolNode*)(s -> hh.next)) {
    printf("   %-5d\t %-15s\t %-10s\t %5c\t\n", s -> symbolID, s -> name, s -> type, s -> symbolType);
  }
  printf("==================================================================\n");
}

/* Clear symbol table mem allocation */
/* https://troydhanson.github.io/uthash/userguide.html#_delete_item */
void free_symbols_table(){
  symbolNode *s, *tmp;
  HASH_ITER(hh, symbolTable, s, tmp) {
    HASH_DEL(symbolTable, s);
    free(s);
  }
}