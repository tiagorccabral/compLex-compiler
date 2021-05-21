%define parse.error verbose
%define parse.trace
%locations

%{

// Required libs declarations
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#include "symbol_table.h"
#include "parser_ast.h"
#include "semantic_analyzer.h"
#include "tac.h"
#include "utils.h"
#include "utstring.h"

#define DEBUG 0 // controls debug msgs, see utils.h

extern int yylex();
extern int yylex_destroy();
extern FILE *yyin;
extern int yynerrs;
extern int lexical_errors_count;

extern int running_line_count;
extern int running_column_count;

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

scopeInfo currentReturnScope;
int currentReturnLine;

void yyerror(const char *msg);

/* Global variables */
int globalCounterOfSymbols = 1;
int lexical_errors_count = 0;
int currentTempReg = 0; /* keeps count of how many regs are used during parse */
int currentParamsReg = 0; /* keeps count of how many params are used during parse */
int currentTableCounter = 1; /* keeps count of how many symbols are added to .table during parse, e.g: strings */
int forIncrementCounter = 0;

char *return_statement_type; /* aux vars to verify presence of return statements*/
struct parserNode* returned_node; /* aux vars to verify presence of return statements*/

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
%type <node> inOutStatement fluxControlstatement ifStart iterationStatement forIncrement
%type <node> expression setOperationalExpression unaryOperation setBody
%type <node> arithmeticExpression arithmeticExpression2 logicalExpression comparationalExpression
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
    currentTempReg = 0;
    currentParamsReg = 0;
    symbolParam symbol = { .symbolID = globalCounterOfSymbols, .symbolType=enumFunction, .type = $1->value, .name = $2, .line = running_line_count, .column = running_column_count };
    add_symbol_node(symbol);
    globalCounterOfSymbols++;
    scopeInfo current_scope = get_current_scope();
    currentFunction.scopeID = current_scope.scopeID;
    currentFunction.name = $2;
    currentFunction.lastParamPosition = 0;
    return_statement_type = strdup($1->type);
    insertTACLabel($2);
  } '(' parameters ')' compoundStatement {
    create_new_scope_level();
    astParam astP = {
      .leftBranch = $1, .middle1Branch = $5, .rightBranch = $7, .type= "IDENTIFIER", .value=$2, .nodeType = enumLeftRightMiddleBranch, .astNodeClass="FUNCTION_DEFINITION" 
    };
    if (currentReturnLine != -1) {
      verify_return_statement($2, found_return_statement, return_statement_type, returned_node, currentReturnScope, currentReturnLine);
    } else {
      verify_return_statement($2, found_return_statement, return_statement_type, returned_node, currentReturnScope, running_line_count);
    }
    currentReturnLine = -1;
    found_return_statement = 0;
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
      return_statement_type = strdup($1->type);
      insertTACLabel("fmain");
  } '(' parameters ')' compoundStatement {
    create_new_scope_level();
    astParam astP = { 
      .leftBranch = $1, .middle1Branch = $5, .rightBranch = $7, .type= "MAIN", .value=$2, .nodeType = enumLeftRightMiddleBranch, .astNodeClass="FUNCTION_DEFINITION" 
    };
    $$ = add_ast_node(astP);
    if (currentReturnLine != -1) {
      verify_return_statement($2, found_return_statement, return_statement_type, returned_node, currentReturnScope, currentReturnLine);
    } else {
      verify_return_statement($2, found_return_statement, return_statement_type, returned_node, currentReturnScope, running_line_count);
    }
    found_return_statement = 0;
    currentReturnLine = -1;
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
    scopeInfo current_scope = get_current_scope();
    int foundSymbol = get_symbolID_by_name_and_current_scope("main", current_scope.scopeID, current_scope.level);
    if (foundSymbol == -1) { /* not main */
      UT_string *tacName;
      utstring_new(tacName);
      set_param(tacName, $$, &currentParamsReg);
      symbolParam symbol = { .symbolID = globalCounterOfSymbols, .symbolType=enumParameter, .type = $$->rightBranch->value, .name = $4, .line= running_line_count, .tacName=utstring_body(tacName), .column= running_column_count, .associated_function=currentFunction.name, .last_param=currentFunction.lastParamPosition, .associated_function_scope=currentFunction.scopeID};
      add_symbol_node(symbol);
    } else {
      symbolParam symbol = { .symbolID = globalCounterOfSymbols, .symbolType=enumParameter, .type = $$->rightBranch->value, .name = $4, .line= running_line_count, .column= running_column_count, .associated_function=currentFunction.name, .last_param=currentFunction.lastParamPosition, .associated_function_scope=currentFunction.scopeID};
      add_symbol_node(symbol);
    }
    currentFunction.lastParamPosition = currentFunction.lastParamPosition + 1;
    globalCounterOfSymbols++;
    print_parser_msg("Parameter, type and identifier\n", DEBUG);
  }
  | typeSpecifier IDENTIFIER {
    astParam astP = { .leftBranch = $1, .type=$2, .value = $2, .nodeType = enumValueLeftBranch, .astNodeClass="PARAMETER TYPE_SPECIFIER IDENTIFIER" };
    $$ = add_ast_node(astP);
    astParam astP2 = { .leftBranch = $1, .type=$$->leftBranch->value, .value = $2, .nodeType = enumValueLeftBranch, .astNodeClass="PARAMETER TYPE_SPECIFIER IDENTIFIER" };
    $$ = add_ast_node(astP2);
    scopeInfo current_scope = get_current_scope();
    int foundSymbol = get_symbolID_by_name_and_current_scope("main", current_scope.scopeID, current_scope.level);
    if (foundSymbol == -1) { /* not main */
      UT_string *tacName;
      utstring_new(tacName);
      set_param(tacName, $$, &currentParamsReg);
      symbolParam symbol = { .symbolID = globalCounterOfSymbols, .symbolType=enumParameter, .type = $$->leftBranch->value, .name = $2, .line= running_line_count, .tacName=utstring_body(tacName), .column= running_column_count, .associated_function=currentFunction.name, .last_param=currentFunction.lastParamPosition, .associated_function_scope=currentFunction.scopeID};
      add_symbol_node(symbol);
    } else {
      symbolParam symbol = { .symbolID = globalCounterOfSymbols, .symbolType=enumParameter, .type = $$->leftBranch->value, .name = $2, .line= running_line_count, .column= running_column_count, .associated_function=currentFunction.name, .last_param=currentFunction.lastParamPosition, .associated_function_scope=currentFunction.scopeID};
      add_symbol_node(symbol);
    }
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
    add_string_to_TAC($3, 0, &currentTempReg, &currentTableCounter);
    print_parser_msg("IO: write string\n", DEBUG);
  }
  | WRITE '(' comparationalExpression ')' ';' {
    astParam astP = { .leftBranch = $3, .type=$1, .value = $1, .nodeType = enumValueLeftBranch, .astNodeClass="WRITE IDENTIFIER" };
    $$ = add_ast_node(astP);
    if ($3->tempReg) {
      tacCodeParam tacP = { .instruction = "print", .op1 = $3->tempReg, .lineType=enumOneOp};
      add_TAC_line(tacP);
    } else if ($3->value) {
      tacCodeParam tacP = { .instruction = "print", .op1 = $3->value, .lineType=enumOneOp};
      add_TAC_line(tacP);
    }
    print_parser_msg("IO: write identifier\n", DEBUG);
  }
  | WRITELN '(' STR ')' ';' {
    astParam astP = { .type = "WRITELN", .value = $3, .nodeType = enumValueTypeOnly, .astNodeClass="WRITELN STRING" };
    $$ = add_ast_node(astP);
    add_string_to_TAC($3, 1, &currentTempReg, &currentTableCounter);
    print_parser_msg("IO: writeln string\n", DEBUG);
  }
  | WRITELN '(' comparationalExpression ')' ';' {
    astParam astP = { .leftBranch = $3, .type=$1, .value = $1, .nodeType = enumValueLeftBranch, .astNodeClass="WRITELN IDENTIFIER" };
    $$ = add_ast_node(astP);
    if ($3->tempReg) {
      tacCodeParam tacP = { .instruction ="println", .op1 = $3->tempReg, .lineType=enumOneOp};
      add_TAC_line(tacP);
    } else if ($3->value) {
      tacCodeParam tacP = { .instruction ="println", .op1 = $3->value, .lineType=enumOneOp};
      add_TAC_line(tacP);
    }
    print_parser_msg("IO: writeln identifier\n", DEBUG);
  }
  | READ '(' variable ')' ';' {
    astParam astP = { .leftBranch = $3, .type=$1, .value = $1, .nodeType = enumValueLeftBranch, .astNodeClass="IN_OUT_STATEMENT" };
    $$ = add_ast_node(astP);
    if ($3->value) {
      int *symbolkey, symbolID;
      struct symbolNode *symbol;
      scopeInfo current_scope = get_current_scope();
      symbolID = get_symbolID_by_name_and_current_scope($3->value, current_scope.scopeID, current_scope.level);
      if (symbolID != -1) {
        symbolkey = &symbolID;
        HASH_FIND_INT(symbolTable, symbolkey, symbol);
        if (strcmp(symbol->type, "int")==0) {
          tacCodeParam tacP = { .instruction = "scani", .op1 = $3->value, .lineType=enumOneOp};
          add_TAC_line(tacP);
        } else if (strcmp(symbol->type, "float")==0) {
          tacCodeParam tacP = { .instruction = "scanf", .op1 = $3->value, .lineType=enumOneOp};
          add_TAC_line(tacP);
        }
      }
    }
    print_parser_msg("IO: read identifier\n", DEBUG);
  }
