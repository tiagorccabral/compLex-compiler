#include <stdio.h>
#include <time.h>
#include "symbol_table.h"

symbolNode *symbolTable = NULL;

scopeStack *scopeStackHead = NULL;

void create_new_scope_level() {
  scopeStack *tmpScope;
  tmpScope = (scopeStack*)malloc(sizeof(scopeStack));
  if (STACK_EMPTY(scopeStackHead)) {
    tmpScope->level = 0; /* if its the first insertion, set as 0 level */
  } else {
    scopeInfo current_scope = get_current_scope();
    tmpScope->level = current_scope.level + 1;
  }
  tmpScope->scopeID = gen_random_uniqueID();
  STACK_PUSH(scopeStackHead, tmpScope);
}

void decrease_scope_level() {
  scopeStack *tmpStack;
  tmpStack = (scopeStack*)malloc(sizeof(scopeStack));
  STACK_POP(scopeStackHead, tmpStack);
  free(tmpStack);
}

scopeInfo get_current_scope() {
  int current_scope = 0;
  int uniqueID;
  scopeInfo scopeData;
  if (!STACK_EMPTY(scopeStackHead)) { /* if scope stack is not empty, return current scope, return 0 otherwise */
    scopeStack *tmpStack;
    tmpStack = (scopeStack*)malloc(sizeof(scopeStack));
    STACK_POP(scopeStackHead, tmpStack);
    current_scope = tmpStack->level;
    uniqueID = tmpStack->scopeID;
    STACK_PUSH(scopeStackHead, tmpStack);
  } else {
    uniqueID = gen_random_uniqueID();
  }
  scopeData.level = current_scope;
  scopeData.scopeID = uniqueID;
  return scopeData;
}

int gen_random_uniqueID() {
  int result = 0, low_num = 0, hi_num = 0;

  low_num = 10000;
  hi_num = 89999;

  result = (rand() % hi_num) + low_num;
  return result;
}

void print_scopes_list() {
}

void add_symbol_node(symbolParam symbol) {
  struct symbolNode *symbolPointer;
  char stringSType = symbol.symbolType;
  scopeInfo current_scope = get_current_scope();
  /* attempts to find entry on symbol table */
  HASH_FIND_INT(symbolTable, &symbol.symbolID, symbolPointer);
  if (symbolPointer == NULL) {
    symbolPointer = (symbolNode*)malloc(sizeof(symbolNode));
    symbolPointer -> symbolID = symbol.symbolID;
    symbolPointer -> type = symbol.type;
    symbolPointer -> symbolType = stringSType;
    symbolPointer -> name = symbol.name;
    symbolPointer -> scope = current_scope.level;
    symbolPointer -> scopeID = current_scope.scopeID;
    HASH_ADD_INT(symbolTable, symbolID, symbolPointer);
  } else {
    printf("symbol %s already declared!\n", symbol.name);
  }
}

void print_symbols() {
  struct symbolNode *s;
  struct symbolNode *nullC = NULL;

  printf("\n==================================== Symbols table ====================================\n\n");
  printf("Symbol ID     Symbol Name                Type           Symbol Type   Scope     ScopeID\n\n");
  for (s = symbolTable; s != nullC; s = (struct symbolNode*)(s -> hh.next)) {
    printf("   %-5d\t %-15s\t %-10s\t %5c\t %7d\t %-10d\t\n", s -> symbolID, s -> name, s -> type, s -> symbolType, s -> scope, s->scopeID);
  }
  printf("========================================================================================\n");
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

void free_scope_stack(){
  scopeStack *tmpStack;
  tmpStack = (scopeStack*)malloc(sizeof(scopeStack));
  while (!STACK_EMPTY(scopeStackHead)) {
    STACK_POP(scopeStackHead, tmpStack);
    free(tmpStack);
  }
}