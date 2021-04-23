%option nounput
%option noinput

%{
#include <stdio.h>

#include "compLex_syntatical.tab.h"

/* Global vars */
int running_line_count = 1;
int running_column_count = 1;
extern int lexical_errors_count;

/* Pre-declaring functions */
void throw_nonexistent_symbol_error(char* symbol);
%}

%option noyywrap

/* Others */
COMMENT "//".*
UNDERSCORE "_"
QUOTES \'
EOL \n
WHITESPACE [ \t]+
IDENTIFIER {LETTER}({LETTER}|{DIGIT}|{UNDERSCORE})*
MAIN_FUNC "main"

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
STR \"[^\"]*\"|\'([^'\\\n]|\\.)'

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
  yylval.str = (char *) strdup(yytext);
  running_column_count += yyleng;
  return STR;
}

{INT} {
  // printf("<integer number, %d>\n", atoi(yytext));
  running_column_count += yyleng;
  yylval.str = (char *) strdup(yytext);
  return INT;
}

{FLOAT} { 
  // printf("<floating point number, %0.2f>\n", atof(yytext));
  running_column_count += yyleng;
  yylval.str = (char *) strdup(yytext);
  return FLOAT;
}

{MAIN_FUNC} { 
  // printf("<main keyword, %s>\n", yytext);
  running_column_count += yyleng;
  yylval.str = (char *) strdup(yytext);
  return MAIN_FUNC;
}

{EMPTY} {
  // printf("<emptyConst, %s>\n", yytext);
  running_column_count += yyleng;
  yylval.str = (char *) strdup(yytext);
  return EMPTY;
}

{T_INT} {
  // printf("<typeInteger, %s>\n", yytext);
  running_column_count += yyleng;
  yylval.str = (char *) strdup(yytext);
  return T_INT;
}

{T_FLOAT} {
  // printf("<typeFloat, %s>\n", yytext);
  running_column_count += yyleng;
  yylval.str = (char *) strdup(yytext);
  return T_FLOAT;
}

{T_ELEM} {
  // printf("<typeElem, %s>\n", yytext);
  running_column_count += yyleng;
  yylval.str = (char *) strdup(yytext);
  return T_ELEM;
}

{T_SET} {
  // printf("<typeSet, %s>\n", yytext);
  running_column_count += yyleng;
  yylval.str = (char *) strdup(yytext);
  return T_SET;
}

{AND} {
  // printf("<logical op AND, %s>\n", yytext);
  running_column_count += yyleng;
  yylval.str = (char *) strdup(yytext);
  return AND;
}

{OR} {
  // printf("<logical op OR, %s>\n", yytext);
  running_column_count += yyleng;
  yylval.str = (char *) strdup(yytext);
  return OR;
}

{NEG} {
  // printf("<logical op Negation, %s>\n", yytext);
  running_column_count += yyleng;
  yylval.str = (char *) strdup(yytext);
  return NEG;
}

{ASSIGN} {
  // printf("<assign op, %s>\n", yytext);
  running_column_count += yyleng;
  yylval.str = (char *) strdup(yytext);
  return ASSIGN;
}

{ADD_OP} {
  // printf("<add op, %s>\n", yytext);
  running_column_count += yyleng;
  yylval.str = (char *) strdup(yytext);
  return ADD_OP;
}

{SUB_OP} {
  // printf("<sub op, %s>\n", yytext);
  running_column_count += yyleng;
  yylval.str = (char *) strdup(yytext);
  return SUB_OP;
}

{MULT_OP} {
  // printf("<mult op, %s>\n", yytext);
  running_column_count += yyleng;
  yylval.str = (char *) strdup(yytext);
  return MULT_OP;
}

{DIV_OP} {
  // printf("<div op, %s>\n", yytext);
  running_column_count += yyleng;
  yylval.str = (char *) strdup(yytext);
  return DIV_OP;
}

