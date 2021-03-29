%define parse.error verbose
%debug
%locations

%{

// Required libs declarations
#include <stdlib.h>
#include <stdio.h>

#include "symbol_table.h"

extern int yylex();
extern int yylex_destroy();
extern FILE *yyin;
extern int yynerrs;

extern int running_line_count;
extern int running_column_count;
extern int total_errors_count;

// Symbles table functions
extern void add_symbol_node();
extern void print_symbols();
extern void free_symbols_table();

void yyerror(const char *msg);

typedef struct parseNode {
  struct parseNode* rightBranch;
  struct parseNode* leftBranch;
  char* value;
  char* type;
} parseNode;

parseNode* parser_tree = NULL;

/* Global variables */
int globalCounterOfSymbols = 1;

%}

%union {
  char* str;
  struct parseNode* node;
}

// Others
%token<str> IDENTIFIER MAIN_FUNC
// Operations
%token ASSIGN
// Data types primitives / values
%token INT FLOAT EMPTY
// Data types
%token T_INT T_FLOAT T_ELEM T_SET
// Arithmetic Operators
%token ADD_OP SUB_OP MULT_OP DIV_OP
// Set Operators
%token ADD_SET_OP REMOVE_SET_OP EXISTS_IN_SET_OP IS_SET ADD_IN_OP
// Logical Operators
%token ILT ILTE IGT IGTE IDIFF IEQ
// Input/output
%token READ WRITE WRITELN
// Flux control
%token RETURN IF ELSE FOR SET_FORALL

// Parsing entry point start
%start entryPoint

// Types definitions
%type <node> compoundStatement
%type <node> variableInit typeSpecifier
%type <node> functionDefinition parameters

%%

entryPoint: programEntries { printf("Program entry point\n"); }
;

programEntries: programEntries variableInit {;}
  | variableInit {;}
  | programEntries functionDefinition {;}
  | functionDefinition {;}
  | error {;}
;

functionDefinition: typeSpecifier IDENTIFIER '(' parameters ')' compoundStatement {
  symbolParam symbol = { globalCounterOfSymbols, enumFunction, $2 };
  add_symbol_node(symbol);
  globalCounterOfSymbols++;
  printf("function definition \n");
}
  | typeSpecifier MAIN_FUNC '(' parameters ')' compoundStatement {
      symbolParam symbol = { globalCounterOfSymbols, enumFunction, $2 };
      add_symbol_node(symbol);
      globalCounterOfSymbols++;
      printf("main function definition \n");
    }
;

parameters: parameter {printf("parameter\n");}
  | %empty {printf("empty parameters\n");}
  | error {;}
;

parameter: typeSpecifier IDENTIFIER {
  symbolParam symbol = { globalCounterOfSymbols, enumParameter, $2 };
  add_symbol_node(symbol);
  globalCounterOfSymbols++;
  printf("parameter and identifier\n");
}
  | parameters ',' typeSpecifier IDENTIFIER {
    symbolParam symbol = { globalCounterOfSymbols, enumParameter, $4 };
    add_symbol_node(symbol);
    globalCounterOfSymbols++;
    printf("parameter, type and identifier\n");
  }
;

compoundStatement: '{' declaration statements '}' {printf("compount statement\n");}
;

declaration: declaration variableInit {printf("declaration\n");}
  | %empty {printf("empty declaration\n");}
;

statements: statements statement {printf("statements, statement\n");}
  | %empty {printf("empty statement\n");}
  | error {;}
;

statement: expression {printf("expression\n");}
  | inOutStatement {;}
  | fluxControlstatement {;}
  | iterationStatement {;}
;

inOutStatement: WRITE '(' variable ')' ';' {printf("IO: write identifier\n");}
  | WRITELN '(' variable ')' ';' {printf("IO: writeln identifier\n");}
  | READ '(' variable ')' ';' {printf("IO: read identifier\n");}
;