;

fluxControlstatement: RETURN comparationalExpression ';' {
    astParam astP = { .leftBranch = $2, .type="RETURN", .value = $1, .nodeType = enumValueLeftBranch, .astNodeClass="FLUX_CONTROL_STATEMENT RETURN_EXP" };
    $$ = add_ast_node(astP);
    found_return_statement = 1;
    scopeInfo tmpScope = get_current_scope();
    currentReturnScope.level = tmpScope.level;
    currentReturnScope.scopeID = tmpScope.scopeID;
    currentReturnLine = running_line_count;
    if ($2->type) returned_node = $2;
    if ($2->value) {
      tacCodeParam tacP = { .instruction = "return", .op1 = $2->value, .lineType=enumOneOp};
      add_TAC_line(tacP);
    } else if ($2->tempReg) {
      tacCodeParam tacP = { .instruction = "return", .op1 = $2->tempReg, .lineType=enumTwoOp};
      add_TAC_line(tacP);
    }
    print_parser_msg("return expression\n", DEBUG);
  }
  | RETURN ';' {
    astParam astP = { .type = "RETURN", .value = $1, .nodeType = enumValueTypeOnly, .astNodeClass="FLUX_CONTROL_STATEMENT RETURN_NULL" };
    $$ = add_ast_node(astP);
    found_return_statement = 1;
    tacCodeParam tacP = { .instruction = "return", .lineType=enumNoOp};
    add_TAC_line(tacP);
    print_parser_msg("return null\n", DEBUG);
  }
  | ifStart '(' comparationalExpression ')' expression {
    astParam astP = {
      .leftBranch = $3, .rightBranch = $5, .nodeType = enumLeftRightBranch, .astNodeClass="FLUX_CONTROL_STATEMENT IF"
    };
    $$ = add_ast_node(astP);
    print_parser_msg("if statement\n", DEBUG);
  }
  | ifStart '(' comparationalExpression ')' RETURN expression {
    astParam astP = {
      .leftBranch = $3, .rightBranch = $6, .nodeType = enumLeftRightBranch, .astNodeClass="FLUX_CONTROL_STATEMENT IF_ONE_LINE RETURN"
    };
    $$ = add_ast_node(astP);
    print_parser_msg("if statement\n", DEBUG);
  }
  | ifStart '(' comparationalExpression ')' localStatetements {
    astParam astP = {
      .leftBranch = $3, .rightBranch = $5, .nodeType = enumLeftRightBranch, .astNodeClass="FLUX_CONTROL_STATEMENT IF_NO_ELSE"
    };
    $$ = add_ast_node(astP);
    if (STACK_TOP(codeStackHead)) {
      add_if_finish_to_TAC();
    }
    print_parser_msg("if statement\n", DEBUG);
  }
  | ifStart '(' comparationalExpression ')' localStatetements {
    add_if_else_entry_to_TAC();
  } ELSE localStatetements {
    astParam astP = {
      .leftBranch = $3, .middle1Branch = $5, .rightBranch = $8, .type= "IF/ELSE", .value="if", .nodeType = enumLeftRightMiddleBranch, .astNodeClass="FLUX_CONTROL_STATEMENT IF_ELSE" 
    };
    $$ = add_ast_node(astP);
    add_if_else_closing_to_TAC();
    print_parser_msg("if/else statement\n", DEBUG);
  }
