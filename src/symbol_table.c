#include <stdio.h>
#include <time.h>
#include "symbol_table.h"

symbolNode *symbolTable = NULL;

scopeStack *scopeStackHead = NULL; /* pointer to beginning of scope el stack */

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
  STACK_POP(scopeStackHead, tmpStack);
  free(tmpStack);
}

scopeInfo get_current_scope() {
  int current_scope = 0;
  int uniqueID;
  scopeInfo scopeData;
  if (!STACK_EMPTY(scopeStackHead)) { /* if scope stack is not empty, return current scope, return 0 otherwise */
    scopeStack *tmpStack;
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

void add_symbol_node(symbolParam symbol) {
  struct symbolNode *symbolPointer;
  char stringSType = symbol.symbolType;
  scopeInfo current_scope = get_current_scope();
  /* attempts to find entry on symbol table */
  HASH_FIND_INT(symbolTable, &symbol.symbolID, symbolPointer);
  if (symbolPointer == NULL) {
    if (symbol.symbolType == enumParameter) { /* if its a param, also update associated function */
      struct symbolNode *func;
      struct symbolNode *nullC = NULL;
      for (func = symbolTable; func != nullC; func = (struct symbolNode*)(func -> hh.next)) {
        if (func->name == symbol.associated_function && func->scopeID == symbol.associated_function_scope) {
          func -> params_list[symbol.last_param] = symbol.symbolID; /* adds params symbol to list of param of func */
          func -> last_param = symbol.last_param + 1;
        }
      }
      symbolPointer = (symbolNode*)malloc(sizeof(symbolNode));
      symbolPointer -> symbolID = symbol.symbolID;
      symbolPointer -> type = symbol.type;
      symbolPointer -> symbolType = stringSType;
      symbolPointer -> name = symbol.name;
      symbolPointer -> scope = current_scope.level;
      symbolPointer -> scopeID = current_scope.scopeID;
      symbolPointer -> tacName = symbol.tacName;
      symbolPointer -> line = symbol.line;
      symbolPointer -> column = symbol.column;
      symbolPointer -> params_list[0] = -1;
      symbolPointer -> last_param = -1;
      HASH_ADD_INT(symbolTable, symbolID, symbolPointer);
    } else {
      symbolPointer = (symbolNode*)malloc(sizeof(symbolNode));
      symbolPointer -> symbolID = symbol.symbolID;
      symbolPointer -> type = symbol.type;
      symbolPointer -> symbolType = stringSType;
      symbolPointer -> name = symbol.name;
      symbolPointer -> scope = current_scope.level;
      symbolPointer -> scopeID = current_scope.scopeID;
      symbolPointer -> tacName = symbol.tacName;
      symbolPointer -> line = symbol.line;
      symbolPointer -> column = symbol.column;
      symbolPointer -> params_list[0] = -1;
      symbolPointer -> last_param = 0;
      HASH_ADD_INT(symbolTable, symbolID, symbolPointer);
    }
  } else {
    printf("symbol %s already declared!\n", symbol.name);
  }
}

int get_symbolID(char *name, int scopeID) {
  struct symbolNode *s;
  struct symbolNode *nullC = NULL;
  int foundSymbolID = -1;

  for (s = symbolTable; s != nullC; s = (struct symbolNode*)(s -> hh.next)) {
    if (strcmp(name, s->name) == 0 && scopeID == s->scopeID) {
      foundSymbolID = s->symbolID;
    }
  }
  return foundSymbolID;
}

int get_symbolID_by_name_and_current_scope(char *name, int currentScopeID, int currentScopeLevel) {
  struct symbolNode *s;
  struct symbolNode *nullC = NULL;
  int foundSymbolID = -1;

  for (s = symbolTable; s != nullC; s = (struct symbolNode*)(s -> hh.next)) {
    if (strcmp(name, s->name) == 0 && currentScopeID == s->scopeID) {
      foundSymbolID = s->symbolID;
    }
  }
  if (foundSymbolID == -1) { /* looks for higher scope */
    for (s = symbolTable; s != nullC; s = (struct symbolNode*)(s -> hh.next)) {
      if (strcmp(name, s->name) == 0 && s->scope < currentScopeLevel) {
        foundSymbolID = s->symbolID;
      }
    }
  }
  return foundSymbolID;
}

void print_symbols() {
  struct symbolNode *s, *tmp;
  struct symbolNode *nullC = NULL;

  printf("\n==================================== Symbols table ====================================\n\n");
  printf("Symbol ID     Symbol Name                Type           Symbol Type   Scope     ScopeID\n\n");
  for (s = symbolTable; s != nullC; s = (struct symbolNode*)(s -> hh.next)) {
    printf("   %-5d\t %-15s\t %-10s\t %5c\t %7d\t %-10d\t\n", s -> symbolID, s -> name, s -> type, s -> symbolType, s -> scope, s->scopeID);
  }

  printf("\n==================================== Func Params ====================================\n\n");
  for (s = symbolTable; s != nullC; s = (struct symbolNode*)(s -> hh.next)) {
    if (s->symbolType == enumFunction) {
      int i;
      printf("Function '%s' params: ", s->name);
      for (i=0; i<s->last_param; i++) {
        int *a;
        a = &s->params_list[i];
        HASH_FIND_INT(symbolTable, a, tmp);
        printf("%s (type: %s, symbolID: %d) | ", tmp->name, tmp->type, tmp->symbolID);
      }
      printf("\n");
    }
  }
  printf("========================================================================================\n");
}

/* Clear symbol table mem allocation */
/* https://troydhanson.github.io/uthash/userguide.html#_delete_item */
void free_symbols_table(){
  symbolNode *s, *tmp;
  HASH_ITER(hh, symbolTable, s, tmp) {
    HASH_DEL(symbolTable, s);
    free(s->name);
    free(s->type);
    free(s->tacName);
    free(s);
  }
}

void free_scope_stack(){
  scopeStack *tmpStack;
  while (!STACK_EMPTY(scopeStackHead)) {
    STACK_POP(scopeStackHead, tmpStack);
    free(tmpStack);
  }
}