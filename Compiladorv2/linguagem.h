#ifndef YY_parse_h_included
#define YY_parse_h_included
/*#define YY_USE_CLASS 
*/
#line 1 "/usr/share/bison++/bison.h"
/* before anything */
#ifdef c_plusplus
 #ifndef __cplusplus
  #define __cplusplus
 #endif
#endif


 #line 8 "/usr/share/bison++/bison.h"

#line 118 "linguagem.y"
typedef union {
    char* str;
    int num;
    Node *node;
} yy_parse_stype;
#define YY_parse_STYPE yy_parse_stype
#ifndef YY_USE_CLASS
#define YYSTYPE yy_parse_stype
#endif

#line 21 "/usr/share/bison++/bison.h"
 /* %{ and %header{ and %union, during decl */
#ifndef YY_parse_COMPATIBILITY
 #ifndef YY_USE_CLASS
  #define  YY_parse_COMPATIBILITY 1
 #else
  #define  YY_parse_COMPATIBILITY 0
 #endif
#endif

#if YY_parse_COMPATIBILITY != 0
/* backward compatibility */
 #ifdef YYLTYPE
  #ifndef YY_parse_LTYPE
   #define YY_parse_LTYPE YYLTYPE
/* WARNING obsolete !!! user defined YYLTYPE not reported into generated header */
/* use %define LTYPE */
  #endif
 #endif
/*#ifdef YYSTYPE*/
  #ifndef YY_parse_STYPE
   #define YY_parse_STYPE YYSTYPE
  /* WARNING obsolete !!! user defined YYSTYPE not reported into generated header */
   /* use %define STYPE */
  #endif
/*#endif*/
 #ifdef YYDEBUG
  #ifndef YY_parse_DEBUG
   #define  YY_parse_DEBUG YYDEBUG
   /* WARNING obsolete !!! user defined YYDEBUG not reported into generated header */
   /* use %define DEBUG */
  #endif
 #endif 
 /* use goto to be compatible */
 #ifndef YY_parse_USE_GOTO
  #define YY_parse_USE_GOTO 1
 #endif
#endif

/* use no goto to be clean in C++ */
#ifndef YY_parse_USE_GOTO
 #define YY_parse_USE_GOTO 0
#endif

#ifndef YY_parse_PURE

 #line 65 "/usr/share/bison++/bison.h"

#line 65 "/usr/share/bison++/bison.h"
/* YY_parse_PURE */
#endif


 #line 68 "/usr/share/bison++/bison.h"

#line 68 "/usr/share/bison++/bison.h"
/* prefix */

#ifndef YY_parse_DEBUG

 #line 71 "/usr/share/bison++/bison.h"

#line 71 "/usr/share/bison++/bison.h"
/* YY_parse_DEBUG */
#endif

#ifndef YY_parse_LSP_NEEDED

 #line 75 "/usr/share/bison++/bison.h"

#line 75 "/usr/share/bison++/bison.h"
 /* YY_parse_LSP_NEEDED*/
#endif

/* DEFAULT LTYPE*/
#ifdef YY_parse_LSP_NEEDED
 #ifndef YY_parse_LTYPE
  #ifndef BISON_YYLTYPE_ISDECLARED
   #define BISON_YYLTYPE_ISDECLARED
typedef
  struct yyltype
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype;
  #endif

  #define YY_parse_LTYPE yyltype
 #endif
#endif

/* DEFAULT STYPE*/
#ifndef YY_parse_STYPE
 #define YY_parse_STYPE int
#endif

/* DEFAULT MISCELANEOUS */
#ifndef YY_parse_PARSE
 #define YY_parse_PARSE yyparse
#endif

#ifndef YY_parse_LEX
 #define YY_parse_LEX yylex
#endif

#ifndef YY_parse_LVAL
 #define YY_parse_LVAL yylval
#endif

#ifndef YY_parse_LLOC
 #define YY_parse_LLOC yylloc
#endif

#ifndef YY_parse_CHAR
 #define YY_parse_CHAR yychar
#endif

#ifndef YY_parse_NERRS
 #define YY_parse_NERRS yynerrs
#endif

#ifndef YY_parse_DEBUG_FLAG
 #define YY_parse_DEBUG_FLAG yydebug
#endif

#ifndef YY_parse_ERROR
 #define YY_parse_ERROR yyerror
#endif

