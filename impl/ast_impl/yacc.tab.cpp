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
#line 13 "yacc.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // For strcpy

// External declaration for the lexer function
extern int yylex();
extern FILE *yyin;

// Error handling function required by Yacc/Bison
void yyerror(const char *s);

#line 84 "yacc.tab.cpp"

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

#include "yacc.tab.hpp"
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
  YYSYMBOL_FuncParams = 61,                /* FuncParams  */
  YYSYMBOL_FuncFParam = 62,                /* FuncFParam  */
  YYSYMBOL_MainFuncDef = 63,               /* MainFuncDef  */
  YYSYMBOL_Block = 64,                     /* Block  */
  YYSYMBOL_BlockItemList = 65,             /* BlockItemList  */
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
  YYSYMBOL_FuncRParamsList = 79,           /* FuncRParamsList  */
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
#define YYLAST   207

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  99
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  180

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
       0,    61,    61,    65,    80,    81,    85,    86,    92,    99,
     109,   120,   121,   125,   137,   138,   142,   143,   144,   148,
     149,   153,   163,   164,   168,   176,   187,   188,   189,   193,
     194,   198,   206,   219,   220,   224,   225,   229,   238,   247,
     256,   257,   261,   262,   266,   274,   280,   286,   292,   298,
     304,   306,   308,   314,   320,   331,   332,   336,   337,   341,
     342,   345,   346,   349,   359,   360,   364,   365,   366,   369,
     373,   374,   382,   394,   395,   399,   400,   404,   405,   406,
     411,   412,   413,   414,   417,   418,   419,   422,   423,   424,
     425,   426,   429,   430,   431,   434,   435,   438,   439,   443
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
  "InitValList", "FuncDef", "OptionalFuncFParams", "FuncParams",
  "FuncFParam", "MainFuncDef", "Block", "BlockItemList", "BlockItem",
  "Stmt", "OptionalExp", "OptionalPrintfArgs", "PrintfArgsList", "Exp",
  "Cond", "LVal", "LValArrayOpt", "PrimaryExp", "Number", "UnaryExp",
  "OptionalFuncRParams", "FuncRParamsList", "UnaryOp", "MulExp", "AddExp",
  "RelExp", "EqExp", "LAndExp", "LOrExp", "ConstExp", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-141)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -141,    28,  -141,     9,  -141,     0,    18,    41,  -141,  -141,
      24,    29,  -141,  -141,    48,   -10,    37,    30,  -141,    43,
    -141,  -141,    59,    51,  -141,    91,   172,    68,    67,   110,
      91,    84,    48,   112,    81,    85,  -141,    19,  -141,  -141,
    -141,  -141,   172,  -141,  -141,  -141,  -141,   172,    64,    47,
      80,   139,    82,    59,  -141,    86,   149,  -141,  -141,    82,
      91,   172,   172,  -141,    97,    47,  -141,   172,   172,   172,
     172,   172,  -141,    55,  -141,  -141,  -141,  -141,    82,    62,
    -141,  -141,  -141,  -141,  -141,    99,   102,   103,  -141,  -141,
    -141,  -141,    64,    64,  -141,  -141,   -30,    31,  -141,  -141,
    -141,   -22,  -141,   172,  -141,   139,  -141,   110,    87,   104,
     113,   114,   118,   172,  -141,  -141,  -141,  -141,  -141,   122,
    -141,   124,   149,  -141,  -141,  -141,  -141,  -141,   172,   172,
     154,   126,  -141,     8,  -141,   127,    47,    83,    44,   143,
     145,   130,   135,  -141,   137,   140,   129,   172,   172,   172,
     172,   172,   172,   172,   172,   129,   172,   144,   142,   146,
    -141,   167,    47,    47,    47,    47,    83,    83,    44,   143,
    -141,  -141,   148,   172,   150,   129,  -141,  -141,  -141,  -141
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     2,     0,     1,     0,     0,     0,     5,     6,
       0,     0,     7,     3,     0,    14,     0,    21,    22,     0,
       8,     9,    14,    10,    11,    33,     0,    24,     0,     0,
      33,     0,     0,     0,     0,    34,    35,    64,    69,    79,
      77,    78,     0,    67,    70,    68,    80,     0,    84,    99,
       0,     0,     0,    14,    23,     0,     0,    12,    37,     0,
       0,    73,     0,    63,     0,    61,    72,     0,     0,     0,
       0,     0,    15,     0,    25,    26,    40,    38,     0,     0,
      13,    16,    32,    36,    75,     0,    74,     0,    66,    81,
      82,    83,    85,    86,    27,    29,     0,    55,    31,    17,
      19,     0,    71,     0,    65,     0,    28,     0,     0,     0,
       0,     0,     0,    55,    39,    42,    46,    41,    43,     0,
      56,    67,     0,    18,    76,    30,    50,    51,     0,     0,
       0,     0,    45,     0,    20,     0,    87,    92,    95,    97,
      62,     0,    57,    52,     0,     0,    55,     0,     0,     0,
       0,     0,     0,     0,     0,    55,     0,     0,    58,     0,
      44,    47,    88,    90,    89,    91,    93,    94,    96,    98,
      49,    59,     0,     0,     0,    55,    54,    60,    53,    48
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -141,  -141,  -141,  -141,  -141,    88,  -141,  -141,   155,   164,
     -76,  -141,  -141,  -141,   160,   -68,  -141,  -141,   161,  -141,
     132,  -141,   -45,  -141,  -141,  -140,    89,  -141,  -141,   -42,
      66,   -96,  -141,  -141,  -141,    39,  -141,  -141,  -141,    11,
     -24,   -59,    45,    42,  -141,   171
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     3,     8,     9,    10,    23,    24,    27,
      80,   101,    11,    17,    18,    74,    96,    12,    34,    35,
      36,    13,   116,    97,   117,   118,   119,   157,   158,   120,
     135,    43,    63,    44,    45,    46,    85,    86,    47,    48,
      65,   137,   138,   139,   140,    81
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      64,   121,    49,   100,   105,    95,   161,    77,    14,    75,
     106,    37,   122,    38,    82,   170,     5,     6,   123,    84,
      87,    15,     7,   144,    16,    25,    39,    26,     4,    40,
      41,    75,    49,    98,    37,   179,    38,   125,     5,   107,
     108,   109,   110,    42,    19,   111,   134,   112,   113,    39,
     121,    22,    40,    41,    61,    49,    62,    20,    37,   121,
      38,   124,    21,    75,    29,    37,    42,    38,    70,    71,
      76,   114,    28,    39,   151,   152,    40,    41,    30,   121,
      39,    92,    93,    40,    41,    32,    66,    67,    68,    69,
      42,   145,   166,   167,    73,    94,    26,    42,    49,    33,
      51,    79,    99,    52,   136,   136,    89,    90,    91,   147,
     148,   149,   150,    53,   171,    58,    56,    59,    72,    60,
     126,    76,    78,   162,   163,   164,   165,   136,   136,   136,
     136,   177,    37,    88,    38,   102,   103,   127,   108,   109,
     110,   104,    37,   111,    38,   112,   113,    39,   128,   129,
      40,    41,    37,   130,    38,   132,   133,    39,   142,   143,
      40,    41,   153,   146,    42,   154,   155,    39,    76,   156,
      40,    41,   159,   160,    42,    37,   173,    38,    73,   175,
     172,   176,   174,   178,    42,   115,    31,    57,    79,    54,
      39,    55,    83,    40,    41,   141,   169,    50,   168,     0,
       0,     0,   131,     0,     0,     0,     0,    42
};

