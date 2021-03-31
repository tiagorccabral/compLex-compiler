%define parse.error verbose
%define parse.trace
%locations

%{

// Required libs declarations
#include <stdlib.h>
#include <stdio.h>

#include "symbol_table.h"
#include "parser_ast.h"

extern int yylex();
extern int yylex_destroy();
extern FILE *yyin;
extern int yynerrs;

extern int running_line_count;
extern int running_column_count;
extern int total_errors_count;

// Symbols table functions
extern void add_symbol_node();
extern void print_symbols();
extern void free_symbols_table();

// AST functions
extern parserNode* add_new_node();
extern void print_parser_ast(parserNode *node);
extern void free_parser_ast(parserNode *node);

parserNode* parser_ast = NULL;

void yyerror(const char *msg);

/* Global variables */
int globalCounterOfSymbols = 1;

%}

%union {
  char* str;
  struct parserNode* node;
}

// Others
%token<str> IDENTIFIER MAIN_FUNC
// Operations
%token<str> ASSIGN
// Data types primitives / values
%token<str> INT FLOAT EMPTY
// Data types
%token<str> T_INT T_FLOAT T_ELEM T_SET
// Arithmetic Operators
%token <str> ADD_OP SUB_OP MULT_OP DIV_OP
// Set Operators
%token<str> ADD_SET_OP REMOVE_SET_OP EXISTS_IN_SET_OP IS_SET ADD_IN_OP
// Logical Operators
%token<str> ILT ILTE IGT IGTE IDIFF IEQ
// Input/output
%token<str> READ WRITE WRITELN
// Flux control
%token<str> RETURN IF ELSE FOR SET_FORALL

// Parsing entry point start
%start entryPoint

// Types definitions
%type <node> programEntries compoundStatement declaration statements statement
%type <node> inOutStatement fluxControlstatement iterationStatement forIncrement
%type <node> expression operationalExpression setOperationalExpression
%type <node> arithmeticExpression logicalExpression
%type <node> variableAssignment
%type <node> variable variableInit typeSpecifier term
%type <node> functionDefinition functionCall functionArguments callArguments parameters parameter

%%

entryPoint: programEntries {
  parser_ast = $1;
  printf("Program entry point\n"); 
}
;

programEntries: programEntries variableInit {
    astParam astP = {
      .leftBranch = $1, .rightBranch = $2, .nodeType = enumLeftRightBranch, .astNodeClass="PROGRAM_ENTRIES VARIABLE_INIT"
    };
    $$ = add_ast_node(astP);
  }
  | variableInit {$$=$1;}
  | programEntries functionDefinition {
    astParam astP = { .leftBranch = $1, .rightBranch = $2, .nodeType = enumLeftRightBranch, .astNodeClass="PROGRAM_ENTRIES FUNCTION_DEFINITION" };
    $$ = add_ast_node(astP);
  }
  | functionDefinition {$$=$1;}
  | error {
      astParam astP = { .type = "ERROR", .value = "ERROR", .nodeType = enumValueTypeOnly, .astNodeClass="ERROR" };
      $$ = add_ast_node(astP);
  }
;

functionDefinition: typeSpecifier IDENTIFIER '(' parameters ')' compoundStatement {
    astParam astP = {
      .leftBranch = $1, .middle1Branch = $4, .rightBranch = $6, .type= "IDENTIFIER", .value=$2, .nodeType = enumLeftRightMiddleBranch, .astNodeClass="FUNCTION_DEFINITION" 
    };
    $$ = add_ast_node(astP);
    symbolParam symbol = { globalCounterOfSymbols, enumFunction, $2 };
    add_symbol_node(symbol);
    globalCounterOfSymbols++;
    printf("function definition \n");
  }
  | typeSpecifier MAIN_FUNC '(' parameters ')' compoundStatement {
    astParam astP = { 
      .leftBranch = $1, .middle1Branch = $4, .rightBranch = $6, .type= "MAIN", .value=$2, .nodeType = enumLeftRightMiddleBranch, .astNodeClass="FUNCTION_DEFINITION" 
    };
    $$ = add_ast_node(astP);
    symbolParam symbol = { globalCounterOfSymbols, enumFunction, $2 };
    add_symbol_node(symbol);
    globalCounterOfSymbols++;
    printf("main function definition \n");
  }
