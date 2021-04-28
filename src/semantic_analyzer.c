#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "semantic_analyzer.h"
#include "symbol_table.h"

int semantic_errors = 0;

int found_return_statement = 0;

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
  int checkedErrorMatrix[symbolTableSize]; /* used to mark comparisons already with errors */
  memset(checkedErrorMatrix, 0, sizeof(checkedErrorMatrix[0]) * symbolTableSize);

  for (s = symbolTable; s != nullC; s = (struct symbolNode*)(s -> hh.next)) {
    for (a = symbolTable; a != nullC; a = (struct symbolNode*)(a -> hh.next)) {
      if (checkedErrorMatrix[s->symbolID - 1] == 0 && s->symbolID != a->symbolID && strcmp(s->name, a->name) == 0 && ((s->scope == a->scope && s->scopeID == a->scopeID) || (s->scope == a->scope && s->symbolType == enumFunction && a->symbolType == enumFunction))) {
        checkedErrorMatrix[a->symbolID - 1] = 1; /* mark symbol as already compared */
        semantic_errors++;
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
    for (s = symbolTable; s != nullC; s = (struct symbolNode*)(s -> hh.next)) {
      if (strcmp(s->name, symbol) == 0 && s->scope < current_scope.level) { /* looks on higher scope */
        found = 1;
      }
      if (strcmp(s->name, symbol) == 0 && s->symbolType == enumFunction && s->scope == 0) { /* looks for global functions */
        found = 1;
      }
    }
  }
  if (found == 0) {
    printf("semantic error, use of undeclared '%s', at line: %d, column: %d\n", symbol, line, column);
    semantic_errors++;
  }
}

void verify_func_call_params(char *currentFuncName, int amountOfParams, int params_list[253], int line) {
  struct symbolNode *s;
  struct symbolNode *nullC = NULL;
  int i;

  for (s = symbolTable; s != nullC; s = (struct symbolNode*)(s -> hh.next)) {
    if (strcmp(s->name, currentFuncName) == 0) {
      if (amountOfParams != (s->last_param)) { /* checks if the amount of params passed by function caller is correct */
        semantic_errors++;
        printf("semantic error, function '%s' expected %d param(s) but got %d, at line %d\n", currentFuncName, (s->last_param), amountOfParams, line);
        break;
      }
      for (i=0;i<amountOfParams;i++) {
        if(params_list[i] > 0) { /* param its a symbol (ID) */
          struct symbolNode *tmp, *tmp2;
          int *symbolkey, *symbolkeyPassedParam;
          symbolkey = &s->params_list[i];
          symbolkeyPassedParam = &params_list[i];
          HASH_FIND_INT(symbolTable, symbolkey, tmp);
          HASH_FIND_INT(symbolTable, symbolkeyPassedParam, tmp2);
          if (strcmp(tmp->type,tmp2->type) != 0) { /* verify if expected symbol type is the same as passed symbol type */
            semantic_errors++;
            printf("semantic error, function '%s' param on position %d expected to be '%s' but got '%s', at line %d\n",currentFuncName, i+1, tmp->type, tmp2->type, line);
          }
        } else if (params_list[i] < 0) { /* param its a primitive type */
          struct symbolNode *tmp;
          int *symbolkey;
          symbolkey = &s->params_list[i];
          HASH_FIND_INT(symbolTable, symbolkey, tmp);
          if (params_list[i] == -1 && strcmp(tmp->type,"int") != 0) { /* passed param its an integer, but func signature param is not */
            semantic_errors++;
            printf("semantic error, function '%s' param on position %d expected to be '%s' but got 'int', at line %d\n",currentFuncName, i+1, tmp->type, line);
          } else if (params_list[i] == -2 && strcmp(tmp->type,"float") != 0) { /* param its a float */
            semantic_errors++;
            printf("semantic error, function '%s' param on position %d expected to be '%s' but got 'float', at line %d\n",currentFuncName, i+1, tmp->type, line);
          }
        }
      }
    }
  }
}

void verify_return_statement(char *name, int found_return_statement, char *expected_return_type, parserNode *returned_type, scopeInfo currentReturnScope, int line) {
  if(!returned_type) {
    semantic_errors++;
    printf("semantic error, function '%s' (line: %d) does not have return statement\n", name, line==0?line+1:line);
    return;
  } else if (found_return_statement == 0) {
    semantic_errors++;
    printf("semantic error, function '%s' (line: %d) does not have return statement\n", name, line==0?line+1:line);
    return;
  }
  if (strcmp(returned_type->type, "IDENTIFIER")!=0) {
    if (strcmp(expected_return_type, "T_INT")==0 && strcmp(returned_type->type, "INT")!=0) {
      semantic_errors++;
      printf("semantic error, function '%s' expected an 'int' type return, but got '%s', (line: %d)\n", name, returned_type->type, line);
    } else if (strcmp(expected_return_type, "T_FLOAT")==0 && strcmp(returned_type->type, "FLOAT")!=0) {
      semantic_errors++;
      printf("semantic error, function '%s' expected a 'float' type return, but got '%s', (line: %d)\n", name, returned_type->type, line);
    } else if (strcmp(expected_return_type, "T_SET")==0 && (strcmp(returned_type->type, "SET")!=0 && (strcmp(returned_type->type, "ELEM")!=0))) {
      semantic_errors++;
      printf("semantic error, function '%s' expected a 'set' type return, but got '%s', (line: %d)\n", name, returned_type->type, line);
    } else if (strcmp(expected_return_type, "T_ELEM")==0 && (strcmp(returned_type->type, "ELEM")!=0)) {
      semantic_errors++;
      printf("semantic error, function '%s' expected an 'elem' type return, but got '%s', (line: %d)\n", name, returned_type->type, line);
    }
  } else if (strcmp(returned_type->type, "IDENTIFIER")==0 && returned_type->value) {
    struct symbolNode *tmp;
    int symbolID, *symbolKey;
    symbolID = get_symbolID_by_name_and_current_scope(returned_type->value, currentReturnScope.scopeID, currentReturnScope.level);
    if (symbolID == -1) return; /* symbol is undeclared (error) */
    symbolKey = &symbolID;
    HASH_FIND_INT(symbolTable, symbolKey, tmp);
    if (strcmp(expected_return_type, "T_INT")==0 && strcmp(tmp->type, "int")!=0) {
      semantic_errors++;
      printf("semantic error, function '%s' (line: %d) expected an 'int' type return, but got '%s'\n", name, line, tmp->type);
    } else if (strcmp(expected_return_type, "T_FLOAT")==0 && strcmp(tmp->type, "float")!=0) {
      semantic_errors++;
      printf("semantic error, function '%s' (line: %d) expected a 'float' type return, but got '%s'\n", name, line, tmp->type);
    } else if (strcmp(expected_return_type, "T_SET")==0 && (strcmp(tmp->type, "set")!=0 && (strcmp(tmp->type, "elem")!=0))) {
      printf("expected return type: %s, returned type: %s compare result: %d\n", expected_return_type, returned_type->type, strcmp(tmp->type, "set"));
      semantic_errors++;
      printf("semantic error, function '%s' (line: %d) expected a 'set' type return, but got '%s'\n", name, line, tmp->type);
    } else if (strcmp(expected_return_type, "T_ELEM")==0 && (strcmp(tmp->type, "elem")!=0)) {
      semantic_errors++;
      printf("semantic error, function '%s' (line: %d) expected an 'elem' type return, but got '%s'\n", name, line, tmp->type);
    }
  }
}

void post_parse_semantic_analysis() {
  semantic_verify_main();
  verify_id_redefinition();
}