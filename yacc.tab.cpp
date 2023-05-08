
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 1



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "yacc.y"

//
// Created by LSJ on 4/19/2023.
//
#include "yyheader.h"
//#include "Lexer.h"
#include "yacc.tab.h"

extern "C"{
    void yyerror(const char *s);
    int yyparse();
    int yylex();
    int yywrap();
    // vector<MyToken> yylex_init();
    // Lexer yylex_init();
}

void yyerror(const char *s, YYLTYPE *loc);
void yyerror(const char *s, int line, int col);
void yyerror(const char *s, int startLine, int startCol, int endLine, int endCol);

extern Lexer yyLexer;

bool isLexerInit = false;

//extern YYSTYPE yylval;

//bool haveSemanticError = false;

MyType* ParseTreeHead = NULL;

vector<string> syntaxErrorInformation;



/* Line 189 of yacc.c  */
#line 109 "yacc.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     SINGLE_QUOTES = 258,
     ARRAY = 259,
     _BEGIN = 260,
     CONST = 261,
     DO = 262,
     ELSE = 263,
     END = 264,
     FOR = 265,
     FUNCTION = 266,
     IF = 267,
     NOT = 268,
     OF = 269,
     PROCEDURE = 270,
     PROGRAM = 271,
     THEN = 272,
     TO = 273,
     TYPE = 274,
     VAR = 275,
     READ = 276,
     WRITE = 277,
     UMINUS = 278,
     AND = 279,
     DIV = 280,
     MOD = 281,
     OR = 282,
     INTEGER = 283,
     REAL = 284,
     CHAR = 285,
     BOOLEAN = 286,
     IDENTIFIER = 287,
     FLOAT = 288,
     INT = 289,
     CHARACTER = 290,
     LPAREN = 291,
     RPAREN = 292,
     LSQUAR = 293,
     RSQUAR = 294,
     COMMA = 295,
     PERIOD = 296,
     SEMICO = 297,
     RANGEDOT = 298,
     LESSEQ = 299,
     MOREEQ = 300,
     NOTEQ = 301,
     LESS = 302,
     MORE = 303,
     EQUAL = 304,
     ASSIGN = 305,
     COLON = 306,
     ADD = 307,
     SUB = 308,
     MULT = 309,
     DIVIDE = 310
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 219 "yacc.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   360

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  156
/* YYNRULES -- Number of states.  */
#define YYNSTATES  298

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   310

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     8,    13,    18,    23,    28,    34,    40,
      46,    52,    58,    61,    67,    73,    79,    85,    88,    93,
      97,    99,   103,   104,   108,   112,   118,   122,   128,   132,
     138,   144,   148,   151,   154,   156,   159,   162,   164,   168,
     172,   173,   177,   181,   187,   191,   197,   203,   209,   213,
     217,   219,   226,   233,   240,   247,   250,   254,   259,   261,
     263,   265,   267,   273,   277,   283,   289,   293,   294,   298,
     302,   306,   310,   316,   322,   328,   334,   339,   342,   345,
     349,   350,   353,   357,   361,   363,   367,   369,   371,   374,
     377,   381,   385,   389,   392,   396,   400,   404,   408,   410,
     414,   418,   420,   422,   428,   437,   442,   447,   448,   454,
     463,   472,   481,   485,   487,   490,   494,   495,   498,   502,
     504,   509,   514,   517,   518,   522,   524,   528,   532,   534,
     538,   540,   544,   546,   548,   550,   552,   554,   559,   563,
     564,   570,   575,   579,   583,   585,   587,   589,   591,   593,
     595,   597,   599,   601,   603,   605,   607
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      57,     0,    -1,    58,    42,    59,    41,    -1,    58,     1,
      59,    41,    -1,    58,    42,    59,     1,    -1,     1,    42,
      59,    41,    -1,    58,    42,     1,    41,    -1,     1,    58,
      42,    59,    41,    -1,     1,    58,     1,    59,    41,    -1,
       1,    58,    42,    59,     1,    -1,     1,    58,    42,     1,
      41,    -1,    16,    32,    36,    60,    37,    -1,    16,    32,
      -1,    16,     1,    36,    60,    37,    -1,    16,    32,     1,
      60,    37,    -1,    16,    32,    36,     1,    37,    -1,    16,
      32,    36,    60,     1,    -1,    16,     1,    -1,    61,    64,
      69,    78,    -1,    60,    40,    32,    -1,    32,    -1,     6,
      62,    42,    -1,    -1,     6,     1,    42,    -1,     6,    62,
       1,    -1,    62,    42,    32,    49,    63,    -1,    32,    49,
      63,    -1,    62,    42,    32,    49,     1,    -1,    32,    49,
       1,    -1,    62,     1,    32,    49,    63,    -1,    62,    42,
      32,     1,    63,    -1,    32,     1,    63,    -1,    52,    34,
      -1,    53,    34,    -1,    34,    -1,    52,    33,    -1,    53,
      33,    -1,    33,    -1,     3,    35,     3,    -1,    20,    65,
      42,    -1,    -1,    20,     1,    42,    -1,    20,    65,     1,
      -1,    65,    42,    60,    51,    66,    -1,    60,    51,    66,
      -1,    65,     1,    60,    51,    66,    -1,    65,    42,    60,
       1,    66,    -1,    65,    42,    83,    51,     1,    -1,    60,
      51,     1,    -1,    60,     1,    66,    -1,    67,    -1,     4,
      38,    68,    39,    14,    67,    -1,     4,     1,    68,    39,
      14,    67,    -1,     4,    38,    68,    39,     1,    67,    -1,
       4,    38,    68,    39,    14,     1,    -1,     4,     1,    -1,
       4,    38,     1,    -1,     4,    38,    68,     1,    -1,    28,
      -1,    29,    -1,    31,    -1,    30,    -1,    68,    40,    34,
      43,    34,    -1,    34,    43,    34,    -1,    68,     1,    34,
      43,    34,    -1,    68,    40,    34,     1,    34,    -1,    69,
      70,    42,    -1,    -1,    69,    70,     1,    -1,    71,    42,
      77,    -1,    71,     1,    77,    -1,    15,    32,    72,    -1,
      11,    32,    72,    51,    67,    -1,    11,     1,    72,    51,
      67,    -1,    11,    32,    72,     1,    67,    -1,    11,    32,
      72,    51,     1,    -1,    11,    32,    72,     1,    -1,    11,
       1,    -1,    15,     1,    -1,    36,    73,    37,    -1,    -1,
      36,     1,    -1,    36,    73,     1,    -1,    73,    42,    74,
      -1,    74,    -1,    73,     1,    74,    -1,    75,    -1,    76,
      -1,    20,    76,    -1,    20,     1,    -1,    60,    51,    67,
      -1,    60,     1,    67,    -1,    60,    51,     1,    -1,    60,
       1,    -1,    61,    64,    78,    -1,     5,    79,     9,    -1,
       5,    79,     1,    -1,    79,    42,    80,    -1,    80,    -1,
      79,     1,    80,    -1,    82,    50,    87,    -1,    84,    -1,
      78,    -1,    12,    87,    17,    80,    85,    -1,    10,    32,
      50,    87,    18,    87,     7,    80,    -1,    21,    36,    81,
      37,    -1,    22,    36,    86,    37,    -1,    -1,    12,    87,
       1,    80,    85,    -1,    10,    32,     1,    87,    18,    87,
       7,    80,    -1,    10,    32,    50,    87,     1,    87,     7,
      80,    -1,    10,    32,    50,    87,    18,    87,     1,    80,
      -1,    81,    40,    82,    -1,    82,    -1,    32,    83,    -1,
      38,    86,    39,    -1,    -1,    38,     1,    -1,    38,    86,
       1,    -1,    32,    -1,    32,    36,    86,    37,    -1,    32,
      36,    86,     1,    -1,     8,    80,    -1,    -1,    86,    40,
      87,    -1,    87,    -1,    86,     1,    87,    -1,    88,    92,
      88,    -1,    88,    -1,    88,    93,    89,    -1,    89,    -1,
      89,    94,    90,    -1,    90,    -1,    34,    -1,    33,    -1,
      35,    -1,    82,    -1,    32,    36,    86,    37,    -1,    36,
      86,    37,    -1,    -1,    53,    90,    91,    23,    90,    -1,
      32,    36,    86,     1,    -1,    32,    36,     1,    -1,    36,
      87,     1,    -1,    44,    -1,    45,    -1,    46,    -1,    47,
      -1,    48,    -1,    49,    -1,    52,    -1,    27,    -1,    54,
      -1,    55,    -1,    25,    -1,    26,    -1,    24,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    99,    99,   106,   110,   114,   118,   122,   126,   130,
     134,   139,   147,   152,   156,   160,   164,   168,   173,   181,
     187,   192,   198,   201,   205,   210,   218,   224,   228,   232,
     236,   240,   245,   250,   255,   259,   264,   269,   273,   280,
     286,   289,   293,   298,   306,   312,   316,   320,   324,   328,
     333,   337,   346,   350,   354,   358,   362,   366,   371,   375,
     379,   383,   388,   396,   403,   407,   412,   418,   421,   426,
     432,   437,   443,   451,   455,   459,   463,   467,   471,   476,
     482,   485,   489,   494,   500,   504,   509,   513,   518,   523,
     528,   534,   538,   542,   547,   554,   560,   565,   571,   575,
     580,   586,   590,   594,   602,   613,   620,   627,   630,   634,
     638,   642,   647,   653,   658,   664,   670,   673,   677,   682,
     686,   693,   698,   703,   707,   713,   717,   722,   728,   733,
     739,   744,   750,   755,   759,   763,   767,   771,   778,   784,
     784,   794,   798,   802,   807,   811,   815,   819,   823,   827,
     832,   836,   841,   845,   849,   853,   857
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SINGLE_QUOTES", "ARRAY", "_BEGIN",
  "CONST", "DO", "ELSE", "END", "FOR", "FUNCTION", "IF", "NOT", "OF",
  "PROCEDURE", "PROGRAM", "THEN", "TO", "TYPE", "VAR", "READ", "WRITE",
  "UMINUS", "AND", "DIV", "MOD", "OR", "INTEGER", "REAL", "CHAR",
  "BOOLEAN", "IDENTIFIER", "FLOAT", "INT", "CHARACTER", "LPAREN", "RPAREN",
  "LSQUAR", "RSQUAR", "COMMA", "PERIOD", "SEMICO", "RANGEDOT", "LESSEQ",
  "MOREEQ", "NOTEQ", "LESS", "MORE", "EQUAL", "ASSIGN", "COLON", "ADD",
  "SUB", "MULT", "DIVIDE", "$accept", "programstruct", "program_head",
  "program_body", "idlist", "const_declarations", "const_declaration",
  "const_value", "var_declarations", "var_declaration", "type",
  "basic_type", "period", "subprogram_declarations", "subprogram",
  "subprogram_head", "formal_parameter", "parameter_list", "parameter",
  "var_parameter", "value_parameter", "subprogram_body",
  "compound_statement", "statement_list", "statement", "variable_list",
  "variable", "id_varpart", "procedure_call", "else_part",
  "expression_list", "expression", "simple_expression", "term", "factor",
  "@1", "rel_option", "add_option", "mul_option", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    56,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    58,    58,    58,    58,    58,    58,    58,    59,    60,
      60,    61,    61,    61,    61,    62,    62,    62,    62,    62,
      62,    62,    63,    63,    63,    63,    63,    63,    63,    64,
      64,    64,    64,    65,    65,    65,    65,    65,    65,    65,
      66,    66,    66,    66,    66,    66,    66,    66,    67,    67,
      67,    67,    68,    68,    68,    68,    69,    69,    69,    70,
      70,    71,    71,    71,    71,    71,    71,    71,    71,    72,
      72,    72,    72,    73,    73,    73,    74,    74,    75,    75,
      76,    76,    76,    76,    77,    78,    78,    79,    79,    79,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    81,    81,    82,    83,    83,    83,    83,    84,
      84,    84,    85,    85,    86,    86,    86,    87,    87,    88,
      88,    89,    89,    90,    90,    90,    90,    90,    90,    91,
      90,    90,    90,    90,    92,    92,    92,    92,    92,    92,
      93,    93,    94,    94,    94,    94,    94
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     4,     4,     4,     4,     5,     5,     5,
       5,     5,     2,     5,     5,     5,     5,     2,     4,     3,
       1,     3,     0,     3,     3,     5,     3,     5,     3,     5,
       5,     3,     2,     2,     1,     2,     2,     1,     3,     3,
       0,     3,     3,     5,     3,     5,     5,     5,     3,     3,
       1,     6,     6,     6,     6,     2,     3,     4,     1,     1,
       1,     1,     5,     3,     5,     5,     3,     0,     3,     3,
       3,     3,     5,     5,     5,     5,     4,     2,     2,     3,
       0,     2,     3,     3,     1,     3,     1,     1,     2,     2,
       3,     3,     3,     2,     3,     3,     3,     3,     1,     3,
       3,     1,     1,     5,     8,     4,     4,     0,     5,     8,
       8,     8,     3,     1,     2,     3,     0,     2,     3,     1,
       4,     4,     2,     0,     3,     1,     3,     3,     1,     3,
       1,     3,     1,     1,     1,     1,     1,     4,     3,     0,
       5,     4,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,    22,     0,    17,     0,     1,
      22,     0,     0,     0,    40,    22,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     5,     0,    67,     0,
       0,     0,    20,     0,     0,     0,     0,     3,     6,     4,
       2,    23,     0,     0,    24,    21,     0,     0,     0,     0,
       8,    10,     9,     7,    13,     0,    14,    15,    16,    11,
       0,    37,    34,     0,     0,    31,    28,    26,     0,     0,
      41,     0,     0,    42,    39,   107,     0,     0,     0,     0,
      18,    19,     0,    35,    32,    36,    33,     0,     0,     0,
       0,    58,    59,    61,    60,    49,    50,    48,    44,     0,
       0,     0,     0,     0,     0,     0,     0,   119,   102,     0,
      98,     0,   101,    77,    80,    78,    80,    68,    66,    22,
      22,    38,    29,    30,    27,    25,    55,     0,     0,   117,
     116,   134,   133,   135,     0,     0,   136,     0,   125,   128,
     130,   132,     0,     0,     0,     0,     0,     0,     0,     0,
     114,    96,    95,   107,     0,     0,     0,     0,    71,    40,
      70,    69,     0,     0,    56,     0,    45,     0,     0,     0,
     139,   118,   115,     0,   151,   144,   145,   146,   147,   148,
     149,   150,     0,     0,   156,   154,   155,   152,   153,     0,
      46,    43,    47,     0,     0,   107,   107,   116,     0,   113,
       0,     0,    99,    97,   100,    81,     0,     0,     0,    84,
      86,    87,     0,    76,     0,     0,     0,     0,     0,     0,
      57,     0,   142,     0,     0,   138,   143,     0,   126,   124,
     127,   129,   131,     0,     0,   123,   123,   105,     0,   106,
     121,   120,    89,    88,    93,     0,    82,    79,     0,    73,
      74,    75,    72,    94,    63,     0,     0,     0,     0,     0,
     141,   137,     0,     0,     0,     0,   107,   108,   103,   112,
      91,    92,    90,    85,    83,     0,    52,     0,     0,    53,
      54,    51,   140,     0,     0,     0,   122,    64,    65,    62,
     107,   107,   107,   107,   109,   110,   111,   104
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,    13,   207,    14,    25,    65,    28,    48,
      95,    96,   163,    49,    78,    79,   156,   208,   209,   210,
     211,   160,   108,   109,   110,   198,   136,   150,   112,   267,
     137,   138,   139,   140,   141,   227,   182,   183,   189
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -150
static const yytype_int16 yypact[] =
{
     186,    85,   167,   124,    38,   199,    84,   178,    93,  -150,
     199,   274,   177,   104,   222,   199,   281,   211,   211,   187,
     185,   216,   106,   242,    21,    97,  -150,   192,  -150,   218,
     257,   113,  -150,   260,   278,   265,   118,  -150,  -150,  -150,
    -150,  -150,    50,    40,   275,   285,   280,    17,   109,   288,
    -150,  -150,  -150,  -150,  -150,   289,  -150,  -150,  -150,  -150,
     290,  -150,  -150,    -4,   152,  -150,  -150,  -150,   271,    22,
    -150,   202,   206,   211,   -19,   246,   195,   196,   110,   111,
    -150,  -150,   320,  -150,  -150,  -150,  -150,    50,    50,    53,
      90,  -150,  -150,  -150,  -150,  -150,  -150,  -150,  -150,   -20,
       2,    24,   273,   295,   238,   292,   293,   245,  -150,    95,
    -150,   282,  -150,   209,   297,  -150,   297,  -150,  -150,   199,
     199,  -150,  -150,  -150,  -150,  -150,   296,     8,   202,  -150,
     -10,  -150,  -150,  -150,   238,   238,  -150,   117,  -150,   217,
     158,  -150,   202,   202,   325,    11,   108,   299,   238,   238,
    -150,   246,  -150,   246,   238,    13,   284,    14,  -150,   222,
    -150,  -150,   291,   121,  -150,   133,  -150,    16,   122,   137,
    -150,   238,  -150,   238,  -150,  -150,  -150,  -150,  -150,  -150,
    -150,  -150,   238,   238,  -150,  -150,  -150,  -150,  -150,   238,
    -150,  -150,  -150,   238,   238,   246,   246,   298,   279,  -150,
     139,   163,  -150,  -150,  -150,  -150,   197,    57,    94,  -150,
    -150,  -150,   283,   283,   210,   332,   304,   305,   326,   307,
     305,   276,  -150,   164,   238,  -150,  -150,   319,  -150,  -150,
     194,   158,  -150,   327,   115,   335,   335,  -150,   299,  -150,
     238,  -150,  -150,  -150,   283,   219,   256,  -150,   256,  -150,
    -150,  -150,  -150,  -150,  -150,   301,   283,    23,   283,   224,
     238,  -150,   238,   238,   238,   238,   246,  -150,  -150,  -150,
    -150,  -150,  -150,  -150,  -150,   312,  -150,   313,   314,  -150,
    -150,  -150,  -150,   342,   343,    20,  -150,  -150,  -150,  -150,
     246,   246,   246,   246,  -150,  -150,  -150,  -150
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -150,  -150,   350,   294,   -11,   103,  -150,     1,   193,  -150,
     -61,   -64,   226,  -150,  -150,  -150,    -1,  -150,    60,  -150,
     148,   235,   -48,  -150,  -149,  -150,   -75,   286,  -150,   120,
      41,   -94,   175,   176,  -130,  -150,  -150,  -150,  -150
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -126
static const yytype_int16 yytable[] =
{
     111,    80,   202,   129,   203,   170,    33,    34,    36,   164,
     146,    98,   193,    32,   205,   213,    47,   222,    71,   100,
      55,   292,    42,    88,   277,   142,   167,   293,   100,    83,
      84,   128,  -116,   206,   130,   131,   132,   133,   134,    10,
     169,    66,   162,    60,    67,    32,   235,   236,   130,   131,
     132,   133,   134,    60,   124,   135,    60,    55,   244,   232,
     204,   194,    99,   101,    55,   214,   278,   166,    72,   135,
      43,    89,   199,    61,    62,   143,   111,   228,   111,   229,
      11,   190,   191,    61,    62,    15,    61,    62,   122,   123,
     125,   126,    63,    64,    18,   246,   151,    55,    44,   233,
     234,     2,    63,    64,   152,    63,    64,    39,   245,   195,
      73,   117,   119,   157,    52,   158,   264,   286,   171,    58,
     111,   111,   217,   224,     9,   196,    16,     5,   127,    19,
     228,   247,   282,   265,   220,   -12,   248,   153,   226,    45,
     224,   294,   295,   296,   297,    26,   228,    40,   249,   250,
     252,    74,   118,   120,    53,    59,   172,   173,    55,   225,
     218,   219,   173,   269,   240,   260,   228,   253,     7,   283,
     284,   285,   221,   219,  -125,   168,   239,  -125,    23,   173,
     270,   272,   184,   185,   186,    85,    86,     1,    35,   200,
     201,   111,   276,    46,   279,   281,   113,   115,   242,     8,
     241,   261,     2,   173,   173,    12,    90,    97,   223,    24,
      90,   251,   187,   188,    17,   111,   111,   111,   111,    32,
     271,   174,   159,   159,    32,   280,    37,   114,   116,    32,
      91,    92,    93,    94,    91,    92,    93,    94,    91,    92,
      93,    94,    27,    32,   174,   155,   181,    91,    92,    93,
      94,    75,    91,    92,    93,    94,   103,    38,   104,    50,
     -80,   175,   176,   177,   178,   179,   180,   105,   106,   181,
     130,   131,   132,   133,   134,    21,   206,   258,   107,   -22,
      12,   149,    30,   100,    41,   -22,   -22,    12,    32,   -22,
     259,   135,   -22,    75,   -22,  -116,   -22,    54,    51,    76,
      55,   -22,    57,    77,    20,    22,   273,    68,   274,    29,
      31,    91,    92,    93,    94,    56,   237,    69,    55,   238,
      87,    81,    70,   121,   144,    82,   192,   145,   147,   148,
     162,   197,   154,   155,   216,   212,   100,    75,   254,   255,
     256,   257,   262,   266,   275,   263,   287,   288,   289,   290,
     291,     6,   215,   165,   243,   161,   268,   230,     0,   231,
     102
};

static const yytype_int16 yycheck[] =
{
      75,    49,   151,     1,   153,   135,    17,    18,    19,     1,
     104,    72,     1,    32,     1,     1,    27,     1,     1,    38,
      40,     1,     1,     1,     1,     1,    36,     7,    38,    33,
      34,    51,    51,    20,    32,    33,    34,    35,    36,     1,
     134,     1,    34,     3,    43,    32,   195,   196,    32,    33,
      34,    35,    36,     3,     1,    53,     3,    40,     1,   189,
     154,    50,    73,    74,    40,    51,    43,   128,    51,    53,
      49,    49,   147,    33,    34,    51,   151,   171,   153,   173,
      42,   142,   143,    33,    34,     1,    33,    34,    87,    88,
      89,     1,    52,    53,     1,     1,     1,    40,     1,   193,
     194,    16,    52,    53,     9,    52,    53,     1,    51,     1,
       1,     1,     1,   114,     1,   116,     1,   266,     1,     1,
     195,   196,     1,     1,     0,    17,    42,    42,    38,    36,
     224,    37,   262,    18,     1,    42,    42,    42,     1,    42,
       1,   290,   291,   292,   293,    41,   240,    41,   212,   213,
     214,    42,    42,    42,    41,    37,    39,    40,    40,    37,
      39,    40,    40,   238,     1,     1,   260,   215,     1,   263,
     264,   265,    39,    40,    37,   134,    37,    40,     1,    40,
     244,   245,    24,    25,    26,    33,    34,     1,     1,   148,
     149,   266,   256,     1,   258,   259,     1,     1,     1,    32,
      37,    37,    16,    40,    40,     6,     4,     1,   167,    32,
       4,     1,    54,    55,    36,   290,   291,   292,   293,    32,
       1,    27,   119,   120,    32,     1,    41,    32,    32,    32,
      28,    29,    30,    31,    28,    29,    30,    31,    28,    29,
      30,    31,    20,    32,    27,    36,    52,    28,    29,    30,
      31,     5,    28,    29,    30,    31,    10,    41,    12,    41,
      51,    44,    45,    46,    47,    48,    49,    21,    22,    52,
      32,    33,    34,    35,    36,     1,    20,     1,    32,     5,
       6,    36,     1,    38,    42,    11,     5,     6,    32,    15,
      14,    53,    11,     5,    20,    50,    15,    37,    41,    11,
      40,    20,    37,    15,    10,    11,   246,    32,   248,    15,
      16,    28,    29,    30,    31,    37,    37,    32,    40,    40,
      49,    32,    42,     3,    51,    35,     1,    32,    36,    36,
      34,    32,    50,    36,    43,    51,    38,     5,    34,    34,
      14,    34,    23,     8,    43,    18,    34,    34,    34,     7,
       7,     1,   159,   127,   206,   120,   236,   182,    -1,   183,
      74
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    16,    57,    58,    42,    58,     1,    32,     0,
       1,    42,     6,    59,    61,     1,    42,    36,     1,    36,
      59,     1,    59,     1,    32,    62,    41,    20,    64,    59,
       1,    59,    32,    60,    60,     1,    60,    41,    41,     1,
      41,    42,     1,    49,     1,    42,     1,    60,    65,    69,
      41,    41,     1,    41,    37,    40,    37,    37,     1,    37,
       3,    33,    34,    52,    53,    63,     1,    63,    32,    32,
      42,     1,    51,     1,    42,     5,    11,    15,    70,    71,
      78,    32,    35,    33,    34,    33,    34,    49,     1,    49,
       4,    28,    29,    30,    31,    66,    67,     1,    66,    60,
      38,    60,    83,    10,    12,    21,    22,    32,    78,    79,
      80,    82,    84,     1,    32,     1,    32,     1,    42,     1,
      42,     3,    63,    63,     1,    63,     1,    38,    51,     1,
      32,    33,    34,    35,    36,    53,    82,    86,    87,    88,
      89,    90,     1,    51,    51,    32,    87,    36,    36,    36,
      83,     1,     9,    42,    50,    36,    72,    72,    72,    61,
      77,    77,    34,    68,     1,    68,    66,    36,    86,    87,
      90,     1,    39,    40,    27,    44,    45,    46,    47,    48,
      49,    52,    92,    93,    24,    25,    26,    54,    55,    94,
      66,    66,     1,     1,    50,     1,    17,    32,    81,    82,
      86,    86,    80,    80,    87,     1,    20,    60,    73,    74,
      75,    76,    51,     1,    51,    64,    43,     1,    39,    40,
       1,    39,     1,    86,     1,    37,     1,    91,    87,    87,
      88,    89,    90,    87,    87,    80,    80,    37,    40,    37,
       1,    37,     1,    76,     1,    51,     1,    37,    42,    67,
      67,     1,    67,    78,    34,    34,    14,    34,     1,    14,
       1,    37,    23,    18,     1,    18,     8,    85,    85,    82,
      67,     1,    67,    74,    74,    43,    67,     1,    43,    67,
       1,    67,    90,    87,    87,    87,    80,    34,    34,    34,
       7,     7,     1,     7,    80,    80,    80,    80
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
	    /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
extern YYSTYPE yylval;

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[2];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;

#if YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 1;
#endif

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
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
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;
  *++yylsp = yylloc;
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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 99 "yacc.y"
    {
                        ParseTreeHead = (yyval) = new MyType;
                        (yyval)->name = "programstruct";
                        (yyval)->children.push_back((yyvsp[(1) - (4)]));
                        (yyval)->children.push_back((yyvsp[(2) - (4)]));
                        (yyval)->children.push_back((yyvsp[(3) - (4)]));
                        (yyval)->children.push_back((yyvsp[(4) - (4)]));
                    ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 106 "yacc.y"
    {//没有分号
                      ParseTreeHead = (yyval) = new MyType;
                      (yyval)->name = "programstruct";
                      yyerror("missing a SEMICO here", (yylsp[(1) - (4)]).last_line, (yylsp[(1) - (4)]).last_column+1);
                    ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 110 "yacc.y"
    {//没有点号
                      ParseTreeHead = (yyval) = new MyType;
                      (yyval)->name = "programstruct";
                      yyerror("missing a PERIOD here", (yylsp[(3) - (4)]).last_line, (yylsp[(3) - (4)]).last_column+1);
                    ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 114 "yacc.y"
    {//没有 program_head
                      ParseTreeHead = (yyval) = new MyType;
                      (yyval)->name = "programstruct";
                      yyerror("missing a 'program_head' here", (yylsp[(1) - (4)]).first_line, (yylsp[(1) - (4)]).first_column, (yylsp[(1) - (4)]).last_line, (yylsp[(1) - (4)]).last_column);
                    ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 118 "yacc.y"
    {//没有 program_body
                      ParseTreeHead = (yyval) = new MyType;
                      (yyval)->name = "programstruct";
                      yyerror("missing a 'program_body' here");
                    ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 122 "yacc.y"
    {//program_head前有非法字符
                      ParseTreeHead = (yyval) = new MyType;
                      (yyval)->name = "programstruct";
                      yyerror("invalid symbol before 'program_head'", (yyloc).first_line, (yyloc).first_column, (yylsp[(2) - (5)]).first_line, (yylsp[(2) - (5)]).first_column-1);
                    ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 126 "yacc.y"
    {//program_head前包含非法字符,没有分号
                      ParseTreeHead = (yyval) = new MyType;
                      (yyval)->name = "programstruct";
                      yyerror("invalid symbol before 'program_head' and missing a SEMICO here", (yyloc).first_line, (yyloc).first_column, (yylsp[(2) - (5)]).first_line, (yylsp[(2) - (5)]).first_column-1);
                    ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 130 "yacc.y"
    {//program_head前包含非法字符,没有点号
                      ParseTreeHead = (yyval) = new MyType;
                      (yyval)->name = "programstruct";
                      yyerror("invalid symbol before 'program_head' and missing a PERIOD here", (yyloc).first_line, (yyloc).first_column, (yylsp[(2) - (5)]).first_line, (yylsp[(2) - (5)]).first_column-1);
                    ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 134 "yacc.y"
    {
                      ParseTreeHead = (yyval) = new MyType;
                      (yyval)->name = "programstruct";
                      yyerror("invalid symbol before 'program_head' and missing a 'program_body' here", (yyloc).first_line, (yyloc).first_column, (yylsp[(2) - (5)]).first_line, (yylsp[(2) - (5)]).first_column-1);
                    ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 139 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "program_head";
                        (yyval)->children.push_back((yyvsp[(1) - (5)]));
                        (yyval)->children.push_back((yyvsp[(2) - (5)]));
                        (yyval)->children.push_back((yyvsp[(3) - (5)]));
                        (yyval)->children.push_back((yyvsp[(4) - (5)]));
                        (yyval)->children.push_back((yyvsp[(5) - (5)]));
                    ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 147 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "program_head";
                        (yyval)->children.push_back((yyvsp[(1) - (2)]));
                        (yyval)->children.push_back((yyvsp[(2) - (2)]));
                    ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 152 "yacc.y"
    {//缺少 IDENTIFIER
                        (yyval) = new MyType;
                        (yyval)->name = "program_head";
                        yyerror("missing IDNETIFIER here", (yylsp[(1) - (5)]).last_line, (yylsp[(1) - (5)]).last_column+1);
                    ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 156 "yacc.y"
    {//缺少 LPAREN
                        (yyval) = new MyType;
                        (yyval)->name = "program_head";
                        yyerror("missing a LPAREN here", (yylsp[(4) - (5)]).first_line, (yylsp[(4) - (5)]).first_column-1);
                    ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 160 "yacc.y"
    {//缺少 idlist
                        (yyval) = new MyType;
                        (yyval)->name = "program_head";
                        yyerror("missing a 'idlist' here", (yylsp[(4) - (5)]).first_line, (yylsp[(4) - (5)]).first_column, (yylsp[(4) - (5)]).last_line, (yylsp[(4) - (5)]).last_column);
                    ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 164 "yacc.y"
    {//缺少 RPAREN
                        (yyval) = new MyType;
                        (yyval)->name = "program_head";
                        yyerror("missing a RPAREN here", (yylsp[(4) - (5)]).last_line, (yylsp[(4) - (5)]).last_column+1);
                    ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 168 "yacc.y"
    {//缺少IDENTIFIER
                        (yyval) = new MyType;
                        (yyval)->name = "program_head";
                        yyerror("missing a IDENTIFIER here", (yylsp[(1) - (2)]).first_line, (yylsp[(1) - (2)]).first_column, (yylsp[(1) - (2)]).last_line, (yylsp[(1) - (2)]).last_column);
                    ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 173 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "program_body";
                        (yyval)->children.push_back((yyvsp[(1) - (4)]));
                        (yyval)->children.push_back((yyvsp[(2) - (4)]));
                        (yyval)->children.push_back((yyvsp[(3) - (4)]));
                        (yyval)->children.push_back((yyvsp[(4) - (4)]));
                    ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 181 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "idlist";
                        (yyval)->children.push_back((yyvsp[(1) - (3)]));
                        (yyval)->children.push_back((yyvsp[(2) - (3)]));
                        (yyval)->children.push_back((yyvsp[(3) - (3)]));
                    ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 187 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "idlist";
                        (yyval)->children.push_back((yyvsp[(1) - (1)]));
                    ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 192 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "const_declarations";
                        (yyval)->children.push_back((yyvsp[(1) - (3)]));
                        (yyval)->children.push_back((yyvsp[(2) - (3)]));
                        (yyval)->children.push_back((yyvsp[(3) - (3)]));
                    ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 198 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "const_declarations";
                    ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 201 "yacc.y"
    {//缺少const_declaration
                        (yyval) = new MyType;
                        (yyval)->name = "const_declarations";
                        yyerror("missing a 'const_declarations' here", (yylsp[(2) - (3)]).first_line, (yylsp[(2) - (3)]).first_column, (yylsp[(2) - (3)]).last_line, (yylsp[(2) - (3)]).last_column);
                    ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 205 "yacc.y"
    {//缺少SEMICO
                        (yyval) = new MyType;
                        (yyval)->name = "const_declarations";
                        yyerror("missing a SEMICO here", (yylsp[(2) - (3)]).first_line, (yylsp[(2) - (3)]).first_column, (yylsp[(2) - (3)]).last_line, (yylsp[(2) - (3)]).last_column);
                    ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 210 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "const_declaration";
                        (yyval)->children.push_back((yyvsp[(1) - (5)]));
                        (yyval)->children.push_back((yyvsp[(2) - (5)]));
                        (yyval)->children.push_back((yyvsp[(3) - (5)]));
                        (yyval)->children.push_back((yyvsp[(4) - (5)]));
                        (yyval)->children.push_back((yyvsp[(5) - (5)]));
                    ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 218 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "const_declaration";
                        (yyval)->children.push_back((yyvsp[(1) - (3)]));
                        (yyval)->children.push_back((yyvsp[(2) - (3)]));
                        (yyval)->children.push_back((yyvsp[(3) - (3)]));
                    ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 224 "yacc.y"
    {//缺少const_value
                        (yyval) = new MyType;
                        (yyval)->name = "const_declaration";
                        yyerror("missing a 'const_value' here", (yylsp[(4) - (5)]).first_line, (yylsp[(4) - (5)]).first_column, (yylsp[(4) - (5)]).last_line, (yylsp[(4) - (5)]).last_column);
                    ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 228 "yacc.y"
    {//缺少const_value
                        (yyval) = new MyType;
                        (yyval)->name = "const_declaration";
                        yyerror("missing a 'const_value' here", (yylsp[(3) - (3)]).first_line, (yylsp[(3) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
                    ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 232 "yacc.y"
    {//缺少SEMICO
                        (yyval) = new MyType;
                        (yyval)->name = "const_declaration";
                        yyerror("missing a SEMICO here", (yylsp[(1) - (5)]).first_line, (yylsp[(1) - (5)]).first_column, (yylsp[(1) - (5)]).last_line, (yylsp[(1) - (5)]).last_column+1);
                    ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 236 "yacc.y"
    {//缺少EQUAL
                        (yyval) = new MyType;
                        (yyval)->name = "const_declaration";
                        yyerror("missing a EQUAL here", (yylsp[(3) - (5)]).first_line, (yylsp[(3) - (5)]).first_column, (yylsp[(3) - (5)]).last_line, (yylsp[(3) - (5)]).last_column);
                    ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 240 "yacc.y"
    {//缺少EQUAL
                        (yyval) = new MyType;
                        (yyval)->name = "const_declaration";
                        yyerror("missing a EQUAL here", (yylsp[(2) - (3)]).first_line, (yylsp[(2) - (3)]).first_column, (yylsp[(2) - (3)]).last_line, (yylsp[(2) - (3)]).last_column);
                    ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 245 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "const_value";
                        (yyval)->children.push_back((yyvsp[(1) - (2)]));
                        (yyval)->children.push_back((yyvsp[(2) - (2)]));
                    ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 250 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "const_value";
                        (yyval)->children.push_back((yyvsp[(1) - (2)]));
                        (yyval)->children.push_back((yyvsp[(2) - (2)]));
                    ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 255 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "const_value";
                        (yyval)->children.push_back((yyvsp[(1) - (1)]));
                    ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 259 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "const_value";
                        (yyval)->children.push_back((yyvsp[(1) - (2)]));
                        (yyval)->children.push_back((yyvsp[(2) - (2)]));
                    ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 264 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "const_value";
                        (yyval)->children.push_back((yyvsp[(1) - (2)]));
                        (yyval)->children.push_back((yyvsp[(2) - (2)]));
                    ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 269 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "const_value";
                        (yyval)->children.push_back((yyvsp[(1) - (1)]));
                    ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 273 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "const_value";
                        (yyval)->children.push_back((yyvsp[(1) - (3)]));
                        (yyval)->children.push_back((yyvsp[(2) - (3)]));
                        (yyval)->children.push_back((yyvsp[(3) - (3)]));
                    ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 280 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "var_declarations";
                        (yyval)->children.push_back((yyvsp[(1) - (3)]));
                        (yyval)->children.push_back((yyvsp[(2) - (3)]));
                        (yyval)->children.push_back((yyvsp[(3) - (3)]));
                    ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 286 "yacc.y"
    { 
                        (yyval) = new MyType;
                        (yyval)->name = "var_declarations";
                    ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 289 "yacc.y"
    {//缺少var_declaration
                        (yyval) = new MyType;
                        (yyval)->name = "var_declaration";
                        yyerror("missing a 'var_declaration' here", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).first_column, (yylsp[(1) - (3)]).last_line, (yylsp[(1) - (3)]).last_column);
                    ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 293 "yacc.y"
    {//缺少SEMICO
                        (yyval) = new MyType;
                        (yyval)->name = "var_declarations";
                        yyerror("missing a SEMICO here", (yylsp[(2) - (3)]).last_line, (yylsp[(2) - (3)]).last_column+1);
                    ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 298 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "var_declaration";
                        (yyval)->children.push_back((yyvsp[(1) - (5)]));
                        (yyval)->children.push_back((yyvsp[(2) - (5)]));
                        (yyval)->children.push_back((yyvsp[(3) - (5)]));
                        (yyval)->children.push_back((yyvsp[(4) - (5)]));
                        (yyval)->children.push_back((yyvsp[(5) - (5)]));
                    ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 306 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "var_declaration";
                        (yyval)->children.push_back((yyvsp[(1) - (3)]));
                        (yyval)->children.push_back((yyvsp[(2) - (3)]));
                        (yyval)->children.push_back((yyvsp[(3) - (3)]));
                    ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 312 "yacc.y"
    {//缺少SEMICO
                        (yyval) = new MyType;
                        (yyval)->name = "var_declaration";
                        yyerror("missing a SEMICO here", (yylsp[(1) - (5)]).last_line, (yylsp[(1) - (5)]).last_column+1);
                    ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 316 "yacc.y"
    {//缺少COLON
                        (yyval) = new MyType;
                        (yyval)->name = "var_declaration";
                        yyerror("missing a COLON here", (yylsp[(3) - (5)]).last_line, (yylsp[(3) - (5)]).last_column+1);
                    ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 320 "yacc.y"
    {//缺少type
                        (yyval) = new MyType;
                        (yyval)->name = "var_declaration";
                        yyerror("missing a 'type' here", (yylsp[(4) - (5)]).last_line, (yylsp[(4) - (5)]).last_column+1);
                    ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 324 "yacc.y"
    {//缺少type
                        (yyval) = new MyType;
                        (yyval)->name = "var_declaration";
                        yyerror("missing a 'type' here", (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column+1);
                    ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 328 "yacc.y"
    {//缺少COLON
                        (yyval) = new MyType;
                        (yyval)->name = "var_declaration";
                        yyerror("missing a COLON here", (yylsp[(1) - (3)]).last_line, (yylsp[(1) - (3)]).last_column+1);
                    ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 333 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "type";
                        (yyval)->children.push_back((yyvsp[(1) - (1)]));
                    ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 337 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "type";
                        (yyval)->children.push_back((yyvsp[(1) - (6)]));
                        (yyval)->children.push_back((yyvsp[(2) - (6)]));
                        (yyval)->children.push_back((yyvsp[(3) - (6)]));
                        (yyval)->children.push_back((yyvsp[(4) - (6)]));
                        (yyval)->children.push_back((yyvsp[(5) - (6)]));
                        (yyval)->children.push_back((yyvsp[(6) - (6)]));
                    ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 346 "yacc.y"
    {//缺少LSQURA
                        (yyval) = new MyType;
                        (yyval)->name = "type";
                        yyerror("missing a LSQUAR here", (yylsp[(1) - (6)]).last_line, (yylsp[(1) - (6)]).last_column+1);
                    ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 350 "yacc.y"
    {//缺少OF
                        (yyval) = new MyType;
                        (yyval)->name = "type";
                        yyerror("missing a OF here", (yylsp[(4) - (6)]).last_line, (yylsp[(4) - (6)]).last_column+1, (yylsp[(6) - (6)]).first_line, (yylsp[(6) - (6)]).first_column-1);
                    ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 354 "yacc.y"
    {//缺少basic_type
                        (yyval) = new MyType;
                        (yyval)->name = "type";
                        yyerror("missing a 'type' here", (yylsp[(5) - (6)]).last_line, (yylsp[(5) - (6)]).last_column+1);
                    ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 358 "yacc.y"
    {//缺少ARRAY type
                      (yyval) = new MyType;
                      (yyval)->name = "type";
                      yyerror("incomplete array type", &(yyloc));
                    ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 362 "yacc.y"
    {//缺少ARRAY type
                        (yyval) = new MyType;
                        (yyval)->name = "type";
                        yyerror("incomplete array type", &(yyloc));
                    ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 366 "yacc.y"
    {//缺少ARRAY type
                        (yyval) = new MyType;
                        (yyval)->name = "type";
                        yyerror("incomplete array type", &(yyloc));
                    ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 371 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "basic_type";
                        (yyval)->children.push_back((yyvsp[(1) - (1)]));
                    ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 375 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "basic_type";
                        (yyval)->children.push_back((yyvsp[(1) - (1)]));
                    ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 379 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "basic_type";
                        (yyval)->children.push_back((yyvsp[(1) - (1)]));
                    ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 383 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "basic_type";
                        (yyval)->children.push_back((yyvsp[(1) - (1)]));
                    ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 388 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "period";
                        (yyval)->children.push_back((yyvsp[(1) - (5)]));
                        (yyval)->children.push_back((yyvsp[(2) - (5)]));
                        (yyval)->children.push_back((yyvsp[(3) - (5)]));
                        (yyval)->children.push_back((yyvsp[(4) - (5)]));
                        //$$->children.push_back($5);
                    ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 396 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "period";
                        (yyval)->children.push_back((yyvsp[(1) - (3)]));
                        (yyval)->children.push_back((yyvsp[(2) - (3)]));
                        (yyval)->children.push_back((yyvsp[(3) - (3)]));
                        //$$->children.push_back($4);
                    ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 403 "yacc.y"
    {//缺少COMMA
                        (yyval) = new MyType;
                        (yyval)->name = "period";
                        yyerror("missing a COMMA here", (yylsp[(1) - (5)]).last_line, (yylsp[(1) - (5)]).last_column+1);
                    ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 407 "yacc.y"
    {//缺少RANGEDOT
                        (yyval) = new MyType;
                        (yyval)->name = "period";
                        yyerror("missing a RANGEDOT here", (yylsp[(3) - (5)]).last_line, (yylsp[(3) - (5)]).last_column+1);
                    ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 412 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "subprogram_declarations";
                        (yyval)->children.push_back((yyvsp[(1) - (3)]));
                        (yyval)->children.push_back((yyvsp[(2) - (3)]));
                        (yyval)->children.push_back((yyvsp[(3) - (3)]));
                    ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 418 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "subprogram_declarations";
                    ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 421 "yacc.y"
    {//缺少SEMICO
                        (yyval) = new MyType;
                        (yyval)->name = "subprogram_declarations";
                        yyerror("missing a SEMICO here", (yylsp[(2) - (3)]).last_line, (yylsp[(2) - (3)]).last_column+1);
                    ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 426 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "subprogram";
                        (yyval)->children.push_back((yyvsp[(1) - (3)]));
                        (yyval)->children.push_back((yyvsp[(2) - (3)]));
                        (yyval)->children.push_back((yyvsp[(3) - (3)]));
                    ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 432 "yacc.y"
    {//缺少SEMICO
                        (yyval) = new MyType;
                        (yyval)->name = "subprogram";
                        yyerror("missing a SEMICO here", (yylsp[(1) - (3)]).last_line, (yylsp[(1) - (3)]).last_column+1);
                    ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 437 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "subprogram_head";
                        (yyval)->children.push_back((yyvsp[(1) - (3)]));
                        (yyval)->children.push_back((yyvsp[(2) - (3)]));
                        (yyval)->children.push_back((yyvsp[(3) - (3)]));
                    ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 443 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "subprogram_head";
                        (yyval)->children.push_back((yyvsp[(1) - (5)]));
                        (yyval)->children.push_back((yyvsp[(2) - (5)]));
                        (yyval)->children.push_back((yyvsp[(3) - (5)]));
                        (yyval)->children.push_back((yyvsp[(4) - (5)]));
                        (yyval)->children.push_back((yyvsp[(5) - (5)]));
                    ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 451 "yacc.y"
    {//缺少IDENTIFIER
                        (yyval) = new MyType;
                        (yyval)->name = "subprogram_head";
                        yyerror("missing a IDENTIFIER here", (yylsp[(1) - (5)]).last_line, (yylsp[(1) - (5)]).last_column+1);
                    ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 455 "yacc.y"
    {//缺少COLON
                        (yyval) = new MyType;
                        (yyval)->name = "subprogram_head";
                        yyerror("missing a COLON here", (yylsp[(3) - (5)]).last_line, (yylsp[(3) - (5)]).last_column);
                    ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 459 "yacc.y"
    {//缺少basic_type
                        (yyval) = new MyType;
                        (yyval)->name = "subprogram_head";
                        yyerror("missing a 'basic_type' here", (yylsp[(4) - (5)]).last_line, (yylsp[(4) - (5)]).last_column+1);
                    ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 463 "yacc.y"
    {//缺少basic_type
                        (yyval) = new MyType;
                        (yyval)->name = "subprogram_head";
                        yyerror("missing a 'basic_type' keyword here", (yylsp[(3) - (4)]).last_line, (yylsp[(3) - (4)]).last_column+1);
                    ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 467 "yacc.y"
    {//缺少function_head
                        (yyval) = new MyType;
                        (yyval)->name = "subprogram_head";
                        yyerror("incomplete function head", &(yyloc));
                    ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 471 "yacc.y"
    {//缺少procedure_head
                        (yyval) = new MyType;
                        (yyval)->name = "subprogram_head";
                        yyerror("incomplete procedure head", &(yyloc));
                    ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 476 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "formal_parameter";
                        (yyval)->children.push_back((yyvsp[(1) - (3)]));
                        (yyval)->children.push_back((yyvsp[(2) - (3)]));
                        (yyval)->children.push_back((yyvsp[(3) - (3)]));
                    ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 482 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "formal_parameter";
                    ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 485 "yacc.y"
    {//缺少parameter_list
                        (yyval) = new MyType;
                        (yyval)->name = "formal_parameter";
                        yyerror("incomplete 'parameter_list' here", &(yyloc));
                    ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 489 "yacc.y"
    {//缺少RPAREN
                        (yyval) = new MyType;
                        (yyval)->name = "formal_parameter";
                        yyerror("missing a RPAREN here", (yylsp[(2) - (3)]).last_line, (yylsp[(2) - (3)]).last_column+1);
                    ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 494 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "parameter_list";
                        (yyval)->children.push_back((yyvsp[(1) - (3)]));
                        (yyval)->children.push_back((yyvsp[(2) - (3)]));
                        (yyval)->children.push_back((yyvsp[(3) - (3)]));
                    ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 500 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "parameter_list";
                        (yyval)->children.push_back((yyvsp[(1) - (1)]));
                    ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 504 "yacc.y"
    {
                       (yyval) = new MyType;
                        (yyval)->name = "parameter_list";
                        yyerror("missing a SEMICO here", (yylsp[(1) - (3)]).last_line, (yylsp[(1) - (3)]).last_column+1);
                    ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 509 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "parameter";
                        (yyval)->children.push_back((yyvsp[(1) - (1)]));
                    ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 513 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "parameter";
                        (yyval)->children.push_back((yyvsp[(1) - (1)]));
                    ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 518 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "var_parameter";
                        (yyval)->children.push_back((yyvsp[(1) - (2)]));
                        (yyval)->children.push_back((yyvsp[(2) - (2)]));
                    ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 523 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "var_parameter";
                        yyerror("incomplete 'value_parameter' here", &(yyloc));
                    ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 528 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "value_parameter";
                        (yyval)->children.push_back((yyvsp[(1) - (3)]));
                        (yyval)->children.push_back((yyvsp[(2) - (3)]));
                        (yyval)->children.push_back((yyvsp[(3) - (3)]));
                    ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 534 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "value_parameter";
                        yyerror("missing a COLON here", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).last_column+1);
                    ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 538 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "value_parameter";
                        yyerror("missing a 'basic_type' here", (yylsp[(2) - (3)]).last_line, (yylsp[(2) - (3)]).last_column+1);
                    ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 542 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "value_parameter";
                        yyerror("missing a 'basic_type' here", (yylsp[(1) - (2)]).last_line, (yylsp[(1) - (2)]).last_column+1);
                    ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 547 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "subprogram_body";
                        (yyval)->children.push_back((yyvsp[(1) - (3)]));
                        (yyval)->children.push_back((yyvsp[(2) - (3)]));
                        (yyval)->children.push_back((yyvsp[(3) - (3)]));
                    ;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 554 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "compound_statement";
                        (yyval)->children.push_back((yyvsp[(1) - (3)]));
                        (yyval)->children.push_back((yyvsp[(2) - (3)]));
                        (yyval)->children.push_back((yyvsp[(3) - (3)]));
                    ;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 560 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "compound_statement";
                        yyerror("missing a END here", (yylsp[(2) - (3)]).last_line, (yylsp[(2) - (3)]).last_column+1);
                    ;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 565 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "statement_list";
                        (yyval)->children.push_back((yyvsp[(1) - (3)]));
                        (yyval)->children.push_back((yyvsp[(2) - (3)]));
                        (yyval)->children.push_back((yyvsp[(3) - (3)]));
                    ;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 571 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "statement_list";
                        (yyval)->children.push_back((yyvsp[(1) - (1)]));
                    ;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 575 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "statement_list";
                        yyerror("missing a SEMICO here", (yylsp[(1) - (3)]).last_line, (yylsp[(1) - (3)]).last_column+1);
                    ;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 580 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "statement";
                        (yyval)->children.push_back((yyvsp[(1) - (3)]));
                        (yyval)->children.push_back((yyvsp[(2) - (3)]));
                        (yyval)->children.push_back((yyvsp[(3) - (3)]));
                    ;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 586 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "statement";
                        (yyval)->children.push_back((yyvsp[(1) - (1)]));
                    ;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 590 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "statement";
                        (yyval)->children.push_back((yyvsp[(1) - (1)]));
                    ;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 594 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "statement";
                        (yyval)->children.push_back((yyvsp[(1) - (5)]));
                        (yyval)->children.push_back((yyvsp[(2) - (5)]));
                        (yyval)->children.push_back((yyvsp[(3) - (5)]));
                        (yyval)->children.push_back((yyvsp[(4) - (5)]));
                        (yyval)->children.push_back((yyvsp[(5) - (5)]));
                    ;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 602 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "statement";
                        (yyval)->children.push_back((yyvsp[(1) - (8)]));
                        (yyval)->children.push_back((yyvsp[(2) - (8)]));
                        (yyval)->children.push_back((yyvsp[(3) - (8)]));
                        (yyval)->children.push_back((yyvsp[(4) - (8)]));
                        (yyval)->children.push_back((yyvsp[(5) - (8)]));
                        (yyval)->children.push_back((yyvsp[(6) - (8)]));
                        (yyval)->children.push_back((yyvsp[(7) - (8)]));
                        (yyval)->children.push_back((yyvsp[(8) - (8)]));
                    ;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 613 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "statement";
                        (yyval)->children.push_back((yyvsp[(1) - (4)]));
                        (yyval)->children.push_back((yyvsp[(2) - (4)]));
                        (yyval)->children.push_back((yyvsp[(3) - (4)]));
                        (yyval)->children.push_back((yyvsp[(4) - (4)]));
                    ;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 620 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "statement";
                        (yyval)->children.push_back((yyvsp[(1) - (4)]));
                        (yyval)->children.push_back((yyvsp[(2) - (4)]));
                        (yyval)->children.push_back((yyvsp[(3) - (4)]));
                        (yyval)->children.push_back((yyvsp[(4) - (4)]));
                    ;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 627 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "statement";
                    ;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 630 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "statement";
                        yyerror("missing a THEN here", (yylsp[(2) - (5)]).last_line, (yylsp[(2) - (5)]).last_column+1);
                    ;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 634 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "statement";
                        yyerror("missing a ASSIGN here", (yylsp[(2) - (8)]).last_line, (yylsp[(2) - (8)]).last_column+1);
                    ;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 638 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "statement";
                        yyerror("missing a TO here", (yylsp[(4) - (8)]).last_line, (yylsp[(4) - (8)]).last_column+1);
                    ;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 642 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "statement";
                        yyerror("missing a DO here", (yylsp[(6) - (8)]).last_line, (yylsp[(4) - (8)]).last_column+1);
                    ;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 647 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "variable_list";
                        (yyval)->children.push_back((yyvsp[(1) - (3)]));
                        (yyval)->children.push_back((yyvsp[(2) - (3)]));
                        (yyval)->children.push_back((yyvsp[(3) - (3)]));
                    ;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 653 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "variable_list";
                        (yyval)->children.push_back((yyvsp[(1) - (1)]));
                    ;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 658 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "variable";
                        (yyval)->children.push_back((yyvsp[(1) - (2)]));
                        (yyval)->children.push_back((yyvsp[(2) - (2)]));
                    ;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 664 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "id_varpart";
                        (yyval)->children.push_back((yyvsp[(1) - (3)]));
                        (yyval)->children.push_back((yyvsp[(2) - (3)]));
                        (yyval)->children.push_back((yyvsp[(3) - (3)]));
                    ;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 670 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "id_varpart";
                    ;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 673 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "id_varpart";
                        yyerror("incomplete 'expression_list' here", &(yyloc));
                    ;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 677 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "id_varpart";
                        yyerror("missing a RSQUAR here", (yylsp[(2) - (3)]).last_line, (yylsp[(2) - (3)]).last_column+1);
                    ;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 682 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "procedure_call";
                        (yyval)->children.push_back((yyvsp[(1) - (1)]));
                    ;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 686 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "procedure_call";
                        (yyval)->children.push_back((yyvsp[(1) - (4)]));
                        (yyval)->children.push_back((yyvsp[(2) - (4)]));
                        (yyval)->children.push_back((yyvsp[(3) - (4)]));
                        (yyval)->children.push_back((yyvsp[(4) - (4)]));
                    ;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 693 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "procedure_call";
                        yyerror("missing a RPAREN here", (yylsp[(3) - (4)]).last_line, (yylsp[(3) - (4)]).last_column+1);
                    ;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 698 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "else_part";
                        (yyval)->children.push_back((yyvsp[(1) - (2)]));
                        (yyval)->children.push_back((yyvsp[(2) - (2)]));
                    ;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 703 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "else_part";
                    ;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 707 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "expression_list";
                        (yyval)->children.push_back((yyvsp[(1) - (3)]));
                        (yyval)->children.push_back((yyvsp[(2) - (3)]));
                        (yyval)->children.push_back((yyvsp[(3) - (3)]));
                    ;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 713 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "expression_list";
                        (yyval)->children.push_back((yyvsp[(1) - (1)]));
                    ;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 717 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "expression_list";
                        yyerror("missing a COMMA here", (yylsp[(1) - (3)]).last_line, (yylsp[(1) - (3)]).last_column+1);
                    ;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 722 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "expression";
                        (yyval)->children.push_back((yyvsp[(1) - (3)]));
                        (yyval)->children.push_back((yyvsp[(2) - (3)]));
                        (yyval)->children.push_back((yyvsp[(3) - (3)]));
                    ;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 728 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "expression";
                        (yyval)->children.push_back((yyvsp[(1) - (1)]));
                    ;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 733 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "simple_expression";
                        (yyval)->children.push_back((yyvsp[(1) - (3)]));
                        (yyval)->children.push_back((yyvsp[(2) - (3)]));
                        (yyval)->children.push_back((yyvsp[(3) - (3)]));
                    ;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 739 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "simple_expression";
                        (yyval)->children.push_back((yyvsp[(1) - (1)]));
                    ;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 744 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "term";
                        (yyval)->children.push_back((yyvsp[(1) - (3)]));
                        (yyval)->children.push_back((yyvsp[(2) - (3)]));
                        (yyval)->children.push_back((yyvsp[(3) - (3)]));
                    ;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 750 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "term";
                        (yyval)->children.push_back((yyvsp[(1) - (1)]));
                    ;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 755 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "factor";
                        (yyval)->children.push_back((yyvsp[(1) - (1)]));
                    ;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 759 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "factor";
                        (yyval)->children.push_back((yyvsp[(1) - (1)]));
                    ;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 763 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "factor";
                        (yyval)->children.push_back((yyvsp[(1) - (1)]));
                    ;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 767 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "factor";
                        (yyval)->children.push_back((yyvsp[(1) - (1)]));
                    ;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 771 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "factor";
                        (yyval)->children.push_back((yyvsp[(1) - (4)]));
                        (yyval)->children.push_back((yyvsp[(2) - (4)]));
                        (yyval)->children.push_back((yyvsp[(3) - (4)]));
                        (yyval)->children.push_back((yyvsp[(4) - (4)]));
                    ;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 778 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "factor";
                        (yyval)->children.push_back((yyvsp[(1) - (3)]));
                        (yyval)->children.push_back((yyvsp[(2) - (3)]));
                        (yyval)->children.push_back((yyvsp[(3) - (3)]));
                    ;}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 784 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "factor";
                        (yyval)->children.push_back((yyvsp[(1) - (2)]));
                        (yyval)->children.push_back((yyvsp[(2) - (2)]));
                    ;}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 789 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "factor";
                        (yyval)->children.push_back((yyvsp[(1) - (5)]));
                        (yyval)->children.push_back((yyvsp[(2) - (5)]));
                    ;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 794 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "factor";
                        yyerror("missing a RPAREN here", (yylsp[(3) - (4)]).last_line, (yylsp[(3) - (4)]).last_column+1);
                    ;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 798 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "factor";
                        yyerror("missing 'expression_list' here", (yylsp[(2) - (3)]).last_line, (yylsp[(2) - (3)]).last_column+1);
                    ;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 802 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "factor";
                        yyerror("missing a RPAREN here", (yylsp[(2) - (3)]).last_line, (yylsp[(2) - (3)]).last_column+1);
                    ;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 807 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "rel_option";
                        (yyval)->children.push_back((yyvsp[(1) - (1)]));
                    ;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 811 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "rel_option";
                        (yyval)->children.push_back((yyvsp[(1) - (1)]));
                    ;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 815 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "rel_option";
                        (yyval)->children.push_back((yyvsp[(1) - (1)]));
                    ;}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 819 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "rel_option";
                        (yyval)->children.push_back((yyvsp[(1) - (1)]));
                    ;}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 823 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "rel_option";
                        (yyval)->children.push_back((yyvsp[(1) - (1)]));
                    ;}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 827 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "rel_option";
                        (yyval)->children.push_back((yyvsp[(1) - (1)]));
                    ;}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 832 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "add_option";
                        (yyval)->children.push_back((yyvsp[(1) - (1)]));
                    ;}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 836 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "add_option";
                        (yyval)->children.push_back((yyvsp[(1) - (1)]));
                    ;}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 841 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "mul_option";
                        (yyval)->children.push_back((yyvsp[(1) - (1)]));
                    ;}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 845 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "mul_option";
                        (yyval)->children.push_back((yyvsp[(1) - (1)]));
                    ;}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 849 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "mul_option";
                        (yyval)->children.push_back((yyvsp[(1) - (1)]));
                    ;}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 853 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "mul_option";
                        (yyval)->children.push_back((yyvsp[(1) - (1)]));
                    ;}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 857 "yacc.y"
    {
                        (yyval) = new MyType;
                        (yyval)->name = "mul_option";
                        (yyval)->children.push_back((yyvsp[(1) - (1)]));
                    ;}
    break;



/* Line 1455 of yacc.c  */
#line 3555 "yacc.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }

  yyerror_range[0] = yylloc;

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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[0] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 862 "yacc.y"


/*
void yyerror(const char* s){
    haveSemanticError = true;
    string errorInformation;
    errorInformation += string(s);
    //errorInformation += ", location: " + itos(yylineno-1) + "." + itos(yycolumn-yyleng);//添加错误位置
	syntaxErrorInformation.push_back(errorInformation);//存放错误信息
}
*/
void yyerror(const char* s){
  cout << "yyerror: HAVE ERROR, "<< s << endl;
}

void yyerror(const char *s, YYLTYPE *loc){//处理单个字符的错误
	string errorInformation;
	errorInformation = "syntax error, " + string(s) + ", location: " + to_string(loc->first_line) + "." + to_string(loc->first_column) + "-" + to_string(loc->last_line) + "." + to_string(loc->last_column);
	syntaxErrorInformation.push_back(errorInformation);
}
void yyerror(const char *s, int line, int col){
    string errorInfo;
    errorInfo += string(s);
    cout << "yyerror: Have Error: " << errorInfo << " at: " << to_string(line) << ", " << to_string(col) << endl;
}
void yyerror(const char *s, int startLine, int startCol, int endLine, int endCol){
    string errorInfo;
    errorInfo += string(s);
    cout << "yyerror: Have Error: " << errorInfo << " at: " << to_string(startLine) << ":" << to_string(startCol) << ", " << to_string(endLine) << ":" << to_string(endCol) << endl;
}

int yylex(){
    MyToken c = yyLexer.getToken();
    yylval = new MyType;
    string tmpType = yylval->type = c.type;
    int tmpNum = c.lin;
    // yylval->linenum = tmpNum;
    yylval->linenum = c.lin;
    // cout << "yylex: " << yylval->linenum << " "<< yylval->type << " " << yylval->name << endl;
    cout << "yylex: " << yylval->linenum << " "<< yylval->type << " ";
    if(string *tmp = any_cast<string>(&(c.value))){
      yylval->name = *tmp;
      cout << *tmp << endl;
    }else if(float *tmp = any_cast<float>(&(c.value))){
      yylval->name = to_string(*tmp);
      cout << *tmp << endl;
    }else if(int *tmp = any_cast<int>(&(c.value))){
      yylval->name = to_string(*tmp);
      cout << *tmp << endl;
    }
    if(tmpType == "end"){
      // yylex_exit();
      return 0;
    }if(tmpType == "ARRAY"){
      return ARRAY;
    }if(tmpType == "_BEGIN"){
      return _BEGIN;
    }if(tmpType == "CONST"){
      return CONST;
    }if(tmpType == "DO"){
      return DO;
    }if(tmpType == "ELSE"){
      return ELSE;
    }if(tmpType == "FOR"){
      return FOR;
    }if(tmpType == "END"){
      return END;
    }if(tmpType == "FUNCTION"){
      return FUNCTION;
    }if(tmpType == "IF"){
      return IF;
    }if(tmpType == "NOT"){
      return NOT;
    }if(tmpType == "OF"){
      return OF;
    }if(tmpType == "PROCEDURE"){
      return PROCEDURE;
    }if(tmpType == "PROGRAM"){
      return PROGRAM;
    }if(tmpType == "RANGEDOT"){
      return RANGEDOT;
    }if(tmpType == "THEN"){
      return THEN;
    }if(tmpType == "TO"){
      return TO;
    }if(tmpType == "TYPE"){
      return TYPE;
    }if(tmpType == "VAR"){
      return VAR;
    }if(tmpType == "READ"){
      return READ;
    }if(tmpType == "WRITE"){
      return WRITE;
    }if(tmpType == "UMINUS"){
      return UMINUS;
    }if(tmpType == "AND"){
      return AND;
    }if(tmpType == "DIV"){
      return DIV;
    }if(tmpType == "MOD"){
      return MOD;
    }if(tmpType == "OR"){
      return OR;
    }if(tmpType == "INTEGER"){
      return INTEGER;
    }if(tmpType == "REAL"){
      return REAL;
    }if(tmpType == "CHAR"){
      return CHAR;
    }
    if(tmpType == "BOOLEAN"){
      return BOOLEAN;
    }
    if(tmpType == "IDENTIFIER"){
      return IDENTIFIER;
    }
    if(tmpType == "FLOAT"){
      // yylval->name = to_string(any_cast<float>(c.value));
      return FLOAT;
    }
    if(tmpType == "INT"){
      // yylval->name = to_string(any_cast<int>(c.value));
      return INT;
    }
    if(tmpType == "CHARACTER"){
      return CHARACTER;
    }
    if(tmpType == "LPAREN"){
      return LPAREN;
    }
    if(tmpType == "RPAREN"){
      return RPAREN;
    }
    if(tmpType == "LSQUAR"){
      return LSQUAR;
    }
    if(tmpType == "RSQUAR"){
      return RSQUAR;
    }
    if(tmpType == "COMMA"){
      return COMMA;
    }
    if(tmpType == "PERIOD"){
      return PERIOD;
    }
    if(tmpType == "SEMICO"){
      return SEMICO;
    }
    if(tmpType == "ADD"){
      return ADD;
    }if(tmpType == "SUB"){
      return SUB;
    }
    if(tmpType == "MULT"){
      return MULT;
    }if(tmpType == "DIVIDE"){
      return DIVIDE;
    }if(tmpType == "LESSEQ"){
      return LESSEQ;
    }if(tmpType == "MOREEQ"){
      return MOREEQ;
    }if(tmpType == "LESS"){
      return LESS;
    }if(tmpType == "MORE"){
      return MORE;
    }if(tmpType == "EQUAL"){
      return EQUAL;
    }if(tmpType == "ASSIGN"){
      return ASSIGN;
    }if(tmpType == "COLON"){
      return COLON;
    }if(tmpType == "SINGLE_QUOTES"){
      return SINGLE_QUOTES;
    }
    return 0;
}


int yywrap(){
  return 1;
}
