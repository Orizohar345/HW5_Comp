/* A Bison parser, made by GNU Bison 3.8.2.  */

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
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.ypp"

    #include <iostream>
    #include <stdlib.h>
    #include <string>
    #include "hw3_output.hpp"
    #include "tables_stack.h"
    #include "types.h"
    #include <stack>
    #include "bp.hpp"

    using namespace std;
    extern int yylineno;
    extern int yylex();
    int yyerror(const char* message);

    TablesStack table_stack;
    CodeBuffer buffer;

    Exp* globalExp;


#line 93 "parser.tab.cpp"

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

#include "parser.tab.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TRUE = 3,                       /* TRUE  */
  YYSYMBOL_FALSE = 4,                      /* FALSE  */
  YYSYMBOL_RETURN = 5,                     /* RETURN  */
  YYSYMBOL_IF = 6,                         /* IF  */
  YYSYMBOL_WHILE = 7,                      /* WHILE  */
  YYSYMBOL_BREAK = 8,                      /* BREAK  */
  YYSYMBOL_CONTINUE = 9,                   /* CONTINUE  */
  YYSYMBOL_SC = 10,                        /* SC  */
  YYSYMBOL_LPAREN = 11,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 12,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 13,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 14,                    /* RBRACE  */
  YYSYMBOL_INT = 15,                       /* INT  */
  YYSYMBOL_BYTE = 16,                      /* BYTE  */
  YYSYMBOL_B = 17,                         /* B  */
  YYSYMBOL_BOOL = 18,                      /* BOOL  */
  YYSYMBOL_STRING = 19,                    /* STRING  */
  YYSYMBOL_ID = 20,                        /* ID  */
  YYSYMBOL_NUM = 21,                       /* NUM  */
  YYSYMBOL_ASSIGN = 22,                    /* ASSIGN  */
  YYSYMBOL_OR = 23,                        /* OR  */
  YYSYMBOL_AND = 24,                       /* AND  */
  YYSYMBOL_RELOP_EQ = 25,                  /* RELOP_EQ  */
  YYSYMBOL_RELOP_REL = 26,                 /* RELOP_REL  */
  YYSYMBOL_BINOP_ADD = 27,                 /* BINOP_ADD  */
  YYSYMBOL_BINOP_MULT = 28,                /* BINOP_MULT  */
  YYSYMBOL_NOT = 29,                       /* NOT  */
  YYSYMBOL_ELSE = 30,                      /* ELSE  */
  YYSYMBOL_YYACCEPT = 31,                  /* $accept  */
  YYSYMBOL_Program = 32,                   /* Program  */
  YYSYMBOL_Statements = 33,                /* Statements  */
  YYSYMBOL_Statement = 34,                 /* Statement  */
  YYSYMBOL_35_1 = 35,                      /* $@1  */
  YYSYMBOL_36_2 = 36,                      /* $@2  */
  YYSYMBOL_37_3 = 37,                      /* $@3  */
  YYSYMBOL_Call = 38,                      /* Call  */
  YYSYMBOL_Type = 39,                      /* Type  */
  YYSYMBOL_Exp = 40,                       /* Exp  */
  YYSYMBOL_M1 = 41,                        /* M1  */
  YYSYMBOL_M2 = 42,                        /* M2  */
  YYSYMBOL_OR_MARKER = 43,                 /* OR_MARKER  */
  YYSYMBOL_AND_MARKER = 44                 /* AND_MARKER  */
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
typedef yytype_int8 yy_state_t;

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

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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
#define YYFINAL  25
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   160

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  31
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  14
/* YYNRULES -- Number of rules.  */
#define YYNRULES  43
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  80

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   285


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
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    38,    38,    41,    42,    45,    45,    46,    55,    82,
     115,   116,   117,   118,   118,   119,   119,   132,   133,   134,
     137,   160,   161,   162,   165,   174,   191,   208,   216,   221,
     227,   233,   242,   247,   252,   266,   289,   317,   335,   352,
     374,   389,   392,   398
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
  "\"end of file\"", "error", "\"invalid token\"", "TRUE", "FALSE",
  "RETURN", "IF", "WHILE", "BREAK", "CONTINUE", "SC", "LPAREN", "RPAREN",
  "LBRACE", "RBRACE", "INT", "BYTE", "B", "BOOL", "STRING", "ID", "NUM",
  "ASSIGN", "OR", "AND", "RELOP_EQ", "RELOP_REL", "BINOP_ADD",
  "BINOP_MULT", "NOT", "ELSE", "$accept", "Program", "Statements",
  "Statement", "$@1", "$@2", "$@3", "Call", "Type", "Exp", "M1", "M2",
  "OR_MARKER", "AND_MARKER", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-25)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     134,    10,    18,    19,    11,    29,   -25,   -25,   -25,   -25,
     -25,    -3,    42,   134,   -25,    38,    25,   -25,    12,    12,
     -25,   -25,   134,    12,    12,   -25,   -25,   -25,    -5,   -25,
     -25,    53,   -25,    54,    50,    12,   -25,   132,    64,    26,
     118,    88,    65,   -25,    12,    67,    94,   -25,   -25,   -25,
     -25,    12,    12,    12,    12,   134,   -25,   -25,   -25,   -25,
      71,    12,   -25,    12,    12,    -2,   -24,    49,   -25,   -25,
     134,   -25,   -25,    35,   -16,    55,   -25,   -25,   134,   -25
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,    19,     5,    21,    23,
      22,     0,     0,     2,     3,     0,     0,    11,     0,     0,
      17,    18,     0,     0,     0,     1,     4,    10,     0,    32,
      33,     0,    31,    27,    29,     0,    28,    40,     0,     0,
       0,     0,     0,     7,     0,     0,     0,    30,    34,    42,
      43,     0,     0,     0,     0,     0,    15,     6,    20,     9,
       0,     0,    24,     0,     0,    37,    38,    26,    25,    41,
       0,     8,    39,    36,    35,    12,    16,    13,     0,    14
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -25,   -25,    58,   -12,   -25,   -25,   -25,     0,    52,   -17,
     -25,   -25,   -25,   -25
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    12,    13,    14,    22,    78,    70,    36,    16,    37,
      38,    75,    63,    64
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      15,    26,    39,    53,    54,    43,    41,    42,    23,    51,
      52,    53,    54,    15,    46,    29,    30,    44,    48,    24,
      17,    20,    15,    31,    52,    53,    54,    60,    26,    18,
      19,    32,    33,    34,    65,    66,    67,    68,    56,    21,
      15,    35,    25,    69,    72,    28,    73,    74,    27,    49,
      50,    51,    52,    53,    54,    15,    29,    30,    76,    50,
      51,    52,    53,    54,    31,    23,    79,    47,     8,     9,
      15,    10,    32,    33,    34,    59,    55,    54,    15,    61,
      40,    71,    35,    45,     0,    77,     0,     0,    49,    50,
      51,    52,    53,    54,    49,    50,    51,    52,    53,    54,
      58,     0,     0,     0,     0,     0,    62,     0,     0,     0,
       0,    49,    50,    51,    52,    53,    54,    49,    50,    51,
      52,    53,    54,     1,     2,     3,     4,     5,     6,     0,
       0,     7,    57,     8,     9,     0,    10,     0,    11,     1,
       2,     3,     4,     5,     6,     0,     0,     7,     0,     8,
       9,     0,    10,     0,    11,    49,    50,    51,    52,    53,
      54
};

