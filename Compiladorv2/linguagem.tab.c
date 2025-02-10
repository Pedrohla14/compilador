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
#line 1 "linguagem.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylineno;  /* Variável definida no scanner (lex) */
int error_count = 0;  /* Contador global de erros */

// Tabela de símbolos para controle semântico (declaração de variáveis)
typedef struct Symbol {
    char *name;
    char *type;
    struct Symbol *next;
} Symbol;

Symbol *symbol_table = NULL;

void declare_variable(const char *name, const char *type) {
    Symbol *s = (Symbol *) malloc(sizeof(Symbol));
    s->name = strdup(name);
    s->type = strdup(type);
    s->next = symbol_table;
    symbol_table = s;
}

int variable_declared(const char *name) {
    Symbol *current = symbol_table;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

void check_variable(const char *name) {
    if (!variable_declared(name)) {
        error_count++;
        fprintf(stderr, "Erro semantico na linha %d: variavel '%s' nao foi declarada\n", yylineno, name);
    }
}

extern FILE *yyin;
void yyerror(const char *s);
int yylex();

#line 119 "linguagem.tab.c"

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

#include "linguagem.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUM = 3,                        /* NUM  */
  YYSYMBOL_STRING = 4,                     /* STRING  */
  YYSYMBOL_IDENTIFICADOR = 5,              /* IDENTIFICADOR  */
  YYSYMBOL_CONFIG = 6,                     /* CONFIG  */
  YYSYMBOL_REPITA = 7,                     /* REPITA  */
  YYSYMBOL_FIM = 8,                        /* FIM  */
  YYSYMBOL_VAR = 9,                        /* VAR  */
  YYSYMBOL_INTEIRO = 10,                   /* INTEIRO  */
  YYSYMBOL_BOOLEANO = 11,                  /* BOOLEANO  */
  YYSYMBOL_TEXTO = 12,                     /* TEXTO  */
  YYSYMBOL_CONFIGURAR = 13,                /* CONFIGURAR  */
  YYSYMBOL_COMO = 14,                      /* COMO  */
  YYSYMBOL_SAIDA = 15,                     /* SAIDA  */
  YYSYMBOL_ENTRADA = 16,                   /* ENTRADA  */
  YYSYMBOL_LIGAR = 17,                     /* LIGAR  */
  YYSYMBOL_DESLIGAR = 18,                  /* DESLIGAR  */
  YYSYMBOL_CONECTAR_WIFI = 19,             /* CONECTAR_WIFI  */
  YYSYMBOL_CONFIGURAR_SERIAL = 20,         /* CONFIGURAR_SERIAL  */
  YYSYMBOL_ESCREVER_SERIAL = 21,           /* ESCREVER_SERIAL  */
  YYSYMBOL_LER_SERIAL = 22,                /* LER_SERIAL  */
  YYSYMBOL_ENVIAR_HTTP = 23,               /* ENVIAR_HTTP  */
  YYSYMBOL_ESPERAR = 24,                   /* ESPERAR  */
  YYSYMBOL_LER_DIGITAL = 25,               /* LER_DIGITAL  */
  YYSYMBOL_LER_ANALOGICO = 26,             /* LER_ANALOGICO  */
  YYSYMBOL_CONFIGURAR_PWM = 27,            /* CONFIGURAR_PWM  */
  YYSYMBOL_FREQUENCIA = 28,                /* FREQUENCIA  */
  YYSYMBOL_RESOLUCAO = 29,                 /* RESOLUCAO  */
  YYSYMBOL_AJUSTAR_PWM = 30,               /* AJUSTAR_PWM  */
  YYSYMBOL_VALOR = 31,                     /* VALOR  */
  YYSYMBOL_COM = 32,                       /* COM  */
  YYSYMBOL_SE = 33,                        /* SE  */
  YYSYMBOL_ENTRADA_PULLDOWN = 34,          /* ENTRADA_PULLDOWN  */
  YYSYMBOL_SENAO = 35,                     /* SENAO  */
  YYSYMBOL_ENTAO = 36,                     /* ENTAO  */
  YYSYMBOL_ENQUANTO = 37,                  /* ENQUANTO  */
  YYSYMBOL_IGUAL = 38,                     /* IGUAL  */
  YYSYMBOL_DIFERENTE = 39,                 /* DIFERENTE  */
  YYSYMBOL_MENOR_IGUAL = 40,               /* MENOR_IGUAL  */
  YYSYMBOL_MAIOR_IGUAL = 41,               /* MAIOR_IGUAL  */
  YYSYMBOL_MENOR = 42,                     /* MENOR  */
  YYSYMBOL_MAIOR = 43,                     /* MAIOR  */
  YYSYMBOL_SOMA = 44,                      /* SOMA  */
  YYSYMBOL_SUBTRACAO = 45,                 /* SUBTRACAO  */
  YYSYMBOL_MULTIPLICACAO = 46,             /* MULTIPLICACAO  */
  YYSYMBOL_DIVISAO = 47,                   /* DIVISAO  */
  YYSYMBOL_IGUALDADE = 48,                 /* IGUALDADE  */
  YYSYMBOL_DOIS_PONTOS = 49,               /* DOIS_PONTOS  */
  YYSYMBOL_VIRGULA = 50,                   /* VIRGULA  */
  YYSYMBOL_PONTO_E_VIRGULA = 51,           /* PONTO_E_VIRGULA  */
  YYSYMBOL_YYACCEPT = 52,                  /* $accept  */
  YYSYMBOL_programa = 53,                  /* programa  */
  YYSYMBOL_declaracoes = 54,               /* declaracoes  */
  YYSYMBOL_declaracao = 55,                /* declaracao  */
  YYSYMBOL_tipo = 56,                      /* tipo  */
  YYSYMBOL_lista_ids = 57,                 /* lista_ids  */
  YYSYMBOL_config = 58,                    /* config  */
  YYSYMBOL_bloco_config = 59,              /* bloco_config  */
  YYSYMBOL_repita = 60,                    /* repita  */
  YYSYMBOL_bloco_repita = 61,              /* bloco_repita  */
  YYSYMBOL_comando = 62,                   /* comando  */
  YYSYMBOL_condicao = 63,                  /* condicao  */
  YYSYMBOL_operando = 64,                  /* operando  */
  YYSYMBOL_comparador = 65,                /* comparador  */
  YYSYMBOL_bloco_cmd = 66,                 /* bloco_cmd  */
  YYSYMBOL_senao_cmd_opt = 67              /* senao_cmd_opt  */
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   142

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  16
/* YYNRULES -- Number of rules.  */
#define YYNRULES  47
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  105

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   306


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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    74,    74,    84,    85,    96,   112,   113,   114,   117,
     119,   129,   134,   135,   146,   151,   152,   164,   169,   174,
     187,   193,   198,   204,   209,   214,   219,   224,   228,   234,
     240,   244,   248,   253,   261,   269,   277,   282,   292,   293,
     294,   295,   296,   297,   302,   303,   315,   316
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
  "\"end of file\"", "error", "\"invalid token\"", "NUM", "STRING",
  "IDENTIFICADOR", "CONFIG", "REPITA", "FIM", "VAR", "INTEIRO", "BOOLEANO",
  "TEXTO", "CONFIGURAR", "COMO", "SAIDA", "ENTRADA", "LIGAR", "DESLIGAR",
  "CONECTAR_WIFI", "CONFIGURAR_SERIAL", "ESCREVER_SERIAL", "LER_SERIAL",
  "ENVIAR_HTTP", "ESPERAR", "LER_DIGITAL", "LER_ANALOGICO",
  "CONFIGURAR_PWM", "FREQUENCIA", "RESOLUCAO", "AJUSTAR_PWM", "VALOR",
  "COM", "SE", "ENTRADA_PULLDOWN", "SENAO", "ENTAO", "ENQUANTO", "IGUAL",
  "DIFERENTE", "MENOR_IGUAL", "MAIOR_IGUAL", "MENOR", "MAIOR", "SOMA",
  "SUBTRACAO", "MULTIPLICACAO", "DIVISAO", "IGUALDADE", "DOIS_PONTOS",
  "VIRGULA", "PONTO_E_VIRGULA", "$accept", "programa", "declaracoes",
  "declaracao", "tipo", "lista_ids", "config", "bloco_config", "repita",
  "bloco_repita", "comando", "condicao", "operando", "comparador",
  "bloco_cmd", "senao_cmd_opt", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-59)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -59,     7,    35,   -59,   -59,    -1,   -59,    23,    -5,   -59,
     -59,   -59,   -18,   -59,   -59,     3,   -59,    47,    54,    60,
      61,    65,    68,    66,    75,    76,    15,   -59,   -59,    78,
      16,     1,    59,    36,    38,    81,    39,    43,    50,    70,
      72,   -59,   -59,    69,    80,    37,   -59,   -49,   -59,   -59,
      56,    62,    63,   103,   105,    32,   -59,   -59,    64,   -59,
     -59,   -59,    83,    86,   -59,   -59,   -59,   -59,   -59,   -59,
     -59,    15,   -59,   -59,   119,   -59,   -59,   -59,   -59,    74,
      77,    82,    84,   -59,   123,    57,    58,   -59,   -59,   -59,
     -59,   -59,   -59,    98,    85,    87,   -59,   121,   127,   -59,
     -59,    79,   -59,    88,   -59
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     0,     1,    12,     0,     4,     0,     0,     6,
       7,     8,     0,    15,     2,     0,    11,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    44,    13,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    37,    36,     0,     0,     0,     9,     0,    14,    16,
       0,     0,     0,     0,     0,     0,    25,    26,     0,    30,
      31,    27,     0,     0,    44,    38,    39,    40,    41,    42,
      43,     0,    34,    45,     0,     5,    17,    18,    32,     0,
       0,     0,     0,    19,     0,     0,    47,    35,    10,    28,
      29,    23,    24,     0,     0,     0,    44,     0,     0,    21,
      20,    46,    33,     0,    22
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -59,   -59,   -59,   -59,   -59,   -59,   -59,   -59,   -59,   -59,
       9,   -59,    71,   -59,   -58,   -59
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,     6,    12,    47,     7,     8,    14,    30,
      73,    43,    44,    71,    45,    97
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      15,    74,    75,    16,    50,    51,    86,     3,    17,     9,
      10,    11,    18,    19,    20,    21,    22,    28,    41,    23,
      42,    15,    24,    52,    48,    25,    53,    54,    26,    17,
      13,    29,    27,    18,    19,    20,    21,    22,   101,    49,
      23,     4,    15,    24,     5,    72,    25,    81,    82,    26,
      17,    31,    32,    27,    18,    19,    20,    21,    22,    33,
      94,    23,    95,    15,    24,    34,    35,    25,    36,    38,
      26,    17,    37,    55,    27,    18,    19,    20,    21,    22,
      39,    40,    23,    46,    15,    24,    58,    56,    25,    57,
      59,    26,    17,    96,    60,    27,    18,    19,    20,    21,
      22,    61,    62,    23,    63,    64,    24,    76,    79,    25,
      80,    84,    26,    77,    78,    83,    27,    85,    65,    66,
      67,    68,    69,    70,    88,    89,    93,    98,    90,   102,
     103,     0,     0,    91,     0,    92,    99,     0,   100,   104,
       0,     0,    87
};

