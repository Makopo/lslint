/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "lslmini.y"

    #include "lslmini.hh"
    #include "logger.hh"
    #include <stdio.h>
    #include <string.h>
    //int yylex(YYSTYPE *yylval_param, YYLTYPE *yylloc_param);
    extern int yylex (YYSTYPE * yylval_param,YYLTYPE * yylloc_param , void *yyscanner);

    LLScriptScript *script;
    int yyerror( YYLTYPE*, void *, const char * );
    #define MAKEID(type,id,pos) new LLScriptIdentifier(TYPE(type), (id), &(pos))
    #define EVENTERR(type,prototype) new LLScriptEvent((type), 0); LOG( LOG_CONTINUE, NULL, "event prototype must match: " # prototype);


    #define LSLINT_STACK_OVERFLOW_AT 150
    inline int _yylex( YYSTYPE * yylval, YYLTYPE *yylloc, void *yyscanner, int stack ) {
        if ( stack == LSLINT_STACK_OVERFLOW_AT ) {
            ERROR( yylloc, W_PARSER_STACK_DEPTH );
        }
        return yylex( yylval, yylloc, yyscanner );
    }
    #define yylex(a,b,c) _yylex(a, b, c,  (int)(yyssp - yyss))
        

    // Same as bison's default, but update global position so we don't have
    // to pass it in every time we make a branch
    # define YYLLOC_DEFAULT(Current, Rhs, N)                \
        ((Current).first_line   = (Rhs)[1].first_line,       \
         (Current).first_column = (Rhs)[1].first_column,     \
         (Current).last_line    = (Rhs)[N].last_line,        \
         (Current).last_column  = (Rhs)[N].last_column,      \
         LLASTNode::set_glloc(&(Current)))


/* Line 371 of yacc.c  */
#line 103 "lslmini.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "lslmini.tab.h".  */
#ifndef YY_YY_LSLMINI_TAB_H_INCLUDED
# define YY_YY_LSLMINI_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INTEGER = 258,
     FLOAT_TYPE = 259,
     STRING = 260,
     LLKEY = 261,
     VECTOR = 262,
     QUATERNION = 263,
     LIST = 264,
     STATE = 265,
     EVENT = 266,
     JUMP = 267,
     RETURN = 268,
     STATE_ENTRY = 269,
     STATE_EXIT = 270,
     TOUCH_START = 271,
     TOUCH = 272,
     TOUCH_END = 273,
     COLLISION_START = 274,
     COLLISION = 275,
     COLLISION_END = 276,
     LAND_COLLISION_START = 277,
     LAND_COLLISION = 278,
     LAND_COLLISION_END = 279,
     TIMER = 280,
     CHAT = 281,
     SENSOR = 282,
     NO_SENSOR = 283,
     CONTROL = 284,
     AT_TARGET = 285,
     NOT_AT_TARGET = 286,
     AT_ROT_TARGET = 287,
     NOT_AT_ROT_TARGET = 288,
     MONEY = 289,
     EMAIL = 290,
     RUN_TIME_PERMISSIONS = 291,
     INVENTORY = 292,
     ATTACH = 293,
     DATASERVER = 294,
     MOVING_START = 295,
     MOVING_END = 296,
     REZ = 297,
     OBJECT_REZ = 298,
     LINK_MESSAGE = 299,
     REMOTE_DATA = 300,
     HTTP_RESPONSE = 301,
     IDENTIFIER = 302,
     STATE_DEFAULT = 303,
     INTEGER_CONSTANT = 304,
     INTEGER_TRUE = 305,
     INTEGER_FALSE = 306,
     FP_CONSTANT = 307,
     STRING_CONSTANT = 308,
     INC_OP = 309,
     DEC_OP = 310,
     ADD_ASSIGN = 311,
     SUB_ASSIGN = 312,
     MUL_ASSIGN = 313,
     DIV_ASSIGN = 314,
     MOD_ASSIGN = 315,
     EQ = 316,
     NEQ = 317,
     GEQ = 318,
     LEQ = 319,
     BOOLEAN_AND = 320,
     BOOLEAN_OR = 321,
     SHIFT_LEFT = 322,
     SHIFT_RIGHT = 323,
     IF = 324,
     ELSE = 325,
     FOR = 326,
     DO = 327,
     WHILE = 328,
     PRINT = 329,
     PERIOD = 330,
     ZERO_VECTOR = 331,
     ZERO_ROTATION = 332,
     LOWER_THAN_ELSE = 333,
     INITIALIZER = 334
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 43 "lslmini.y"

	S32								ival;
	F32								fval;
	char							*sval;
	class LLScriptType				*type;
	class LLScriptConstant			*constant;
	class LLScriptIdentifier		*identifier;
	class LLScriptSimpleAssignable	*assignable;
	class LLScriptGlobalVariable	*global;
	class LLScriptEvent				*event;
	class LLScriptEventHandler		*handler;
	class LLScriptExpression		*expression;
	class LLScriptStatement			*statement;
	class LLScriptGlobalFunction	*global_funcs;
	class LLScriptFunctionDec		*global_decl;
	class LLScriptEventDec		*global_event_decl;
	class LLScriptState				*state;
	class LLScriptGlobalStorage		*global_store;
	class LLScriptScript			*script;


/* Line 387 of yacc.c  */
#line 247 "lslmini.tab.c"
} YYSTYPE;
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


#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void *scanner);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_LSLMINI_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 287 "lslmini.tab.c"

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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
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

