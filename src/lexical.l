%option nounput
%option noinput

%{
#include <stdio.h>

#include "compLex_syntatical.tab.h"

/* Global vars */
int running_line_count = 1;
int running_column_count = 1;
int total_errors_count = 0;

/* Pre-declaring functions */
void throw_nonexistent_symbol_error(char* symbol);
void yyerror(const char* msg);
%}

%option noyywrap

/* Others */
COMMENT "//".*
UNDERSCORE "_"
QUOTES \'
EOL \n
WHITESPACE [ \t]+
IDENTIFIER {LETTER}({LETTER}|{DIGIT}|{UNDERSCORE})*

/* Constants */
DIGIT [0-9]
LETTER [a-zA-z]
EMPTY "EMPTY"

/* Data types */
T_INT "int"
T_FLOAT "float"
T_ELEM "elem"
T_SET "set"

/* Data type primitives */
INT {DIGIT}+
FLOAT {DIGIT}+[.]{DIGIT}+
%s STRING
STR \"[^\"]*\"|'[^']*'

/* Operations */
ASSIGN "="
ADD_OP "+"
SUB_OP "-"
MULT_OP "*"
DIV_OP "/"
ADD_SET_OP "add"
ADD_IN_OP "in"
REMOVE_SET_OP "remove"
EXISTS_IN_SET_OP "exists"

/* Logical operators */
AND "&&"
OR "||"
NEG "!"

/* Relational operators */
ILT "<"
ILTE "<="
IGT ">"
IGTE ">="
IDIFF "!="
IEQ "=="
IS_SET "is_set"

/* Flux control */
IF "if"
ELSE "else"
FOR "for"
SET_FORALL "forall"
RETURN "return"

/* Input/Output */
READ "read"
WRITE "write"
WRITELN "writeln"

%%

{EOL} {
  running_column_count = 1;
  running_line_count++;
}

{WHITESPACE} {
  running_column_count += yyleng;
}

{QUOTES} {
  // printf("<quote, %s>\n", yytext);
  running_column_count += yyleng;
}

{STR} {
  // printf("<string value, %s>\n", yytext);
  running_column_count += yyleng;
}

{INT} {
  // printf("<integer number, %d>\n", atoi(yytext));
  running_column_count += yyleng;
  return INT;
}

{FLOAT} { 
  // printf("<floating point number, %0.2f>\n", atof(yytext));
  running_column_count += yyleng;
  return FLOAT;
}

{EMPTY} {
  // printf("<emptyConst, %s>\n", yytext);
  running_column_count += yyleng;
  return EMPTY;
}

{T_INT} {
  // printf("<typeInteger, %s>\n", yytext);
  running_column_count += yyleng;
  return T_INT;
}

{T_FLOAT} {
  // printf("<typeFloat, %s>\n", yytext);
  running_column_count += yyleng;
  return T_FLOAT;
}

{T_ELEM} {
  // printf("<typeElem, %s>\n", yytext);
  running_column_count += yyleng;
  return T_ELEM;
}

{T_SET} {
  // printf("<typeSet, %s>\n", yytext);
  running_column_count += yyleng;
  return T_SET;
}

{AND} {
  // printf("<logical op AND, %s>\n", yytext);
  running_column_count += yyleng;
}

{OR} {
  // printf("<logical op OR, %s>\n", yytext);
  running_column_count += yyleng;
}

{NEG} {
  // printf("<logical op Negation, %s>\n", yytext);
  running_column_count += yyleng;
}

{ASSIGN} {
  // printf("<assign op, %s>\n", yytext);
  running_column_count += yyleng;
  return ASSIGN;
}

{ADD_OP} {
  // printf("<add op, %s>\n", yytext);
  running_column_count += yyleng;
  return ADD_OP;
}

{SUB_OP} {
  // printf("<sub op, %s>\n", yytext);
  running_column_count += yyleng;
  return SUB_OP;
}

{MULT_OP} {
  // printf("<mult op, %s>\n", yytext);
  running_column_count += yyleng;
  return MULT_OP;
}

