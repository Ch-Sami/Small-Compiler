
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
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "synt.y"

  //bibliothèques
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <stdbool.h>
  //définitions des variables
  typedef struct Entite{
      char nom[20];
      char code[10];
      char type[20];
      int taille;
      char estConstante[10];
      char valeur[100];
      struct Entite *suivant;
  }Entite;

  int nbr_ligne = 1;
  int bib_io_included = 0;
  int bib_lang_included = 0;
  int bib_io_manquante_detecte = 0;
  int bib_lang_manquante_detecte = 0;
  char sauvType[20];
  char var_idf_sauv[20];
  bool idf_var_prblm = false;
  bool exp_erreur = false;

  float arithmetic_expression_result = 0;
  typedef struct Arithmetic_expression{
    float valeur;
    char mot[20];
    char type[20];
    int numPar;
    int priorite;
    struct Arithmetic_expression *suivant;
  }arithmetic_expression;

  typedef struct Var_idf_list{
    char idf[30];
    struct Var_idf_list *suivant;
  }Var_idf_list;

  typedef struct Non_declare_list{
    char idf[30];
    int nbr_ligne;
    struct Non_declare_list *suivant;
  }Non_declare_list;

  typedef struct Signes_formatage{
    char signe[3];
    struct Signes_formatage *suivant;
  }Signes_formatage;

  typedef struct Liste_elements{
    char element[255];
    char type[30];
    struct Liste_elements *suivant;
  }Liste_elements;

  //prototypes des fonctions
  Entite* recherche(char nom[]);
  void inserer(char nom[], char code[]);
  void insererType(char nom[], char type[]);
  bool estDeclare(char nom[]);
  void afficher();
  void constante(char nom[]);
  bool estConstante(char nom[]);
  void definirTailleTableau(char nom[], int taille);
  int getTailleTableau(char nom[]);
  bool estDepasseTaille(char nom[], int i);
  void ajouter_operand_expression_arithmetique(char idf[], float valeur);
  void ajouter_parenthese_expression_arithmetique(char par[]);
  void ajouter_operation_expression_arithmetique(char operation[]);
  bool estNombre(char nom[]);
  char* getValue(char nom[]);
  char* getType(char nom[]);
  void reinitialiser_var_idf_list_head();
  void inserer_var_idf(char idf[]);
  void afficherIDFs(); // used just for tests
  Var_idf_list * get_var_idf_list_head();
  void inserer_non_declare(char idf[], int nbr_ligne);
  bool non_declare_deja_detecte(char idf[], int nbr_ligne);
  void afficher_non_declare_list(); // used just for tests
  void creerCellules(char nomTab[], int taille);
  float calculer_expression_arithmetique(int nbr_ligne);
  void affecter(char nom[], char valeur[]);
  void initialiser_expression_arithmetique();
  void afficherAX(); // used just for tests
  void afficherSignes(); // used just for tests
  void reinitialiser_signes_formatage_head();
  void inserer_signe_formatage(char signe[]);
  Signes_formatage * get_signes_formatage_head();
  int var_idf_list_length();
  int signes_formatage_length();
  int liste_elements_length();
  void reinitialiser_liste_elements_head();
  void inserer_element(char element[], char type[]);
  Liste_elements * get_liste_elements_head();
  void afficher_liste_elements(); // used just for tests

  int yylex();
  void yyerror(const char *s);


/* Line 189 of yacc.c  */
#line 178 "synt.tab.c"

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
     mc_import = 258,
     bib_io = 259,
     bib_lang = 260,
     pvg = 261,
     err = 262,
     idf = 263,
     mc_private = 264,
     mc_public = 265,
     mc_protected = 266,
     mc_class = 267,
     aco_ov = 268,
     aco_fr = 269,
     mc_entier = 270,
     mc_reel = 271,
     mc_chaine = 272,
     nom_tableau = 273,
     taille_tab = 274,
     mc_const = 275,
     cr_ov = 276,
     cr_fr = 277,
     cst = 278,
     vrg = 279,
     mc_main = 280,
     pr_ov = 281,
     pr_fr = 282,
     aff = 283,
     add = 284,
     sus = 285,
     mult = 286,
     dv = 287,
     entier = 288,
     reel = 289,
     chaine = 290,
     mc_for = 291,
     equals = 292,
     not_equals = 293,
     inf = 294,
     inf_or_equals = 295,
     sup = 296,
     sup_or_equals = 297,
     mc_in = 298,
     mc_out = 299,
     quotation_mark = 300
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 104 "synt.y"

	int entier;
  float reel;
	char* chaine;