#ifndef YY_parse_PARSE_PARAM
 #ifndef __STDC__
  #ifndef __cplusplus
   #ifndef YY_USE_CLASS
    #define YY_parse_PARSE_PARAM
    #ifndef YY_parse_PARSE_PARAM_DEF
     #define YY_parse_PARSE_PARAM_DEF
    #endif
   #endif
  #endif
 #endif
 #ifndef YY_parse_PARSE_PARAM
  #define YY_parse_PARSE_PARAM void
 #endif
#endif

/* TOKEN C */
#ifndef YY_USE_CLASS

 #ifndef YY_parse_PURE
  #ifndef yylval
   extern YY_parse_STYPE YY_parse_LVAL;
  #else
   #if yylval != YY_parse_LVAL
    extern YY_parse_STYPE YY_parse_LVAL;
   #else
    #warning "Namespace conflict, disabling some functionality (bison++ only)"
   #endif
  #endif
 #endif


 #line 169 "/usr/share/bison++/bison.h"
#define	NUM	258
#define	STRING	259
#define	IDENTIFICADOR	260
#define	CONFIG	261
#define	REPITA	262
#define	FIM	263
#define	VAR	264
#define	INTEIRO	265
#define	BOOLEANO	266
#define	TEXTO	267
#define	CONFIGURAR	268
#define	COMO	269
#define	SAIDA	270
#define	ENTRADA	271
#define	LIGAR	272
#define	DESLIGAR	273
#define	CONECTAR_WIFI	274
#define	CONFIGURAR_SERIAL	275
#define	ESCREVER_SERIAL	276
#define	LER_SERIAL	277
#define	ENVIAR_HTTP	278
#define	ESPERAR	279
#define	LER_DIGITAL	280
#define	LER_ANALOGICO	281
#define	CONFIGURAR_PWM	282
#define	FREQUENCIA	283
#define	RESOLUCAO	284
#define	AJUSTAR_PWM	285
#define	VALOR	286
#define	COM	287
#define	SE	288
#define	ENTRADA_PULLDOWN	289
#define	SENAO	290
#define	ENTAO	291
#define	ENQUANTO	292
#define	IGUAL	293
#define	DIFERENTE	294
#define	MENOR_IGUAL	295
#define	MAIOR_IGUAL	296
#define	MENOR	297
#define	MAIOR	298
#define	SOMA	299
#define	SUBTRACAO	300
#define	MULTIPLICACAO	301
#define	DIVISAO	302
#define	IGUALDADE	303
#define	DOIS_PONTOS	304
#define	VIRGULA	305
#define	PONTO_E_VIRGULA	306
#define	ID	307


#line 169 "/usr/share/bison++/bison.h"
 /* #defines token */
/* after #define tokens, before const tokens S5*/
#else
 #ifndef YY_parse_CLASS
  #define YY_parse_CLASS parse
 #endif

 #ifndef YY_parse_INHERIT
  #define YY_parse_INHERIT
 #endif

 #ifndef YY_parse_MEMBERS
  #define YY_parse_MEMBERS 
 #endif

 #ifndef YY_parse_LEX_BODY
  #define YY_parse_LEX_BODY  
 #endif

 #ifndef YY_parse_ERROR_BODY
  #define YY_parse_ERROR_BODY  
 #endif

 #ifndef YY_parse_CONSTRUCTOR_PARAM
  #define YY_parse_CONSTRUCTOR_PARAM
 #endif
 /* choose between enum and const */
 #ifndef YY_parse_USE_CONST_TOKEN
  #define YY_parse_USE_CONST_TOKEN 0
  /* yes enum is more compatible with flex,  */
  /* so by default we use it */ 
 #endif
 #if YY_parse_USE_CONST_TOKEN != 0
  #ifndef YY_parse_ENUM_TOKEN
   #define YY_parse_ENUM_TOKEN yy_parse_enum_token
  #endif
 #endif

class YY_parse_CLASS YY_parse_INHERIT
{
public: 
 #if YY_parse_USE_CONST_TOKEN != 0
  /* static const int token ... */
  