static const yytype_int8 yycheck[] =
{
       5,    50,    51,     8,     3,     4,    64,     0,    13,    10,
      11,    12,    17,    18,    19,    20,    21,     8,     3,    24,
       5,     5,    27,    22,     8,    30,    25,    26,    33,    13,
       7,    49,    37,    17,    18,    19,    20,    21,    96,    30,
      24,     6,     5,    27,     9,     8,    30,    15,    16,    33,
      13,    48,     5,    37,    17,    18,    19,    20,    21,     5,
       3,    24,     5,     5,    27,     5,     5,    30,     3,     3,
      33,    13,     4,    14,    37,    17,    18,    19,    20,    21,
       5,     5,    24,     5,     5,    27,     5,    51,    30,    51,
      51,    33,    13,    35,    51,    37,    17,    18,    19,    20,
      21,    51,    32,    24,    32,    36,    27,    51,     5,    30,
       5,    28,    33,    51,    51,    51,    37,    31,    38,    39,
      40,    41,    42,    43,     5,    51,     3,    29,    51,     8,
       3,    -1,    -1,    51,    -1,    51,    51,    -1,    51,    51,
      -1,    -1,    71
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    53,    54,     0,     6,     9,    55,    58,    59,    10,
      11,    12,    56,     7,    60,     5,     8,    13,    17,    18,
      19,    20,    21,    24,    27,    30,    33,    37,    62,    49,
      61,    48,     5,     5,     5,     5,     3,     4,     3,     5,
       5,     3,     5,    63,    64,    66,     5,    57,     8,    62,
       3,     4,    22,    25,    26,    14,    51,    51,     5,    51,
      51,    51,    32,    32,    36,    38,    39,    40,    41,    42,
      43,    65,     8,    62,    50,    51,    51,    51,    51,     5,
       5,    15,    16,    51,    28,    31,    66,    64,     5,    51,
      51,    51,    51,     3,     3,     5,    35,    67,    29,    51,
      51,    66,     8,     3,    51
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    52,    53,    54,    54,    55,    56,    56,    56,    57,
      57,    58,    59,    59,    60,    61,    61,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    63,    64,    64,    65,    65,
      65,    65,    65,    65,    66,    66,    67,    67
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     0,     2,     5,     1,     1,     1,     1,
       3,     3,     0,     2,     3,     0,     2,     4,     4,     4,
       6,     6,     8,     5,     5,     3,     3,     3,     5,     5,
       3,     3,     4,     6,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     2,     2,     0
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
  case 2: /* programa: declaracoes config repita  */
#line 75 "linguagem.y"
    { 
        printf("#include <Arduino.h>\n");
        printf("#include <WiFi.h>\n\n");  /* Inclui o header do WiFi */
        printf("%s\n\nvoid setup() {\n%s}\n\nvoid loop() {\n%s}\n", (yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));
        free((yyvsp[-2].str)); free((yyvsp[-1].str)); free((yyvsp[0].str));
    }
#line 1252 "linguagem.tab.c"
    break;

  case 3: /* declaracoes: %empty  */
#line 84 "linguagem.y"
    { (yyval.str) = strdup(""); }
#line 1258 "linguagem.tab.c"
    break;

  case 4: /* declaracoes: declaracoes declaracao  */
#line 86 "linguagem.y"
    { 
        char* temp = (char*) malloc(strlen((yyvsp[-1].str)) + strlen((yyvsp[0].str)) + 1);
        strcpy(temp, (yyvsp[-1].str));
        strcat(temp, (yyvsp[0].str));
        free((yyvsp[-1].str)); free((yyvsp[0].str));
        (yyval.str) = temp;
    }
#line 1270 "linguagem.tab.c"
    break;

  case 5: /* declaracao: VAR tipo DOIS_PONTOS lista_ids PONTO_E_VIRGULA  */
#line 97 "linguagem.y"
    { 
        char* buffer = (char*) malloc(strlen((yyvsp[-3].str)) + strlen((yyvsp[-1].str)) + 4);
        sprintf(buffer, "%s %s;\n", (yyvsp[-3].str), (yyvsp[-1].str));
        char *ids = strdup((yyvsp[-1].str));
        char *token = strtok(ids, ", ");
        while (token != NULL) {
            declare_variable(token, (yyvsp[-3].str));
            token = strtok(NULL, ", ");
        }
        free(ids);
        free((yyvsp[-3].str)); free((yyvsp[-1].str));
        (yyval.str) = buffer;
    }
#line 1288 "linguagem.tab.c"
    break;

  case 6: /* tipo: INTEIRO  */
#line 112 "linguagem.y"
              { (yyval.str) = strdup("int"); }
#line 1294 "linguagem.tab.c"
    break;

  case 7: /* tipo: BOOLEANO  */
#line 113 "linguagem.y"
             { (yyval.str) = strdup("bool"); }
#line 1300 "linguagem.tab.c"
    break;

  case 8: /* tipo: TEXTO  */
#line 114 "linguagem.y"
             { (yyval.str) = strdup("String"); }
#line 1306 "linguagem.tab.c"
    break;

  case 9: /* lista_ids: IDENTIFICADOR  */
#line 118 "linguagem.y"
    { (yyval.str) = strdup((yyvsp[0].str)); free((yyvsp[0].str)); }
#line 1312 "linguagem.tab.c"
    break;

  case 10: /* lista_ids: lista_ids VIRGULA IDENTIFICADOR  */
#line 120 "linguagem.y"
    { 
        char* temp = (char*) malloc(strlen((yyvsp[-2].str)) + strlen((yyvsp[0].str)) + 3);
        sprintf(temp, "%s, %s", (yyvsp[-2].str), (yyvsp[0].str));
        free((yyvsp[-2].str)); free((yyvsp[0].str));
        (yyval.str) = temp;
    }
#line 1323 "linguagem.tab.c"
    break;

  case 11: /* config: CONFIG bloco_config FIM  */
#line 130 "linguagem.y"
    { (yyval.str) = (yyvsp[-1].str); }
#line 1329 "linguagem.tab.c"
    break;

  case 12: /* bloco_config: %empty  */
#line 134 "linguagem.y"
    { (yyval.str) = strdup(""); }
#line 1335 "linguagem.tab.c"
    break;

  case 13: /* bloco_config: bloco_config comando  */
#line 136 "linguagem.y"
    { 
        char* temp = (char*) malloc(strlen((yyvsp[-1].str)) + strlen((yyvsp[0].str)) + 1);
        strcpy(temp, (yyvsp[-1].str));
        strcat(temp, (yyvsp[0].str));
        free((yyvsp[-1].str)); free((yyvsp[0].str));
        (yyval.str) = temp;
    }
#line 1347 "linguagem.tab.c"
    break;

  case 14: /* repita: REPITA bloco_repita FIM  */
#line 147 "linguagem.y"
    { (yyval.str) = (yyvsp[-1].str); }
#line 1353 "linguagem.tab.c"
    break;

  case 15: /* bloco_repita: %empty  */
#line 151 "linguagem.y"
    { (yyval.str) = strdup(""); }
#line 1359 "linguagem.tab.c"
    break;

  case 16: /* bloco_repita: bloco_repita comando  */
#line 153 "linguagem.y"
    { 
        char* temp = (char*) malloc(strlen((yyvsp[-1].str)) + strlen((yyvsp[0].str)) + 1);
        strcpy(temp, (yyvsp[-1].str));
        strcat(temp, (yyvsp[0].str));
        free((yyvsp[-1].str)); free((yyvsp[0].str));
        (yyval.str) = temp;
    }
#line 1371 "linguagem.tab.c"
    break;

  case 17: /* comando: IDENTIFICADOR IGUALDADE NUM PONTO_E_VIRGULA  */
#line 165 "linguagem.y"
    { 
        check_variable((yyvsp[-3].str));
        asprintf(&(yyval.str), "%s = %d;\n", (yyvsp[-3].str), (yyvsp[-1].num));
    }
#line 1380 "linguagem.tab.c"
    break;

  case 18: /* comando: IDENTIFICADOR IGUALDADE STRING PONTO_E_VIRGULA  */
#line 170 "linguagem.y"
    { 
        check_variable((yyvsp[-3].str));
        asprintf(&(yyval.str), "%s = %s;\n", (yyvsp[-3].str), (yyvsp[-1].str));
    }
#line 1389 "linguagem.tab.c"
    break;

  case 19: /* comando: CONECTAR_WIFI IDENTIFICADOR IDENTIFICADOR PONTO_E_VIRGULA  */
#line 175 "linguagem.y"
    {
        check_variable((yyvsp[-2].str));
        check_variable((yyvsp[-1].str));
        asprintf(&(yyval.str), 
            "WiFi.begin(%s.c_str(), %s.c_str());\n"
            "while (WiFi.status() != WL_CONNECTED) {\n"
            "    delay(500);\n"
            "    Serial.println(\"Conectando ao WiFi...\");\n"
            "}\n"
            "Serial.println(\"Conectado ao WiFi!\");\n",
            (yyvsp[-2].str), (yyvsp[-1].str));
    }
#line 1406 "linguagem.tab.c"
    break;

  case 20: /* comando: AJUSTAR_PWM IDENTIFICADOR COM VALOR IDENTIFICADOR PONTO_E_VIRGULA  */
#line 188 "linguagem.y"
    {
        check_variable((yyvsp[-4].str));  
        check_variable((yyvsp[-1].str)); 
        asprintf(&(yyval.str), "ledcWrite(%s, %s);\n", (yyvsp[-4].str), (yyvsp[-1].str)); 
    }
#line 1416 "linguagem.tab.c"
    break;

  case 21: /* comando: AJUSTAR_PWM IDENTIFICADOR COM VALOR NUM PONTO_E_VIRGULA  */
#line 194 "linguagem.y"
    {
        check_variable((yyvsp[-4].str));  
        asprintf(&(yyval.str), "ledcWrite(%s, %d);\n", (yyvsp[-4].str), (yyvsp[-1].num)); 
    }
#line 1425 "linguagem.tab.c"
    break;

  case 22: /* comando: CONFIGURAR_PWM IDENTIFICADOR COM FREQUENCIA NUM RESOLUCAO NUM PONTO_E_VIRGULA  */
#line 199 "linguagem.y"
    { 
        check_variable((yyvsp[-6].str));
        asprintf(&(yyval.str), "ledcSetup(%s, %d, %d);\nledcAttachPin(%s, %s);", 
                (yyvsp[-6].str), (yyvsp[-3].num), (yyvsp[-1].num), (yyvsp[-6].str), (yyvsp[-6].str)); 
    }
#line 1435 "linguagem.tab.c"
    break;

  case 23: /* comando: CONFIGURAR IDENTIFICADOR COMO SAIDA PONTO_E_VIRGULA  */
#line 205 "linguagem.y"
    {
        check_variable((yyvsp[-3].str));
        asprintf(&(yyval.str), "pinMode(%s, OUTPUT);\n", (yyvsp[-3].str));
    }
#line 1444 "linguagem.tab.c"
    break;

  case 24: /* comando: CONFIGURAR IDENTIFICADOR COMO ENTRADA PONTO_E_VIRGULA  */
#line 210 "linguagem.y"
    {
        check_variable((yyvsp[-3].str));
        asprintf(&(yyval.str), "pinMode(%s, INPUT);\n", (yyvsp[-3].str));
    }
#line 1453 "linguagem.tab.c"
    break;

  case 25: /* comando: LIGAR IDENTIFICADOR PONTO_E_VIRGULA  */
#line 215 "linguagem.y"
    {
        check_variable((yyvsp[-1].str));
        asprintf(&(yyval.str),"digitalWrite(%s, HIGH);\n", (yyvsp[-1].str));
    }
#line 1462 "linguagem.tab.c"
    break;

  case 26: /* comando: DESLIGAR IDENTIFICADOR PONTO_E_VIRGULA  */
#line 220 "linguagem.y"
    {
        check_variable((yyvsp[-1].str));
        asprintf(&(yyval.str), "digitalWrite(%s, LOW);\n", (yyvsp[-1].str));
    }
#line 1471 "linguagem.tab.c"
    break;

  case 27: /* comando: ESPERAR NUM PONTO_E_VIRGULA  */
#line 225 "linguagem.y"
    {
        asprintf(&(yyval.str), "delay(%d);\n", (yyvsp[-1].num));
    }
#line 1479 "linguagem.tab.c"
    break;

  case 28: /* comando: IDENTIFICADOR IGUALDADE LER_DIGITAL IDENTIFICADOR PONTO_E_VIRGULA  */
#line 229 "linguagem.y"
    {
        check_variable((yyvsp[-4].str));
        check_variable((yyvsp[-1].str));
        asprintf(&(yyval.str), "%s = digitalRead(%s);\n", (yyvsp[-4].str), (yyvsp[-1].str));
    }
#line 1489 "linguagem.tab.c"
    break;

  case 29: /* comando: IDENTIFICADOR IGUALDADE LER_ANALOGICO IDENTIFICADOR PONTO_E_VIRGULA  */
#line 235 "linguagem.y"
    {
        check_variable((yyvsp[-4].str));
        check_variable((yyvsp[-1].str));
        asprintf(&(yyval.str), "%s = analogRead(%s);\n", (yyvsp[-4].str), (yyvsp[-1].str));
    }
#line 1499 "linguagem.tab.c"
    break;

  case 30: /* comando: CONFIGURAR_SERIAL NUM PONTO_E_VIRGULA  */
#line 241 "linguagem.y"
    {
        asprintf(&(yyval.str), "Serial.begin(%d);\n", (yyvsp[-1].num));
    }
#line 1507 "linguagem.tab.c"
    break;

  case 31: /* comando: ESCREVER_SERIAL STRING PONTO_E_VIRGULA  */
#line 245 "linguagem.y"
    {
        asprintf(&(yyval.str), "Serial.println(%s);\n", (yyvsp[-1].str));
    }
#line 1515 "linguagem.tab.c"
    break;

  case 32: /* comando: IDENTIFICADOR IGUALDADE LER_SERIAL PONTO_E_VIRGULA  */
#line 249 "linguagem.y"
    {
        check_variable((yyvsp[-3].str));
        asprintf(&(yyval.str), "%s = Serial.readString();\n", (yyvsp[-3].str));
    }
#line 1524 "linguagem.tab.c"
    break;

  case 33: /* comando: SE condicao ENTAO bloco_cmd senao_cmd_opt FIM  */
#line 254 "linguagem.y"
    {
        if (strlen((yyvsp[-1].str)) > 0) {
            asprintf(&(yyval.str), "if (%s) {\n%s} else {\n%s}\n", (yyvsp[-4].str), (yyvsp[-2].str), (yyvsp[-1].str));
        } else {
            asprintf(&(yyval.str), "if (%s) {\n%s}\n", (yyvsp[-4].str), (yyvsp[-2].str));
        }
    }
#line 1536 "linguagem.tab.c"
    break;

  case 34: /* comando: ENQUANTO bloco_cmd FIM  */
#line 262 "linguagem.y"
    {
        asprintf(&(yyval.str), "while (true) {\n%s}\n", (yyvsp[-1].str));
    }
#line 1544 "linguagem.tab.c"
    break;

  case 35: /* condicao: operando comparador operando  */
#line 270 "linguagem.y"
    { 
        asprintf(&(yyval.str), "%s %s %s", (yyvsp[-2].str), (yyvsp[-1].str), (yyvsp[0].str));
    }
#line 1552 "linguagem.tab.c"
    break;

  case 36: /* operando: IDENTIFICADOR  */
#line 278 "linguagem.y"
    { 
        check_variable((yyvsp[0].str)); 
        (yyval.str) = (yyvsp[0].str); 
    }
#line 1561 "linguagem.tab.c"
    break;

  case 37: /* operando: NUM  */
#line 283 "linguagem.y"
    { 
        char temp[32];
        sprintf(temp, "%d", (yyvsp[0].num));
        (yyval.str) = strdup(temp);
    }
#line 1571 "linguagem.tab.c"
    break;

  case 38: /* comparador: IGUAL  */
#line 292 "linguagem.y"
          { (yyval.str) = strdup("=="); }
#line 1577 "linguagem.tab.c"
    break;

  case 39: /* comparador: DIFERENTE  */
#line 293 "linguagem.y"
                { (yyval.str) = strdup("!="); }
#line 1583 "linguagem.tab.c"
    break;

  case 40: /* comparador: MENOR_IGUAL  */
#line 294 "linguagem.y"
                  { (yyval.str) = strdup("<="); }
#line 1589 "linguagem.tab.c"
    break;

  case 41: /* comparador: MAIOR_IGUAL  */
#line 295 "linguagem.y"
                  { (yyval.str) = strdup(">="); }
#line 1595 "linguagem.tab.c"
    break;

  case 42: /* comparador: MENOR  */
#line 296 "linguagem.y"
            { (yyval.str) = strdup("<"); }
#line 1601 "linguagem.tab.c"
    break;

  case 43: /* comparador: MAIOR  */
#line 297 "linguagem.y"
            { (yyval.str) = strdup(">"); }
#line 1607 "linguagem.tab.c"
    break;

  case 44: /* bloco_cmd: %empty  */
#line 302 "linguagem.y"
    { (yyval.str) = strdup(""); }
#line 1613 "linguagem.tab.c"
    break;

  case 45: /* bloco_cmd: bloco_cmd comando  */
#line 304 "linguagem.y"
    { 
        char* temp = (char*) malloc(strlen((yyvsp[-1].str)) + strlen((yyvsp[0].str)) + 1);
        strcpy(temp, (yyvsp[-1].str));
        strcat(temp, (yyvsp[0].str));
        free((yyvsp[-1].str)); free((yyvsp[0].str));
        (yyval.str) = temp;
    }
#line 1625 "linguagem.tab.c"
    break;

  case 46: /* senao_cmd_opt: SENAO bloco_cmd  */
#line 315 "linguagem.y"
                    { (yyval.str) = (yyvsp[0].str); }
#line 1631 "linguagem.tab.c"
    break;

  case 47: /* senao_cmd_opt: %empty  */
#line 316 "linguagem.y"
                  { (yyval.str) = strdup(""); }
#line 1637 "linguagem.tab.c"
    break;


#line 1641 "linguagem.tab.c"

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

#line 319 "linguagem.y"


void yyerror(const char *s) {
    error_count++;
    fprintf(stderr, "Erro sintatico na linha %d: %s\n", yylineno, s);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: %s arquivo_entrada\n", argv[0]);
        return 1;
    }
    
    yyin = fopen(argv[1], "r");
    if (!yyin) {
        perror("Erro ao abrir arquivo");
        return 1;
    }
    
    int parse_result = yyparse();
    fclose(yyin);
    
    if (error_count > 0) {
        fprintf(stderr, "Compilacao finalizada com %d erro(s).\n", error_count);
        return 1;
    }
    return parse_result;
}