static const yytype_int16 yycheck[] =
{
      42,    97,    26,    79,    34,    73,   146,    52,     8,    51,
      40,     3,    34,     5,    59,   155,     7,     8,    40,    61,
      62,     3,    13,    15,     6,    35,    18,    37,     0,    21,
      22,    73,    56,    78,     3,   175,     5,   105,     7,     8,
       9,    10,    11,    35,     3,    14,   122,    16,    17,    18,
     146,     3,    21,    22,    35,    79,    37,    33,     3,   155,
       5,   103,    33,   105,    34,     3,    35,     5,    21,    22,
      39,    40,    35,    18,    30,    31,    21,    22,    35,   175,
      18,    70,    71,    21,    22,    34,    47,    23,    24,    25,
      35,   133,   151,   152,    39,    40,    37,    35,   122,     8,
      32,    39,    40,    36,   128,   129,    67,    68,    69,    26,
      27,    28,    29,     3,   156,     3,    32,    36,    38,    34,
      33,    39,    36,   147,   148,   149,   150,   151,   152,   153,
     154,   173,     3,    36,     5,    36,    34,    33,     9,    10,
      11,    38,     3,    14,     5,    16,    17,    18,    35,    35,
      21,    22,     3,    35,     5,    33,    32,    18,     4,    33,
      21,    22,    19,    36,    35,    20,    36,    18,    39,    34,
      21,    22,    35,    33,    35,     3,    34,     5,    39,    12,
      36,    33,    36,    33,    35,    97,    22,    32,    39,    29,
      18,    30,    60,    21,    22,   129,   154,    26,   153,    -1,
      -1,    -1,   113,    -1,    -1,    -1,    -1,    35
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
      77,    77,    81,    81,    40,    57,    58,    65,    64,    40,
      52,    53,    36,    34,    38,    34,    40,     8,     9,    10,
      11,    14,    16,    17,    40,    47,    64,    66,    67,    68,
      71,    73,    34,    40,    71,    57,    33,    33,    35,    35,
      35,    68,    33,    32,    52,    72,    82,    83,    84,    85,
      86,    72,     4,    33,    15,    71,    36,    26,    27,    28,
      29,    30,    31,    19,    20,    36,    34,    69,    70,    35,
      33,    67,    82,    82,    82,    82,    83,    83,    84,    85,
      67,    71,    36,    34,    36,    12,    33,    71,    33,    67
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    44,    45,    45,    46,    46,    47,    47,
      48,    49,    49,    50,    51,    51,    52,    52,    52,    53,
      53,    54,    55,    55,    56,    56,    57,    57,    57,    58,
      58,    59,    59,    60,    60,    61,    61,    62,    63,    64,
      65,    65,    66,    66,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    68,    68,    69,    69,    70,
      70,    71,    72,    73,    74,    74,    75,    75,    75,    76,
      77,    77,    77,    78,    78,    79,    79,    80,    80,    80,
      81,    81,    81,    81,    82,    82,    82,    83,    83,    83,
      83,    83,    84,    84,    84,    85,    85,    86,    86,    87
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     1,     1,     2,     2,
       3,     1,     3,     4,     0,     3,     1,     2,     3,     1,
       3,     2,     1,     3,     2,     4,     1,     2,     3,     1,
       3,     6,     6,     0,     1,     1,     3,     2,     5,     3,
       0,     2,     1,     1,     4,     2,     1,     5,     7,     5,
       2,     2,     3,     6,     6,     0,     1,     0,     1,     2,
       3,     1,     1,     2,     0,     3,     3,     1,     1,     1,
       1,     4,     2,     0,     1,     1,     3,     1,     1,     1,
       1,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     1,     3,     1
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
#line 61 "yacc.y"
               { root.reset((yyvsp[0].ast_ptr)); }
#line 1287 "yacc.tab.cpp"
    break;

  case 3: /* CompUnit: OptionalTopLevelItems MainFuncDef  */
#line 66 "yacc.y"
      {
          auto node = new CompUnitAST();
          // This structure needs review based on how OptionalTopLevelItems returns data.
          // If $1 returns a list container node:
          // node->decl_defs = std::move(static_cast<TopLevelListAST*>($1)->items);
          // delete $1;
          // If $1 returns just the last Decl/FuncDef (current simplistic approach):
          if ((yyvsp[-1].ast_ptr)) node->decl.reset((yyvsp[-1].ast_ptr)); // Placeholder, needs proper list aggregation
          node->main_func_def.reset((yyvsp[0].ast_ptr));
          (yyval.ast_ptr) = node;
      }
#line 1303 "yacc.tab.cpp"
    break;

  case 4: /* OptionalTopLevelItems: %empty  */
#line 80 "yacc.y"
                    { (yyval.ast_ptr) = nullptr; }
#line 1309 "yacc.tab.cpp"
    break;

  case 5: /* OptionalTopLevelItems: OptionalTopLevelItems TopLevelItem  */
#line 81 "yacc.y"
                                         { delete (yyvsp[-1].ast_ptr); (yyval.ast_ptr) = (yyvsp[0].ast_ptr); /* Incorrect: Loses previous items */ }
#line 1315 "yacc.tab.cpp"
    break;

  case 6: /* TopLevelItem: Decl  */
#line 85 "yacc.y"
              { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); }
