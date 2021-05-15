/* A Bison parser, made by GNU Bison 3.7.6.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30706

/* Bison version string.  */
#define YYBISON_VERSION "3.7.6"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 5 "compLex_syntatical.y"


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
int currentForLoop = 0; /* keeps count of the current for loop */
int forIncrementCounter = 0;

char *return_statement_type; /* aux vars to verify presence of return statements*/
struct parserNode* returned_node; /* aux vars to verify presence of return statements*/


#line 142 "compLex_syntatical.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "compLex_syntatical.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_MAIN_FUNC = 4,                  /* MAIN_FUNC  */
  YYSYMBOL_ASSIGN = 5,                     /* ASSIGN  */
  YYSYMBOL_INT = 6,                        /* INT  */
  YYSYMBOL_FLOAT = 7,                      /* FLOAT  */
  YYSYMBOL_EMPTY = 8,                      /* EMPTY  */
  YYSYMBOL_STR = 9,                        /* STR  */
  YYSYMBOL_T_INT = 10,                     /* T_INT  */
  YYSYMBOL_T_FLOAT = 11,                   /* T_FLOAT  */
  YYSYMBOL_T_ELEM = 12,                    /* T_ELEM  */
  YYSYMBOL_T_SET = 13,                     /* T_SET  */
  YYSYMBOL_ADD_OP = 14,                    /* ADD_OP  */
  YYSYMBOL_SUB_OP = 15,                    /* SUB_OP  */
  YYSYMBOL_MULT_OP = 16,                   /* MULT_OP  */
  YYSYMBOL_DIV_OP = 17,                    /* DIV_OP  */
  YYSYMBOL_ADD_SET_OP = 18,                /* ADD_SET_OP  */
  YYSYMBOL_REMOVE_SET_OP = 19,             /* REMOVE_SET_OP  */
  YYSYMBOL_EXISTS_IN_SET_OP = 20,          /* EXISTS_IN_SET_OP  */
  YYSYMBOL_IS_SET = 21,                    /* IS_SET  */
  YYSYMBOL_ADD_IN_OP = 22,                 /* ADD_IN_OP  */
  YYSYMBOL_ILT = 23,                       /* ILT  */
  YYSYMBOL_ILTE = 24,                      /* ILTE  */
  YYSYMBOL_IGT = 25,                       /* IGT  */
  YYSYMBOL_IGTE = 26,                      /* IGTE  */
  YYSYMBOL_IDIFF = 27,                     /* IDIFF  */
  YYSYMBOL_IEQ = 28,                       /* IEQ  */
  YYSYMBOL_AND = 29,                       /* AND  */
  YYSYMBOL_OR = 30,                        /* OR  */
  YYSYMBOL_NEG = 31,                       /* NEG  */
  YYSYMBOL_READ = 32,                      /* READ  */
  YYSYMBOL_WRITE = 33,                     /* WRITE  */
  YYSYMBOL_WRITELN = 34,                   /* WRITELN  */
  YYSYMBOL_RETURN = 35,                    /* RETURN  */
  YYSYMBOL_IF = 36,                        /* IF  */
  YYSYMBOL_ELSE = 37,                      /* ELSE  */
  YYSYMBOL_FOR = 38,                       /* FOR  */
  YYSYMBOL_SET_FORALL = 39,                /* SET_FORALL  */
  YYSYMBOL_40_ = 40,                       /* '('  */
  YYSYMBOL_41_ = 41,                       /* ')'  */
  YYSYMBOL_42_ = 42,                       /* ','  */
  YYSYMBOL_43_ = 43,                       /* '{'  */
  YYSYMBOL_44_ = 44,                       /* '}'  */
  YYSYMBOL_45_ = 45,                       /* ';'  */
  YYSYMBOL_YYACCEPT = 46,                  /* $accept  */
  YYSYMBOL_entryPoint = 47,                /* entryPoint  */
  YYSYMBOL_programEntries = 48,            /* programEntries  */
  YYSYMBOL_functionDefinition = 49,        /* functionDefinition  */
  YYSYMBOL_50_1 = 50,                      /* $@1  */
  YYSYMBOL_51_2 = 51,                      /* $@2  */
  YYSYMBOL_parameters = 52,                /* parameters  */
  YYSYMBOL_parameter = 53,                 /* parameter  */
  YYSYMBOL_compoundStatement = 54,         /* compoundStatement  */
  YYSYMBOL_declaration = 55,               /* declaration  */
  YYSYMBOL_statements = 56,                /* statements  */
  YYSYMBOL_statement = 57,                 /* statement  */
  YYSYMBOL_inOutStatement = 58,            /* inOutStatement  */
  YYSYMBOL_fluxControlstatement = 59,      /* fluxControlstatement  */
  YYSYMBOL_ifStart = 60,                   /* ifStart  */
  YYSYMBOL_iterationStatement = 61,        /* iterationStatement  */
  YYSYMBOL_62_3 = 62,                      /* $@3  */
  YYSYMBOL_63_4 = 63,                      /* $@4  */
  YYSYMBOL_expression = 64,                /* expression  */
  YYSYMBOL_comparationalExpression = 65,   /* comparationalExpression  */
  YYSYMBOL_logicalExpression = 66,         /* logicalExpression  */
  YYSYMBOL_arithmeticExpression = 67,      /* arithmeticExpression  */
  YYSYMBOL_arithmeticExpression2 = 68,     /* arithmeticExpression2  */
  YYSYMBOL_unaryOperation = 69,            /* unaryOperation  */
  YYSYMBOL_setOperationalExpression = 70,  /* setOperationalExpression  */
  YYSYMBOL_setBody = 71,                   /* setBody  */
  YYSYMBOL_variableAssignment = 72,        /* variableAssignment  */
  YYSYMBOL_localStatetements = 73,         /* localStatetements  */
  YYSYMBOL_74_5 = 74,                      /* $@5  */
  YYSYMBOL_forIncrement = 75,              /* forIncrement  */
  YYSYMBOL_term = 76,                      /* term  */
  YYSYMBOL_functionCall = 77,              /* functionCall  */
  YYSYMBOL_functionArguments = 78,         /* functionArguments  */
  YYSYMBOL_callArguments = 79,             /* callArguments  */
  YYSYMBOL_variableInit = 80,              /* variableInit  */
  YYSYMBOL_variable = 81,                  /* variable  */
  YYSYMBOL_typeSpecifier = 82              /* typeSpecifier  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   354

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  92
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  185

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   294


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      40,    41,     2,     2,    42,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    45,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    43,     2,    44,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   114,   114,   120,   126,   127,   131,   132,   138,   138,
     165,   165,   192,   196,   200,   206,   229,   250,   260,   267,
     273,   280,   284,   290,   291,   292,   293,   294,   297,   303,
     310,   316,   323,   347,   365,   373,   380,   387,   397,   406,
     411,   414,   411,   422,   431,   432,   435,   442,   449,   454,
     459,   482,   505,   528,   551,   574,   597,   602,   620,   638,
     641,   659,   677,   680,   685,   690,   695,   700,   705,   712,
     719,   728,   752,   752,   763,   770,   774,   778,   782,   783,
     788,   793,   800,   823,   824,   830,   851,   873,   885,   904,
     909,   914,   919
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "MAIN_FUNC", "ASSIGN", "INT", "FLOAT", "EMPTY", "STR", "T_INT",
  "T_FLOAT", "T_ELEM", "T_SET", "ADD_OP", "SUB_OP", "MULT_OP", "DIV_OP",
  "ADD_SET_OP", "REMOVE_SET_OP", "EXISTS_IN_SET_OP", "IS_SET", "ADD_IN_OP",
  "ILT", "ILTE", "IGT", "IGTE", "IDIFF", "IEQ", "AND", "OR", "NEG", "READ",
  "WRITE", "WRITELN", "RETURN", "IF", "ELSE", "FOR", "SET_FORALL", "'('",
  "')'", "','", "'{'", "'}'", "';'", "$accept", "entryPoint",
  "programEntries", "functionDefinition", "$@1", "$@2", "parameters",
  "parameter", "compoundStatement", "declaration", "statements",
  "statement", "inOutStatement", "fluxControlstatement", "ifStart",
  "iterationStatement", "$@3", "$@4", "expression",
  "comparationalExpression", "logicalExpression", "arithmeticExpression",
  "arithmeticExpression2", "unaryOperation", "setOperationalExpression",
  "setBody", "variableAssignment", "localStatetements", "$@5",
  "forIncrement", "term", "functionCall", "functionArguments",
  "callArguments", "variableInit", "variable", "typeSpecifier", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
      40,    41,    44,   123,   125,    59
};
#endif

#define YYPACT_NINF (-110)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-22)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     111,  -110,  -110,  -110,  -110,  -110,    21,   147,  -110,  -110,
      44,  -110,  -110,  -110,   -29,  -110,  -110,    30,    34,    50,
      50,  -110,    16,  -110,    74,    40,    53,   147,  -110,    53,
    -110,  -110,    95,  -110,    96,  -110,  -110,   135,  -110,    98,
       2,  -110,  -110,  -110,   314,    78,    80,    93,    97,   291,
     125,   136,   148,    19,  -110,   150,   151,   239,  -110,  -110,
    -110,  -110,  -110,   156,  -110,  -110,    26,   121,   137,   109,
    -110,  -110,  -110,  -110,  -110,  -110,  -110,   -29,   265,   239,
     157,  -110,   239,   239,   239,   314,   121,   169,    63,   110,
    -110,    49,   265,   314,    -6,  -110,   239,   291,   291,  -110,
     291,   291,   291,   291,   291,   291,   291,   291,   291,   291,
    -110,   132,   146,   158,    14,   160,   161,   162,   163,  -110,
     170,   181,   182,   183,   184,  -110,  -110,   176,  -110,    96,
       0,   121,   121,   137,   137,   137,   137,   137,   137,   109,
     109,  -110,  -110,  -110,   239,    66,  -110,  -110,  -110,  -110,
     154,   185,   190,   191,   192,   265,   239,   174,   213,   132,
    -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,    59,  -110,
     265,  -110,   178,   223,   186,  -110,   186,   222,   197,  -110,
    -110,   291,   186,   137,  -110
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     7,    89,    90,    91,    92,     0,     2,     6,     4,
       0,     1,     5,     3,     8,    10,    87,     0,     0,     0,
       0,    14,     0,    12,     0,     0,     0,     0,    16,     0,
      19,     9,     0,    11,     0,    15,    22,     0,    18,     0,
      88,    81,    80,    79,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    39,     0,     0,     0,    72,    17,
      20,    24,    25,     0,    26,    23,     0,    49,    56,    59,
      62,    77,    45,    27,    64,    78,    76,     0,     0,    84,
      88,    63,     0,     0,     0,     0,    48,     0,     0,     0,
      34,     0,     0,     0,     0,    19,     0,     0,     0,    44,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      71,    86,     0,    83,     0,     0,     0,     0,     0,    88,
       0,     0,     0,     0,     0,    33,    40,     0,    75,     0,
       0,    46,    47,    50,    51,    52,    53,    54,    55,    57,
      58,    60,    61,    82,     0,     0,    65,    66,    67,    68,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    85,
      69,    70,    32,    28,    29,    30,    31,    41,     0,    73,
       0,    35,    37,     0,     0,    36,     0,     0,     0,    43,
      38,     0,     0,    74,    42
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -110,  -110,  -110,   232,  -110,  -110,   220,  -110,   212,   155,
     114,  -110,  -110,  -110,  -110,  -110,  -110,  -110,   -75,   -51,
     -45,   -91,    57,    75,   104,   102,  -110,  -109,  -110,  -110,
     -39,  -110,  -110,  -110,    68,   -69,   -19
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     6,     7,     8,    17,    18,    22,    23,    31,    34,
      37,    60,    61,    62,    63,    64,   155,   173,    65,    66,
      67,    68,    69,    70,    71,   115,    72,    73,    95,   178,
      74,    75,   112,   113,    38,    76,    10
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      24,    24,    91,   110,    86,    81,    94,    78,    32,   133,
     134,   135,   136,   137,   138,    39,    16,   126,   120,   122,
     124,    11,    80,    97,    98,    41,    42,    43,   111,    97,
      98,   114,   114,   114,    44,   128,   145,    45,    46,    47,
      48,   158,    79,    97,    98,   130,   118,    14,    15,   172,
      49,    21,   131,   132,   127,    97,    98,    26,    27,    57,
       2,     3,     4,     5,    90,   179,   119,   180,     9,   119,
      19,    99,   121,   184,    20,    13,   161,    28,    97,    98,
     167,    29,    27,   171,    45,    46,    47,    48,    97,    98,
     183,   -13,   -13,   159,   125,   175,    30,    36,    35,   -21,
     174,    77,   -21,   -21,   -21,   168,     2,     3,     4,     5,
      39,   -21,     1,   119,   -21,   -21,   -21,   -21,    82,   123,
      83,     2,     3,     4,     5,   108,   109,   -21,   -21,   -21,
     -21,   -21,   -21,    84,   -21,   -21,   -21,    85,    40,   -21,
     -21,    41,    42,    43,   100,   101,   102,   103,   104,   105,
      44,   106,   107,    45,    46,    47,    48,     2,     3,     4,
       5,    97,    98,   139,   140,    87,    49,    50,    51,    52,
      53,    54,   119,    55,    56,    57,    88,    40,    58,    59,
      41,    42,    43,   141,   142,   116,   117,   143,    89,    44,
      92,    93,    45,    46,    47,    48,    96,    79,   156,   162,
     144,   146,   147,   148,   149,    49,    50,    51,    52,    53,
      54,   150,    55,    56,    57,   176,    40,    58,   169,    41,
      42,    43,   151,   152,   153,   154,   177,   181,    44,    58,
     163,    45,    46,    47,    48,   164,   165,   166,   182,    12,
      25,    33,    80,   157,    49,    41,    42,    43,   170,   160,
     129,     0,     0,    57,    44,     0,    58,    45,    46,    47,
      48,     0,     0,     0,     0,     0,     0,     0,    40,     0,
      49,    41,    42,    43,     0,     0,     0,     0,     0,    57,
      44,     0,     0,    45,    46,    47,    48,     0,     0,     0,
       0,     0,     0,     0,    80,     0,    49,    41,    42,    43,
       0,     0,     0,     0,     0,    57,    44,     0,     0,    45,
      46,    47,    48,     0,     0,     0,     0,    80,     0,     0,
      41,    42,    43,     0,     0,     0,     0,     0,     0,     0,
       0,    57,    45,    46,    47,    48,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    57
};

static const yytype_int16 yycheck[] =
{
      19,    20,    53,    78,    49,    44,    57,     5,    27,   100,
     101,   102,   103,   104,   105,    34,    45,    92,    87,    88,
      89,     0,     3,    29,    30,     6,     7,     8,    79,    29,
      30,    82,    83,    84,    15,    41,    22,    18,    19,    20,
      21,    41,    40,    29,    30,    96,    85,     3,     4,   158,
      31,     1,    97,    98,    93,    29,    30,    41,    42,    40,
      10,    11,    12,    13,    45,   174,     3,   176,     0,     3,
      40,    45,     9,   182,    40,     7,   145,     3,    29,    30,
     155,    41,    42,   158,    18,    19,    20,    21,    29,    30,
     181,    41,    42,   144,    45,   170,    43,     1,     3,     3,
      41,     3,     6,     7,     8,   156,    10,    11,    12,    13,
     129,    15,     1,     3,    18,    19,    20,    21,    40,     9,
      40,    10,    11,    12,    13,    16,    17,    31,    32,    33,
      34,    35,    36,    40,    38,    39,    40,    40,     3,    43,
      44,     6,     7,     8,    23,    24,    25,    26,    27,    28,
      15,    14,    15,    18,    19,    20,    21,    10,    11,    12,
      13,    29,    30,   106,   107,    40,    31,    32,    33,    34,
      35,    36,     3,    38,    39,    40,    40,     3,    43,    44,
       6,     7,     8,   108,   109,    83,    84,    41,    40,    15,
      40,    40,    18,    19,    20,    21,    40,    40,    22,    45,
      42,    41,    41,    41,    41,    31,    32,    33,    34,    35,
      36,    41,    38,    39,    40,    37,     3,    43,    44,     6,
       7,     8,    41,    41,    41,    41,     3,     5,    15,    43,
      45,    18,    19,    20,    21,    45,    45,    45,    41,     7,
      20,    29,     3,   129,    31,     6,     7,     8,    35,   145,
      95,    -1,    -1,    40,    15,    -1,    43,    18,    19,    20,
      21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,
      31,     6,     7,     8,    -1,    -1,    -1,    -1,    -1,    40,
      15,    -1,    -1,    18,    19,    20,    21,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,    -1,    31,     6,     7,     8,
      -1,    -1,    -1,    -1,    -1,    40,    15,    -1,    -1,    18,
      19,    20,    21,    -1,    -1,    -1,    -1,     3,    -1,    -1,
       6,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    40,    18,    19,    20,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    40
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,    10,    11,    12,    13,    47,    48,    49,    80,
      82,     0,    49,    80,     3,     4,    45,    50,    51,    40,
      40,     1,    52,    53,    82,    52,    41,    42,     3,    41,
      43,    54,    82,    54,    55,     3,     1,    56,    80,    82,
       3,     6,     7,     8,    15,    18,    19,    20,    21,    31,
      32,    33,    34,    35,    36,    38,    39,    40,    43,    44,
      57,    58,    59,    60,    61,    64,    65,    66,    67,    68,
      69,    70,    72,    73,    76,    77,    81,     3,     5,    40,
       3,    76,    40,    40,    40,    40,    66,    40,    40,    40,
      45,    65,    40,    40,    65,    74,    40,    29,    30,    45,
      23,    24,    25,    26,    27,    28,    14,    15,    16,    17,
      64,    65,    78,    79,    65,    71,    71,    71,    76,     3,
      81,     9,    81,     9,    81,    45,    64,    76,    41,    55,
      65,    66,    66,    67,    67,    67,    67,    67,    67,    68,
      68,    69,    69,    41,    42,    22,    41,    41,    41,    41,
      41,    41,    41,    41,    41,    62,    22,    56,    41,    65,
      70,    81,    45,    45,    45,    45,    45,    64,    65,    44,
      35,    64,    73,    63,    41,    64,    37,     3,    75,    73,
      73,     5,    41,    67,    73
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    48,    48,    48,    48,    48,    50,    49,
      51,    49,    52,    52,    52,    53,    53,    54,    55,    55,
      56,    56,    56,    57,    57,    57,    57,    57,    58,    58,
      58,    58,    58,    59,    59,    59,    59,    59,    59,    60,
      62,    63,    61,    61,    64,    64,    65,    65,    65,    65,
      66,    66,    66,    66,    66,    66,    66,    67,    67,    67,
      68,    68,    68,    69,    69,    70,    70,    70,    70,    71,
      71,    72,    74,    73,    75,    76,    76,    76,    76,    76,
      76,    76,    77,    78,    78,    79,    79,    80,    81,    82,
      82,    82,    82
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     1,     1,     0,     7,
       0,     7,     1,     0,     1,     4,     2,     4,     2,     0,
       2,     0,     1,     1,     1,     1,     1,     1,     5,     5,
       5,     5,     5,     3,     2,     5,     6,     5,     7,     1,
       0,     0,     9,     7,     2,     1,     3,     3,     2,     1,
       3,     3,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     1,     2,     1,     4,     4,     4,     4,     3,
       3,     3,     0,     5,     3,     3,     1,     1,     1,     1,
       1,     1,     4,     1,     0,     3,     1,     3,     1,     1,
       1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YY_LOCATION_PRINT
#  if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#   define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

#  else
#   define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#  endif
# endif /* !defined YY_LOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
  YYLTYPE *yylloc;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* entryPoint: programEntries  */