;

ifStart: IF {
  add_for_or_if_entry_to_TAC("ifStart");
}
;

iterationStatement: FOR '(' expression {
      add_for_or_if_entry_to_TAC("forLoop");
      forIncrementCounter++; 
    } expression {;} forIncrement ')' localStatetements {
      astParam astP = {
        .leftBranch = $3, .middle1Branch=$5, .middle2Branch=$7, .rightBranch = $9, .type= "FOR", .value=$1, .nodeType = enumLeftRightMiddle1And2Branch, .astNodeClass="ITERATION_STATEMENT FOR_THREE_ARGUMENTS"
      };
      $$ = add_ast_node(astP);
      add_for_loop_closing_to_TAC("forLoop", &currentTempReg, $$->middle1Branch, $$->middle2Branch);
      print_parser_msg("for loop three arguments\n", DEBUG);
  }
  | SET_FORALL '(' term ADD_IN_OP comparationalExpression {
      struct setInfo *setInfoPointer;
      setInfoPointer = getSetSymbolInfo($5->value);
      if (setInfoPointer && setInfoPointer->current_size > 0) {
        UT_string *operand_array, *currentPos;
        utstring_new(operand_array);utstring_new(currentPos);
        set_operand_array(operand_array, setInfoPointer->pointerToSet, "0");
        tacCodeParam tacP0 = {.instruction = "mov", .op1 = $3->value, .op2 = utstring_body(operand_array), .lineType=enumTwoOp};
        add_TAC_line(tacP0);
        create_temporary_register(currentPos, &currentTempReg);
        tacCodeParam tacP1 = {.instruction = "mov", .op1 = utstring_body(currentPos), .op2 = "0", .lineType=enumTwoOp};
        add_TAC_line(tacP1);
        add_for_or_if_entry_to_TAC("forallLoop");
        setForallStack *tmpForallStack = (setForallStack *)malloc(sizeof *tmpForallStack);
        tmpForallStack->name = strdup(utstring_body(currentPos));
        STACK_PUSH(setForall, tmpForallStack);
        forIncrementCounter++;
        utstring_free(operand_array);utstring_free(currentPos);
      }
    } ')' localStatetements {
      astParam astP = {
        .leftBranch = $3, .middle1Branch = $5, .rightBranch = $8, .type="SET_FORALL", .value=$1, .nodeType = enumLeftRightMiddleBranch, .astNodeClass="ITERATION_STATEMENT FORALL" 
      };
      $$ = add_ast_node(astP);
      struct setInfo *setInfoPointer;
      setInfoPointer = getSetSymbolInfo($5->value);
      if (setInfoPointer && setInfoPointer->current_size > 0) {
        add_forall_loop_closing_to_TAC("forallLoop", setInfoPointer, &currentTempReg, $3->value);
      }
      print_parser_msg("set forall loop\n", DEBUG);
  }
;

expression: comparationalExpression ';' {$$=$1;}
  | variableAssignment {$$=$1;}
;

