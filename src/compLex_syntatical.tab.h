/* A Bison parser, made by GNU Bison 3.7.6.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_COMPLEX_SYNTATICAL_TAB_H_INCLUDED
# define YY_YY_COMPLEX_SYNTATICAL_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IDENTIFIER = 258,              /* IDENTIFIER  */
    MAIN_FUNC = 259,               /* MAIN_FUNC  */
    ASSIGN = 260,                  /* ASSIGN  */
    INT = 261,                     /* INT  */
    FLOAT = 262,                   /* FLOAT  */
    EMPTY = 263,                   /* EMPTY  */
    STR = 264,                     /* STR  */
    T_INT = 265,                   /* T_INT  */
    T_FLOAT = 266,                 /* T_FLOAT  */
    T_ELEM = 267,                  /* T_ELEM  */
    T_SET = 268,                   /* T_SET  */
    ADD_OP = 269,                  /* ADD_OP  */
    SUB_OP = 270,                  /* SUB_OP  */
    MULT_OP = 271,                 /* MULT_OP  */
    DIV_OP = 272,                  /* DIV_OP  */
    ADD_SET_OP = 273,              /* ADD_SET_OP  */
    REMOVE_SET_OP = 274,           /* REMOVE_SET_OP  */
    EXISTS_IN_SET_OP = 275,        /* EXISTS_IN_SET_OP  */
    IS_SET = 276,                  /* IS_SET  */
    ADD_IN_OP = 277,               /* ADD_IN_OP  */
    ILT = 278,                     /* ILT  */
    ILTE = 279,                    /* ILTE  */
    IGT = 280,                     /* IGT  */
    IGTE = 281,                    /* IGTE  */
    IDIFF = 282,                   /* IDIFF  */
    IEQ = 283,                     /* IEQ  */
    AND = 284,                     /* AND  */
    OR = 285,                      /* OR  */
    NEG = 286,                     /* NEG  */
    READ = 287,                    /* READ  */
    WRITE = 288,                   /* WRITE  */
    WRITELN = 289,                 /* WRITELN  */
    RETURN = 290,                  /* RETURN  */
    IF = 291,                      /* IF  */
    ELSE = 292,                    /* ELSE  */
    FOR = 293,                     /* FOR  */
    SET_FORALL = 294               /* SET_FORALL  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 85 "compLex_syntatical.y"

  char* str;
  struct parserNode* node;

#line 108 "compLex_syntatical.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_COMPLEX_SYNTATICAL_TAB_H_INCLUDED  */