# define YYCOPY_NEEDED 1

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

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  21
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1676

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  102
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  151
/* YYNRULES -- Number of states.  */
#define YYNSTATES  293

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   334

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    82,     2,     2,     2,    90,    91,     2,
      94,    95,    88,    87,    97,    81,     2,    89,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    79,
      85,    84,    86,     2,    80,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    98,     2,    99,    93,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   100,    92,   101,    83,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    96
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     8,    10,    13,    15,    17,    20,
      23,    28,    33,    38,    40,    42,    44,    46,    48,    50,
      52,    54,    56,    58,    60,    62,    70,    72,    82,    84,
      88,    91,    93,    97,    99,   101,   103,   105,   107,   109,
     111,   113,   118,   123,   129,   135,   137,   141,   144,   146,
     150,   153,   155,   158,   160,   163,   168,   172,   178,   183,
     185,   188,   193,   199,   202,   206,   208,   211,   213,   217,
     221,   225,   229,   233,   236,   239,   242,   244,   250,   258,
     268,   276,   282,   285,   288,   293,   294,   296,   298,   302,
     303,   305,   307,   311,   312,   314,   316,   320,   322,   326,
     330,   334,   338,   342,   346,   350,   354,   358,   362,   366,
     370,   374,   378,   382,   386,   390,   394,   398,   402,   406,
     410,   414,   418,   421,   424,   427,   430,   433,   436,   439,
     441,   443,   447,   452,   457,   462,   469,   471,   473,   475,
     477,   480,   483,   488,   493,   495,   503,   505,   515,   517,
     521,   523
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     103,     0,    -1,   104,   123,    -1,   123,    -1,   105,    -1,
     105,   104,    -1,   107,    -1,   118,    -1,   117,    47,    -1,
     106,    79,    -1,   106,    84,   108,    79,    -1,   106,    84,
     139,    79,    -1,   106,    84,     1,    79,    -1,   109,    -1,
     114,    -1,    47,    -1,   110,    -1,   111,    -1,    49,    -1,
      50,    -1,    51,    -1,    52,    -1,    53,    -1,   112,    -1,
     113,    -1,    85,   108,    97,   108,    97,   108,    86,    -1,
      76,    -1,    85,   108,    97,   108,    97,   108,    97,   108,
      86,    -1,    77,    -1,    98,   115,    99,    -1,    98,    99,
      -1,   116,    -1,   116,    97,   115,    -1,   109,    -1,     3,
      -1,     4,    -1,     5,    -1,     6,    -1,     7,    -1,     8,
      -1,     9,    -1,    47,    94,    95,   129,    -1,   106,    94,
      95,   129,    -1,    47,    94,   119,    95,   129,    -1,   106,
      94,   119,    95,   129,    -1,   120,    -1,   120,    97,   119,
      -1,   117,    47,    -1,   122,    -1,   122,    97,   121,    -1,
     117,    47,    -1,   125,    -1,   125,   124,    -1,   126,    -1,
     126,   124,    -1,    48,   100,   127,   101,    -1,    48,   100,
     101,    -1,    10,    47,   100,   127,   101,    -1,    10,    47,
     100,   101,    -1,   128,    -1,   128,   127,    -1,    47,    94,
      95,   129,    -1,    47,    94,   121,    95,   129,    -1,   100,
     101,    -1,   100,   130,   101,    -1,   131,    -1,   130,   131,
      -1,    79,    -1,    10,    47,    79,    -1,    10,    48,    79,
      -1,    12,    47,    79,    -1,    80,    47,    79,    -1,    13,
     139,    79,    -1,    13,    79,    -1,   139,    79,    -1,   132,
      79,    -1,   129,    -1,    69,    94,   139,    95,   131,    -1,
      69,    94,   139,    95,   131,    70,   131,    -1,    71,    94,
     133,    79,   139,    79,   133,    95,   131,    -1,    72,   131,
      73,    94,   139,    95,    79,    -1,    73,    94,   139,    95,
     131,    -1,     1,    79,    -1,   117,    47,    -1,   117,    47,
      84,   139,    -1,    -1,   134,    -1,   139,    -1,   139,    97,
     134,    -1,    -1,   136,    -1,   139,    -1,   139,    97,   136,
      -1,    -1,   138,    -1,   139,    -1,   139,    97,   138,    -1,
     140,    -1,   146,    84,   139,    -1,   146,    56,   139,    -1,
     146,    57,   139,    -1,   146,    58,   139,    -1,   146,    59,
     139,    -1,   146,    60,   139,    -1,   139,    61,   139,    -1,
     139,    62,   139,    -1,   139,    64,   139,    -1,   139,    63,
     139,    -1,   139,    85,   139,    -1,   139,    86,   139,    -1,
     139,    87,   139,    -1,   139,    81,   139,    -1,   139,    88,
     139,    -1,   139,    89,   139,    -1,   139,    90,   139,    -1,
     139,    91,   139,    -1,   139,    92,   139,    -1,   139,    93,
     139,    -1,   139,    65,   139,    -1,   139,    66,   139,    -1,
     139,    67,   139,    -1,   139,    68,   139,    -1,   139,    49,
      -1,   139,    52,    -1,    81,   139,    -1,    82,   139,    -1,
      83,   139,    -1,    54,   146,    -1,    55,   146,    -1,   141,
      -1,   142,    -1,    94,   139,    95,    -1,    94,   117,    95,
     146,    -1,    94,   117,    95,   110,    -1,    94,   117,    95,
     142,    -1,    94,   117,    95,    94,   139,    95,    -1,   143,
      -1,   144,    -1,   145,    -1,   146,    -1,   146,    54,    -1,
     146,    55,    -1,    47,    94,   135,    95,    -1,    74,    94,
     139,    95,    -1,   110,    -1,    85,   139,    97,   139,    97,
     139,    86,    -1,    76,    -1,    85,   139,    97,   139,    97,
     139,    97,   139,    86,    -1,    77,    -1,    98,   137,    99,
      -1,    47,    -1,    47,    75,    47,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   253,   253,   257,   264,   269,   282,   286,   293,   300,
     304,   308,   313,   320,   324,   331,   335,   339,   346,   350,
     354,   358,   362,   369,   373,   380,   384,   391,   395,   402,
     406,   413,   417,   429,   436,   440,   444,   448,   452,   456,
     460,   467,   471,   475,   479,   486,   490,   503,   510,   514,
     527,   534,   538,   551,   556,   569,   573,   581,   585,   593,
     597,   609,   613,   620,   624,   631,   636,   648,   652,   656,
     660,   664,   668,   672,   676,   680,   684,   688,   692,   696,
     700,   704,   708,   715,   719,   728,   732,   739,   743,   756,
     760,   767,   771,   784,   789,   796,   800,   812,   816,   820,
     825,   829,   833,   837,   841,   845,   849,   854,   859,   863,
     867,   871,   875,   879,   883,   887,   891,   895,   899,   903,
     907,   911,   915,   925,   937,   941,   945,   949,   953,   957,
     961,   965,   972,   976,   980,   984,   991,   996,  1000,  1004,
    1008,  1012,  1016,  1025,  1029,  1036,  1040,  1047,  1051,  1058,
    1065,  1069
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER", "FLOAT_TYPE", "STRING",
  "LLKEY", "VECTOR", "QUATERNION", "LIST", "STATE", "EVENT", "JUMP",
  "RETURN", "STATE_ENTRY", "STATE_EXIT", "TOUCH_START", "TOUCH",
  "TOUCH_END", "COLLISION_START", "COLLISION", "COLLISION_END",
  "LAND_COLLISION_START", "LAND_COLLISION", "LAND_COLLISION_END", "TIMER",
  "CHAT", "SENSOR", "NO_SENSOR", "CONTROL", "AT_TARGET", "NOT_AT_TARGET",
  "AT_ROT_TARGET", "NOT_AT_ROT_TARGET", "MONEY", "EMAIL",
  "RUN_TIME_PERMISSIONS", "INVENTORY", "ATTACH", "DATASERVER",
  "MOVING_START", "MOVING_END", "REZ", "OBJECT_REZ", "LINK_MESSAGE",
  "REMOTE_DATA", "HTTP_RESPONSE", "IDENTIFIER", "STATE_DEFAULT",
  "INTEGER_CONSTANT", "INTEGER_TRUE", "INTEGER_FALSE", "FP_CONSTANT",
  "STRING_CONSTANT", "INC_OP", "DEC_OP", "ADD_ASSIGN", "SUB_ASSIGN",
  "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "EQ", "NEQ", "GEQ", "LEQ",
  "BOOLEAN_AND", "BOOLEAN_OR", "SHIFT_LEFT", "SHIFT_RIGHT", "IF", "ELSE",
  "FOR", "DO", "WHILE", "PRINT", "PERIOD", "ZERO_VECTOR", "ZERO_ROTATION",
  "LOWER_THAN_ELSE", "';'", "'@'", "'-'", "'!'", "'~'", "'='", "'<'",
  "'>'", "'+'", "'*'", "'/'", "'%'", "'&'", "'|'", "'^'", "'('", "')'",
  "INITIALIZER", "','", "'['", "']'", "'{'", "'}'", "$accept",
  "lscript_program", "globals", "global", "name_type", "global_variable",
  "simple_assignable", "simple_assignable_no_list", "constant",
  "special_constant", "vector_constant", "quaternion_constant",
  "list_constant", "list_entries", "list_entry", "typename",
  "global_function", "function_parameters", "function_parameter",
  "event_parameters", "event_parameter", "states", "other_states",
  "default", "state", "state_body", "event", "compound_statement",
  "statements", "statement", "declaration", "forexpressionlist",
  "nextforexpressionlist", "funcexpressionlist", "nextfuncexpressionlist",
  "listexpressionlist", "nextlistexpressionlist", "expression",
  "unaryexpression", "typecast", "unarypostfixexpression",
  "vector_initializer", "quaternion_initializer", "list_initializer",
  "lvalue", YY_NULL
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,    59,
      64,    45,    33,   126,    61,    60,    62,    43,    42,    47,
      37,    38,   124,    94,    40,    41,   334,    44,    91,    93,
     123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   102,   103,   103,   104,   104,   105,   105,   106,   107,
     107,   107,   107,   108,   108,   109,   109,   109,   110,   110,
     110,   110,   110,   111,   111,   112,   112,   113,   113,   114,
     114,   115,   115,   116,   117,   117,   117,   117,   117,   117,
     117,   118,   118,   118,   118,   119,   119,   120,   121,   121,
     122,   123,   123,   124,   124,   125,   125,   126,   126,   127,
     127,   128,   128,   129,   129,   130,   130,   131,   131,   131,
     131,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   131,   131,   132,   132,   133,   133,   134,   134,   135,
     135,   136,   136,   137,   137,   138,   138,   139,   139,   139,
     139,   139,   139,   139,   139,   139,   139,   139,   139,   139,
     139,   139,   139,   139,   139,   139,   139,   139,   139,   139,
     139,   139,   139,   139,   140,   140,   140,   140,   140,   140,
     140,   140,   141,   141,   141,   141,   142,   142,   142,   142,
     142,   142,   142,   142,   142,   143,   143,   144,   144,   145,
     146,   146
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     1,     2,     1,     1,     2,     2,
       4,     4,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     7,     1,     9,     1,     3,
       2,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     5,     5,     1,     3,     2,     1,     3,
       2,     1,     2,     1,     2,     4,     3,     5,     4,     1,
       2,     4,     5,     2,     3,     1,     2,     1,     3,     3,
       3,     3,     3,     2,     2,     2,     1,     5,     7,     9,
       7,     5,     2,     2,     4,     0,     1,     1,     3,     0,
       1,     1,     3,     0,     1,     1,     3,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     2,     2,     2,     2,     2,     1,
       1,     3,     4,     4,     4,     6,     1,     1,     1,     1,
       2,     2,     4,     4,     1,     7,     1,     9,     1,     3,
       1,     3
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    34,    35,    36,    37,    38,    39,    40,     0,     0,
       0,     0,     4,     0,     6,     0,     7,     3,    51,     0,
       0,     1,     2,     5,     9,     0,     0,     8,     0,    52,
      53,     0,     0,     0,    45,     0,    56,     0,    59,     0,
     150,    18,    19,    20,    21,    22,     0,     0,     0,   146,
     148,     0,     0,     0,     0,     0,     0,     0,    13,   144,
      17,    23,    24,    14,     0,    97,   129,   130,   136,   137,
     138,   139,     0,     0,     0,    54,     0,    41,    47,     0,
       0,     0,    55,    60,    12,     0,    89,   150,   127,   128,
       0,   150,   146,   148,     0,    93,   144,   124,   125,   126,
       0,     0,     0,     0,    30,    33,     0,    31,     0,    94,
      95,    10,   122,   123,     0,     0,     0,     0,     0,     0,
       0,     0,    11,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   140,   141,     0,     0,     0,     0,     0,
       0,    42,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    67,     0,    63,     0,    76,     0,    65,     0,
       0,    43,    46,     0,     0,     0,    48,   151,     0,    90,
      91,     0,     0,     0,     0,   131,    29,     0,   149,     0,
     104,   105,   107,   106,   118,   119,   120,   121,   111,   108,
     109,   110,   112,   113,   114,   115,   116,   117,    99,   100,
     101,   102,   103,    98,    44,    58,     0,    82,     0,     0,
       0,    73,     0,     0,    85,     0,     0,     0,    83,    64,
      66,    75,    74,    61,    50,     0,     0,   142,     0,   143,
      15,    26,    28,     0,     0,     0,    16,     0,     0,   133,
     134,   132,    32,    96,    57,    68,    69,    70,    72,     0,
       0,    86,    87,     0,     0,    71,     0,    62,    49,    92,
       0,     0,     0,     0,     0,     0,     0,     0,    84,     0,
       0,   135,    77,     0,    88,     0,    81,    25,     0,   145,
       0,     0,    85,     0,     0,     0,    78,     0,    80,    27,
     147,     0,    79
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    10,    11,    12,    13,    14,   100,    58,    96,    60,
      61,    62,    63,   106,   107,   155,    16,    33,    34,   165,
     166,    17,    29,    18,    30,    37,    38,   156,   157,   158,
     159,   250,   251,   168,   169,   108,   109,   160,    65,    66,
      67,    68,    69,    70,    71
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -143
static const yytype_int16 yypact[] =
{
     477,  -143,  -143,  -143,  -143,  -143,  -143,  -143,   -87,   -75,
      33,   -35,   323,    57,  -143,     0,  -143,  -143,    41,    13,
     -46,  -143,  -143,  -143,  -143,   365,    32,  -143,    10,  -143,
      41,   -41,    20,   -27,   -19,   -17,  -143,   -29,    28,    18,
     -23,  -143,  -143,  -143,  -143,  -143,    70,    70,   -15,   -55,
     103,   535,   535,   535,   572,   461,   424,    39,  -143,   135,
    -143,  -143,  -143,  -143,  1169,  -143,  -143,  -143,  -143,  -143,
    -143,   507,   -41,    -7,    24,  -143,   217,  -143,  -143,   -41,
     316,    78,  -143,  -143,  -143,    73,   535,    53,  -143,  -143,
     535,   -32,  -143,  -143,   535,   535,  -143,   127,    -4,    -4,
      34,   623,    35,   899,  -143,  -143,    48,    36,    69,  -143,
     669,  -143,  -143,  -143,   535,   535,   535,   535,   535,   535,
     535,   535,  -143,   535,   535,   535,   535,   535,   535,   535,
     535,   535,   535,  -143,  -143,   535,   535,   535,   535,   535,
     535,  -143,   -41,   -43,    74,     2,    85,   498,    80,    81,
     355,    83,  -143,   124,  -143,   125,  -143,   300,  -143,   102,
    1214,  -143,  -143,   -41,   136,    90,    96,  -143,    95,  -143,
     715,   944,   443,   535,   110,  -143,  -143,   198,  -143,   535,
    1586,  1586,  1515,  1515,  1439,  1439,    77,    77,   127,  1515,
    1515,   127,    -4,    -4,    -4,  1558,  1484,  1527,  1349,  1349,
    1349,  1349,  1349,  1349,  -143,  -143,    97,  -143,   115,   117,
     118,  -143,  1259,   535,   535,   128,   535,   126,   122,  -143,
    -143,  -143,  -143,  -143,  -143,   -41,   316,  -143,   535,  -143,
    -143,  -143,  -143,   443,    93,   112,  -143,   761,   535,  -143,
    -143,     9,  -143,  -143,  -143,  -143,  -143,  -143,  -143,   989,
     131,  -143,   807,   113,  1034,  -143,   535,  -143,  -143,  -143,
     443,   535,  1079,   355,   535,   535,   535,   355,  1349,   -74,
     853,  -143,   149,  1304,  -143,  1124,  -143,  -143,   443,   585,
     535,   355,   535,   154,   142,  1394,  -143,   140,  -143,  -143,
     585,   355,  -143
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -143,  -143,   225,  -143,  -143,  -143,   -16,   -54,   -22,  -143,
    -143,  -143,  -143,    65,  -143,    54,  -143,   -20,  -143,    17,
    -143,   235,   222,  -143,  -143,   -24,  -143,   -26,  -143,  -142,
    -143,   -21,   -12,  -143,    30,  -143,    84,   -25,  -143,  -143,
      86,  -143,  -143,  -143,   -36
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -29
static const yytype_int16 yytable[] =
{
      64,    35,   105,    59,    35,    77,    73,    19,   215,    57,
      88,    89,   277,     9,    83,   220,     1,     2,     3,     4,
       5,     6,     7,   278,   -26,    20,    97,    98,    99,   101,
     103,   110,    59,    21,    59,     1,     2,     3,     4,     5,
       6,     7,   -26,    85,   -26,   112,   141,    27,   113,   208,
     209,    28,    85,   161,    15,    36,   -15,    74,   205,    76,
     162,   170,    86,   133,   134,   171,    15,    78,    79,   101,
     110,    86,    82,    32,   -15,    35,   -15,    81,    80,    90,
      32,     1,     2,     3,     4,     5,     6,     7,   142,   180,
     181,   182,   183,   184,   185,   186,   187,    84,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,    31,   102,
     198,   199,   200,   201,   202,   203,   204,    87,   111,   206,
     167,   272,   212,   105,   143,   276,   112,    72,    85,   113,
     174,   172,   210,   177,    32,   164,    24,   223,   241,   286,
     230,    25,    41,    42,    43,    44,    45,   176,   237,   292,
     236,    26,   239,   207,   110,   236,   235,    91,   123,    41,
      42,    43,    44,    45,   126,   127,   128,   129,   178,   231,
     232,   217,   218,   163,   213,   214,   112,   216,   233,   113,
     105,   221,   -28,   224,    48,   225,    92,    93,   249,   252,
     227,   254,   104,   226,   245,    94,   246,   247,   244,   257,
     -28,   253,   -28,   170,   238,   255,   256,   266,    95,   260,
     264,   236,   236,   262,   -16,   127,   128,   129,   144,   281,
       1,     2,     3,     4,     5,     6,     7,   145,   289,   146,
     147,   268,   -16,   288,   -16,   291,   270,    23,   236,   273,
     252,   275,   242,   258,   269,   230,    22,    41,    42,    43,
      44,    45,    75,   274,   190,   285,   236,   252,   259,     0,
     240,   287,   284,   243,    91,   190,    41,    42,    43,    44,
      45,    46,    47,     0,   231,   232,     0,     0,     0,     0,
     164,     0,     0,   233,     0,     0,   148,     0,   149,   150,
     151,    48,     0,    92,    93,     0,   152,   153,    51,    52,
      53,   144,    94,     1,     2,     3,     4,     5,     6,     7,
     145,    55,   146,   147,     0,    95,     0,    76,   154,     1,
       2,     3,     4,     5,     6,     7,     1,     2,     3,     4,
       5,     6,     7,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    91,     0,    41,
      42,    43,    44,    45,    46,    47,   144,     0,     1,     2,
       3,     4,     5,     6,     7,   145,    39,   146,   147,   148,
       8,   149,   150,   151,    48,     0,    92,    93,     0,   152,
     153,    51,    52,    53,     0,    94,     0,     0,     0,     0,
       0,     0,     0,     0,    55,     0,     0,     0,    95,     0,
      76,   219,    91,     0,    41,    42,    43,    44,    45,    46,
      47,     0,    40,     0,    41,    42,    43,    44,    45,    46,
      47,     0,     0,     0,   148,     0,   149,   150,   151,    48,
       0,    92,    93,     0,   152,   153,    51,    52,    53,    48,
      94,    49,    50,     0,     0,     0,    51,    52,    53,    55,
      54,     0,     0,    95,     0,    76,     0,     0,     0,    55,
       0,     0,     0,    56,     1,     2,     3,     4,     5,     6,
       7,    40,     0,    41,    42,    43,    44,    45,    46,    47,
       1,     2,     3,     4,     5,     6,     7,     0,     0,     0,
     230,     0,    41,    42,    43,    44,    45,     0,    48,     0,
      49,    50,     0,     0,     0,    51,    52,    53,    91,    54,
      41,    42,    43,    44,    45,    46,    47,     0,    55,   231,
     232,     0,    95,   104,     8,     9,     0,     0,   233,     0,
       0,     0,     0,     0,     0,    48,     0,    92,    93,     0,
       0,   234,    51,    52,    53,    91,    94,    41,    42,    43,
      44,    45,    46,    47,     0,    55,     0,     0,     0,    95,
       0,   133,   134,   135,   136,   137,   138,   139,     0,     0,
       0,     0,    48,     0,    92,    93,     0,   211,     0,    51,
      52,    53,    91,    94,    41,    42,    43,    44,    45,    46,
      47,   140,    55,     0,     0,     0,    95,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    48,
       0,    92,    93,     0,     0,     0,    51,    52,    53,    40,
      94,    41,    42,    43,    44,    45,    46,    47,     0,    55,
       0,     0,    91,    95,    41,    42,    43,    44,    45,    46,
      47,     0,     0,     0,     0,     0,    48,     0,    49,    50,
       0,     0,     0,    51,    52,    53,     0,    54,     0,    48,
       0,    92,    93,     0,     0,     0,    55,    52,    53,     0,
      56,     0,   112,     0,     0,   113,     0,     0,     0,    55,
       0,     0,     0,    95,   114,   115,   116,   117,   118,   119,
     120,   121,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   123,     0,     0,     0,   124,   125,
     126,   127,   128,   129,   130,   131,   132,     0,   112,     0,
     173,   113,     0,     0,     0,     0,     0,     0,     0,     0,
     114,   115,   116,   117,   118,   119,   120,   121,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     123,     0,     0,     0,   124,   125,   126,   127,   128,   129,
     130,   131,   132,     0,   112,     0,   179,   113,     0,     0,
       0,     0,     0,     0,     0,     0,   114,   115,   116,   117,
     118,   119,   120,   121,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   123,     0,     0,     0,
     124,   125,   126,   127,   128,   129,   130,   131,   132,     0,
     112,     0,   228,   113,     0,     0,     0,     0,     0,     0,
       0,     0,   114,   115,   116,   117,   118,   119,   120,   121,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   123,     0,     0,     0,   124,   125,   126,   127,
     128,   129,   130,   131,   132,     0,   112,     0,   261,   113,
       0,     0,     0,     0,     0,     0,     0,     0,   114,   115,
     116,   117,   118,   119,   120,   121,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   123,     0,
       0,     0,   124,   125,   126,   127,   128,   129,   130,   131,
     132,     0,   112,     0,   265,   113,     0,     0,     0,     0,
       0,     0,     0,     0,   114,   115,   116,   117,   118,   119,
     120,   121,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   123,     0,     0,     0,   124,   279,
     126,   127,   128,   129,   130,   131,   132,     0,   112,     0,
     280,   113,     0,     0,     0,     0,     0,     0,     0,     0,
     114,   115,   116,   117,   118,   119,   120,   121,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     123,     0,     0,     0,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   112,   175,     0,   113,     0,     0,     0,
       0,     0,     0,     0,     0,   114,   115,   116,   117,   118,
     119,   120,   121,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   123,     0,     0,     0,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   112,   229,
       0,   113,     0,     0,     0,     0,     0,     0,     0,     0,
     114,   115,   116,   117,   118,   119,   120,   121,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     123,     0,     0,     0,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   112,   263,     0,   113,     0,     0,     0,
       0,     0,     0,     0,     0,   114,   115,   116,   117,   118,
     119,   120,   121,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   123,     0,     0,     0,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   112,   267,
       0,   113,     0,     0,     0,     0,     0,     0,     0,     0,
     114,   115,   116,   117,   118,   119,   120,   121,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     123,     0,     0,     0,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   112,   271,     0,   113,     0,     0,     0,
       0,     0,     0,     0,     0,   114,   115,   116,   117,   118,
     119,   120,   121,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   123,     0,     0,     0,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   112,   283,
       0,   113,     0,     0,     0,     0,     0,     0,     0,     0,
     114,   115,   116,   117,   118,   119,   120,   121,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   122,     0,
     123,     0,     0,     0,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   112,     0,     0,   113,     0,     0,     0,
       0,     0,     0,     0,     0,   114,   115,   116,   117,   118,
     119,   120,   121,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   222,     0,   123,     0,     0,     0,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   112,     0,
       0,   113,     0,     0,     0,     0,     0,     0,     0,     0,
     114,   115,   116,   117,   118,   119,   120,   121,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   248,     0,
     123,     0,     0,     0,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   112,     0,     0,   113,     0,     0,     0,
       0,     0,     0,     0,     0,   114,   115,   116,   117,   118,
     119,   120,   121,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   282,     0,   123,     0,     0,     0,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   112,     0,
       0,   113,     0,     0,     0,     0,     0,     0,     0,     0,
     114,   115,   116,   117,   118,   119,   120,   121,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     123,     0,     0,     0,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   112,     0,     0,   113,     0,     0,     0,
       0,     0,     0,     0,     0,   114,   115,   116,   117,   118,
     119,   120,   121,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   123,     0,     0,     0,   124,
     290,   126,   127,   128,   129,   130,   131,   132,   112,     0,
       0,   113,     0,     0,     0,     0,     0,     0,     0,     0,
     114,   115,   116,   117,     0,     0,   120,   121,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     123,     0,     0,     0,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   112,     0,     0,   113,     0,     0,     0,
       0,     0,     0,     0,     0,   114,   115,   116,   117,     0,
       0,   120,   121,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   112,   123,     0,   113,     0,   124,
     125,   126,   127,   128,   129,   130,   112,   132,     0,   113,
       0,     0,   120,   121,     0,     0,     0,     0,   114,   115,
     116,   117,     0,     0,   120,   121,   123,     0,     0,     0,
       0,     0,   126,   127,   128,   129,     0,   112,   123,     0,
     113,     0,   124,   125,   126,   127,   128,   129,   130,   114,
     115,   116,   117,     0,     0,   120,   121,     0,     0,     0,
       0,     0,     0,     0,     0,   112,     0,     0,   113,   123,
       0,     0,     0,   124,   125,   126,   127,   128,   129,   116,
     117,     0,     0,   120,   121,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   123,     0,     0,
       0,   124,   125,   126,   127,   128,   129
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-143)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      25,    47,    56,    25,    47,    31,    26,    94,   150,    25,
      46,    47,    86,    48,    38,   157,     3,     4,     5,     6,
       7,     8,     9,    97,    79,   100,    51,    52,    53,    54,
      55,    56,    54,     0,    56,     3,     4,     5,     6,     7,
       8,     9,    97,    75,    99,    49,    72,    47,    52,    47,
      48,    10,    75,    79,     0,   101,    79,    47,   101,   100,
      80,    86,    94,    54,    55,    90,    12,    47,    95,    94,
      95,    94,   101,    19,    97,    47,    99,    94,    97,    94,
      26,     3,     4,     5,     6,     7,     8,     9,    95,   114,
     115,   116,   117,   118,   119,   120,   121,    79,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,    95,    55,
     135,   136,   137,   138,   139,   140,   142,    47,    79,   143,
      47,   263,   147,   177,   100,   267,    49,    95,    75,    52,
      95,    97,    47,    97,    80,    81,    79,   163,   174,   281,
      47,    84,    49,    50,    51,    52,    53,    99,   173,   291,
     172,    94,   174,    79,   179,   177,   172,    47,    81,    49,
      50,    51,    52,    53,    87,    88,    89,    90,    99,    76,
      77,    47,    47,    95,    94,    94,    49,    94,    85,    52,
     234,    79,    79,    47,    74,    95,    76,    77,   213,   214,
      95,   216,    99,    97,    79,    85,    79,    79,   101,   225,
      97,    73,    99,   228,    94,    79,    84,    94,    98,    97,
      79,   233,   234,   238,    79,    88,    89,    90,     1,    70,
       3,     4,     5,     6,     7,     8,     9,    10,    86,    12,
      13,   256,    97,    79,    99,    95,   261,    12,   260,   264,
     265,   266,   177,   226,   260,    47,    11,    49,    50,    51,
      52,    53,    30,   265,   279,   280,   278,   282,   228,    -1,
     174,   282,   278,   179,    47,   290,    49,    50,    51,    52,
      53,    54,    55,    -1,    76,    77,    -1,    -1,    -1,    -1,
     226,    -1,    -1,    85,    -1,    -1,    69,    -1,    71,    72,
      73,    74,    -1,    76,    77,    -1,    79,    80,    81,    82,
      83,     1,    85,     3,     4,     5,     6,     7,     8,     9,
      10,    94,    12,    13,    -1,    98,    -1,   100,   101,     3,
       4,     5,     6,     7,     8,     9,     3,     4,     5,     6,
       7,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,    49,
      50,    51,    52,    53,    54,    55,     1,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,     1,    12,    13,    69,
      47,    71,    72,    73,    74,    -1,    76,    77,    -1,    79,
      80,    81,    82,    83,    -1,    85,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    94,    -1,    -1,    -1,    98,    -1,
     100,   101,    47,    -1,    49,    50,    51,    52,    53,    54,
      55,    -1,    47,    -1,    49,    50,    51,    52,    53,    54,
      55,    -1,    -1,    -1,    69,    -1,    71,    72,    73,    74,
      -1,    76,    77,    -1,    79,    80,    81,    82,    83,    74,
      85,    76,    77,    -1,    -1,    -1,    81,    82,    83,    94,
      85,    -1,    -1,    98,    -1,   100,    -1,    -1,    -1,    94,
      -1,    -1,    -1,    98,     3,     4,     5,     6,     7,     8,
       9,    47,    -1,    49,    50,    51,    52,    53,    54,    55,
       3,     4,     5,     6,     7,     8,     9,    -1,    -1,    -1,
      47,    -1,    49,    50,    51,    52,    53,    -1,    74,    -1,
      76,    77,    -1,    -1,    -1,    81,    82,    83,    47,    85,
      49,    50,    51,    52,    53,    54,    55,    -1,    94,    76,
      77,    -1,    98,    99,    47,    48,    -1,    -1,    85,    -1,
      -1,    -1,    -1,    -1,    -1,    74,    -1,    76,    77,    -1,
      -1,    98,    81,    82,    83,    47,    85,    49,    50,    51,
      52,    53,    54,    55,    -1,    94,    -1,    -1,    -1,    98,
      -1,    54,    55,    56,    57,    58,    59,    60,    -1,    -1,
      -1,    -1,    74,    -1,    76,    77,    -1,    79,    -1,    81,
      82,    83,    47,    85,    49,    50,    51,    52,    53,    54,
      55,    84,    94,    -1,    -1,    -1,    98,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,
      -1,    76,    77,    -1,    -1,    -1,    81,    82,    83,    47,
      85,    49,    50,    51,    52,    53,    54,    55,    -1,    94,
      -1,    -1,    47,    98,    49,    50,    51,    52,    53,    54,
      55,    -1,    -1,    -1,    -1,    -1,    74,    -1,    76,    77,
      -1,    -1,    -1,    81,    82,    83,    -1,    85,    -1,    74,
      -1,    76,    77,    -1,    -1,    -1,    94,    82,    83,    -1,
      98,    -1,    49,    -1,    -1,    52,    -1,    -1,    -1,    94,
      -1,    -1,    -1,    98,    61,    62,    63,    64,    65,    66,
      67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    -1,    49,    -1,
      97,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      61,    62,    63,    64,    65,    66,    67,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      81,    -1,    -1,    -1,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    -1,    49,    -1,    97,    52,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    61,    62,    63,    64,
      65,    66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    -1,
      49,    -1,    97,    52,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    -1,    -1,    -1,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    -1,    49,    -1,    97,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,
      -1,    -1,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    -1,    49,    -1,    97,    52,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    61,    62,    63,    64,    65,    66,
      67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    -1,    49,    -1,
      97,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      61,    62,    63,    64,    65,    66,    67,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      81,    -1,    -1,    -1,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    49,    95,    -1,    52,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    61,    62,    63,    64,    65,
      66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    49,    95,
      -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      61,    62,    63,    64,    65,    66,    67,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      81,    -1,    -1,    -1,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    49,    95,    -1,    52,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    61,    62,    63,    64,    65,
      66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    49,    95,
      -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      61,    62,    63,    64,    65,    66,    67,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      81,    -1,    -1,    -1,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    49,    95,    -1,    52,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    61,    62,    63,    64,    65,
      66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    49,    95,
      -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      61,    62,    63,    64,    65,    66,    67,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,    -1,
      81,    -1,    -1,    -1,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    49,    -1,    -1,    52,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    61,    62,    63,    64,    65,
      66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    79,    -1,    81,    -1,    -1,    -1,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    49,    -1,
      -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      61,    62,    63,    64,    65,    66,    67,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    79,    -1,
      81,    -1,    -1,    -1,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    49,    -1,    -1,    52,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    61,    62,    63,    64,    65,
      66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    79,    -1,    81,    -1,    -1,    -1,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    49,    -1,
      -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      61,    62,    63,    64,    65,    66,    67,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      81,    -1,    -1,    -1,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    49,    -1,    -1,    52,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    61,    62,    63,    64,    65,
      66,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    49,    -1,
      -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      61,    62,    63,    64,    -1,    -1,    67,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      81,    -1,    -1,    -1,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    49,    -1,    -1,    52,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    61,    62,    63,    64,    -1,
      -1,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    49,    81,    -1,    52,    -1,    85,
      86,    87,    88,    89,    90,    91,    49,    93,    -1,    52,
      -1,    -1,    67,    68,    -1,    -1,    -1,    -1,    61,    62,
      63,    64,    -1,    -1,    67,    68,    81,    -1,    -1,    -1,
      -1,    -1,    87,    88,    89,    90,    -1,    49,    81,    -1,
      52,    -1,    85,    86,    87,    88,    89,    90,    91,    61,
      62,    63,    64,    -1,    -1,    67,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,    52,    81,
      -1,    -1,    -1,    85,    86,    87,    88,    89,    90,    63,
      64,    -1,    -1,    67,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    -1,    -1,
      -1,    85,    86,    87,    88,    89,    90
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    47,    48,
     103,   104,   105,   106,   107,   117,   118,   123,   125,    94,
     100,     0,   123,   104,    79,    84,    94,    47,    10,   124,
     126,    95,   117,   119,   120,    47,   101,   127,   128,     1,
      47,    49,    50,    51,    52,    53,    54,    55,    74,    76,
      77,    81,    82,    83,    85,    94,    98,   108,   109,   110,
     111,   112,   113,   114,   139,   140,   141,   142,   143,   144,
     145,   146,    95,   119,    47,   124,   100,   129,    47,    95,
      97,    94,   101,   127,    79,    75,    94,    47,   146,   146,
      94,    47,    76,    77,    85,    98,   110,   139,   139,   139,
     108,   139,   117,   139,    99,   109,   115,   116,   137,   138,
     139,    79,    49,    52,    61,    62,    63,    64,    65,    66,
      67,    68,    79,    81,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    54,    55,    56,    57,    58,    59,    60,
      84,   129,    95,   100,     1,    10,    12,    13,    69,    71,
      72,    73,    79,    80,   101,   117,   129,   130,   131,   132,
     139,   129,   119,    95,   117,   121,   122,    47,   135,   136,
     139,   139,    97,    97,    95,    95,    99,    97,    99,    97,
     139,   139,   139,   139,   139,   139,   139,   139,   139,   139,
     139,   139,   139,   139,   139,   139,   139,   139,   139,   139,
     139,   139,   139,   139,   129,   101,   127,    79,    47,    48,
      47,    79,   139,    94,    94,   131,    94,    47,    47,   101,
     131,    79,    79,   129,    47,    95,    97,    95,    97,    95,
      47,    76,    77,    85,    98,   108,   110,   139,    94,   110,
     142,   146,   115,   138,   101,    79,    79,    79,    79,   139,
     133,   134,   139,    73,   139,    79,    84,   129,   121,   136,
      97,    97,   139,    95,    79,    97,    94,    95,   139,   108,
     139,    95,   131,   139,   134,   139,   131,    86,    97,    86,
      97,    70,    79,    95,   108,   139,   131,   133,    79,    86,
      86,    95,   131
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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
      yyerror (&yylloc, scanner, YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (YYID (N))                                                     \
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
    while (YYID (0))
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

__attribute__((__unused__))
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
#else
static unsigned
yy_location_print_ (yyo, yylocp)
    FILE *yyo;
    YYLTYPE const * const yylocp;
#endif
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += fprintf (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += fprintf (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += fprintf (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += fprintf (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += fprintf (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (&yylval, &yylloc, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval, &yylloc, scanner)
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
		  Type, Value, Location, scanner); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, void *scanner)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, scanner)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
    void *scanner;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
  YYUSE (scanner);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, void *scanner)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp, scanner)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
    void *scanner;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, scanner);
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
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, void *scanner)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule, scanner)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
    void *scanner;
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
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       , scanner);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule, scanner); \
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
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
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
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
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, void *scanner)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp, scanner)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
    void *scanner;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (scanner);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/*----------.
| yyparse.  |
`----------*/

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
yyparse (void *scanner)
#else
int
yyparse (scanner)
    void *scanner;