comparationalExpression: comparationalExpression AND logicalExpression {
    astParam astP = {
      .leftBranch = $1, .rightBranch = $3, .nodeType = enumLeftRightBranch, .astNodeClass="LOGICAL_EXPRESSION LOGICAL_AND"
    };
    $$ = add_ast_node(astP);
    print_parser_msg("logical AND operation\n", DEBUG);
  }
  | comparationalExpression OR logicalExpression {
    astParam astP = {
      .leftBranch = $1, .rightBranch = $3, .nodeType = enumLeftRightBranch, .astNodeClass="LOGICAL_EXPRESSION LOGICAL_OR"
    };
    $$ = add_ast_node(astP);
    print_parser_msg("logical OR operation\n", DEBUG);
  }
  | NEG logicalExpression {
    astParam astP = { .leftBranch = $2, .type="NEG", .value = $1, .nodeType = enumValueLeftBranch, .astNodeClass="LOGICAL_EXPRESSION LOGICAL_NOT" };
    $$ = add_ast_node(astP);
    print_parser_msg("logical NOT operation\n", DEBUG);
  }
  | logicalExpression {
    $$ = $1;
  }
;

logicalExpression: logicalExpression ILT arithmeticExpression {
    astParam astP = {
      .leftBranch = $1, .rightBranch = $3, .nodeType = enumLeftRightBranch, .astNodeClass="LOGICAL_EXPRESSION IS_LESS_THAN"
    };
    $$ = add_ast_node(astP);
    set_temporary_register($$, &currentTempReg);
    int symbolOK = 0;
    symbolOK = cast_operators($1, $3, running_line_count);
    if (symbolOK == 0 && STACK_TOP(codeStackHead)) {
      UT_string *label;
      utstring_new(label);
      codeLabelStack *currentLoopLabel;
      currentLoopLabel = STACK_TOP(codeStackHead);
      utstring_printf(label, "%sFinish", currentLoopLabel->name);
      tacCodeValidationParams tacP = { .instruction = "slt", .dst= $$,.op1 = $1, .op2=$3, .lineType=enumThreeOp};
      check_ops_and_add_TAC_line(tacP);
      tacCodeParam tacP1 = { .instruction = "brz", .op1 = utstring_body(label), $$->tempReg, .lineType=enumTwoOp};
      add_TAC_line(tacP1);
      utstring_free(label);
    }
    if($1->type) $$->type = $1->type;
    print_parser_msg("is less than operation\n", DEBUG);
  }
  | logicalExpression ILTE arithmeticExpression {
    astParam astP = {
      .leftBranch = $1, .rightBranch = $3, .nodeType = enumLeftRightBranch, .astNodeClass="LOGICAL_EXPRESSION IS_LESS_THAN_EQUAL"
    };
    $$ = add_ast_node(astP);
    set_temporary_register($$, &currentTempReg);
    int symbolOK = 0;
    symbolOK = cast_operators($1, $3, running_line_count);
    if (symbolOK == 0 && STACK_TOP(codeStackHead)) {
      UT_string *label;
      utstring_new(label);
      codeLabelStack *currentLoopLabel;
      currentLoopLabel = STACK_TOP(codeStackHead);
      utstring_printf(label, "%sFinish", currentLoopLabel->name);
      tacCodeValidationParams tacP = { .instruction = "sleq", .dst= $$,.op1 = $1, .op2=$3, .lineType=enumThreeOp};
      check_ops_and_add_TAC_line(tacP);
      tacCodeParam tacP1 = { .instruction = "brz", .op1 = utstring_body(label), $$->tempReg, .lineType=enumTwoOp};
      add_TAC_line(tacP1);
      utstring_free(label);
    }
    if($1->type) $$->type = $1->type;
    print_parser_msg("is less or equal operation\n", DEBUG);
  }
  | logicalExpression IGT arithmeticExpression {
    astParam astP = {
      .leftBranch = $1, .rightBranch = $3, .nodeType = enumLeftRightBranch, .astNodeClass="LOGICAL_EXPRESSION IS_GREATER_THAN"
    };
    $$ = add_ast_node(astP);
    set_temporary_register($$, &currentTempReg);
    int symbolOK = 0;
    symbolOK = cast_operators($1, $3, running_line_count);
    if (symbolOK == 0 && STACK_TOP(codeStackHead)) {
      UT_string *label;
      utstring_new(label);
      codeLabelStack *currentLoopLabel;
      currentLoopLabel = STACK_TOP(codeStackHead);
      utstring_printf(label, "%sFinish", currentLoopLabel->name);
      tacCodeValidationParams tacP = { .instruction = "sleq", .dst= $$,.op1 = $1, .op2=$3, .lineType=enumThreeOp};
      check_ops_and_add_TAC_line(tacP);
      tacCodeParam tacP1 = { .instruction = "brnz", .op1 = utstring_body(label), $$->tempReg, .lineType=enumTwoOp};
      add_TAC_line(tacP1);
      utstring_free(label);
    }
    if($1->type) $$->type = $1->type;
    print_parser_msg("is greater than operation\n", DEBUG);
  }
  | logicalExpression IGTE arithmeticExpression {
    astParam astP = {
      .leftBranch = $1, .rightBranch = $3, .nodeType = enumLeftRightBranch, .astNodeClass="LOGICAL_EXPRESSION IS_GREATER_THAN_EQUAL"
    };
    $$ = add_ast_node(astP);
    set_temporary_register($$, &currentTempReg);
    int symbolOK = 0;
    symbolOK = cast_operators($1, $3, running_line_count);
    if (symbolOK == 0 && STACK_TOP(codeStackHead)) {
      UT_string *label;
      utstring_new(label);
      codeLabelStack *currentLoopLabel;
      currentLoopLabel = STACK_TOP(codeStackHead);
      utstring_printf(label, "%sFinish", currentLoopLabel->name);
      tacCodeValidationParams tacP = { .instruction = "slt", .dst= $$,.op1 = $1, .op2=$3, .lineType=enumThreeOp};
      check_ops_and_add_TAC_line(tacP);
      tacCodeParam tacP1 = { .instruction = "brnz", .op1 = utstring_body(label), $$->tempReg, .lineType=enumTwoOp};
      add_TAC_line(tacP1);
      utstring_free(label);
    }
    if($1->type) $$->type = $1->type;
    print_parser_msg("is greater than or equal operation\n", DEBUG);
  }
  | logicalExpression IDIFF arithmeticExpression {
    astParam astP = {
      .leftBranch = $1, .rightBranch = $3, .nodeType = enumLeftRightBranch, .astNodeClass="LOGICAL_EXPRESSION IS_DIFFERENT_THAN"
    };
    $$ = add_ast_node(astP);
    set_temporary_register($$, &currentTempReg);
    int symbolOK = 0;
    symbolOK = cast_operators($1, $3, running_line_count);
    if (symbolOK == 0 && STACK_TOP(codeStackHead)) {
      UT_string *label;
      utstring_new(label);
      codeLabelStack *currentLoopLabel;
      currentLoopLabel = STACK_TOP(codeStackHead);
      utstring_printf(label, "%sFinish", currentLoopLabel->name);
      tacCodeValidationParams tacP = { .instruction = "seq", .dst= $$,.op1 = $1, .op2=$3, .lineType=enumThreeOp};
      check_ops_and_add_TAC_line(tacP);
      tacCodeParam tacP1 = { .instruction = "brnz", .op1 = utstring_body(label), $$->tempReg, .lineType=enumTwoOp};
      add_TAC_line(tacP1);
      utstring_free(label);
    }
    if($1->type) $$->type = $1->type;
    print_parser_msg("is different than operation\n", DEBUG);
  }
  | logicalExpression IEQ arithmeticExpression {
    astParam astP = {
      .leftBranch = $1, .rightBranch = $3, .nodeType = enumLeftRightBranch, .astNodeClass="LOGICAL_EXPRESSION IS_EQUAL"
    };
    $$ = add_ast_node(astP);
    set_temporary_register($$, &currentTempReg);
    int symbolOK = 0;
    symbolOK = cast_operators($1, $3, running_line_count);
    if (symbolOK == 0 && STACK_TOP(codeStackHead)) {
      UT_string *label;
      utstring_new(label);
      codeLabelStack *currentLoopLabel;
      currentLoopLabel = STACK_TOP(codeStackHead);
      utstring_printf(label, "%sFinish", currentLoopLabel->name);
      tacCodeValidationParams tacP = { .instruction = "seq", .dst= $$,.op1 = $1, .op2=$3, .lineType=enumThreeOp};
      check_ops_and_add_TAC_line(tacP);
      tacCodeParam tacP1 = { .instruction = "brz", .op1 = utstring_body(label), $$->tempReg, .lineType=enumTwoOp};
      add_TAC_line(tacP1);
      utstring_free(label);
    }
    if($1->type) $$->type = $1->type;
    print_parser_msg("is equal to operation\n", DEBUG);
  }
  | arithmeticExpression {
    $$ = $1;
  }
