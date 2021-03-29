/* A Bison parser, made by GNU Bison 3.7.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
    T_INT = 264,                   /* T_INT  */
    T_FLOAT = 265,                 /* T_FLOAT  */
    T_ELEM = 266,                  /* T_ELEM  */
    T_SET = 267,                   /* T_SET  */
    ADD_OP = 268,                  /* ADD_OP  */
    SUB_OP = 269,                  /* SUB_OP  */
    MULT_OP = 270,                 /* MULT_OP  */
    DIV_OP = 271,                  /* DIV_OP  */
    ADD_SET_OP = 272,              /* ADD_SET_OP  */
    REMOVE_SET_OP = 273,           /* REMOVE_SET_OP  */
    EXISTS_IN_SET_OP = 274,        /* EXISTS_IN_SET_OP  */
    IS_SET = 275,                  /* IS_SET  */
    ADD_IN_OP = 276,               /* ADD_IN_OP  */
    ILT = 277,                     /* ILT  */
    ILTE = 278,                    /* ILTE  */
    IGT = 279,                     /* IGT  */
    IGTE = 280,                    /* IGTE  */
    IDIFF = 281,                   /* IDIFF  */
    IEQ = 282,                     /* IEQ  */
    READ = 283,                    /* READ  */
    WRITE = 284,                   /* WRITE  */
    WRITELN = 285,                 /* WRITELN  */
    RETURN = 286,                  /* RETURN  */
    IF = 287,                      /* IF  */
    ELSE = 288,                    /* ELSE  */
    FOR = 289,                     /* FOR  */
    SET_FORALL = 290               /* SET_FORALL  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 42 "compLex_syntatical.y"

  char* str;
  struct parseNode* node;

#line 104 "compLex_syntatical.tab.h"

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