#line 114 "compLex_syntatical.y"
                           {
  parser_ast = (yyvsp[0].node);
  print_parser_msg("Program entry point\n", DEBUG);
}
#line 1755 "compLex_syntatical.tab.c"
    break;

  case 3: /* programEntries: programEntries variableInit  */
#line 120 "compLex_syntatical.y"
                                            {
    astParam astP = {
      .leftBranch = (yyvsp[-1].node), .rightBranch = (yyvsp[0].node), .nodeType = enumLeftRightBranch, .astNodeClass="PROGRAM_ENTRIES VARIABLE_INIT"
    };
    (yyval.node) = add_ast_node(astP);
  }
#line 1766 "compLex_syntatical.tab.c"
    break;

  case 4: /* programEntries: variableInit  */
#line 126 "compLex_syntatical.y"
                 {(yyval.node)=(yyvsp[0].node);}
#line 1772 "compLex_syntatical.tab.c"
    break;

  case 5: /* programEntries: programEntries functionDefinition  */
#line 127 "compLex_syntatical.y"
                                      {
    astParam astP = { .leftBranch = (yyvsp[-1].node), .rightBranch = (yyvsp[0].node), .nodeType = enumLeftRightBranch, .astNodeClass="PROGRAM_ENTRIES FUNCTION_DEFINITION" };
    (yyval.node) = add_ast_node(astP);
  }
