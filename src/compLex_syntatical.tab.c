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
#line 1 "compLex_syntatical.y"


// Required libs declarations
#include <stdlib.h>
#include <stdio.h>

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


#line 93 "compLex_syntatical.tab.c"

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
  YYSYMBOL_ASSIGN = 4,                     /* ASSIGN  */
  YYSYMBOL_INT = 5,                        /* INT  */
  YYSYMBOL_FLOAT = 6,                      /* FLOAT  */
  YYSYMBOL_EMPTY = 7,                      /* EMPTY  */
  YYSYMBOL_T_INT = 8,                      /* T_INT  */
  YYSYMBOL_T_FLOAT = 9,                    /* T_FLOAT  */
  YYSYMBOL_T_ELEM = 10,                    /* T_ELEM  */
  YYSYMBOL_T_SET = 11,                     /* T_SET  */
  YYSYMBOL_ADD_OP = 12,                    /* ADD_OP  */
  YYSYMBOL_SUB_OP = 13,                    /* SUB_OP  */
  YYSYMBOL_MULT_OP = 14,                   /* MULT_OP  */
  YYSYMBOL_DIV_OP = 15,                    /* DIV_OP  */
  YYSYMBOL_ADD_SET_OP = 16,                /* ADD_SET_OP  */
  YYSYMBOL_REMOVE_SET_OP = 17,             /* REMOVE_SET_OP  */
  YYSYMBOL_EXISTS_IN_SET_OP = 18,          /* EXISTS_IN_SET_OP  */
  YYSYMBOL_IS_SET = 19,                    /* IS_SET  */
  YYSYMBOL_ADD_IN_OP = 20,                 /* ADD_IN_OP  */
  YYSYMBOL_ILT = 21,                       /* ILT  */
  YYSYMBOL_ILTE = 22,                      /* ILTE  */
  YYSYMBOL_IGT = 23,                       /* IGT  */
  YYSYMBOL_IGTE = 24,                      /* IGTE  */
  YYSYMBOL_IDIFF = 25,                     /* IDIFF  */
  YYSYMBOL_IEQ = 26,                       /* IEQ  */
  YYSYMBOL_READ = 27,                      /* READ  */
  YYSYMBOL_WRITE = 28,                     /* WRITE  */
  YYSYMBOL_WRITELN = 29,                   /* WRITELN  */
  YYSYMBOL_RETURN = 30,                    /* RETURN  */
  YYSYMBOL_IF = 31,                        /* IF  */
  YYSYMBOL_ELSE = 32,                      /* ELSE  */
  YYSYMBOL_FOR = 33,                       /* FOR  */
  YYSYMBOL_34_ = 34,                       /* '('  */
  YYSYMBOL_35_ = 35,                       /* ')'  */
  YYSYMBOL_36_ = 36,                       /* ','  */
  YYSYMBOL_37_ = 37,                       /* '{'  */
  YYSYMBOL_38_ = 38,                       /* '}'  */
  YYSYMBOL_39_ = 39,                       /* ';'  */
  YYSYMBOL_YYACCEPT = 40,                  /* $accept  */
  YYSYMBOL_entryPoint = 41,                /* entryPoint  */
  YYSYMBOL_programEntries = 42,            /* programEntries  */
  YYSYMBOL_functionDefinition = 43,        /* functionDefinition  */
  YYSYMBOL_44_1 = 44,                      /* $@1  */
  YYSYMBOL_parameters = 45,                /* parameters  */
  YYSYMBOL_parameter = 46,                 /* parameter  */
  YYSYMBOL_compoundStatement = 47,         /* compoundStatement  */
  YYSYMBOL_declaration = 48,               /* declaration  */
  YYSYMBOL_statements = 49,                /* statements  */
  YYSYMBOL_statement = 50,                 /* statement  */
  YYSYMBOL_inOutStatement = 51,            /* inOutStatement  */
  YYSYMBOL_fluxControlstatement = 52,      /* fluxControlstatement  */
  YYSYMBOL_iterationStatement = 53,        /* iterationStatement  */
  YYSYMBOL_expression = 54,                /* expression  */
  YYSYMBOL_operationalExpression = 55,     /* operationalExpression  */
  YYSYMBOL_arithmeticExpression = 56,      /* arithmeticExpression  */
  YYSYMBOL_logicalExpression = 57,         /* logicalExpression  */
  YYSYMBOL_setOperationalExpression = 58,  /* setOperationalExpression  */
  YYSYMBOL_term = 59,                      /* term  */
  YYSYMBOL_variableInit = 60,              /* variableInit  */
  YYSYMBOL_variable = 61,                  /* variable  */
  YYSYMBOL_typeSpecifier = 62              /* typeSpecifier  */
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
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYLAST   213

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  62
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  133

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   288


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
      34,    35,     2,     2,    36,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    39,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    37,     2,    38,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    52,    52,    55,    56,    57,    58,    61,    61,    67,
      68,    71,    72,    75,    78,    79,    82,    83,    86,    87,
      88,    89,    92,    93,    94,    97,    98,    99,   100,   103,
     104,   107,   108,   109,   112,   113,   114,   115,   118,   119,
     120,   121,   124,   125,   126,   127,   128,   129,   132,   133,
     134,   135,   138,   139,   140,   141,   142,   145,   148,   151,
     152,   153,   154
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
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER", "ASSIGN",
  "INT", "FLOAT", "EMPTY", "T_INT", "T_FLOAT", "T_ELEM", "T_SET", "ADD_OP",
  "SUB_OP", "MULT_OP", "DIV_OP", "ADD_SET_OP", "REMOVE_SET_OP",
  "EXISTS_IN_SET_OP", "IS_SET", "ADD_IN_OP", "ILT", "ILTE", "IGT", "IGTE",
  "IDIFF", "IEQ", "READ", "WRITE", "WRITELN", "RETURN", "IF", "ELSE",
  "FOR", "'('", "')'", "','", "'{'", "'}'", "';'", "$accept", "entryPoint",
  "programEntries", "functionDefinition", "$@1", "parameters", "parameter",
  "compoundStatement", "declaration", "statements", "statement",
  "inOutStatement", "fluxControlstatement", "iterationStatement",
  "expression", "operationalExpression", "arithmeticExpression",
  "logicalExpression", "setOperationalExpression", "term", "variableInit",
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
     285,   286,   287,   288,    40,    41,    44,   123,   125,    59
};
#endif

