/* A Bison parser, made by GNU Bison 3.7.4.  */

/* Bison implementation for Yacc-like parsers in C

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
#define YYBISON 30704

/* Bison version string.  */
#define YYBISON_VERSION "3.7.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 3 "compLex_syntatical.y"


// Required libs declarations
#include <stdlib.h>
#include <stdio.h>

#include "symbol_table.h"

extern int yylex();
extern void yyerror(const char *msg);
extern int yylex_destroy();
extern FILE *yyin;

typedef struct parseNode {
  struct parseNode* rightBranch;
  struct parseNode* leftBranch;
  char* value;
  char* type;
} parseNode;

parseNode* parser_tree = NULL;

/* Global variables */
int globalCounterOfSymbols = 1;


#line 98 "compLex_syntatical.tab.c"

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
  YYSYMBOL_T_INT = 9,                      /* T_INT  */
  YYSYMBOL_T_FLOAT = 10,                   /* T_FLOAT  */
  YYSYMBOL_T_ELEM = 11,                    /* T_ELEM  */
  YYSYMBOL_T_SET = 12,                     /* T_SET  */
  YYSYMBOL_ADD_OP = 13,                    /* ADD_OP  */
  YYSYMBOL_SUB_OP = 14,                    /* SUB_OP  */
  YYSYMBOL_MULT_OP = 15,                   /* MULT_OP  */
  YYSYMBOL_DIV_OP = 16,                    /* DIV_OP  */
  YYSYMBOL_ADD_SET_OP = 17,                /* ADD_SET_OP  */
  YYSYMBOL_REMOVE_SET_OP = 18,             /* REMOVE_SET_OP  */
  YYSYMBOL_EXISTS_IN_SET_OP = 19,          /* EXISTS_IN_SET_OP  */
  YYSYMBOL_IS_SET = 20,                    /* IS_SET  */
  YYSYMBOL_ADD_IN_OP = 21,                 /* ADD_IN_OP  */
  YYSYMBOL_ILT = 22,                       /* ILT  */
  YYSYMBOL_ILTE = 23,                      /* ILTE  */
  YYSYMBOL_IGT = 24,                       /* IGT  */
  YYSYMBOL_IGTE = 25,                      /* IGTE  */
  YYSYMBOL_IDIFF = 26,                     /* IDIFF  */
  YYSYMBOL_IEQ = 27,                       /* IEQ  */
  YYSYMBOL_READ = 28,                      /* READ  */
  YYSYMBOL_WRITE = 29,                     /* WRITE  */
  YYSYMBOL_WRITELN = 30,                   /* WRITELN  */
  YYSYMBOL_RETURN = 31,                    /* RETURN  */
  YYSYMBOL_IF = 32,                        /* IF  */
  YYSYMBOL_ELSE = 33,                      /* ELSE  */
  YYSYMBOL_FOR = 34,                       /* FOR  */
  YYSYMBOL_SET_FORALL = 35,                /* SET_FORALL  */
  YYSYMBOL_36_ = 36,                       /* '('  */
  YYSYMBOL_37_ = 37,                       /* ')'  */
  YYSYMBOL_38_ = 38,                       /* ','  */
  YYSYMBOL_39_ = 39,                       /* '{'  */
  YYSYMBOL_40_ = 40,                       /* '}'  */
  YYSYMBOL_41_ = 41,                       /* ';'  */
  YYSYMBOL_YYACCEPT = 42,                  /* $accept  */
  YYSYMBOL_entryPoint = 43,                /* entryPoint  */
  YYSYMBOL_programEntries = 44,            /* programEntries  */
  YYSYMBOL_functionDefinition = 45,        /* functionDefinition  */
  YYSYMBOL_parameters = 46,                /* parameters  */
  YYSYMBOL_parameter = 47,                 /* parameter  */
  YYSYMBOL_compoundStatement = 48,         /* compoundStatement  */
  YYSYMBOL_declaration = 49,               /* declaration  */
  YYSYMBOL_statements = 50,                /* statements  */
  YYSYMBOL_statement = 51,                 /* statement  */
  YYSYMBOL_inOutStatement = 52,            /* inOutStatement  */
  YYSYMBOL_fluxControlstatement = 53,      /* fluxControlstatement  */
  YYSYMBOL_iterationStatement = 54,        /* iterationStatement  */
  YYSYMBOL_expression = 55,                /* expression  */
  YYSYMBOL_operationalExpression = 56,     /* operationalExpression  */
  YYSYMBOL_arithmeticExpression = 57,      /* arithmeticExpression  */
  YYSYMBOL_logicalExpression = 58,         /* logicalExpression  */
  YYSYMBOL_setOperationalExpression = 59,  /* setOperationalExpression  */
  YYSYMBOL_variableAssignment = 60,        /* variableAssignment  */
  YYSYMBOL_forIncrement = 61,              /* forIncrement  */
  YYSYMBOL_term = 62,                      /* term  */
  YYSYMBOL_functionCall = 63,              /* functionCall  */
  YYSYMBOL_functionArguments = 64,         /* functionArguments  */
  YYSYMBOL_callArguments = 65,             /* callArguments  */
  YYSYMBOL_variableInit = 66,              /* variableInit  */
  YYSYMBOL_variable = 67,                  /* variable  */
  YYSYMBOL_typeSpecifier = 68              /* typeSpecifier  */
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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   292

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  157

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   290


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
      36,    37,     2,     2,    38,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    41,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,     2,    40,     2,     2,     2,     2,
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
      35
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    64,    64,    67,    68,    69,    70,    73,    79,    87,
      88,    91,    92,    95,    98,    99,   102,   103,   106,   107,
     108,   109,   112,   113,   114,   117,   118,   119,   120,   123,
     124,   125,   128,   129,   132,   133,   134,   135,   138,   139,
     140,   141,   144,   145,   146,   147,   148,   149,   152,   153,
     154,   155,   158,   161,   164,   165,   166,   167,   168,   169,
     172,   175,   176,   179,   180,   183,   191,   194,   195,   196,
     197
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "MAIN_FUNC", "ASSIGN", "INT", "FLOAT", "EMPTY", "T_INT", "T_FLOAT",
  "T_ELEM", "T_SET", "ADD_OP", "SUB_OP", "MULT_OP", "DIV_OP", "ADD_SET_OP",
  "REMOVE_SET_OP", "EXISTS_IN_SET_OP", "IS_SET", "ADD_IN_OP", "ILT",
  "ILTE", "IGT", "IGTE", "IDIFF", "IEQ", "READ", "WRITE", "WRITELN",
  "RETURN", "IF", "ELSE", "FOR", "SET_FORALL", "'('", "')'", "','", "'{'",
  "'}'", "';'", "$accept", "entryPoint", "programEntries",
  "functionDefinition", "parameters", "parameter", "compoundStatement",
  "declaration", "statements", "statement", "inOutStatement",
  "fluxControlstatement", "iterationStatement", "expression",
  "operationalExpression", "arithmeticExpression", "logicalExpression",
  "setOperationalExpression", "variableAssignment", "forIncrement", "term",
  "functionCall", "functionArguments", "callArguments", "variableInit",
  "variable", "typeSpecifier", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,    40,    41,    44,   123,
     125,    59
};
#endif