#line 1781 "compLex_syntatical.tab.c"
    break;

  case 6: /* programEntries: functionDefinition  */
#line 131 "compLex_syntatical.y"
                       {(yyval.node)=(yyvsp[0].node);}
#line 1787 "compLex_syntatical.tab.c"
    break;

  case 7: /* programEntries: error  */
#line 132 "compLex_syntatical.y"
          {
      astParam astP = { .type = "ERROR", .value = "ERROR", .nodeType = enumValueTypeOnly, .astNodeClass="ERROR" };
      (yyval.node) = add_ast_node(astP);
  }
#line 1796 "compLex_syntatical.tab.c"
    break;

  case 8: /* $@1: %empty  */
#line 138 "compLex_syntatical.y"
                                             {
    currentTempReg = 0;
    currentParamsReg = 0;
    symbolParam symbol = { .symbolID = globalCounterOfSymbols, .symbolType=enumFunction, .type = (yyvsp[-1].node)->value, .name = (yyvsp[0].str), .line = running_line_count, .column = running_column_count };
    add_symbol_node(symbol);
    globalCounterOfSymbols++;
    scopeInfo current_scope = get_current_scope();
    currentFunction.scopeID = current_scope.scopeID;
    currentFunction.name = (yyvsp[0].str);
    currentFunction.lastParamPosition = 0;
    return_statement_type = strdup((yyvsp[-1].node)->type);
    insertTACLabel((yyvsp[0].str));
  }
#line 1814 "compLex_syntatical.tab.c"
    break;

  case 9: /* functionDefinition: typeSpecifier IDENTIFIER $@1 '(' parameters ')' compoundStatement  */
#line 150 "compLex_syntatical.y"
                                         {
    create_new_scope_level();
    astParam astP = {
      .leftBranch = (yyvsp[-6].node), .middle1Branch = (yyvsp[-2].node), .rightBranch = (yyvsp[0].node), .type= "IDENTIFIER", .value=(yyvsp[-5].str), .nodeType = enumLeftRightMiddleBranch, .astNodeClass="FUNCTION_DEFINITION" 
    };
    if (currentReturnLine != -1) {
      verify_return_statement((yyvsp[-5].str), found_return_statement, return_statement_type, returned_node, currentReturnScope, currentReturnLine);
    } else {
      verify_return_statement((yyvsp[-5].str), found_return_statement, return_statement_type, returned_node, currentReturnScope, running_line_count);
    }
    currentReturnLine = -1;
    found_return_statement = 0;
    (yyval.node) = add_ast_node(astP);
    print_parser_msg("Function definition \n", DEBUG);
  }
#line 1834 "compLex_syntatical.tab.c"
    break;

  case 10: /* $@2: %empty  */
#line 165 "compLex_syntatical.y"
                            {
      symbolParam symbol = { .symbolID = globalCounterOfSymbols, .symbolType=enumFunction, .type = (yyvsp[-1].node)->value, .name = (yyvsp[0].str), .line = running_line_count, .column = running_column_count};
      add_symbol_node(symbol);
      globalCounterOfSymbols++;
      scopeInfo current_scope = get_current_scope();
      currentFunction.scopeID = current_scope.scopeID;
      currentFunction.name = (yyvsp[0].str);
      currentFunction.lastParamPosition = 0;
      return_statement_type = strdup((yyvsp[-1].node)->type);
      insertTACLabel("fmain");
  }
#line 1850 "compLex_syntatical.tab.c"
    break;

  case 11: /* functionDefinition: typeSpecifier MAIN_FUNC $@2 '(' parameters ')' compoundStatement  */
#line 175 "compLex_syntatical.y"
                                         {
    create_new_scope_level();
    astParam astP = { 
      .leftBranch = (yyvsp[-6].node), .middle1Branch = (yyvsp[-2].node), .rightBranch = (yyvsp[0].node), .type= "MAIN", .value=(yyvsp[-5].str), .nodeType = enumLeftRightMiddleBranch, .astNodeClass="FUNCTION_DEFINITION" 
    };
    (yyval.node) = add_ast_node(astP);
    if (currentReturnLine != -1) {
      verify_return_statement((yyvsp[-5].str), found_return_statement, return_statement_type, returned_node, currentReturnScope, currentReturnLine);
    } else {
      verify_return_statement((yyvsp[-5].str), found_return_statement, return_statement_type, returned_node, currentReturnScope, running_line_count);
    }
    found_return_statement = 0;
    currentReturnLine = -1;
    print_parser_msg("Main function definition \n", DEBUG);
  }
#line 1870 "compLex_syntatical.tab.c"
    break;

  case 12: /* parameters: parameter  */
#line 192 "compLex_syntatical.y"
                      {
    (yyval.node) = (yyvsp[0].node);
    print_parser_msg("Parameter\n", DEBUG);
  }
#line 1879 "compLex_syntatical.tab.c"
    break;

  case 13: /* parameters: %empty  */
#line 196 "compLex_syntatical.y"
           {
    (yyval.node) = NULL;
    print_parser_msg("Empty parameters\n", DEBUG);
  }
#line 1888 "compLex_syntatical.tab.c"
    break;

  case 14: /* parameters: error  */
#line 200 "compLex_syntatical.y"
          {
    astParam astP = { .type = "ERROR", .value = "ERROR", .nodeType = enumValueTypeOnly, .astNodeClass="ERROR" };
    (yyval.node) = add_ast_node(astP);
  }
#line 1897 "compLex_syntatical.tab.c"
    break;

  case 15: /* parameter: parameters ',' typeSpecifier IDENTIFIER  */
#line 206 "compLex_syntatical.y"
                                                   {
    astParam astP = {
      .leftBranch = (yyvsp[-3].node), .rightBranch = (yyvsp[-1].node), .nodeType = enumLeftRightBranch, .astNodeClass="PARAMETER PARAMETERS TYPE_SPECIFIER"
    };
    (yyval.node) = add_ast_node(astP);
    astParam astP2 = {
      .leftBranch = (yyvsp[-3].node), .rightBranch = (yyvsp[-1].node), .type=(yyval.node)->rightBranch->value, .value = (yyvsp[0].str), .nodeType = enumLeftRightValueBranch, .astNodeClass="PARAMETER PARAMETERS TYPE_SPECIFIER"
    };
    (yyval.node) = add_ast_node(astP2);
    scopeInfo current_scope = get_current_scope();
    int foundSymbol = get_symbolID_by_name_and_current_scope("main", current_scope.scopeID, current_scope.level);
    if (foundSymbol == -1) { /* not main */
      char* tacName = set_param((yyval.node), &currentParamsReg);
      symbolParam symbol = { .symbolID = globalCounterOfSymbols, .symbolType=enumParameter, .type = (yyval.node)->rightBranch->value, .name = (yyvsp[0].str), .line= running_line_count, .tacName=tacName, .column= running_column_count, .associated_function=currentFunction.name, .last_param=currentFunction.lastParamPosition, .associated_function_scope=currentFunction.scopeID};
      add_symbol_node(symbol);
    } else {
      symbolParam symbol = { .symbolID = globalCounterOfSymbols, .symbolType=enumParameter, .type = (yyval.node)->rightBranch->value, .name = (yyvsp[0].str), .line= running_line_count, .column= running_column_count, .associated_function=currentFunction.name, .last_param=currentFunction.lastParamPosition, .associated_function_scope=currentFunction.scopeID};
      add_symbol_node(symbol);
    }
    currentFunction.lastParamPosition = currentFunction.lastParamPosition + 1;
    globalCounterOfSymbols++;
    print_parser_msg("Parameter, type and identifier\n", DEBUG);
  }
#line 1925 "compLex_syntatical.tab.c"
    break;

  case 16: /* parameter: typeSpecifier IDENTIFIER  */
#line 229 "compLex_syntatical.y"
                             {
    astParam astP = { .leftBranch = (yyvsp[-1].node), .type=(yyvsp[0].str), .value = (yyvsp[0].str), .nodeType = enumValueLeftBranch, .astNodeClass="PARAMETER TYPE_SPECIFIER IDENTIFIER" };
    (yyval.node) = add_ast_node(astP);
    astParam astP2 = { .leftBranch = (yyvsp[-1].node), .type=(yyval.node)->leftBranch->value, .value = (yyvsp[0].str), .nodeType = enumValueLeftBranch, .astNodeClass="PARAMETER TYPE_SPECIFIER IDENTIFIER" };
    (yyval.node) = add_ast_node(astP2);
    scopeInfo current_scope = get_current_scope();
    int foundSymbol = get_symbolID_by_name_and_current_scope("main", current_scope.scopeID, current_scope.level);
    if (foundSymbol == -1) { /* not main */
      char* tacName = set_param((yyval.node), &currentParamsReg);
      symbolParam symbol = { .symbolID = globalCounterOfSymbols, .symbolType=enumParameter, .type = (yyval.node)->leftBranch->value, .name = (yyvsp[0].str), .line= running_line_count, .tacName=tacName, .column= running_column_count, .associated_function=currentFunction.name, .last_param=currentFunction.lastParamPosition, .associated_function_scope=currentFunction.scopeID};
      add_symbol_node(symbol);
    } else {
      symbolParam symbol = { .symbolID = globalCounterOfSymbols, .symbolType=enumParameter, .type = (yyval.node)->leftBranch->value, .name = (yyvsp[0].str), .line= running_line_count, .column= running_column_count, .associated_function=currentFunction.name, .last_param=currentFunction.lastParamPosition, .associated_function_scope=currentFunction.scopeID};
      add_symbol_node(symbol);
    }
    currentFunction.lastParamPosition = currentFunction.lastParamPosition + 1;
    globalCounterOfSymbols++;
    print_parser_msg("Parameter and identifier\n", DEBUG);
  }
#line 1949 "compLex_syntatical.tab.c"
    break;

  case 17: /* compoundStatement: '{' declaration statements '}'  */