fluxControlstatement: RETURN expression {printf("return variable\n");}
  | RETURN ';' {printf("return null\n");}
  | IF '(' operationalExpression ')' compoundStatement {printf("if statement\n");}
  | IF '(' operationalExpression ')' compoundStatement  ELSE compoundStatement {printf("if/else statement\n");}
;

iterationStatement: FOR '(' operationalExpression ')' compoundStatement {printf("for loop one argument\n");}
  | FOR '(' expression expression forIncrement ')' compoundStatement {printf("for loop three arguments\n");}
  | SET_FORALL '(' term ADD_IN_OP operationalExpression ')' compoundStatement {printf("set forall loop\n");}
;

expression: operationalExpression ';' {;}
  | variableAssignment {;}
;

operationalExpression: arithmeticExpression {;}
  | logicalExpression {;}
  | setOperationalExpression {;}
  | term {;}
;

arithmeticExpression: operationalExpression ADD_OP term {printf("add operation\n");}
  | operationalExpression SUB_OP term {printf("subtraction operation\n");}
  | operationalExpression MULT_OP term {printf("multiplication operation\n");}
  | operationalExpression DIV_OP term {printf("division operation\n");}
;

logicalExpression: operationalExpression ILT term {printf("is less than operation\n");}
  | operationalExpression ILTE term {printf("is less or equal operation\n");}
  | operationalExpression IGT term {printf("is greater than operation\n");}
  | operationalExpression IGTE term {printf("is greater than or equal operation\n");}
  | operationalExpression IDIFF term {printf("is different than operation\n");}
  | operationalExpression IEQ term {printf("is equal to operation\n");}
;

setOperationalExpression: ADD_SET_OP '(' term ADD_IN_OP operationalExpression ')' {printf("add to set op\n");}
  | REMOVE_SET_OP '(' term ADD_IN_OP operationalExpression ')' {printf("remove from set op\n");}
  | EXISTS_IN_SET_OP '(' term ADD_IN_OP operationalExpression ')' {printf("exists el in set op\n");}
  | IS_SET '(' term ')' {printf("is set operator\n");}
;

variableAssignment: IDENTIFIER ASSIGN expression {printf("variable assignment\n");}
;

forIncrement: IDENTIFIER ASSIGN arithmeticExpression {printf("for loop increment\n");}
;

term: '(' operationalExpression ')' {printf("( operationalExp )\n");} 
  | variable {printf("variable\n");}  
  | functionCall {;}
  | EMPTY {printf("EMPTY constant value\n");}
  | FLOAT {printf("float value\n");}
  | INT {printf("int value\n");}
;

functionCall: IDENTIFIER '(' functionArguments ')' {printf("function call\n");}
;

functionArguments: callArguments {;}
  | %empty {printf("empty function argument\n");}
;

callArguments: callArguments ',' operationalExpression {printf("function arguments , term\n");}
  | operationalExpression {printf("function term argument\n");}
;

variableInit: typeSpecifier IDENTIFIER ';' {
  symbolParam symbol = { globalCounterOfSymbols, enumVariable, $2 };
  add_symbol_node(symbol);
  globalCounterOfSymbols++;
  printf("variable initialization %s\n", $2);
}
;

variable: IDENTIFIER {printf("variable\n");}
;

typeSpecifier: T_INT {printf("integer type\n");}
  | T_FLOAT {printf("float type\n");}
  | T_ELEM {printf("elem type\n");}
  | T_SET {printf("set type\n");}
;

%%

int main(int argc, char **argv) {
  if(argc > 1) {
    yyin = fopen(argv[1], "r");
  }
  else {
    yyin = stdin;
  }

  printf("\n----------------\n");
  printf("\nSyntatical analisys start\n\n");

  yyparse();
  fclose(yyin);

  int parseErrors = yynerrs;

  printf("\nReported amount of parse errors: %d\n", parseErrors);

  print_symbols();

  free_symbols_table();

  yylex_destroy();

  return 0;
}


void yyerror(const char* msg) {
  total_errors_count++;
  fprintf(stderr, "%s at line: %d, column: %d\n", msg, running_line_count, running_column_count);
}