#line 1321 "yacc.tab.cpp"
    break;

  case 7: /* TopLevelItem: FuncDef  */
#line 86 "yacc.y"
              { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); }
#line 1327 "yacc.tab.cpp"
    break;

  case 8: /* Decl: ConstDecl SEMICN  */
#line 93 "yacc.y"
      { 
          auto node = new DeclAST();
          node->kind = DeclAST::CONST_DECL;
          node->decl.reset((yyvsp[-1].ast_ptr));
          (yyval.ast_ptr) = node;
      }
#line 1338 "yacc.tab.cpp"
    break;

  case 9: /* Decl: VarDecl SEMICN  */
#line 100 "yacc.y"
      { 
          auto node = new DeclAST();
          node->kind = DeclAST::VAR_DECL;
          node->decl.reset((yyvsp[-1].ast_ptr));
          (yyval.ast_ptr) = node;
      }
#line 1349 "yacc.tab.cpp"
    break;

  case 10: /* ConstDecl: CONST INT ConstDefList  */
#line 110 "yacc.y"
      {
          // Assuming ConstDeclAST needs to be created here, holding multiple ConstDefs
          // This needs a proper list handling for ConstDefList ($3)
          auto node = new ConstDeclListAST(); // Assuming this exists
          // node->items = ... // Populate from $3
          (yyval.ast_ptr) = node; // Placeholder - returns list node
      }
#line 1361 "yacc.tab.cpp"
    break;

  case 11: /* ConstDefList: ConstDef  */
#line 120 "yacc.y"
               { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); }
#line 1367 "yacc.tab.cpp"
    break;

  case 12: /* ConstDefList: ConstDefList COMMA ConstDef  */
#line 121 "yacc.y"
                                  { delete (yyvsp[-2].ast_ptr); (yyval.ast_ptr) = (yyvsp[0].ast_ptr); /* Incorrect */ }
#line 1373 "yacc.tab.cpp"
    break;

  case 13: /* ConstDef: IDENT ArraySpecifierOpt ASSIGN ConstInitVal  */
#line 126 "yacc.y"
      {
          // Assuming ConstDefAST exists and takes ident, array spec, initval
          auto node = new ConstDefAST((yyvsp[-3].str_val)); 
          // if ($2) node->array_specifier.reset($2);
          // node->value.reset($4);
          free((yyvsp[-3].str_val));
          (yyval.ast_ptr) = node;
      }