#line 250 "compLex_syntatical.y"
                                                  {
  astParam astP = {
    .leftBranch = (yyvsp[-2].node), .rightBranch = (yyvsp[-1].node), .nodeType = enumLeftRightBranch, .astNodeClass="COMPOUND_STATEMENT"
  };
  (yyval.node) = add_ast_node(astP);
  decrease_scope_level();
  print_parser_msg("Compound statement\n", DEBUG);
}
#line 1962 "compLex_syntatical.tab.c"
    break;

  case 18: /* declaration: declaration variableInit  */
#line 260 "compLex_syntatical.y"
                                      {
    astParam astP = {
      .leftBranch = (yyvsp[-1].node), .rightBranch = (yyvsp[0].node), .nodeType = enumLeftRightBranch, .astNodeClass="DECLARATION"
    };
    (yyval.node) = add_ast_node(astP);
    print_parser_msg("Declaration\n", DEBUG);
  }
#line 1974 "compLex_syntatical.tab.c"
    break;

  case 19: /* declaration: %empty  */
#line 267 "compLex_syntatical.y"
           {
    (yyval.node) = NULL;
    print_parser_msg("Empty declaration\n", DEBUG);
  }
#line 1983 "compLex_syntatical.tab.c"
    break;

  case 20: /* statements: statements statement  */
#line 273 "compLex_syntatical.y"
                                 {
    astParam astP = {
      .leftBranch = (yyvsp[-1].node), .rightBranch = (yyvsp[0].node), .nodeType = enumLeftRightBranch, .astNodeClass="STATEMENTS"
    };
    (yyval.node) = add_ast_node(astP);
    print_parser_msg("Statements, statement\n", DEBUG);
  }
#line 1995 "compLex_syntatical.tab.c"
    break;

  case 21: /* statements: %empty  */
#line 280 "compLex_syntatical.y"
           {
    (yyval.node) = NULL;
    print_parser_msg("Empty statement\n", DEBUG);
  }
#line 2004 "compLex_syntatical.tab.c"
    break;

  case 22: /* statements: error  */
#line 284 "compLex_syntatical.y"
          {
    astParam astP = { .type = "ERROR", .value = "ERROR", .nodeType = enumValueTypeOnly, .astNodeClass="ERROR" };
    (yyval.node) = add_ast_node(astP);
  }
#line 2013 "compLex_syntatical.tab.c"
    break;

  case 23: /* statement: expression  */
#line 290 "compLex_syntatical.y"
                      {(yyval.node) = (yyvsp[0].node);}
#line 2019 "compLex_syntatical.tab.c"
    break;

  case 24: /* statement: inOutStatement  */
#line 291 "compLex_syntatical.y"
                   {(yyval.node) = (yyvsp[0].node);}
#line 2025 "compLex_syntatical.tab.c"
    break;

  case 25: /* statement: fluxControlstatement  */
#line 292 "compLex_syntatical.y"
                         {(yyval.node) = (yyvsp[0].node);}
#line 2031 "compLex_syntatical.tab.c"
    break;

  case 26: /* statement: iterationStatement  */
#line 293 "compLex_syntatical.y"
                       {(yyval.node) = (yyvsp[0].node);}
#line 2037 "compLex_syntatical.tab.c"
    break;

  case 27: /* statement: localStatetements  */
#line 294 "compLex_syntatical.y"
                      {(yyval.node) = (yyvsp[0].node);}
#line 2043 "compLex_syntatical.tab.c"
    break;

  case 28: /* inOutStatement: WRITE '(' STR ')' ';'  */
#line 297 "compLex_syntatical.y"
                                      {
    astParam astP = { .type = "WRITE", .value = (yyvsp[-2].str), .nodeType = enumValueTypeOnly, .astNodeClass="WRITE STRING" };
    (yyval.node) = add_ast_node(astP);
    add_string_to_TAC((yyvsp[-2].str), 0, &currentTempReg, &currentTableCounter);
    print_parser_msg("IO: write string\n", DEBUG);
  }
#line 2054 "compLex_syntatical.tab.c"
    break;

  case 29: /* inOutStatement: WRITE '(' variable ')' ';'  */
#line 303 "compLex_syntatical.y"
                               {
    astParam astP = { .leftBranch = (yyvsp[-2].node), .type=(yyvsp[-4].str), .value = (yyvsp[-4].str), .nodeType = enumValueLeftBranch, .astNodeClass="WRITE IDENTIFIER" };
    (yyval.node) = add_ast_node(astP);
    tacCodeValidationParams tacP = { .instruction = "print", .op1 = (yyvsp[-2].node), .lineType=enumOneOp};
    check_ops_and_add_TAC_line(tacP);
    print_parser_msg("IO: write identifier\n", DEBUG);
  }
#line 2066 "compLex_syntatical.tab.c"
    break;

  case 30: /* inOutStatement: WRITELN '(' STR ')' ';'  */
#line 310 "compLex_syntatical.y"
                            {
    astParam astP = { .type = "WRITELN", .value = (yyvsp[-2].str), .nodeType = enumValueTypeOnly, .astNodeClass="WRITELN STRING" };
    (yyval.node) = add_ast_node(astP);
    add_string_to_TAC((yyvsp[-2].str), 1, &currentTempReg, &currentTableCounter);
    print_parser_msg("IO: writeln string\n", DEBUG);
  }
#line 2077 "compLex_syntatical.tab.c"
    break;

  case 31: /* inOutStatement: WRITELN '(' variable ')' ';'  */
#line 316 "compLex_syntatical.y"
                                 {
    astParam astP = { .leftBranch = (yyvsp[-2].node), .type=(yyvsp[-4].str), .value = (yyvsp[-4].str), .nodeType = enumValueLeftBranch, .astNodeClass="WRITELN IDENTIFIER" };
    (yyval.node) = add_ast_node(astP);
    tacCodeValidationParams tacP = { .instruction = "println", .op1 = (yyvsp[-2].node), .lineType=enumOneOp};
    check_ops_and_add_TAC_line(tacP);
    print_parser_msg("IO: writeln identifier\n", DEBUG);
  }
#line 2089 "compLex_syntatical.tab.c"
    break;

  case 32: /* inOutStatement: READ '(' variable ')' ';'  */
#line 323 "compLex_syntatical.y"
                              {
    astParam astP = { .leftBranch = (yyvsp[-2].node), .type=(yyvsp[-4].str), .value = (yyvsp[-4].str), .nodeType = enumValueLeftBranch, .astNodeClass="IN_OUT_STATEMENT" };
    (yyval.node) = add_ast_node(astP);
    if ((yyvsp[-2].node)->value) {
      int *symbolkey, symbolID;
      struct symbolNode *symbol;
      scopeInfo current_scope = get_current_scope();
      symbolID = get_symbolID_by_name_and_current_scope((yyvsp[-2].node)->value, current_scope.scopeID, current_scope.level);
      if (symbolID != -1) {
        symbolkey = &symbolID;
        HASH_FIND_INT(symbolTable, symbolkey, symbol);
        if (strcmp(symbol->type, "int")==0) {
          tacCodeParam tacP = { .instruction = "scani", .op1 = (yyvsp[-2].node)->value, .lineType=enumOneOp};
          add_TAC_line(tacP);
        } else if (strcmp(symbol->type, "float")==0) {
          tacCodeParam tacP = { .instruction = "scanf", .op1 = (yyvsp[-2].node)->value, .lineType=enumOneOp};
          add_TAC_line(tacP);
        }
      }
    }
    print_parser_msg("IO: read identifier\n", DEBUG);
  }
#line 2116 "compLex_syntatical.tab.c"
    break;

  case 33: /* fluxControlstatement: RETURN comparationalExpression ';'  */
#line 347 "compLex_syntatical.y"
                                                         {
    astParam astP = { .leftBranch = (yyvsp[-1].node), .type="RETURN", .value = (yyvsp[-2].str), .nodeType = enumValueLeftBranch, .astNodeClass="FLUX_CONTROL_STATEMENT RETURN_EXP" };
    (yyval.node) = add_ast_node(astP);
    found_return_statement = 1;
    scopeInfo tmpScope = get_current_scope();
    currentReturnScope.level = tmpScope.level;
    currentReturnScope.scopeID = tmpScope.scopeID;
    currentReturnLine = running_line_count;
    if ((yyvsp[-1].node)->type) returned_node = (yyvsp[-1].node);
    if ((yyvsp[-1].node)->value) {
      tacCodeParam tacP = { .instruction = "return", .op1 = (yyvsp[-1].node)->value, .lineType=enumOneOp};
      add_TAC_line(tacP);
    } else if ((yyvsp[-1].node)->tempReg) {
      tacCodeParam tacP = { .instruction = "return", .op1 = (yyvsp[-1].node)->tempReg, .lineType=enumTwoOp};
      add_TAC_line(tacP);
    }
    print_parser_msg("return expression\n", DEBUG);
  }
#line 2139 "compLex_syntatical.tab.c"
    break;

  case 34: /* fluxControlstatement: RETURN ';'  */
#line 365 "compLex_syntatical.y"
               {
    astParam astP = { .type = "RETURN", .value = (yyvsp[-1].str), .nodeType = enumValueTypeOnly, .astNodeClass="FLUX_CONTROL_STATEMENT RETURN_NULL" };
    (yyval.node) = add_ast_node(astP);
    found_return_statement = 1;
    tacCodeParam tacP = { .instruction = "return", .lineType=enumNoOp};
    add_TAC_line(tacP);
    print_parser_msg("return null\n", DEBUG);
  }
#line 2152 "compLex_syntatical.tab.c"
    break;

  case 35: /* fluxControlstatement: ifStart '(' comparationalExpression ')' expression  */
#line 373 "compLex_syntatical.y"
                                                       {
    astParam astP = {
      .leftBranch = (yyvsp[-2].node), .rightBranch = (yyvsp[0].node), .nodeType = enumLeftRightBranch, .astNodeClass="FLUX_CONTROL_STATEMENT IF"
    };
    (yyval.node) = add_ast_node(astP);
    print_parser_msg("if statement\n", DEBUG);
  }
#line 2164 "compLex_syntatical.tab.c"
    break;

  case 36: /* fluxControlstatement: ifStart '(' comparationalExpression ')' RETURN expression  */
#line 380 "compLex_syntatical.y"
                                                              {
    astParam astP = {
      .leftBranch = (yyvsp[-3].node), .rightBranch = (yyvsp[0].node), .nodeType = enumLeftRightBranch, .astNodeClass="FLUX_CONTROL_STATEMENT IF_ONE_LINE RETURN"
    };
    (yyval.node) = add_ast_node(astP);
    print_parser_msg("if statement\n", DEBUG);
  }