#define YYPACT_NINF (-109)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      18,  -109,  -109,  -109,  -109,     7,    18,  -109,  -109,     6,
    -109,  -109,  -109,   -26,  -109,   -18,    18,   -31,  -109,    27,
       2,    18,  -109,  -109,  -109,    39,    18,  -109,    66,  -109,
      40,  -109,  -109,  -109,  -109,    13,    14,    15,    17,    19,
      20,    22,    -1,    23,    28,   100,  -109,  -109,  -109,  -109,
    -109,  -109,   133,  -109,  -109,  -109,  -109,    48,   -26,   100,
     100,   100,    12,    58,    58,    58,  -109,    25,   100,   100,
     152,  -109,    12,    12,    12,    12,    12,    12,    12,    12,
      12,    12,  -109,   100,    43,    47,    50,    33,    41,    42,
      51,  -109,   167,   100,   114,  -109,  -109,  -109,  -109,  -109,
    -109,  -109,  -109,  -109,  -109,  -109,  -109,   100,   100,   100,
    -109,    35,    36,    49,     2,   100,     2,    54,    55,    56,
    -109,  -109,  -109,    46,    57,  -109,  -109,  -109,  -109,     2,
       2,  -109,  -109
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    59,    60,    61,    62,     0,     2,     6,     4,     0,
       1,     5,     3,     7,    57,     0,    10,     0,     9,     0,
       0,     0,    11,    15,     8,     0,    17,    12,     0,    14,
       0,    58,    56,    55,    54,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    13,    16,    19,    20,
      21,    18,    33,    34,    35,    36,    37,    52,     0,     0,
       0,     0,     0,     0,     0,     0,    26,     0,     0,     0,
       0,    52,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    32,     0,     0,     0,     0,     0,     0,     0,
       0,    25,     0,     0,    33,    53,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    31,     0,     0,     0,
      51,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      24,    22,    23,    27,     0,    29,    48,    49,    50,     0,
       0,    28,    30
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -109,  -109,  -109,    92,  -109,  -109,  -109,  -108,  -109,  -109,
    -109,  -109,  -109,  -109,   -49,   -44,  -109,  -109,  -109,   132,
      -3,   -28,    24
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     5,     6,     7,    15,    17,    18,    24,    26,    28,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
       8,    71,     9
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      57,    70,    31,    12,    20,    21,   123,    10,   125,    13,
      84,    85,    86,    14,    67,    31,    16,    32,    33,    34,
      93,   131,   132,    29,    92,    94,     1,     2,     3,     4,
      22,    57,    57,    57,   106,    88,    89,    90,    66,    23,
      19,    57,    27,    58,   115,    25,    45,    59,    60,    61,
      30,    62,    83,    63,    64,    57,    65,    68,   117,   118,
     119,    31,    69,   107,    91,    57,   124,   108,   110,    31,
     109,    32,    33,    34,   120,   121,   111,   112,   129,    57,
      57,    57,    35,    36,    37,    38,   113,    57,   122,   126,
     127,   128,   130,    39,    40,    41,    42,    43,    11,    44,
      45,     0,     0,    31,    46,    32,    33,    34,     0,     0,
       0,     0,     0,     0,     0,     0,    35,    36,    37,    38,
       0,     0,     0,     0,     0,     0,    72,    73,    74,    75,
       0,     0,     0,     0,    45,    76,    77,    78,    79,    80,
      81,     0,     0,     0,     0,    72,    73,    74,    75,   116,
       0,     0,     0,    82,    76,    77,    78,    79,    80,    81,
       0,     0,     0,     0,    72,    73,    74,    75,     0,     0,
       0,     0,    82,    76,    77,    78,    79,    80,    81,    72,
      73,    74,    75,     0,     0,     0,     0,    95,    76,    77,
      78,    79,    80,    81,    87,     0,     0,     0,     0,     0,
       0,     0,   114,     0,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105
};