;

arithmeticExpression: arithmeticExpression ADD_OP arithmeticExpression2 {
    astParam astP = {
      .leftBranch = $1, .rightBranch = $3, .nodeType = enumLeftRightBranch, .astNodeClass="ARITHMETIC_EXPRESSION ADD_OP"
    };
    $$ = add_ast_node(astP);
    set_temporary_register($$, &currentTempReg);
    int symbolOK = 0;
    symbolOK = cast_operators($1, $3, running_line_count);
    if (symbolOK == 0 && forIncrementCounter == 0) {
      tacCodeValidationParams tacP = { .instruction = "add", .dst= $$,.op1 = $1, .op2 = $3, .lineType=enumThreeOp};
      check_ops_and_add_TAC_line(tacP);
    }
    else if (symbolOK == 0 && forIncrementCounter > 0) {
      forIncrementCounter--;
    }
    if($1->type) $$->type = $1->type;
    print_parser_msg("add operation\n", DEBUG);
  }
  | arithmeticExpression SUB_OP arithmeticExpression2 {
    astParam astP = {
      .leftBranch = $1, .rightBranch = $3, .nodeType = enumLeftRightBranch, .astNodeClass="ARITHMETIC_EXPRESSION SUB_OP"
    };
    $$ = add_ast_node(astP);
    set_temporary_register($$, &currentTempReg);
    int symbolOK = 0;
    symbolOK = cast_operators($1, $3, running_line_count);
    if (symbolOK == 0 && forIncrementCounter == 0) {
      tacCodeValidationParams tacP = { .instruction = "sub", .dst= $$,.op1 = $1, .op2 = $3, .lineType=enumThreeOp};
      check_ops_and_add_TAC_line(tacP);
    }
    else if (symbolOK == 0 && forIncrementCounter > 0) {
      forIncrementCounter--;
    }
    if($1->type) $$->type = $1->type;
    print_parser_msg("subtraction operation\n", DEBUG);
  }
  | arithmeticExpression2 {$$=$1;}
;

