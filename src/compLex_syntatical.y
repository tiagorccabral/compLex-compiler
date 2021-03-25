%{

// Required libs declarations
#include <stdlib.h>
#include <stdio.h>

extern int yylex();
extern void yyerror(const char *msg);
extern int yylex_destroy();
extern FILE *yyin;

typedef struct parseNode {
  struct parseNode* rightBranch;
  struct parseNode* leftBranch;
  char* value;
  char* type;
} parseNode;

parseNode* parser_tree = NULL;

%}

%union {
  char* str;
  struct parseNode* node;
}

// Others
%token IDENTIFIER MAIN_FUNC
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

%type <node> variableInit 
%type <node> functionDefinition

%%

entryPoint: programEntries { printf("Program entry point\n"); }
;

programEntries: programEntries variableInit {;}
  | variableInit {;}
  | programEntries functionDefinition {;}
  | functionDefinition {;}
;

functionDefinition: typeSpecifier IDENTIFIER '(' parameters ')' compoundStatement {printf("function definition \n");}
  | typeSpecifier MAIN_FUNC '(' parameters ')' compoundStatement {printf("main function definition \n");}
;

parameters: parameter {printf("parameter\n");}
  | %empty {printf("empty parameters\n");}
;

parameter: typeSpecifier IDENTIFIER {printf("parameter and identifier\n");}
  | parameters ',' typeSpecifier IDENTIFIER {printf("parameter, type and identifier\n");}
;

compoundStatement: '{' declaration statements '}' {printf("compount statement\n");}
;

declaration: declaration variableInit {printf("declaration\n");}
  | %empty {printf("empty declaration\n");}
;

statements: statements statement {printf("statements, statement\n");}
  | %empty {printf("empty statement\n");}
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
  | FOR '(' expression expression operationalExpression ')' compoundStatement {printf("for loop three arguments\n");}
  | SET_FORALL '(' term ADD_IN_OP operationalExpression ')' compoundStatement {printf("set forall loop\n");}
;

expression: operationalExpression ';' {;}
  | variable_assignment {;}
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

variable_assignment: IDENTIFIER ASSIGN expression {printf("variable assignment\n");}
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

variableInit: typeSpecifier IDENTIFIER ';' {printf("variable initialization\n");}
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
  yylex_destroy();

  return 0;
}
