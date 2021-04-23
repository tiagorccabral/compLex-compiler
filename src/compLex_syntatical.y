%define parse.error verbose
%define parse.trace
%locations

%{

// Required libs declarations
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "symbol_table.h"
#include "parser_ast.h"
#include "semantic_analyzer.h"
#include "utils.h"

#define DEBUG 0 // controls debug msgs, see utils.h

extern int yylex();
extern int yylex_destroy();
extern FILE *yyin;
extern int yynerrs;

extern int running_line_count;
extern int running_column_count;
extern int total_errors_count;

// AST functions
extern parserNode* add_new_node();
extern void print_parser_ast(parserNode *node, int level);
extern void free_parser_ast(parserNode *node);

// Utils functions
extern void print_parser_msg(char* msg, int debug);

parserNode* parser_ast = NULL;

typedef struct currentParsedFunction {
  char *name;
  int scopeID;
  int lastParamPosition;
}currentParsedFunction;

typedef struct calledFunction {
  char *name;
  int amountOfParamsCalled;
  int passedParams[253];
}calledFunction;

currentParsedFunction currentFunction = {"", 0, 0};

calledFunction currentCalledFunction = {"", 0};

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
%token<str> INT FLOAT EMPTY STR
// Data types
%token<str> T_INT T_FLOAT T_ELEM T_SET
// Arithmetic Operators
%token <str> ADD_OP SUB_OP MULT_OP DIV_OP
// Set Operators
%token<str> ADD_SET_OP REMOVE_SET_OP EXISTS_IN_SET_OP IS_SET ADD_IN_OP
// Logical Operators
%token<str> ILT ILTE IGT IGTE IDIFF IEQ AND OR NEG
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
%type <node> variableAssignment localStatetements
%type <node> variable variableInit typeSpecifier term
%type <node> functionDefinition functionCall functionArguments callArguments parameters parameter

%%

entryPoint: programEntries {
  parser_ast = $1;
  print_parser_msg("Program entry point\n", DEBUG);
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

functionDefinition: typeSpecifier IDENTIFIER {
    symbolParam symbol = { .symbolID = globalCounterOfSymbols, .symbolType=enumFunction, .type = $1->value, .name = $2, .line = running_line_count, .column = running_column_count };
    add_symbol_node(symbol);
    globalCounterOfSymbols++;
    scopeInfo current_scope = get_current_scope();
    currentFunction.scopeID = current_scope.scopeID;
    currentFunction.name = $2;
    currentFunction.lastParamPosition = 0;
  } '(' parameters ')' compoundStatement {
    create_new_scope_level();
    astParam astP = {
      .leftBranch = $1, .middle1Branch = $5, .rightBranch = $7, .type= "IDENTIFIER", .value=$2, .nodeType = enumLeftRightMiddleBranch, .astNodeClass="FUNCTION_DEFINITION" 
    };
    $$ = add_ast_node(astP);
    print_parser_msg("Function definition \n", DEBUG);
  }
  | typeSpecifier MAIN_FUNC {
      symbolParam symbol = { .symbolID = globalCounterOfSymbols, .symbolType=enumFunction, .type = $1->value, .name = $2, .line = running_line_count, .column = running_column_count};
      add_symbol_node(symbol);
      globalCounterOfSymbols++;
      scopeInfo current_scope = get_current_scope();
      currentFunction.scopeID = current_scope.scopeID;
      currentFunction.name = $2;
      currentFunction.lastParamPosition = 0;
  } '(' parameters ')' compoundStatement {
    create_new_scope_level();
    astParam astP = { 
      .leftBranch = $1, .middle1Branch = $5, .rightBranch = $7, .type= "MAIN", .value=$2, .nodeType = enumLeftRightMiddleBranch, .astNodeClass="FUNCTION_DEFINITION" 
    };
    $$ = add_ast_node(astP);
    print_parser_msg("Main function definition \n", DEBUG);
  }
;

parameters: parameter {
    $$ = $1;
    print_parser_msg("Parameter\n", DEBUG);
  }
  | %empty {
    $$ = NULL;
    print_parser_msg("Empty parameters\n", DEBUG);
  }
  | error {
    astParam astP = { .type = "ERROR", .value = "ERROR", .nodeType = enumValueTypeOnly, .astNodeClass="ERROR" };
    $$ = add_ast_node(astP);
  }
;

parameter: parameters ',' typeSpecifier IDENTIFIER {
    astParam astP = {
      .leftBranch = $1, .rightBranch = $3, .nodeType = enumLeftRightBranch, .astNodeClass="PARAMETER PARAMETERS TYPE_SPECIFIER"
    };
    $$ = add_ast_node(astP);
    astParam astP2 = {
      .leftBranch = $1, .rightBranch = $3, .type=$$->rightBranch->value, .value = $4, .nodeType = enumLeftRightValueBranch, .astNodeClass="PARAMETER PARAMETERS TYPE_SPECIFIER"
    };
    $$ = add_ast_node(astP2);
    symbolParam symbol = { .symbolID = globalCounterOfSymbols, .symbolType=enumParameter, .type = $$->rightBranch->value, .name = $4, .line= running_line_count, .column= running_column_count, .associated_function=currentFunction.name, .last_param=currentFunction.lastParamPosition, .associated_function_scope=currentFunction.scopeID};
    add_symbol_node(symbol);
    currentFunction.lastParamPosition = currentFunction.lastParamPosition + 1;
    globalCounterOfSymbols++;
    print_parser_msg("Parameter, type and identifier\n", DEBUG);
  }
  | typeSpecifier IDENTIFIER {
    astParam astP = { .leftBranch = $1, .type=$2, .value = $2, .nodeType = enumValueLeftBranch, .astNodeClass="PARAMETER TYPE_SPECIFIER IDENTIFIER" };
    $$ = add_ast_node(astP);
    astParam astP2 = { .leftBranch = $1, .type=$$->leftBranch->value, .value = $2, .nodeType = enumValueLeftBranch, .astNodeClass="PARAMETER TYPE_SPECIFIER IDENTIFIER" };
    $$ = add_ast_node(astP2);
    symbolParam symbol = { .symbolID = globalCounterOfSymbols, .symbolType=enumParameter, .type = $$->leftBranch->value, .name = $2, .line= running_line_count, .column= running_column_count, .associated_function=currentFunction.name, .last_param=currentFunction.lastParamPosition, .associated_function_scope=currentFunction.scopeID};
    add_symbol_node(symbol);
    currentFunction.lastParamPosition = currentFunction.lastParamPosition + 1;
    globalCounterOfSymbols++;
    print_parser_msg("Parameter and identifier\n", DEBUG);
  }
;

compoundStatement: '{' declaration statements '}' {
  astParam astP = {
    .leftBranch = $2, .rightBranch = $3, .nodeType = enumLeftRightBranch, .astNodeClass="COMPOUND_STATEMENT"
  };
  $$ = add_ast_node(astP);
  decrease_scope_level();
  print_parser_msg("Compound statement\n", DEBUG);
}
;

declaration: declaration variableInit {
    astParam astP = {
      .leftBranch = $1, .rightBranch = $2, .nodeType = enumLeftRightBranch, .astNodeClass="DECLARATION"
    };
    $$ = add_ast_node(astP);
    print_parser_msg("Declaration\n", DEBUG);
  }
  | %empty {
    $$ = NULL;
    print_parser_msg("Empty declaration\n", DEBUG);
  }
;

statements: statements statement {
    astParam astP = {
      .leftBranch = $1, .rightBranch = $2, .nodeType = enumLeftRightBranch, .astNodeClass="STATEMENTS"
    };
    $$ = add_ast_node(astP);
    print_parser_msg("Statements, statement\n", DEBUG);
  }
  | %empty {
    $$ = NULL;
    print_parser_msg("Empty statement\n", DEBUG);
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
  | localStatetements {$$ = $1;}
;

inOutStatement: WRITE '(' STR ')' ';' {
    astParam astP = { .type = "WRITE", .value = $3, .nodeType = enumValueTypeOnly, .astNodeClass="WRITE STRING" };
    $$ = add_ast_node(astP);
    print_parser_msg("IO: write string\n", DEBUG);
  }
  | WRITE '(' variable ')' ';' {
    astParam astP = { .leftBranch = $3, .type=$1, .value = $1, .nodeType = enumValueLeftBranch, .astNodeClass="WRITE IDENTIFIER" };
    $$ = add_ast_node(astP);
    print_parser_msg("IO: write identifier\n", DEBUG);
  }
  | WRITELN '(' STR ')' ';' {
    astParam astP = { .type = "WRITELN", .value = $3, .nodeType = enumValueTypeOnly, .astNodeClass="WRITELN STRING" };
    $$ = add_ast_node(astP);
    print_parser_msg("IO: writeln string\n", DEBUG);
  }
  | WRITELN '(' variable ')' ';' {
    astParam astP = { .leftBranch = $3, .type=$1, .value = $1, .nodeType = enumValueLeftBranch, .astNodeClass="WRITELN IDENTIFIER" };
    $$ = add_ast_node(astP);
    print_parser_msg("IO: writeln identifier\n", DEBUG);
  }
  | READ '(' variable ')' ';' {
    astParam astP = { .leftBranch = $3, .type=$1, .value = $1, .nodeType = enumValueLeftBranch, .astNodeClass="IN_OUT_STATEMENT" };
    $$ = add_ast_node(astP);
    print_parser_msg("IO: read identifier\n", DEBUG);
  }
;

fluxControlstatement: RETURN expression {
    astParam astP = { .leftBranch = $2, .type="RETURN", .value = $1, .nodeType = enumValueLeftBranch, .astNodeClass="FLUX_CONTROL_STATEMENT RETURN_EXP" };
    $$ = add_ast_node(astP);
    print_parser_msg("return expression\n", DEBUG);
  }
  | RETURN ';' {
    astParam astP = { .type = "RETURN", .value = $1, .nodeType = enumValueTypeOnly, .astNodeClass="FLUX_CONTROL_STATEMENT RETURN_NULL" };
    $$ = add_ast_node(astP);
    print_parser_msg("return null\n", DEBUG);
  }
  | IF '(' operationalExpression ')' expression {
    astParam astP = {
      .leftBranch = $3, .rightBranch = $5, .nodeType = enumLeftRightBranch, .astNodeClass="FLUX_CONTROL_STATEMENT IF"
    };
    $$ = add_ast_node(astP);
    print_parser_msg("if statement\n", DEBUG);
  }
  | IF '(' operationalExpression ')' RETURN expression {
    astParam astP = {
      .leftBranch = $3, .rightBranch = $6, .nodeType = enumLeftRightBranch, .astNodeClass="FLUX_CONTROL_STATEMENT IF_ONE_LINE RETURN"
    };
    $$ = add_ast_node(astP);
    print_parser_msg("if statement\n", DEBUG);
  }
  | IF '(' operationalExpression ')' localStatetements {
    astParam astP = {
      .leftBranch = $3, .rightBranch = $5, .nodeType = enumLeftRightBranch, .astNodeClass="FLUX_CONTROL_STATEMENT IF_NO_ELSE"
    };
    $$ = add_ast_node(astP);
    print_parser_msg("if statement\n", DEBUG);
  }
  | IF '(' operationalExpression ')' localStatetements  ELSE localStatetements {
    astParam astP = {
      .leftBranch = $3, .middle1Branch = $5, .rightBranch = $7, .type= "IF/ELSE", .value=$1, .nodeType = enumLeftRightMiddleBranch, .astNodeClass="FLUX_CONTROL_STATEMENT IF_ELSE" 
    };
    $$ = add_ast_node(astP);
    print_parser_msg("if/else statement\n", DEBUG);
  }
;

iterationStatement: FOR '(' operationalExpression ')' localStatetements {
    astParam astP = {
      .leftBranch = $3, .rightBranch = $5, .nodeType = enumLeftRightBranch, .astNodeClass="ITERATION_STATEMENT FOR_ONE_ARGUMENT"
    };
    $$ = add_ast_node(astP);
    print_parser_msg("for loop one argument\n", DEBUG);
  }
  | FOR '(' expression expression forIncrement ')' localStatetements {
    astParam astP = {
      .leftBranch = $3, .middle1Branch=$4, .middle2Branch=$5, .rightBranch = $7, .type= "FOR", .value=$1, .nodeType = enumLeftRightMiddle1And2Branch, .astNodeClass="ITERATION_STATEMENT FOR_THREE_ARGUMENTS"
    };
    $$ = add_ast_node(astP);
    print_parser_msg("for loop three arguments\n", DEBUG);
  }
  | SET_FORALL '(' term ADD_IN_OP operationalExpression ')' localStatetements {
    astParam astP = {
      .leftBranch = $3, .middle1Branch = $5, .rightBranch = $7, .type="SET_FORALL", .value=$1, .nodeType = enumLeftRightMiddleBranch, .astNodeClass="ITERATION_STATEMENT FORALL" 
    };
    $$ = add_ast_node(astP);
    print_parser_msg("set forall loop\n", DEBUG);
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
    if (strcmp($1->type, "INT") != 0 && strcmp($1->type, "FLOAT") != 0) {
      verify_declared_id($1->value, running_line_count, running_column_count);
    }
    if (strcmp($3->type, "INT") != 0 && strcmp($3->type, "FLOAT") != 0) {
      verify_declared_id($3->value, running_line_count, running_column_count);
    }
    print_parser_msg("add operation\n", DEBUG);
  }
  | operationalExpression SUB_OP term {
    astParam astP = {
      .leftBranch = $1, .rightBranch = $3, .nodeType = enumLeftRightBranch, .astNodeClass="ARITHMETIC_EXPRESSION SUB_OP"
    };
    $$ = add_ast_node(astP);
    if (strcmp($1->type, "INT") != 0 && strcmp($1->type, "FLOAT") != 0) {
      verify_declared_id($1->value, running_line_count, running_column_count);
    }
    if (strcmp($3->type, "INT") != 0 && strcmp($3->type, "FLOAT") != 0) {
      verify_declared_id($3->value, running_line_count, running_column_count);
    }
    print_parser_msg("subtraction operation\n", DEBUG);
  }
  | operationalExpression MULT_OP term {
    astParam astP = {
      .leftBranch = $1, .rightBranch = $3, .nodeType = enumLeftRightBranch, .astNodeClass="ARITHMETIC_EXPRESSION MULT_OP"
    };
    $$ = add_ast_node(astP);
    if (strcmp($1->type, "INT") != 0 && strcmp($1->type, "FLOAT") != 0) {
      verify_declared_id($1->value, running_line_count, running_column_count);
    }
    if (strcmp($3->type, "INT") != 0 && strcmp($3->type, "FLOAT") != 0) {
      verify_declared_id($3->value, running_line_count, running_column_count);
    }
    print_parser_msg("multiplication operation\n", DEBUG);
  }
  | operationalExpression DIV_OP term {
    astParam astP = {
      .leftBranch = $1, .rightBranch = $3, .nodeType = enumLeftRightBranch, .astNodeClass="ARITHMETIC_EXPRESSION DIV_OP"
    };
    $$ = add_ast_node(astP);
    if (strcmp($1->type, "INT") != 0 && strcmp($1->type, "FLOAT") != 0) {
      verify_declared_id($1->value, running_line_count, running_column_count);
    }
    if (strcmp($3->type, "INT") != 0 && strcmp($3->type, "FLOAT") != 0) {
      verify_declared_id($3->value, running_line_count, running_column_count);
    }
    print_parser_msg("division operation\n", DEBUG);
  }
;

logicalExpression: operationalExpression ILT term {
    astParam astP = {
      .leftBranch = $1, .rightBranch = $3, .nodeType = enumLeftRightBranch, .astNodeClass="LOGICAL_EXPRESSION IS_LESS_THAN"
    };
    $$ = add_ast_node(astP);
    print_parser_msg("is less than operation\n", DEBUG);
  }
  | operationalExpression ILTE term {
    astParam astP = {
      .leftBranch = $1, .rightBranch = $3, .nodeType = enumLeftRightBranch, .astNodeClass="LOGICAL_EXPRESSION IS_LESS_THAN_EQUAL"
    };
    $$ = add_ast_node(astP);
    print_parser_msg("is less or equal operation\n", DEBUG);
  }
  | operationalExpression IGT term {
    astParam astP = {
      .leftBranch = $1, .rightBranch = $3, .nodeType = enumLeftRightBranch, .astNodeClass="LOGICAL_EXPRESSION IS_GREATER_THAN"
    };
    $$ = add_ast_node(astP);
    print_parser_msg("is greater than operation\n", DEBUG);
  }
  | operationalExpression IGTE term {
    astParam astP = {
      .leftBranch = $1, .rightBranch = $3, .nodeType = enumLeftRightBranch, .astNodeClass="LOGICAL_EXPRESSION IS_GREATER_THAN_EQUAL"
    };
    $$ = add_ast_node(astP);
    print_parser_msg("is greater than or equal operation\n", DEBUG);
  }
  | operationalExpression IDIFF term {
    astParam astP = {
      .leftBranch = $1, .rightBranch = $3, .nodeType = enumLeftRightBranch, .astNodeClass="LOGICAL_EXPRESSION IS_DIFFERENT_THAN"
    };
    $$ = add_ast_node(astP);
    print_parser_msg("is different than operation\n", DEBUG);
  }
  | operationalExpression IEQ term {
    astParam astP = {
      .leftBranch = $1, .rightBranch = $3, .nodeType = enumLeftRightBranch, .astNodeClass="LOGICAL_EXPRESSION IS_EQUAL"
    };
    $$ = add_ast_node(astP);
    print_parser_msg("is equal to operation\n", DEBUG);
  }
  | operationalExpression AND term {
    astParam astP = {
      .leftBranch = $1, .rightBranch = $3, .nodeType = enumLeftRightBranch, .astNodeClass="LOGICAL_EXPRESSION LOGICAL_AND"
    };
    $$ = add_ast_node(astP);
    print_parser_msg("logical AND operation\n", DEBUG);
  }
  | operationalExpression OR term {
    astParam astP = {
      .leftBranch = $1, .rightBranch = $3, .nodeType = enumLeftRightBranch, .astNodeClass="LOGICAL_EXPRESSION LOGICAL_OR"
    };
    $$ = add_ast_node(astP);
    print_parser_msg("logical OR operation\n", DEBUG);
  }
  | NEG term {
    astParam astP = { .leftBranch = $2, .type="NEG", .value = $1, .nodeType = enumValueLeftBranch, .astNodeClass="LOGICAL_EXPRESSION LOGICAL_NOT" };
    $$ = add_ast_node(astP);
    print_parser_msg("logical NOT operation\n", DEBUG);
  }
;

setOperationalExpression: ADD_SET_OP '(' term ADD_IN_OP operationalExpression ')' {
    astParam astP = {
      .leftBranch = $3, .rightBranch = $5, .nodeType = enumLeftRightBranch, .astNodeClass="SET_OPERATION_EXPRESSION ADD_SET_OP"
    };
    $$ = add_ast_node(astP);
    print_parser_msg("add to set OP\n", DEBUG);
  }
  | REMOVE_SET_OP '(' term ADD_IN_OP operationalExpression ')' {
    astParam astP = {
      .leftBranch = $3, .rightBranch = $5, .nodeType = enumLeftRightBranch, .astNodeClass="SET_OPERATION_EXPRESSION REMOVE_SET_OP"
    };
    $$ = add_ast_node(astP);
    print_parser_msg("remove from set OP\n", DEBUG);
  }
  | EXISTS_IN_SET_OP '(' term ADD_IN_OP operationalExpression ')' {
    astParam astP = {
      .leftBranch = $3, .rightBranch = $5, .nodeType = enumLeftRightBranch, .astNodeClass="SET_OPERATION_EXPRESSION EXISTS_IN_SET_OP"
    };
    $$ = add_ast_node(astP);
    print_parser_msg("exists el in set OP\n", DEBUG);
  }
  | IS_SET '(' term ')' {
    astParam astP = { .leftBranch = $3, .type="IDENTIFIER", .value = $1, .nodeType = enumValueLeftBranch, .astNodeClass="SET_OPERATION_EXPRESSION IS_SET" };
    $$ = add_ast_node(astP);
    print_parser_msg("is_set OP\n", DEBUG);
  }
;

variableAssignment: IDENTIFIER ASSIGN expression {
    verify_declared_id($1, running_line_count, running_column_count);
    astParam astP = { .leftBranch = $3, .type="IDENTIFIER", .value = $1, .nodeType = enumValueLeftBranch, .astNodeClass="VARIABLE_ASSIGNMENT" };
    $$ = add_ast_node(astP);
    if (strcmp($$->leftBranch->astNodeClass, "IDENTIFIER") == 0) {
      verify_declared_id($$->leftBranch->value, running_line_count, running_column_count);
    }
    print_parser_msg("variable assignment\n", DEBUG);
  }
;

localStatetements: '{' {create_new_scope_level();}
  declaration statements '}' {
  decrease_scope_level();
  astParam astP = {
    .leftBranch = $3, .rightBranch = $4, .nodeType = enumLeftRightBranch, .astNodeClass="LOCAL_STATEMENTS DECLARATION STATEMENTS"
  };
  $$ = add_ast_node(astP);
  print_parser_msg("local statetements\n", DEBUG);
}
;

forIncrement: IDENTIFIER ASSIGN arithmeticExpression {
  astParam astP = { .leftBranch = $3, .type="IDENTIFIER", .value = $1, .nodeType = enumValueLeftBranch, .astNodeClass="FOR_INCREMENT" };
  $$ = add_ast_node(astP);
  print_parser_msg("for loop increment\n", DEBUG);
}
;

term: '(' operationalExpression ')' {
    $$=$2;
    print_parser_msg("( operationalExp )\n", DEBUG);
  }
  | variable {
    $$=$1;
    print_parser_msg("variable\n", DEBUG);
  }
  | functionCall {$$=$1;}
  | EMPTY {
    astParam astP = { .type = "EMPTY", .value = $1, .nodeType = enumValueTypeOnly, .astNodeClass="TERM" };
    $$ = add_ast_node(astP);
    print_parser_msg("EMPTY constant value\n", DEBUG);
  }
  | FLOAT {
    astParam astP = { .type = "FLOAT", .value = $1, .nodeType = enumValueTypeOnly, .astNodeClass="TERM" };
    $$ = add_ast_node(astP);
    print_parser_msg("float value\n", DEBUG);
  }
  | INT {
    astParam astP = { .type = "INT", .value = $1, .nodeType = enumValueTypeOnly, .astNodeClass="TERM" };
    $$ = add_ast_node(astP);
    print_parser_msg("int value\n", DEBUG);
  }
;

functionCall: IDENTIFIER '(' functionArguments ')' {
  verify_declared_id($1, running_line_count, running_column_count);
  currentCalledFunction.name = $1;
  verify_func_call_params(currentCalledFunction.name, currentCalledFunction.amountOfParamsCalled, currentCalledFunction.passedParams, running_line_count);
  currentCalledFunction.amountOfParamsCalled = 0;
  astParam astP = { .leftBranch = $3, .type="IDENTIFIER", .value = $1, .nodeType = enumValueLeftBranch, .astNodeClass="FUNCTION_CALL" };
  $$ = add_ast_node(astP);
  print_parser_msg("function call\n", DEBUG);
}
;

functionArguments: callArguments {$$=$1;}
  | %empty {
    $$ = NULL;
    print_parser_msg("empty function argument\n", DEBUG);
  }
;

callArguments: callArguments ',' operationalExpression {
    astParam astP = {
      .leftBranch = $1, .rightBranch = $3, .nodeType = enumLeftRightBranch, .astNodeClass="CALL_ARGUMENTS MULTIPLE_ARGUMENTS"
    };
    $$ = add_ast_node(astP);
    if (strcmp($3->astNodeClass,"IDENTIFIER") == 0) {
      scopeInfo current_scope = get_current_scope();
      int symbolID = get_symbolID($3->value, current_scope.scopeID);
      currentCalledFunction.passedParams[currentCalledFunction.amountOfParamsCalled] = symbolID;
    } else if (strcmp($3->astNodeClass,"TERM") == 0) {
      if (strcmp($3->type,"INT") == 0) {
        currentCalledFunction.passedParams[currentCalledFunction.amountOfParamsCalled] = -1;
      } else if (strcmp($3->type,"FLOAT") == 0) {
        currentCalledFunction.passedParams[currentCalledFunction.amountOfParamsCalled] = -2;
      }
    }
    currentCalledFunction.amountOfParamsCalled = currentCalledFunction.amountOfParamsCalled + 1;
    print_parser_msg("function callarguments, opExpression\n", DEBUG);
  }
  | operationalExpression {
    $$ = $1;
    if (strcmp($1->astNodeClass,"IDENTIFIER") == 0) {
      scopeInfo current_scope = get_current_scope();
      int symbolID = get_symbolID($1->value, current_scope.scopeID);
      currentCalledFunction.passedParams[currentCalledFunction.amountOfParamsCalled] = symbolID;
    } else if (strcmp($1->astNodeClass,"TERM") == 0) {
      if (strcmp($1->type,"INT") == 0) {
        currentCalledFunction.passedParams[currentCalledFunction.amountOfParamsCalled] = -1;
      } else if (strcmp($1->type,"FLOAT") == 0) {
        currentCalledFunction.passedParams[currentCalledFunction.amountOfParamsCalled] = -2;
      }
    }
    currentCalledFunction.amountOfParamsCalled = currentCalledFunction.amountOfParamsCalled + 1;

    print_parser_msg("function callarguments\n", DEBUG);
  }
;

variableInit: typeSpecifier IDENTIFIER ';' {
  astParam astP = { .leftBranch = $1, .type="IDENTIFIER", .value = $2, .nodeType = enumValueLeftBranch, .astNodeClass="VARIABLE_INIT" };
  $$ = add_ast_node(astP);
  symbolParam symbol = { .symbolID = globalCounterOfSymbols, .symbolType=enumVariable, .type = $$->leftBranch->value, .name = $2, .line= running_line_count, .column= running_column_count};
  add_symbol_node(symbol);
  globalCounterOfSymbols++;
  print_parser_msg("variable initialization\n", DEBUG);
}
;

variable: IDENTIFIER {
  astParam astP = { .type = "IDENTIFIER", .value = $1, .nodeType = enumValueTypeOnly, .astNodeClass="IDENTIFIER" };
  $$ = add_ast_node(astP);
  print_parser_msg("variable\n", DEBUG);
}
;

typeSpecifier: T_INT {
    astParam astP = { .type = "T_INT", .value = $1, .nodeType = enumValueTypeOnly, .astNodeClass="TYPE_SPECIFIER" };
    $$ = add_ast_node(astP);
    print_parser_msg("integer type\n", DEBUG);
  }
  | T_FLOAT {
    astParam astP = { .type = "T_FLOAT", .value = $1, .nodeType = enumValueTypeOnly, .astNodeClass="TYPE_SPECIFIER" };
    $$ = add_ast_node(astP);
    print_parser_msg("float type\n", DEBUG);
  }
  | T_ELEM {
    astParam astP = { .type = "T_ELEM", .value = $1, .nodeType = enumValueTypeOnly, .astNodeClass="TYPE_SPECIFIER" };
    $$ = add_ast_node(astP);
    print_parser_msg("elem type\n", DEBUG);
  }
  | T_SET {
    astParam astP = { .type = "T_SET", .value = $1, .nodeType = enumValueTypeOnly, .astNodeClass="TYPE_SPECIFIER" };
    $$ = add_ast_node(astP);
    print_parser_msg("set type\n", DEBUG);
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

  srand(time(NULL));

  create_new_scope_level(); /* initialize scope stack */

  parser_ast = NULL; /* initialize syntatical AST */

  printf("\n----------------\n");

  yyparse();
  fclose(yyin);

  post_parse_semantic_analysis();

  print_symbols();
  printf("\n=================== Parser AST ====================\n\n");
  print_parser_ast(parser_ast, 0);

  printf("\nReported amount of syntax errors: %d\n", yynerrs);
  printf("Reported amount of semantic errors: %d\n", semantic_errors);

  free_symbols_table();

  free_parser_ast(parser_ast);

  free_scope_stack();

  yylex_destroy();

  return 0;
}

void yyerror(const char* msg) {
  total_errors_count++;
  fprintf(stderr, "%s at line: %d, column: %d\n", msg, running_line_count, running_column_count);
}