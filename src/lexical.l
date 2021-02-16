%{
#include <stdio.h>
%}

DIGIT [0-9]
LETTER [a-zA-z]

%%
{DIGIT}+ { printf("Inteiro: %d\n", atoi(yytext)); }
{DIGIT}+[.]{DIGIT}+ { printf("Float\n"); }

[[:space:]]+ ;
%%

int main ()  {
  yylex();
  return 0;
}
