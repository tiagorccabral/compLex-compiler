#ifndef SEMANTIC_ANALYZER_H_
#define SEMANTIC_ANALYZER_H_

int semantic_errors;

/* verify if there is a function main, and if it is unique */
void semantic_verify_main();

/* verify if there is redefinition of ID */
void verify_id_redefinition();

/* verify if called function has correct params (amount and type) and in correct order */
void verify_func_call_params(char *currentFuncName, int amountOfParams, int line);

/* verify if term in expression has been declared */
void verify_declared_id(char *symbol, int line, int column);

/* calls semantic analysis functions that run after AST is built */
void post_parse_semantic_analysis();

#endif // SEMANTIC_ANALYZER_