arithmeticExpression2: arithmeticExpression2 MULT_OP unaryOperation {
    astParam astP = {
      .leftBranch = $1, .rightBranch = $3, .nodeType = enumLeftRightBranch, .astNodeClass="ARITHMETIC_EXPRESSION MULT_OP"
    };
    $$ = add_ast_node(astP);
    set_temporary_register($$, &currentTempReg);
    int symbolOK = 0;
    symbolOK = cast_operators($1, $3, running_line_count);
    if (symbolOK == 0 && forIncrementCounter == 0) {
      tacCodeValidationParams tacP = { .instruction = "mul", .dst= $$,.op1 = $1, .op2 = $3, .lineType=enumThreeOp};
      check_ops_and_add_TAC_line(tacP);
    }
    else if (symbolOK == 0 && forIncrementCounter > 0) {
      forIncrementCounter--;
    }
    if($1->type) $$->type = $1->type;
    print_parser_msg("multiplication operation\n", DEBUG);
  }
  | arithmeticExpression2 DIV_OP unaryOperation {
    astParam astP = {
      .leftBranch = $1, .rightBranch = $3, .nodeType = enumLeftRightBranch, .astNodeClass="ARITHMETIC_EXPRESSION DIV_OP"
    };
    $$ = add_ast_node(astP);
    set_temporary_register($$, &currentTempReg);
    int symbolOK = 0;
    symbolOK = cast_operators($1, $3, running_line_count);
    if (symbolOK == 0 && forIncrementCounter == 0) {
      tacCodeValidationParams tacP = { .instruction = "div", .dst= $$,.op1 = $1, .op2 = $3, .lineType=enumThreeOp};
      check_ops_and_add_TAC_line(tacP);
    }
    else if (symbolOK == 0 && forIncrementCounter > 0) {
      forIncrementCounter--;
    }
    if($1->type) $$->type = $1->type;
    print_parser_msg("division operation\n", DEBUG);
  }
  | unaryOperation {$$=$1;}
;

unaryOperation: SUB_OP term {
    astParam astP = { .leftBranch = $2, .type="IDENTIFIER", .value = $2->value, .nodeType = enumValueLeftBranch, .astNodeClass="SUB TERM" };
    $$ = add_ast_node(astP);
    print_parser_msg("is_set OP\n", DEBUG);
  }
  | term {
    $$ = $1;
  }
;

setOperationalExpression: ADD_SET_OP '(' setBody ')' {
    astParam astP = { .leftBranch = $3, .type="IDENTIFIER", .value = $1, .nodeType = enumValueLeftBranch, .astNodeClass="SET_OPERATION_EXPRESSION ADD_SET_OP" };
    $$ = add_ast_node(astP);
    if ($$->leftBranch->rightBranch && $$->leftBranch->rightBranch->value && strcmp($$->leftBranch->rightBranch->astNodeClass, "IDENTIFIER") == 0) {
      struct setInfo *setInfoPointer;
      setInfoPointer = getSetSymbolInfo($$->leftBranch->rightBranch->value);
      if (setInfoPointer) {
        if (setInfoPointer->current_size > 0) {
          int i, setID = setInfoPointer->setID, current_size = setInfoPointer->current_size;
          UT_string *newSetReg, *sizePlusOne, *operand_array, *currentPos, *operand_array_dest, *tmpReg;
          utstring_new(newSetReg); utstring_new(sizePlusOne); utstring_new(tmpReg); 
          utstring_new(operand_array); utstring_new(operand_array_dest); utstring_new(currentPos);
          stringify_integer(sizePlusOne, setInfoPointer->current_size + 1);
          create_temporary_register(newSetReg, &currentTempReg);
          create_temporary_register(tmpReg, &currentTempReg);
          tacCodeParam tacP = {.instruction="mema", .op1=utstring_body(newSetReg), .op2=utstring_body(sizePlusOne), .lineType=enumTwoOp};
          add_TAC_line(tacP);
          for (i=0; i<setInfoPointer->current_size; i++) {
            utstring_clear(currentPos);utstring_clear(operand_array);utstring_clear(operand_array_dest);
            stringify_integer(currentPos, i);
            set_operand_array(operand_array, setInfoPointer->pointerToSet, utstring_body(currentPos));
            set_operand_array(operand_array_dest, utstring_body(newSetReg), utstring_body(currentPos));
            tacCodeParam tacP2 = {.instruction="mov", .op1=utstring_body(tmpReg), .op2=utstring_body(operand_array), .lineType=enumTwoOp};
            add_TAC_line(tacP2);
            tacCodeParam tacP1 = {.instruction="mov", .op1=utstring_body(operand_array_dest), .op2=utstring_body(tmpReg), .lineType=enumTwoOp};
            add_TAC_line(tacP1);
          }
          utstring_clear(operand_array_dest);utstring_clear(currentPos);
          stringify_integer(currentPos, i);
          set_operand_array(operand_array_dest, utstring_body(newSetReg), utstring_body(currentPos));
          tacCodeParam tacP4 = {.instruction="mov", .op1=utstring_body(operand_array_dest), .op2=$$->leftBranch->leftBranch->value, .lineType=enumTwoOp};
          add_TAC_line(tacP4);
          tacCodeParam tacP3 = {.instruction="memf", .op1=setInfoPointer->pointerToSet, .lineType=enumOneOp};
          add_TAC_line(tacP3);
          deleteSymbolSetInfo(setID);
          addSymbolToSetInfoTable(setID, strdup(utstring_body(newSetReg)), current_size+1);
          utstring_free(sizePlusOne);utstring_free(operand_array_dest);utstring_free(currentPos);
          utstring_free(operand_array);utstring_free(newSetReg);utstring_free(tmpReg);
        } else {
          UT_string *operand_array, *sizePlusOne, *size;
          utstring_new(operand_array); utstring_new(sizePlusOne); utstring_new(size);
          stringify_integer(sizePlusOne, setInfoPointer->current_size + 1);
          stringify_integer(size, setInfoPointer->current_size);
          tacCodeParam tacP = {.instruction="mema", .op1=setInfoPointer->pointerToSet, .op2=utstring_body(sizePlusOne), .lineType=enumTwoOp};
          add_TAC_line(tacP);
          set_operand_array(operand_array, setInfoPointer->pointerToSet, utstring_body(size));
          tacCodeParam tacP1 = {.instruction="mov", .op1=utstring_body(operand_array), .op2=$$->leftBranch->leftBranch->value, .lineType=enumTwoOp};
          add_TAC_line(tacP1);
          increaseSetSize(setInfoPointer->setID);
          utstring_free(operand_array);
          utstring_free(sizePlusOne);
          utstring_free(size);
        }
      }
    }
    print_parser_msg("add to set OP\n", DEBUG);
  }
  | REMOVE_SET_OP '(' setBody ')' {
    astParam astP = { .leftBranch = $3, .type="IDENTIFIER", .value = $1, .nodeType = enumValueLeftBranch, .astNodeClass="SET_OPERATION_EXPRESSION REMOVE_FROM_SET_OP" };
    $$ = add_ast_node(astP);
    print_parser_msg("remove from set OP\n", DEBUG);
  }
  | EXISTS_IN_SET_OP '(' setBody ')' {
    astParam astP = { .leftBranch = $3, .type="IDENTIFIER", .value = $1, .nodeType = enumValueLeftBranch, .astNodeClass="SET_OPERATION_EXPRESSION EXISTS_FROM_SET_OP" };
    $$ = add_ast_node(astP);
    print_parser_msg("exists el in set OP\n", DEBUG);
  }
  | IS_SET '(' term ')' {
    astParam astP = { .leftBranch = $3, .type="IDENTIFIER", .value = $1, .nodeType = enumValueLeftBranch, .astNodeClass="SET_OPERATION_EXPRESSION IS_SET" };
    $$ = add_ast_node(astP);
    print_parser_msg("is_set OP\n", DEBUG);
  }
