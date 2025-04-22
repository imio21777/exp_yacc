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

#define YYDEBUG 1

#include <cstdio>
#include <cstdlib>
#include <string>
#include <memory>
#include "ast.h"

// 声明全局根变量
std::unique_ptr<BaseAST> root;

int yylex();
void yyerror(const char *s);
extern char* yytext;


#line 89 "yacc.tab.c"

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
  YYSYMBOL_IDENT = 3,                      /* IDENT  */
  YYSYMBOL_STR_CONST = 4,                  /* STR_CONST  */
  YYSYMBOL_INT_CONST = 5,                  /* INT_CONST  */
  YYSYMBOL_MAIN = 6,                       /* MAIN  */
  YYSYMBOL_CONST = 7,                      /* CONST  */
  YYSYMBOL_INT = 8,                        /* INT  */
  YYSYMBOL_BREAK = 9,                      /* BREAK  */
  YYSYMBOL_CONTINUE = 10,                  /* CONTINUE  */
  YYSYMBOL_IF = 11,                        /* IF  */
  YYSYMBOL_ELSE = 12,                      /* ELSE  */
  YYSYMBOL_VOID = 13,                      /* VOID  */
  YYSYMBOL_WHILE = 14,                     /* WHILE  */
  YYSYMBOL_GETINT = 15,                    /* GETINT  */
  YYSYMBOL_PRINTF = 16,                    /* PRINTF  */
  YYSYMBOL_RETURN = 17,                    /* RETURN  */
  YYSYMBOL_NOT = 18,                       /* NOT  */
  YYSYMBOL_AND = 19,                       /* AND  */
  YYSYMBOL_OR = 20,                        /* OR  */
  YYSYMBOL_PLUS = 21,                      /* PLUS  */
  YYSYMBOL_MINU = 22,                      /* MINU  */
  YYSYMBOL_MULT = 23,                      /* MULT  */
  YYSYMBOL_DIV = 24,                       /* DIV  */
  YYSYMBOL_MOD = 25,                       /* MOD  */
  YYSYMBOL_LSS = 26,                       /* LSS  */
  YYSYMBOL_LEQ = 27,                       /* LEQ  */
  YYSYMBOL_GRE = 28,                       /* GRE  */
  YYSYMBOL_GEQ = 29,                       /* GEQ  */
  YYSYMBOL_EQL = 30,                       /* EQL  */
  YYSYMBOL_NEQ = 31,                       /* NEQ  */
  YYSYMBOL_ASSIGN = 32,                    /* ASSIGN  */
  YYSYMBOL_SEMICN = 33,                    /* SEMICN  */
  YYSYMBOL_COMMA = 34,                     /* COMMA  */
  YYSYMBOL_LPARENT = 35,                   /* LPARENT  */
  YYSYMBOL_RPARENT = 36,                   /* RPARENT  */
  YYSYMBOL_LBRACK = 37,                    /* LBRACK  */
  YYSYMBOL_RBRACK = 38,                    /* RBRACK  */
  YYSYMBOL_LBRACE = 39,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 40,                    /* RBRACE  */
  YYSYMBOL_LOWER_THAN_ELSE = 41,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 42,                  /* $accept  */
  YYSYMBOL_Program = 43,                   /* Program  */
  YYSYMBOL_CompUnit = 44,                  /* CompUnit  */
  YYSYMBOL_OptionalTopLevelItems = 45,     /* OptionalTopLevelItems  */
  YYSYMBOL_TopLevelItem = 46,              /* TopLevelItem  */
  YYSYMBOL_Decl = 47,                      /* Decl  */
  YYSYMBOL_ConstDecl = 48,                 /* ConstDecl  */
  YYSYMBOL_ConstDefList = 49,              /* ConstDefList  */
  YYSYMBOL_ConstDef = 50,                  /* ConstDef  */
  YYSYMBOL_ArraySpecifierOpt = 51,         /* ArraySpecifierOpt  */
  YYSYMBOL_ConstInitVal = 52,              /* ConstInitVal  */
  YYSYMBOL_ConstInitValList = 53,          /* ConstInitValList  */
  YYSYMBOL_VarDecl = 54,                   /* VarDecl  */
  YYSYMBOL_VarDefList = 55,                /* VarDefList  */
  YYSYMBOL_VarDef = 56,                    /* VarDef  */
  YYSYMBOL_InitVal = 57,                   /* InitVal  */
  YYSYMBOL_InitValList = 58,               /* InitValList  */
  YYSYMBOL_FuncDef = 59,                   /* FuncDef  */
  YYSYMBOL_OptionalFuncFParams = 60,       /* OptionalFuncFParams  */
  YYSYMBOL_FuncFParams = 61,               /* FuncFParams  */
  YYSYMBOL_FuncFParam = 62,                /* FuncFParam  */
  YYSYMBOL_MainFuncDef = 63,               /* MainFuncDef  */
  YYSYMBOL_Block = 64,                     /* Block  */
  YYSYMBOL_BlockItems = 65,                /* BlockItems  */
  YYSYMBOL_BlockItem = 66,                 /* BlockItem  */
  YYSYMBOL_Stmt = 67,                      /* Stmt  */
  YYSYMBOL_OptionalExp = 68,               /* OptionalExp  */
  YYSYMBOL_OptionalPrintfArgs = 69,        /* OptionalPrintfArgs  */
  YYSYMBOL_PrintfArgsList = 70,            /* PrintfArgsList  */
  YYSYMBOL_Exp = 71,                       /* Exp  */
  YYSYMBOL_Cond = 72,                      /* Cond  */
  YYSYMBOL_LVal = 73,                      /* LVal  */
  YYSYMBOL_LValArrayOpt = 74,              /* LValArrayOpt  */
  YYSYMBOL_PrimaryExp = 75,                /* PrimaryExp  */
  YYSYMBOL_Number = 76,                    /* Number  */
  YYSYMBOL_UnaryExp = 77,                  /* UnaryExp  */
  YYSYMBOL_OptionalFuncRParams = 78,       /* OptionalFuncRParams  */
  YYSYMBOL_FuncRParams = 79,               /* FuncRParams  */
  YYSYMBOL_UnaryOp = 80,                   /* UnaryOp  */
  YYSYMBOL_MulExp = 81,                    /* MulExp  */
  YYSYMBOL_AddExp = 82,                    /* AddExp  */
  YYSYMBOL_RelExp = 83,                    /* RelExp  */
  YYSYMBOL_EqExp = 84,                     /* EqExp  */
  YYSYMBOL_LAndExp = 85,                   /* LAndExp  */
  YYSYMBOL_LOrExp = 86,                    /* LOrExp  */
  YYSYMBOL_ConstExp = 87                   /* ConstExp  */
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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   218

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  100
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  182

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
       0,    63,    63,    69,    85,    89,    99,   102,   108,   114,
     123,   129,   132,   138,   160,   163,   169,   172,   175,   181,
     184,   190,   196,   199,   205,   215,   229,   232,   235,   241,
     244,   250,   266,   285,   288,   294,   297,   303,   316,   324,
     327,   334,   341,   351,   354,   360,   373,   379,   385,   392,
     400,   407,   412,   417,   423,   436,   450,   453,   459,   462,
     468,   471,   476,   477,   480,   495,   498,   504,   505,   506,
     510,   518,   519,   532,   542,   545,   551,   554,   560,   565,
     570,   579,   580,   588,   596,   607,   608,   616,   627,   628,
     636,   644,   652,   663,   664,   672,   683,   684,   695,   696,
     706
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
  "\"end of file\"", "error", "\"invalid token\"", "IDENT", "STR_CONST",
  "INT_CONST", "MAIN", "CONST", "INT", "BREAK", "CONTINUE", "IF", "ELSE",
  "VOID", "WHILE", "GETINT", "PRINTF", "RETURN", "NOT", "AND", "OR",
  "PLUS", "MINU", "MULT", "DIV", "MOD", "LSS", "LEQ", "GRE", "GEQ", "EQL",
  "NEQ", "ASSIGN", "SEMICN", "COMMA", "LPARENT", "RPARENT", "LBRACK",
  "RBRACK", "LBRACE", "RBRACE", "LOWER_THAN_ELSE", "$accept", "Program",
  "CompUnit", "OptionalTopLevelItems", "TopLevelItem", "Decl", "ConstDecl",
  "ConstDefList", "ConstDef", "ArraySpecifierOpt", "ConstInitVal",
  "ConstInitValList", "VarDecl", "VarDefList", "VarDef", "InitVal",
  "InitValList", "FuncDef", "OptionalFuncFParams", "FuncFParams",
  "FuncFParam", "MainFuncDef", "Block", "BlockItems", "BlockItem", "Stmt",
  "OptionalExp", "OptionalPrintfArgs", "PrintfArgsList", "Exp", "Cond",
  "LVal", "LValArrayOpt", "PrimaryExp", "Number", "UnaryExp",
  "OptionalFuncRParams", "FuncRParams", "UnaryOp", "MulExp", "AddExp",
  "RelExp", "EqExp", "LAndExp", "LOrExp", "ConstExp", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-119)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -119,     8,  -119,    -2,  -119,    18,    42,    19,  -119,  -119,
      16,    28,  -119,  -119,    76,     6,    48,    51,  -119,    67,
    -119,  -119,    68,    81,  -119,   109,   178,    86,    87,   116,
     109,    89,    76,   119,    99,   103,  -119,    23,  -119,  -119,
    -119,  -119,   178,  -119,  -119,  -119,  -119,   178,    72,    14,
     105,    35,   107,    68,  -119,   108,    85,  -119,  -119,   107,
     109,   178,   178,  -119,   114,    14,  -119,   178,   178,   178,
     178,   178,  -119,    47,  -119,  -119,     7,  -119,   107,    59,
    -119,  -119,  -119,  -119,  -119,   115,   121,   120,  -119,  -119,
    -119,  -119,    72,    72,  -119,  -119,   -27,   116,   124,   126,
     128,   129,   139,   178,  -119,  -119,  -119,   131,  -119,  -119,
     142,  -119,   145,  -119,  -119,  -119,    -7,  -119,   178,  -119,
      35,  -119,  -119,  -119,   178,   178,   175,   147,  -119,  -119,
    -119,   173,    85,  -119,  -119,  -119,   146,    14,    83,    36,
     165,   167,   149,   155,  -119,   157,   160,  -119,   151,   178,
     178,   178,   178,   178,   178,   178,   178,   151,   178,   161,
     164,   166,  -119,   189,    14,    14,    14,    14,    83,    83,
      36,   165,  -119,  -119,   170,   178,   171,   151,  -119,  -119,
    -119,  -119
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     2,     0,     1,     0,     0,     0,     5,     6,
       0,     0,     7,     3,     0,    14,     0,    21,    22,     0,
       8,     9,    14,    10,    11,    33,     0,    24,     0,     0,
      33,     0,     0,     0,     0,    34,    35,    65,    70,    80,
      78,    79,     0,    68,    71,    69,    81,     0,    85,   100,
       0,     0,     0,    14,    23,     0,     0,    12,    37,     0,
       0,    74,     0,    64,     0,    62,    73,     0,     0,     0,
       0,     0,    15,     0,    25,    26,    56,    38,     0,     0,
      13,    16,    32,    36,    76,     0,    75,     0,    67,    82,
      83,    84,    86,    87,    27,    29,     0,     0,     0,     0,
       0,     0,     0,    56,    40,    43,    47,    56,    41,    44,
       0,    57,    68,    31,    17,    19,     0,    72,     0,    66,
       0,    28,    51,    52,     0,     0,     0,     0,    39,    42,
      46,     0,     0,    18,    77,    30,     0,    88,    93,    96,
      98,    63,     0,    58,    53,     0,     0,    20,    56,     0,
       0,     0,     0,     0,     0,     0,     0,    56,     0,     0,
      59,     0,    45,    48,    89,    91,    90,    92,    94,    95,
      97,    99,    50,    60,     0,     0,     0,    56,    55,    61,
      54,    49
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -119,  -119,  -119,  -119,  -119,   202,  -119,  -119,   174,   185,
     -78,  -119,  -119,  -119,   180,   -69,  -119,  -119,   181,  -119,
     150,  -119,   -15,  -119,   110,  -118,   111,  -119,  -119,   -42,
      90,   -73,  -119,  -119,  -119,    24,  -119,  -119,  -119,     2,
     -24,   -40,    57,    60,  -119,   192
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     3,     8,   105,    10,    23,    24,    27,
      80,   116,    11,    17,    18,    74,    96,    12,    34,    35,
      36,    13,   106,   107,   108,   109,   110,   159,   160,   111,
     136,    43,    63,    44,    45,    46,    85,    86,    47,    48,
      65,   138,   139,   140,   141,    81
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      64,   115,    49,   112,    95,     5,     6,   120,     4,    75,
      37,     7,    38,   121,     5,    97,    98,    99,   100,    84,
      87,   101,    19,   102,   103,    39,    14,   132,    40,    41,
     163,    75,    49,   133,   112,    70,    71,    77,    37,   172,
      38,    25,    42,    26,    82,    15,    76,   104,    16,    20,
      37,   135,    38,    39,   147,    49,    40,    41,    61,   181,
      62,    21,    37,   113,    38,    39,   153,   154,    40,    41,
      42,    66,    92,    93,    73,   112,   134,    39,    75,    22,
      40,    41,    42,    28,   112,    29,    73,    94,    37,   146,
      38,    89,    90,    91,    42,    67,    68,    69,    79,   114,
     137,   137,    30,    39,   112,    26,    40,    41,    49,   149,
     150,   151,   152,   168,   169,    32,   173,    33,    51,    53,
      42,    56,    58,    52,    79,   164,   165,   166,   167,   137,
     137,   137,   137,   179,    37,    59,    38,    60,     5,    97,
      98,    99,   100,    72,    78,   101,    76,   102,   103,    39,
      88,   117,    40,    41,    37,   118,    38,   122,   119,   123,
      98,    99,   100,   124,   125,   101,    42,   102,   103,    39,
      76,   128,    40,    41,   126,   130,    37,   131,    38,   143,
     144,    37,   148,    38,   155,   157,    42,   156,   145,   158,
      76,    39,   161,   162,    40,    41,    39,   174,   175,    40,
      41,   177,   176,   178,   180,     9,    57,    31,    42,    54,
      83,    55,   170,    42,   127,   142,   171,   129,    50
};