#line 1386 "yacc.tab.cpp"
    break;

  case 14: /* ArraySpecifierOpt: %empty  */
#line 137 "yacc.y"
                    { (yyval.ast_ptr) = nullptr; }
#line 1392 "yacc.tab.cpp"
    break;

  case 15: /* ArraySpecifierOpt: LBRACK ConstExp RBRACK  */
#line 138 "yacc.y"
                             { (yyval.ast_ptr) = (yyvsp[-1].ast_ptr); }
#line 1398 "yacc.tab.cpp"
    break;

  case 16: /* ConstInitVal: ConstExp  */
#line 142 "yacc.y"
               { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); }
#line 1404 "yacc.tab.cpp"
    break;

  case 17: /* ConstInitVal: LBRACE RBRACE  */
#line 143 "yacc.y"
                    { (yyval.ast_ptr) = nullptr; /* TODO: Needs InitListAST? */ }
#line 1410 "yacc.tab.cpp"
    break;

  case 18: /* ConstInitVal: LBRACE ConstInitValList RBRACE  */
#line 144 "yacc.y"
                                     { (yyval.ast_ptr) = (yyvsp[-1].ast_ptr); /* Incorrect list */ }
#line 1416 "yacc.tab.cpp"
    break;

  case 19: /* ConstInitValList: ConstInitVal  */
#line 148 "yacc.y"
                   { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); }
#line 1422 "yacc.tab.cpp"
    break;

  case 20: /* ConstInitValList: ConstInitValList COMMA ConstInitVal  */
#line 149 "yacc.y"
                                          { delete (yyvsp[-2].ast_ptr); (yyval.ast_ptr) = (yyvsp[0].ast_ptr); /* Incorrect */ }
#line 1428 "yacc.tab.cpp"
    break;

  case 21: /* VarDecl: INT VarDefList  */
#line 154 "yacc.y"
      {
          // Assuming VarDeclAST holds multiple VarDefs
          auto node = new VarDeclListAST(); // Assuming this exists
          // node->items = ... // Populate from $2
          (yyval.ast_ptr) = node; // Placeholder
      }
#line 1439 "yacc.tab.cpp"
    break;

  case 22: /* VarDefList: VarDef  */
#line 163 "yacc.y"
             { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); }
#line 1445 "yacc.tab.cpp"
    break;

  case 23: /* VarDefList: VarDefList COMMA VarDef  */
#line 164 "yacc.y"
                              { delete (yyvsp[-2].ast_ptr); (yyval.ast_ptr) = (yyvsp[0].ast_ptr); /* Incorrect */ }
#line 1451 "yacc.tab.cpp"
    break;

  case 24: /* VarDef: IDENT ArraySpecifierOpt  */
#line 169 "yacc.y"
      {
          // Assuming VarDefAST exists 
          auto node = new VarDefAST((yyvsp[-1].str_val));
          // if ($2) node->array_specifier.reset($2);
          free((yyvsp[-1].str_val));
          (yyval.ast_ptr) = node;
      }
#line 1463 "yacc.tab.cpp"
    break;

  case 25: /* VarDef: IDENT ArraySpecifierOpt ASSIGN InitVal  */
#line 177 "yacc.y"
      {
          auto node = new VarDefAST((yyvsp[-3].str_val));
          // if ($2) node->array_specifier.reset($2);
          // node->initializer.reset($4); 
          free((yyvsp[-3].str_val));
          (yyval.ast_ptr) = node;
      }
#line 1475 "yacc.tab.cpp"
    break;

  case 26: /* InitVal: Exp  */
#line 187 "yacc.y"
          { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); }
#line 1481 "yacc.tab.cpp"
    break;

  case 27: /* InitVal: LBRACE RBRACE  */
#line 188 "yacc.y"
                    { (yyval.ast_ptr) = nullptr; /* TODO: Needs InitListAST? */ }
#line 1487 "yacc.tab.cpp"
    break;

  case 28: /* InitVal: LBRACE InitValList RBRACE  */
#line 189 "yacc.y"
                                { (yyval.ast_ptr) = (yyvsp[-1].ast_ptr); /* Incorrect list */ }
#line 1493 "yacc.tab.cpp"
    break;

  case 29: /* InitValList: InitVal  */
#line 193 "yacc.y"
              { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); }
#line 1499 "yacc.tab.cpp"
    break;

  case 30: /* InitValList: InitValList COMMA InitVal  */
#line 194 "yacc.y"
                                { delete (yyvsp[-2].ast_ptr); (yyval.ast_ptr) = (yyvsp[0].ast_ptr); /* Incorrect */ }
#line 1505 "yacc.tab.cpp"
    break;

  case 31: /* FuncDef: VOID IDENT LPARENT OptionalFuncFParams RPARENT Block  */
#line 199 "yacc.y"
      {
          auto node = new FuncDefAST(TYPE_VOID, (yyvsp[-4].str_val));
          // node->params = ... // Populate from $4 (list)
          node->block.reset((yyvsp[0].ast_ptr));
          free((yyvsp[-4].str_val));
          (yyval.ast_ptr) = node;
      }