;

parameters: parameter {
    $$ = $1;
    printf("parameter\n");
  }
  | %empty {
    $$ = NULL;
    printf("empty parameters\n");
  }
  | error {
    astParam astP = { .type = "ERROR", .value = "ERROR", .nodeType = enumValueTypeOnly, .astNodeClass="ERROR" };
    $$ = add_ast_node(astP);
  }
;

parameter: typeSpecifier IDENTIFIER {
    astParam astP = { .leftBranch = $1, .type=$2, .value = $2, .nodeType = enumValueLeftBranch, .astNodeClass="PARAMETER TYPE_SPECIFIER IDENTIFIER" };
    $$ = add_ast_node(astP);
    symbolParam symbol = { globalCounterOfSymbols, enumParameter, $2 };
    add_symbol_node(symbol);
    globalCounterOfSymbols++;
    printf("parameter and identifier\n");
  }
  | parameters ',' typeSpecifier IDENTIFIER {
    astParam astP = {
      .leftBranch = $1, .rightBranch = $3, .nodeType = enumLeftRightBranch, .astNodeClass="PARAMETER PARAMETERS TYPE_SPECIFIER"
    };
    $$ = add_ast_node(astP);
    symbolParam symbol = { globalCounterOfSymbols, enumParameter, $4 };
    add_symbol_node(symbol);
    globalCounterOfSymbols++;
    printf("parameter, type and identifier\n");
  }
;

compoundStatement: '{' declaration statements '}' {
  astParam astP = {
    .leftBranch = $2, .rightBranch = $3, .nodeType = enumLeftRightBranch, .astNodeClass="COMPOUND_STATEMENT"
  };
  $$ = add_ast_node(astP);
  printf("compount statement\n");
}
;

declaration: declaration variableInit {
    astParam astP = {
      .leftBranch = $1, .rightBranch = $2, .nodeType = enumLeftRightBranch, .astNodeClass="DECLARATION"
    };
    $$ = add_ast_node(astP);
    printf("declaration\n");
  }
  | %empty {
    $$ = NULL;
    printf("empty declaration\n");
  }
;

statements: statements statement {
    astParam astP = {
      .leftBranch = $1, .rightBranch = $2, .nodeType = enumLeftRightBranch, .astNodeClass="STATEMENTS"
    };
    $$ = add_ast_node(astP);
    printf("statements, statement\n");
  }
  | %empty {
    $$ = NULL;
    printf("empty statement\n");
  }
  | error {
    astParam astP = { .type = "ERROR", .value = "ERROR", .nodeType = enumValueTypeOnly, .astNodeClass="ERROR" };
    $$ = add_ast_node(astP);
  }
;

statement: expression {$$ = $1;}
  | inOutStatement {$$ = $1;}
  | fluxControlstatement {$$ = $1;}
  | iterationStatement {$$ = $1;}
;

inOutStatement: WRITE '(' variable ')' ';' {
    astParam astP = { .leftBranch = $3, .type=$1, .value = $1, .nodeType = enumValueLeftBranch, .astNodeClass="IN_OUT_STATEMENT" };
    $$ = add_ast_node(astP);
    printf("IO: write identifier\n");
  }
  | WRITELN '(' variable ')' ';' {
    astParam astP = { .leftBranch = $3, .type=$1, .value = $1, .nodeType = enumValueLeftBranch, .astNodeClass="IN_OUT_STATEMENT" };
    $$ = add_ast_node(astP);
    printf("IO: writeln identifier\n");
  }
  | READ '(' variable ')' ';' {
    astParam astP = { .leftBranch = $3, .type=$1, .value = $1, .nodeType = enumValueLeftBranch, .astNodeClass="IN_OUT_STATEMENT" };
    $$ = add_ast_node(astP);
    printf("IO: read identifier\n");
  }
;