 #line 212 "/usr/share/bison++/bison.h"
static const int NUM;
static const int STRING;
static const int IDENTIFICADOR;
static const int CONFIG;
static const int REPITA;
static const int FIM;
static const int VAR;
static const int INTEIRO;
static const int BOOLEANO;
static const int TEXTO;
static const int CONFIGURAR;
static const int COMO;
static const int SAIDA;
static const int ENTRADA;
static const int LIGAR;
static const int DESLIGAR;
static const int CONECTAR_WIFI;
static const int CONFIGURAR_SERIAL;
static const int ESCREVER_SERIAL;
static const int LER_SERIAL;
static const int ENVIAR_HTTP;
static const int ESPERAR;
static const int LER_DIGITAL;
static const int LER_ANALOGICO;
static const int CONFIGURAR_PWM;
static const int FREQUENCIA;
static const int RESOLUCAO;
static const int AJUSTAR_PWM;
static const int VALOR;
static const int COM;
static const int SE;
static const int ENTRADA_PULLDOWN;
static const int SENAO;
static const int ENTAO;
static const int ENQUANTO;
static const int IGUAL;
static const int DIFERENTE;
static const int MENOR_IGUAL;
static const int MAIOR_IGUAL;
static const int MENOR;
static const int MAIOR;
static const int SOMA;
static const int SUBTRACAO;
static const int MULTIPLICACAO;
static const int DIVISAO;
static const int IGUALDADE;
static const int DOIS_PONTOS;
static const int VIRGULA;
static const int PONTO_E_VIRGULA;
static const int ID;


#line 212 "/usr/share/bison++/bison.h"
 /* decl const */
 #else
  enum YY_parse_ENUM_TOKEN { YY_parse_NULL_TOKEN=0
  
 #line 215 "/usr/share/bison++/bison.h"
	,NUM=258
	,STRING=259
	,IDENTIFICADOR=260
	,CONFIG=261
	,REPITA=262
	,FIM=263
	,VAR=264
	,INTEIRO=265
	,BOOLEANO=266
	,TEXTO=267
	,CONFIGURAR=268
	,COMO=269
	,SAIDA=270
	,ENTRADA=271
	,LIGAR=272
	,DESLIGAR=273
	,CONECTAR_WIFI=274
	,CONFIGURAR_SERIAL=275
	,ESCREVER_SERIAL=276
	,LER_SERIAL=277
	,ENVIAR_HTTP=278
	,ESPERAR=279
	,LER_DIGITAL=280
	,LER_ANALOGICO=281
	,CONFIGURAR_PWM=282
	,FREQUENCIA=283
	,RESOLUCAO=284
	,AJUSTAR_PWM=285
	,VALOR=286
	,COM=287
	,SE=288
	,ENTRADA_PULLDOWN=289
	,SENAO=290
	,ENTAO=291
	,ENQUANTO=292
	,IGUAL=293
	,DIFERENTE=294
	,MENOR_IGUAL=295
	,MAIOR_IGUAL=296
	,MENOR=297
	,MAIOR=298
	,SOMA=299
	,SUBTRACAO=300
	,MULTIPLICACAO=301
	,DIVISAO=302
	,IGUALDADE=303
	,DOIS_PONTOS=304
	,VIRGULA=305
	,PONTO_E_VIRGULA=306
	,ID=307


#line 215 "/usr/share/bison++/bison.h"
 /* enum token */
     }; /* end of enum declaration */
 #endif
public:
 int YY_parse_PARSE(YY_parse_PARSE_PARAM);
 virtual void YY_parse_ERROR(char *msg) YY_parse_ERROR_BODY;
 #ifdef YY_parse_PURE
  #ifdef YY_parse_LSP_NEEDED
   virtual int  YY_parse_LEX(YY_parse_STYPE *YY_parse_LVAL,YY_parse_LTYPE *YY_parse_LLOC) YY_parse_LEX_BODY;
  #else
   virtual int  YY_parse_LEX(YY_parse_STYPE *YY_parse_LVAL) YY_parse_LEX_BODY;
  #endif
 #else
  virtual int YY_parse_LEX() YY_parse_LEX_BODY;
  YY_parse_STYPE YY_parse_LVAL;
  #ifdef YY_parse_LSP_NEEDED
   YY_parse_LTYPE YY_parse_LLOC;
  #endif
  int YY_parse_NERRS;
  int YY_parse_CHAR;
 #endif
 #if YY_parse_DEBUG != 0
  public:
   int YY_parse_DEBUG_FLAG;	/*  nonzero means print parse trace	*/
 #endif
public:
 YY_parse_CLASS(YY_parse_CONSTRUCTOR_PARAM);
public:
 YY_parse_MEMBERS 
};
/* other declare folow */
#endif


#if YY_parse_COMPATIBILITY != 0
 /* backward compatibility */
 /* Removed due to bison problems
 /#ifndef YYSTYPE
 / #define YYSTYPE YY_parse_STYPE
 /#endif*/

 #ifndef YYLTYPE
  #define YYLTYPE YY_parse_LTYPE
 #endif
 #ifndef YYDEBUG
  #ifdef YY_parse_DEBUG 
   #define YYDEBUG YY_parse_DEBUG
  #endif
 #endif

#endif
/* END */

 #line 267 "/usr/share/bison++/bison.h"
#endif
