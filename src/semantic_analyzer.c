#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "semantic_analyzer.h"
#include "symbol_table.h"

int semantic_errors = 0;

extern void yyerror(const char *msg);

void semantic_verify_main() {
  struct symbolNode *s;
  struct symbolNode *nullC = NULL;
  int foundMain = 0;

  for (s = symbolTable; s != nullC; s = (struct symbolNode*)(s -> hh.next)) {
    if (strcmp(s->name, "main") == 0) {
      foundMain = 1;
      break;
    }
  }
  if (foundMain == 0) {
    semantic_errors++;
    printf("semantic error, main function was not declared\n");
  }
}

void verify_id_redefinition() {
  struct symbolNode *s, *a;
  struct symbolNode *nullC = NULL;
  unsigned int symbolTableSize = HASH_COUNT(symbolTable);
  int checkedErrorMatrix[symbolTableSize][symbolTableSize]; /* used to mark comparisons already with errors */
  memset(checkedErrorMatrix, 0, sizeof(checkedErrorMatrix[0][0]) * symbolTableSize * symbolTableSize);

  for (s = symbolTable; s != nullC; s = (struct symbolNode*)(s -> hh.next)) {
    for (a = symbolTable; a != nullC; a = (struct symbolNode*)(a -> hh.next)) {
      if (checkedErrorMatrix[s->symbolID][a->symbolID] == 0 && s->symbolID != a->symbolID && strcmp(s->name, a->name) == 0 && s->scope == a->scope && s->scopeID == a->scopeID) {
        semantic_errors++;
        checkedErrorMatrix[s->symbolID][a->symbolID] = 1;
        checkedErrorMatrix[a->symbolID][s->symbolID] = 1;
        printf("semantic error, redefinition of '%s', at line: %d, column: %d\n", a->name, a->line, a->column);
      }
    }
  }
}

void verify_declared_id(char *symbol, int line, int column) {
  struct symbolNode *s, *tmp;
  struct symbolNode *nullC = NULL;
  int found = 0;

  scopeInfo current_scope = get_current_scope();

  for (s = symbolTable; s != nullC; s = (struct symbolNode*)(s -> hh.next)) {
    if (strcmp(s->name, symbol) == 0) {
      HASH_FIND_INT(symbolTable, s, tmp);  /* attempts to find a declaration of id on same scopeID */
      if (tmp != NULL && tmp->scopeID == current_scope.scopeID) {
        found = 1;
      }
    }
  }
  if (found == 0) {
    printf("semantic error, use of undeclared '%s', at line: %d, column: %d\n", symbol, line, column);
    semantic_errors++;
  }
}

void post_parse_semantic_analysis() {
  semantic_verify_main();
  verify_id_redefinition();
}