#define YYPACT_NINF (-50)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-54)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      54,   -50,   -50,   -50,   -50,    11,    54,   -50,   -50,    34,
     -50,   -50,   -50,   -31,   -19,    54,   -50,    54,     3,   -50,
      24,    17,     4,    54,   -50,     4,   -50,   -50,    42,   -50,
      54,   -50,    50,   -50,    45,    -1,   -50,   -50,   -50,    14,
      25,    35,    40,    41,    55,    56,     6,    57,    59,    60,
      13,   -50,   -50,   -50,   -50,   -50,   -50,   126,   -50,   -50,
     -50,   -50,   -50,   -50,   -50,    10,    91,    13,     0,     0,
       0,     0,    98,    98,    98,   -50,   -50,    13,    91,     0,
      66,   146,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   -50,   -50,   265,    23,    65,    84,    86,    92,
      75,   -50,    77,    78,    79,   162,    91,   106,    96,   -50,
     -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,
     -50,    13,    13,    13,    13,   -50,    83,    93,    94,     4,
     115,     4,    13,   265,   178,   194,   210,   -50,   -50,   -50,
     103,   132,   101,   -50,   226,   -50,   -50,   -50,     4,    13,
       4,     4,   -50,   265,   107,   -50,   -50
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    67,    68,    69,    70,     0,     2,     6,     4,     0,
       1,     5,     3,     0,     0,    10,    65,    10,     0,     9,
       0,     0,     0,     0,    11,     0,    15,     7,     0,     8,
      17,    12,     0,    14,     0,    66,    59,    58,    57,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    13,    16,    19,    20,    21,    18,     0,    34,    35,
      36,    33,    37,    56,    55,     0,     0,    62,     0,     0,
       0,     0,     0,     0,     0,    26,    25,     0,     0,     0,
      66,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    32,    52,    64,     0,    61,     0,     0,     0,
       0,    66,     0,     0,     0,     0,     0,     0,     0,    54,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      60,     0,     0,     0,     0,    51,     0,     0,     0,     0,
       0,     0,     0,    63,     0,     0,     0,    24,    22,    23,
      27,     0,     0,    29,     0,    48,    49,    50,     0,     0,
       0,     0,    28,     0,    34,    30,    31
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -50,   -50,   -50,   139,   129,   -50,   -25,   -50,   -50,   -50,
     -50,   -50,   -50,   -44,   -49,     5,   -50,   -50,   -50,   -50,
     186,   -50,   -50,   -50,     9,    15,    29
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,     7,    18,    19,    27,    30,    32,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,   142,
      62,    63,    95,    96,     8,    64,     9
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      29,    81,    76,    80,    66,    15,    36,    37,    38,    35,
      16,    10,    36,    37,    38,    12,    80,    17,    94,    36,
      37,    38,    93,    39,    40,    41,    42,    24,   105,   107,
      39,    40,    41,    42,   106,    67,    50,    13,    14,    33,
      22,    23,    50,    26,    20,    31,    20,    75,    65,    50,
      68,    16,    28,    35,    25,    23,    36,    37,    38,    34,
     120,    69,   130,     1,     2,     3,     4,    39,    40,    41,
      42,    70,   133,   134,   135,   136,    71,    72,    43,    44,
      45,    46,    47,   144,    48,    49,    50,   102,   103,   104,
      51,    73,    74,    77,    35,    78,    79,    36,    37,    38,
     153,   101,    67,   121,   140,   122,   143,   123,    39,    40,
      41,    42,   125,   124,   126,   127,   128,   132,   141,    82,
      83,    84,    85,   152,   137,   155,   156,    50,    86,    87,
      88,    89,    90,    91,   138,   139,   148,   149,   150,    82,
      83,    84,    85,   131,   -53,    11,    21,    92,    86,    87,
      88,    89,    90,    91,   154,     0,     0,     0,     0,    82,
      83,    84,    85,     0,     0,     0,     0,    92,    86,    87,
      88,    89,    90,    91,     0,    82,    83,    84,    85,     0,
       0,     0,     0,   109,    86,    87,    88,    89,    90,    91,
       0,    82,    83,    84,    85,     0,     0,     0,     0,   129,
      86,    87,    88,    89,    90,    91,     0,    82,    83,    84,
      85,     0,     0,     0,     0,   145,    86,    87,    88,    89,
      90,    91,     0,    82,    83,    84,    85,     0,     0,     0,
       0,   146,    86,    87,    88,    89,    90,    91,     0,    82,
      83,    84,    85,     0,     0,     0,     0,   147,    86,    87,
      88,    89,    90,    91,    97,    98,    99,   100,     0,     0,
       0,     0,     0,   151,     0,   108,     0,     0,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,    82,    83,
      84,    85,     0,     0,     0,     0,     0,    86,    87,    88,
      89,    90,    91
};