static const yytype_uint8 yycheck[] =
{
      42,    79,    26,    76,    73,     7,     8,    34,     0,    51,
       3,    13,     5,    40,     7,     8,     9,    10,    11,    61,
      62,    14,     3,    16,    17,    18,     8,    34,    21,    22,
     148,    73,    56,    40,   107,    21,    22,    52,     3,   157,
       5,    35,    35,    37,    59,     3,    39,    40,     6,    33,
       3,   120,     5,    18,   132,    79,    21,    22,    35,   177,
      37,    33,     3,    78,     5,    18,    30,    31,    21,    22,
      35,    47,    70,    71,    39,   148,   118,    18,   120,     3,
      21,    22,    35,    35,   157,    34,    39,    40,     3,   131,
       5,    67,    68,    69,    35,    23,    24,    25,    39,    40,
     124,   125,    35,    18,   177,    37,    21,    22,   132,    26,
      27,    28,    29,   153,   154,    34,   158,     8,    32,     3,
      35,    32,     3,    36,    39,   149,   150,   151,   152,   153,
     154,   155,   156,   175,     3,    36,     5,    34,     7,     8,
       9,    10,    11,    38,    36,    14,    39,    16,    17,    18,
      36,    36,    21,    22,     3,    34,     5,    33,    38,    33,
       9,    10,    11,    35,    35,    14,    35,    16,    17,    18,
      39,    40,    21,    22,    35,    33,     3,    32,     5,     4,
      33,     3,    36,     5,    19,    36,    35,    20,    15,    34,
      39,    18,    35,    33,    21,    22,    18,    36,    34,    21,
      22,    12,    36,    33,    33,     3,    32,    22,    35,    29,
      60,    30,   155,    35,   103,   125,   156,   107,    26
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    43,    44,    45,     0,     7,     8,    13,    46,    47,
      48,    54,    59,    63,     8,     3,     6,    55,    56,     3,
      33,    33,     3,    49,    50,    35,    37,    51,    35,    34,
      35,    51,    34,     8,    60,    61,    62,     3,     5,    18,
      21,    22,    35,    73,    75,    76,    77,    80,    81,    82,
      87,    32,    36,     3,    56,    60,    32,    50,     3,    36,
      34,    35,    37,    74,    71,    82,    77,    23,    24,    25,
      21,    22,    38,    39,    57,    71,    39,    64,    36,    39,
      52,    87,    64,    62,    71,    78,    79,    71,    36,    77,
      77,    77,    81,    81,    40,    57,    58,     8,     9,    10,
      11,    14,    16,    17,    40,    47,    64,    65,    66,    67,
      68,    71,    73,    64,    40,    52,    53,    36,    34,    38,
      34,    40,    33,    33,    35,    35,    35,    68,    40,    66,
      33,    32,    34,    40,    71,    57,    72,    82,    83,    84,
      85,    86,    72,     4,    33,    15,    71,    52,    36,    26,
      27,    28,    29,    30,    31,    19,    20,    36,    34,    69,
      70,    35,    33,    67,    82,    82,    82,    82,    83,    83,
      84,    85,    67,    71,    36,    34,    36,    12,    33,    71,
      33,    67
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    44,    45,    45,    46,    46,    47,    47,
      48,    49,    49,    50,    51,    51,    52,    52,    52,    53,
      53,    54,    55,    55,    56,    56,    57,    57,    57,    58,
      58,    59,    59,    60,    60,    61,    61,    62,    63,    64,
      64,    65,    65,    66,    66,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    68,    68,    69,    69,
      70,    70,    71,    72,    73,    74,    74,    75,    75,    75,
      76,    77,    77,    77,    78,    78,    79,    79,    80,    80,
      80,    81,    81,    81,    81,    82,    82,    82,    83,    83,
      83,    83,    83,    84,    84,    84,    85,    85,    86,    86,
      87
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     1,     1,     2,     2,
       3,     1,     3,     4,     0,     3,     1,     2,     3,     1,
       3,     2,     1,     3,     2,     4,     1,     2,     3,     1,
       3,     6,     6,     0,     1,     1,     3,     2,     5,     3,
       2,     1,     2,     1,     1,     4,     2,     1,     5,     7,
       5,     2,     2,     3,     6,     6,     0,     1,     0,     1,
       2,     3,     1,     1,     2,     0,     3,     3,     1,     1,
       1,     1,     4,     2,     0,     1,     1,     3,     1,     1,
       1,     1,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     1,     3,
       1
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
  case 2: /* Program: CompUnit  */
#line 63 "yacc.y"
               { 
        root.reset(static_cast<BaseAST*>((yyvsp[0].ast_ptr))); // 设置全局根节点
    }
#line 1302 "yacc.tab.c"
    break;

  case 3: /* CompUnit: OptionalTopLevelItems MainFuncDef  */
#line 69 "yacc.y"
                                        {
        auto ast = new CompUnitAST();
        
        // 处理全局声明和函数
        auto global_items = static_cast<CompUnitAST*>((yyvsp[-1].ast_ptr));
        if (global_items) {
            ast->global_items = std::move(global_items->global_items);
        }
        
        // 设置主函数
        ast->main_func_def.reset(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        (yyval.ast_ptr) = ast;
    }
#line 1320 "yacc.tab.c"
    break;

  case 4: /* OptionalTopLevelItems: %empty  */
#line 85 "yacc.y"
                    {
        auto ast = new CompUnitAST();
        (yyval.ast_ptr) = ast;
    }
#line 1329 "yacc.tab.c"
    break;

  case 5: /* OptionalTopLevelItems: OptionalTopLevelItems TopLevelItem  */
#line 89 "yacc.y"
                                         {
        auto ast = static_cast<CompUnitAST*>((yyvsp[-1].ast_ptr));
        if ((yyvsp[0].ast_ptr)) {
            ast->global_items.emplace_back(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        }
        (yyval.ast_ptr) = ast;
    }
#line 1341 "yacc.tab.c"
    break;

  case 6: /* TopLevelItem: Decl  */
#line 99 "yacc.y"
           {
        (yyval.ast_ptr) = (yyvsp[0].ast_ptr);
    }
#line 1349 "yacc.tab.c"
    break;

  case 7: /* TopLevelItem: FuncDef  */
#line 102 "yacc.y"
              {
        (yyval.ast_ptr) = (yyvsp[0].ast_ptr);
    }
#line 1357 "yacc.tab.c"
    break;

  case 8: /* Decl: ConstDecl SEMICN  */
#line 108 "yacc.y"
                       { 
        auto ast = new DeclAST();
        ast->kind = DeclAST::CONST_DECL;
        ast->decl.reset(static_cast<BaseAST*>((yyvsp[-1].ast_ptr)));
        (yyval.ast_ptr) = ast;
    }
#line 1368 "yacc.tab.c"
    break;

  case 9: /* Decl: VarDecl SEMICN  */
#line 114 "yacc.y"
                     {
        auto ast = new DeclAST();
        ast->kind = DeclAST::VAR_DECL;
        ast->decl.reset(static_cast<BaseAST*>((yyvsp[-1].ast_ptr)));
        (yyval.ast_ptr) = ast;
    }
#line 1379 "yacc.tab.c"
    break;

  case 10: /* ConstDecl: CONST INT ConstDefList  */
#line 123 "yacc.y"
                             {
        (yyval.ast_ptr) = (yyvsp[0].ast_ptr); // 直接传递ConstDefList
    }
#line 1387 "yacc.tab.c"
    break;

  case 11: /* ConstDefList: ConstDef  */
#line 129 "yacc.y"
               {
        (yyval.ast_ptr) = (yyvsp[0].ast_ptr);
    }
#line 1395 "yacc.tab.c"
    break;

  case 12: /* ConstDefList: ConstDefList COMMA ConstDef  */
#line 132 "yacc.y"
                                  {
        (yyval.ast_ptr) = (yyvsp[-2].ast_ptr); // 当前我们只处理单个定义，可以扩展为列表
    }
#line 1403 "yacc.tab.c"
    break;

  case 13: /* ConstDef: IDENT ArraySpecifierOpt ASSIGN ConstInitVal  */
#line 138 "yacc.y"
                                                  {
        auto ast = new ConstDeclAST();
        ast->type = TYPE_INT;
        ast->ident = std::string((yyvsp[-3].str_val));
        
        // 处理数组声明
        // 这里简化了，实际需要从ArraySpecifierOpt获取数组维度
        
        // 处理初始值
        auto init_val = dynamic_cast<NumberAST*>((yyvsp[0].ast_ptr));
        if (init_val) {
            ast->value = init_val->value;
        }
        
        // 释放字符串
        free((yyvsp[-3].str_val));
        
        (yyval.ast_ptr) = ast;
    }
#line 1427 "yacc.tab.c"
    break;

  case 14: /* ArraySpecifierOpt: %empty  */
#line 160 "yacc.y"
                    {
        (yyval.ast_ptr) = nullptr;
    }
#line 1435 "yacc.tab.c"
    break;

  case 15: /* ArraySpecifierOpt: LBRACK ConstExp RBRACK  */
#line 163 "yacc.y"
                             {
        (yyval.ast_ptr) = (yyvsp[-1].ast_ptr); // 传递数组下标表达式
    }
#line 1443 "yacc.tab.c"
    break;

  case 16: /* ConstInitVal: ConstExp  */
#line 169 "yacc.y"
               {
        (yyval.ast_ptr) = (yyvsp[0].ast_ptr);
    }
#line 1451 "yacc.tab.c"
    break;

  case 17: /* ConstInitVal: LBRACE RBRACE  */
#line 172 "yacc.y"
                    {
        (yyval.ast_ptr) = nullptr; // 空数组初始化
    }
#line 1459 "yacc.tab.c"
    break;

  case 18: /* ConstInitVal: LBRACE ConstInitValList RBRACE  */
#line 175 "yacc.y"
                                     {
        (yyval.ast_ptr) = (yyvsp[-1].ast_ptr);
    }
#line 1467 "yacc.tab.c"
    break;

  case 19: /* ConstInitValList: ConstInitVal  */
#line 181 "yacc.y"
                   {
        (yyval.ast_ptr) = (yyvsp[0].ast_ptr);
    }
#line 1475 "yacc.tab.c"
    break;

  case 20: /* ConstInitValList: ConstInitValList COMMA ConstInitVal  */
#line 184 "yacc.y"
                                          {
        (yyval.ast_ptr) = (yyvsp[-2].ast_ptr); // 目前只处理第一个值
    }
#line 1483 "yacc.tab.c"
    break;

  case 21: /* VarDecl: INT VarDefList  */
#line 190 "yacc.y"
                     {
        (yyval.ast_ptr) = (yyvsp[0].ast_ptr); // 直接传递VarDefList
    }
#line 1491 "yacc.tab.c"
    break;

  case 22: /* VarDefList: VarDef  */
#line 196 "yacc.y"
             {
        (yyval.ast_ptr) = (yyvsp[0].ast_ptr);
    }
#line 1499 "yacc.tab.c"
    break;

  case 23: /* VarDefList: VarDefList COMMA VarDef  */
#line 199 "yacc.y"
                              {
        (yyval.ast_ptr) = (yyvsp[-2].ast_ptr); // 当前我们只处理单个定义
    }
#line 1507 "yacc.tab.c"
    break;

  case 24: /* VarDef: IDENT ArraySpecifierOpt  */
#line 205 "yacc.y"
                              {
        auto ast = new VarDeclAST();
        ast->type = TYPE_INT;
        ast->ident = std::string((yyvsp[-1].str_val));
        
        // 释放字符串
        free((yyvsp[-1].str_val));
        
        (yyval.ast_ptr) = ast;
    }
#line 1522 "yacc.tab.c"
    break;

  case 25: /* VarDef: IDENT ArraySpecifierOpt ASSIGN InitVal  */
#line 215 "yacc.y"
                                             {
        auto ast = new VarDeclAST();
        ast->type = TYPE_INT;
        ast->ident = std::string((yyvsp[-3].str_val));
        ast->init_val.reset(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        
        // 释放字符串
        free((yyvsp[-3].str_val));
        
        (yyval.ast_ptr) = ast;
    }
#line 1538 "yacc.tab.c"
    break;

  case 26: /* InitVal: Exp  */
#line 229 "yacc.y"
          {
        (yyval.ast_ptr) = (yyvsp[0].ast_ptr);
    }
#line 1546 "yacc.tab.c"
    break;

  case 27: /* InitVal: LBRACE RBRACE  */
#line 232 "yacc.y"
                    {
        (yyval.ast_ptr) = nullptr; // 空数组初始化
    }
#line 1554 "yacc.tab.c"
    break;

  case 28: /* InitVal: LBRACE InitValList RBRACE  */
#line 235 "yacc.y"
                                {
        (yyval.ast_ptr) = (yyvsp[-1].ast_ptr);
    }
#line 1562 "yacc.tab.c"
    break;

  case 29: /* InitValList: InitVal  */
#line 241 "yacc.y"
              {
        (yyval.ast_ptr) = (yyvsp[0].ast_ptr);
    }
#line 1570 "yacc.tab.c"
    break;

  case 30: /* InitValList: InitValList COMMA InitVal  */
#line 244 "yacc.y"
                                {
        (yyval.ast_ptr) = (yyvsp[-2].ast_ptr); // 目前只处理第一个值
    }
#line 1578 "yacc.tab.c"
    break;

  case 31: /* FuncDef: VOID IDENT LPARENT OptionalFuncFParams RPARENT Block  */
#line 250 "yacc.y"
                                                           { 
        auto ast = new FuncDefAST();
        ast->return_type = TYPE_VOID;
        ast->ident = std::string((yyvsp[-4].str_val));
        
        // 处理参数
        // 这里简化了，实际需要从OptionalFuncFParams获取参数列表
        
        // 设置函数体
        ast->block.reset(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        
        // 释放字符串
        free((yyvsp[-4].str_val));
        
        (yyval.ast_ptr) = ast;
    }
#line 1599 "yacc.tab.c"
    break;

  case 32: /* FuncDef: INT IDENT LPARENT OptionalFuncFParams RPARENT Block  */
#line 266 "yacc.y"
                                                          { 
        auto ast = new FuncDefAST();
        ast->return_type = TYPE_INT;
        ast->ident = std::string((yyvsp[-4].str_val));
        
        // 处理参数
        // 这里简化了，实际需要从OptionalFuncFParams获取参数列表
        
        // 设置函数体
        ast->block.reset(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        
        // 释放字符串
        free((yyvsp[-4].str_val));
        
        (yyval.ast_ptr) = ast;
    }
#line 1620 "yacc.tab.c"
    break;

  case 33: /* OptionalFuncFParams: %empty  */
#line 285 "yacc.y"
                    {
        (yyval.ast_ptr) = nullptr;
    }
#line 1628 "yacc.tab.c"
    break;

  case 34: /* OptionalFuncFParams: FuncFParams  */
#line 288 "yacc.y"
                  {
        (yyval.ast_ptr) = (yyvsp[0].ast_ptr);
    }
#line 1636 "yacc.tab.c"
    break;

  case 35: /* FuncFParams: FuncFParam  */
#line 294 "yacc.y"
                 {
        (yyval.ast_ptr) = (yyvsp[0].ast_ptr);
    }
#line 1644 "yacc.tab.c"
    break;

  case 36: /* FuncFParams: FuncFParams COMMA FuncFParam  */
#line 297 "yacc.y"
                                   {
        (yyval.ast_ptr) = (yyvsp[-2].ast_ptr); // 目前只处理第一个参数
    }
#line 1652 "yacc.tab.c"
    break;

  case 37: /* FuncFParam: INT IDENT  */
#line 303 "yacc.y"
                {
        auto ast = new VarDeclAST(); // 复用VarDeclAST表示参数
        ast->type = TYPE_INT;
        ast->ident = std::string((yyvsp[0].str_val));
        
        // 释放字符串
        free((yyvsp[0].str_val));
        
        (yyval.ast_ptr) = ast;
    }
#line 1667 "yacc.tab.c"
    break;

  case 38: /* MainFuncDef: INT MAIN LPARENT RPARENT Block  */
#line 316 "yacc.y"
                                     { 
        auto ast = new MainFuncDefAST();
        ast->block.reset(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        (yyval.ast_ptr) = ast;
    }
#line 1677 "yacc.tab.c"
    break;

  case 39: /* Block: LBRACE BlockItems RBRACE  */
#line 324 "yacc.y"
                               { 
        (yyval.ast_ptr) = (yyvsp[-1].ast_ptr);
    }
#line 1685 "yacc.tab.c"
    break;

  case 40: /* Block: LBRACE RBRACE  */
#line 327 "yacc.y"
                    {
        auto ast = new BlockAST();
        (yyval.ast_ptr) = ast;
    }
#line 1694 "yacc.tab.c"
    break;

  case 41: /* BlockItems: BlockItem  */
#line 334 "yacc.y"
                {
        auto ast = new BlockAST();
        if ((yyvsp[0].ast_ptr)) {
            ast->items.emplace_back(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        }
        (yyval.ast_ptr) = ast;
    }
#line 1706 "yacc.tab.c"
    break;

  case 42: /* BlockItems: BlockItems BlockItem  */
#line 341 "yacc.y"
                           {
        auto ast = static_cast<BlockAST*>((yyvsp[-1].ast_ptr));
        if ((yyvsp[0].ast_ptr)) {
            ast->items.emplace_back(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        }
        (yyval.ast_ptr) = ast;
    }
#line 1718 "yacc.tab.c"
    break;

  case 43: /* BlockItem: Decl  */
#line 351 "yacc.y"
           {
        (yyval.ast_ptr) = (yyvsp[0].ast_ptr);
    }
#line 1726 "yacc.tab.c"
    break;

  case 44: /* BlockItem: Stmt  */
#line 354 "yacc.y"
           {
        (yyval.ast_ptr) = (yyvsp[0].ast_ptr);
    }
#line 1734 "yacc.tab.c"
    break;

  case 45: /* Stmt: LVal ASSIGN Exp SEMICN  */
#line 360 "yacc.y"
                             { 
        auto ast = new StmtAST();
        ast->kind = StmtAST::ASSIGNMENT;
        
        auto assign = new AssignmentAST();
        auto lval = static_cast<LValAST*>((yyvsp[-3].ast_ptr));
        if (lval) {
            assign->ident = lval->ident;
        }
        
        ast->content.reset(assign);
        (yyval.ast_ptr) = ast;
    }
#line 1752 "yacc.tab.c"
    break;

  case 46: /* Stmt: OptionalExp SEMICN  */
#line 373 "yacc.y"
                         { 
        auto ast = new StmtAST();
        ast->kind = StmtAST::EXPR;
        ast->content.reset(static_cast<BaseAST*>((yyvsp[-1].ast_ptr)));
        (yyval.ast_ptr) = ast;
    }
#line 1763 "yacc.tab.c"
    break;

  case 47: /* Stmt: Block  */
#line 379 "yacc.y"
            { 
        auto ast = new StmtAST();
        ast->kind = StmtAST::BLOCK;
        ast->content.reset(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        (yyval.ast_ptr) = ast;
    }
#line 1774 "yacc.tab.c"
    break;

  case 48: /* Stmt: IF LPARENT Cond RPARENT Stmt  */
#line 385 "yacc.y"
                                                         { 
        auto ast = new StmtAST();
        ast->kind = StmtAST::IF;
        ast->content.reset(static_cast<BaseAST*>((yyvsp[-2].ast_ptr))); // 条件
        ast->else_stmt.reset(static_cast<BaseAST*>((yyvsp[0].ast_ptr))); // if块
        (yyval.ast_ptr) = ast;
    }
#line 1786 "yacc.tab.c"
    break;

  case 49: /* Stmt: IF LPARENT Cond RPARENT Stmt ELSE Stmt  */
#line 392 "yacc.y"
                                             { 
        auto ast = new StmtAST();
        ast->kind = StmtAST::IF;
        ast->content.reset(static_cast<BaseAST*>((yyvsp[-4].ast_ptr))); // 条件
        ast->else_stmt.reset(static_cast<BaseAST*>((yyvsp[0].ast_ptr))); // else块
        // 这里简化处理，实际应该有一个三元结构的if-then-else
        (yyval.ast_ptr) = ast;
    }
#line 1799 "yacc.tab.c"
    break;

  case 50: /* Stmt: WHILE LPARENT Cond RPARENT Stmt  */
#line 400 "yacc.y"
                                      { 
        auto ast = new StmtAST();
        ast->kind = StmtAST::WHILE;
        ast->content.reset(static_cast<BaseAST*>((yyvsp[-2].ast_ptr))); // 循环条件
        ast->else_stmt.reset(static_cast<BaseAST*>((yyvsp[0].ast_ptr))); // 循环体
        (yyval.ast_ptr) = ast;
    }
#line 1811 "yacc.tab.c"
    break;

  case 51: /* Stmt: BREAK SEMICN  */
#line 407 "yacc.y"
                   { 
        auto ast = new StmtAST();
        ast->kind = StmtAST::BREAK;
        (yyval.ast_ptr) = ast;
    }
#line 1821 "yacc.tab.c"
    break;

  case 52: /* Stmt: CONTINUE SEMICN  */
#line 412 "yacc.y"
                      { 
        auto ast = new StmtAST();
        ast->kind = StmtAST::CONTINUE;
        (yyval.ast_ptr) = ast;
    }
#line 1831 "yacc.tab.c"
    break;

  case 53: /* Stmt: RETURN OptionalExp SEMICN  */
#line 417 "yacc.y"
                                { 
        auto ast = new StmtAST();
        ast->kind = StmtAST::RETURN;
        ast->content.reset(static_cast<BaseAST*>((yyvsp[-1].ast_ptr))); // 返回表达式
        (yyval.ast_ptr) = ast;
    }
#line 1842 "yacc.tab.c"
    break;

  case 54: /* Stmt: LVal ASSIGN GETINT LPARENT RPARENT SEMICN  */
#line 423 "yacc.y"
                                                { 
        auto ast = new StmtAST();
        ast->kind = StmtAST::ASSIGNMENT;
        
        auto assign = new AssignmentAST();
        auto lval = static_cast<LValAST*>((yyvsp[-5].ast_ptr));
        if (lval) {
            assign->ident = lval->ident;
        }
        
        ast->content.reset(assign);
        (yyval.ast_ptr) = ast;
    }
#line 1860 "yacc.tab.c"
    break;

  case 55: /* Stmt: PRINTF LPARENT STR_CONST OptionalPrintfArgs RPARENT SEMICN  */
#line 436 "yacc.y"
                                                                 { 
        auto ast = new StmtAST();
        ast->kind = StmtAST::PRINTF;
        
        // 这里简化处理printf，实际需要保存格式串和参数列表
        
        // 释放字符串
        free((yyvsp[-3].str_val));
        
        (yyval.ast_ptr) = ast;
    }
#line 1876 "yacc.tab.c"
    break;

  case 56: /* OptionalExp: %empty  */
#line 450 "yacc.y"
                    {
        (yyval.ast_ptr) = nullptr;
    }
#line 1884 "yacc.tab.c"
    break;

  case 57: /* OptionalExp: Exp  */
#line 453 "yacc.y"
          {
        (yyval.ast_ptr) = (yyvsp[0].ast_ptr);
    }
#line 1892 "yacc.tab.c"
    break;

  case 58: /* OptionalPrintfArgs: %empty  */
#line 459 "yacc.y"
                    {
        (yyval.ast_ptr) = nullptr;
    }
#line 1900 "yacc.tab.c"
    break;

  case 59: /* OptionalPrintfArgs: PrintfArgsList  */
#line 462 "yacc.y"
                     {
        (yyval.ast_ptr) = (yyvsp[0].ast_ptr);
    }
#line 1908 "yacc.tab.c"
    break;

  case 60: /* PrintfArgsList: COMMA Exp  */
#line 468 "yacc.y"
                {
        (yyval.ast_ptr) = (yyvsp[0].ast_ptr);
    }
#line 1916 "yacc.tab.c"
    break;

  case 61: /* PrintfArgsList: PrintfArgsList COMMA Exp  */
#line 471 "yacc.y"
                               {
        (yyval.ast_ptr) = (yyvsp[-2].ast_ptr); // 目前只处理第一个参数
    }
#line 1924 "yacc.tab.c"
    break;

  case 62: /* Exp: AddExp  */
#line 476 "yacc.y"
             { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); }
#line 1930 "yacc.tab.c"
    break;

  case 63: /* Cond: LOrExp  */
#line 477 "yacc.y"
              { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); }
#line 1936 "yacc.tab.c"
    break;

  case 64: /* LVal: IDENT LValArrayOpt  */
#line 480 "yacc.y"
                         {
        auto ast = new LValAST();
        ast->ident = std::string((yyvsp[-1].str_val));
        
        // 处理数组索引
        // 这里简化处理，实际需要从LValArrayOpt获取索引列表
        
        // 释放字符串
        free((yyvsp[-1].str_val));
        
        (yyval.ast_ptr) = ast;
    }
#line 1953 "yacc.tab.c"
    break;

  case 65: /* LValArrayOpt: %empty  */
#line 495 "yacc.y"
                    {
        (yyval.ast_ptr) = nullptr;
    }
#line 1961 "yacc.tab.c"
    break;

  case 66: /* LValArrayOpt: LBRACK Exp RBRACK  */
#line 498 "yacc.y"
                        {
        (yyval.ast_ptr) = (yyvsp[-1].ast_ptr);
    }
#line 1969 "yacc.tab.c"
    break;

  case 67: /* PrimaryExp: LPARENT Exp RPARENT  */
#line 504 "yacc.y"
                          { (yyval.ast_ptr) = (yyvsp[-1].ast_ptr); }
#line 1975 "yacc.tab.c"
    break;

  case 68: /* PrimaryExp: LVal  */
#line 505 "yacc.y"
           { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); }
#line 1981 "yacc.tab.c"
    break;

  case 69: /* PrimaryExp: Number  */
#line 506 "yacc.y"
             { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); }
#line 1987 "yacc.tab.c"
    break;

  case 70: /* Number: INT_CONST  */
#line 510 "yacc.y"
                {
        auto ast = new NumberAST();
        ast->value = (yyvsp[0].int_val);
        (yyval.ast_ptr) = ast;
    }
#line 1997 "yacc.tab.c"
    break;

  case 71: /* UnaryExp: PrimaryExp  */
#line 518 "yacc.y"
                 { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); }
#line 2003 "yacc.tab.c"
    break;

  case 72: /* UnaryExp: IDENT LPARENT OptionalFuncRParams RPARENT  */
#line 519 "yacc.y"
                                                {
        auto ast = new ExprAST();
        ast->kind = ExprAST::CALL;
        ast->ident = std::string((yyvsp[-3].str_val));
        
        // 处理函数参数
        // 这里简化处理，实际需要保存参数列表
        
        // 释放字符串
        free((yyvsp[-3].str_val));
        
        (yyval.ast_ptr) = ast;
    }
#line 2021 "yacc.tab.c"
    break;

  case 73: /* UnaryExp: UnaryOp UnaryExp  */
#line 532 "yacc.y"
                       {
        auto ast = new ExprAST();
        ast->kind = ExprAST::UNARY;
        ast->op = static_cast<ExprAST*>((yyvsp[-1].ast_ptr))->op;
        ast->right.reset(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        (yyval.ast_ptr) = ast;
    }
#line 2033 "yacc.tab.c"
    break;

  case 74: /* OptionalFuncRParams: %empty  */
#line 542 "yacc.y"
                    {
        (yyval.ast_ptr) = nullptr;
    }
#line 2041 "yacc.tab.c"
    break;

  case 75: /* OptionalFuncRParams: FuncRParams  */
#line 545 "yacc.y"
                  {
        (yyval.ast_ptr) = (yyvsp[0].ast_ptr);
    }
#line 2049 "yacc.tab.c"
    break;

  case 76: /* FuncRParams: Exp  */
#line 551 "yacc.y"
          {
        (yyval.ast_ptr) = (yyvsp[0].ast_ptr);
    }
#line 2057 "yacc.tab.c"
    break;

  case 77: /* FuncRParams: FuncRParams COMMA Exp  */
#line 554 "yacc.y"
                            {
        (yyval.ast_ptr) = (yyvsp[-2].ast_ptr); // 目前只处理第一个参数
    }
#line 2065 "yacc.tab.c"
    break;

  case 78: /* UnaryOp: PLUS  */
#line 560 "yacc.y"
           {
        auto ast = new ExprAST();
        ast->op = "+";
        (yyval.ast_ptr) = ast;
    }
#line 2075 "yacc.tab.c"
    break;

  case 79: /* UnaryOp: MINU  */
#line 565 "yacc.y"
           {
        auto ast = new ExprAST();
        ast->op = "-";
        (yyval.ast_ptr) = ast;
    }
#line 2085 "yacc.tab.c"
    break;

  case 80: /* UnaryOp: NOT  */
#line 570 "yacc.y"
          {
        auto ast = new ExprAST();
        ast->op = "!";
        (yyval.ast_ptr) = ast;
    }
#line 2095 "yacc.tab.c"
    break;

  case 81: /* MulExp: UnaryExp  */
#line 579 "yacc.y"
               { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); }
#line 2101 "yacc.tab.c"
    break;

  case 82: /* MulExp: MulExp MULT UnaryExp  */
#line 580 "yacc.y"
                           {
        auto ast = new ExprAST();
        ast->kind = ExprAST::BINARY;
        ast->op = "*";
        ast->left.reset(static_cast<BaseAST*>((yyvsp[-2].ast_ptr)));
        ast->right.reset(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        (yyval.ast_ptr) = ast;
    }
#line 2114 "yacc.tab.c"
    break;

  case 83: /* MulExp: MulExp DIV UnaryExp  */
#line 588 "yacc.y"
                          {
        auto ast = new ExprAST();
        ast->kind = ExprAST::BINARY;
        ast->op = "/";
        ast->left.reset(static_cast<BaseAST*>((yyvsp[-2].ast_ptr)));
        ast->right.reset(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        (yyval.ast_ptr) = ast;
    }
#line 2127 "yacc.tab.c"
    break;

  case 84: /* MulExp: MulExp MOD UnaryExp  */
#line 596 "yacc.y"
                          {
        auto ast = new ExprAST();
        ast->kind = ExprAST::BINARY;
        ast->op = "%";
        ast->left.reset(static_cast<BaseAST*>((yyvsp[-2].ast_ptr)));
        ast->right.reset(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        (yyval.ast_ptr) = ast;
    }
#line 2140 "yacc.tab.c"
    break;

  case 85: /* AddExp: MulExp  */
#line 607 "yacc.y"
             { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); }
#line 2146 "yacc.tab.c"
    break;

  case 86: /* AddExp: AddExp PLUS MulExp  */
#line 608 "yacc.y"
                         {
        auto ast = new ExprAST();
        ast->kind = ExprAST::BINARY;
        ast->op = "+";
        ast->left.reset(static_cast<BaseAST*>((yyvsp[-2].ast_ptr)));
        ast->right.reset(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        (yyval.ast_ptr) = ast;
    }
#line 2159 "yacc.tab.c"
    break;

  case 87: /* AddExp: AddExp MINU MulExp  */
#line 616 "yacc.y"
                         {
        auto ast = new ExprAST();
        ast->kind = ExprAST::BINARY;
        ast->op = "-";
        ast->left.reset(static_cast<BaseAST*>((yyvsp[-2].ast_ptr)));
        ast->right.reset(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        (yyval.ast_ptr) = ast;
    }
#line 2172 "yacc.tab.c"
    break;

  case 88: /* RelExp: AddExp  */
#line 627 "yacc.y"
             { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); }
#line 2178 "yacc.tab.c"
    break;

  case 89: /* RelExp: RelExp LSS AddExp  */
#line 628 "yacc.y"
                        {
        auto ast = new ExprAST();
        ast->kind = ExprAST::BINARY;
        ast->op = "<";
        ast->left.reset(static_cast<BaseAST*>((yyvsp[-2].ast_ptr)));
        ast->right.reset(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        (yyval.ast_ptr) = ast;
    }
#line 2191 "yacc.tab.c"
    break;

  case 90: /* RelExp: RelExp GRE AddExp  */
#line 636 "yacc.y"
                        {
        auto ast = new ExprAST();
        ast->kind = ExprAST::BINARY;
        ast->op = ">";
        ast->left.reset(static_cast<BaseAST*>((yyvsp[-2].ast_ptr)));
        ast->right.reset(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        (yyval.ast_ptr) = ast;
    }
#line 2204 "yacc.tab.c"
    break;

  case 91: /* RelExp: RelExp LEQ AddExp  */
#line 644 "yacc.y"
                        {
        auto ast = new ExprAST();
        ast->kind = ExprAST::BINARY;
        ast->op = "<=";
        ast->left.reset(static_cast<BaseAST*>((yyvsp[-2].ast_ptr)));
        ast->right.reset(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        (yyval.ast_ptr) = ast;
    }
#line 2217 "yacc.tab.c"
    break;

  case 92: /* RelExp: RelExp GEQ AddExp  */
#line 652 "yacc.y"
                        {
        auto ast = new ExprAST();
        ast->kind = ExprAST::BINARY;
        ast->op = ">=";
        ast->left.reset(static_cast<BaseAST*>((yyvsp[-2].ast_ptr)));
        ast->right.reset(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        (yyval.ast_ptr) = ast;
    }
#line 2230 "yacc.tab.c"
    break;

  case 93: /* EqExp: RelExp  */
#line 663 "yacc.y"
             { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); }
#line 2236 "yacc.tab.c"
    break;

  case 94: /* EqExp: EqExp EQL RelExp  */
#line 664 "yacc.y"
                       {
        auto ast = new ExprAST();
        ast->kind = ExprAST::BINARY;
        ast->op = "==";
        ast->left.reset(static_cast<BaseAST*>((yyvsp[-2].ast_ptr)));
        ast->right.reset(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        (yyval.ast_ptr) = ast;
    }
#line 2249 "yacc.tab.c"
    break;

  case 95: /* EqExp: EqExp NEQ RelExp  */
#line 672 "yacc.y"
                       {
        auto ast = new ExprAST();
        ast->kind = ExprAST::BINARY;
        ast->op = "!=";
        ast->left.reset(static_cast<BaseAST*>((yyvsp[-2].ast_ptr)));
        ast->right.reset(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        (yyval.ast_ptr) = ast;
    }
#line 2262 "yacc.tab.c"
    break;

  case 96: /* LAndExp: EqExp  */
#line 683 "yacc.y"
            { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); }
#line 2268 "yacc.tab.c"
    break;

  case 97: /* LAndExp: LAndExp AND EqExp  */
#line 684 "yacc.y"
                        {
        auto ast = new ExprAST();
        ast->kind = ExprAST::BINARY;
        ast->op = "&&";
        ast->left.reset(static_cast<BaseAST*>((yyvsp[-2].ast_ptr)));
        ast->right.reset(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        (yyval.ast_ptr) = ast;
    }
#line 2281 "yacc.tab.c"
    break;

  case 98: /* LOrExp: LAndExp  */
#line 695 "yacc.y"
              { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); }
#line 2287 "yacc.tab.c"
    break;

  case 99: /* LOrExp: LOrExp OR LAndExp  */
#line 696 "yacc.y"
                        {
        auto ast = new ExprAST();
        ast->kind = ExprAST::BINARY;
        ast->op = "||";
        ast->left.reset(static_cast<BaseAST*>((yyvsp[-2].ast_ptr)));
        ast->right.reset(static_cast<BaseAST*>((yyvsp[0].ast_ptr)));
        (yyval.ast_ptr) = ast;
    }
#line 2300 "yacc.tab.c"
    break;

  case 100: /* ConstExp: AddExp  */
#line 706 "yacc.y"
                  { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); }
#line 2306 "yacc.tab.c"
    break;


#line 2310 "yacc.tab.c"

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

#line 709 "yacc.y"
 

void yyerror(const char *s) {
    fprintf(stderr, "Syntax error: %s near '%s'\n", s, yytext ? yytext : "<unknown>");
    exit(1);
}