#line 2176 "compLex_syntatical.tab.c"
    break;

  case 37: /* fluxControlstatement: ifStart '(' comparationalExpression ')' localStatetements  */
#line 387 "compLex_syntatical.y"
                                                              {
    astParam astP = {
      .leftBranch = (yyvsp[-2].node), .rightBranch = (yyvsp[0].node), .nodeType = enumLeftRightBranch, .astNodeClass="FLUX_CONTROL_STATEMENT IF_NO_ELSE"
    };
    (yyval.node) = add_ast_node(astP);
    if (STACK_TOP(codeStackHead)) {
      add_if_finish_to_TAC();
    }
    print_parser_msg("if statement\n", DEBUG);
  }
#line 2191 "compLex_syntatical.tab.c"
    break;

  case 38: /* fluxControlstatement: ifStart '(' comparationalExpression ')' localStatetements ELSE localStatetements  */
#line 397 "compLex_syntatical.y"
                                                                                      {
    astParam astP = {
      .leftBranch = (yyvsp[-4].node), .middle1Branch = (yyvsp[-2].node), .rightBranch = (yyvsp[0].node), .type= "IF/ELSE", .value="if", .nodeType = enumLeftRightMiddleBranch, .astNodeClass="FLUX_CONTROL_STATEMENT IF_ELSE" 
    };
    (yyval.node) = add_ast_node(astP);
    print_parser_msg("if/else statement\n", DEBUG);
  }
#line 2203 "compLex_syntatical.tab.c"
    break;

  case 39: /* ifStart: IF  */
#line 406 "compLex_syntatical.y"
            {
  add_for_or_if_entry_to_TAC("simpleIfStart", &currentForLoop);
}
#line 2211 "compLex_syntatical.tab.c"
    break;

  case 40: /* $@3: %empty  */
#line 411 "compLex_syntatical.y"
                                       {
      add_for_or_if_entry_to_TAC("forLoop", &currentForLoop);
      forIncrementCounter++; 
    }
#line 2220 "compLex_syntatical.tab.c"
    break;

  case 41: /* $@4: %empty  */
#line 414 "compLex_syntatical.y"
                 {;}
#line 2226 "compLex_syntatical.tab.c"
    break;

  case 42: /* iterationStatement: FOR '(' expression $@3 expression $@4 forIncrement ')' localStatetements  */
#line 414 "compLex_syntatical.y"
                                                        {
      astParam astP = {
        .leftBranch = (yyvsp[-6].node), .middle1Branch=(yyvsp[-4].node), .middle2Branch=(yyvsp[-2].node), .rightBranch = (yyvsp[0].node), .type= "FOR", .value=(yyvsp[-8].str), .nodeType = enumLeftRightMiddle1And2Branch, .astNodeClass="ITERATION_STATEMENT FOR_THREE_ARGUMENTS"
      };
      (yyval.node) = add_ast_node(astP);
      add_for_loop_closing_to_TAC("forLoop", &currentForLoop, &currentTempReg, (yyval.node)->middle1Branch, (yyval.node)->middle2Branch);
      print_parser_msg("for loop three arguments\n", DEBUG);
  }
#line 2239 "compLex_syntatical.tab.c"
    break;

  case 43: /* iterationStatement: SET_FORALL '(' term ADD_IN_OP comparationalExpression ')' localStatetements  */
#line 422 "compLex_syntatical.y"
                                                                                {
    astParam astP = {
      .leftBranch = (yyvsp[-4].node), .middle1Branch = (yyvsp[-2].node), .rightBranch = (yyvsp[0].node), .type="SET_FORALL", .value=(yyvsp[-6].str), .nodeType = enumLeftRightMiddleBranch, .astNodeClass="ITERATION_STATEMENT FORALL" 
    };
    (yyval.node) = add_ast_node(astP);
    print_parser_msg("set forall loop\n", DEBUG);
  }
#line 2251 "compLex_syntatical.tab.c"
    break;

  case 44: /* expression: comparationalExpression ';'  */
#line 431 "compLex_syntatical.y"
                                        {(yyval.node)=(yyvsp[-1].node);}
#line 2257 "compLex_syntatical.tab.c"
    break;

  case 45: /* expression: variableAssignment  */
#line 432 "compLex_syntatical.y"
                       {(yyval.node)=(yyvsp[0].node);}
#line 2263 "compLex_syntatical.tab.c"
    break;

  case 46: /* comparationalExpression: comparationalExpression AND logicalExpression  */
#line 435 "compLex_syntatical.y"
                                                                       {
    astParam astP = {
      .leftBranch = (yyvsp[-2].node), .rightBranch = (yyvsp[0].node), .nodeType = enumLeftRightBranch, .astNodeClass="LOGICAL_EXPRESSION LOGICAL_AND"
    };
    (yyval.node) = add_ast_node(astP);
    print_parser_msg("logical AND operation\n", DEBUG);
  }
#line 2275 "compLex_syntatical.tab.c"
    break;

  case 47: /* comparationalExpression: comparationalExpression OR logicalExpression  */
#line 442 "compLex_syntatical.y"
                                                 {
    astParam astP = {
      .leftBranch = (yyvsp[-2].node), .rightBranch = (yyvsp[0].node), .nodeType = enumLeftRightBranch, .astNodeClass="LOGICAL_EXPRESSION LOGICAL_OR"
    };
    (yyval.node) = add_ast_node(astP);
    print_parser_msg("logical OR operation\n", DEBUG);
  }
#line 2287 "compLex_syntatical.tab.c"
    break;

  case 48: /* comparationalExpression: NEG logicalExpression  */
#line 449 "compLex_syntatical.y"
                          {
    astParam astP = { .leftBranch = (yyvsp[0].node), .type="NEG", .value = (yyvsp[-1].str), .nodeType = enumValueLeftBranch, .astNodeClass="LOGICAL_EXPRESSION LOGICAL_NOT" };
    (yyval.node) = add_ast_node(astP);
    print_parser_msg("logical NOT operation\n", DEBUG);
  }
#line 2297 "compLex_syntatical.tab.c"
    break;

  case 49: /* comparationalExpression: logicalExpression  */
#line 454 "compLex_syntatical.y"
                      {
    (yyval.node) = (yyvsp[0].node);
  }
#line 2305 "compLex_syntatical.tab.c"
    break;

  case 50: /* logicalExpression: logicalExpression ILT arithmeticExpression  */
#line 459 "compLex_syntatical.y"
                                                              {
    astParam astP = {
      .leftBranch = (yyvsp[-2].node), .rightBranch = (yyvsp[0].node), .nodeType = enumLeftRightBranch, .astNodeClass="LOGICAL_EXPRESSION IS_LESS_THAN"
    };
    (yyval.node) = add_ast_node(astP);
    set_temporary_register((yyval.node), &currentTempReg);
    int symbolOK = 0;
    symbolOK = cast_operators((yyvsp[-2].node), (yyvsp[0].node), running_line_count);
    if (symbolOK == 0 && STACK_TOP(codeStackHead)) {
      UT_string *label;
      utstring_new(label);
      codeLabelStack *currentLoopLabel;
      currentLoopLabel = STACK_TOP(codeStackHead);
      utstring_printf(label, "%sFinish", currentLoopLabel->name);
      tacCodeValidationParams tacP = { .instruction = "slt", .dst= (yyval.node),.op1 = (yyvsp[-2].node), .op2=(yyvsp[0].node), .lineType=enumThreeOp};
      check_ops_and_add_TAC_line(tacP);
      tacCodeParam tacP1 = { .instruction = "brz", .op1 = utstring_body(label), (yyval.node)->tempReg, .lineType=enumTwoOp};
      add_TAC_line(tacP1);
      utstring_free(label);
    }
    if((yyvsp[-2].node)->type) (yyval.node)->type = strdup((yyvsp[-2].node)->type);
    print_parser_msg("is less than operation\n", DEBUG);
  }
#line 2333 "compLex_syntatical.tab.c"
    break;

  case 51: /* logicalExpression: logicalExpression ILTE arithmeticExpression  */
#line 482 "compLex_syntatical.y"
                                                {
    astParam astP = {
      .leftBranch = (yyvsp[-2].node), .rightBranch = (yyvsp[0].node), .nodeType = enumLeftRightBranch, .astNodeClass="LOGICAL_EXPRESSION IS_LESS_THAN_EQUAL"
    };
    (yyval.node) = add_ast_node(astP);
    set_temporary_register((yyval.node), &currentTempReg);
    int symbolOK = 0;
    symbolOK = cast_operators((yyvsp[-2].node), (yyvsp[0].node), running_line_count);
    if (symbolOK == 0 && STACK_TOP(codeStackHead)) {
      UT_string *label;
      utstring_new(label);
      codeLabelStack *currentLoopLabel;
      currentLoopLabel = STACK_TOP(codeStackHead);
      utstring_printf(label, "%sFinish", currentLoopLabel->name);
      tacCodeValidationParams tacP = { .instruction = "sleq", .dst= (yyval.node),.op1 = (yyvsp[-2].node), .op2=(yyvsp[0].node), .lineType=enumThreeOp};
      check_ops_and_add_TAC_line(tacP);
      tacCodeParam tacP1 = { .instruction = "brz", .op1 = utstring_body(label), (yyval.node)->tempReg, .lineType=enumTwoOp};
      add_TAC_line(tacP1);
      utstring_free(label);
    }
    if((yyvsp[-2].node)->type) (yyval.node)->type = strdup((yyvsp[-2].node)->type);
    print_parser_msg("is less or equal operation\n", DEBUG);
  }
#line 2361 "compLex_syntatical.tab.c"
    break;

  case 52: /* logicalExpression: logicalExpression IGT arithmeticExpression  */