static const yytype_int8 yycheck[] =
{
       0,    13,    19,    27,    28,    10,    23,    24,    11,    25,
      26,    27,    28,    13,    31,     3,     4,    22,    35,    22,
      10,    10,    22,    11,    26,    27,    28,    44,    40,    11,
      11,    19,    20,    21,    51,    52,    53,    54,    12,    10,
      40,    29,     0,    55,    61,    20,    63,    64,    10,    23,
      24,    25,    26,    27,    28,    55,     3,     4,    70,    24,
      25,    26,    27,    28,    11,    11,    78,    17,    15,    16,
      70,    18,    19,    20,    21,    10,    12,    28,    78,    12,
      22,    10,    29,    31,    -1,    30,    -1,    -1,    23,    24,
      25,    26,    27,    28,    23,    24,    25,    26,    27,    28,
      12,    -1,    -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,
      -1,    23,    24,    25,    26,    27,    28,    23,    24,    25,
      26,    27,    28,     5,     6,     7,     8,     9,    10,    -1,
      -1,    13,    14,    15,    16,    -1,    18,    -1,    20,     5,
       6,     7,     8,     9,    10,    -1,    -1,    13,    -1,    15,
      16,    -1,    18,    -1,    20,    23,    24,    25,    26,    27,
      28
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,     6,     7,     8,     9,    10,    13,    15,    16,
      18,    20,    32,    33,    34,    38,    39,    10,    11,    11,
      10,    10,    35,    11,    22,     0,    34,    10,    20,     3,
       4,    11,    19,    20,    21,    29,    38,    40,    41,    40,
      33,    40,    40,    10,    22,    39,    40,    17,    40,    23,
      24,    25,    26,    27,    28,    12,    12,    14,    12,    10,
      40,    12,    12,    43,    44,    40,    40,    40,    40,    34,
      37,    10,    40,    40,    40,    42,    34,    30,    36,    34
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    31,    32,    33,    33,    35,    34,    34,    34,    34,
      34,    34,    34,    36,    34,    37,    34,    34,    34,    34,
      38,    39,    39,    39,    40,    40,    40,    40,    40,    40,
      40,    40,    40,    40,    40,    40,    40,    40,    40,    40,
      41,    42,    43,    44
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     0,     4,     3,     5,     4,
       2,     2,     6,     0,     9,     0,     6,     2,     2,     1,
       4,     1,     1,     1,     3,     3,     3,     1,     1,     1,
       2,     1,     1,     1,     2,     4,     4,     3,     3,     4,
       1,     0,     0,     0
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
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
  YY_USE (yyvaluep);
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
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
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
  case 2: /* Program: Statements  */
#line 38 "parser.ypp"
                     { table_stack.removeTopTable(); }
#line 1185 "parser.tab.cpp"
    break;

  case 3: /* Statements: Statement  */
#line 41 "parser.ypp"
                       {}
#line 1191 "parser.tab.cpp"
    break;

  case 4: /* Statements: Statements Statement  */
#line 42 "parser.ypp"
                                  {}
#line 1197 "parser.tab.cpp"
    break;

  case 5: /* $@1: %empty  */
#line 45 "parser.ypp"
                   { table_stack.addNewTable(); }
#line 1203 "parser.tab.cpp"
    break;

  case 6: /* Statement: LBRACE $@1 Statements RBRACE  */
#line 45 "parser.ypp"
                                                                    { table_stack.removeTopTable(); }
#line 1209 "parser.tab.cpp"
    break;

  case 7: /* Statement: Type ID SC  */
#line 46 "parser.ypp"
                       {
                if (table_stack.entryExists(yyvsp[-1]->text)) {
                    output::errorDef(yylineno, yyvsp[-1]->text);
                    exit(1);
                }
                table_stack.addToTopTable(Entry(yyvsp[-1]->text, yyvsp[-2]->text));
                std::string var = generateLoad(yyvsp[-1]->text);
                generateStore("0", var);
            }
#line 1223 "parser.tab.cpp"
    break;

  case 8: /* Statement: Type ID ASSIGN Exp SC  */
#line 55 "parser.ypp"
                                  {
                Exp* exp = dynamic_cast<Exp*>(yyvsp[-1]);
                if (!exp->is_const && !table_stack.entryExists(exp->text)) {
                    output::errorUndef(yylineno, exp->text);
                    exit(1);
                }

                if (yyvsp[-3]->text != "WHILE" && table_stack.entryExists(yyvsp[-3]->text)) {
                    output::errorDef(yylineno, yyvsp[-3]->text);
                    exit(1);
                }

                 if (exp->type != "INT" && exp->type != "BYTE" && exp->type != "BOOL" && exp->type != "STRING" && exp->type != "VOID" ){
                    output::errorUndef(yylineno, exp->text);
                    exit(1);
                }

                if (yyvsp[-4]->text != exp->type && !(yyvsp[-4]->text == "INT" && exp->type == "BYTE")) {
                    output::errorMismatch(yylineno);
                    exit(1);
                }
                table_stack.addToTopTable(Entry(yyvsp[-3]->text, yyvsp[-4]->text));
                std::string src = handleExp(exp);
                std::string target = generateLoad(yyvsp[-3]->text);
                generateStore(src, target);

            }
#line 1255 "parser.tab.cpp"
    break;

  case 9: /* Statement: ID ASSIGN Exp SC  */
#line 82 "parser.ypp"
                             {
                Exp* exp = dynamic_cast<Exp*>(yyvsp[-1]);

                if ((!exp->is_const && !table_stack.entryExists(exp->text))) {
                    output::errorUndef(yylineno, exp->text);
                    exit(1);
                }
                table_stack.getEntry(yyvsp[-3]->text);

                Entry entry;
                if (table_stack.entryExists(yyvsp[-3]->text)) {
                    entry = table_stack.getEntry(yyvsp[-3]->text);
                } else {
                    output::errorUndef(yylineno, yyvsp[-3]->text);
                    exit(1);
                }

                if (exp->type != "INT" && exp->type != "BYTE" && exp->type != "BOOL" && exp->type != "STRING" && exp->type != "VOID"){
                    output::errorUndef(yylineno, exp->text);
                    exit(1);
                }

                if (entry.type != exp->type && !(entry.type == "INT" && exp->type == "BYTE")) {
                    output::errorMismatch(yylineno);
                    exit(1);
                }

                std::string src = handleExp(exp);
                std::string target = generateLoad(yyvsp[-3]->text);
                generateStore(src, target);

                table_stack.entryChangeVal(yyvsp[-3]->text, exp->val);
            }
#line 1293 "parser.tab.cpp"
    break;

  case 10: /* Statement: Call SC  */
#line 115 "parser.ypp"
                    {}
#line 1299 "parser.tab.cpp"
    break;

  case 11: /* Statement: RETURN SC  */
#line 116 "parser.ypp"
                      {}
#line 1305 "parser.tab.cpp"
    break;

  case 13: /* $@2: %empty  */
#line 118 "parser.ypp"
                                                  { table_stack.addNewTable(); }
#line 1311 "parser.tab.cpp"
    break;

  case 14: /* Statement: IF LPAREN M1 RPAREN Statement M2 ELSE $@2 Statement  */
#line 118 "parser.ypp"
                                                                                           { table_stack.removeTopTable(); }
#line 1317 "parser.tab.cpp"
    break;

  case 15: /* $@3: %empty  */
#line 119 "parser.ypp"
                                    {
                Exp* exp = dynamic_cast<Exp*>(yyvsp[-1]);
                if ((!exp->is_const && !table_stack.entryExists(exp->text))) {
                    output::errorUndef(yylineno, exp->text);
                    exit(1);
                }
                if (exp->type != "BOOL") {
                    output::errorMismatch(yylineno);
                    exit(1);
                }
                table_stack.addNewTable();
                table_stack.addToTopTable(Entry("WHILE", "WHILE"), true);
            }
#line 1335 "parser.tab.cpp"
    break;

  case 16: /* Statement: WHILE LPAREN Exp RPAREN $@3 Statement  */
#line 131 "parser.ypp"
                        {table_stack.removeTopTable(); }
#line 1341 "parser.tab.cpp"
    break;

  case 17: /* Statement: BREAK SC  */
#line 132 "parser.ypp"
                     { if (!table_stack.entryExists("WHILE")) { output::errorUnexpectedBreak(yylineno); exit(1); } }
#line 1347 "parser.tab.cpp"
    break;

  case 18: /* Statement: CONTINUE SC  */
#line 133 "parser.ypp"
                        { if (!table_stack.entryExists("WHILE")) { output::errorUnexpectedContinue(yylineno); exit(1); } }
#line 1353 "parser.tab.cpp"
    break;

  case 19: /* Statement: SC  */
#line 134 "parser.ypp"
               {output::errorSyn(yylineno); exit(1);}
#line 1359 "parser.tab.cpp"
    break;

  case 20: /* Call: ID LPAREN Exp RPAREN  */
#line 137 "parser.ypp"
                            {
            Exp* exp = dynamic_cast<Exp*>(yyvsp[-1]);
            if (!exp->is_const && !table_stack.entryExists(exp->text)) {
                output::errorUndef(yylineno, exp->text);
                exit(1);
            }

            std::string type = verifyFunc(yyvsp[-3]->text, exp->type, yylineno);

            if (yyvsp[-3]->text == "print") {
                generatePrintCode(exp->text, exp->reg);
                yyval = new Call("", type, "",0, true);
            } else if (yyvsp[-3]->text == "printi") {
                std::string reg = handleExp(exp);
                generatePrintiCode(reg);
                yyval = new Call("", type, "",0, true);
            } else if (yyvsp[-3]->text == "readi") {
                std::string reg = handleExp(exp);
                std::string ret = generateReadiCode(reg);
                yyval = new Call("", type, ret ,exp->val, true);
            }
        }
#line 1386 "parser.tab.cpp"
    break;

  case 21: /* Type: INT  */
#line 160 "parser.ypp"
           { yyval = new Type("INT");}
#line 1392 "parser.tab.cpp"
    break;

  case 22: /* Type: BOOL  */
#line 161 "parser.ypp"
            { yyval = new Type("BOOL"); }
#line 1398 "parser.tab.cpp"
    break;

  case 23: /* Type: BYTE  */
#line 162 "parser.ypp"
            { yyval = new Type("BYTE"); }
#line 1404 "parser.tab.cpp"
    break;

  case 24: /* Exp: LPAREN Exp RPAREN  */
#line 165 "parser.ypp"
                        {
            Exp* exp = dynamic_cast<Exp*>(yyvsp[-1]);
            if (!exp->is_const && !table_stack.entryExists(exp->text)) {
                output::errorUndef(yylineno, exp->text);
                exit(1);
            }
            yyval = new Exp(exp->text, exp->type, exp->reg, exp->val, exp->is_const);
            globalExp = dynamic_cast<Exp*>(yyval);
        }
#line 1418 "parser.tab.cpp"
    break;

  case 25: /* Exp: Exp BINOP_MULT Exp  */
#line 174 "parser.ypp"
                         {
            Exp* exp1 = dynamic_cast<Exp*>(yyvsp[-2]);
            Exp* exp2 = dynamic_cast<Exp*>(yyvsp[0]);
            if (!exp1->is_const && !table_stack.entryExists(exp1->text)) {
                output::errorUndef(yylineno, exp1->text);
                exit(1);
            }
            if (!exp2->is_const && !table_stack.entryExists(exp2->text)) {
                output::errorUndef(yylineno, exp2->text);
                exit(1);
            }
            std::string type = verifyBinop(exp1->type, exp2->type, yylineno);
            int val = calcBinop(exp1->type, exp2->type, exp1->val, exp2->val, yyvsp[-1]->text, yylineno);
            yyval = new Exp("", type, "" , val, true);
            generateBinopCode(dynamic_cast<Exp*>(yyval), handleExp(exp1), handleExp(exp2), yyvsp[-1]->text);
            globalExp = dynamic_cast<Exp*>(yyval);
        }
#line 1440 "parser.tab.cpp"
    break;

  case 26: /* Exp: Exp BINOP_ADD Exp  */
#line 191 "parser.ypp"
                        {
            Exp* exp1 = dynamic_cast<Exp*>(yyvsp[-2]);
            Exp* exp2 = dynamic_cast<Exp*>(yyvsp[0]);
            if (!exp1->is_const && !table_stack.entryExists(exp1->text)) {
                output::errorUndef(yylineno, exp1->text);
                exit(1);
            }
            if (!exp2->is_const && !table_stack.entryExists(exp2->text)) {
                output::errorUndef(yylineno, exp2->text);
                exit(1);
            }
            std::string type = verifyBinop(exp1->type, exp2->type, yylineno);
            int val = calcBinop(exp1->type, exp2->type, exp1->val, exp2->val, yyvsp[-1]->text, yylineno);
            yyval = new Exp("", type, "", val, true);
            generateBinopCode(dynamic_cast<Exp*>(yyval), handleExp(exp1), handleExp(exp2), yyvsp[-1]->text);
            globalExp = dynamic_cast<Exp*>(yyval);
        }
#line 1462 "parser.tab.cpp"
    break;

  case 27: /* Exp: ID  */
#line 208 "parser.ypp"
         {
        if (table_stack.entryExists(yyvsp[0]->text)) {
            Entry entry = table_stack.getEntry(yyvsp[0]->text);
            yyval = new Exp(yyvsp[0]->text, entry.type, "",entry.val, false);
        } else
            yyval = new Exp(yyvsp[0]->text, "", "",0, false);
        globalExp = dynamic_cast<Exp*>(yyval);
        }
#line 1475 "parser.tab.cpp"
    break;

  case 28: /* Exp: Call  */
#line 216 "parser.ypp"
           {
         Call* call = dynamic_cast<Call*>(yyvsp[0]);
         yyval = new Exp(call->text, call->type, call->reg ,call->val, call->is_const);
         globalExp = dynamic_cast<Exp*>(yyval);
         }
#line 1485 "parser.tab.cpp"
    break;

  case 29: /* Exp: NUM  */
#line 221 "parser.ypp"
          {
        int value = std::stoi(yyvsp[0]->text);
        yyval = new Exp(yyvsp[0]->text, "INT", "",value, true);
        generateNumCode(dynamic_cast<Exp*>(yyval));
        globalExp = dynamic_cast<Exp*>(yyval);
        }
#line 1496 "parser.tab.cpp"
    break;

  case 30: /* Exp: NUM B  */
#line 227 "parser.ypp"
            {
        int value = std::stoi(yyvsp[-1]->text) & 255;
        yyval = new Exp(yyvsp[-1]->text, "BYTE","", value, true);
        generateNumByteCode(dynamic_cast<Exp*>(yyval));
        globalExp = dynamic_cast<Exp*>(yyval);
        }
#line 1507 "parser.tab.cpp"
    break;

  case 31: /* Exp: STRING  */
#line 233 "parser.ypp"
             {
        std::string fixed_string = yyvsp[0]->text;
        fixed_string.erase(0, 1);
        fixed_string.erase(fixed_string.size() - 1, 1);

        std::string global_string = generateGlobalString(fixed_string);
        yyval = new Exp(fixed_string, "STRING", global_string, 0, true);
        globalExp = dynamic_cast<Exp*>(yyval);
        }
#line 1521 "parser.tab.cpp"
    break;

  case 32: /* Exp: TRUE  */
#line 242 "parser.ypp"
           {
        yyval = new Exp("", "BOOL", "",1, true);
        generateTrueCode(dynamic_cast<Exp*>(yyval));
        globalExp = dynamic_cast<Exp*>(yyval);
    }
#line 1531 "parser.tab.cpp"
    break;

  case 33: /* Exp: FALSE  */
#line 247 "parser.ypp"
            {
        yyval = new Exp("", "BOOL", "",0, true);
        generateFalseCode(dynamic_cast<Exp*>(yyval));
        globalExp = dynamic_cast<Exp*>(yyval);
        }
#line 1541 "parser.tab.cpp"
    break;

  case 34: /* Exp: NOT Exp  */
#line 252 "parser.ypp"
              {
            Exp* exp = dynamic_cast<Exp*>(yyvsp[0]);
            if (!exp->is_const && !table_stack.entryExists(exp->text)) {
                output::errorUndef(yylineno, exp->text);
                exit(1);
            }
            if (exp->type != "BOOL") {
                output::errorMismatch(yylineno);
                exit(1);
            }
            yyval = new Exp("", "BOOL", "",~exp->val, true);
            generateNotCode(dynamic_cast<Exp*>(yyval), handleExp(exp));
            globalExp = dynamic_cast<Exp*>(yyval);
        }
#line 1560 "parser.tab.cpp"
    break;

  case 35: /* Exp: Exp AND AND_MARKER Exp  */
#line 266 "parser.ypp"
                             {
            BoolAndOperation* exp1 = dynamic_cast<BoolAndOperation*>(yyvsp[-1]);
            Exp* exp2 = dynamic_cast<Exp*>(yyvsp[0]);
            if (!exp1->is_const && !table_stack.entryExists(exp1->text)) {
                output::errorUndef(yylineno, exp1->text);
                exit(1);
            }
            if (!exp2->is_const && !table_stack.entryExists(exp2->text)) {
                output::errorUndef(yylineno, exp2->text);
                exit(1);
            }

            if (exp1->type != "BOOL") {
                output::errorMismatch(yylineno);
                exit(1);
            }
            if (exp2->type != "BOOL") {
                output::errorMismatch(yylineno);
                exit(1);
            }
            yyval = new Exp("", "BOOL", exp1->finalizeOperation(exp2) ,exp1->val & exp2->val, true);
            globalExp = dynamic_cast<Exp*>(yyval);
            }
#line 1588 "parser.tab.cpp"
    break;

  case 36: /* Exp: Exp OR OR_MARKER Exp  */
#line 289 "parser.ypp"
                           {
            BoolOrOperation* exp1 = dynamic_cast<BoolOrOperation*>(yyvsp[-1]);
            Exp* exp2 = dynamic_cast<Exp*>(yyvsp[0]);

            if (!exp1->is_const && !table_stack.entryExists(exp1->text)) {
                output::errorUndef(yylineno, exp1->text);
                exit(1);
            }

            if (!exp2->is_const && !table_stack.entryExists(exp2->text)) {
                output::errorUndef(yylineno, exp2->text);
                exit(1);
            }

            if (exp1->type != "BOOL") {
                output::errorMismatch(yylineno);
                exit(1);
            }

            if (exp2->type != "BOOL") {
                output::errorMismatch(yylineno);
                exit(1);
            }

            yyval = new Exp("", "BOOL", exp1->finalizeOperation(exp2), exp1->val | exp2->val, true);
            globalExp = dynamic_cast<Exp*>(yyval);

        }
#line 1621 "parser.tab.cpp"
    break;

  case 37: /* Exp: Exp RELOP_EQ Exp  */
#line 317 "parser.ypp"
                       {
        Exp* exp1 = dynamic_cast<Exp*>(yyvsp[-2]);
            Exp* exp2 = dynamic_cast<Exp*>(yyvsp[0]);

            if (!exp1->is_const && !table_stack.entryExists(exp1->text)) {
                output::errorUndef(yylineno, exp1->text);
                exit(1);
            }

            if (!exp2->is_const && !table_stack.entryExists(exp2->text)) {
                output::errorUndef(yylineno, exp2->text);
                exit(1);
            }

            verifyNumeric(exp1->type, exp2->type, yylineno);
            yyval = new Exp("", "BOOL", "", 0, true);
            globalExp = dynamic_cast<Exp*>(yyval);
        }
#line 1644 "parser.tab.cpp"
    break;

  case 38: /* Exp: Exp RELOP_REL Exp  */
#line 335 "parser.ypp"
                        {
            Exp* exp1 = dynamic_cast<Exp*>(yyvsp[-2]);
            Exp* exp2 = dynamic_cast<Exp*>(yyvsp[0]);

            if (!exp1->is_const && !table_stack.entryExists(exp1->text)) {
                output::errorUndef(yylineno, exp1->text);
                exit(1);
            }

            if (!exp2->is_const && !table_stack.entryExists(exp2->text)) {
                output::errorUndef(yylineno, exp2->text);
                exit(1);
            }
            verifyNumeric(exp1->type, exp2->type, yylineno);
            yyval = new Exp("", "BOOL", "",0, true);
            globalExp = dynamic_cast<Exp*>(yyval);
        }
#line 1666 "parser.tab.cpp"
    break;

  case 39: /* Exp: LPAREN Type RPAREN Exp  */
#line 352 "parser.ypp"
                             {
            Exp* exp = dynamic_cast<Exp*>(yyvsp[0]);
            int val = exp->val;

            if (!exp->is_const && !table_stack.entryExists(exp->text)) {
                output::errorUndef(yylineno, exp->text);
                exit(1);
            }
            verifyNumeric(yyvsp[-2]->text, exp->type, yylineno);
            if (yyvsp[-2]->text == "BYTE" && exp->val > 255) {
                val = val & 255;
            }
            yyval = new Exp("", yyvsp[-2]->text,"", val, true);

            if (yyvsp[-2]->text == "BYTE")
                generateNumByteCode(exp);
            else
                generateNumCode(exp);
            globalExp = dynamic_cast<Exp*>(yyval);
        }
#line 1691 "parser.tab.cpp"
    break;

  case 40: /* M1: Exp  */
#line 374 "parser.ypp"
            {
                    Exp* exp = dynamic_cast<Exp*>(yyvsp[0]);
                    if ((!exp->is_const && !table_stack.entryExists(exp->text)) || table_stack.entryExists(exp->text)) {
                        output::errorUndef(yylineno, exp->text);
                        exit(1);
                    }
                    if (exp->type != "BOOL") {
                        output::errorMismatch(yylineno);
                        exit(1);
                    }
                    table_stack.addNewTable();
                    yyval = new Exp(exp->text, exp->type, "",exp->val, exp->is_const);
            }
#line 1709 "parser.tab.cpp"
    break;

  case 41: /* M2: %empty  */
#line 389 "parser.ypp"
     { table_stack.removeTopTable(); }
#line 1715 "parser.tab.cpp"
    break;

  case 42: /* OR_MARKER: %empty  */
#line 392 "parser.ypp"
            {
        BoolOrOperation *orOp = new BoolOrOperation(*globalExp);
        orOp->emitInitialPart();
        yyval = orOp;
    }
#line 1725 "parser.tab.cpp"
    break;

  case 43: /* AND_MARKER: %empty  */
#line 398 "parser.ypp"
             {
        BoolAndOperation *andOp = new BoolAndOperation(*globalExp);
        andOp->emitInitialPart();
        yyval = andOp;
    }
#line 1735 "parser.tab.cpp"
    break;


#line 1739 "parser.tab.cpp"

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
  ++yynerrs;

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
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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

#line 405 "parser.ypp"


int main()
{
    int res = yyparse();
    return res;
}

int yyerror(const char* message)
{
    output::errorSyn(yylineno);
    exit(0);
}