{ADD_SET_OP} {
  // printf("<add to set op, %s>\n", yytext);
  running_column_count += yyleng;
  return ADD_SET_OP;
}

{ADD_IN_OP} {
  // printf("<add in op (keyword), %s>\n", yytext);
  running_column_count += yyleng;
  return ADD_IN_OP;
}

{REMOVE_SET_OP} {
  // printf("<remove from Set op (keyword), %s>\n", yytext);
  running_column_count += yyleng;
  return REMOVE_SET_OP;
}

{EXISTS_IN_SET_OP} {
  // printf("<exists in Set op (keyword), %s>\n", yytext);
  running_column_count += yyleng;
  return EXISTS_IN_SET_OP;
}

{IF} {
  // printf("<if op, %s>\n", yytext);
  running_column_count += yyleng;
  yylval.str = (char *) strdup(yytext);
  return IF;
}

{ELSE} {
  // printf("<else op, %s>\n", yytext);
  running_column_count += yyleng;
  yylval.str = (char *) strdup(yytext);
  return ELSE;
}

{FOR} {
  // printf("<for op, %s>\n", yytext);
  running_column_count += yyleng;
  yylval.str = (char *) strdup(yytext);
  return FOR;
}

{SET_FORALL} {
  // printf("<set forall flux control, %s>\n", yytext);
  running_column_count += yyleng;
  yylval.str = (char *) strdup(yytext);
  return SET_FORALL;
}

{RETURN} {
  // printf("<return op, %s>\n", yytext);
  running_column_count += yyleng;
  yylval.str = (char *) strdup(yytext);
  return RETURN;
}

{ILT} {
  // printf("<is less then op, %s>\n", yytext);
  running_column_count += yyleng;
  yylval.str = (char *) strdup(yytext);
  return ILT;
}

{ILTE} {
  // printf("<is less then equal op, %s>\n", yytext);
  running_column_count += yyleng;
  yylval.str = (char *) strdup(yytext);
  return ILTE;
}

{IGT} {
  // printf("<is greater then op, %s>\n", yytext);
  running_column_count += yyleng;
  yylval.str = (char *) strdup(yytext);
  return IGT;
}

{IGTE} {
  // printf("<is greater then equal op, %s>\n", yytext);
  running_column_count += yyleng;
  yylval.str = (char *) strdup(yytext);
  return IGTE;
}

{IDIFF} {
  // printf("<is different then op, %s>\n", yytext);
  running_column_count += yyleng;
  yylval.str = (char *) strdup(yytext);
  return IDIFF;
}

{IEQ} {
  // printf("<is equal then op, %s>\n", yytext);
  running_column_count += yyleng;
  yylval.str = (char *) strdup(yytext);
  return IEQ;
}

{IS_SET} {
  // printf("<isSet operator op, %s>\n", yytext);
  running_column_count += yyleng;
  yylval.str = (char *) strdup(yytext);
  return IS_SET;
}

{READ} {
  // printf("<read directive, %s>\n", yytext);
  running_column_count += yyleng;
  yylval.str = (char *) strdup(yytext);
  return READ;
}

{WRITE} {
  // printf("<write directive, %s>\n", yytext);
  running_column_count += yyleng;
  yylval.str = (char *) strdup(yytext);
  return WRITE;
}

{WRITELN} {
  // printf("<writeLine directive, %s>\n", yytext);
  running_column_count += yyleng;
  yylval.str = (char *) strdup(yytext);
  return WRITELN;
}

<INITIAL,STRING>{IDENTIFIER} { 
  // printf("<identifier, %s>\n", yytext);
  running_column_count += yyleng;
  yylval.str = (char *) strdup(yytext);
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
  throw_nonexistent_symbol_error(yytext);
}

%%

void throw_nonexistent_symbol_error(char* symbol){
  printf("%-14s unrecognized token '%s' at line: %d, column: %d \n","lexical error,", symbol, running_line_count, running_column_count);
  running_column_count += yyleng;
  lexical_errors_count++;
}