#line 1517 "yacc.tab.cpp"
    break;

  case 32: /* FuncDef: INT IDENT LPARENT OptionalFuncFParams RPARENT Block  */
#line 207 "yacc.y"
      {
          auto node = new FuncDefAST(TYPE_INT, (yyvsp[-4].str_val));
          // node->params = ... // Populate from $4 (list)
          node->block.reset((yyvsp[0].ast_ptr));
          free((yyvsp[-4].str_val));
          (yyval.ast_ptr) = node;
      }
#line 1529 "yacc.tab.cpp"
    break;

  case 33: /* OptionalFuncFParams: %empty  */
#line 219 "yacc.y"
                    { (yyval.ast_ptr) = nullptr; }
#line 1535 "yacc.tab.cpp"
    break;

  case 34: /* OptionalFuncFParams: FuncParams  */
#line 220 "yacc.y"
                 { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); /* Incorrect */ }
#line 1541 "yacc.tab.cpp"
    break;

  case 35: /* FuncParams: FuncFParam  */
#line 224 "yacc.y"
                 { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); }
#line 1547 "yacc.tab.cpp"
    break;

  case 36: /* FuncParams: FuncParams COMMA FuncFParam  */
#line 225 "yacc.y"
                                  { delete (yyvsp[-2].ast_ptr); (yyval.ast_ptr) = (yyvsp[0].ast_ptr); /* Incorrect */ }
#line 1553 "yacc.tab.cpp"
    break;

  case 37: /* FuncFParam: INT IDENT  */
#line 230 "yacc.y"
      {
          auto node = new FuncParamAST(TYPE_INT, (yyvsp[0].str_val));
          free((yyvsp[0].str_val));
          (yyval.ast_ptr) = node;
      }
#line 1563 "yacc.tab.cpp"
    break;

  case 38: /* MainFuncDef: INT MAIN LPARENT RPARENT Block  */
#line 239 "yacc.y"
      {
          auto node = new MainFuncDefAST();
          node->block.reset((yyvsp[0].ast_ptr));
          (yyval.ast_ptr) = node;
      }
#line 1573 "yacc.tab.cpp"
    break;

  case 39: /* Block: LBRACE BlockItemList RBRACE  */
#line 248 "yacc.y"
      {
          auto node = new BlockAST();
          // node->items = ... // Populate from $2 (list)
          (yyval.ast_ptr) = node; 
      }
#line 1583 "yacc.tab.cpp"
    break;

  case 40: /* BlockItemList: %empty  */
#line 256 "yacc.y"
                    { (yyval.ast_ptr) = nullptr; }
#line 1589 "yacc.tab.cpp"
    break;

  case 41: /* BlockItemList: BlockItemList BlockItem  */
#line 257 "yacc.y"
                              { delete (yyvsp[-1].ast_ptr); (yyval.ast_ptr) = (yyvsp[0].ast_ptr); /* Incorrect */ }
#line 1595 "yacc.tab.cpp"
    break;

  case 42: /* BlockItem: Decl  */
#line 261 "yacc.y"
           { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); }
#line 1601 "yacc.tab.cpp"
    break;

  case 43: /* BlockItem: Stmt  */
#line 262 "yacc.y"
           { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); }
#line 1607 "yacc.tab.cpp"
    break;

  case 44: /* Stmt: LVal ASSIGN Exp SEMICN  */
#line 267 "yacc.y"
      { 
          // Assume StmtAST has kind, and maybe specific fields or sub-nodes
          auto node = new StmtAST(); node->kind = StmtAST::ASSIGNMENT;
          // Need specific AssignStmtAST or store lval/exp in StmtAST
          // node->lval.reset($1); node->exp.reset($3); 
          (yyval.ast_ptr) = node; 
      }
#line 1619 "yacc.tab.cpp"
    break;

  case 45: /* Stmt: OptionalExp SEMICN  */
#line 275 "yacc.y"
      { 
          auto node = new StmtAST(); node->kind = StmtAST::EXP_STMT;
          // if ($1) node->exp.reset($1); 
          (yyval.ast_ptr) = node; 
      }
#line 1629 "yacc.tab.cpp"
    break;

  case 46: /* Stmt: Block  */
#line 281 "yacc.y"
      { 
          auto node = new StmtAST(); node->kind = StmtAST::BLOCK_STMT;
          // node->block.reset($1);
          (yyval.ast_ptr) = node;
      }
#line 1639 "yacc.tab.cpp"
    break;

  case 47: /* Stmt: IF LPARENT Cond RPARENT Stmt  */
#line 287 "yacc.y"
      { 
          auto node = new StmtAST(); node->kind = StmtAST::IF_STMT;
          // node->cond.reset($3); node->then_stmt.reset($5);
          (yyval.ast_ptr) = node;
      }
#line 1649 "yacc.tab.cpp"
    break;

  case 48: /* Stmt: IF LPARENT Cond RPARENT Stmt ELSE Stmt  */
