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
#line 1 "Suraj_Sharma_PA4.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Suraj_Sharma_PA4_translator.h"

#define MAX_FILENAME_LEN 256

int yylex(void);
void yyerror(const char *s);
extern int yylineno; 
extern char *yytext;
extern FILE *yyin;

#line 86 "Suraj_Sharma_PA4.tab.c"

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

#include "Suraj_Sharma_PA4.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_PROGRAM = 3,                    /* PROGRAM  */
  YYSYMBOL_FUNCTION = 4,                   /* FUNCTION  */
  YYSYMBOL_VAR = 5,                        /* VAR  */
  YYSYMBOL_INTEGER = 6,                    /* INTEGER  */
  YYSYMBOL_STRING = 7,                     /* STRING  */
  YYSYMBOL_WHILE = 8,                      /* WHILE  */
  YYSYMBOL_DO = 9,                         /* DO  */
  YYSYMBOL_IF = 10,                        /* IF  */
  YYSYMBOL_THEN = 11,                      /* THEN  */
  YYSYMBOL_ELSE = 12,                      /* ELSE  */
  YYSYMBOL_BEGIN_ = 13,                    /* BEGIN_  */
  YYSYMBOL_END_ = 14,                      /* END_  */
  YYSYMBOL_identifier = 15,                /* identifier  */
  YYSYMBOL_constant = 16,                  /* constant  */
  YYSYMBOL_string_literal = 17,            /* string_literal  */
  YYSYMBOL_relop = 18,                     /* relop  */
  YYSYMBOL_addop = 19,                     /* addop  */
  YYSYMBOL_mulop = 20,                     /* mulop  */
  YYSYMBOL_LPAREN = 21,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 22,                    /* RPAREN  */
  YYSYMBOL_comma = 23,                     /* comma  */
  YYSYMBOL_semicolon = 24,                 /* semicolon  */
  YYSYMBOL_colon = 25,                     /* colon  */
  YYSYMBOL_period = 26,                    /* period  */
  YYSYMBOL_assignop = 27,                  /* assignop  */
  YYSYMBOL_YYACCEPT = 28,                  /* $accept  */
  YYSYMBOL_program = 29,                   /* program  */
  YYSYMBOL_declaration_list_opt = 30,      /* declaration_list_opt  */
  YYSYMBOL_declaration_list = 31,          /* declaration_list  */
  YYSYMBOL_variable_list = 32,             /* variable_list  */
  YYSYMBOL_type = 33,                      /* type  */
  YYSYMBOL_function_declaration_list_opt = 34, /* function_declaration_list_opt  */
  YYSYMBOL_function_declaration_list = 35, /* function_declaration_list  */
  YYSYMBOL_function_declaration = 36,      /* function_declaration  */
  YYSYMBOL_function_intro = 37,            /* function_intro  */
  YYSYMBOL_function_header = 38,           /* function_header  */
  YYSYMBOL_parameter_list = 39,            /* parameter_list  */
  YYSYMBOL_compound_statement = 40,        /* compound_statement  */
  YYSYMBOL_statement_list = 41,            /* statement_list  */
  YYSYMBOL_statement = 42,                 /* statement  */
  YYSYMBOL_selection_statement = 43,       /* selection_statement  */
  YYSYMBOL_iteration_statement = 44,       /* iteration_statement  */
  YYSYMBOL_function_statement = 45,        /* function_statement  */
  YYSYMBOL_expression_list = 46,           /* expression_list  */
  YYSYMBOL_expression = 47,                /* expression  */
  YYSYMBOL_simple_expression = 48,         /* simple_expression  */
  YYSYMBOL_term = 49,                      /* term  */
  YYSYMBOL_factor = 50,                    /* factor  */
  YYSYMBOL_M = 51                          /* M  */
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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   79

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  28
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  43
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  94

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   282


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
      25,    26,    27
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    58,    58,    65,    65,    69,    81,    85,    92,    93,
      97,    97,   101,   105,   117,   126,   137,   146,   158,   165,
     169,   179,   188,   189,   190,   191,   195,   204,   214,   228,
     264,   268,   275,   279,   304,   308,   322,   326,   340,   348,
     360,   371,   375,   399
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
  "\"end of file\"", "error", "\"invalid token\"", "PROGRAM", "FUNCTION",
  "VAR", "INTEGER", "STRING", "WHILE", "DO", "IF", "THEN", "ELSE",
  "BEGIN_", "END_", "identifier", "constant", "string_literal", "relop",
  "addop", "mulop", "LPAREN", "RPAREN", "comma", "semicolon", "colon",
  "period", "assignop", "$accept", "program", "declaration_list_opt",
  "declaration_list", "variable_list", "type",
  "function_declaration_list_opt", "function_declaration_list",
  "function_declaration", "function_intro", "function_header",
  "parameter_list", "compound_statement", "statement_list", "statement",
  "selection_statement", "iteration_statement", "function_statement",
  "expression_list", "expression", "simple_expression", "term", "factor",
  "M", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-63)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      27,    23,     9,    -3,   -63,   -63,    40,   -63,    33,     2,
     -63,   -63,   -15,    39,    14,    35,    37,   -63,    36,    45,
      44,   -63,   -63,    19,    10,   -63,    -7,   -63,   -63,   -63,
     -63,   -63,    33,     6,   -63,   -63,   -63,   -63,    41,    19,
      42,   -63,   -63,    19,    50,    -6,    46,   -63,    19,    19,
     -63,    14,    18,    22,   -63,   -63,    55,    19,    47,   -63,
      19,    19,    19,    30,   -63,   -63,   -63,    44,    43,    33,
     -63,    34,   -63,    14,    48,    46,   -63,   -63,    19,   -63,
      44,    24,    14,   -63,    58,   -63,    49,    44,   -63,   -63,
     -63,   -63,    14,   -63
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     4,    11,     3,     0,     0,
      10,     6,     0,     0,     0,     0,     0,     4,     0,     0,
       0,    14,    43,     0,     0,    24,     0,    19,    22,    23,
      25,    12,     0,     0,     2,     7,     8,     9,     0,     0,
      38,    39,    40,     0,     0,    32,    34,    36,     0,     0,
      18,     0,     0,     0,    13,     5,     0,     0,     0,    43,
       0,     0,     0,     0,    30,    21,    20,     0,     0,     0,
      43,     0,    41,     0,    33,    35,    37,    29,     0,    16,
       0,     0,     0,    42,    27,    31,     0,     0,    28,    43,
      15,    17,     0,    26
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -63,   -63,    54,   -63,   -30,   -62,   -63,   -63,   -63,   -63,
     -63,   -63,    -5,   -63,   -50,   -63,   -63,   -63,    15,   -23,
      16,    13,    17,   -56
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     6,     7,    12,    38,     9,    10,    15,    16,
      17,    53,    25,    26,    27,    28,    29,    30,    63,    64,
      45,    46,    47,    39
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      44,    66,    52,    73,    18,    79,    13,    50,    19,     4,
      20,     8,    60,    61,    82,    14,    56,    51,    86,    14,
      58,     5,    22,    84,    23,    91,    65,    14,    54,    24,
       1,    48,    88,    92,    40,    41,    42,    49,     3,    81,
      43,    19,    93,    67,    68,     8,    69,    19,    11,    87,
      36,    37,    77,    78,    21,    85,    83,    78,    32,    31,
      35,    59,    34,    57,    70,    55,    62,    61,    80,    72,
      89,    33,    71,    90,    75,     0,    74,     0,     0,    76
};