static const yytype_int16 yycheck[] =
{
      25,    50,    46,     3,     5,    36,     6,     7,     8,     3,
      41,     0,     6,     7,     8,     6,     3,    36,    67,     6,
       7,     8,    66,    17,    18,    19,    20,     3,    77,    78,
      17,    18,    19,    20,    78,    36,    36,     3,     4,    30,
      37,    38,    36,    39,    15,     3,    17,    41,     3,    36,
      36,    41,    23,     3,    37,    38,     6,     7,     8,    30,
      37,    36,   106,     9,    10,    11,    12,    17,    18,    19,
      20,    36,   121,   122,   123,   124,    36,    36,    28,    29,
      30,    31,    32,   132,    34,    35,    36,    72,    73,    74,
      40,    36,    36,    36,     3,    36,    36,     6,     7,     8,
     149,     3,    36,    38,   129,    21,   131,    21,    17,    18,
      19,    20,    37,    21,    37,    37,    37,    21,     3,    13,
      14,    15,    16,   148,    41,   150,   151,    36,    22,    23,
      24,    25,    26,    27,    41,    41,    33,     5,    37,    13,
      14,    15,    16,    37,    37,     6,    17,    41,    22,    23,
      24,    25,    26,    27,   149,    -1,    -1,    -1,    -1,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    41,    22,    23,
      24,    25,    26,    27,    -1,    13,    14,    15,    16,    -1,
      -1,    -1,    -1,    37,    22,    23,    24,    25,    26,    27,
      -1,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    37,
      22,    23,    24,    25,    26,    27,    -1,    13,    14,    15,
      16,    -1,    -1,    -1,    -1,    37,    22,    23,    24,    25,
      26,    27,    -1,    13,    14,    15,    16,    -1,    -1,    -1,
      -1,    37,    22,    23,    24,    25,    26,    27,    -1,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    37,    22,    23,
      24,    25,    26,    27,    68,    69,    70,    71,    -1,    -1,
      -1,    -1,    -1,    37,    -1,    79,    -1,    -1,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    13,    14,
      15,    16,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,
      25,    26,    27
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     9,    10,    11,    12,    43,    44,    45,    66,    68,
       0,    45,    66,     3,     4,    36,    41,    36,    46,    47,
      68,    46,    37,    38,     3,    37,    39,    48,    68,    48,
      49,     3,    50,    66,    68,     3,     6,     7,     8,    17,
      18,    19,    20,    28,    29,    30,    31,    32,    34,    35,
      36,    40,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    62,    63,    67,     3,     5,    36,    36,    36,
      36,    36,    36,    36,    36,    41,    55,    36,    36,    36,
       3,    56,    13,    14,    15,    16,    22,    23,    24,    25,
      26,    27,    41,    55,    56,    64,    65,    62,    62,    62,
      62,     3,    67,    67,    67,    56,    55,    56,    62,    37,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      37,    38,    21,    21,    21,    37,    37,    37,    37,    37,
      55,    37,    21,    56,    56,    56,    56,    41,    41,    41,
      48,     3,    61,    48,    56,    37,    37,    37,    33,     5,
      37,    37,    48,    56,    57,    48,    48
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    44,    44,    44,    44,    45,    45,    46,
      46,    47,    47,    48,    49,    49,    50,    50,    51,    51,
      51,    51,    52,    52,    52,    53,    53,    53,    53,    54,
      54,    54,    55,    55,    56,    56,    56,    56,    57,    57,
      57,    57,    58,    58,    58,    58,    58,    58,    59,    59,
      59,    59,    60,    61,    62,    62,    62,    62,    62,    62,
      63,    64,    64,    65,    65,    66,    67,    68,    68,    68,
      68
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     1,     6,     6,     1,
       0,     2,     4,     4,     2,     0,     2,     0,     1,     1,
       1,     1,     5,     5,     5,     2,     2,     5,     7,     5,
       7,     7,     2,     1,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     6,     6,
       6,     4,     3,     3,     3,     1,     1,     1,     1,     1,
       4,     1,     0,     3,     1,     3,     1,     1,     1,     1,
       1
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
  YYUSE (yyoutput);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
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
#line 64 "compLex_syntatical.y"
                           { printf("Program entry point\n"); }
#line 1380 "compLex_syntatical.tab.c"
    break;

  case 3: /* programEntries: programEntries variableInit  */
#line 67 "compLex_syntatical.y"
                                            {;}
#line 1386 "compLex_syntatical.tab.c"
    break;

  case 4: /* programEntries: variableInit  */
#line 68 "compLex_syntatical.y"
                 {;}
#line 1392 "compLex_syntatical.tab.c"
    break;

  case 5: /* programEntries: programEntries functionDefinition  */
#line 69 "compLex_syntatical.y"
                                      {;}
#line 1398 "compLex_syntatical.tab.c"
    break;

  case 6: /* programEntries: functionDefinition  */
#line 70 "compLex_syntatical.y"
                       {;}
#line 1404 "compLex_syntatical.tab.c"
    break;

  case 7: /* functionDefinition: typeSpecifier IDENTIFIER '(' parameters ')' compoundStatement  */
#line 73 "compLex_syntatical.y"
                                                                                  {
  symbolParam symbol = { globalCounterOfSymbols, enumFunction, (yyvsp[-4].str) };
  add_symbol_node(symbol);
  globalCounterOfSymbols++;
  printf("function definition \n");
}
#line 1415 "compLex_syntatical.tab.c"
    break;

  case 8: /* functionDefinition: typeSpecifier MAIN_FUNC '(' parameters ')' compoundStatement  */
#line 79 "compLex_syntatical.y"
                                                                 {
      symbolParam symbol = { globalCounterOfSymbols, enumFunction, (yyvsp[-4].str) };
      add_symbol_node(symbol);
      globalCounterOfSymbols++;
      printf("main function definition \n");
    }
#line 1426 "compLex_syntatical.tab.c"
    break;

  case 9: /* parameters: parameter  */
#line 87 "compLex_syntatical.y"
                      {printf("parameter\n");}
#line 1432 "compLex_syntatical.tab.c"
    break;

  case 10: /* parameters: %empty  */
#line 88 "compLex_syntatical.y"
           {printf("empty parameters\n");}
#line 1438 "compLex_syntatical.tab.c"
    break;

  case 11: /* parameter: typeSpecifier IDENTIFIER  */
#line 91 "compLex_syntatical.y"
                                    {printf("parameter and identifier\n");}
#line 1444 "compLex_syntatical.tab.c"
    break;

  case 12: /* parameter: parameters ',' typeSpecifier IDENTIFIER  */
#line 92 "compLex_syntatical.y"
                                            {printf("parameter, type and identifier\n");}
#line 1450 "compLex_syntatical.tab.c"
    break;

  case 13: /* compoundStatement: '{' declaration statements '}'  */
#line 95 "compLex_syntatical.y"
                                                  {printf("compount statement\n");}
#line 1456 "compLex_syntatical.tab.c"
    break;

  case 14: /* declaration: declaration variableInit  */
#line 98 "compLex_syntatical.y"
                                      {printf("declaration\n");}
#line 1462 "compLex_syntatical.tab.c"
    break;

  case 15: /* declaration: %empty  */
#line 99 "compLex_syntatical.y"
           {printf("empty declaration\n");}
#line 1468 "compLex_syntatical.tab.c"
    break;

  case 16: /* statements: statements statement  */
#line 102 "compLex_syntatical.y"
                                 {printf("statements, statement\n");}
#line 1474 "compLex_syntatical.tab.c"
    break;

  case 17: /* statements: %empty  */
#line 103 "compLex_syntatical.y"
           {printf("empty statement\n");}
#line 1480 "compLex_syntatical.tab.c"
    break;

  case 18: /* statement: expression  */
#line 106 "compLex_syntatical.y"
                      {printf("expression\n");}
#line 1486 "compLex_syntatical.tab.c"
    break;

  case 19: /* statement: inOutStatement  */
#line 107 "compLex_syntatical.y"
                   {;}
#line 1492 "compLex_syntatical.tab.c"
    break;

  case 20: /* statement: fluxControlstatement  */
#line 108 "compLex_syntatical.y"
                         {;}
#line 1498 "compLex_syntatical.tab.c"
    break;

  case 21: /* statement: iterationStatement  */
#line 109 "compLex_syntatical.y"
                       {;}
#line 1504 "compLex_syntatical.tab.c"
    break;

  case 22: /* inOutStatement: WRITE '(' variable ')' ';'  */
#line 112 "compLex_syntatical.y"
                                           {printf("IO: write identifier\n");}
#line 1510 "compLex_syntatical.tab.c"
    break;

  case 23: /* inOutStatement: WRITELN '(' variable ')' ';'  */
#line 113 "compLex_syntatical.y"
                                 {printf("IO: writeln identifier\n");}
#line 1516 "compLex_syntatical.tab.c"
    break;

  case 24: /* inOutStatement: READ '(' variable ')' ';'  */
#line 114 "compLex_syntatical.y"
                              {printf("IO: read identifier\n");}
#line 1522 "compLex_syntatical.tab.c"
    break;

  case 25: /* fluxControlstatement: RETURN expression  */
#line 117 "compLex_syntatical.y"
                                        {printf("return variable\n");}
#line 1528 "compLex_syntatical.tab.c"
    break;

  case 26: /* fluxControlstatement: RETURN ';'  */
#line 118 "compLex_syntatical.y"
               {printf("return null\n");}
#line 1534 "compLex_syntatical.tab.c"
    break;

  case 27: /* fluxControlstatement: IF '(' operationalExpression ')' compoundStatement  */
#line 119 "compLex_syntatical.y"
                                                       {printf("if statement\n");}
#line 1540 "compLex_syntatical.tab.c"
    break;

  case 28: /* fluxControlstatement: IF '(' operationalExpression ')' compoundStatement ELSE compoundStatement  */
#line 120 "compLex_syntatical.y"
                                                                               {printf("if/else statement\n");}
#line 1546 "compLex_syntatical.tab.c"
    break;

  case 29: /* iterationStatement: FOR '(' operationalExpression ')' compoundStatement  */
#line 123 "compLex_syntatical.y"
                                                                        {printf("for loop one argument\n");}
#line 1552 "compLex_syntatical.tab.c"
    break;

  case 30: /* iterationStatement: FOR '(' expression expression forIncrement ')' compoundStatement  */
#line 124 "compLex_syntatical.y"
                                                                     {printf("for loop three arguments\n");}
#line 1558 "compLex_syntatical.tab.c"
    break;

  case 31: /* iterationStatement: SET_FORALL '(' term ADD_IN_OP operationalExpression ')' compoundStatement  */
#line 125 "compLex_syntatical.y"
                                                                              {printf("set forall loop\n");}
#line 1564 "compLex_syntatical.tab.c"
    break;

  case 32: /* expression: operationalExpression ';'  */
#line 128 "compLex_syntatical.y"
                                      {;}
#line 1570 "compLex_syntatical.tab.c"
    break;

  case 33: /* expression: variableAssignment  */
#line 129 "compLex_syntatical.y"
                       {;}
#line 1576 "compLex_syntatical.tab.c"
    break;

  case 34: /* operationalExpression: arithmeticExpression  */
#line 132 "compLex_syntatical.y"
                                            {;}
#line 1582 "compLex_syntatical.tab.c"
    break;

  case 35: /* operationalExpression: logicalExpression  */
#line 133 "compLex_syntatical.y"
                      {;}
#line 1588 "compLex_syntatical.tab.c"
    break;

  case 36: /* operationalExpression: setOperationalExpression  */
#line 134 "compLex_syntatical.y"
                             {;}
#line 1594 "compLex_syntatical.tab.c"
    break;

  case 37: /* operationalExpression: term  */
#line 135 "compLex_syntatical.y"
         {;}
#line 1600 "compLex_syntatical.tab.c"
    break;

  case 38: /* arithmeticExpression: operationalExpression ADD_OP term  */
#line 138 "compLex_syntatical.y"
                                                        {printf("add operation\n");}
#line 1606 "compLex_syntatical.tab.c"
    break;

  case 39: /* arithmeticExpression: operationalExpression SUB_OP term  */
#line 139 "compLex_syntatical.y"
                                      {printf("subtraction operation\n");}
#line 1612 "compLex_syntatical.tab.c"
    break;

  case 40: /* arithmeticExpression: operationalExpression MULT_OP term  */
#line 140 "compLex_syntatical.y"
                                       {printf("multiplication operation\n");}
#line 1618 "compLex_syntatical.tab.c"
    break;

  case 41: /* arithmeticExpression: operationalExpression DIV_OP term  */
#line 141 "compLex_syntatical.y"
                                      {printf("division operation\n");}
#line 1624 "compLex_syntatical.tab.c"
    break;

  case 42: /* logicalExpression: operationalExpression ILT term  */
#line 144 "compLex_syntatical.y"
                                                  {printf("is less than operation\n");}
#line 1630 "compLex_syntatical.tab.c"
    break;

  case 43: /* logicalExpression: operationalExpression ILTE term  */
#line 145 "compLex_syntatical.y"
                                    {printf("is less or equal operation\n");}
#line 1636 "compLex_syntatical.tab.c"
    break;

  case 44: /* logicalExpression: operationalExpression IGT term  */
#line 146 "compLex_syntatical.y"
                                   {printf("is greater than operation\n");}
#line 1642 "compLex_syntatical.tab.c"
    break;

  case 45: /* logicalExpression: operationalExpression IGTE term  */
#line 147 "compLex_syntatical.y"
                                    {printf("is greater than or equal operation\n");}
#line 1648 "compLex_syntatical.tab.c"
    break;

  case 46: /* logicalExpression: operationalExpression IDIFF term  */
#line 148 "compLex_syntatical.y"
                                     {printf("is different than operation\n");}
#line 1654 "compLex_syntatical.tab.c"
    break;

  case 47: /* logicalExpression: operationalExpression IEQ term  */
#line 149 "compLex_syntatical.y"
                                   {printf("is equal to operation\n");}
#line 1660 "compLex_syntatical.tab.c"
    break;

  case 48: /* setOperationalExpression: ADD_SET_OP '(' term ADD_IN_OP operationalExpression ')'  */
#line 152 "compLex_syntatical.y"
                                                                                  {printf("add to set op\n");}
#line 1666 "compLex_syntatical.tab.c"
    break;

  case 49: /* setOperationalExpression: REMOVE_SET_OP '(' term ADD_IN_OP operationalExpression ')'  */
#line 153 "compLex_syntatical.y"
                                                               {printf("remove from set op\n");}
#line 1672 "compLex_syntatical.tab.c"
    break;

  case 50: /* setOperationalExpression: EXISTS_IN_SET_OP '(' term ADD_IN_OP operationalExpression ')'  */
#line 154 "compLex_syntatical.y"
                                                                  {printf("exists el in set op\n");}
#line 1678 "compLex_syntatical.tab.c"
    break;

  case 51: /* setOperationalExpression: IS_SET '(' term ')'  */
#line 155 "compLex_syntatical.y"
                        {printf("is set operator\n");}
#line 1684 "compLex_syntatical.tab.c"
    break;

  case 52: /* variableAssignment: IDENTIFIER ASSIGN expression  */
#line 158 "compLex_syntatical.y"
                                                 {printf("variable assignment\n");}
#line 1690 "compLex_syntatical.tab.c"
    break;

  case 53: /* forIncrement: IDENTIFIER ASSIGN arithmeticExpression  */
#line 161 "compLex_syntatical.y"
                                                     {printf("for loop increment\n");}
#line 1696 "compLex_syntatical.tab.c"
    break;

  case 54: /* term: '(' operationalExpression ')'  */
#line 164 "compLex_syntatical.y"
                                    {printf("( operationalExp )\n");}
#line 1702 "compLex_syntatical.tab.c"
    break;

  case 55: /* term: variable  */
#line 165 "compLex_syntatical.y"
             {printf("variable\n");}
#line 1708 "compLex_syntatical.tab.c"
    break;

  case 56: /* term: functionCall  */
#line 166 "compLex_syntatical.y"
                 {;}
#line 1714 "compLex_syntatical.tab.c"
    break;

  case 57: /* term: EMPTY  */
#line 167 "compLex_syntatical.y"
          {printf("EMPTY constant value\n");}
#line 1720 "compLex_syntatical.tab.c"
    break;

  case 58: /* term: FLOAT  */
#line 168 "compLex_syntatical.y"
          {printf("float value\n");}
#line 1726 "compLex_syntatical.tab.c"
    break;

  case 59: /* term: INT  */
#line 169 "compLex_syntatical.y"
        {printf("int value\n");}
#line 1732 "compLex_syntatical.tab.c"
    break;

  case 60: /* functionCall: IDENTIFIER '(' functionArguments ')'  */
#line 172 "compLex_syntatical.y"
                                                   {printf("function call\n");}
#line 1738 "compLex_syntatical.tab.c"
    break;

  case 61: /* functionArguments: callArguments  */
#line 175 "compLex_syntatical.y"
                                 {;}
#line 1744 "compLex_syntatical.tab.c"
    break;

  case 62: /* functionArguments: %empty  */
#line 176 "compLex_syntatical.y"
           {printf("empty function argument\n");}
#line 1750 "compLex_syntatical.tab.c"
    break;

  case 63: /* callArguments: callArguments ',' operationalExpression  */
#line 179 "compLex_syntatical.y"
                                                       {printf("function arguments , term\n");}
#line 1756 "compLex_syntatical.tab.c"
    break;

  case 64: /* callArguments: operationalExpression  */
#line 180 "compLex_syntatical.y"
                          {printf("function term argument\n");}
#line 1762 "compLex_syntatical.tab.c"
    break;

  case 65: /* variableInit: typeSpecifier IDENTIFIER ';'  */
#line 183 "compLex_syntatical.y"
                                           {
  symbolParam symbol = { globalCounterOfSymbols, enumVariable, (yyvsp[-1].str) };
  add_symbol_node(symbol);
  globalCounterOfSymbols++;
  printf("variable initialization %s\n", (yyvsp[-1].str));
}
#line 1773 "compLex_syntatical.tab.c"
    break;

  case 66: /* variable: IDENTIFIER  */
#line 191 "compLex_syntatical.y"
                     {printf("variable\n");}
#line 1779 "compLex_syntatical.tab.c"
    break;

  case 67: /* typeSpecifier: T_INT  */
#line 194 "compLex_syntatical.y"
                     {printf("integer type\n");}
#line 1785 "compLex_syntatical.tab.c"
    break;

  case 68: /* typeSpecifier: T_FLOAT  */
#line 195 "compLex_syntatical.y"
            {printf("float type\n");}
#line 1791 "compLex_syntatical.tab.c"
    break;

  case 69: /* typeSpecifier: T_ELEM  */
#line 196 "compLex_syntatical.y"
           {printf("elem type\n");}
#line 1797 "compLex_syntatical.tab.c"
    break;

  case 70: /* typeSpecifier: T_SET  */
#line 197 "compLex_syntatical.y"
          {printf("set type\n");}
#line 1803 "compLex_syntatical.tab.c"
    break;


#line 1807 "compLex_syntatical.tab.c"

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
      yyerror (YY_("syntax error"));
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


#if !defined yyoverflow
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

  return yyresult;
}

#line 200 "compLex_syntatical.y"


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

  print_symbols();

  return 0;
}