#line 293 "yacc.y"
      { 
          auto node = new StmtAST(); node->kind = StmtAST::IF_ELSE_STMT;
          // node->cond.reset($3); node->then_stmt.reset($5); node->else_stmt.reset($7);
          (yyval.ast_ptr) = node;
      }
#line 1659 "yacc.tab.cpp"
    break;

  case 49: /* Stmt: WHILE LPARENT Cond RPARENT Stmt  */
#line 299 "yacc.y"
      { 
          auto node = new StmtAST(); node->kind = StmtAST::WHILE_STMT;
          // node->cond.reset($3); node->body.reset($5);
          (yyval.ast_ptr) = node;
      }
#line 1669 "yacc.tab.cpp"
    break;

  case 50: /* Stmt: BREAK SEMICN  */
#line 305 "yacc.y"
      { auto node = new StmtAST(); node->kind = StmtAST::BREAK_STMT; (yyval.ast_ptr) = node; }
#line 1675 "yacc.tab.cpp"
    break;

  case 51: /* Stmt: CONTINUE SEMICN  */
#line 307 "yacc.y"
      { auto node = new StmtAST(); node->kind = StmtAST::CONTINUE_STMT; (yyval.ast_ptr) = node; }
#line 1681 "yacc.tab.cpp"
    break;

  case 52: /* Stmt: RETURN OptionalExp SEMICN  */
#line 309 "yacc.y"
      { 
          auto node = new StmtAST(); node->kind = StmtAST::RETURN_STMT;
          // if ($2) node->return_exp.reset($2);
          (yyval.ast_ptr) = node;
      }
#line 1691 "yacc.tab.cpp"
    break;

  case 53: /* Stmt: LVal ASSIGN GETINT LPARENT RPARENT SEMICN  */
#line 315 "yacc.y"
      { 
          auto node = new StmtAST(); node->kind = StmtAST::ASSIGN_GETINT_STMT;
          // node->lval.reset($1); 
          (yyval.ast_ptr) = node; 
      }
#line 1701 "yacc.tab.cpp"
    break;

  case 54: /* Stmt: PRINTF LPARENT STR_CONST OptionalPrintfArgs RPARENT SEMICN  */
#line 321 "yacc.y"
      { 
          auto node = new StmtAST(); node->kind = StmtAST::PRINTF_STMT;
          // node->format_string = $3; // Need to handle string copy/ownership
          // node->args = ... // Populate from $4 (list)
          free((yyvsp[-3].str_val)); 
          (yyval.ast_ptr) = node; 
      }
#line 1713 "yacc.tab.cpp"
    break;

  case 55: /* OptionalExp: %empty  */
#line 331 "yacc.y"
                    { (yyval.ast_ptr) = nullptr; }
#line 1719 "yacc.tab.cpp"
    break;

  case 56: /* OptionalExp: Exp  */
#line 332 "yacc.y"
          { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); }
#line 1725 "yacc.tab.cpp"
    break;

  case 57: /* OptionalPrintfArgs: %empty  */
#line 336 "yacc.y"
                    { (yyval.ast_ptr) = nullptr; }
#line 1731 "yacc.tab.cpp"
    break;

  case 58: /* OptionalPrintfArgs: PrintfArgsList  */
#line 337 "yacc.y"
                     { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); /* Incorrect */ }
#line 1737 "yacc.tab.cpp"
    break;

  case 59: /* PrintfArgsList: COMMA Exp  */
#line 341 "yacc.y"
                { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); }
#line 1743 "yacc.tab.cpp"
    break;

  case 60: /* PrintfArgsList: PrintfArgsList COMMA Exp  */
#line 342 "yacc.y"
                               { delete (yyvsp[-2].ast_ptr); (yyval.ast_ptr) = (yyvsp[0].ast_ptr); /* Incorrect */ }
#line 1749 "yacc.tab.cpp"
    break;

  case 61: /* Exp: AddExp  */
#line 345 "yacc.y"
                 { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); }
#line 1755 "yacc.tab.cpp"
    break;

  case 62: /* Cond: LOrExp  */
#line 346 "yacc.y"
                 { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); }
#line 1761 "yacc.tab.cpp"
    break;

  case 63: /* LVal: IDENT LValArrayOpt  */
#line 350 "yacc.y"
      { 
          // Assuming LValAST exists
          auto node = new LValAST((yyvsp[-1].str_val)); 
          // if ($2) node->array_index.reset($2); 
          free((yyvsp[-1].str_val)); 
          (yyval.ast_ptr) = node; 
      }
#line 1773 "yacc.tab.cpp"
    break;

  case 64: /* LValArrayOpt: %empty  */
#line 359 "yacc.y"
                    { (yyval.ast_ptr) = nullptr; }
#line 1779 "yacc.tab.cpp"
    break;

  case 65: /* LValArrayOpt: LBRACK Exp RBRACK  */
#line 360 "yacc.y"
                        { (yyval.ast_ptr) = (yyvsp[-1].ast_ptr); }
#line 1785 "yacc.tab.cpp"
    break;

  case 66: /* PrimaryExp: LPARENT Exp RPARENT  */
#line 364 "yacc.y"
                          { (yyval.ast_ptr) = (yyvsp[-1].ast_ptr); }