static const yytype_int8 yycheck[] =
{
      23,    51,    32,    59,     9,    67,     4,    14,    23,     0,
      25,     5,    18,    19,    70,    13,    39,    24,    80,    13,
      43,    24,     8,    73,    10,    87,    49,    13,    33,    15,
       3,    21,    82,    89,    15,    16,    17,    27,    15,    69,
      21,    23,    92,    25,    22,     5,    24,    23,    15,    25,
       6,     7,    22,    23,    15,    78,    22,    23,    21,    24,
      15,    11,    26,    21,     9,    24,    20,    19,    25,    22,
      12,    17,    57,    24,    61,    -1,    60,    -1,    -1,    62
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    29,    15,     0,    24,    30,    31,     5,    34,
      35,    15,    32,     4,    13,    36,    37,    38,    40,    23,
      25,    15,     8,    10,    15,    40,    41,    42,    43,    44,
      45,    24,    21,    30,    26,    15,     6,     7,    33,    51,
      15,    16,    17,    21,    47,    48,    49,    50,    21,    27,
      14,    24,    32,    39,    40,    24,    47,    21,    47,    11,
      18,    19,    20,    46,    47,    47,    42,    25,    22,    24,
       9,    46,    22,    51,    48,    49,    50,    22,    23,    33,
      25,    32,    51,    22,    42,    47,    33,    25,    42,    12,
      24,    33,    51,    42
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    28,    29,    30,    30,    31,    32,    32,    33,    33,
      34,    34,    35,    36,    37,    38,    39,    39,    40,    41,
      41,    42,    42,    42,    42,    42,    43,    43,    44,    45,
      46,    46,    47,    47,    48,    48,    49,    49,    50,    50,
      50,    50,    50,    51
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     7,     1,     0,     6,     1,     3,     1,     1,
       1,     0,     3,     3,     2,     7,     3,     5,     3,     1,
       3,     3,     1,     1,     1,     1,     8,     5,     6,     4,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     1,
       1,     3,     4,     0
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
  case 2: /* program: PROGRAM identifier semicolon declaration_list_opt function_declaration_list_opt compound_statement period  */
#line 59 "Suraj_Sharma_PA4.y"
        {
            emit(OP_STOP, NULL, NULL, NULL);
        }
#line 1182 "Suraj_Sharma_PA4.tab.c"
    break;

  case 5: /* declaration_list: declaration_list_opt VAR variable_list colon type semicolon  */
#line 70 "Suraj_Sharma_PA4.y"
        {
            symlist *curr = (yyvsp[-3].slist);
            int size = (strcmp((yyvsp[-1].sval), "INTEGER") == 0) ? SIZE_INT : SIZE_STRING;
            while (curr) {
                updateSymbolInfo(curr->sym, (yyvsp[-1].sval), size, "local");
                curr = curr->next;
            }
        }
#line 1195 "Suraj_Sharma_PA4.tab.c"
    break;

  case 6: /* variable_list: identifier  */
#line 82 "Suraj_Sharma_PA4.y"
        {
            (yyval.slist) = makeSymList((yyvsp[0].sym));
        }
#line 1203 "Suraj_Sharma_PA4.tab.c"
    break;

  case 7: /* variable_list: variable_list comma identifier  */
#line 86 "Suraj_Sharma_PA4.y"
        {
            (yyval.slist) = mergeSymLists((yyvsp[-2].slist), makeSymList((yyvsp[0].sym)));
        }
#line 1211 "Suraj_Sharma_PA4.tab.c"
    break;

  case 8: /* type: INTEGER  */
#line 92 "Suraj_Sharma_PA4.y"
                { (yyval.sval) = "INTEGER"; }
#line 1217 "Suraj_Sharma_PA4.tab.c"
    break;

  case 9: /* type: STRING  */
#line 93 "Suraj_Sharma_PA4.y"
                { (yyval.sval) = "STRING"; }
#line 1223 "Suraj_Sharma_PA4.tab.c"
    break;

  case 13: /* function_declaration: function_header declaration_list_opt compound_statement  */
#line 106 "Suraj_Sharma_PA4.y"
        {
            /* Return to parent scope */
            if (ST_current && ST_current->parent) {
                ST_current = find_symboltable_by_name(ST_current->parent);
            }
            emit(OP_RETURN, NULL, NULL, NULL); 
        }
#line 1235 "Suraj_Sharma_PA4.tab.c"
    break;

  case 14: /* function_intro: FUNCTION identifier  */
#line 118 "Suraj_Sharma_PA4.y"
        {
            ST_current = createSymbolTable((yyvsp[0].sym)->name);
            (yyvsp[0].sym)->nested_symboltable_name = xstrdup((yyvsp[0].sym)->name);
            (yyval.sym) = (yyvsp[0].sym); 
        }
#line 1245 "Suraj_Sharma_PA4.tab.c"
    break;

  case 15: /* function_header: function_intro LPAREN parameter_list RPAREN colon type semicolon  */
#line 127 "Suraj_Sharma_PA4.y"
        {
       
            updateSymbolInfo((yyvsp[-6].sym), (yyvsp[-1].sval), 0, NULL); 
            
            symbol *retVar = lookupSymbol((yyvsp[-6].sym)->name);
            updateSymbolInfo(retVar, (yyvsp[-1].sval), SIZE_INT, "return_var");
        }
#line 1257 "Suraj_Sharma_PA4.tab.c"
    break;

  case 16: /* parameter_list: variable_list colon type  */
#line 138 "Suraj_Sharma_PA4.y"
        {
             symlist *curr = (yyvsp[-2].slist);
             int size = (strcmp((yyvsp[0].sval), "INTEGER") == 0) ? SIZE_INT : SIZE_STRING;
             while (curr) {
                updateSymbolInfo(curr->sym, (yyvsp[0].sval), size, "param");
                curr = curr->next;
             }
        }
#line 1270 "Suraj_Sharma_PA4.tab.c"
    break;

  case 17: /* parameter_list: parameter_list semicolon variable_list colon type  */
#line 147 "Suraj_Sharma_PA4.y"
        {
             symlist *curr = (yyvsp[-2].slist);
             int size = (strcmp((yyvsp[0].sval), "INTEGER") == 0) ? SIZE_INT : SIZE_STRING;
             while (curr) {
                updateSymbolInfo(curr->sym, (yyvsp[0].sval), size, "param");
                curr = curr->next;
             }
        }
#line 1283 "Suraj_Sharma_PA4.tab.c"
    break;

  case 18: /* compound_statement: BEGIN_ statement_list END_  */
#line 159 "Suraj_Sharma_PA4.y"
        {
            (yyval.stmt) = (yyvsp[-1].stmt);
        }
#line 1291 "Suraj_Sharma_PA4.tab.c"
    break;

  case 19: /* statement_list: statement  */
#line 166 "Suraj_Sharma_PA4.y"
        {
            (yyval.stmt) = (yyvsp[0].stmt);
        }
#line 1299 "Suraj_Sharma_PA4.tab.c"
    break;

  case 20: /* statement_list: statement_list semicolon statement  */
#line 170 "Suraj_Sharma_PA4.y"
        {
            stmtattr res;
            if ((yyvsp[-2].stmt).nextlist) backpatch((yyvsp[-2].stmt).nextlist, (yyvsp[0].stmt).nextlist ? ((markerattr*)(&((yyvsp[0].stmt))))->instr : nextinstr()); 
            res.nextlist = (yyvsp[0].stmt).nextlist;
            (yyval.stmt) = res;
        }
#line 1310 "Suraj_Sharma_PA4.tab.c"
    break;

  case 21: /* statement: identifier assignop expression  */
#line 180 "Suraj_Sharma_PA4.y"
    {
        stmtattr res;
        res.nextlist = NULL;
        if ((yyvsp[0].expr).place) {
            emit(OP_COPY, (yyvsp[0].expr).place->name, NULL, (yyvsp[-2].sym)->name);
        }
        (yyval.stmt) = res;
    }
#line 1323 "Suraj_Sharma_PA4.tab.c"
    break;

  case 26: /* selection_statement: IF expression THEN M statement ELSE M statement  */
#line 196 "Suraj_Sharma_PA4.y"
    {
        backpatch((yyvsp[-6].expr).truelist, (yyvsp[-4].mark).instr);
        backpatch((yyvsp[-6].expr).falselist, (yyvsp[-1].mark).instr);
        stmtattr res;
        res.nextlist = mergeLists((yyvsp[-3].stmt).nextlist, (yyvsp[0].stmt).nextlist);
        res.nextlist = mergeLists(res.nextlist, (yyvsp[-6].expr).is_boolean ? NULL : NULL); 
        (yyval.stmt) = res;
    }
#line 1336 "Suraj_Sharma_PA4.tab.c"
    break;

  case 27: /* selection_statement: IF expression THEN M statement  */
#line 205 "Suraj_Sharma_PA4.y"
    {
        backpatch((yyvsp[-3].expr).truelist, (yyvsp[-1].mark).instr);
        stmtattr res;
        res.nextlist = mergeLists((yyvsp[0].stmt).nextlist, (yyvsp[-3].expr).falselist);
        (yyval.stmt) = res;
    }
#line 1347 "Suraj_Sharma_PA4.tab.c"
    break;

  case 28: /* iteration_statement: WHILE M expression DO M statement  */
#line 215 "Suraj_Sharma_PA4.y"
    {
        backpatch((yyvsp[-3].expr).truelist, (yyvsp[-1].mark).instr);
        backpatch((yyvsp[0].stmt).nextlist, (yyvsp[-4].mark).instr);
        char *t_start = int_to_str((yyvsp[-4].mark).instr);
        emit(OP_GOTO, NULL, NULL, t_start);
        free(t_start);
        stmtattr res;
        res.nextlist = (yyvsp[-3].expr).falselist;
        (yyval.stmt) = res;
    }
#line 1362 "Suraj_Sharma_PA4.tab.c"
    break;

  case 29: /* function_statement: identifier LPAREN expression_list RPAREN  */
#line 229 "Suraj_Sharma_PA4.y"
    {
        stmtattr res;
        res.nextlist = NULL;
        
        if (strcmp((yyvsp[-3].sym)->name, "readln") == 0 || strcmp((yyvsp[-3].sym)->name, "read") == 0) {
            arglist *cur = (yyvsp[-1].alist);
            while(cur) {
                emit(OP_READ, cur->name, NULL, NULL);
                cur = cur->next;
            }
        } 
        else if (strcmp((yyvsp[-3].sym)->name, "writeln") == 0 || strcmp((yyvsp[-3].sym)->name, "write") == 0) {
             arglist *cur = (yyvsp[-1].alist);
            while(cur) {
                emit(OP_PRINT, cur->name, NULL, NULL);
                cur = cur->next;
            }
        }
        else {
            int argc = 0;
            arglist *cur = (yyvsp[-1].alist);
            while (cur) {
                emit(OP_PARAM, cur->name, NULL, NULL);
                argc++;
                cur = cur->next;
            }
            char buf[10];
            snprintf(buf, 10, "%d", argc);
            emit(OP_CALL, (yyvsp[-3].sym)->name, buf, NULL); 
        }
        (yyval.stmt) = res;
    }
#line 1399 "Suraj_Sharma_PA4.tab.c"
    break;

  case 30: /* expression_list: expression  */
#line 265 "Suraj_Sharma_PA4.y"
    {
        (yyval.alist) = makeArgList((yyvsp[0].expr).place ? (yyvsp[0].expr).place->name : "");
    }
#line 1407 "Suraj_Sharma_PA4.tab.c"
    break;

  case 31: /* expression_list: expression_list comma expression  */
#line 269 "Suraj_Sharma_PA4.y"
    {
        (yyval.alist) = mergeArgLists((yyvsp[-2].alist), makeArgList((yyvsp[0].expr).place ? (yyvsp[0].expr).place->name : ""));
    }
#line 1415 "Suraj_Sharma_PA4.tab.c"
    break;

  case 32: /* expression: simple_expression  */
#line 276 "Suraj_Sharma_PA4.y"
    {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 1423 "Suraj_Sharma_PA4.tab.c"
    break;

  case 33: /* expression: simple_expression relop simple_expression  */
#line 280 "Suraj_Sharma_PA4.y"
    {
        exprattr res;
        res.is_boolean = 1;
        res.place = NULL;
        
        Opcode op = OP_IF_EQ; 
        switch((yyvsp[-1].num)) {
            case RELOP_LT: op = OP_IF_LT; break;
            case RELOP_LE: op = OP_IF_LE; break;
            case RELOP_GT: op = OP_IF_GT; break;
            case RELOP_GE: op = OP_IF_GE; break;
            case RELOP_EQ: op = OP_IF_EQ; break;
            case RELOP_NE: op = OP_IF_NE; break;
        }

        res.truelist = makeList(nextinstr());
        res.falselist = makeList(nextinstr() + 1);
        emit(op, (yyvsp[-2].expr).place ? (yyvsp[-2].expr).place->name : NULL, (yyvsp[0].expr).place ? (yyvsp[0].expr).place->name : NULL, NULL);
        emit(OP_GOTO, NULL, NULL, NULL);
        (yyval.expr) = res;
    }
#line 1449 "Suraj_Sharma_PA4.tab.c"
    break;

  case 34: /* simple_expression: term  */
#line 305 "Suraj_Sharma_PA4.y"
    {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 1457 "Suraj_Sharma_PA4.tab.c"
    break;

  case 35: /* simple_expression: simple_expression addop term  */
#line 309 "Suraj_Sharma_PA4.y"
    {
        exprattr res;
        res.is_boolean = 0;
        res.truelist = res.falselist = NULL;
        symbol *t = genTemp("INTEGER");
        if ((yyvsp[-1].num) == '+') emit(OP_ADD, (yyvsp[-2].expr).place ? (yyvsp[-2].expr).place->name : NULL, (yyvsp[0].expr).place ? (yyvsp[0].expr).place->name : NULL, t->name);
        else emit(OP_SUB, (yyvsp[-2].expr).place ? (yyvsp[-2].expr).place->name : NULL, (yyvsp[0].expr).place ? (yyvsp[0].expr).place->name : NULL, t->name);
        res.place = t;
        (yyval.expr) = res;
    }
#line 1472 "Suraj_Sharma_PA4.tab.c"
    break;

  case 36: /* term: factor  */
#line 323 "Suraj_Sharma_PA4.y"
    {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 1480 "Suraj_Sharma_PA4.tab.c"
    break;

  case 37: /* term: term mulop factor  */
#line 327 "Suraj_Sharma_PA4.y"
    {
        exprattr res;
        res.is_boolean = 0;
        res.truelist = res.falselist = NULL;
        symbol *t = genTemp("INTEGER");
        if ((yyvsp[-1].num) == '*') emit(OP_MUL, (yyvsp[-2].expr).place ? (yyvsp[-2].expr).place->name : NULL, (yyvsp[0].expr).place ? (yyvsp[0].expr).place->name : NULL, t->name);
        else emit(OP_DIV, (yyvsp[-2].expr).place ? (yyvsp[-2].expr).place->name : NULL, (yyvsp[0].expr).place ? (yyvsp[0].expr).place->name : NULL, t->name);
        res.place = t;
        (yyval.expr) = res;
    }
#line 1495 "Suraj_Sharma_PA4.tab.c"
    break;

  case 38: /* factor: identifier  */
#line 341 "Suraj_Sharma_PA4.y"
    {
        exprattr res;
        res.is_boolean = 0;
        res.truelist = res.falselist = NULL;
        res.place = (yyvsp[0].sym);
        (yyval.expr) = res;
    }
#line 1507 "Suraj_Sharma_PA4.tab.c"
    break;

  case 39: /* factor: constant  */
#line 349 "Suraj_Sharma_PA4.y"
    {
        exprattr res;
        res.is_boolean = 0;
        res.truelist = res.falselist = NULL;
        symbol *t = genTemp("INTEGER");
        char *lit = int_to_str((yyvsp[0].num));
        emit(OP_COPY, lit, NULL, t->name);
        free(lit);
        res.place = t;
        (yyval.expr) = res;
    }
#line 1523 "Suraj_Sharma_PA4.tab.c"
    break;

  case 40: /* factor: string_literal  */
#line 361 "Suraj_Sharma_PA4.y"
    {
        exprattr res;
        res.is_boolean = 0;
        res.truelist = res.falselist = NULL;
        symbol *t = genTemp("STRING");
        emit(OP_COPY, (yyvsp[0].sval), NULL, t->name);
        free((yyvsp[0].sval));
        res.place = t;
        (yyval.expr) = res;
    }
#line 1538 "Suraj_Sharma_PA4.tab.c"
    break;

  case 41: /* factor: LPAREN expression RPAREN  */
#line 372 "Suraj_Sharma_PA4.y"
    {
        (yyval.expr) = (yyvsp[-1].expr);
    }
#line 1546 "Suraj_Sharma_PA4.tab.c"
    break;

  case 42: /* factor: identifier LPAREN expression_list RPAREN  */
#line 376 "Suraj_Sharma_PA4.y"
    {
        exprattr res;
        res.is_boolean = 0;
        res.truelist = res.falselist = NULL;
        
        int argc = 0;
        arglist *cur = (yyvsp[-1].alist);
        while (cur) {
            emit(OP_PARAM, cur->name, NULL, NULL);
            argc++;
            cur = cur->next;
        }

        symbol *t = genTemp("INTEGER");
        char buf[10];
        snprintf(buf, 10, "%d", argc);
        emit(OP_CALL, (yyvsp[-3].sym)->name, buf, t->name);
        res.place = t;
        (yyval.expr) = res;
    }
#line 1571 "Suraj_Sharma_PA4.tab.c"
    break;

  case 43: /* M: %empty  */
#line 399 "Suraj_Sharma_PA4.y"
    {
        markerattr m;
        m.instr = nextinstr();
        (yyval.mark) = m;
    }
#line 1581 "Suraj_Sharma_PA4.tab.c"
    break;


#line 1585 "Suraj_Sharma_PA4.tab.c"

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

#line 406 "Suraj_Sharma_PA4.y"


void yyerror(const char *s) {
    fprintf(stderr, "Syntax Error at %s at line %d at token '%s'\n", s, yylineno, yytext);
}

int main(int argc, char **argv) {
	
	if (argc < 2) {
		fprintf(stderr, "Usage: %s <input_file.np> [-o <output_file.asm>]\n", argv[0]);
		return 1;
	}

	const char *input_filename = NULL;
	const char *output_filename = NULL;
	char default_output_buffer[MAX_FILENAME_LEN];

	for (int i = 1; i < argc; i++) {
		if (strcmp(argv[i], "-o") == 0) {
			if (i + 1 < argc) {
				output_filename = argv[i + 1];
				i++;
			} else {
				fprintf(stderr, "Error: -o flag requires an output filename.\n");
				return 1;
			}
		} else if (input_filename == NULL) {
			input_filename = argv[i];
		}	
	}
	
	if (input_filename == NULL) {
		fprintf(stderr, "Error: Input filename not specified.\n");
		return 1;
	}

	if (output_filename == NULL) {
		char *dot_pos = strrchr(input_filename, '.');
		if (dot_pos) {
			size_t base_len = dot_pos - input_filename;
			snprintf(default_output_buffer, MAX_FILENAME_LEN, "%.*s.asm", (int)base_len, input_filename);
		} else {
			snprintf(default_output_buffer, MAX_FILENAME_LEN, "%s.asm", input_filename);
		}
		output_filename = default_output_buffer;
	}
	
	char out_filename_buffer[MAX_FILENAME_LEN];
	snprintf(out_filename_buffer, MAX_FILENAME_LEN, "%s", output_filename);
	char *asm_ext_pos = strrchr(out_filename_buffer, '.');
	if (asm_ext_pos) {
		strcpy(asm_ext_pos, ".out");
	} else {
		strcat(out_filename_buffer, ".out");
	}

	yyin = fopen(input_filename, "r");
	if (!yyin) {
		perror("Error opening input file");
		return 1;
	}
	
	ST_current = createSymbolTable("global");
	ST_global = ST_current;

	if (yyparse() == 0) {
		
		print_quads(out_filename_buffer);	
		
		x86_generate_all(output_filename);
		
	} else {
		fprintf(stderr, "Parsing failed.\n");
		return 1;
	}
	
	fclose(yyin);
	return 0;
}
