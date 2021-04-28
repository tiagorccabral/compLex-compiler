#ifndef SEMANTIC_ANALYZER_H_
#define SEMANTIC_ANALYZER_H_

#include "parser_ast.h"
#include "symbol_table.h"

int semantic_errors;

int found_return_statement; /* aux vars to verify presence of return statements*/

/* verify if there is a function main, and if it is unique */
void semantic_verify_main();

/* verify if there is redefinition of ID */
void verify_id_redefinition();

/* verify if called function has correct params (amount and type) and in correct order */
void verify_func_call_params(char *currentFuncName, int amountOfParams, int params_list[253], int line);

/* verify if term in expression has been declared */
void verify_declared_id(char *symbol, int line, int column);

/* verifies if function has return statement */
void verify_return_statement(char *name, int found_return_statement, char *expected_return_type, parserNode *returned_type, scopeInfo currentReturnScope, int line);

/* calls semantic analysis functions that run after AST is built */
void post_parse_semantic_analysis();

#endif // SEMANTIC_ANALYZER_