#line 1791 "yacc.tab.cpp"
    break;

  case 67: /* PrimaryExp: LVal  */
#line 365 "yacc.y"
           { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); }
#line 1797 "yacc.tab.cpp"
    break;

  case 68: /* PrimaryExp: Number  */
#line 366 "yacc.y"
             { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); }
#line 1803 "yacc.tab.cpp"
    break;

  case 69: /* Number: INT_CONST  */
#line 369 "yacc.y"
                { (yyval.ast_ptr) = new NumberAST((yyvsp[0].int_val)); }
#line 1809 "yacc.tab.cpp"
    break;

  case 70: /* UnaryExp: PrimaryExp  */
#line 373 "yacc.y"
                 { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); }
#line 1815 "yacc.tab.cpp"
    break;

  case 71: /* UnaryExp: IDENT LPARENT OptionalFuncRParams RPARENT  */
#line 375 "yacc.y"
      { 
          // Assuming FuncCallAST exists
          auto node = new FuncCallAST((yyvsp[-3].str_val)); 
          // node->args = ... // Populate from $3 (list)
          free((yyvsp[-3].str_val)); 
          (yyval.ast_ptr) = node; 
      }
#line 1827 "yacc.tab.cpp"
    break;

  case 72: /* UnaryExp: UnaryOp UnaryExp  */
#line 383 "yacc.y"
      { 
          // Assuming UnaryExpAST exists
          auto node = new UnaryExpAST(); 
          // node->op = ... // Get op from $1
          // node->operand.reset($2); 
          delete (yyvsp[-1].ast_ptr); // Delete temporary UnaryOp node
          (yyval.ast_ptr) = node; 
      }
#line 1840 "yacc.tab.cpp"
    break;

  case 73: /* OptionalFuncRParams: %empty  */
#line 394 "yacc.y"
                    { (yyval.ast_ptr) = nullptr; }
#line 1846 "yacc.tab.cpp"
    break;

  case 74: /* OptionalFuncRParams: FuncRParamsList  */
#line 395 "yacc.y"
                      { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); /* Incorrect */ }
#line 1852 "yacc.tab.cpp"
    break;

  case 75: /* FuncRParamsList: Exp  */
#line 399 "yacc.y"
          { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); }
#line 1858 "yacc.tab.cpp"
    break;

  case 76: /* FuncRParamsList: FuncRParamsList COMMA Exp  */
#line 400 "yacc.y"
                                { delete (yyvsp[-2].ast_ptr); (yyval.ast_ptr) = (yyvsp[0].ast_ptr); /* Incorrect */ }
#line 1864 "yacc.tab.cpp"
    break;

  case 77: /* UnaryOp: PLUS  */
#line 404 "yacc.y"
           { auto node = new UnaryOpAST(OP_PLUS); (yyval.ast_ptr) = node; }
#line 1870 "yacc.tab.cpp"
    break;

  case 78: /* UnaryOp: MINU  */
#line 405 "yacc.y"
           { auto node = new UnaryOpAST(OP_MINUS); (yyval.ast_ptr) = node; }
#line 1876 "yacc.tab.cpp"
    break;

  case 79: /* UnaryOp: NOT  */
#line 406 "yacc.y"
           { auto node = new UnaryOpAST(OP_NOT); (yyval.ast_ptr) = node; }
#line 1882 "yacc.tab.cpp"
    break;

  case 80: /* MulExp: UnaryExp  */
#line 411 "yacc.y"
               { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); }
#line 1888 "yacc.tab.cpp"
    break;

  case 81: /* MulExp: MulExp MULT UnaryExp  */
#line 412 "yacc.y"
                           { auto node = new BinaryExpAST(OP_MULT); node->left.reset((yyvsp[-2].ast_ptr)); node->right.reset((yyvsp[0].ast_ptr)); (yyval.ast_ptr) = node; }
#line 1894 "yacc.tab.cpp"
    break;

  case 82: /* MulExp: MulExp DIV UnaryExp  */
#line 413 "yacc.y"
                           { auto node = new BinaryExpAST(OP_DIV);  node->left.reset((yyvsp[-2].ast_ptr)); node->right.reset((yyvsp[0].ast_ptr)); (yyval.ast_ptr) = node; }
#line 1900 "yacc.tab.cpp"
    break;

  case 83: /* MulExp: MulExp MOD UnaryExp  */
#line 414 "yacc.y"
                           { auto node = new BinaryExpAST(OP_MOD);  node->left.reset((yyvsp[-2].ast_ptr)); node->right.reset((yyvsp[0].ast_ptr)); (yyval.ast_ptr) = node; }
#line 1906 "yacc.tab.cpp"
    break;

  case 84: /* AddExp: MulExp  */
#line 417 "yacc.y"
             { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); }
#line 1912 "yacc.tab.cpp"
    break;

  case 85: /* AddExp: AddExp PLUS MulExp  */
#line 418 "yacc.y"
                         { auto node = new BinaryExpAST(OP_PLUS); node->left.reset((yyvsp[-2].ast_ptr)); node->right.reset((yyvsp[0].ast_ptr)); (yyval.ast_ptr) = node; }
