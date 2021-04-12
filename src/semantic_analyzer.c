#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "semantic_analyzer.h"
#include "symbol_table.h"

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
    char *error_message = (char *)malloc(40 * sizeof(char));
    sprintf(error_message, "semantic error: main function was not declared");
    yyerror(error_message);
    free(error_message);
  }
}