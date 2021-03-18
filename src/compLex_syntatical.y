%{

// Required libs declarations
#include <stdlib.h>
#include <stdio.h>

extern int yylex();
int yyerror(const char *msg);
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

%token QUOTES
%token IDENTIFIER ASSIGN
%token READ WRITE WRITELN 
%token INT FLOAT EMPTY
%token T_INT T_FLOAT T_ELEM T_SET

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

functionDefinition: typeSpecifier IDENTIFIER {}
  '(' parameters ')' compoundStatement {
    printf("function definition \n");
  }
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
  | inOutStatements {;}
;

inOutStatements: WRITE '(' QUOTES QUOTES ')' ';' {printf("IO: write\n");}
  | WRITELN '(' variable ')' ';' {printf("IO: writeln\n");}
  | READ '(' variable ')' ';' {printf("IO: read\n");}
;

expression: variable ASSIGN expression {printf("assignment Expression\n");}
  | operationalExpression ';' {;}
;

operationalExpression: term {;}
;

term: variable {printf("variable\n");}
  | '(' operationalExpression ')' {printf("( operationalExp )\n");}
  | EMPTY {printf("EMPTY constant value\n");}
  | FLOAT {printf("float value\n");}
  | INT {printf("int value\n");}
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

int yyerror(const char *msg) {
  printf("yyerror: %s\n", msg);
  return 0;
}

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