/* Line 214 of yacc.c  */
#line 267 "synt.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 279 "synt.tab.c"

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
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   202

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  49
/* YYNRULES -- Number of rules.  */
#define YYNRULES  98
/* YYNRULES -- Number of states.  */
#define YYNSTATES  195

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

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
      45
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     9,    12,    13,    17,    19,    21,    25,
      27,    29,    31,    39,    42,    43,    45,    47,    49,    53,
      54,    61,    67,    68,    73,    75,    79,    80,    89,    93,
      95,    97,    99,   101,   103,   104,   112,   117,   122,   123,
     131,   138,   142,   144,   146,   148,   150,   153,   154,   156,
     158,   160,   162,   163,   169,   174,   179,   184,   185,   195,
     197,   202,   205,   208,   209,   214,   217,   218,   220,   225,
     227,   229,   231,   233,   235,   237,   239,   244,   253,   254,
     259,   260,   266,   270,   272,   274,   276,   278,   280,   282,
     286,   290,   291,   296,   304,   311,   312,   317,   319
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      47,     0,    -1,    48,    51,    13,    53,    14,    -1,    49,
      48,    -1,    -1,     3,    50,     6,    -1,     4,    -1,     5,
      -1,    52,    12,     8,    -1,     9,    -1,    10,    -1,    11,
      -1,    54,    25,    26,    27,    13,    70,    14,    -1,    55,
      54,    -1,    -1,    56,    -1,    60,    -1,    66,    -1,    69,
      58,     6,    -1,    -1,    69,    58,    28,    57,    76,     6,
      -1,    69,    58,    28,    35,     6,    -1,    -1,     8,    59,
      24,    58,    -1,     8,    -1,    69,    64,     6,    -1,    -1,
      69,    64,    28,    61,    21,    62,    22,     6,    -1,    63,
      24,    62,    -1,    63,    -1,    23,    -1,    33,    -1,    34,
      -1,    35,    -1,    -1,    18,    21,    23,    22,    65,    24,
      64,    -1,    18,    21,    23,    22,    -1,    20,    69,    68,
       6,    -1,    -1,    20,    69,    68,    28,    67,    76,     6,
      -1,    20,    69,    68,    28,    35,     6,    -1,     8,    24,
      68,    -1,     8,    -1,    15,    -1,    16,    -1,    17,    -1,
      71,    70,    -1,    -1,    72,    -1,    82,    -1,    91,    -1,
      92,    -1,    -1,    75,    28,    73,    76,     6,    -1,    75,
      28,    35,     6,    -1,    75,    29,    29,     6,    -1,    75,
      30,    30,     6,    -1,    -1,    18,    21,    22,    28,    74,
      21,    62,    22,     6,    -1,     8,    -1,    18,    21,    23,
      22,    -1,    77,    79,    -1,    80,    79,    -1,    -1,    26,
      78,    76,    27,    -1,    81,    76,    -1,    -1,     8,    -1,
      18,    21,    23,    22,    -1,    23,    -1,    33,    -1,    34,
      -1,    29,    -1,    30,    -1,    31,    -1,    32,    -1,    83,
      13,    70,    14,    -1,    36,    26,    84,     6,    87,     6,
      89,    27,    -1,    -1,    75,    28,    85,    76,    -1,    -1,
      69,     8,    28,    86,    76,    -1,    76,    88,    76,    -1,
      37,    -1,    38,    -1,    39,    -1,    40,    -1,    41,    -1,
      42,    -1,    75,    29,    29,    -1,    75,    30,    30,    -1,
      -1,    75,    28,    90,    76,    -1,    43,    26,    35,    24,
      75,    27,     6,    -1,    44,    26,    35,    93,    27,     6,
      -1,    -1,    24,    75,    94,    93,    -1,    75,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   117,   117,   119,   120,   122,   124,   131,   139,   141,
     142,   143,   145,   147,   148,   150,   151,   152,   155,   156,
     156,   200,   222,   222,   234,   246,   247,   247,   296,   297,
     300,   305,   310,   315,   320,   320,   335,   351,   352,   352,
     393,   416,   429,   443,   444,   445,   447,   448,   450,   451,
     452,   460,   469,   469,   509,   526,   552,   578,   578,   623,
     638,   664,   665,   667,   667,   673,   674,   676,   696,   729,
     734,   739,   745,   748,   751,   754,   758,   760,   762,   762,
     800,   800,   850,   852,   853,   854,   855,   856,   857,   859,
     866,   873,   873,   912,   952,  1000,  1000,  1001,  1002
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "mc_import", "bib_io", "bib_lang", "pvg",
  "err", "idf", "mc_private", "mc_public", "mc_protected", "mc_class",
  "aco_ov", "aco_fr", "mc_entier", "mc_reel", "mc_chaine", "nom_tableau",
  "taille_tab", "mc_const", "cr_ov", "cr_fr", "cst", "vrg", "mc_main",
  "pr_ov", "pr_fr", "aff", "add", "sus", "mult", "dv", "entier", "reel",
  "chaine", "mc_for", "equals", "not_equals", "inf", "inf_or_equals",
  "sup", "sup_or_equals", "mc_in", "mc_out", "quotation_mark", "$accept",
  "S", "bib_importation_liste", "bib_importation", "nom_bib",
  "class_header_syntax", "access_modifier", "corps",
  "variable_declaration_liste", "variable_declaration",
  "simple_variable_declaration", "$@1", "liste_idf_variable_simple", "$@2",
  "table_declaration", "$@3", "liste_elements", "element",
  "liste_idf_tab_dec", "$@4", "const_declaration", "$@5",
  "liste_idf_const", "variable_type", "liste_instruction", "instruction",
  "affectation", "$@6", "$@7", "variable_idf", "arithmetic_expression",
  "entre_parentheses", "$@8", "arithmetic_expression_rest", "operand",
  "operation", "loop", "loop_header", "loop_initialisation", "$@9", "$@10",
  "loop_condition", "comparaison", "loop_incrementation", "$@11",
  "lecture", "ecriture", "liste_sorties", "$@12", 0
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
     295,   296,   297,   298,   299,   300
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    50,    50,    51,    52,
      52,    52,    53,    54,    54,    55,    55,    55,    56,    57,
      56,    56,    59,    58,    58,    60,    61,    60,    62,    62,
      63,    63,    63,    63,    65,    64,    64,    66,    67,    66,
      66,    68,    68,    69,    69,    69,    70,    70,    71,    71,
      71,    71,    73,    72,    72,    72,    72,    74,    72,    75,
      75,    76,    76,    78,    77,    79,    79,    80,    80,    80,
      80,    80,    81,    81,    81,    81,    82,    83,    85,    84,
      86,    84,    87,    88,    88,    88,    88,    88,    88,    89,
      89,    90,    89,    91,    92,    94,    93,    93,    93
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     2,     0,     3,     1,     1,     3,     1,
       1,     1,     7,     2,     0,     1,     1,     1,     3,     0,
       6,     5,     0,     4,     1,     3,     0,     8,     3,     1,
       1,     1,     1,     1,     0,     7,     4,     4,     0,     7,
       6,     3,     1,     1,     1,     1,     2,     0,     1,     1,
       1,     1,     0,     5,     4,     4,     4,     0,     9,     1,
       4,     2,     2,     0,     4,     2,     0,     1,     4,     1,
       1,     1,     1,     1,     1,     1,     4,     8,     0,     4,
       0,     5,     3,     1,     1,     1,     1,     1,     1,     3,
       3,     0,     4,     7,     6,     0,     4,     1,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     0,     4,     6,     7,     0,     1,     9,
      10,    11,     0,     0,     3,     5,    14,     0,    43,    44,
      45,     0,     0,     0,    14,    15,    16,    17,     0,     8,
       0,     2,     0,    13,    24,     0,     0,     0,    42,     0,
       0,     0,     0,    18,    19,    25,    26,     0,    37,    38,
       0,     0,     0,     0,     0,     0,    41,     0,     0,    47,
      23,    36,    21,    67,     0,    69,    63,    70,    71,     0,
      66,    66,     0,    40,     0,    59,     0,     0,     0,     0,
       0,    47,    48,     0,    49,     0,    50,    51,     0,     0,
       0,    20,    72,    73,    74,    75,    61,     0,    62,    30,
      31,    32,    33,     0,    29,    39,     0,     0,     0,     0,
      12,    46,    52,     0,     0,    47,     0,     0,     0,    65,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    98,
       0,     0,     0,     0,     0,    35,    68,    64,    27,    28,
      57,    60,     0,     0,    78,     0,     0,     0,    97,     0,
      54,     0,    55,    56,    76,     0,    80,     0,     0,     0,
       0,    95,     0,    53,     0,     0,    79,    83,    84,    85,
      86,    87,    88,     0,     0,     0,    98,    94,     0,    81,
      82,     0,     0,    93,    96,     0,    91,     0,     0,    77,
      58,     0,    89,    90,    92
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,     7,    12,    13,    22,    23,    24,
      25,    54,    36,    41,    26,    55,   103,   104,    37,    88,
      27,    58,    39,    28,    80,    81,    82,   131,   155,    83,
      69,    70,    90,    96,    71,    97,    84,    85,   127,   157,
     165,   159,   173,   182,   191,    86,    87,   149,   176
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -119
static const yytype_int16 yypact[] =
{
       7,     9,    16,    69,     7,  -119,  -119,    12,  -119,  -119,
    -119,  -119,    11,     8,  -119,  -119,    32,    14,  -119,  -119,
    -119,    66,    13,    20,    32,  -119,  -119,  -119,    -3,  -119,
      23,  -119,    27,  -119,    68,    48,     0,     2,    70,     6,
      71,    72,    10,  -119,    58,  -119,  -119,    23,  -119,    60,
      84,    92,    79,    96,     3,    82,  -119,    98,     3,    -1,
    -119,    81,  -119,  -119,    85,  -119,  -119,  -119,  -119,   102,
      45,    45,    21,  -119,   103,  -119,    89,    86,    87,    88,
      97,    -1,  -119,    56,  -119,   104,  -119,  -119,    94,    93,
       3,  -119,  -119,  -119,  -119,  -119,  -119,     3,  -119,  -119,
    -119,  -119,  -119,    99,    95,  -119,    49,    42,    90,    91,
    -119,  -119,   100,   101,   106,    -1,   105,   107,   110,  -119,
     114,    21,   111,   109,   113,   116,   112,   121,   108,     1,
     122,     3,   132,   135,   128,  -119,  -119,  -119,  -119,  -119,
    -119,  -119,   120,   117,  -119,     3,    43,    43,  -119,   119,
    -119,   138,  -119,  -119,  -119,   126,  -119,     3,    25,   142,
     123,  -119,   143,  -119,    21,     3,  -119,  -119,  -119,  -119,
    -119,  -119,  -119,     3,    43,   145,     1,  -119,   130,  -119,
    -119,    61,   127,  -119,  -119,   147,  -119,   129,   125,  -119,
    -119,     3,  -119,  -119,  -119
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -119,  -119,   118,  -119,  -119,  -119,  -119,  -119,   133,  -119,
    -119,  -119,   115,  -119,  -119,  -119,  -118,  -119,    40,  -119,
    -119,  -119,   124,   -19,   -77,  -119,  -119,  -119,  -119,  -106,
     -58,  -119,  -119,   131,  -119,  -119,  -119,  -119,  -119,  -119,
    -119,  -119,  -119,  -119,  -119,  -119,  -119,   -17,  -119
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -35
static const yytype_int16 yytable[] =
{
      74,   126,    30,   139,   111,    34,    43,    75,    45,    75,
       1,    63,    48,     5,     6,    35,     8,    76,    15,   124,
      17,    64,    29,   148,    16,   147,    65,    31,    44,    66,
      46,    38,   118,    52,    49,    77,    67,    68,   134,   119,
     160,   161,    78,    79,    99,    32,   178,    18,    19,    20,
      75,    75,    21,    40,   100,   101,   102,    18,    19,    20,
     124,   124,   167,   168,   169,   170,   171,   172,   181,    42,
     148,   122,   123,   151,    92,    93,    94,    95,     9,    10,
      11,    18,    19,    20,   112,   113,   114,   158,   125,   186,
     187,   188,   -22,    53,    47,    57,    51,    59,    50,   166,
      34,    61,    62,    72,    73,   -34,    89,   179,    91,   105,
     106,   110,   107,   108,   109,   180,   117,   115,   116,   121,
     138,   120,    14,    35,   143,   128,   129,   145,   150,   136,
     132,   141,   146,   194,   142,   130,   133,   137,   152,   140,
     144,   153,   154,   123,   163,   156,   162,   164,   174,   177,
     175,   183,   185,   190,   189,   193,   135,    33,   192,   184,
       0,     0,     0,     0,     0,     0,    60,     0,     0,     0,
       0,    56,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    98
};

static const yytype_int16 yycheck[] =
{
      58,   107,    21,   121,    81,     8,     6,     8,     6,     8,
       3,     8,     6,     4,     5,    18,     0,    18,     6,    18,
      12,    18,     8,   129,    13,    24,    23,    14,    28,    26,
      28,     8,    90,    23,    28,    36,    33,    34,   115,    97,
     146,   147,    43,    44,    23,    25,   164,    15,    16,    17,
       8,     8,    20,    26,    33,    34,    35,    15,    16,    17,
      18,    18,    37,    38,    39,    40,    41,    42,   174,    21,
     176,    22,    23,   131,    29,    30,    31,    32,     9,    10,
      11,    15,    16,    17,    28,    29,    30,   145,   107,    28,
      29,    30,    24,    35,    24,    35,    24,    13,    27,   157,
       8,    22,     6,    21,     6,    24,    21,   165,     6,     6,
      21,    14,    26,    26,    26,   173,    23,    13,    24,    24,
       6,    22,     4,    18,     8,    35,    35,     6,     6,    22,
      29,    22,    24,   191,    21,    35,    30,    27,     6,    28,
      28,     6,    14,    23,     6,    28,    27,    21,     6,     6,
      27,     6,    22,     6,    27,    30,   116,    24,    29,   176,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,
      -1,    47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    71
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    47,    48,    49,     4,     5,    50,     0,     9,
      10,    11,    51,    52,    48,     6,    13,    12,    15,    16,
      17,    20,    53,    54,    55,    56,    60,    66,    69,     8,
      69,    14,    25,    54,     8,    18,    58,    64,     8,    68,
      26,    59,    21,     6,    28,     6,    28,    24,     6,    28,
      27,    24,    23,    35,    57,    61,    68,    35,    67,    13,
      58,    22,     6,     8,    18,    23,    26,    33,    34,    76,
      77,    80,    21,     6,    76,     8,    18,    36,    43,    44,
      70,    71,    72,    75,    82,    83,    91,    92,    65,    21,
      78,     6,    29,    30,    31,    32,    79,    81,    79,    23,
      33,    34,    35,    62,    63,     6,    21,    26,    26,    26,
      14,    70,    28,    29,    30,    13,    24,    23,    76,    76,
      22,    24,    22,    23,    18,    69,    75,    84,    35,    35,
      35,    73,    29,    30,    70,    64,    22,    27,     6,    62,
      28,    22,    21,     8,    28,     6,    24,    24,    75,    93,
       6,    76,     6,     6,    14,    74,    28,    85,    76,    87,
      75,    75,    27,     6,    21,    86,    76,    37,    38,    39,
      40,    41,    42,    88,     6,    27,    94,     6,    62,    76,
      76,    75,    89,     6,    93,    22,    28,    29,    30,    27,
       6,    90,    29,    30,    76
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
		  Type, Value); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
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
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
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
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

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
YYSTYPE yylval;

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

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
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

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

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
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 117 "synt.y"
    {printf("syntaxe correct");;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 124 "synt.y"
    {
                  if(bib_io_included == 1){
                    printf("erreur semantique a la ligne %d : double inclusion de la bibliotheque ISIL.io.\n", nbr_ligne);
                  }else{
                    bib_io_included = 1;
                  }
                ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 131 "synt.y"
    {
                   if(bib_lang_included == 1){
                    printf("erreur semantique a la ligne %d : double inclusion de la bibliotheque ISIL.lang.\n", nbr_ligne);
                  }else{
                    bib_lang_included = 1;
                  }
                 ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 150 "synt.y"
    {reinitialiser_var_idf_list_head();;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 151 "synt.y"
    {reinitialiser_var_idf_list_head();  reinitialiser_liste_elements_head();;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 152 "synt.y"
    {reinitialiser_var_idf_list_head();;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 156 "synt.y"
    {
                              //verifier si bib.lang inclue
                              if(bib_lang_included == 0 && bib_lang_manquante_detecte == 0){
                                printf("erreur semantique : la bibliotheque ISIL.lang est manquante.\n");
                                bib_lang_manquante_detecte = 1;
                              }
                               //initialiser l'expression arithmetique
                               initialiser_expression_arithmetique();
                               exp_erreur = false;
                              ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 165 "synt.y"
    {
                                if(!exp_erreur && !bib_lang_manquante_detecte){
                                  //calculer le resultat de l'expression arithmetique
                                  float resultat = calculer_expression_arithmetique(nbr_ligne);
                                  // printf("RESULT :  %f \n", resultat);

                                  char result_string[100];
                                  sprintf(result_string, "%f", resultat);
                                  //verifier la compatibilite des types
                                  char resultat_type[10];
                                  int partie_entiere = (int)resultat;
                                  float partie_decimal = resultat - partie_entiere;
                                  if(partie_decimal == 0){
                                    strcpy(resultat_type, "entier");
                                    strcpy(result_string, strtok(result_string, "."));
                                  }else{
                                    strcpy(resultat_type, "reel");
                                  }
                                  Var_idf_list * courant = get_var_idf_list_head();
                                  while(courant != NULL){
                                      if(strcmp(getType(courant->idf), "chaine") == 0){
                                        printf("erreur semantique a la ligne %d : incompatibilite de type, %s est de type chaine mais %s est de type %s.\n", nbr_ligne, courant->idf, result_string, resultat_type);
                                      }else if(strcmp(getType(courant->idf), "entier") == 0 && strcmp(resultat_type, "reel") == 0){
                                        printf("erreur semantique a la ligne %d : incompatibilite de type, %s est de type entier mais %s est un reel.\n", nbr_ligne, courant->idf, result_string);
                                      }else{
                                        //affecter
                                        affecter(courant->idf, result_string);
                                      }
                                      courant = courant->suivant;
                                  }

                                  //affichage exp arithmetique
                                  // afficherAX();
                                }
                              ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 200 "synt.y"
    {
                                //verifier si bib.lang inclue
                                if(bib_lang_included == 0 && bib_lang_manquante_detecte == 0){
                                  printf("erreur semantique : la bibliotheque ISIL.lang est manquante.\n");
                                  bib_lang_manquante_detecte = 1;
                                }
                                if(!bib_lang_manquante_detecte){
                                  Var_idf_list * courant = get_var_idf_list_head();
                                  while(courant != NULL){
                                    char type[30];
                                    strcpy(type, getType(courant->idf));
                                    if(strcmp(type, "chaine") != 0){
                                        printf("erreur semantique a la ligne %d : incompatibilite de type, %s est de type %s mais %s est une chaine.\n", nbr_ligne, courant->idf, type, (yyvsp[(4) - (5)].chaine));
                                      }else{
                                        //affecter
                                        affecter(courant->idf, (yyvsp[(4) - (5)].chaine));
                                      }
                                      courant = courant->suivant;
                                  }
                                }
                              ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 222 "synt.y"
    {
                               // verifier si double declaration
                               if(estDeclare((yyvsp[(1) - (1)].chaine))){
                                 printf("erreur semantique a la ligne %d : double declaration de la variable %s.\n", nbr_ligne, (yyvsp[(1) - (1)].chaine));
                               }else{
                                 //inserer le type
                                 insererType((yyvsp[(1) - (1)].chaine), sauvType);
                                 //sauv idf
                                 inserer_var_idf((yyvsp[(1) - (1)].chaine));
                                 
                               }
                            ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 234 "synt.y"
    {
                               // verifier si double declaration
                               if(estDeclare((yyvsp[(1) - (1)].chaine))){
                                 printf("erreur semantique a la ligne %d : double declaration de la variable %s.\n", nbr_ligne, (yyvsp[(1) - (1)].chaine));
                               }else{
                                 //inserer le type
                                 insererType((yyvsp[(1) - (1)].chaine), sauvType);
                                 //sauv idf
                                 inserer_var_idf((yyvsp[(1) - (1)].chaine));
                               }
                            ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 247 "synt.y"
    {
                        //verifier si bib.lang inclue
                        if(bib_lang_included == 0 && bib_lang_manquante_detecte == 0){
                          printf("erreur semantique : la bibliotheque ISIL.lang est manquante.\n");
                          bib_lang_manquante_detecte = 1;
                        }
                      ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 253 "synt.y"
    {
                        if(!bib_lang_manquante_detecte){
                          Var_idf_list * courant = get_var_idf_list_head();
                          while(courant != NULL){
                            //verification de taille
                            if(getTailleTableau(courant->idf) < liste_elements_length()){
                              printf("erreur semantique a la ligne %d : depassement de la taille du tableau %s.\n", nbr_ligne, courant->idf);
                            }else{
                              //verification des types
                              bool estCompatible = true;
                              Liste_elements *elt_courant = get_liste_elements_head();
                              while(elt_courant != NULL){
                                if(strcmp(elt_courant->type, getType(courant->idf)) != 0){
                                  printf("erreur semantique a la ligne %d : incompatibilite de type, le tableau %s est de type %s mais l'element %s est de type %s.\n", nbr_ligne, courant->idf, getType(courant->idf), elt_courant->element, elt_courant->type);
                                  estCompatible = false;
                                }
                                elt_courant = elt_courant->suivant;
                              }
                              if(estCompatible){
                                //remplissement des cellules
                                int i = 0;
                                char str[10];
                                elt_courant = get_liste_elements_head();
                                while(elt_courant != NULL){
                                char cellule[30];
                                strcpy(cellule, courant->idf);
                                strcat(cellule, "[");
                                sprintf(str, "%d", i);
                                strcat(cellule, str);
                                strcat(cellule, "]");
                                affecter(cellule, elt_courant->element);
                                i++;
                                elt_courant = elt_courant->suivant;
                              }
                              }
                            }
                            courant = courant->suivant;
                          }
                        }
                      ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 300 "synt.y"
    {
                  char element[255];
                  sprintf(element, "%d", (yyvsp[(1) - (1)].entier));
                  inserer_element(element, "entier");
                ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 305 "synt.y"
    {
                  char element[255];
                  sprintf(element, "%d", (yyvsp[(1) - (1)].entier));
                  inserer_element(element, "entier");
                ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 310 "synt.y"
    {
                char element[255];
                sprintf(element, "%f", (yyvsp[(1) - (1)].reel));
                inserer_element(element, "reel");
              ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 315 "synt.y"
    {
                  inserer_element((yyvsp[(1) - (1)].chaine), "chaine");
                ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 320 "synt.y"
    {
                  // verifier si double declaration
                  if(estDeclare((yyvsp[(1) - (4)].chaine))){
                    printf("erreur semantique a la ligne %d : double declaration du tableau %s.\n", nbr_ligne, (yyvsp[(1) - (4)].chaine));
                  }else{
                    //inserer le type
                    insererType((yyvsp[(1) - (4)].chaine), sauvType);
                    //definir la taille du tableau
                    definirTailleTableau((yyvsp[(1) - (4)].chaine), (yyvsp[(3) - (4)].entier));
                    //allouer les cellules
                    creerCellules((yyvsp[(1) - (4)].chaine), (yyvsp[(3) - (4)].entier));
                    //sauv idf
                    inserer_var_idf((yyvsp[(1) - (4)].chaine));
                  }
                ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 335 "synt.y"
    {
                  // verifier si double declaration
                  if(estDeclare((yyvsp[(1) - (4)].chaine))){
                    printf("erreur semantique a la ligne %d : double declaration du tableau %s.\n", nbr_ligne, (yyvsp[(1) - (4)].chaine));
                  }else{
                    //inserer le type
                    insererType((yyvsp[(1) - (4)].chaine), sauvType);
                    //definir la taille du tableau
                    definirTailleTableau((yyvsp[(1) - (4)].chaine), (yyvsp[(3) - (4)].entier));
                    //allouer les cellules
                    creerCellules((yyvsp[(1) - (4)].chaine), (yyvsp[(3) - (4)].entier));
                    //sauv idf
                    inserer_var_idf((yyvsp[(1) - (4)].chaine));
                  }
                ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 352 "synt.y"
    { 
                     //verifier si bib.lang inclue
                     if(bib_lang_included == 0 && bib_lang_manquante_detecte == 0){
                       printf("erreur semantique : la bibliotheque ISIL.lang est manquante.\n");
                       bib_lang_manquante_detecte = 1;
                     }
                     //initialiser l'expression arithmetique
                     initialiser_expression_arithmetique();
                     exp_erreur = false;
                    ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 361 "synt.y"
    {
                      if(!exp_erreur && !bib_lang_manquante_detecte){
                        //calculer le resultat de l'expression arithmetique
                        float resultat = calculer_expression_arithmetique(nbr_ligne);
                        // printf("RESULT :  %f \n", resultat);

                        char result_string[100];
                        sprintf(result_string, "%f", resultat);
                        //verifier la compatibilite des types
                        char resultat_type[10];
                        int partie_entiere = (int)resultat;
                        float partie_decimal = resultat - partie_entiere;
                        if(partie_decimal == 0){
                          strcpy(resultat_type, "entier");
                          strcpy(result_string, strtok(result_string, "."));
                        }else{
                          strcpy(resultat_type, "reel");
                        }
                        Var_idf_list * courant = get_var_idf_list_head();
                        while(courant != NULL){
                            if(strcmp(getType(courant->idf), "entier") == 0 && strcmp(resultat_type, "reel") == 0){
                              printf("erreur semantique a la ligne %d : incompatibilite de type, %s est de type entier mais %s est un reel.\n", nbr_ligne, courant->idf, result_string);
                            }else{
                              //affecter
                              affecter(courant->idf, result_string);
                            }
                            courant = courant->suivant;
                        }
                        //affichage exp arithmetique
                        // afficherAX();
                      }
                    ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 393 "synt.y"
    {
                      //verifier si bib.lang inclue
                      if(bib_lang_included == 0 && bib_lang_manquante_detecte == 0){
                        printf("erreur semantique : la bibliotheque ISIL.lang est manquante.\n");
                        bib_lang_manquante_detecte = 1;
                      }
                      if(!bib_lang_manquante_detecte){
                        Var_idf_list * courant = get_var_idf_list_head();
                        while(courant != NULL){
                          char type[30];
                          strcpy(type, getType(courant->idf));
                          if(strcmp(type, "chaine") != 0){
                              printf("erreur semantique a la ligne %d : incompatibilite de type, %s est de type %s mais %s est une chaine.\n", nbr_ligne, courant->idf, type, (yyvsp[(4) - (6)].entier));
                            }else{
                              //affecter
                              affecter(courant->idf, (yyvsp[(5) - (6)].chaine));
                            }
                            courant = courant->suivant;
                        }
                      }
                    ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 416 "synt.y"
    {
                    // verifier si double declaration
                    if(estDeclare((yyvsp[(1) - (3)].chaine))){
                      printf("erreur semantique a la ligne %d : double declaration de la constante %s.\n", nbr_ligne, (yyvsp[(1) - (3)].chaine));
                    }else{
                      //inserer le type
                      insererType((yyvsp[(1) - (3)].chaine), sauvType);
                      //est constante
                      constante((yyvsp[(1) - (3)].chaine));
                      //sauv idf
                      inserer_var_idf((yyvsp[(1) - (3)].chaine));
                    }
                  ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 429 "synt.y"
    {
                    // verifier si double declaration
                    if(estDeclare((yyvsp[(1) - (1)].chaine))){
                      printf("erreur semantique a la ligne %d : double declaration de la constante %s.\n", nbr_ligne, (yyvsp[(1) - (1)].chaine));
                    }else{
                      //inserer le type
                      insererType((yyvsp[(1) - (1)].chaine), sauvType);
                      //est constante
                      constante((yyvsp[(1) - (1)].chaine));
                      //sauv idf
                      inserer_var_idf((yyvsp[(1) - (1)].chaine));
                    }
                  ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 443 "synt.y"
    { strcpy(sauvType, (yyvsp[(1) - (1)].chaine)); ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 444 "synt.y"
    { strcpy(sauvType, (yyvsp[(1) - (1)].chaine)); ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 445 "synt.y"
    { strcpy(sauvType, (yyvsp[(1) - (1)].chaine)); ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 450 "synt.y"
    {reinitialiser_var_idf_list_head(); reinitialiser_liste_elements_head();;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 452 "synt.y"
    {
               if(bib_io_included == 0 && bib_io_manquante_detecte == 0){
                 printf("erreur semantique : la bibliotheque ISIL.io est manquante.\n");
                 bib_io_manquante_detecte = 1;
               }
               reinitialiser_var_idf_list_head();
               reinitialiser_signes_formatage_head();
              ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 460 "synt.y"
    {
               if(bib_io_included == 0 && bib_io_manquante_detecte == 0){
                 printf("erreur semantique : la bibliotheque ISIL.io est manquante.\n");
                 bib_io_manquante_detecte = 1;
               }
               reinitialiser_var_idf_list_head();
               reinitialiser_signes_formatage_head();
              ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 469 "synt.y"
    { 
            //verifier si bib.lang inclue
             if(bib_lang_included == 0 && bib_lang_manquante_detecte == 0){
               printf("erreur semantique : la bibliotheque ISIL.lang est manquante.\n");
               bib_lang_manquante_detecte = 1;
             }
             //initialiser l'expression arithmetique
             initialiser_expression_arithmetique();
             exp_erreur = false;
            ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 478 "synt.y"
    {
                                      if(!idf_var_prblm && !exp_erreur && !bib_lang_manquante_detecte){
                                         //calculer le resultat de l'expression arithmetique
                                         float resultat = calculer_expression_arithmetique(nbr_ligne);
                                         // printf("RESULT :  %f \n", resultat);

                                         char result_string[100];
                                         sprintf(result_string, "%f", resultat);
                                         //verifier la compatibilite des types
                                         char resultat_type[10];
                                         int partie_entiere = (int)resultat;
                                         float partie_decimal = resultat - partie_entiere;
                                         if(partie_decimal == 0){
                                           strcpy(resultat_type, "entier");
                                           strcpy(result_string, strtok(result_string, "."));
                                         }else{
                                           strcpy(resultat_type, "reel");
                                         }
                                         if(strcmp(getType(var_idf_sauv), "chaine") == 0){
                                            printf("erreur semantique a la ligne %d : incompatibilite de type, %s est de type chaine mais %s est un %s.\n", nbr_ligne, var_idf_sauv, result_string, resultat_type);
                                          }else if(strcmp(getType(var_idf_sauv), "entier") == 0 && strcmp(resultat_type, "reel") == 0){
                                            printf("erreur semantique a la ligne %d : incompatibilite de type, %s est de type entier mais %s est un reel.\n", nbr_ligne, var_idf_sauv, result_string);
                                          }else{
                                            //affecter
                                            affecter(var_idf_sauv, result_string);
                                          }
  
                                          //affichage exp arithmetique
                                          // afficherAX();
                                      }
                                    ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 509 "synt.y"
    {
              //verifier si bib.lang inclue
              if(bib_lang_included == 0 && bib_lang_manquante_detecte == 0){
                printf("erreur semantique : la bibliotheque ISIL.lang est manquante.\n");
                bib_lang_manquante_detecte = 1;
              }
              if(!idf_var_prblm && !bib_lang_manquante_detecte){
                char type[30];
                strcpy(type, getType(var_idf_sauv));
                if(strcmp(type, "chaine") != 0){
                  printf("erreur semantique a la ligne %d : incompatibilite de type, %s est de type %s mais %s est une chaine.\n", nbr_ligne, var_idf_sauv, type, (yyvsp[(3) - (4)].chaine));
                }else{
                  //affecter
                  affecter(var_idf_sauv, (yyvsp[(3) - (4)].chaine));
                }
              }
            ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 526 "synt.y"
    {
                                        if(bib_lang_included == 0 && bib_lang_manquante_detecte == 0){
                                          printf("erreur semantique : la bibliotheque ISIL.lang est manquante.\n");
                                          bib_lang_manquante_detecte = 1;
                                        }
                                        if(!idf_var_prblm && !bib_lang_manquante_detecte){
                                          if(estNombre(var_idf_sauv)){
                                            //affecter
                                            char ans_valeur[100];
                                            char nvl_valeur[100];
                                            strcpy(ans_valeur, getValue(var_idf_sauv));
                                            if(strcmp(getType(var_idf_sauv), "reel") == 0){
                                              float val_reel = atof(ans_valeur);
                                              val_reel ++;
                                              sprintf(nvl_valeur, "%f", val_reel);
                                            }else if(strcmp(getType(var_idf_sauv), "entier") == 0){
                                              int val_entier = atoi(ans_valeur);
                                              val_entier ++;
                                              sprintf(nvl_valeur, "%d", val_entier);
                                            }
                                            affecter(var_idf_sauv, nvl_valeur);
                                          }else{
                                            printf("erreur semantique a la ligne %d : la variable %s est de type chaine, elle ne peut pas etre augmenter par 1.\n", nbr_ligne, var_idf_sauv);
                                          }
                                        }
                                      ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 552 "synt.y"
    {
                                        if(bib_lang_included == 0 && bib_lang_manquante_detecte == 0){
                                          printf("erreur semantique : la bibliotheque ISIL.lang est manquante.\n");
                                          bib_lang_manquante_detecte = 1;
                                        }
                                        if(!idf_var_prblm && !bib_lang_manquante_detecte){
                                          if(estNombre(var_idf_sauv)){
                                            //affecter
                                            char ans_valeur[100];
                                            char nvl_valeur[100];
                                            strcpy(ans_valeur, getValue(var_idf_sauv));
                                            if(strcmp(getType(var_idf_sauv), "reel") == 0){
                                              float val_reel = atof(ans_valeur);
                                              val_reel --;
                                              sprintf(nvl_valeur, "%f", val_reel);
                                            }else if(strcmp(getType(var_idf_sauv), "entier") == 0){
                                              int val_entier = atoi(ans_valeur);
                                              val_entier --;
                                              sprintf(nvl_valeur, "%d", val_entier);
                                            }
                                            affecter(var_idf_sauv, nvl_valeur);
                                          }else{
                                            printf("erreur semantique a la ligne %d : la variable %s est de type chaine, elle ne peut pas etre augmenter par 1.\n", nbr_ligne, var_idf_sauv);
                                          }
                                        }
                                      ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 578 "synt.y"
    {
                        //verifier si bib.lang inclue
                        if(bib_lang_included == 0 && bib_lang_manquante_detecte == 0){
                          printf("erreur semantique : la bibliotheque ISIL.lang est manquante.\n");
                          bib_lang_manquante_detecte = 1;
                        }
                      ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 584 "synt.y"
    {
                        if(!bib_lang_manquante_detecte){
                          //verification de taille
                          if(getTailleTableau((yyvsp[(1) - (9)].chaine)) < liste_elements_length()){
                            printf("erreur semantique a la ligne %d : depassement de la taille du tableau %s.\n", nbr_ligne, (yyvsp[(1) - (9)].chaine));
                          }else{
                            //verification des types
                            bool estCompatible = true;
                            Liste_elements *elt_courant = get_liste_elements_head();
                            while(elt_courant != NULL){
                              if(strcmp(elt_courant->type, getType((yyvsp[(1) - (9)].chaine))) != 0){
                                printf("erreur semantique a la ligne %d : incompatibilite de type, le tableau %s est de type %s mais l'element %s est de type %s.\n", nbr_ligne, (yyvsp[(1) - (9)].chaine), getType((yyvsp[(1) - (9)].chaine)), elt_courant->element, elt_courant->type);
                                estCompatible = false;
                              }
                              elt_courant = elt_courant->suivant;
                            }
                            if(estCompatible){
                              //remplissement des cellules
                              int i = 0;
                              char str[10];
                              elt_courant = get_liste_elements_head();
                              while(elt_courant != NULL){
                              char cellule[30];
                              strcpy(cellule, (yyvsp[(1) - (9)].chaine));
                              strcat(cellule, "[");
                              sprintf(str, "%d", i);
                              strcat(cellule, str);
                              strcat(cellule, "]");
                              affecter(cellule, elt_courant->element);
                              i++;
                              elt_courant = elt_courant->suivant;
                            }
                            }
                          }
                        }
                      ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 623 "synt.y"
    {
                if(!estDeclare((yyvsp[(1) - (1)].chaine))){
                  if(!non_declare_deja_detecte((yyvsp[(1) - (1)].chaine), nbr_ligne)){
                    printf("erreur semantique a la ligne %d : la variable %s est non declare.\n", nbr_ligne, (yyvsp[(1) - (1)].chaine));
                    inserer_non_declare((yyvsp[(1) - (1)].chaine), nbr_ligne);
                  }
                  idf_var_prblm = true;
                }else if(strcmp(getValue((yyvsp[(1) - (1)].chaine)), "") != 0 && estConstante((yyvsp[(1) - (1)].chaine))){
                  printf("erreur semantique a la ligne %d : la constante %s est deja definie.\n", nbr_ligne, (yyvsp[(1) - (1)].chaine));
                  idf_var_prblm = true;
                }else{
                  strcpy(var_idf_sauv, (yyvsp[(1) - (1)].chaine));
                  idf_var_prblm = false;
                }
              ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 638 "synt.y"
    {
                //nom de cellule
                char nom_cellule[30];
                char num_cellule[10];
                strcpy(nom_cellule, "");
                strcpy(num_cellule, "");
                sprintf(num_cellule, "%d", (yyvsp[(3) - (4)].entier));
                strcat(nom_cellule, (yyvsp[(1) - (4)].chaine));
                strcat(nom_cellule, "[");
                strcat(nom_cellule, num_cellule);
                strcat(nom_cellule, "]");
                if(!estDeclare((yyvsp[(1) - (4)].chaine))){
                  if(!non_declare_deja_detecte((yyvsp[(1) - (4)].chaine), nbr_ligne)){
                    printf("erreur semantique a la ligne %d : le tableau %s est non declare.\n", nbr_ligne, (yyvsp[(1) - (4)].chaine));
                    inserer_non_declare((yyvsp[(1) - (4)].chaine), nbr_ligne);
                  }
                  idf_var_prblm = true;
                }else if(estDepasseTaille((yyvsp[(1) - (4)].chaine), (yyvsp[(3) - (4)].entier))){
                  printf("erreur semantique a la ligne %d : depassement de la taille, la cellule %s n'existe pas.\n", nbr_ligne, nom_cellule); 
                  idf_var_prblm = true;
                }else{
                  idf_var_prblm = false;
                  strcpy(var_idf_sauv, nom_cellule);
                }
              ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 667 "synt.y"
    {
                           ajouter_parenthese_expression_arithmetique("pr_ov");
                         ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 669 "synt.y"
    {
                           ajouter_parenthese_expression_arithmetique("pr_fr");
                         ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 676 "synt.y"
    {
            if(!estDeclare((yyvsp[(1) - (1)].chaine))){
              if(!non_declare_deja_detecte((yyvsp[(1) - (1)].chaine), nbr_ligne)){
                printf("erreur semantique a la ligne %d : la variable %s est non declare.\n", nbr_ligne, (yyvsp[(1) - (1)].chaine));
                inserer_non_declare((yyvsp[(1) - (1)].chaine), nbr_ligne);
              }
            }else if(!estNombre((yyvsp[(1) - (1)].chaine))){
              exp_erreur = true;
              printf("erreur semantique a la ligne %d : la variable %s n'est pas un nombre, elle ne peut pas etre un operand dans une expression arithmetique.\n", nbr_ligne, (yyvsp[(1) - (1)].chaine));
            }else if(strcmp(getValue((yyvsp[(1) - (1)].chaine)), "") == 0){
              printf("erreur semantique a la ligne %d : la variable %s est non definie.\n", nbr_ligne, (yyvsp[(1) - (1)].chaine));
              exp_erreur = true;
            }else{
              if(strcmp(getType((yyvsp[(1) - (1)].chaine)), "entier") == 0){
                ajouter_operand_expression_arithmetique((yyvsp[(1) - (1)].chaine), atoi(getValue((yyvsp[(1) - (1)].chaine))));
              }else if(strcmp(getType((yyvsp[(1) - (1)].chaine)), "reel") == 0){
                ajouter_operand_expression_arithmetique((yyvsp[(1) - (1)].chaine), atof(getValue((yyvsp[(1) - (1)].chaine))));
              }
            }
         ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 696 "synt.y"
    {
            //nom de cellule
            char nom_cellule[30];
            char num_cellule[10];
            strcpy(nom_cellule, "");
            strcpy(num_cellule, "");
            sprintf(num_cellule, "%d", (yyvsp[(3) - (4)].entier));
            strcat(nom_cellule, (yyvsp[(1) - (4)].chaine));
            strcat(nom_cellule, "[");
            strcat(nom_cellule, num_cellule);
            strcat(nom_cellule, "]");
            if(!estDeclare(nom_cellule)){
              if(!non_declare_deja_detecte(nom_cellule, nbr_ligne)){
                printf("erreur semantique a la ligne %d : la variable %s est non declare.\n", nbr_ligne, nom_cellule);
                inserer_non_declare(nom_cellule, nbr_ligne);
              }
            }else if(estDepasseTaille((yyvsp[(1) - (4)].chaine), (yyvsp[(3) - (4)].entier))){
              printf("erreur semantique a la ligne %d : depassement de la taille, la cellule %s n'existe pas.\n", nbr_ligne, nom_cellule);
              exp_erreur = true;
            }else if(!estNombre(nom_cellule)){
              printf("erreur semantique a la ligne %d : la variable %s n'est pas un nombre, elle ne peut pas etre un operand dans une expression arithmetique.\n", nbr_ligne, nom_cellule);
              exp_erreur = true;
            }else if(strcmp(getValue(nom_cellule), "") == 0){
              printf("erreur semantique a la ligne %d : la variable %s est non definie.\n", nbr_ligne, nom_cellule);
              exp_erreur = true;
            }else{
              if(strcmp(getType(nom_cellule), "entier") == 0){
                ajouter_operand_expression_arithmetique(nom_cellule, atoi(getValue(nom_cellule)));
              }else if(strcmp(getType(nom_cellule), "reel") == 0){
                ajouter_operand_expression_arithmetique(nom_cellule, atof(getValue(nom_cellule)));
              }
            }
         ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 729 "synt.y"
    {
                char str[255];
                sprintf(str, "%d", (yyvsp[(1) - (1)].entier));
                ajouter_operand_expression_arithmetique(str, (float)(yyvsp[(1) - (1)].entier));
              ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 734 "synt.y"
    {
                  char str[255];
                  sprintf(str, "%d", (yyvsp[(1) - (1)].entier));
                  ajouter_operand_expression_arithmetique(str, (float)(yyvsp[(1) - (1)].entier));
                ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 739 "synt.y"
    {
                char str[255];
                sprintf(str, "%f", (yyvsp[(1) - (1)].reel));
                ajouter_operand_expression_arithmetique(str, (yyvsp[(1) - (1)].reel));
              ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 745 "synt.y"
    {
                 ajouter_operation_expression_arithmetique("add");
               ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 748 "synt.y"
    {
                 ajouter_operation_expression_arithmetique("sus");
               ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 751 "synt.y"
    {
                 ajouter_operation_expression_arithmetique("mult");
                ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 754 "synt.y"
    {
                ajouter_operation_expression_arithmetique("dv");
              ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 762 "synt.y"
    {
                     //initialiser l'expression arithmetique
                     initialiser_expression_arithmetique();
                     exp_erreur = false;
                    ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 766 "synt.y"
    {
                                              //verifier si bib.lang inclue
                                              if(bib_lang_included == 0 && bib_lang_manquante_detecte == 0){
                                                printf("erreur semantique : la bibliotheque ISIL.lang est manquante.\n");
                                                bib_lang_manquante_detecte = 1;
                                              }
                                              if(!idf_var_prblm && !exp_erreur && !bib_lang_manquante_detecte){
                                                //calculer le resultat de l'expression arithmetique
                                                float resultat = calculer_expression_arithmetique(nbr_ligne);
                                                // printf("RESULT :  %f \n", resultat);

                                                char result_string[100];
                                                sprintf(result_string, "%f", resultat);
                                                //verifier la compatibilite des types
                                                char resultat_type[10];
                                                int partie_entiere = (int)resultat;
                                                float partie_decimal = resultat - partie_entiere;
                                                if(partie_decimal == 0){
                                                  strcpy(resultat_type, "entier");
                                                  strcpy(result_string, strtok(result_string, "."));
                                                }else{
                                                  strcpy(resultat_type, "reel");
                                                }
                                                if(strcmp(getType(var_idf_sauv), "entier") == 0 && strcmp(resultat_type, "reel") == 0){
                                                  printf("erreur semantique a la ligne %d : incompatibilite de type, %s est de type entier mais %s est un reel.\n", nbr_ligne, var_idf_sauv, result_string);
                                                }else{
                                                  //affecter
                                                  affecter(var_idf_sauv, result_string);
                                                }

                                                //affichage exp arithmetique
                                                // afficherAX();
                                              }
                                            ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 800 "synt.y"
    { 
                     //initialiser l'expression arithmetique
                     initialiser_expression_arithmetique();
                     exp_erreur = false;
                    ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 804 "synt.y"
    {
                                              //verifier si bib.lang inclue
                                              if(bib_lang_included == 0 && bib_lang_manquante_detecte == 0){
                                                printf("erreur semantique : la bibliotheque ISIL.lang est manquante.\n");
                                                bib_lang_manquante_detecte = 1;
                                              }
                                              if(!bib_lang_manquante_detecte){
                                                // verifier si double declaration
                                                if(estDeclare((yyvsp[(2) - (5)].chaine))){
                                                  printf("erreur semantique a la ligne %d : double declaration de la variable %s.\n", nbr_ligne, (yyvsp[(2) - (5)].chaine));
                                                }else{
                                                  //inserer le type
                                                  insererType((yyvsp[(2) - (5)].chaine), sauvType);
                                                  if(!exp_erreur){
                                                      //calculer le resultat de l'expression arithmetique
                                                      float resultat = calculer_expression_arithmetique(nbr_ligne);
                                                      // printf("RESULT :  %f \n", resultat);

                                                      char result_string[100];
                                                      sprintf(result_string, "%f", resultat);
                                                      //verifier la compatibilite des types
                                                      char resultat_type[10];
                                                      int partie_entiere = (int)resultat;
                                                      float partie_decimal = resultat - partie_entiere;
                                                      if(partie_decimal == 0){
                                                        strcpy(resultat_type, "entier");
                                                        strcpy(result_string, strtok(result_string, "."));
                                                      }else{
                                                        strcpy(resultat_type, "reel");
                                                      }
                                                      if(strcmp(getType((yyvsp[(2) - (5)].chaine)), "chaine") == 0){
                                                        printf("erreur semantique a la ligne %d : incompatibilite de type, %s est de type chaine mais %s est un %s.\n", nbr_ligne, (yyvsp[(2) - (5)].chaine), result_string, resultat_type);
                                                      }else if(strcmp(getType((yyvsp[(2) - (5)].chaine)), "entier") == 0 && strcmp(resultat_type, "reel") == 0){
                                                        printf("erreur semantique a la ligne %d : incompatibilite de type, %s est de type entier mais %s est un reel.\n", nbr_ligne, (yyvsp[(2) - (5)].chaine), result_string);
                                                      }else{
                                                        //affecter
                                                        affecter((yyvsp[(2) - (5)].chaine), result_string);
                                                      }

                                                      //affichage exp arithmetique
                                                      // afficherAX();
                                                  }
                                                }
                                              }
                                            ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 859 "synt.y"
    {
                          //verifier si bib.lang inclue
                          if(bib_lang_included == 0 && bib_lang_manquante_detecte == 0){
                            printf("erreur semantique : la bibliotheque ISIL.lang est manquante.\n");
                            bib_lang_manquante_detecte = 1;
                          }
                        ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 866 "synt.y"
    {
                        //verifier si bib.lang inclue
                          if(bib_lang_included == 0 && bib_lang_manquante_detecte == 0){
                            printf("erreur semantique : la bibliotheque ISIL.lang est manquante.\n");
                            bib_lang_manquante_detecte = 1;
                          }
                        ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 873 "synt.y"
    { 
                       //verifier si bib.lang inclue
                       if(bib_lang_included == 0 && bib_lang_manquante_detecte == 0){
                         printf("erreur semantique : la bibliotheque ISIL.lang est manquante.\n");
                         bib_lang_manquante_detecte = 1;
                       }
                       //initialiser l'expression arithmetique
                       initialiser_expression_arithmetique();
                       exp_erreur = false;
                      ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 882 "synt.y"
    {
                        if(!idf_var_prblm && !exp_erreur && !bib_lang_manquante_detecte){
                          //calculer le resultat de l'expression arithmetique
                           float resultat = calculer_expression_arithmetique(nbr_ligne);
                           // printf("RESULT :  %f \n", resultat);
                           char result_string[100];
                           sprintf(result_string, "%f", resultat);
                           //verifier la compatibilite des types
                           char resultat_type[10];
                           int partie_entiere = (int)resultat;
                           float partie_decimal = resultat - partie_entiere;
                           if(partie_decimal == 0){
                             strcpy(resultat_type, "entier");
                             strcpy(result_string, strtok(result_string, "."));
                           }else{
                             strcpy(resultat_type, "reel");
                           }
                           if(strcmp(getType(var_idf_sauv), "entier") == 0 && strcmp(resultat_type, "reel") == 0){
                             printf("erreur semantique a la ligne %d : incompatibilite de type, %s est de type entier mais %s est un reel.\n", nbr_ligne, var_idf_sauv, result_string);
                           }else{
                             //ne pas affecter
                             //affecter(var_idf_sauv, result_string);
                           }

                           //affichage exp arithmetique
                           // afficherAX();
                        }
                      ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 912 "synt.y"
    {
  if(!idf_var_prblm){
    int len = strlen((yyvsp[(3) - (7)].chaine));
    for(int i = 1 ; i < len-2 ; i++){
      if((yyvsp[(3) - (7)].chaine)[i] == '%' && (yyvsp[(3) - (7)].chaine)[i-1] != '\\' && ((yyvsp[(3) - (7)].chaine)[i+1] == 'd' || (yyvsp[(3) - (7)].chaine)[i+1] == 'f' || (yyvsp[(3) - (7)].chaine)[i+1] == 's') ){
        char signe[3];
        signe[0] = (yyvsp[(3) - (7)].chaine)[i];
        signe[1] = (yyvsp[(3) - (7)].chaine)[i+1];
        inserer_signe_formatage(signe);
      }
    }
    if(signes_formatage_length() > 1){
      printf("erreur semantique a la ligne %d : trop de signes de formatage.\n", nbr_ligne);
    }else if(signes_formatage_length() == 0){
      printf("erreur semantique a la ligne %d : aucun signe de formatage.\n", nbr_ligne);
    }else{
      char temp[len-2];
      strcpy(temp, get_signes_formatage_head()->signe);
      char type[30];
      strcpy(type, getType(var_idf_sauv));
      if(strcmp(temp, "%d") == 0){
        if(strcmp("entier", type) != 0){
          printf("erreur semantique a la ligne %d : incompatibilite de type, l'entree est de type entier mais %s est de type %s.\n", nbr_ligne, var_idf_sauv, type);
        }
      }else if(strcmp(temp, "%f") == 0){
        if(strcmp("reel", type) != 0){
          printf("erreur semantique a la ligne %d : incompatibilite de type, l'entree est de type reel mais %s est de type %s.\n", nbr_ligne, var_idf_sauv, type);
        }
      }else if(strcmp(temp, "%s") == 0){
        if(strcmp("chaine", type) != 0){
          printf("erreur semantique a la ligne %d : incompatibilite de type, l'entree est de type chaine mais %s est de type %s.\n", nbr_ligne, var_idf_sauv, type);
        }
      }else{
        printf("erreur semantique a la ligne %d : le signe de formatage %s est inconnu.\n", nbr_ligne, (yyvsp[(3) - (7)].chaine));
      }
    }
  }
;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 952 "synt.y"
    {
  if(!idf_var_prblm){
    int len = strlen((yyvsp[(3) - (6)].chaine));
    for(int i = 1 ; i < len-2 ; i++){
      if((yyvsp[(3) - (6)].chaine)[i] == '%' && (yyvsp[(3) - (6)].chaine)[i-1] != '\\' && ((yyvsp[(3) - (6)].chaine)[i+1] == 'd' || (yyvsp[(3) - (6)].chaine)[i+1] == 'f' || (yyvsp[(3) - (6)].chaine)[i+1] == 's') ){
        char signe[3];
        signe[0] = (yyvsp[(3) - (6)].chaine)[i];
        signe[1] = (yyvsp[(3) - (6)].chaine)[i+1];
        inserer_signe_formatage(signe);
      }
    }
    int signes_formatage_length_con = signes_formatage_length();
    int var_idf_list_length_con = var_idf_list_length();
    if(signes_formatage_length_con > var_idf_list_length_con){
      printf("erreur semantique a la ligne %d : le nombre des signes de formatage est superieur au nombre des sorties.\n", nbr_ligne);
    }else if(signes_formatage_length_con < var_idf_list_length_con){
      printf("erreur semantique a la ligne %d : le nombre des signes de formatage est inferieur au nombre des sorties.\n", nbr_ligne);
    }else if(signes_formatage_length_con == var_idf_list_length_con){
      Signes_formatage *sf_courant = get_signes_formatage_head();
      Var_idf_list *idf_courant = get_var_idf_list_head();
      int num_sortie = signes_formatage_length_con;
      while(sf_courant != NULL && idf_courant != NULL){
        char type[30];
        strcpy(type, getType(idf_courant->idf));
        if(strcmp(sf_courant->signe, "%d") == 0){
          if(strcmp("entier", type) != 0){
            printf("erreur semantique a la ligne %d : incompatibilite de type, la sortie num%d est de type entier mais %s est de type %s.\n", nbr_ligne, num_sortie, idf_courant->idf, type);
          }
        }else if(strcmp(sf_courant->signe, "%f") == 0){
          if(strcmp("reel", type) != 0){
            printf("erreur semantique a la ligne %d : incompatibilite de type, la sortie num%d est de type reel mais %s est de type %s.\n", nbr_ligne, num_sortie, idf_courant->idf, type);
          }
        }else if(strcmp(sf_courant->signe, "%s") == 0){
          if(strcmp("chaine", type) != 0){
            printf("erreur semantique a la ligne %d : incompatibilite de type, la sortie num%d est de type chaine mais %s est de type %s.\n", nbr_ligne, num_sortie, idf_courant->idf, type);
          }
        }else{
          printf("erreur semantique a la ligne %d : le signe de formatage %s est inconnu.\n", nbr_ligne, (yyvsp[(3) - (6)].chaine));
        }
        num_sortie--;
        sf_courant = sf_courant->suivant;
        idf_courant = idf_courant->suivant;
      }
    }
  }
;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 1000 "synt.y"
    {inserer_var_idf(var_idf_sauv);;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 1001 "synt.y"
    {inserer_var_idf(var_idf_sauv);;}
    break;



/* Line 1455 of yacc.c  */
#line 2843 "synt.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


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
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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
#line 1005 "synt.y"

void yyerror (const char *s) {
  printf("erreur syntaxique !! a la ligne %d \n", nbr_ligne);
}
int main()
{
  yyparse();
  afficher();
}
int yywrap() {}