#endif
#endif
{
/* The lookahead symbol.  */
int yychar;


#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
static YYSTYPE yyval_default;
# define YY_INITIAL_VALUE(Value) = Value
#endif
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc = yyloc_default;


    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
  if (yypact_value_is_default (yyn))
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
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
/* Line 1792 of yacc.c  */
#line 254 "lslmini.y"
    {
    script = new LLScriptScript((yyvsp[(1) - (2)].global_store), (yyvsp[(2) - (2)].state));
	}
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 258 "lslmini.y"
    {
    script = new LLScriptScript(NULL, (yyvsp[(1) - (1)].state));
	}
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 265 "lslmini.y"
    {
    DEBUG( LOG_DEBUG_SPAM, NULL, "** global\n");
    (yyval.global_store) = (yyvsp[(1) - (1)].global_store);
	}
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 270 "lslmini.y"
    {
    if ( (yyvsp[(1) - (2)].global_store) ) {
        DEBUG( LOG_DEBUG_SPAM, NULL, "** global [%p,%p] globals [%p,%p]\n", (yyvsp[(1) - (2)].global_store)->get_prev(), (yyvsp[(1) - (2)].global_store)->get_next(), (yyvsp[(2) - (2)].global_store)->get_prev(), (yyvsp[(2) - (2)].global_store)->get_next());
        (yyvsp[(1) - (2)].global_store)->add_next_sibling((yyvsp[(2) - (2)].global_store));
        (yyval.global_store) = (yyvsp[(1) - (2)].global_store);
    } else {
        (yyval.global_store) = (yyvsp[(2) - (2)].global_store);
    }
	}
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 283 "lslmini.y"
    {
    (yyval.global_store) = new LLScriptGlobalStorage((yyvsp[(1) - (1)].global), NULL);
	}
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 287 "lslmini.y"
    {
    (yyval.global_store) = new LLScriptGlobalStorage(NULL, (yyvsp[(1) - (1)].global_funcs));
	}
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 294 "lslmini.y"
    {
    (yyval.identifier) = new LLScriptIdentifier((yyvsp[(1) - (2)].type), (yyvsp[(2) - (2)].sval), &(yylsp[(2) - (2)]));
	}
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 301 "lslmini.y"
    {
    (yyval.global) = new LLScriptGlobalVariable((yyvsp[(1) - (2)].identifier), NULL);
	}
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 305 "lslmini.y"
    {
    (yyval.global) = new LLScriptGlobalVariable((yyvsp[(1) - (4)].identifier), (yyvsp[(3) - (4)].assignable));
	}
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 309 "lslmini.y"
    {
    ERROR(&(yylsp[(3) - (4)]), E_GLOBAL_INITIALIZER_NOT_CONSTANT);
    (yyval.global) = NULL;
    }
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 314 "lslmini.y"
    {
    (yyval.global) = NULL;
    }
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 321 "lslmini.y"
    {
    (yyval.assignable) = (yyvsp[(1) - (1)].assignable);
	}
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 325 "lslmini.y"
    {
    (yyval.assignable) = (yyvsp[(1) - (1)].assignable);
	}
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 332 "lslmini.y"
    {
    (yyval.assignable) = new LLScriptSimpleAssignable(new LLScriptIdentifier((yyvsp[(1) - (1)].sval)));
	}
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 336 "lslmini.y"
    {
    (yyval.assignable) = new LLScriptSimpleAssignable((yyvsp[(1) - (1)].constant));
	}
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 340 "lslmini.y"
    {
    (yyval.assignable) = (yyvsp[(1) - (1)].assignable); //new LLScriptSimpleAssignable($1);
	}
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 347 "lslmini.y"
    {
    (yyval.constant) = new LLScriptIntegerConstant((yyvsp[(1) - (1)].ival));
	}
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 351 "lslmini.y"
    {
    (yyval.constant) = new LLScriptIntegerConstant((yyvsp[(1) - (1)].ival));
	}
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 355 "lslmini.y"
    {
    (yyval.constant) = new LLScriptIntegerConstant((yyvsp[(1) - (1)].ival));
	}
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 359 "lslmini.y"
    {
    (yyval.constant) = new LLScriptFloatConstant((yyvsp[(1) - (1)].fval));
	}
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 363 "lslmini.y"
    {
    (yyval.constant) = new LLScriptStringConstant((yyvsp[(1) - (1)].sval));
	}
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 370 "lslmini.y"
    {
    (yyval.assignable) = (yyvsp[(1) - (1)].assignable);
	}
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 374 "lslmini.y"
    {
    (yyval.assignable) = (yyvsp[(1) - (1)].assignable);
	}
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 381 "lslmini.y"
    {
    (yyval.assignable) = new LLScriptSimpleAssignable(new LLScriptVectorConstant((yyvsp[(2) - (7)].assignable), (yyvsp[(4) - (7)].assignable), (yyvsp[(6) - (7)].assignable)));
	}
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 385 "lslmini.y"
    {
    (yyval.assignable) = new LLScriptSimpleAssignable(new LLScriptVectorConstant(0.0, 0.0, 0.0));
	}
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 392 "lslmini.y"
    {
    (yyval.assignable) = new LLScriptSimpleAssignable(new LLScriptQuaternionConstant((yyvsp[(2) - (9)].assignable), (yyvsp[(4) - (9)].assignable), (yyvsp[(6) - (9)].assignable), (yyvsp[(8) - (9)].assignable)));
	}
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 396 "lslmini.y"
    {
    (yyval.assignable) = new LLScriptSimpleAssignable(new LLScriptQuaternionConstant(0.0, 0.0, 0.0, 0.0));
	}
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 403 "lslmini.y"
    {
    (yyval.assignable) = new LLScriptSimpleAssignable(new LLScriptListConstant((yyvsp[(2) - (3)].assignable)));
	}
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 407 "lslmini.y"
    {
    (yyval.assignable) = new LLScriptSimpleAssignable(new LLScriptListConstant((LLScriptSimpleAssignable*)NULL));
	}
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 414 "lslmini.y"
    {
    (yyval.assignable) = (yyvsp[(1) - (1)].assignable);
	}
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 418 "lslmini.y"
    {
    if ( (yyvsp[(1) - (3)].assignable) ) {
        (yyvsp[(1) - (3)].assignable)->add_next_sibling((yyvsp[(3) - (3)].assignable));
        (yyval.assignable) = (yyvsp[(1) - (3)].assignable);
    } else {
        (yyval.assignable) = (yyvsp[(3) - (3)].assignable);
    }
	}
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 430 "lslmini.y"
    {
    (yyval.assignable) = (yyvsp[(1) - (1)].assignable);
	}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 437 "lslmini.y"
    {
    (yyval.type) = TYPE(LST_INTEGER);
	}
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 441 "lslmini.y"
    {
    (yyval.type) = TYPE(LST_FLOATINGPOINT);
	}
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 445 "lslmini.y"
    {  
    (yyval.type) = TYPE(LST_STRING);
	}
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 449 "lslmini.y"
    {  
    (yyval.type) = TYPE(LST_KEY);
	}
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 453 "lslmini.y"
    {  
    (yyval.type) = TYPE(LST_VECTOR);
	}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 457 "lslmini.y"
    {  
    (yyval.type) = TYPE(LST_QUATERNION);
	}
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 461 "lslmini.y"
    {
    (yyval.type) = TYPE(LST_LIST);
	}
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 468 "lslmini.y"
    {  
    (yyval.global_funcs) = new LLScriptGlobalFunction( MAKEID(LST_NULL, (yyvsp[(1) - (4)].sval), (yylsp[(1) - (4)])), NULL, (yyvsp[(4) - (4)].statement) );
	}
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 472 "lslmini.y"
    {
    (yyval.global_funcs) = new LLScriptGlobalFunction( (yyvsp[(1) - (4)].identifier), NULL, (yyvsp[(4) - (4)].statement) );
	}
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 476 "lslmini.y"
    {
    (yyval.global_funcs) = new LLScriptGlobalFunction( MAKEID(LST_NULL, (yyvsp[(1) - (5)].sval), (yylsp[(1) - (5)])), (yyvsp[(3) - (5)].global_decl), (yyvsp[(5) - (5)].statement) );
	}
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 480 "lslmini.y"
    {  
    (yyval.global_funcs) = new LLScriptGlobalFunction( (yyvsp[(1) - (5)].identifier), (yyvsp[(3) - (5)].global_decl), (yyvsp[(5) - (5)].statement) );
	}
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 487 "lslmini.y"
    {  
    (yyval.global_decl) = (yyvsp[(1) - (1)].global_decl);
	}
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 491 "lslmini.y"
    {  
      if ( (yyvsp[(1) - (3)].global_decl) ) {
          (yyvsp[(1) - (3)].global_decl)->push_child((yyvsp[(3) - (3)].global_decl)->get_children());
          //delete $3;
          (yyval.global_decl) = (yyvsp[(1) - (3)].global_decl);
      } else {
          (yyval.global_decl) = (yyvsp[(3) - (3)].global_decl);
      }
	}
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 504 "lslmini.y"
    {  
    (yyval.global_decl) = new LLScriptFunctionDec( new LLScriptIdentifier((yyvsp[(1) - (2)].type), (yyvsp[(2) - (2)].sval), &(yylsp[(2) - (2)])) );
	}
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 511 "lslmini.y"
    {  
    (yyval.global_event_decl) = (yyvsp[(1) - (1)].global_event_decl);
	}
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 515 "lslmini.y"
    {  
      if ( (yyvsp[(1) - (3)].global_event_decl) ) {
          (yyvsp[(1) - (3)].global_event_decl)->push_child((yyvsp[(3) - (3)].global_event_decl)->get_children());
          //delete $3;
          (yyval.global_event_decl) = (yyvsp[(1) - (3)].global_event_decl);
      } else {
          (yyval.global_event_decl) = (yyvsp[(3) - (3)].global_event_decl);
      }
	}
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 528 "lslmini.y"
    {  
    (yyval.global_event_decl) = new LLScriptEventDec( new LLScriptIdentifier((yyvsp[(1) - (2)].type), (yyvsp[(2) - (2)].sval), &(yylsp[(2) - (2)])) );
	}
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 535 "lslmini.y"
    {  
    (yyval.state) = (yyvsp[(1) - (1)].state);
	}
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 539 "lslmini.y"
    {  
    if ( (yyvsp[(1) - (2)].state) ) {
        DEBUG( LOG_DEBUG_SPAM, NULL, "---- default [%p,%p] other_states [%p,%p]\n", (yyvsp[(1) - (2)].state)->get_prev(), (yyvsp[(1) - (2)].state)->get_next(), (yyvsp[(2) - (2)].state)->get_prev(), (yyvsp[(2) - (2)].state)->get_next());
        (yyvsp[(1) - (2)].state)->add_next_sibling((yyvsp[(2) - (2)].state));
        (yyval.state) = (yyvsp[(1) - (2)].state);
    } else {
        (yyval.state) = (yyvsp[(2) - (2)].state);
    }
	}
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 552 "lslmini.y"
    {  
    //DEBUG(200,"--(%d)-- state\n", yylloc.first_line);
    (yyval.state) = (yyvsp[(1) - (1)].state);
	}
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 557 "lslmini.y"
    {  
    //DEBUG(200,"--(%d)-- state other_states\n", yylloc.first_line);
    if ( (yyvsp[(1) - (2)].state) ) {
        (yyvsp[(1) - (2)].state)->add_next_sibling((yyvsp[(2) - (2)].state));
        (yyval.state) = (yyvsp[(1) - (2)].state);
    } else {
        (yyval.state) = (yyvsp[(2) - (2)].state);
    }
	}
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 570 "lslmini.y"
    {  
    (yyval.state) = new LLScriptState( NULL, (yyvsp[(3) - (4)].handler) );
	}
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 574 "lslmini.y"
    {
    ERROR( &(yylsp[(1) - (3)]), E_NO_EVENT_HANDLERS );
    (yyval.state) = new LLScriptState( NULL, NULL );
    }
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 582 "lslmini.y"
    {  
    (yyval.state) = new LLScriptState( MAKEID(LST_NULL, (yyvsp[(2) - (5)].sval), (yylsp[(2) - (5)])), (yyvsp[(4) - (5)].handler) );
	}
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 586 "lslmini.y"
    {
    ERROR( &(yylsp[(1) - (4)]), E_NO_EVENT_HANDLERS );
    (yyval.state) = new LLScriptState( NULL, NULL );
    }
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 594 "lslmini.y"
    {  
    (yyval.handler) = (yyvsp[(1) - (1)].handler);
	}
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 598 "lslmini.y"
    {  
    if ( (yyvsp[(1) - (2)].handler) ) {
        (yyvsp[(1) - (2)].handler)->add_next_sibling((yyvsp[(2) - (2)].handler));
        (yyval.handler) = (yyvsp[(1) - (2)].handler);
    } else {
        (yyval.handler) = (yyvsp[(2) - (2)].handler);
    }
	}
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 610 "lslmini.y"
    {  
    (yyval.handler) = new LLScriptEventHandler(MAKEID(LST_NULL, (yyvsp[(1) - (4)].sval), (yylsp[(1) - (4)])), NULL, (yyvsp[(4) - (4)].statement));
	}
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 614 "lslmini.y"
    {  
    (yyval.handler) = new LLScriptEventHandler(MAKEID(LST_NULL, (yyvsp[(1) - (5)].sval), (yylsp[(1) - (5)])), (yyvsp[(3) - (5)].global_event_decl), (yyvsp[(5) - (5)].statement));
	}
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 621 "lslmini.y"
    {  
    (yyval.statement) = new LLScriptStatement(0);
	}
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 625 "lslmini.y"
    {  
    (yyval.statement) = new LLScriptCompoundStatement((yyvsp[(2) - (3)].statement));
	}
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 632 "lslmini.y"
    {  
    //DEBUG( LOG_DEBUG_SPAM, NULL, "statement %d\n", yylloc.first_line );
    (yyval.statement) = (yyvsp[(1) - (1)].statement);
	}
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 637 "lslmini.y"
    {  
    if ( (yyvsp[(1) - (2)].statement) ) {
        (yyvsp[(1) - (2)].statement)->add_next_sibling((yyvsp[(2) - (2)].statement));
        (yyval.statement) = (yyvsp[(1) - (2)].statement);
    } else {
        (yyval.statement) = (yyvsp[(2) - (2)].statement);
    }
	}
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 649 "lslmini.y"
    {  
    (yyval.statement) = new LLScriptStatement(0);
	}
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 653 "lslmini.y"
    {  
    (yyval.statement) = new LLScriptStateStatement(MAKEID(LST_NULL, (yyvsp[(2) - (3)].sval), (yylsp[(2) - (3)])));
	}
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 657 "lslmini.y"
    {  
    (yyval.statement) = new LLScriptStateStatement();
	}
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 661 "lslmini.y"
    {  
    (yyval.statement) = new LLScriptJumpStatement(MAKEID(LST_NULL, (yyvsp[(2) - (3)].sval), (yylsp[(2) - (3)])));
	}
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 665 "lslmini.y"
    {  
    (yyval.statement) = new LLScriptLabel(MAKEID(LST_NULL, (yyvsp[(2) - (3)].sval), (yylsp[(2) - (3)])));
	}
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 669 "lslmini.y"
    {  
    (yyval.statement) = new LLScriptReturnStatement((yyvsp[(2) - (3)].expression));
	}
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 673 "lslmini.y"
    {  
    (yyval.statement) = new LLScriptReturnStatement(NULL);
	}
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 677 "lslmini.y"
    {  
    (yyval.statement) = new LLScriptStatement((yyvsp[(1) - (2)].expression));
	}
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 681 "lslmini.y"
    {  
    (yyval.statement) = (yyvsp[(1) - (2)].statement);
	}
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 685 "lslmini.y"
    { 
    (yyval.statement) = (yyvsp[(1) - (1)].statement);
	}
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 689 "lslmini.y"
    {  
    (yyval.statement) = new LLScriptIfStatement((yyvsp[(3) - (5)].expression), (yyvsp[(5) - (5)].statement), NULL);
	}
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 693 "lslmini.y"
    {  
    (yyval.statement) = new LLScriptIfStatement((yyvsp[(3) - (7)].expression), (yyvsp[(5) - (7)].statement), (yyvsp[(7) - (7)].statement));
	}
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 697 "lslmini.y"
    {  
    (yyval.statement) = new LLScriptForStatement((yyvsp[(3) - (9)].expression), (yyvsp[(5) - (9)].expression), (yyvsp[(7) - (9)].expression), (yyvsp[(9) - (9)].statement));
	}
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 701 "lslmini.y"
    {  
    (yyval.statement) = new LLScriptDoStatement((yyvsp[(2) - (7)].statement), (yyvsp[(5) - (7)].expression));
	}
    break;

  case 81:
/* Line 1792 of yacc.c  */
#line 705 "lslmini.y"
    {  
    (yyval.statement) = new LLScriptWhileStatement((yyvsp[(3) - (5)].expression), (yyvsp[(5) - (5)].statement));
	}
    break;

  case 82:
/* Line 1792 of yacc.c  */
#line 709 "lslmini.y"
    {
    (yyval.statement) = new LLScriptStatement(0);
    }
    break;

  case 83:
/* Line 1792 of yacc.c  */
#line 716 "lslmini.y"
    {  
    (yyval.statement) = new LLScriptDeclaration(new LLScriptIdentifier((yyvsp[(1) - (2)].type), (yyvsp[(2) - (2)].sval), &(yylsp[(2) - (2)])), NULL);
	}
    break;

  case 84:
/* Line 1792 of yacc.c  */
#line 720 "lslmini.y"
    {  
    DEBUG( LOG_DEBUG_SPAM, NULL, "= %s\n", (yyvsp[(4) - (4)].expression)->get_node_name());
    (yyval.statement) = new LLScriptDeclaration(new LLScriptIdentifier((yyvsp[(1) - (4)].type), (yyvsp[(2) - (4)].sval), &(yylsp[(2) - (4)])), (yyvsp[(4) - (4)].expression));
	}
    break;

  case 85:
/* Line 1792 of yacc.c  */
#line 728 "lslmini.y"
    {  
    //$$ = new LLScriptExpression(0, NULL, NULL);
    (yyval.expression) = NULL;
	}
    break;

  case 86:
/* Line 1792 of yacc.c  */
#line 733 "lslmini.y"
    {
    (yyval.expression) = (yyvsp[(1) - (1)].expression);
	}
    break;

  case 87:
/* Line 1792 of yacc.c  */
#line 740 "lslmini.y"
    { 
    (yyval.expression) = (yyvsp[(1) - (1)].expression);
	}
    break;

  case 88:
/* Line 1792 of yacc.c  */
#line 744 "lslmini.y"
    {
    if ( (yyvsp[(1) - (3)].expression) ) {
        (yyvsp[(1) - (3)].expression)->add_next_sibling((yyvsp[(3) - (3)].expression));
        (yyval.expression) = (yyvsp[(1) - (3)].expression);
    } else {
        (yyval.expression) = (yyvsp[(3) - (3)].expression);
    }
	}
    break;

  case 89:
/* Line 1792 of yacc.c  */
#line 756 "lslmini.y"
    {  
    //$$ = new LLScriptExpression(0);
    (yyval.expression) = NULL;
	}
    break;

  case 90:
/* Line 1792 of yacc.c  */
#line 761 "lslmini.y"
    {
    (yyval.expression) = (yyvsp[(1) - (1)].expression);
	}
    break;

  case 91:
/* Line 1792 of yacc.c  */
#line 768 "lslmini.y"
    {  
    (yyval.expression) = (yyvsp[(1) - (1)].expression);
	}
    break;

  case 92:
/* Line 1792 of yacc.c  */
#line 772 "lslmini.y"
    {
    if ( (yyvsp[(1) - (3)].expression) ) {
        (yyvsp[(1) - (3)].expression)->add_next_sibling((yyvsp[(3) - (3)].expression));
        (yyval.expression) = (yyvsp[(1) - (3)].expression);
    } else {
        (yyval.expression) = (yyvsp[(3) - (3)].expression);
    }
	}
    break;

  case 93:
/* Line 1792 of yacc.c  */
#line 784 "lslmini.y"
    {  
    //$$ = new LLScriptExpression(0);
    //$$ = NULL;
    (yyval.expression) = NULL;
	}
    break;

  case 94:
/* Line 1792 of yacc.c  */
#line 790 "lslmini.y"
    {
    (yyval.expression) = (yyvsp[(1) - (1)].expression);
	}
    break;

  case 95:
/* Line 1792 of yacc.c  */
#line 797 "lslmini.y"
    {  
    (yyval.expression) = (yyvsp[(1) - (1)].expression);
	}
    break;

  case 96:
/* Line 1792 of yacc.c  */
#line 801 "lslmini.y"
    {
    if ((yyvsp[(1) - (3)].expression)) {
        (yyvsp[(1) - (3)].expression)->add_next_sibling((yyvsp[(3) - (3)].expression));
        (yyval.expression) = (yyvsp[(1) - (3)].expression);
    } else {
        (yyval.expression) = (yyvsp[(3) - (3)].expression);
    }
	}
    break;

  case 97:
/* Line 1792 of yacc.c  */
#line 813 "lslmini.y"
    {  
    (yyval.expression) = (yyvsp[(1) - (1)].expression);
	}
    break;

  case 98:
/* Line 1792 of yacc.c  */
#line 817 "lslmini.y"
    {  
    (yyval.expression) = new LLScriptExpression( (yyvsp[(1) - (3)].expression), '=', (yyvsp[(3) - (3)].expression) );
	}
    break;

  case 99:
/* Line 1792 of yacc.c  */
#line 821 "lslmini.y"
    {  
    // TODO: clean these up
    (yyval.expression) = new LLScriptExpression( (yyvsp[(1) - (3)].expression),'=', new LLScriptExpression(new LLScriptLValueExpression(new LLScriptIdentifier((LLScriptIdentifier*)(yyvsp[(1) - (3)].expression)->get_child(0))), '+', (yyvsp[(3) - (3)].expression)) );
	}
    break;

  case 100:
/* Line 1792 of yacc.c  */
#line 826 "lslmini.y"
    {  
    (yyval.expression) = new LLScriptExpression( (yyvsp[(1) - (3)].expression), '=', new LLScriptExpression(new LLScriptLValueExpression(new LLScriptIdentifier((LLScriptIdentifier*)(yyvsp[(1) - (3)].expression)->get_child(0))), '-', (yyvsp[(3) - (3)].expression)) );
	}
    break;

  case 101:
/* Line 1792 of yacc.c  */
#line 830 "lslmini.y"
    {  
    (yyval.expression) = new LLScriptExpression( (yyvsp[(1) - (3)].expression), '=', new LLScriptExpression(new LLScriptLValueExpression(new LLScriptIdentifier((LLScriptIdentifier*)(yyvsp[(1) - (3)].expression)->get_child(0))), '*', (yyvsp[(3) - (3)].expression)) );
	}
    break;

  case 102:
/* Line 1792 of yacc.c  */
#line 834 "lslmini.y"
    {  
    (yyval.expression) = new LLScriptExpression( (yyvsp[(1) - (3)].expression), '=', new LLScriptExpression(new LLScriptLValueExpression(new LLScriptIdentifier((LLScriptIdentifier*)(yyvsp[(1) - (3)].expression)->get_child(0))), '/', (yyvsp[(3) - (3)].expression)) );
	}
    break;

  case 103:
/* Line 1792 of yacc.c  */
#line 838 "lslmini.y"
    {  
    (yyval.expression) = new LLScriptExpression( (yyvsp[(1) - (3)].expression), '=', new LLScriptExpression(new LLScriptLValueExpression(new LLScriptIdentifier((LLScriptIdentifier*)(yyvsp[(1) - (3)].expression)->get_child(0))), '%', (yyvsp[(3) - (3)].expression)) );
	}
    break;

  case 104:
/* Line 1792 of yacc.c  */
#line 842 "lslmini.y"
    {  
    (yyval.expression) = new LLScriptExpression( (yyvsp[(1) - (3)].expression), EQ, (yyvsp[(3) - (3)].expression) );
	}
    break;

  case 105:
/* Line 1792 of yacc.c  */
#line 846 "lslmini.y"
    {  
    (yyval.expression) = new LLScriptExpression( new LLScriptExpression( (yyvsp[(1) - (3)].expression), EQ, (yyvsp[(3) - (3)].expression) ), '!' );
	}
    break;

  case 106:
/* Line 1792 of yacc.c  */
#line 850 "lslmini.y"
    {  
    // if ( A <= B ) B > A
    (yyval.expression) = new LLScriptExpression( (yyvsp[(3) - (3)].expression), '>', (yyvsp[(1) - (3)].expression) );
	}
    break;

  case 107:
/* Line 1792 of yacc.c  */
#line 855 "lslmini.y"
    {  
    // if ( A >= B ) B < A
    (yyval.expression) = new LLScriptExpression( (yyvsp[(3) - (3)].expression), '<', (yyvsp[(1) - (3)].expression) );
	}
    break;

  case 108:
/* Line 1792 of yacc.c  */
#line 860 "lslmini.y"
    {  
    (yyval.expression) = new LLScriptExpression( (yyvsp[(1) - (3)].expression), '<', (yyvsp[(3) - (3)].expression) );
	}
    break;

  case 109:
/* Line 1792 of yacc.c  */
#line 864 "lslmini.y"
    {  
    (yyval.expression) = new LLScriptExpression( (yyvsp[(1) - (3)].expression), '>', (yyvsp[(3) - (3)].expression) );
	}
    break;

  case 110:
/* Line 1792 of yacc.c  */
#line 868 "lslmini.y"
    {  
    (yyval.expression) = new LLScriptExpression( (yyvsp[(1) - (3)].expression), '+', (yyvsp[(3) - (3)].expression) );
	}
    break;

  case 111:
/* Line 1792 of yacc.c  */
#line 872 "lslmini.y"
    {  
    (yyval.expression) = new LLScriptExpression( (yyvsp[(1) - (3)].expression), '-', (yyvsp[(3) - (3)].expression) );
	}
    break;

  case 112:
/* Line 1792 of yacc.c  */
#line 876 "lslmini.y"
    {  
    (yyval.expression) = new LLScriptExpression( (yyvsp[(1) - (3)].expression), '*', (yyvsp[(3) - (3)].expression) );
	}
    break;

  case 113:
/* Line 1792 of yacc.c  */
#line 880 "lslmini.y"
    {  
    (yyval.expression) = new LLScriptExpression(  (yyvsp[(1) - (3)].expression), '/',  (yyvsp[(3) - (3)].expression)  );
	}
    break;

  case 114:
/* Line 1792 of yacc.c  */
#line 884 "lslmini.y"
    {  
    (yyval.expression) = new LLScriptExpression(  (yyvsp[(1) - (3)].expression), '%',  (yyvsp[(3) - (3)].expression)  );
	}
    break;

  case 115:
/* Line 1792 of yacc.c  */
#line 888 "lslmini.y"
    {  
    (yyval.expression) = new LLScriptExpression(  (yyvsp[(1) - (3)].expression), '&',  (yyvsp[(3) - (3)].expression)  );
	}
    break;

  case 116:
/* Line 1792 of yacc.c  */
#line 892 "lslmini.y"
    {  
    (yyval.expression) = new LLScriptExpression(  (yyvsp[(1) - (3)].expression), '|',  (yyvsp[(3) - (3)].expression)  );
	}
    break;

  case 117:
/* Line 1792 of yacc.c  */
#line 896 "lslmini.y"
    {  
    (yyval.expression) = new LLScriptExpression(  (yyvsp[(1) - (3)].expression), '^',  (yyvsp[(3) - (3)].expression)  );
	}
    break;

  case 118:
/* Line 1792 of yacc.c  */
#line 900 "lslmini.y"
    {  
    (yyval.expression) = new LLScriptExpression(  (yyvsp[(1) - (3)].expression), BOOLEAN_AND,  (yyvsp[(3) - (3)].expression)  );
	}
    break;

  case 119:
/* Line 1792 of yacc.c  */
#line 904 "lslmini.y"
    {  
    (yyval.expression) = new LLScriptExpression(  (yyvsp[(1) - (3)].expression), BOOLEAN_OR,  (yyvsp[(3) - (3)].expression)  );
	}
    break;

  case 120:
/* Line 1792 of yacc.c  */
#line 908 "lslmini.y"
    {
    (yyval.expression) = new LLScriptExpression(  (yyvsp[(1) - (3)].expression), SHIFT_LEFT,  (yyvsp[(3) - (3)].expression)  );
	}
    break;

  case 121:
/* Line 1792 of yacc.c  */
#line 912 "lslmini.y"
    {
    (yyval.expression) = new LLScriptExpression(  (yyvsp[(1) - (3)].expression), SHIFT_RIGHT,  (yyvsp[(3) - (3)].expression)  );
	}
    break;

  case 122:
/* Line 1792 of yacc.c  */
#line 916 "lslmini.y"
    {
    ERROR( &(yylsp[(2) - (2)]), E_NO_OPERATOR );
    if ( (yyvsp[(2) - (2)].ival) < 0 ) { // if const is negative, assume they meant expr - const
        // - is included as part of the constant, so make sure to reverse it
        (yyval.expression) = new LLScriptExpression( (yyvsp[(1) - (2)].expression), '-', new LLScriptExpression( 1, new LLScriptIntegerConstant( - (yyvsp[(2) - (2)].ival)) ) );
    } else {
        (yyval.expression) = NULL;
    }
    }
    break;

  case 123:
/* Line 1792 of yacc.c  */
#line 926 "lslmini.y"
    {
    ERROR( &(yylsp[(2) - (2)]), E_NO_OPERATOR );
    if ( (yyvsp[(2) - (2)].fval) < 0 ) {
        (yyval.expression) = new LLScriptExpression( (yyvsp[(1) - (2)].expression), '-', new LLScriptExpression( 1, new LLScriptFloatConstant( - (yyvsp[(2) - (2)].fval)) ) );
    } else {
        (yyval.expression) = NULL;
    }
    }
    break;

  case 124:
/* Line 1792 of yacc.c  */
#line 938 "lslmini.y"
    {  
    (yyval.expression) = new LLScriptExpression( (yyvsp[(2) - (2)].expression), '-' );
	}
    break;

  case 125:
/* Line 1792 of yacc.c  */
#line 942 "lslmini.y"
    {  
    (yyval.expression) = new LLScriptExpression(  (yyvsp[(2) - (2)].expression) , '!' );
	}
    break;

  case 126:
/* Line 1792 of yacc.c  */
#line 946 "lslmini.y"
    {  
    (yyval.expression) = new LLScriptExpression(  (yyvsp[(2) - (2)].expression) , '~' );
	}
    break;

  case 127:
/* Line 1792 of yacc.c  */
#line 950 "lslmini.y"
    {  
    (yyval.expression) = new LLScriptExpression(  (yyvsp[(2) - (2)].expression) , INC_OP );
	}
    break;

  case 128:
/* Line 1792 of yacc.c  */
#line 954 "lslmini.y"
    {  
    (yyval.expression) = new LLScriptExpression(  (yyvsp[(2) - (2)].expression) , DEC_OP );
	}
    break;

  case 129:
/* Line 1792 of yacc.c  */
#line 958 "lslmini.y"
    {
    (yyval.expression) = (yyvsp[(1) - (1)].expression);
	}
    break;

  case 130:
/* Line 1792 of yacc.c  */
#line 962 "lslmini.y"
    {  
    (yyval.expression) = (yyvsp[(1) - (1)].expression);
	}
    break;

  case 131:
/* Line 1792 of yacc.c  */
#line 966 "lslmini.y"
    {  
    (yyval.expression) = new LLScriptExpression((yyvsp[(2) - (3)].expression), 0);
	}
    break;

  case 132:
/* Line 1792 of yacc.c  */
#line 973 "lslmini.y"
    {
    (yyval.expression) = new LLScriptTypecastExpression((yyvsp[(2) - (4)].type), (yyvsp[(4) - (4)].expression));
	}
    break;

  case 133:
/* Line 1792 of yacc.c  */
#line 977 "lslmini.y"
    {
    (yyval.expression) = new LLScriptTypecastExpression((yyvsp[(2) - (4)].type), (yyvsp[(4) - (4)].constant));
	}
    break;

  case 134:
/* Line 1792 of yacc.c  */
#line 981 "lslmini.y"
    {
    (yyval.expression) = new LLScriptTypecastExpression((yyvsp[(2) - (4)].type), (yyvsp[(4) - (4)].expression));
	}
    break;

  case 135:
/* Line 1792 of yacc.c  */
#line 985 "lslmini.y"
    {
    (yyval.expression) = new LLScriptTypecastExpression((yyvsp[(2) - (6)].type), (yyvsp[(5) - (6)].expression));
	}
    break;

  case 136:
/* Line 1792 of yacc.c  */
#line 992 "lslmini.y"
    {  
    DEBUG( LOG_DEBUG_SPAM, NULL, "vector intializer..");
    (yyval.expression) = (yyvsp[(1) - (1)].expression);
	}
    break;

  case 137:
/* Line 1792 of yacc.c  */
#line 997 "lslmini.y"
    {
    (yyval.expression) = (yyvsp[(1) - (1)].expression);
	}
    break;

  case 138:
/* Line 1792 of yacc.c  */
#line 1001 "lslmini.y"
    {  
    (yyval.expression) = (yyvsp[(1) - (1)].expression);
	}
    break;

  case 139:
/* Line 1792 of yacc.c  */
#line 1005 "lslmini.y"
    {  
    (yyval.expression) = (yyvsp[(1) - (1)].expression);
	}
    break;

  case 140:
/* Line 1792 of yacc.c  */
#line 1009 "lslmini.y"
    {  
    (yyval.expression) = new LLScriptExpression(  (yyvsp[(1) - (2)].expression) , INC_OP );
	}
    break;

  case 141:
/* Line 1792 of yacc.c  */
#line 1013 "lslmini.y"
    {  
    (yyval.expression) = new LLScriptExpression(  (yyvsp[(1) - (2)].expression) , DEC_OP );
	}
    break;

  case 142:
/* Line 1792 of yacc.c  */
#line 1017 "lslmini.y"
    {  
    if ( (yyvsp[(3) - (4)].expression) != NULL ) {
      (yyval.expression) = new LLScriptFunctionExpression( new LLScriptIdentifier((yyvsp[(1) - (4)].sval)), (yyvsp[(3) - (4)].expression) );
    } else {
      (yyval.expression) = new LLScriptFunctionExpression( new LLScriptIdentifier((yyvsp[(1) - (4)].sval)) );
    }

	}
    break;

  case 143:
/* Line 1792 of yacc.c  */
#line 1026 "lslmini.y"
    {  
    /* FIXME: What does this do? */
	}
    break;

  case 144:
/* Line 1792 of yacc.c  */
#line 1030 "lslmini.y"
    {  
    (yyval.expression) = new LLScriptExpression((yyvsp[(1) - (1)].constant));
	}
    break;

  case 145:
/* Line 1792 of yacc.c  */
#line 1037 "lslmini.y"
    {
    (yyval.expression) = new LLScriptVectorExpression((yyvsp[(2) - (7)].expression), (yyvsp[(4) - (7)].expression), (yyvsp[(6) - (7)].expression));
	}
    break;

  case 146:
/* Line 1792 of yacc.c  */
#line 1041 "lslmini.y"
    {
    (yyval.expression) = new LLScriptVectorExpression();
	}
    break;

  case 147:
/* Line 1792 of yacc.c  */
#line 1048 "lslmini.y"
    {
    (yyval.expression) = new LLScriptQuaternionExpression((yyvsp[(2) - (9)].expression), (yyvsp[(4) - (9)].expression), (yyvsp[(6) - (9)].expression), (yyvsp[(8) - (9)].expression));
	}
    break;

  case 148:
/* Line 1792 of yacc.c  */
#line 1052 "lslmini.y"
    {
    (yyval.expression) = new LLScriptQuaternionExpression();
	}
    break;

  case 149:
/* Line 1792 of yacc.c  */
#line 1059 "lslmini.y"
    {  
    (yyval.expression) = new LLScriptListExpression((yyvsp[(2) - (3)].expression));
	}
    break;

  case 150:
/* Line 1792 of yacc.c  */
#line 1066 "lslmini.y"
    {  
    (yyval.expression) = new LLScriptLValueExpression(new LLScriptIdentifier((yyvsp[(1) - (1)].sval)));
	}
    break;

  case 151:
/* Line 1792 of yacc.c  */
#line 1070 "lslmini.y"
    {
    (yyval.expression) = new LLScriptLValueExpression(new LLScriptIdentifier((yyvsp[(1) - (3)].sval), (yyvsp[(3) - (3)].sval)));
	}
    break;


/* Line 1792 of yacc.c  */
#line 3478 "lslmini.tab.c"
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
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (&yylloc, scanner, YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (&yylloc, scanner, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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
		      yytoken, &yylval, &yylloc, scanner);
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

  yyerror_range[1] = yylsp[1-yylen];
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
      if (!yypact_value_is_default (yyn))
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp, scanner);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (&yylloc, scanner, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc, scanner);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp, scanner);
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


/* Line 2055 of yacc.c  */
#line 1075 "lslmini.y"


int yyerror( YYLTYPE *lloc, void *scanner, const char *message ) {
    ERROR( lloc, E_SYNTAX_ERROR, message );
    return 0;
}