;

setBody: comparationalExpression ADD_IN_OP setOperationalExpression {
    astParam astP = {
      .leftBranch = $1, .rightBranch = $3, .nodeType = enumLeftRightBranch, .astNodeClass="SET_OPERATION_EXPRESSION_SET_BODY"
    };
    $$ = add_ast_node(astP);
    print_parser_msg("is_set body\n", DEBUG);
  }
  | comparationalExpression ADD_IN_OP variable {
    astParam astP = {
      .leftBranch = $1, .rightBranch = $3, .nodeType = enumLeftRightBranch, .astNodeClass="SET_OPERATION_EXPRESSION_SET_BODY"
    };
    $$ = add_ast_node(astP);
    print_parser_msg("is_set body\n", DEBUG);
  }
;

variableAssignment: IDENTIFIER ASSIGN expression {
    verify_declared_id($1, running_line_count, running_column_count);
    astParam astP = { .leftBranch = $3, .type="IDENTIFIER", .value = $1, .nodeType = enumValueLeftBranch, .astNodeClass="VARIABLE_ASSIGNMENT" };
    $$ = add_ast_node(astP);
    int symbolOK = 0;
    if (strcmp($$->leftBranch->astNodeClass, "IDENTIFIER") == 0) {
      symbolOK = verify_declared_id($$->leftBranch->value, running_line_count, running_column_count);
    }
    if (symbolOK == 0) {
      if ($3->tempReg && $3->value) {
        tacCodeParam tacP = { .instruction = "mov", .op1 = $1, .op2 = $3->tempReg, .lineType=enumTwoOp};
        add_TAC_line(tacP);
      } else if ($3->value && strcmp($3->value, "EMPTY")==0) {
        struct setInfo *setInfoPointer;
        setInfoPointer = getSetSymbolInfo($1);
        if (setInfoPointer) {
          tacCodeParam tacP = { .instruction = "mov", .op1 = setInfoPointer->pointerToSet, .op2 = $1, .lineType=enumTwoOp};
          add_TAC_line(tacP);
        }
      } else if ($3->value && strcmp($3->value, "EMPTY")!=0) {
        tacCodeParam tacP = { .instruction = "mov", .op1 = $1, .op2 = $3->value, .lineType=enumTwoOp};
        add_TAC_line(tacP);
      } else if ($3->tempReg) {
        tacCodeParam tacP = { .instruction = "mov", .op1 = $1, .op2 = $3->tempReg, .lineType=enumTwoOp};
        add_TAC_line(tacP);
      }
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

term: '(' comparationalExpression ')' {
    $$=$2;
    print_parser_msg("( operationalExp )\n", DEBUG);
  }
  | variable {
    $$=$1;
    print_parser_msg("variable\n", DEBUG);
  }
  | setOperationalExpression {
    $$=$1;
    print_parser_msg("set op\n", DEBUG);
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
  int symbolOK = verify_declared_id($1, running_line_count, running_column_count);
  currentCalledFunction.name = $1;
  astParam astP = { .leftBranch = $3, .type="IDENTIFIER", .value = $1, .nodeType = enumValueLeftBranch, .astNodeClass="FUNCTION_CALL" };
  $$ = add_ast_node(astP);
  if (symbolOK == 0) { /* symbol is declared */
    if (currentCalledFunction.amountOfParamsCalled == 0) {
      tacCodeParam tacP = { .instruction = "call", .op1 = $1, .lineType=enumOneOp};
      add_TAC_line(tacP);
    } else {
      UT_string *tmp;
      utstring_new(tmp);
      stringify_integer(tmp, currentCalledFunction.amountOfParamsCalled);
      tacCodeParam tacP = { .instruction = "call", .op1 = $1, .op2 = utstring_body(tmp), .lineType=enumTwoOp};
      add_TAC_line(tacP);
      utstring_free(tmp);
    }
  }
  verify_func_call_params(currentCalledFunction.name, currentCalledFunction.amountOfParamsCalled, currentCalledFunction.passedParams, running_line_count);
  currentCalledFunction.amountOfParamsCalled = 0;
  currentParamsReg = 0;
  set_temporary_register($$, &currentTempReg);
  tacCodeParam tacP = { .instruction = "pop", .op1 = $$->tempReg, .lineType=enumOneOp};
  add_TAC_line(tacP);
  print_parser_msg("function call\n", DEBUG);
}
;

functionArguments: callArguments {$$=$1;}
  | %empty {
    $$ = NULL;
    print_parser_msg("empty function argument\n", DEBUG);
  }
;

callArguments: callArguments ',' comparationalExpression {
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
    tacCodeValidationParams tacP = { .instruction = "param", .op1 = $3, .lineType=enumOneOp};
    check_ops_and_add_TAC_line(tacP);
    currentCalledFunction.amountOfParamsCalled = currentCalledFunction.amountOfParamsCalled + 1;
    print_parser_msg("function callarguments, opExpression\n", DEBUG);
  }
  | comparationalExpression {
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
    tacCodeValidationParams tacP = { .instruction = "param", .op1 = $1, .lineType=enumOneOp};
    check_ops_and_add_TAC_line(tacP);

    currentCalledFunction.amountOfParamsCalled = currentCalledFunction.amountOfParamsCalled + 1;

    print_parser_msg("function callarguments\n", DEBUG);
  }
;

variableInit: typeSpecifier IDENTIFIER ';' {
  astParam astP = { .leftBranch = $1, .type="IDENTIFIER", .value = $2, .nodeType = enumValueLeftBranch, .astNodeClass="VARIABLE_INIT" };
  parserNode *node = add_ast_node(astP);
  astParam astP2 = { .leftBranch = $1, .type=node->leftBranch->value, .value = $2, .nodeType = enumValueLeftBranch, .astNodeClass="VARIABLE_INIT" };
  $$ = add_ast_node(astP2);
  free(node);
  symbolParam symbol = { .symbolID = globalCounterOfSymbols, .symbolType=enumVariable, .type = $$->leftBranch->value, .name = $2, .line= running_line_count, .column= running_column_count};
  add_symbol_node(symbol);
  if ($$->leftBranch && $$->leftBranch->type && strcmp($$->leftBranch->type, "T_SET") == 0) {
    UT_string *currentPos;
    utstring_new(currentPos);
    create_temporary_register(currentPos, &currentTempReg);
    set_temporary_register($$, &currentTempReg);
    addSymbolToSetInfoTable(globalCounterOfSymbols, strdup(utstring_body(currentPos)), 0);
    utstring_free(currentPos);
  }
  globalCounterOfSymbols++;
  print_parser_msg("variable initialization\n", DEBUG);
}
;

variable: IDENTIFIER {
  astParam astP = { .type = "IDENTIFIER", .value = $1, .nodeType = enumValueTypeOnly, .astNodeClass="IDENTIFIER" };
  $$ = add_ast_node(astP);
  int symbolOK = verify_declared_id($1, running_line_count, running_column_count);
  if (symbolOK == 0) {
    int *symbolkey, symbolID;
    struct symbolNode *symbol;
    scopeInfo current_scope = get_current_scope();
    symbolID = get_symbolID_by_name_and_current_scope($1, current_scope.scopeID, current_scope.level);
    if (symbolID != -1) {
      symbolkey = &symbolID;
      HASH_FIND_INT(symbolTable, symbolkey, symbol);
      $$->tempReg = symbol->tacName;
    }
  }
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
  if(yynerrs == 0) {
    printf("\n=================== Parser AST ====================\n\n");
    print_parser_ast(parser_ast, 0);
  }

  printf("\nReported amount of lexical errors: %d\n", lexical_errors_count);
  printf("Reported amount of syntax errors: %d\n", yynerrs); /* mostrar so tabela de simbolos */
  printf("Reported amount of semantic errors: %d\n", semantic_errors); /* mostrar tanto arvore quanto tabela */

  if (lexical_errors_count == 0 && yynerrs == 0 && semantic_errors == 0) {
    createTacFile(tacFileHead);
  }

  free_TAC_list(tacFileHead);

  free_TAC_table_list(tacFileTableHead);

  free_symbols_table();

  free_parser_ast(parser_ast);

  free_scope_stack();

  free_setInfo_table();

  yylex_destroy();

  return 0;
}

void yyerror(const char* msg) {
  fprintf(stderr, "%s at line: %d, column: %d\n", msg, running_line_count, running_column_count);
}