%{
#include <string.h>
#include <stdio.h>
%}

/* Constants */
DIGIT [0-9]
LETTER [a-zA-z]
EMPTY "EMPTY"

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

/* Logical operators */
AND "&&"
OR "||"
NEG "!"

/* Relational operators */
ILT "<"
ILTE "<="
IGT ">"
IGTE ">="
ID "!="
IEQ "=="

/* Flux control */
IF "if"
ELSE "else"
ELSEIF "else if"
FOR "for"
RETURN "return"

/* Input/Output */
READ "read"
WRITE "write"
WRITELN "writeln"

%%
{DIGIT}+ {
  printf("<id, %d>\n", atoi(yytext));
}
{DIGIT}+[.]{DIGIT}+ { 
  printf("<id, %0.2f>\n", atof(yytext));
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

[[:space:]]+ ;
%%

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
