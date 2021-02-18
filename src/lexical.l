%{
#include <stdio.h>

/* Global vars */
int running_line_count = 1;
int total_errors_count = 0;

/* Pre-declaring functions */
void throw_nonexistent_symbol_error(char* symbol);
void yyerror(const char* msg);
%}

/* Others */
COMMENT "//".*
UNDERSCORE "_"
QUOTES \'
NONEXISTENT_SYM "."
EOL \n
WHITESPACE [ \t]+

/* Constants */
DIGIT [0-9]
LETTER [a-zA-z]
EMPTY "EMPTY"
%s STRING
STR [^\"]*

/* Data types */
T_INT "int"
T_FLOAT "float"
T_ELEM "elem"
T_SET "set"

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

IDENTIFIER ({LETTER})({LETTER}|{DIGIT}|{UNDERSCORE})*

%%

{EOL} {
  running_line_count++;
}

{WHITESPACE} {}

{QUOTES} {
  printf("<quote, %s>\n", yytext);
}

<STRING>{STR} {
  printf("<strig value, %s>\n", yytext);
}

{DIGIT}+ {
  printf("<integer number, %d>\n", atoi(yytext));
}
{DIGIT}+[.]{DIGIT}+ { 
  printf("<floating point number, %0.2f>\n", atof(yytext));
}

{EMPTY} {
  printf("<emptyConst, %s>\n", yytext);
}

{T_INT} {
  printf("<typeInteger, %s>\n", yytext);
}

{T_FLOAT} {
  printf("<typeFloat, %s>\n", yytext);
}

{T_ELEM} {
  printf("<typeElem, %s>\n", yytext);
}

{T_SET} {
  printf("<typeSet, %s>\n", yytext);
}

{AND} {
  printf("<logical op AND, %s>\n", yytext);
}

{OR} {
  printf("<logical op OR, %s>\n", yytext);
}

{NEG} {
  printf("<logical op Negation, %s>\n", yytext);
}

{ASSIGN} {
  printf("<assign op, %s>\n", yytext);
}

{ADD_OP} {
  printf("<add op, %s>\n", yytext);
}

{SUB_OP} {
  printf("<sub op, %s>\n", yytext);
}

{MULT_OP} {
  printf("<mult op, %s>\n", yytext);
}

{DIV_OP} {
  printf("<div op, %s>\n", yytext);
}

{ADD_SET_OP} {
  printf("<add to set op, %s>\n", yytext);
}

{ADD_IN_OP} {
  printf("<add in op (keyword), %s>\n", yytext);
}

{REMOVE_SET_OP} {
  printf("<remove from Set op (keyword), %s>\n", yytext);
}

{EXISTS_IN_SET_OP} {
  printf("<exists in Set op (keyword), %s>\n", yytext);
}

{IF} {
  printf("<if op, %s>\n", yytext);
}

{ELSE} {
  printf("<else op, %s>\n", yytext);
}

{FOR} {
  printf("<for op, %s>\n", yytext);
}

{SET_FORALL} {
  printf("<set forall flux control, %s>\n", yytext);
}

{RETURN} {
  printf("<return op, %s>\n", yytext);
}

{ILT} {
  printf("<is less then op, %s>\n", yytext);
}

{ILTE} {
  printf("<is less then equal op, %s>\n", yytext);
}

{IGT} {
  printf("<is greater then op, %s>\n", yytext);
}

{IGTE} {
  printf("<is greater then equal op, %s>\n", yytext);
}

{IDIFF} {
  printf("<is different then op, %s>\n", yytext);
}

{IEQ} {
  printf("<is equal then op, %s>\n", yytext);
}

{IS_SET} {
  printf("<isSet operator op, %s>\n", yytext);
}

{READ} {
  printf("<read directive, %s>\n", yytext);
}

{WRITE} {
  printf("<write directive, %s>\n", yytext);
}

{WRITELN} {
  printf("<writeLine directive, %s>\n", yytext);
}

<INITIAL,STRING>{IDENTIFIER} { 
  printf("<identifier, %s>\n", yytext);
}

"," {
  printf("<%s>\n", yytext);
}

";" {
  printf("<%s>\n", yytext);
}

"(" {
  printf("<%s>\n", yytext);
}

")" {
  printf("<%s>\n", yytext);
}

"{" {
  printf("<%s>\n", yytext);
}

"}" {
  printf("<%s>\n", yytext);
}

{COMMENT} {}

. { throw_nonexistent_symbol_error(yytext); }

%%

void yyerror(const char* msg) {
  total_errors_count++;
  fprintf(stderr, "%s at line: %d\n", msg, running_line_count);
}

void throw_nonexistent_symbol_error(char* symbol){
  char *error = (char *)malloc((strlen(symbol) + 1 + 35) * sizeof(char));
  sprintf(error, "Error on lexical analisys: \nNonexistent symbol '%s' detected ", symbol);
  yyerror(error);
  free(error);
}

int main(int argc, char **argv) {
  if(argc > 1) {
    yyin = fopen(argv[1], "r");
  }
  else {
    yyin = stdin;
  }

  yylex();
  fclose(yyin);
}
