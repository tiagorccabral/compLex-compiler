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

%token IDENTIFIER
%token T_INT T_FLOAT T_ELEM T_SET

%type <node> variableInit

%%

entryPoint: programEntries { printf("Program start\n"); }
;

programEntries: variableInit {;}
  | functions {

  }
;

functions: type IDENTIFIER {}
  | '(' ')' {
    printf("function \n");
  }
;

variableInit: type IDENTIFIER ';' {
  printf("variable initialization\n");
}
;

type: T_INT {printf("integer type\n");}
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

// %error-verbose
// %debug
// %locations

// %{
//     #include <stdio.h>

//     extern int yylex();
//     int yyerror(const char *s);
//     extern int yylex_destroy();
//     extern FILE *yyin;


// %}

// %token TYPE_INT
// %token TYPE_FLOAT
// %token TYPE_SET
// %token TYPE_ELEM
// %token <string> ID
// %token RETURN
// %token SEMICOLON
// %token CURLY_BRACKETS_OPEN
// %token CURLY_BRACKETS_CLOSE
// %token PARENTHESES_OPEN
// %token PARENTHESES_CLOSE
// %token COMMA
// %token SINGLE_QUOTE
// %token DOUBLE_QUOTE

// %union{
//     char* tokenname;
//     struct node *node;
// }

// %%

// start : programlist { printf("start\n"); }
//                 | error { printf("deu ruim start\n"); }
// ;

// programlist : programlist variable
//                 | variable { printf("programlist\n"); }
//                 | programlist function
//                 | function
//                 | error { printf("deu ruim programlist\n"); }
// ;

// type: TYPE_INT | TYPE_FLOAT

// variable : type ID { 
//     printf("variable"); 
//     printf("\t %s \n", $2);
//     }
//             | error { printf("deu ruim variable\n"); }
// ;

// function : type ID "(" ")"
//             | error { printf("deu ruim function\n"); }
// ;

// %%

// //  main function from: https://westes.github.io/flex/manual/Simple-Examples.html#Simple-Examples

// int yyerror(const char *s) {
//     printf("yyerror: %s\n", s);
// }

// int main(int argc, char **argv){
    
//     ++argv, --argc;
    
//     if (argc > 0)
//         yyin = fopen( argv[0], "r" );
//     else
//         yyin = stdin;

//     yyparse();
//     fclose(yyin);
//     yylex_destroy();

//     return 0;
// }