fluxControlstatement: RETURN expression {
    astParam astP = { .leftBranch = $2, .type="RETURN", .value = $1, .nodeType = enumValueLeftBranch, .astNodeClass="FLUX_CONTROL_STATEMENT RETURN_EXP" };
    $$ = add_ast_node(astP);
    printf("return expression\n");
  }
  | RETURN ';' {
    astParam astP = { .type = "RETURN", .value = $1, .nodeType = enumValueTypeOnly, .astNodeClass="FLUX_CONTROL_STATEMENT RETURN_NULL" };
    $$ = add_ast_node(astP);
    printf("return null\n");
  }
  | IF '(' operationalExpression ')' compoundStatement {
    astParam astP = {
      .leftBranch = $3, .rightBranch = $5, .nodeType = enumLeftRightBranch, .astNodeClass="FLUX_CONTROL_STATEMENT IF"
    };
    $$ = add_ast_node(astP);
    printf("if statement\n");
  }
  | IF '(' operationalExpression ')' compoundStatement  ELSE compoundStatement {
    astParam astP = {
      .leftBranch = $3, .middle1Branch = $5, .rightBranch = $7, .type= "IF/ELSE", .value=$1, .nodeType = enumLeftRightMiddleBranch, .astNodeClass="FLUX_CONTROL_STATEMENT IF_ELSE" 
    };
    $$ = add_ast_node(astP);
    printf("if/else statement\n");
  }
;

iterationStatement: FOR '(' operationalExpression ')' compoundStatement {
    astParam astP = {
      .leftBranch = $3, .rightBranch = $5, .nodeType = enumLeftRightBranch, .astNodeClass="ITERATION_STATEMENT FOR_ONE_ARGUMENT"
    };
    $$ = add_ast_node(astP);
    printf("for loop one argument\n");
  }
  | FOR '(' expression expression forIncrement ')' compoundStatement {
    astParam astP = {
      .leftBranch = $3, .middle1Branch=$4, .middle2Branch=$5, .rightBranch = $7, .type= "FOR", .value=$1, .nodeType = enumLeftRightMiddle1And2Branch, .astNodeClass="ITERATION_STATEMENT FOR_THREE_ARGUMENTS"
    };
    $$ = add_ast_node(astP);
    printf("for loop three arguments\n");
  }
  | SET_FORALL '(' term ADD_IN_OP operationalExpression ')' compoundStatement {
    astParam astP = {
      .leftBranch = $3, .middle1Branch = $5, .rightBranch = $7, .type="SET_FORALL", .value=$1, .nodeType = enumLeftRightMiddleBranch, .astNodeClass="ITERATION_STATEMENT FORALL" 
    };
    $$ = add_ast_node(astP);
    printf("set forall loop\n");
  }
;

expression: operationalExpression ';' {$$=$1;}
  | variableAssignment {$$=$1;}
;

operationalExpression: arithmeticExpression {$$=$1;}
  | logicalExpression {$$=$1;}
  | setOperationalExpression {$$=$1;}
  | term {$$=$1;}
;

arithmeticExpression: operationalExpression ADD_OP term {
    astParam astP = {
      .leftBranch = $1, .rightBranch = $3, .nodeType = enumLeftRightBranch, .astNodeClass="ARITHMETIC_EXPRESSION ADD_OP"
    };
    $$ = add_ast_node(astP);
    printf("add operation\n");
  }
  | operationalExpression SUB_OP term {
    astParam astP = {
      .leftBranch = $1, .rightBranch = $3, .nodeType = enumLeftRightBranch, .astNodeClass="ARITHMETIC_EXPRESSION SUB_OP"
    };
    $$ = add_ast_node(astP);
    printf("subtraction operation\n");
  }
  | operationalExpression MULT_OP term {
    astParam astP = {
      .leftBranch = $1, .rightBranch = $3, .nodeType = enumLeftRightBranch, .astNodeClass="ARITHMETIC_EXPRESSION MULT_OP"
    };
    $$ = add_ast_node(astP);
    printf("multiplication operation\n");
  }
  | operationalExpression DIV_OP term {
    astParam astP = {
      .leftBranch = $1, .rightBranch = $3, .nodeType = enumLeftRightBranch, .astNodeClass="ARITHMETIC_EXPRESSION DIV_OP"
    };
    $$ = add_ast_node(astP);
    printf("division operation\n");
  }
;

