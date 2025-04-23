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
#line 1 "yacc.y"

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <memory>
#include <string>
#include <sstream>
#include "ast.h"

extern int yylex();
extern int yyparse();
extern FILE* yyin;
void yyerror(const char* s);

// 语法分析完成后的AST根节点
std::unique_ptr<CompUnitAST> root;


#line 91 "yacc.tab.c"

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

#include "yacc.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_CONST = 3,                      /* CONST  */
  YYSYMBOL_INT = 4,                        /* INT  */
  YYSYMBOL_RETURN = 5,                     /* RETURN  */
  YYSYMBOL_PRINTF = 6,                     /* PRINTF  */
  YYSYMBOL_GETINT = 7,                     /* GETINT  */
  YYSYMBOL_MAIN = 8,                       /* MAIN  */
  YYSYMBOL_BREAK = 9,                      /* BREAK  */
  YYSYMBOL_CONTINUE = 10,                  /* CONTINUE  */
  YYSYMBOL_IF = 11,                        /* IF  */
  YYSYMBOL_ELSE = 12,                      /* ELSE  */
  YYSYMBOL_WHILE = 13,                     /* WHILE  */
  YYSYMBOL_VOID = 14,                      /* VOID  */
  YYSYMBOL_ASSIGN = 15,                    /* ASSIGN  */
  YYSYMBOL_LBRACE = 16,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 17,                    /* RBRACE  */
  YYSYMBOL_LPARENT = 18,                   /* LPARENT  */
  YYSYMBOL_RPARENT = 19,                   /* RPARENT  */
  YYSYMBOL_SEMICN = 20,                    /* SEMICN  */
  YYSYMBOL_COMMA = 21,                     /* COMMA  */
  YYSYMBOL_LBRACK = 22,                    /* LBRACK  */
  YYSYMBOL_RBRACK = 23,                    /* RBRACK  */
  YYSYMBOL_NOT = 24,                       /* NOT  */
  YYSYMBOL_AND = 25,                       /* AND  */
  YYSYMBOL_OR = 26,                        /* OR  */
  YYSYMBOL_PLUS = 27,                      /* PLUS  */
  YYSYMBOL_MINU = 28,                      /* MINU  */
  YYSYMBOL_MULT = 29,                      /* MULT  */
  YYSYMBOL_DIV = 30,                       /* DIV  */
  YYSYMBOL_MOD = 31,                       /* MOD  */
  YYSYMBOL_LSS = 32,                       /* LSS  */
  YYSYMBOL_LEQ = 33,                       /* LEQ  */
  YYSYMBOL_GRE = 34,                       /* GRE  */
  YYSYMBOL_GEQ = 35,                       /* GEQ  */
  YYSYMBOL_EQL = 36,                       /* EQL  */
  YYSYMBOL_NEQ = 37,                       /* NEQ  */
  YYSYMBOL_INT_CONST = 38,                 /* INT_CONST  */
  YYSYMBOL_IDENT = 39,                     /* IDENT  */
  YYSYMBOL_STR_CONST = 40,                 /* STR_CONST  */
  YYSYMBOL_UNARY = 41,                     /* UNARY  */
  YYSYMBOL_YYACCEPT = 42,                  /* $accept  */
  YYSYMBOL_CompUnit = 43,                  /* CompUnit  */
  YYSYMBOL_Decl = 44,                      /* Decl  */
  YYSYMBOL_ConstDecl = 45,                 /* ConstDecl  */
  YYSYMBOL_VarDecl = 46,                   /* VarDecl  */
  YYSYMBOL_FuncDef = 47,                   /* FuncDef  */
  YYSYMBOL_FuncFParams = 48,               /* FuncFParams  */
  YYSYMBOL_MainFuncDef = 49,               /* MainFuncDef  */
  YYSYMBOL_Block = 50,                     /* Block  */
  YYSYMBOL_BlockItems = 51,                /* BlockItems  */
  YYSYMBOL_BlockItem = 52,                 /* BlockItem  */
  YYSYMBOL_Stmt = 53,                      /* Stmt  */
  YYSYMBOL_Exp = 54,                       /* Exp  */
  YYSYMBOL_Cond = 55,                      /* Cond  */
  YYSYMBOL_LVal = 56,                      /* LVal  */
  YYSYMBOL_PrimaryExp = 57,                /* PrimaryExp  */
  YYSYMBOL_Number = 58,                    /* Number  */
  YYSYMBOL_UnaryExp = 59,                  /* UnaryExp  */
  YYSYMBOL_FuncRParams = 60,               /* FuncRParams  */
  YYSYMBOL_MulExp = 61,                    /* MulExp  */
  YYSYMBOL_AddExp = 62,                    /* AddExp  */
  YYSYMBOL_RelExp = 63,                    /* RelExp  */
  YYSYMBOL_EqExp = 64,                     /* EqExp  */
  YYSYMBOL_LAndExp = 65,                   /* LAndExp  */
  YYSYMBOL_LOrExp = 66,                    /* LOrExp  */
  YYSYMBOL_ConstExp = 67                   /* ConstExp  */
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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   184

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  142

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   296


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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    69,    69,    75,    80,    86,    91,    98,   108,   111,
     118,   131,   139,   152,   161,   175,   182,   192,   196,   204,
     207,   224,   229,   238,   245,   251,   257,   262,   268,   276,
     284,   291,   296,   301,   307,   312,   319,   331,   338,   345,
     355,   358,   361,   368,   377,   380,   386,   400,   406,   412,
     422,   427,   436,   439,   446,   453,   464,   467,   474,   485,
     488,   495,   502,   509,   520,   523,   530,   541,   544,   555,
     558,   569
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
  "\"end of file\"", "error", "\"invalid token\"", "CONST", "INT",
  "RETURN", "PRINTF", "GETINT", "MAIN", "BREAK", "CONTINUE", "IF", "ELSE",
  "WHILE", "VOID", "ASSIGN", "LBRACE", "RBRACE", "LPARENT", "RPARENT",
  "SEMICN", "COMMA", "LBRACK", "RBRACK", "NOT", "AND", "OR", "PLUS",
  "MINU", "MULT", "DIV", "MOD", "LSS", "LEQ", "GRE", "GEQ", "EQL", "NEQ",
  "INT_CONST", "IDENT", "STR_CONST", "UNARY", "$accept", "CompUnit",
  "Decl", "ConstDecl", "VarDecl", "FuncDef", "FuncFParams", "MainFuncDef",
  "Block", "BlockItems", "BlockItem", "Stmt", "Exp", "Cond", "LVal",
  "PrimaryExp", "Number", "UnaryExp", "FuncRParams", "MulExp", "AddExp",
  "RelExp", "EqExp", "LAndExp", "LOrExp", "ConstExp", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-98)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      41,     5,    -7,    30,   -98,   -98,   -98,   -98,   -98,   -37,
       8,    48,   -98,   -98,   -98,   -98,    21,    -3,   144,    19,
     -98,   144,    46,   144,   144,   144,   144,   -98,    49,    61,
     -98,   -98,   -98,   -98,    42,    24,    47,    46,    94,    24,
      98,     1,   -98,    95,   -98,   -98,   -98,   126,   -98,   144,
     144,   144,   144,   144,   -98,   -98,    46,   -98,    81,   128,
     103,   105,   110,   106,   111,   -98,   -98,   -98,   -98,    99,
     -98,   -98,   116,   124,   -98,   -98,   -98,    39,   -98,   -98,
     -98,    42,    42,   -98,     7,   -98,   120,   101,   -98,   -98,
     144,   144,   -98,   -98,   -98,   104,   -98,   144,   -98,    63,
     130,    24,    45,    52,   122,   125,   138,   143,   149,   -98,
     150,   144,    37,   144,   144,   144,   144,   144,   144,   144,
     144,    37,   154,   -98,   -98,   155,   151,    24,    24,    24,
      24,    45,    45,    52,   122,   -98,   156,   157,    37,   -98,
     -98,   -98
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     2,     8,     9,     4,     6,     0,
       0,     0,     1,     3,     5,     7,     0,     0,     0,     0,
      11,     0,     0,     0,     0,     0,     0,    43,    39,     0,
      41,    44,    42,    52,    56,    37,     0,     0,     0,    71,
       0,     0,    16,     0,    49,    47,    48,     0,    12,     0,
       0,     0,     0,     0,    15,    13,     0,    10,     0,     0,
       0,     0,     0,     0,     0,    18,    26,    21,    27,     0,
      19,    22,     0,    41,    40,    45,    50,     0,    53,    54,
      55,    57,    58,    14,     0,    34,     0,     0,    31,    32,
       0,     0,    17,    20,    25,     0,    46,     0,    33,     0,
       0,    59,    64,    67,    69,    38,     0,     0,     0,    51,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    23,    35,     0,    28,    60,    62,    61,
      63,    65,    66,    68,    70,    30,     0,     0,     0,    24,
      36,    29
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -98,   -98,    56,   -98,   -98,   172,   -98,   175,    -2,   -98,
     112,   -97,   -10,    88,   -38,   -98,   -98,   109,   -98,    38,
     -21,   -11,    65,    60,   -98,   -98
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,    67,     5,     6,     7,    38,     8,    68,    69,
      70,    71,    72,   100,    30,    31,    32,    33,    77,    34,
      35,   102,   103,   104,   105,    40
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      39,    10,    16,    73,     1,    58,    59,    60,    29,     9,
      61,    62,    63,    43,    64,   126,    22,    41,    65,    23,
      42,    66,    18,    36,   135,    24,    17,    20,    25,    26,
      12,    73,    11,     1,     2,    55,    21,    76,    37,    27,
      28,   141,    59,    60,     1,     2,    61,    62,    63,    86,
      64,    52,    53,    41,    83,    23,     4,    66,    96,    13,
      97,    24,    41,    18,    25,    26,    19,    47,    20,   101,
     101,    49,    50,    51,    73,    27,    28,   113,   114,   115,
     116,    48,   110,    73,   111,   108,    54,   109,   117,   118,
      81,    82,   127,   128,   129,   130,   101,   101,   101,   101,
      73,   125,     1,    58,    59,    60,   131,   132,    61,    62,
      63,   107,    64,    56,    74,    41,    92,    23,    57,    66,
      84,    87,    23,    24,    90,    88,    25,    26,    24,    91,
      89,    25,    26,    44,    45,    46,    94,    27,    28,    95,
      98,    99,    27,    28,    23,    75,    23,   119,    85,   112,
      24,   120,    24,    25,    26,    25,    26,   121,    78,    79,
      80,   122,    23,   138,    27,    28,    27,    28,    24,   123,
     124,    25,    26,   136,   137,    14,   139,   140,    15,   106,
     134,    93,    27,    28,   133
};