static const yytype_int16 yycheck[] =
{
      28,    45,     3,     6,    35,    36,   114,     0,   116,     3,
      59,    60,    61,    39,    42,     3,    34,     5,     6,     7,
      69,   129,   130,    26,    68,    69,     8,     9,    10,    11,
       3,    59,    60,    61,    83,    63,    64,    65,    39,    37,
      16,    69,     3,     3,    93,    21,    34,    34,    34,    34,
      26,    34,     4,    34,    34,    83,    34,    34,   107,   108,
     109,     3,    34,    20,    39,    93,   115,    20,    35,     3,
      20,     5,     6,     7,    39,    39,    35,    35,    32,   107,
     108,   109,    16,    17,    18,    19,    35,   115,    39,    35,
      35,    35,    35,    27,    28,    29,    30,    31,     6,    33,
      34,    -1,    -1,     3,    38,     5,     6,     7,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    16,    17,    18,    19,
      -1,    -1,    -1,    -1,    -1,    -1,    12,    13,    14,    15,
      -1,    -1,    -1,    -1,    34,    21,    22,    23,    24,    25,
      26,    -1,    -1,    -1,    -1,    12,    13,    14,    15,    35,
      -1,    -1,    -1,    39,    21,    22,    23,    24,    25,    26,
      -1,    -1,    -1,    -1,    12,    13,    14,    15,    -1,    -1,
      -1,    -1,    39,    21,    22,    23,    24,    25,    26,    12,
      13,    14,    15,    -1,    -1,    -1,    -1,    35,    21,    22,
      23,    24,    25,    26,    62,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    -1,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     8,     9,    10,    11,    41,    42,    43,    60,    62,
       0,    43,    60,     3,    39,    44,    34,    45,    46,    62,
      35,    36,     3,    37,    47,    62,    48,     3,    49,    60,
      62,     3,     5,     6,     7,    16,    17,    18,    19,    27,
      28,    29,    30,    31,    33,    34,    38,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    61,     3,    34,
      34,    34,    34,    34,    34,    34,    39,    61,    34,    34,
      55,    61,    12,    13,    14,    15,    21,    22,    23,    24,
      25,    26,    39,     4,    54,    54,    54,    59,    61,    61,
      61,    39,    55,    54,    55,    35,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    54,    20,    20,    20,
      35,    35,    35,    35,    35,    54,    35,    54,    54,    54,
      39,    39,    39,    47,    54,    47,    35,    35,    35,    32,
      35,    47,    47
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    40,    41,    42,    42,    42,    42,    44,    43,    45,
      45,    46,    46,    47,    48,    48,    49,    49,    50,    50,
      50,    50,    51,    51,    51,    52,    52,    52,    52,    53,
      53,    54,    54,    54,    55,    55,    55,    55,    56,    56,
      56,    56,    57,    57,    57,    57,    57,    57,    58,    58,
      58,    58,    59,    59,    59,    59,    59,    60,    61,    62,
      62,    62,    62
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     1,     0,     7,     1,
       0,     2,     4,     4,     2,     0,     2,     0,     1,     1,
       1,     1,     5,     5,     5,     3,     2,     5,     7,     5,
       7,     3,     2,     1,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     6,     6,
       6,     4,     1,     3,     1,     1,     1,     3,     1,     1,
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

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
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
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
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

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
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
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* entryPoint: programEntries  */
#line 52 "compLex_syntatical.y"
                           { printf("Program entry point\n"); }
#line 1242 "compLex_syntatical.tab.c"
    break;

  case 3: /* programEntries: programEntries variableInit  */
#line 55 "compLex_syntatical.y"
                                            {;}
#line 1248 "compLex_syntatical.tab.c"
    break;

  case 4: /* programEntries: variableInit  */
#line 56 "compLex_syntatical.y"
                 {;}
#line 1254 "compLex_syntatical.tab.c"
    break;

  case 5: /* programEntries: programEntries functionDefinition  */
#line 57 "compLex_syntatical.y"
                                      {;}
#line 1260 "compLex_syntatical.tab.c"
    break;

  case 6: /* programEntries: functionDefinition  */
#line 58 "compLex_syntatical.y"
                       {;}
#line 1266 "compLex_syntatical.tab.c"
    break;

  case 7: /* $@1: %empty  */
#line 61 "compLex_syntatical.y"
                                             {}
#line 1272 "compLex_syntatical.tab.c"
    break;

  case 8: /* functionDefinition: typeSpecifier IDENTIFIER $@1 '(' parameters ')' compoundStatement  */
#line 62 "compLex_syntatical.y"
                                       {
    printf("function definition \n");
  }
#line 1280 "compLex_syntatical.tab.c"
    break;

  case 9: /* parameters: parameter  */
#line 67 "compLex_syntatical.y"
                      {printf("parameter\n");}
#line 1286 "compLex_syntatical.tab.c"
    break;

  case 10: /* parameters: %empty  */
#line 68 "compLex_syntatical.y"
           {printf("empty parameters\n");}
#line 1292 "compLex_syntatical.tab.c"
    break;

  case 11: /* parameter: typeSpecifier IDENTIFIER  */
#line 71 "compLex_syntatical.y"
                                    {printf("parameter and identifier\n");}
#line 1298 "compLex_syntatical.tab.c"
    break;

  case 12: /* parameter: parameters ',' typeSpecifier IDENTIFIER  */
#line 72 "compLex_syntatical.y"
                                            {printf("parameter, type and identifier\n");}
#line 1304 "compLex_syntatical.tab.c"
    break;

  case 13: /* compoundStatement: '{' declaration statements '}'  */
#line 75 "compLex_syntatical.y"
                                                  {printf("compount statement\n");}
#line 1310 "compLex_syntatical.tab.c"
    break;

  case 14: /* declaration: declaration variableInit  */
#line 78 "compLex_syntatical.y"
                                      {printf("declaration\n");}
#line 1316 "compLex_syntatical.tab.c"
    break;

  case 15: /* declaration: %empty  */
#line 79 "compLex_syntatical.y"
           {printf("empty declaration\n");}
#line 1322 "compLex_syntatical.tab.c"
    break;

  case 16: /* statements: statements statement  */
#line 82 "compLex_syntatical.y"
                                 {printf("statements, statement\n");}
#line 1328 "compLex_syntatical.tab.c"
    break;

  case 17: /* statements: %empty  */
#line 83 "compLex_syntatical.y"
           {printf("empty statement\n");}
#line 1334 "compLex_syntatical.tab.c"
    break;

  case 18: /* statement: expression  */
#line 86 "compLex_syntatical.y"
                      {printf("expression\n");}
#line 1340 "compLex_syntatical.tab.c"
    break;

  case 19: /* statement: inOutStatement  */
#line 87 "compLex_syntatical.y"
                   {;}
#line 1346 "compLex_syntatical.tab.c"
    break;

  case 20: /* statement: fluxControlstatement  */
#line 88 "compLex_syntatical.y"
                         {;}
#line 1352 "compLex_syntatical.tab.c"
    break;

  case 21: /* statement: iterationStatement  */
#line 89 "compLex_syntatical.y"
                       {;}
#line 1358 "compLex_syntatical.tab.c"
    break;

  case 22: /* inOutStatement: WRITE '(' variable ')' ';'  */
#line 92 "compLex_syntatical.y"
                                           {printf("IO: write identifier\n");}
#line 1364 "compLex_syntatical.tab.c"
    break;

  case 23: /* inOutStatement: WRITELN '(' variable ')' ';'  */
#line 93 "compLex_syntatical.y"
                                 {printf("IO: writeln identifier\n");}
#line 1370 "compLex_syntatical.tab.c"
    break;

  case 24: /* inOutStatement: READ '(' variable ')' ';'  */
#line 94 "compLex_syntatical.y"
                              {printf("IO: read identifier\n");}
#line 1376 "compLex_syntatical.tab.c"
    break;

  case 25: /* fluxControlstatement: RETURN variable ';'  */
#line 97 "compLex_syntatical.y"
                                          {printf("return variable\n");}
#line 1382 "compLex_syntatical.tab.c"
    break;

  case 26: /* fluxControlstatement: RETURN ';'  */
#line 98 "compLex_syntatical.y"
               {printf("return null\n");}
#line 1388 "compLex_syntatical.tab.c"
    break;

  case 27: /* fluxControlstatement: IF '(' operationalExpression ')' compoundStatement  */
#line 99 "compLex_syntatical.y"
                                                       {printf("if statement\n");}
#line 1394 "compLex_syntatical.tab.c"
    break;

  case 28: /* fluxControlstatement: IF '(' operationalExpression ')' compoundStatement ELSE compoundStatement  */
#line 100 "compLex_syntatical.y"
                                                                               {printf("if/else statement\n");}
#line 1400 "compLex_syntatical.tab.c"
    break;

  case 29: /* iterationStatement: FOR '(' operationalExpression ')' compoundStatement  */
#line 103 "compLex_syntatical.y"
                                                                        {printf("for loop one argument\n");}
#line 1406 "compLex_syntatical.tab.c"
    break;

  case 30: /* iterationStatement: FOR '(' expression expression expression ')' compoundStatement  */
#line 104 "compLex_syntatical.y"
                                                                   {printf("for loop three arguments\n");}
#line 1412 "compLex_syntatical.tab.c"
    break;

  case 31: /* expression: variable ASSIGN expression  */
#line 107 "compLex_syntatical.y"
                                       {printf("assignment Expression\n");}
#line 1418 "compLex_syntatical.tab.c"
    break;

  case 32: /* expression: operationalExpression ';'  */
#line 108 "compLex_syntatical.y"
                              {;}
#line 1424 "compLex_syntatical.tab.c"
    break;

  case 33: /* expression: operationalExpression  */
#line 109 "compLex_syntatical.y"
                          {;}
#line 1430 "compLex_syntatical.tab.c"
    break;

  case 34: /* operationalExpression: arithmeticExpression  */
#line 112 "compLex_syntatical.y"
                                            {;}
#line 1436 "compLex_syntatical.tab.c"
    break;

  case 35: /* operationalExpression: logicalExpression  */
#line 113 "compLex_syntatical.y"
                      {;}
#line 1442 "compLex_syntatical.tab.c"
    break;

  case 36: /* operationalExpression: setOperationalExpression  */
#line 114 "compLex_syntatical.y"
                             {;}
#line 1448 "compLex_syntatical.tab.c"
    break;

  case 37: /* operationalExpression: term  */
#line 115 "compLex_syntatical.y"
         {;}
#line 1454 "compLex_syntatical.tab.c"
    break;

  case 38: /* arithmeticExpression: operationalExpression ADD_OP term  */
#line 118 "compLex_syntatical.y"
                                                        {printf("add operation\n");}
#line 1460 "compLex_syntatical.tab.c"
    break;

  case 39: /* arithmeticExpression: operationalExpression SUB_OP term  */
#line 119 "compLex_syntatical.y"
                                      {printf("subtraction operation\n");}
#line 1466 "compLex_syntatical.tab.c"
    break;

  case 40: /* arithmeticExpression: operationalExpression MULT_OP term  */
#line 120 "compLex_syntatical.y"
                                       {printf("multiplication operation\n");}
#line 1472 "compLex_syntatical.tab.c"
    break;

  case 41: /* arithmeticExpression: operationalExpression DIV_OP term  */
#line 121 "compLex_syntatical.y"
                                      {printf("division operation\n");}
#line 1478 "compLex_syntatical.tab.c"
    break;

  case 42: /* logicalExpression: operationalExpression ILT term  */
#line 124 "compLex_syntatical.y"
                                                  {printf("is less than operation\n");}
#line 1484 "compLex_syntatical.tab.c"
    break;

  case 43: /* logicalExpression: operationalExpression ILTE term  */
#line 125 "compLex_syntatical.y"
                                    {printf("is less or equal operation\n");}
#line 1490 "compLex_syntatical.tab.c"
    break;

  case 44: /* logicalExpression: operationalExpression IGT term  */
#line 126 "compLex_syntatical.y"
                                   {printf("is greater than operation\n");}
#line 1496 "compLex_syntatical.tab.c"
    break;

  case 45: /* logicalExpression: operationalExpression IGTE term  */
#line 127 "compLex_syntatical.y"
                                    {printf("is greater than or equal operation\n");}
#line 1502 "compLex_syntatical.tab.c"
    break;

  case 46: /* logicalExpression: operationalExpression IDIFF term  */
#line 128 "compLex_syntatical.y"
                                     {printf("is different than operation\n");}
#line 1508 "compLex_syntatical.tab.c"
    break;

  case 47: /* logicalExpression: operationalExpression IEQ term  */
#line 129 "compLex_syntatical.y"
                                   {printf("is equal to operation\n");}
#line 1514 "compLex_syntatical.tab.c"
    break;

  case 48: /* setOperationalExpression: ADD_SET_OP '(' expression ADD_IN_OP expression ')'  */
#line 132 "compLex_syntatical.y"
                                                                             {printf("add to set op\n");}
#line 1520 "compLex_syntatical.tab.c"
    break;

  case 49: /* setOperationalExpression: REMOVE_SET_OP '(' expression ADD_IN_OP expression ')'  */
#line 133 "compLex_syntatical.y"
                                                          {printf("remove from set op\n");}
#line 1526 "compLex_syntatical.tab.c"
    break;

  case 50: /* setOperationalExpression: EXISTS_IN_SET_OP '(' expression ADD_IN_OP expression ')'  */
#line 134 "compLex_syntatical.y"
                                                             {printf("exists el in set op\n");}
#line 1532 "compLex_syntatical.tab.c"
    break;

  case 51: /* setOperationalExpression: IS_SET '(' term ')'  */
#line 135 "compLex_syntatical.y"
                        {printf("is set operator\n");}
#line 1538 "compLex_syntatical.tab.c"
    break;

  case 52: /* term: variable  */
#line 138 "compLex_syntatical.y"
               {printf("variable\n");}
#line 1544 "compLex_syntatical.tab.c"
    break;

  case 53: /* term: '(' operationalExpression ')'  */
#line 139 "compLex_syntatical.y"
                                  {printf("( operationalExp )\n");}
#line 1550 "compLex_syntatical.tab.c"
    break;

  case 54: /* term: EMPTY  */
#line 140 "compLex_syntatical.y"
          {printf("EMPTY constant value\n");}
#line 1556 "compLex_syntatical.tab.c"
    break;

  case 55: /* term: FLOAT  */
#line 141 "compLex_syntatical.y"
          {printf("float value\n");}
#line 1562 "compLex_syntatical.tab.c"
    break;

  case 56: /* term: INT  */
#line 142 "compLex_syntatical.y"
        {printf("int value\n");}
#line 1568 "compLex_syntatical.tab.c"
    break;

  case 57: /* variableInit: typeSpecifier IDENTIFIER ';'  */
#line 145 "compLex_syntatical.y"
                                           {printf("variable initialization\n");}
#line 1574 "compLex_syntatical.tab.c"
    break;

  case 58: /* variable: IDENTIFIER  */
#line 148 "compLex_syntatical.y"
                     {printf("variable\n");}
#line 1580 "compLex_syntatical.tab.c"
    break;

  case 59: /* typeSpecifier: T_INT  */
#line 151 "compLex_syntatical.y"
                     {printf("integer type\n");}
#line 1586 "compLex_syntatical.tab.c"
    break;

  case 60: /* typeSpecifier: T_FLOAT  */
#line 152 "compLex_syntatical.y"
            {printf("float type\n");}
#line 1592 "compLex_syntatical.tab.c"
    break;

  case 61: /* typeSpecifier: T_ELEM  */
#line 153 "compLex_syntatical.y"
           {printf("elem type\n");}
#line 1598 "compLex_syntatical.tab.c"
    break;

  case 62: /* typeSpecifier: T_SET  */
#line 154 "compLex_syntatical.y"
          {printf("set type\n");}
#line 1604 "compLex_syntatical.tab.c"
    break;


#line 1608 "compLex_syntatical.tab.c"

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
                      yytoken, &yylval);
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


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 157 "compLex_syntatical.y"


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