logicalExpression: operationalExpression ILT term {
    astParam astP = {
      .leftBranch = $1, .rightBranch = $3, .nodeType = enumLeftRightBranch, .astNodeClass="LOGICAL_EXPRESSION IS_LESS_THAN"
    };
    $$ = add_ast_node(astP);
    printf("is less than operation\n");
  }
  | operationalExpression ILTE term {
    astParam astP = {
      .leftBranch = $1, .rightBranch = $3, .nodeType = enumLeftRightBranch, .astNodeClass="LOGICAL_EXPRESSION IS_LESS_THAN_EQUAL"
    };
    $$ = add_ast_node(astP);
    printf("is less or equal operation\n");
  }
  | operationalExpression IGT term {
    astParam astP = {
      .leftBranch = $1, .rightBranch = $3, .nodeType = enumLeftRightBranch, .astNodeClass="LOGICAL_EXPRESSION IS_GREATER_THAN"
    };
    $$ = add_ast_node(astP);
    printf("is greater than operation\n");
  }
  | operationalExpression IGTE term {
    astParam astP = {
      .leftBranch = $1, .rightBranch = $3, .nodeType = enumLeftRightBranch, .astNodeClass="LOGICAL_EXPRESSION IS_GREATER_THAN_EQUAL"
    };
    $$ = add_ast_node(astP);
    printf("is greater than or equal operation\n");
  }
  | operationalExpression IDIFF term {
    astParam astP = {
      .leftBranch = $1, .rightBranch = $3, .nodeType = enumLeftRightBranch, .astNodeClass="LOGICAL_EXPRESSION IS_DIFFERENT_THAN"
    };
    $$ = add_ast_node(astP);
    printf("is different than operation\n");
  }
  | operationalExpression IEQ term {
    astParam astP = {
      .leftBranch = $1, .rightBranch = $3, .nodeType = enumLeftRightBranch, .astNodeClass="LOGICAL_EXPRESSION IS_EQUAL_THAN"
    };
    $$ = add_ast_node(astP);
    printf("is equal to operation\n");
  }
;

setOperationalExpression: ADD_SET_OP '(' term ADD_IN_OP operationalExpression ')' {
    astParam astP = {
      .leftBranch = $3, .rightBranch = $5, .nodeType = enumLeftRightBranch, .astNodeClass="SET_OPERATION_EXPRESSION ADD_SET_OP"
    };
    $$ = add_ast_node(astP);
    printf("add to set op\n");
  }
  | REMOVE_SET_OP '(' term ADD_IN_OP operationalExpression ')' {
    astParam astP = {
      .leftBranch = $3, .rightBranch = $5, .nodeType = enumLeftRightBranch, .astNodeClass="SET_OPERATION_EXPRESSION REMOVE_SET_OP"
    };
    $$ = add_ast_node(astP);
    printf("remove from set op\n");
  }
  | EXISTS_IN_SET_OP '(' term ADD_IN_OP operationalExpression ')' {
    astParam astP = {
      .leftBranch = $3, .rightBranch = $5, .nodeType = enumLeftRightBranch, .astNodeClass="SET_OPERATION_EXPRESSION EXISTS_IN_SET_OP"
    };
    $$ = add_ast_node(astP);
    printf("exists el in set op\n");
  }
  | IS_SET '(' term ')' {
    astParam astP = { .leftBranch = $3, .type="IDENTIFIER", .value = $1, .nodeType = enumValueLeftBranch, .astNodeClass="SET_OPERATION_EXPRESSION IS_SET" };
    $$ = add_ast_node(astP);
    printf("is set operator\n");
  }
;

variableAssignment: IDENTIFIER ASSIGN expression {
    astParam astP = { .leftBranch = $3, .type="IDENTIFIER", .value = $1, .nodeType = enumValueLeftBranch, .astNodeClass="VARIABLE_ASSIGNMENT" };
    $$ = add_ast_node(astP);
    printf("variable assignment\n");
  }
;

forIncrement: IDENTIFIER ASSIGN arithmeticExpression {
  astParam astP = { .leftBranch = $3, .type="IDENTIFIER", .value = $1, .nodeType = enumValueLeftBranch, .astNodeClass="FOR_INCREMENT" };
  $$ = add_ast_node(astP);
  printf("for loop increment\n");
}
;