static const yytype_uint8 yycheck[] =
{
      21,     8,    39,    41,     3,     4,     5,     6,    18,     4,
       9,    10,    11,    23,    13,   112,    19,    16,    17,    18,
      22,    20,    15,     4,   121,    24,    18,    20,    27,    28,
       0,    69,    39,     3,     4,    37,    15,    47,    19,    38,
      39,   138,     5,     6,     3,     4,     9,    10,    11,    59,
      13,    27,    28,    16,    56,    18,     0,    20,    19,     3,
      21,    24,    16,    15,    27,    28,    18,    18,    20,    90,
      91,    29,    30,    31,   112,    38,    39,    32,    33,    34,
      35,    20,    19,   121,    21,    95,    39,    97,    36,    37,
      52,    53,   113,   114,   115,   116,   117,   118,   119,   120,
     138,   111,     3,     4,     5,     6,   117,   118,     9,    10,
      11,     7,    13,    19,    19,    16,    17,    18,    20,    20,
      39,    18,    18,    24,    18,    20,    27,    28,    24,    18,
      20,    27,    28,    24,    25,    26,    20,    38,    39,    15,
      20,    40,    38,    39,    18,    19,    18,    25,    20,    19,
      24,    26,    24,    27,    28,    27,    28,    19,    49,    50,
      51,    18,    18,    12,    38,    39,    38,    39,    24,    20,
      20,    27,    28,    19,    19,     3,    20,    20,     3,    91,
     120,    69,    38,    39,   119
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,    43,    44,    45,    46,    47,    49,     4,
       8,    39,     0,    44,    47,    49,    39,    18,    15,    18,
      20,    15,    19,    18,    24,    27,    28,    38,    39,    54,
      56,    57,    58,    59,    61,    62,     4,    19,    48,    62,
      67,    16,    50,    54,    59,    59,    59,    18,    20,    29,
      30,    31,    27,    28,    39,    50,    19,    20,     4,     5,
       6,     9,    10,    11,    13,    17,    20,    44,    50,    51,
      52,    53,    54,    56,    19,    19,    54,    60,    59,    59,
      59,    61,    61,    50,    39,    20,    54,    18,    20,    20,
      18,    18,    17,    52,    20,    15,    19,    21,    20,    40,
      55,    62,    63,    64,    65,    66,    55,     7,    54,    54,
      19,    21,    19,    32,    33,    34,    35,    36,    37,    25,
      26,    19,    18,    20,    20,    54,    53,    62,    62,    62,
      62,    63,    63,    64,    65,    53,    19,    19,    12,    20,
      20,    53
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    43,    43,    43,    43,    43,    44,    44,
      45,    46,    46,    47,    47,    48,    49,    50,    50,    51,
      51,    52,    52,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    54,    55,    56,
      57,    57,    57,    58,    59,    59,    59,    59,    59,    59,
      60,    60,    61,    61,    61,    61,    62,    62,    62,    63,
      63,    63,    63,    63,    64,    64,    64,    65,    65,    66,
      66,    67
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     1,     2,     1,     1,
       6,     3,     5,     5,     6,     2,     5,     3,     2,     1,
       2,     1,     1,     4,     6,     2,     1,     1,     5,     7,
       5,     2,     2,     3,     2,     5,     7,     1,     1,     1,
       3,     1,     1,     1,     1,     3,     4,     2,     2,     2,
       1,     3,     1,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     1,
       3,     1
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


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

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

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


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

  YYLOCATION_PRINT (yyo, yylocationp);
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
  case 2: /* CompUnit: Decl  */
#line 69 "yacc.y"
           {
        auto ast = new CompUnitAST();
        ast->global_decls.emplace_back(std::unique_ptr<DeclAST>(static_cast<DeclAST*>((yyvsp[0].decl_val))));
        root.reset(ast);
        (yyval.ast_val) = ast;
    }
#line 1638 "yacc.tab.c"
    break;

  case 3: /* CompUnit: CompUnit Decl  */
#line 75 "yacc.y"
                    {
        auto ast = static_cast<CompUnitAST*>((yyvsp[-1].ast_val));
        ast->global_decls.emplace_back(std::unique_ptr<DeclAST>(static_cast<DeclAST*>((yyvsp[0].decl_val))));
        (yyval.ast_val) = ast;
    }
#line 1648 "yacc.tab.c"
    break;

  case 4: /* CompUnit: FuncDef  */
#line 80 "yacc.y"
              {
        auto ast = new CompUnitAST();
        ast->func_defs.emplace_back(std::unique_ptr<FuncDefAST>(static_cast<FuncDefAST*>((yyvsp[0].ast_val))));
        root.reset(ast);
        (yyval.ast_val) = ast;
    }
#line 1659 "yacc.tab.c"
    break;

  case 5: /* CompUnit: CompUnit FuncDef  */
#line 86 "yacc.y"
                       {
        auto ast = static_cast<CompUnitAST*>((yyvsp[-1].ast_val));
        ast->func_defs.emplace_back(std::unique_ptr<FuncDefAST>(static_cast<FuncDefAST*>((yyvsp[0].ast_val))));
        (yyval.ast_val) = ast;
    }
#line 1669 "yacc.tab.c"
    break;

  case 6: /* CompUnit: MainFuncDef  */
#line 91 "yacc.y"
                  {
        auto ast = new CompUnitAST();
        ast->main_func_def.reset(static_cast<MainFuncDefAST*>((yyvsp[0].ast_val)));
        root.reset(ast);
        (yyval.ast_val) = ast;
        printf("<CompUnit>\n");
    }
#line 1681 "yacc.tab.c"
    break;

  case 7: /* CompUnit: CompUnit MainFuncDef  */
#line 98 "yacc.y"
                           {
        auto ast = static_cast<CompUnitAST*>((yyvsp[-1].ast_val));
        ast->main_func_def.reset(static_cast<MainFuncDefAST*>((yyvsp[0].ast_val)));
        (yyval.ast_val) = ast;
        printf("<CompUnit>\n");
    }
#line 1692 "yacc.tab.c"
    break;

  case 8: /* Decl: ConstDecl  */
#line 108 "yacc.y"
                {
        (yyval.decl_val) = (yyvsp[0].decl_val);
    }
#line 1700 "yacc.tab.c"
    break;

  case 9: /* Decl: VarDecl  */
#line 111 "yacc.y"
              {
        (yyval.decl_val) = (yyvsp[0].decl_val);
    }
#line 1708 "yacc.tab.c"
    break;

  case 10: /* ConstDecl: CONST INT IDENT ASSIGN ConstExp SEMICN  */
#line 118 "yacc.y"
                                             {
        auto ast = new ConstDeclAST();
        ast->type = "int";
        ast->ident = (yyvsp[-3].str_val);
        ast->init_val.reset(static_cast<ExpAST*>((yyvsp[-1].exp_val)));
        free((yyvsp[-3].str_val));
        printf("<ConstDecl>\n");
        (yyval.decl_val) = ast;
    }
#line 1722 "yacc.tab.c"
    break;

  case 11: /* VarDecl: INT IDENT SEMICN  */
#line 131 "yacc.y"
                       {
        auto ast = new VarDeclAST();
        ast->type = "int";
        ast->ident = (yyvsp[-1].str_val);
        free((yyvsp[-1].str_val));
        printf("<VarDecl>\n");
        (yyval.decl_val) = ast;
    }
#line 1735 "yacc.tab.c"
    break;

  case 12: /* VarDecl: INT IDENT ASSIGN Exp SEMICN  */
#line 139 "yacc.y"
                                  {
        auto ast = new VarDeclAST();
        ast->type = "int";
        ast->ident = (yyvsp[-3].str_val);
        ast->init_val.reset(static_cast<ExpAST*>((yyvsp[-1].exp_val)));
        free((yyvsp[-3].str_val));
        printf("<VarDecl>\n");
        (yyval.decl_val) = ast;
    }
#line 1749 "yacc.tab.c"
    break;

  case 13: /* FuncDef: INT IDENT LPARENT RPARENT Block  */
#line 152 "yacc.y"
                                      {
        auto ast = new FuncDefAST();
        ast->return_type = "int";
        ast->func_name = (yyvsp[-3].str_val);
        ast->body.reset((yyvsp[0].block_val));
        free((yyvsp[-3].str_val));
        printf("<FuncDef>\n");
        (yyval.ast_val) = ast;
    }
#line 1763 "yacc.tab.c"
    break;

  case 14: /* FuncDef: INT IDENT LPARENT FuncFParams RPARENT Block  */
#line 161 "yacc.y"
                                                  {
        auto ast = new FuncDefAST();
        ast->return_type = "int";
        ast->func_name = (yyvsp[-4].str_val);
        // 处理参数...（这里简化处理）
        ast->body.reset((yyvsp[0].block_val));
        free((yyvsp[-4].str_val));
        printf("<FuncDef>\n");
        (yyval.ast_val) = ast;
    }
#line 1778 "yacc.tab.c"
    break;

  case 15: /* FuncFParams: INT IDENT  */
#line 175 "yacc.y"
                {
        // 简单存储参数，不返回任何值
    }
#line 1786 "yacc.tab.c"
    break;

  case 16: /* MainFuncDef: INT MAIN LPARENT RPARENT Block  */
#line 182 "yacc.y"
                                     {
        auto ast = new MainFuncDefAST();
        ast->body.reset((yyvsp[0].block_val));
        printf("<MainFuncDef>\n");
        (yyval.ast_val) = ast;
    }
#line 1797 "yacc.tab.c"
    break;

  case 17: /* Block: LBRACE BlockItems RBRACE  */
#line 192 "yacc.y"
                               {
        (yyval.block_val) = (yyvsp[-1].block_val);
        printf("<Block>\n");
    }
#line 1806 "yacc.tab.c"
    break;

  case 18: /* Block: LBRACE RBRACE  */
#line 196 "yacc.y"
                    {
        auto ast = new BlockAST();
        printf("<Block>\n");
        (yyval.block_val) = ast;
    }
#line 1816 "yacc.tab.c"
    break;

  case 19: /* BlockItems: BlockItem  */
#line 204 "yacc.y"
                {
        (yyval.block_val) = (yyvsp[0].block_val);
    }
#line 1824 "yacc.tab.c"
    break;

  case 20: /* BlockItems: BlockItems BlockItem  */
#line 207 "yacc.y"
                           {
        auto block_items = (yyvsp[-1].block_val);
        auto block_item = static_cast<BlockAST*>((yyvsp[0].block_val));
        
        // 将$2中的items全部移动到$1中
        for (auto& item : block_item->items) {
            block_items->items.emplace_back(std::move(item));
        }
        
        // 释放已经移动内容的block_item
        delete block_item;
        
        (yyval.block_val) = block_items;
    }
#line 1843 "yacc.tab.c"
    break;

  case 21: /* BlockItem: Decl  */
#line 224 "yacc.y"
           {
        auto ast = new BlockAST();
        ast->items.emplace_back(std::unique_ptr<BaseAST>(static_cast<BaseAST*>((yyvsp[0].decl_val))));
        (yyval.block_val) = ast;
    }
#line 1853 "yacc.tab.c"
    break;

  case 22: /* BlockItem: Stmt  */
#line 229 "yacc.y"
           {
        auto ast = new BlockAST();
        ast->items.emplace_back(std::unique_ptr<BaseAST>(static_cast<BaseAST*>((yyvsp[0].stmt_val))));
        (yyval.block_val) = ast;
    }
#line 1863 "yacc.tab.c"
    break;

  case 23: /* Stmt: LVal ASSIGN Exp SEMICN  */
#line 238 "yacc.y"
                             {
        auto ast = new AssignStmtAST();
        ast->lval.reset(static_cast<LValAST*>((yyvsp[-3].exp_val)));
        ast->exp.reset(static_cast<ExpAST*>((yyvsp[-1].exp_val)));
        printf("<Stmt>\n");
        (yyval.stmt_val) = ast;
    }
#line 1875 "yacc.tab.c"
    break;

  case 24: /* Stmt: LVal ASSIGN GETINT LPARENT RPARENT SEMICN  */
#line 245 "yacc.y"
                                                {
        auto ast = new GetIntStmtAST();
        ast->lval.reset(static_cast<LValAST*>((yyvsp[-5].exp_val)));
        printf("<Stmt>\n");
        (yyval.stmt_val) = ast;
    }
#line 1886 "yacc.tab.c"
    break;

  case 25: /* Stmt: Exp SEMICN  */
#line 251 "yacc.y"
                 {
        auto ast = new ExprStmtAST();
        ast->exp.reset(static_cast<ExpAST*>((yyvsp[-1].exp_val)));
        printf("<Stmt>\n");
        (yyval.stmt_val) = ast;
    }
#line 1897 "yacc.tab.c"
    break;

  case 26: /* Stmt: SEMICN  */
#line 257 "yacc.y"
             {
        auto ast = new ExprStmtAST();
        printf("<Stmt>\n");
        (yyval.stmt_val) = ast;
    }
#line 1907 "yacc.tab.c"
    break;

  case 27: /* Stmt: Block  */
#line 262 "yacc.y"
            {
        auto ast = new ExprStmtAST();
        ast->exp = nullptr; // 使用空语句块
        printf("<Stmt>\n");
        (yyval.stmt_val) = ast;
    }
#line 1918 "yacc.tab.c"
    break;

  case 28: /* Stmt: IF LPARENT Cond RPARENT Stmt  */
#line 268 "yacc.y"
                                   {
        auto ast = new IfStmtAST();
        ast->cond.reset(static_cast<ExpAST*>((yyvsp[-2].exp_val)));
        ast->then_stmt.reset((yyvsp[0].stmt_val));
        ast->else_stmt = nullptr;
        printf("<Stmt>\n");
        (yyval.stmt_val) = ast;
    }
#line 1931 "yacc.tab.c"
    break;

  case 29: /* Stmt: IF LPARENT Cond RPARENT Stmt ELSE Stmt  */
#line 276 "yacc.y"
                                             {
        auto ast = new IfStmtAST();
        ast->cond.reset(static_cast<ExpAST*>((yyvsp[-4].exp_val)));
        ast->then_stmt.reset((yyvsp[-2].stmt_val));
        ast->else_stmt.reset((yyvsp[0].stmt_val));
        printf("<Stmt>\n");
        (yyval.stmt_val) = ast;
    }
#line 1944 "yacc.tab.c"
    break;

  case 30: /* Stmt: WHILE LPARENT Cond RPARENT Stmt  */
#line 284 "yacc.y"
                                      {
        auto ast = new WhileStmtAST();
        ast->cond.reset(static_cast<ExpAST*>((yyvsp[-2].exp_val)));
        ast->body.reset((yyvsp[0].stmt_val));
        printf("<Stmt>\n");
        (yyval.stmt_val) = ast;
    }
#line 1956 "yacc.tab.c"
    break;

  case 31: /* Stmt: BREAK SEMICN  */
#line 291 "yacc.y"
                   {
        auto ast = new BreakStmtAST();
        printf("<Stmt>\n");
        (yyval.stmt_val) = ast;
    }
#line 1966 "yacc.tab.c"
    break;

  case 32: /* Stmt: CONTINUE SEMICN  */
#line 296 "yacc.y"
                      {
        auto ast = new ContinueStmtAST();
        printf("<Stmt>\n");
        (yyval.stmt_val) = ast;
    }
#line 1976 "yacc.tab.c"
    break;

  case 33: /* Stmt: RETURN Exp SEMICN  */
#line 301 "yacc.y"
                        {
        auto ast = new ReturnStmtAST();
        ast->exp.reset(static_cast<ExpAST*>((yyvsp[-1].exp_val)));
        printf("<Stmt>\n");
        (yyval.stmt_val) = ast;
    }
#line 1987 "yacc.tab.c"
    break;

  case 34: /* Stmt: RETURN SEMICN  */
#line 307 "yacc.y"
                    {
        auto ast = new ReturnStmtAST();
        printf("<Stmt>\n");
        (yyval.stmt_val) = ast;
    }
#line 1997 "yacc.tab.c"
    break;

  case 35: /* Stmt: PRINTF LPARENT STR_CONST RPARENT SEMICN  */
#line 312 "yacc.y"
                                              {
        auto ast = new PrintfStmtAST();
        ast->format_string = (yyvsp[-2].str_val);
        free((yyvsp[-2].str_val));
        printf("<Stmt>\n");
        (yyval.stmt_val) = ast;
    }
#line 2009 "yacc.tab.c"
    break;

  case 36: /* Stmt: PRINTF LPARENT STR_CONST COMMA Exp RPARENT SEMICN  */
#line 319 "yacc.y"
                                                        {
        auto ast = new PrintfStmtAST();
        ast->format_string = (yyvsp[-4].str_val);
        ast->args.emplace_back(std::unique_ptr<ExpAST>(static_cast<ExpAST*>((yyvsp[-2].exp_val))));
        free((yyvsp[-4].str_val));
        printf("<Stmt>\n");
        (yyval.stmt_val) = ast;
    }
#line 2022 "yacc.tab.c"
    break;

  case 37: /* Exp: AddExp  */
#line 331 "yacc.y"
             {
        (yyval.exp_val) = (yyvsp[0].exp_val);
    }
#line 2030 "yacc.tab.c"
    break;

  case 38: /* Cond: LOrExp  */
#line 338 "yacc.y"
             {
        (yyval.exp_val) = (yyvsp[0].exp_val);
    }
#line 2038 "yacc.tab.c"
    break;

  case 39: /* LVal: IDENT  */
#line 345 "yacc.y"
            {
        auto ast = new LValAST();
        ast->ident = (yyvsp[0].str_val);
        free((yyvsp[0].str_val));
        (yyval.exp_val) = ast;
    }
#line 2049 "yacc.tab.c"
    break;

  case 40: /* PrimaryExp: LPARENT Exp RPARENT  */
#line 355 "yacc.y"
                          {
        (yyval.exp_val) = (yyvsp[-1].exp_val);
    }
#line 2057 "yacc.tab.c"
    break;

  case 41: /* PrimaryExp: LVal  */
#line 358 "yacc.y"
           {
        (yyval.exp_val) = (yyvsp[0].exp_val);
    }
#line 2065 "yacc.tab.c"
    break;

  case 42: /* PrimaryExp: Number  */
#line 361 "yacc.y"
             {
        (yyval.exp_val) = (yyvsp[0].exp_val);
    }
#line 2073 "yacc.tab.c"
    break;

  case 43: /* Number: INT_CONST  */
#line 368 "yacc.y"
                {
        auto ast = new NumberAST();
        ast->value = (yyvsp[0].int_val);
        (yyval.exp_val) = ast;
    }
#line 2083 "yacc.tab.c"
    break;

  case 44: /* UnaryExp: PrimaryExp  */
#line 377 "yacc.y"
                 {
        (yyval.exp_val) = (yyvsp[0].exp_val);
    }
#line 2091 "yacc.tab.c"
    break;

  case 45: /* UnaryExp: IDENT LPARENT RPARENT  */
#line 380 "yacc.y"
                            {
        auto ast = new FuncCallAST();
        ast->func_name = (yyvsp[-2].str_val);
        free((yyvsp[-2].str_val));
        (yyval.exp_val) = ast;
    }
#line 2102 "yacc.tab.c"
    break;

  case 46: /* UnaryExp: IDENT LPARENT FuncRParams RPARENT  */
#line 386 "yacc.y"
                                        {
        auto ast = new FuncCallAST();
        ast->func_name = (yyvsp[-3].str_val);
        
        // 将FuncRParams的参数提取出来
        auto func_params = dynamic_cast<FuncCallAST*>((yyvsp[-1].exp_val));
        if (func_params) {
            ast->args = std::move(func_params->args);
            delete func_params;
        }
        
        free((yyvsp[-3].str_val));
        (yyval.exp_val) = ast;
    }
#line 2121 "yacc.tab.c"
    break;

  case 47: /* UnaryExp: PLUS UnaryExp  */
#line 400 "yacc.y"
                                {
        auto ast = new UnaryExpAST();
        ast->op = UnaryExpAST::PLUS;
        ast->exp.reset(static_cast<ExpAST*>((yyvsp[0].exp_val)));
        (yyval.exp_val) = ast;
    }
#line 2132 "yacc.tab.c"
    break;

  case 48: /* UnaryExp: MINU UnaryExp  */
#line 406 "yacc.y"
                                {
        auto ast = new UnaryExpAST();
        ast->op = UnaryExpAST::MINUS;
        ast->exp.reset(static_cast<ExpAST*>((yyvsp[0].exp_val)));
        (yyval.exp_val) = ast;
    }
#line 2143 "yacc.tab.c"
    break;

  case 49: /* UnaryExp: NOT UnaryExp  */
#line 412 "yacc.y"
                               {
        auto ast = new UnaryExpAST();
        ast->op = UnaryExpAST::NOT;
        ast->exp.reset(static_cast<ExpAST*>((yyvsp[0].exp_val)));
        (yyval.exp_val) = ast;
    }
#line 2154 "yacc.tab.c"
    break;

  case 50: /* FuncRParams: Exp  */
#line 422 "yacc.y"
          {
        auto ast = new FuncCallAST();
        ast->args.emplace_back(std::unique_ptr<ExpAST>(static_cast<ExpAST*>((yyvsp[0].exp_val))));
        (yyval.exp_val) = ast;
    }
#line 2164 "yacc.tab.c"
    break;

  case 51: /* FuncRParams: FuncRParams COMMA Exp  */
#line 427 "yacc.y"
                            {
        auto ast = static_cast<FuncCallAST*>((yyvsp[-2].exp_val));
        ast->args.emplace_back(std::unique_ptr<ExpAST>(static_cast<ExpAST*>((yyvsp[0].exp_val))));
        (yyval.exp_val) = ast;
    }
#line 2174 "yacc.tab.c"
    break;

  case 52: /* MulExp: UnaryExp  */
#line 436 "yacc.y"
               {
        (yyval.exp_val) = (yyvsp[0].exp_val);
    }
#line 2182 "yacc.tab.c"
    break;

  case 53: /* MulExp: MulExp MULT UnaryExp  */
#line 439 "yacc.y"
                           {
        auto ast = new BinaryExpAST();
        ast->op = BinaryExpAST::MUL;
        ast->lhs.reset(static_cast<ExpAST*>((yyvsp[-2].exp_val)));
        ast->rhs.reset(static_cast<ExpAST*>((yyvsp[0].exp_val)));
        (yyval.exp_val) = ast;
    }
#line 2194 "yacc.tab.c"
    break;

  case 54: /* MulExp: MulExp DIV UnaryExp  */
#line 446 "yacc.y"
                          {
        auto ast = new BinaryExpAST();
        ast->op = BinaryExpAST::DIV;
        ast->lhs.reset(static_cast<ExpAST*>((yyvsp[-2].exp_val)));
        ast->rhs.reset(static_cast<ExpAST*>((yyvsp[0].exp_val)));
        (yyval.exp_val) = ast;
    }
#line 2206 "yacc.tab.c"
    break;

  case 55: /* MulExp: MulExp MOD UnaryExp  */
#line 453 "yacc.y"
                          {
        auto ast = new BinaryExpAST();
        ast->op = BinaryExpAST::MOD;
        ast->lhs.reset(static_cast<ExpAST*>((yyvsp[-2].exp_val)));
        ast->rhs.reset(static_cast<ExpAST*>((yyvsp[0].exp_val)));
        (yyval.exp_val) = ast;
    }
#line 2218 "yacc.tab.c"
    break;

  case 56: /* AddExp: MulExp  */
#line 464 "yacc.y"
             {
        (yyval.exp_val) = (yyvsp[0].exp_val);
    }
#line 2226 "yacc.tab.c"
    break;

  case 57: /* AddExp: AddExp PLUS MulExp  */
#line 467 "yacc.y"
                         {
        auto ast = new BinaryExpAST();
        ast->op = BinaryExpAST::ADD;
        ast->lhs.reset(static_cast<ExpAST*>((yyvsp[-2].exp_val)));
        ast->rhs.reset(static_cast<ExpAST*>((yyvsp[0].exp_val)));
        (yyval.exp_val) = ast;
    }
#line 2238 "yacc.tab.c"
    break;

  case 58: /* AddExp: AddExp MINU MulExp  */
#line 474 "yacc.y"
                         {
        auto ast = new BinaryExpAST();
        ast->op = BinaryExpAST::SUB;
        ast->lhs.reset(static_cast<ExpAST*>((yyvsp[-2].exp_val)));
        ast->rhs.reset(static_cast<ExpAST*>((yyvsp[0].exp_val)));
        (yyval.exp_val) = ast;
    }
#line 2250 "yacc.tab.c"
    break;

  case 59: /* RelExp: AddExp  */
#line 485 "yacc.y"
             {
        (yyval.exp_val) = (yyvsp[0].exp_val);
    }
#line 2258 "yacc.tab.c"
    break;

  case 60: /* RelExp: RelExp LSS AddExp  */
#line 488 "yacc.y"
                        {
        auto ast = new BinaryExpAST();
        ast->op = BinaryExpAST::LT;
        ast->lhs.reset(static_cast<ExpAST*>((yyvsp[-2].exp_val)));
        ast->rhs.reset(static_cast<ExpAST*>((yyvsp[0].exp_val)));
        (yyval.exp_val) = ast;
    }
#line 2270 "yacc.tab.c"
    break;

  case 61: /* RelExp: RelExp GRE AddExp  */
#line 495 "yacc.y"
                        {
        auto ast = new BinaryExpAST();
        ast->op = BinaryExpAST::GT;
        ast->lhs.reset(static_cast<ExpAST*>((yyvsp[-2].exp_val)));
        ast->rhs.reset(static_cast<ExpAST*>((yyvsp[0].exp_val)));
        (yyval.exp_val) = ast;
    }
#line 2282 "yacc.tab.c"
    break;

  case 62: /* RelExp: RelExp LEQ AddExp  */
#line 502 "yacc.y"
                        {
        auto ast = new BinaryExpAST();
        ast->op = BinaryExpAST::LE;
        ast->lhs.reset(static_cast<ExpAST*>((yyvsp[-2].exp_val)));
        ast->rhs.reset(static_cast<ExpAST*>((yyvsp[0].exp_val)));
        (yyval.exp_val) = ast;
    }
#line 2294 "yacc.tab.c"
    break;

  case 63: /* RelExp: RelExp GEQ AddExp  */
#line 509 "yacc.y"
                        {
        auto ast = new BinaryExpAST();
        ast->op = BinaryExpAST::GE;
        ast->lhs.reset(static_cast<ExpAST*>((yyvsp[-2].exp_val)));
        ast->rhs.reset(static_cast<ExpAST*>((yyvsp[0].exp_val)));
        (yyval.exp_val) = ast;
    }
#line 2306 "yacc.tab.c"
    break;

  case 64: /* EqExp: RelExp  */
#line 520 "yacc.y"
             {
        (yyval.exp_val) = (yyvsp[0].exp_val);
    }
#line 2314 "yacc.tab.c"
    break;

  case 65: /* EqExp: EqExp EQL RelExp  */
#line 523 "yacc.y"
                       {
        auto ast = new BinaryExpAST();
        ast->op = BinaryExpAST::EQ;
        ast->lhs.reset(static_cast<ExpAST*>((yyvsp[-2].exp_val)));
        ast->rhs.reset(static_cast<ExpAST*>((yyvsp[0].exp_val)));
        (yyval.exp_val) = ast;
    }
#line 2326 "yacc.tab.c"
    break;

  case 66: /* EqExp: EqExp NEQ RelExp  */
#line 530 "yacc.y"
                       {
        auto ast = new BinaryExpAST();
        ast->op = BinaryExpAST::NE;
        ast->lhs.reset(static_cast<ExpAST*>((yyvsp[-2].exp_val)));
        ast->rhs.reset(static_cast<ExpAST*>((yyvsp[0].exp_val)));
        (yyval.exp_val) = ast;
    }
#line 2338 "yacc.tab.c"
    break;

  case 67: /* LAndExp: EqExp  */
#line 541 "yacc.y"
            {
        (yyval.exp_val) = (yyvsp[0].exp_val);
    }
#line 2346 "yacc.tab.c"
    break;

  case 68: /* LAndExp: LAndExp AND EqExp  */
#line 544 "yacc.y"
                        {
        auto ast = new BinaryExpAST();
        ast->op = BinaryExpAST::AND;
        ast->lhs.reset(static_cast<ExpAST*>((yyvsp[-2].exp_val)));
        ast->rhs.reset(static_cast<ExpAST*>((yyvsp[0].exp_val)));
        (yyval.exp_val) = ast;
    }
#line 2358 "yacc.tab.c"
    break;

  case 69: /* LOrExp: LAndExp  */
#line 555 "yacc.y"
              {
        (yyval.exp_val) = (yyvsp[0].exp_val);
    }
#line 2366 "yacc.tab.c"
    break;

  case 70: /* LOrExp: LOrExp OR LAndExp  */
#line 558 "yacc.y"
                        {
        auto ast = new BinaryExpAST();
        ast->op = BinaryExpAST::OR;
        ast->lhs.reset(static_cast<ExpAST*>((yyvsp[-2].exp_val)));
        ast->rhs.reset(static_cast<ExpAST*>((yyvsp[0].exp_val)));
        (yyval.exp_val) = ast;
    }
#line 2378 "yacc.tab.c"
    break;

  case 71: /* ConstExp: AddExp  */
#line 569 "yacc.y"
             {
        (yyval.exp_val) = (yyvsp[0].exp_val);
    }
#line 2386 "yacc.tab.c"
    break;


#line 2390 "yacc.tab.c"

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
          YYNOMEM;
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

#line 574 "yacc.y"


void yyerror(const char* s) {
    fprintf(stderr, "错误: %s\n", s);
}

int main(int argc, char* argv[]) {
    // 设置输入文件
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            fprintf(stderr, "无法打开文件 %s\n", argv[1]);
            return 1;
        }
    }

    // 执行解析
    yyparse();

    // 输出AST到DOT文件
    if (root) {
        std::ofstream dot_file("ast.dot");
        dot_file << "digraph AST {\n";
        dot_file << "  node [fontname=\"Arial\"];\n";
        dot_file << root->DumpDOT();
        dot_file << "}\n";
        dot_file.close();
    }

    // 关闭文件
    if (argc > 1) {
        fclose(yyin);
    }

    return 0;
} 