#line 505 "compLex_syntatical.y"
                                               {
    astParam astP = {
      .leftBranch = (yyvsp[-2].node), .rightBranch = (yyvsp[0].node), .nodeType = enumLeftRightBranch, .astNodeClass="LOGICAL_EXPRESSION IS_GREATER_THAN"
    };
    (yyval.node) = add_ast_node(astP);
    set_temporary_register((yyval.node), &currentTempReg);
    int symbolOK = 0;
    symbolOK = cast_operators((yyvsp[-2].node), (yyvsp[0].node), running_line_count);
    if (symbolOK == 0 && STACK_TOP(codeStackHead)) {
      UT_string *label;
      utstring_new(label);
      codeLabelStack *currentLoopLabel;
      currentLoopLabel = STACK_TOP(codeStackHead);
      utstring_printf(label, "%sFinish", currentLoopLabel->name);
      tacCodeValidationParams tacP = { .instruction = "sleq", .dst= (yyval.node),.op1 = (yyvsp[-2].node), .op2=(yyvsp[0].node), .lineType=enumThreeOp};
      check_ops_and_add_TAC_line(tacP);
      tacCodeParam tacP1 = { .instruction = "brnz", .op1 = utstring_body(label), (yyval.node)->tempReg, .lineType=enumTwoOp};
      add_TAC_line(tacP1);
      utstring_free(label);
    }
    if((yyvsp[-2].node)->type) (yyval.node)->type = strdup((yyvsp[-2].node)->type);
    print_parser_msg("is greater than operation\n", DEBUG);
  }
#line 2389 "compLex_syntatical.tab.c"
    break;

  case 53: /* logicalExpression: logicalExpression IGTE arithmeticExpression  */
#line 528 "compLex_syntatical.y"
                                                {
    astParam astP = {
      .leftBranch = (yyvsp[-2].node), .rightBranch = (yyvsp[0].node), .nodeType = enumLeftRightBranch, .astNodeClass="LOGICAL_EXPRESSION IS_GREATER_THAN_EQUAL"
    };
    (yyval.node) = add_ast_node(astP);
    set_temporary_register((yyval.node), &currentTempReg);
    int symbolOK = 0;
    symbolOK = cast_operators((yyvsp[-2].node), (yyvsp[0].node), running_line_count);
    if (symbolOK == 0 && STACK_TOP(codeStackHead)) {
      UT_string *label;
      utstring_new(label);
      codeLabelStack *currentLoopLabel;
      currentLoopLabel = STACK_TOP(codeStackHead);
      utstring_printf(label, "%sFinish", currentLoopLabel->name);
      tacCodeValidationParams tacP = { .instruction = "slt", .dst= (yyval.node),.op1 = (yyvsp[-2].node), .op2=(yyvsp[0].node), .lineType=enumThreeOp};
      check_ops_and_add_TAC_line(tacP);
      tacCodeParam tacP1 = { .instruction = "brnz", .op1 = utstring_body(label), (yyval.node)->tempReg, .lineType=enumTwoOp};
      add_TAC_line(tacP1);
      utstring_free(label);
    }
    if((yyvsp[-2].node)->type) (yyval.node)->type = strdup((yyvsp[-2].node)->type);
    print_parser_msg("is greater than or equal operation\n", DEBUG);
  }
#line 2417 "compLex_syntatical.tab.c"
    break;

  case 54: /* logicalExpression: logicalExpression IDIFF arithmeticExpression  */
#line 551 "compLex_syntatical.y"
                                                 {
    astParam astP = {
      .leftBranch = (yyvsp[-2].node), .rightBranch = (yyvsp[0].node), .nodeType = enumLeftRightBranch, .astNodeClass="LOGICAL_EXPRESSION IS_DIFFERENT_THAN"
    };
    (yyval.node) = add_ast_node(astP);
    set_temporary_register((yyval.node), &currentTempReg);
    int symbolOK = 0;
    symbolOK = cast_operators((yyvsp[-2].node), (yyvsp[0].node), running_line_count);
    if (symbolOK == 0 && STACK_TOP(codeStackHead)) {
      UT_string *label;
      utstring_new(label);
      codeLabelStack *currentLoopLabel;
      currentLoopLabel = STACK_TOP(codeStackHead);
      utstring_printf(label, "%sFinish", currentLoopLabel->name);
      tacCodeValidationParams tacP = { .instruction = "seq", .dst= (yyval.node),.op1 = (yyvsp[-2].node), .op2=(yyvsp[0].node), .lineType=enumThreeOp};
      check_ops_and_add_TAC_line(tacP);
      tacCodeParam tacP1 = { .instruction = "brnz", .op1 = utstring_body(label), (yyval.node)->tempReg, .lineType=enumTwoOp};
      add_TAC_line(tacP1);
      utstring_free(label);
    }
    if((yyvsp[-2].node)->type) (yyval.node)->type = strdup((yyvsp[-2].node)->type);
    print_parser_msg("is different than operation\n", DEBUG);
  }
#line 2445 "compLex_syntatical.tab.c"
    break;

  case 55: /* logicalExpression: logicalExpression IEQ arithmeticExpression  */
#line 574 "compLex_syntatical.y"
                                               {
    astParam astP = {
      .leftBranch = (yyvsp[-2].node), .rightBranch = (yyvsp[0].node), .nodeType = enumLeftRightBranch, .astNodeClass="LOGICAL_EXPRESSION IS_EQUAL"
    };
    (yyval.node) = add_ast_node(astP);
    set_temporary_register((yyval.node), &currentTempReg);
    int symbolOK = 0;
    symbolOK = cast_operators((yyvsp[-2].node), (yyvsp[0].node), running_line_count);
    if (symbolOK == 0 && STACK_TOP(codeStackHead)) {
      UT_string *label;
      utstring_new(label);
      codeLabelStack *currentLoopLabel;
      currentLoopLabel = STACK_TOP(codeStackHead);
      utstring_printf(label, "%sFinish", currentLoopLabel->name);
      tacCodeValidationParams tacP = { .instruction = "seq", .dst= (yyval.node),.op1 = (yyvsp[-2].node), .op2=(yyvsp[0].node), .lineType=enumThreeOp};
      check_ops_and_add_TAC_line(tacP);
      tacCodeParam tacP1 = { .instruction = "brz", .op1 = utstring_body(label), (yyval.node)->tempReg, .lineType=enumTwoOp};
      add_TAC_line(tacP1);
      utstring_free(label);
    }
    if((yyvsp[-2].node)->type) (yyval.node)->type = strdup((yyvsp[-2].node)->type);
    print_parser_msg("is equal to operation\n", DEBUG);
  }
#line 2473 "compLex_syntatical.tab.c"
    break;

  case 56: /* logicalExpression: arithmeticExpression  */
#line 597 "compLex_syntatical.y"
                         {
    (yyval.node) = (yyvsp[0].node);
  }
#line 2481 "compLex_syntatical.tab.c"
    break;

  case 57: /* arithmeticExpression: arithmeticExpression ADD_OP arithmeticExpression2  */
#line 602 "compLex_syntatical.y"
                                                                        {
    astParam astP = {
      .leftBranch = (yyvsp[-2].node), .rightBranch = (yyvsp[0].node), .nodeType = enumLeftRightBranch, .astNodeClass="ARITHMETIC_EXPRESSION ADD_OP"
    };
    (yyval.node) = add_ast_node(astP);
    set_temporary_register((yyval.node), &currentTempReg);
    int symbolOK = 0;
    symbolOK = cast_operators((yyvsp[-2].node), (yyvsp[0].node), running_line_count);
    if (symbolOK == 0 && forIncrementCounter == 0) {
      tacCodeValidationParams tacP = { .instruction = "add", .dst= (yyval.node),.op1 = (yyvsp[-2].node), .op2 = (yyvsp[0].node), .lineType=enumThreeOp};
      check_ops_and_add_TAC_line(tacP);
    }
    else if (symbolOK == 0 && forIncrementCounter > 0) {
      forIncrementCounter--;
    }
    if((yyvsp[-2].node)->type) (yyval.node)->type = strdup((yyvsp[-2].node)->type);
    print_parser_msg("add operation\n", DEBUG);
  }
#line 2504 "compLex_syntatical.tab.c"
    break;

  case 58: /* arithmeticExpression: arithmeticExpression SUB_OP arithmeticExpression2  */
#line 620 "compLex_syntatical.y"
                                                      {
    astParam astP = {
      .leftBranch = (yyvsp[-2].node), .rightBranch = (yyvsp[0].node), .nodeType = enumLeftRightBranch, .astNodeClass="ARITHMETIC_EXPRESSION SUB_OP"
    };
    (yyval.node) = add_ast_node(astP);
    set_temporary_register((yyval.node), &currentTempReg);
    int symbolOK = 0;
    symbolOK = cast_operators((yyvsp[-2].node), (yyvsp[0].node), running_line_count);
    if (symbolOK == 0 && forIncrementCounter == 0) {
      tacCodeValidationParams tacP = { .instruction = "sub", .dst= (yyval.node),.op1 = (yyvsp[-2].node), .op2 = (yyvsp[0].node), .lineType=enumThreeOp};
      check_ops_and_add_TAC_line(tacP);
    }
    else if (symbolOK == 0 && forIncrementCounter > 0) {
      forIncrementCounter--;
    }
    if((yyvsp[-2].node)->type) (yyval.node)->type = strdup((yyvsp[-2].node)->type);
    print_parser_msg("subtraction operation\n", DEBUG);
  }
#line 2527 "compLex_syntatical.tab.c"
    break;

  case 59: /* arithmeticExpression: arithmeticExpression2  */
#line 638 "compLex_syntatical.y"
                          {(yyval.node)=(yyvsp[0].node);}
#line 2533 "compLex_syntatical.tab.c"
    break;

  case 60: /* arithmeticExpression2: arithmeticExpression2 MULT_OP unaryOperation  */
#line 641 "compLex_syntatical.y"
                                                                    {
    astParam astP = {
      .leftBranch = (yyvsp[-2].node), .rightBranch = (yyvsp[0].node), .nodeType = enumLeftRightBranch, .astNodeClass="ARITHMETIC_EXPRESSION MULT_OP"
    };
    (yyval.node) = add_ast_node(astP);
    set_temporary_register((yyval.node), &currentTempReg);
    int symbolOK = 0;
    symbolOK = cast_operators((yyvsp[-2].node), (yyvsp[0].node), running_line_count);
    if (symbolOK == 0 && forIncrementCounter == 0) {
      tacCodeValidationParams tacP = { .instruction = "mul", .dst= (yyval.node),.op1 = (yyvsp[-2].node), .op2 = (yyvsp[0].node), .lineType=enumThreeOp};
      check_ops_and_add_TAC_line(tacP);
    }
    else if (symbolOK == 0 && forIncrementCounter > 0) {
      forIncrementCounter--;
    }
    if((yyvsp[-2].node)->type) (yyval.node)->type = strdup((yyvsp[-2].node)->type);
    print_parser_msg("multiplication operation\n", DEBUG);
  }
#line 2556 "compLex_syntatical.tab.c"
    break;

  case 61: /* arithmeticExpression2: arithmeticExpression2 DIV_OP unaryOperation  */