term: '(' operationalExpression ')' {
    $$=$2;
    printf("( operationalExp )\n");
  }
  | variable {
    $$=$1;
    printf("variable\n");
  }
  | functionCall {$$=$1;}
  | EMPTY {
    astParam astP = { .type = "EMPTY", .value = $1, .nodeType = enumValueTypeOnly, .astNodeClass="TERM" };
    $$ = add_ast_node(astP);
    printf("EMPTY constant value\n");
  }
  | FLOAT {
    astParam astP = { .type = "FLOAT", .value = $1, .nodeType = enumValueTypeOnly, .astNodeClass="TERM" };
    $$ = add_ast_node(astP);
    printf("float value\n");
  }
  | INT {
    astParam astP = { .type = "INT", .value = $1, .nodeType = enumValueTypeOnly, .astNodeClass="TERM" };
    $$ = add_ast_node(astP);
    printf("int value\n");
  }
;

functionCall: IDENTIFIER '(' functionArguments ')' {
  astParam astP = { .leftBranch = $3, .type="IDENTIFIER", .value = $1, .nodeType = enumValueLeftBranch, .astNodeClass="FUNCTION_CALL" };
  $$ = add_ast_node(astP);
  printf("function call\n");
}
;

functionArguments: callArguments {$$=$1;}
  | %empty {
    $$ = NULL;
    printf("empty function argument\n");
  }
;

callArguments: callArguments ',' operationalExpression {
    astParam astP = {
      .leftBranch = $1, .rightBranch = $3, .nodeType = enumLeftRightBranch, .astNodeClass="CALL_ARGUMENTS MULTIPLE_ARGUMENTS"
    };
    $$ = add_ast_node(astP);
    printf("function arguments , term\n");
  }
  | operationalExpression {
    $$ = $1;
    printf("function term argument\n");
  }
;

variableInit: typeSpecifier IDENTIFIER ';' {
  astParam astP = { .leftBranch = $1, .type="IDENTIFIER", .value = $2, .nodeType = enumValueLeftBranch, .astNodeClass="VARIABLE_INIT" };
  $$ = add_ast_node(astP);
  symbolParam symbol = { globalCounterOfSymbols, enumVariable, $2 };
  add_symbol_node(symbol);
  globalCounterOfSymbols++;
  printf("variable initialization %s\n", $2);
}
;

variable: IDENTIFIER {
  astParam astP = { .type = "IDENTIFIER", .value = $1, .nodeType = enumValueTypeOnly, .astNodeClass="IDENTIFIER" };
  $$ = add_ast_node(astP);
  printf("variable\n");
}
;

typeSpecifier: T_INT {
    astParam astP = { .type = "T_INT", .value = $1, .nodeType = enumValueTypeOnly, .astNodeClass="TYPE_SPECIFIER" };
    $$ = add_ast_node(astP);
    printf("integer type\n");
  }
  | T_FLOAT {
    astParam astP = { .type = "T_FLOAT", .value = $1, .nodeType = enumValueTypeOnly, .astNodeClass="TYPE_SPECIFIER" };
    $$ = add_ast_node(astP);
    printf("float type\n");
  }
  | T_ELEM {
    astParam astP = { .type = "T_ELEM", .value = $1, .nodeType = enumValueTypeOnly, .astNodeClass="TYPE_SPECIFIER" };
    $$ = add_ast_node(astP);
    printf("elem type\n");
  }
  | T_SET {
    astParam astP = { .type = "T_SET", .value = $1, .nodeType = enumValueTypeOnly, .astNodeClass="TYPE_SPECIFIER" };
    $$ = add_ast_node(astP);
    printf("set type\n");
  }
;

%%

int main(int argc, char **argv) {
  if(argc > 1) {
    yyin = fopen(argv[1], "r");
  }
  else {
    yyin = stdin;
  }

  parser_ast = NULL;

  printf("\n----------------\n");
  printf("\nSyntatical analisys start\n\n");

  yyparse();
  fclose(yyin);

  int parseErrors = yynerrs;

  printf("\nReported amount of parse errors: %d\n", parseErrors);

  print_symbols();
  free_symbols_table();

  printf("\n=================== Parser AST ====================\n\n");
  print_parser_ast(parser_ast);
  free_parser_ast(parser_ast);

  yylex_destroy();

  return 0;
}


void yyerror(const char* msg) {
  total_errors_count++;
  fprintf(stderr, "%s at line: %d, column: %d\n", msg, running_line_count, running_column_count);
}