#line 1918 "yacc.tab.cpp"
    break;

  case 86: /* AddExp: AddExp MINU MulExp  */
#line 419 "yacc.y"
                         { auto node = new BinaryExpAST(OP_MINUS); node->left.reset((yyvsp[-2].ast_ptr)); node->right.reset((yyvsp[0].ast_ptr)); (yyval.ast_ptr) = node; }
#line 1924 "yacc.tab.cpp"
    break;

  case 87: /* RelExp: AddExp  */
#line 422 "yacc.y"
             { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); }
#line 1930 "yacc.tab.cpp"
    break;

  case 88: /* RelExp: RelExp LSS AddExp  */
#line 423 "yacc.y"
                        { auto node = new BinaryExpAST(OP_LSS); node->left.reset((yyvsp[-2].ast_ptr)); node->right.reset((yyvsp[0].ast_ptr)); (yyval.ast_ptr) = node; }
#line 1936 "yacc.tab.cpp"
    break;

  case 89: /* RelExp: RelExp GRE AddExp  */
#line 424 "yacc.y"
                        { auto node = new BinaryExpAST(OP_GRE); node->left.reset((yyvsp[-2].ast_ptr)); node->right.reset((yyvsp[0].ast_ptr)); (yyval.ast_ptr) = node; }
#line 1942 "yacc.tab.cpp"
    break;

  case 90: /* RelExp: RelExp LEQ AddExp  */
#line 425 "yacc.y"
                        { auto node = new BinaryExpAST(OP_LEQ); node->left.reset((yyvsp[-2].ast_ptr)); node->right.reset((yyvsp[0].ast_ptr)); (yyval.ast_ptr) = node; }
#line 1948 "yacc.tab.cpp"
    break;

  case 91: /* RelExp: RelExp GEQ AddExp  */
#line 426 "yacc.y"
                        { auto node = new BinaryExpAST(OP_GEQ); node->left.reset((yyvsp[-2].ast_ptr)); node->right.reset((yyvsp[0].ast_ptr)); (yyval.ast_ptr) = node; }
#line 1954 "yacc.tab.cpp"
    break;

  case 92: /* EqExp: RelExp  */
#line 429 "yacc.y"
             { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); }
#line 1960 "yacc.tab.cpp"
    break;

  case 93: /* EqExp: EqExp EQL RelExp  */
#line 430 "yacc.y"
                       { auto node = new BinaryExpAST(OP_EQL); node->left.reset((yyvsp[-2].ast_ptr)); node->right.reset((yyvsp[0].ast_ptr)); (yyval.ast_ptr) = node; }
#line 1966 "yacc.tab.cpp"
    break;

  case 94: /* EqExp: EqExp NEQ RelExp  */
#line 431 "yacc.y"
                       { auto node = new BinaryExpAST(OP_NEQ); node->left.reset((yyvsp[-2].ast_ptr)); node->right.reset((yyvsp[0].ast_ptr)); (yyval.ast_ptr) = node; }
#line 1972 "yacc.tab.cpp"
    break;

  case 95: /* LAndExp: EqExp  */
#line 434 "yacc.y"
            { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); }
#line 1978 "yacc.tab.cpp"
    break;

  case 96: /* LAndExp: LAndExp AND EqExp  */
#line 435 "yacc.y"
                        { auto node = new BinaryExpAST(OP_AND); node->left.reset((yyvsp[-2].ast_ptr)); node->right.reset((yyvsp[0].ast_ptr)); (yyval.ast_ptr) = node; }
#line 1984 "yacc.tab.cpp"
    break;

  case 97: /* LOrExp: LAndExp  */
#line 438 "yacc.y"
              { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); }
#line 1990 "yacc.tab.cpp"
    break;

  case 98: /* LOrExp: LOrExp OR LAndExp  */
#line 439 "yacc.y"
                        { auto node = new BinaryExpAST(OP_OR); node->left.reset((yyvsp[-2].ast_ptr)); node->right.reset((yyvsp[0].ast_ptr)); (yyval.ast_ptr) = node; }
#line 1996 "yacc.tab.cpp"
    break;

  case 99: /* ConstExp: AddExp  */
#line 443 "yacc.y"
             { (yyval.ast_ptr) = (yyvsp[0].ast_ptr); }
#line 2002 "yacc.tab.cpp"
    break;


#line 2006 "yacc.tab.cpp"

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

#line 447 "yacc.y"
 

/* User Code Section */
#include <stdio.h>
#include <iostream> // Needed for unique_ptr declaration if not included by %code requires

// Define the global root pointer (must match declaration in %code provides)
std::unique_ptr<BaseAST> root;

extern char *yytext;
// extern int yylex(); // Already declared above

void yyerror(const char *s) {
    // Bison expects this function to be defined.
    // yytext might not point to the exact error location due to lookahead.
    fprintf(stderr, "Syntax error: %s near '%s'\n", s, yytext ? yytext : "<unknown>");
    // Consider adding line number tracking in lexer for better errors
    exit(1);
}

// Main function is in main.cpp, no need for one here 