#line 659 "compLex_syntatical.y"
                                                {
    astParam astP = {
      .leftBranch = (yyvsp[-2].node), .rightBranch = (yyvsp[0].node), .nodeType = enumLeftRightBranch, .astNodeClass="ARITHMETIC_EXPRESSION DIV_OP"
    };
    (yyval.node) = add_ast_node(astP);
    set_temporary_register((yyval.node), &currentTempReg);
    int symbolOK = 0;
    symbolOK = cast_operators((yyvsp[-2].node), (yyvsp[0].node), running_line_count);
    if (symbolOK == 0 && forIncrementCounter == 0) {
      tacCodeValidationParams tacP = { .instruction = "div", .dst= (yyval.node),.op1 = (yyvsp[-2].node), .op2 = (yyvsp[0].node), .lineType=enumThreeOp};
      check_ops_and_add_TAC_line(tacP);
    }
    else if (symbolOK == 0 && forIncrementCounter > 0) {
      forIncrementCounter--;
    }
    if((yyvsp[-2].node)->type) (yyval.node)->type = strdup((yyvsp[-2].node)->type);
    print_parser_msg("division operation\n", DEBUG);
  }
#line 2579 "compLex_syntatical.tab.c"
    break;

  case 62: /* arithmeticExpression2: unaryOperation  */
#line 677 "compLex_syntatical.y"
                   {(yyval.node)=(yyvsp[0].node);}
#line 2585 "compLex_syntatical.tab.c"
    break;

  case 63: /* unaryOperation: SUB_OP term  */
#line 680 "compLex_syntatical.y"
                            {
    astParam astP = { .leftBranch = (yyvsp[0].node), .type="IDENTIFIER", .value = (yyvsp[0].node)->value, .nodeType = enumValueLeftBranch, .astNodeClass="SUB TERM" };
    (yyval.node) = add_ast_node(astP);
    print_parser_msg("is_set OP\n", DEBUG);
  }
#line 2595 "compLex_syntatical.tab.c"
    break;

  case 64: /* unaryOperation: term  */
#line 685 "compLex_syntatical.y"
         {
    (yyval.node) = (yyvsp[0].node);
  }
#line 2603 "compLex_syntatical.tab.c"
    break;

  case 65: /* setOperationalExpression: ADD_SET_OP '(' setBody ')'  */
#line 690 "compLex_syntatical.y"
                                                     {
    astParam astP = { .leftBranch = (yyvsp[-1].node), .type="IDENTIFIER", .value = (yyvsp[-3].str), .nodeType = enumValueLeftBranch, .astNodeClass="SET_OPERATION_EXPRESSION ADD_SET_OP" };
    (yyval.node) = add_ast_node(astP);
    print_parser_msg("add to set OP\n", DEBUG);
  }
#line 2613 "compLex_syntatical.tab.c"
    break;

  case 66: /* setOperationalExpression: REMOVE_SET_OP '(' setBody ')'  */
#line 695 "compLex_syntatical.y"
                                  {
    astParam astP = { .leftBranch = (yyvsp[-1].node), .type="IDENTIFIER", .value = (yyvsp[-3].str), .nodeType = enumValueLeftBranch, .astNodeClass="SET_OPERATION_EXPRESSION REMOVE_FROM_SET_OP" };
    (yyval.node) = add_ast_node(astP);
    print_parser_msg("remove from set OP\n", DEBUG);
  }
#line 2623 "compLex_syntatical.tab.c"
    break;

  case 67: /* setOperationalExpression: EXISTS_IN_SET_OP '(' setBody ')'  */
#line 700 "compLex_syntatical.y"
                                     {
    astParam astP = { .leftBranch = (yyvsp[-1].node), .type="IDENTIFIER", .value = (yyvsp[-3].str), .nodeType = enumValueLeftBranch, .astNodeClass="SET_OPERATION_EXPRESSION EXISTS_FROM_SET_OP" };
    (yyval.node) = add_ast_node(astP);
    print_parser_msg("exists el in set OP\n", DEBUG);
  }
#line 2633 "compLex_syntatical.tab.c"
    break;

  case 68: /* setOperationalExpression: IS_SET '(' term ')'  */
#line 705 "compLex_syntatical.y"
                        {
    astParam astP = { .leftBranch = (yyvsp[-1].node), .type="IDENTIFIER", .value = (yyvsp[-3].str), .nodeType = enumValueLeftBranch, .astNodeClass="SET_OPERATION_EXPRESSION IS_SET" };
    (yyval.node) = add_ast_node(astP);
    print_parser_msg("is_set OP\n", DEBUG);
  }
#line 2643 "compLex_syntatical.tab.c"
    break;

  case 69: /* setBody: comparationalExpression ADD_IN_OP setOperationalExpression  */
#line 712 "compLex_syntatical.y"
                                                                    {
    astParam astP = {
      .leftBranch = (yyvsp[-2].node), .rightBranch = (yyvsp[0].node), .nodeType = enumLeftRightBranch, .astNodeClass="SET_OPERATION_EXPRESSION_SET_BODY"
    };
    (yyval.node) = add_ast_node(astP);
    print_parser_msg("is_set body\n", DEBUG);
  }
#line 2655 "compLex_syntatical.tab.c"
    break;

  case 70: /* setBody: comparationalExpression ADD_IN_OP variable  */
#line 719 "compLex_syntatical.y"
                                               {
    astParam astP = {
      .leftBranch = (yyvsp[-2].node), .rightBranch = (yyvsp[0].node), .nodeType = enumLeftRightBranch, .astNodeClass="SET_OPERATION_EXPRESSION_SET_BODY"
    };
    (yyval.node) = add_ast_node(astP);
    print_parser_msg("is_set body\n", DEBUG);
  }
#line 2667 "compLex_syntatical.tab.c"
    break;

  case 71: /* variableAssignment: IDENTIFIER ASSIGN expression  */
#line 728 "compLex_syntatical.y"
                                                 {
    verify_declared_id((yyvsp[-2].str), running_line_count, running_column_count);
    astParam astP = { .leftBranch = (yyvsp[0].node), .type="IDENTIFIER", .value = (yyvsp[-2].str), .nodeType = enumValueLeftBranch, .astNodeClass="VARIABLE_ASSIGNMENT" };
    (yyval.node) = add_ast_node(astP);
    int symbolOK = 0;
    if (strcmp((yyval.node)->leftBranch->astNodeClass, "IDENTIFIER") == 0) {
      symbolOK = verify_declared_id((yyval.node)->leftBranch->value, running_line_count, running_column_count);
    }
    if (symbolOK == 0) {
      if ((yyvsp[0].node)->tempReg && (yyvsp[0].node)->value) {
        tacCodeParam tacP = { .instruction = "mov", .op1 = (yyvsp[-2].str), .op2 = (yyvsp[0].node)->tempReg, .lineType=enumTwoOp};
        add_TAC_line(tacP);
      } else if ((yyvsp[0].node)->value) {
        tacCodeParam tacP = { .instruction = "mov", .op1 = (yyvsp[-2].str), .op2 = (yyvsp[0].node)->value, .lineType=enumTwoOp};
        add_TAC_line(tacP);
      } else if ((yyvsp[0].node)->tempReg) {
        tacCodeParam tacP = { .instruction = "mov", .op1 = (yyvsp[-2].str), .op2 = (yyvsp[0].node)->tempReg, .lineType=enumTwoOp};
        add_TAC_line(tacP);
      }
    }
    print_parser_msg("variable assignment\n", DEBUG);
  }
#line 2694 "compLex_syntatical.tab.c"
    break;

  case 72: /* $@5: %empty  */
#line 752 "compLex_syntatical.y"
                       {create_new_scope_level();}
#line 2700 "compLex_syntatical.tab.c"
    break;

  case 73: /* localStatetements: '{' $@5 declaration statements '}'  */
#line 753 "compLex_syntatical.y"
                             {
  decrease_scope_level();
  astParam astP = {
    .leftBranch = (yyvsp[-2].node), .rightBranch = (yyvsp[-1].node), .nodeType = enumLeftRightBranch, .astNodeClass="LOCAL_STATEMENTS DECLARATION STATEMENTS"
  };
  (yyval.node) = add_ast_node(astP);
  print_parser_msg("local statetements\n", DEBUG);
}
#line 2713 "compLex_syntatical.tab.c"
    break;

  case 74: /* forIncrement: IDENTIFIER ASSIGN arithmeticExpression  */
#line 763 "compLex_syntatical.y"
                                                     {
  astParam astP = { .leftBranch = (yyvsp[0].node), .type="IDENTIFIER", .value = (yyvsp[-2].str), .nodeType = enumValueLeftBranch, .astNodeClass="FOR_INCREMENT" };
  (yyval.node) = add_ast_node(astP);
  print_parser_msg("for loop increment\n", DEBUG);
}
#line 2723 "compLex_syntatical.tab.c"
    break;

  case 75: /* term: '(' comparationalExpression ')'  */
#line 770 "compLex_syntatical.y"
                                      {
    (yyval.node)=(yyvsp[-1].node);
    print_parser_msg("( operationalExp )\n", DEBUG);
  }
#line 2732 "compLex_syntatical.tab.c"
    break;

  case 76: /* term: variable  */
#line 774 "compLex_syntatical.y"
             {
    (yyval.node)=(yyvsp[0].node);
    print_parser_msg("variable\n", DEBUG);
  }
#line 2741 "compLex_syntatical.tab.c"
    break;

  case 77: /* term: setOperationalExpression  */
#line 778 "compLex_syntatical.y"
                             {
    (yyval.node)=(yyvsp[0].node);
    print_parser_msg("set op\n", DEBUG);
  }
#line 2750 "compLex_syntatical.tab.c"
    break;

  case 78: /* term: functionCall  */
#line 782 "compLex_syntatical.y"
                 {(yyval.node)=(yyvsp[0].node);}
#line 2756 "compLex_syntatical.tab.c"
    break;

  case 79: /* term: EMPTY  */
#line 783 "compLex_syntatical.y"
          {
    astParam astP = { .type = "EMPTY", .value = (yyvsp[0].str), .nodeType = enumValueTypeOnly, .astNodeClass="TERM" };
    (yyval.node) = add_ast_node(astP);
    print_parser_msg("EMPTY constant value\n", DEBUG);
  }
#line 2766 "compLex_syntatical.tab.c"
    break;

  case 80: /* term: FLOAT  */
