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
# define YYDEBUG 0
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
    ASSIGN = 259,                  /* ASSIGN  */
    INT = 260,                     /* INT  */
    FLOAT = 261,                   /* FLOAT  */
    EMPTY = 262,                   /* EMPTY  */
    T_INT = 263,                   /* T_INT  */
    T_FLOAT = 264,                 /* T_FLOAT  */
    T_ELEM = 265,                  /* T_ELEM  */
    T_SET = 266,                   /* T_SET  */
    ADD_OP = 267,                  /* ADD_OP  */
    SUB_OP = 268,                  /* SUB_OP  */
    MULT_OP = 269,                 /* MULT_OP  */
    DIV_OP = 270,                  /* DIV_OP  */
    ILT = 271,                     /* ILT  */
    ILTE = 272,                    /* ILTE  */
    IGT = 273,                     /* IGT  */
    IGTE = 274,                    /* IGTE  */
    IDIFF = 275,                   /* IDIFF  */
    IEQ = 276,                     /* IEQ  */
    READ = 277,                    /* READ  */
    WRITE = 278,                   /* WRITE  */
    WRITELN = 279,                 /* WRITELN  */
    RETURN = 280,                  /* RETURN  */
    IF = 281,                      /* IF  */
    ELSE = 282,                    /* ELSE  */
    FOR = 283                      /* FOR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 23 "compLex_syntatical.y"

  char* str;
  struct parseNode* node;

#line 97 "compLex_syntatical.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_COMPLEX_SYNTATICAL_TAB_H_INCLUDED  */