{DIV_OP} {
  // printf("<div op, %s>\n", yytext);
  running_column_count += yyleng;
  return DIV_OP;
}

{ADD_SET_OP} {
  // printf("<add to set op, %s>\n", yytext);
  running_column_count += yyleng;
}

{ADD_IN_OP} {
  // printf("<add in op (keyword), %s>\n", yytext);
  running_column_count += yyleng;
}

{REMOVE_SET_OP} {
  // printf("<remove from Set op (keyword), %s>\n", yytext);
  running_column_count += yyleng;
}

{EXISTS_IN_SET_OP} {
  // printf("<exists in Set op (keyword), %s>\n", yytext);
  running_column_count += yyleng;
}

{IF} {
  // printf("<if op, %s>\n", yytext);
  running_column_count += yyleng;
  return IF;
}

{ELSE} {
  // printf("<else op, %s>\n", yytext);
  running_column_count += yyleng;
  return ELSE;
}

{FOR} {
  // printf("<for op, %s>\n", yytext);
  running_column_count += yyleng;
}

{SET_FORALL} {
  // printf("<set forall flux control, %s>\n", yytext);
  running_column_count += yyleng;
}

{RETURN} {
  // printf("<return op, %s>\n", yytext);
  running_column_count += yyleng;
  return RETURN;
}

{ILT} {
  // printf("<is less then op, %s>\n", yytext);
  running_column_count += yyleng;
  return ILT;
}

{ILTE} {
  // printf("<is less then equal op, %s>\n", yytext);
  running_column_count += yyleng;
  return ILTE;
}

{IGT} {
  // printf("<is greater then op, %s>\n", yytext);
  running_column_count += yyleng;
  return IGT;
}

{IGTE} {
  // printf("<is greater then equal op, %s>\n", yytext);
  running_column_count += yyleng;
  return IGTE;
}

{IDIFF} {
  // printf("<is different then op, %s>\n", yytext);
  running_column_count += yyleng;
  return IDIFF;
}

{IEQ} {
  // printf("<is equal then op, %s>\n", yytext);
  running_column_count += yyleng;
  return IEQ;
}

{IS_SET} {
  // printf("<isSet operator op, %s>\n", yytext);
  running_column_count += yyleng;
}

{READ} {
  // printf("<read directive, %s>\n", yytext);
  running_column_count += yyleng;
  return READ;
}

{WRITE} {
  // printf("<write directive, %s>\n", yytext);
  running_column_count += yyleng;
  return WRITE;
}

{WRITELN} {
  // printf("<writeLine directive, %s>\n", yytext);
  running_column_count += yyleng;
  return WRITELN;
}

<INITIAL,STRING>{IDENTIFIER} { 
  // printf("<identifier, %s>\n", yytext);
  running_column_count += yyleng;
  return IDENTIFIER;
}

"," {
  // printf("<%s>\n", yytext);
  running_column_count += yyleng;
  return ',';
}

";" {
  // printf("<%s>\n", yytext);
  running_column_count += yyleng;
  return ';';
}

"(" {
  // printf("<%s>\n", yytext);
  running_column_count += yyleng;
  return '(';
}

")" {
  // printf("<%s>\n", yytext);
  running_column_count += yyleng;
  return ')';
}

"{" {
  // printf("<%s>\n", yytext);
  running_column_count += yyleng;
  return '{';
}

"}" {
  // printf("<%s>\n", yytext);
  running_column_count += yyleng;
  return '}';
}

{COMMENT} {}

. { 
  running_column_count += yyleng;
  throw_nonexistent_symbol_error(yytext);
}

%%

void yyerror(const char* msg) {
   total_errors_count++;
   fprintf(stderr, "%s at line: %d, column: %d\n", msg, running_line_count, running_column_count);
}

void throw_nonexistent_symbol_error(char* symbol){
  char *error = (char *)malloc((strlen(symbol) + 1 + 35) * sizeof(char));
  sprintf(error, "Error on lexical analisys: \nNonexistent symbol '%s' detected ", symbol);
  yyerror(error);
  free(error);
}