#line 788 "compLex_syntatical.y"
          {
    astParam astP = { .type = "FLOAT", .value = (yyvsp[0].str), .nodeType = enumValueTypeOnly, .astNodeClass="TERM" };
    (yyval.node) = add_ast_node(astP);
    print_parser_msg("float value\n", DEBUG);
  }
#line 2776 "compLex_syntatical.tab.c"
    break;

  case 81: /* term: INT  */
#line 793 "compLex_syntatical.y"
        {
    astParam astP = { .type = "INT", .value = (yyvsp[0].str), .nodeType = enumValueTypeOnly, .astNodeClass="TERM" };
    (yyval.node) = add_ast_node(astP);
    print_parser_msg("int value\n", DEBUG);
  }
#line 2786 "compLex_syntatical.tab.c"
    break;

  case 82: /* functionCall: IDENTIFIER '(' functionArguments ')'  */
#line 800 "compLex_syntatical.y"
                                                   {
  int symbolOK = verify_declared_id((yyvsp[-3].str), running_line_count, running_column_count);
  currentCalledFunction.name = (yyvsp[-3].str);
  astParam astP = { .leftBranch = (yyvsp[-1].node), .type="IDENTIFIER", .value = (yyvsp[-3].str), .nodeType = enumValueLeftBranch, .astNodeClass="FUNCTION_CALL" };
  (yyval.node) = add_ast_node(astP);
  if (symbolOK == 0) { /* symbol is declared */
    if (currentCalledFunction.amountOfParamsCalled == 0) {
      tacCodeParam tacP = { .instruction = "call", .op1 = (yyvsp[-3].str), .lineType=enumOneOp};
      add_TAC_line(tacP);
    } else {
      tacCodeParam tacP = { .instruction = "call", .op1 = (yyvsp[-3].str), .op2 = stringify_integer(currentCalledFunction.amountOfParamsCalled), .lineType=enumTwoOp};
      add_TAC_line(tacP);
    }
  }
  verify_func_call_params(currentCalledFunction.name, currentCalledFunction.amountOfParamsCalled, currentCalledFunction.passedParams, running_line_count);
  currentCalledFunction.amountOfParamsCalled = 0;
  set_temporary_register((yyval.node), &currentTempReg);
  tacCodeParam tacP = { .instruction = "pop", .op1 = (yyval.node)->tempReg, .lineType=enumOneOp};
  add_TAC_line(tacP);
  print_parser_msg("function call\n", DEBUG);
}
#line 2812 "compLex_syntatical.tab.c"
    break;

  case 83: /* functionArguments: callArguments  */
#line 823 "compLex_syntatical.y"
                                 {(yyval.node)=(yyvsp[0].node);}
#line 2818 "compLex_syntatical.tab.c"
    break;

  case 84: /* functionArguments: %empty  */
#line 824 "compLex_syntatical.y"
           {
    (yyval.node) = NULL;
    print_parser_msg("empty function argument\n", DEBUG);
  }
#line 2827 "compLex_syntatical.tab.c"
    break;

  case 85: /* callArguments: callArguments ',' comparationalExpression  */
#line 830 "compLex_syntatical.y"
                                                         {
    astParam astP = {
      .leftBranch = (yyvsp[-2].node), .rightBranch = (yyvsp[0].node), .nodeType = enumLeftRightBranch, .astNodeClass="CALL_ARGUMENTS MULTIPLE_ARGUMENTS"
    };
    (yyval.node) = add_ast_node(astP);
    if (strcmp((yyvsp[0].node)->astNodeClass,"IDENTIFIER") == 0) {
      scopeInfo current_scope = get_current_scope();
      int symbolID = get_symbolID((yyvsp[0].node)->value, current_scope.scopeID);
      currentCalledFunction.passedParams[currentCalledFunction.amountOfParamsCalled] = symbolID;
    } else if (strcmp((yyvsp[0].node)->astNodeClass,"TERM") == 0) {
      if (strcmp((yyvsp[0].node)->type,"INT") == 0) {
        currentCalledFunction.passedParams[currentCalledFunction.amountOfParamsCalled] = -1;
      } else if (strcmp((yyvsp[0].node)->type,"FLOAT") == 0) {
        currentCalledFunction.passedParams[currentCalledFunction.amountOfParamsCalled] = -2;
      }
    }
    tacCodeValidationParams tacP = { .instruction = "param", .op1 = (yyvsp[0].node), .lineType=enumOneOp};
    check_ops_and_add_TAC_line(tacP);
    currentCalledFunction.amountOfParamsCalled = currentCalledFunction.amountOfParamsCalled + 1;
    print_parser_msg("function callarguments, opExpression\n", DEBUG);
  }
#line 2853 "compLex_syntatical.tab.c"
    break;

  case 86: /* callArguments: comparationalExpression  */
#line 851 "compLex_syntatical.y"
                            {
    (yyval.node) = (yyvsp[0].node);
    if (strcmp((yyvsp[0].node)->astNodeClass,"IDENTIFIER") == 0) {
      scopeInfo current_scope = get_current_scope();
      int symbolID = get_symbolID((yyvsp[0].node)->value, current_scope.scopeID);
      currentCalledFunction.passedParams[currentCalledFunction.amountOfParamsCalled] = symbolID;
    } else if (strcmp((yyvsp[0].node)->astNodeClass,"TERM") == 0) {
      if (strcmp((yyvsp[0].node)->type,"INT") == 0) {
        currentCalledFunction.passedParams[currentCalledFunction.amountOfParamsCalled] = -1;
      } else if (strcmp((yyvsp[0].node)->type,"FLOAT") == 0) {
        currentCalledFunction.passedParams[currentCalledFunction.amountOfParamsCalled] = -2;
      }
    }
    tacCodeValidationParams tacP = { .instruction = "param", .op1 = (yyvsp[0].node), .lineType=enumOneOp};
    check_ops_and_add_TAC_line(tacP);

    currentCalledFunction.amountOfParamsCalled = currentCalledFunction.amountOfParamsCalled + 1;

    print_parser_msg("function callarguments\n", DEBUG);
  }
#line 2878 "compLex_syntatical.tab.c"
    break;

  case 87: /* variableInit: typeSpecifier IDENTIFIER ';'  */
#line 873 "compLex_syntatical.y"
                                           {
  astParam astP = { .leftBranch = (yyvsp[-2].node), .type="IDENTIFIER", .value = (yyvsp[-1].str), .nodeType = enumValueLeftBranch, .astNodeClass="VARIABLE_INIT" };
  (yyval.node) = add_ast_node(astP);
  astParam astP2 = { .leftBranch = (yyvsp[-2].node), .type=(yyval.node)->leftBranch->value, .value = (yyvsp[-1].str), .nodeType = enumValueLeftBranch, .astNodeClass="VARIABLE_INIT" };
  (yyval.node) = add_ast_node(astP2);
  symbolParam symbol = { .symbolID = globalCounterOfSymbols, .symbolType=enumVariable, .type = (yyval.node)->leftBranch->value, .name = (yyvsp[-1].str), .line= running_line_count, .column= running_column_count};
  add_symbol_node(symbol);
  globalCounterOfSymbols++;
  print_parser_msg("variable initialization\n", DEBUG);
}
#line 2893 "compLex_syntatical.tab.c"
    break;

  case 88: /* variable: IDENTIFIER  */
#line 885 "compLex_syntatical.y"
                     {
  astParam astP = { .type = "IDENTIFIER", .value = (yyvsp[0].str), .nodeType = enumValueTypeOnly, .astNodeClass="IDENTIFIER" };
  (yyval.node) = add_ast_node(astP);
  int symbolOK = verify_declared_id((yyvsp[0].str), running_line_count, running_column_count);
  if (symbolOK == 0) {
    int *symbolkey, symbolID;
    struct symbolNode *symbol;
    scopeInfo current_scope = get_current_scope();
    symbolID = get_symbolID_by_name_and_current_scope((yyvsp[0].str), current_scope.scopeID, current_scope.level);
    if (symbolID != -1) {
      symbolkey = &symbolID;
      HASH_FIND_INT(symbolTable, symbolkey, symbol);
      (yyval.node)->tempReg = symbol->tacName;
    }
  }
  print_parser_msg("variable\n", DEBUG);
}
#line 2915 "compLex_syntatical.tab.c"
    break;

  case 89: /* typeSpecifier: T_INT  */
#line 904 "compLex_syntatical.y"
                     {
    astParam astP = { .type = "T_INT", .value = (yyvsp[0].str), .nodeType = enumValueTypeOnly, .astNodeClass="TYPE_SPECIFIER" };
    (yyval.node) = add_ast_node(astP);
    print_parser_msg("integer type\n", DEBUG);
  }
#line 2925 "compLex_syntatical.tab.c"
    break;

  case 90: /* typeSpecifier: T_FLOAT  */
#line 909 "compLex_syntatical.y"
            {
    astParam astP = { .type = "T_FLOAT", .value = (yyvsp[0].str), .nodeType = enumValueTypeOnly, .astNodeClass="TYPE_SPECIFIER" };
    (yyval.node) = add_ast_node(astP);
    print_parser_msg("float type\n", DEBUG);
  }
#line 2935 "compLex_syntatical.tab.c"
    break;

  case 91: /* typeSpecifier: T_ELEM  */
#line 914 "compLex_syntatical.y"
           {
    astParam astP = { .type = "T_ELEM", .value = (yyvsp[0].str), .nodeType = enumValueTypeOnly, .astNodeClass="TYPE_SPECIFIER" };
    (yyval.node) = add_ast_node(astP);
    print_parser_msg("elem type\n", DEBUG);
  }
#line 2945 "compLex_syntatical.tab.c"
    break;

  case 92: /* typeSpecifier: T_SET  */
#line 919 "compLex_syntatical.y"
          {
    astParam astP = { .type = "T_SET", .value = (yyvsp[0].str), .nodeType = enumValueTypeOnly, .astNodeClass="TYPE_SPECIFIER" };
    (yyval.node) = add_ast_node(astP);
    print_parser_msg("set type\n", DEBUG);
  }
#line 2955 "compLex_syntatical.tab.c"
    break;


#line 2959 "compLex_syntatical.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken, &yylloc};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          goto yyexhaustedlab;
      }
    }

  yyerror_range[1] = yylloc;
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if 1
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 926 "compLex_syntatical.y"


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

  yylex_destroy();

  return 0;
}

void yyerror(const char* msg) {
  fprintf(stderr, "%s at line: %d, column: %d\n", msg, running_line_count, running_column_count);
}
