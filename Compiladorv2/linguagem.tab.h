/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_LINGUAGEM_TAB_H_INCLUDED
# define YY_YY_LINGUAGEM_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    NUM = 258,                     /* NUM  */
    STRING = 259,                  /* STRING  */
    IDENTIFICADOR = 260,           /* IDENTIFICADOR  */
    CONFIG = 261,                  /* CONFIG  */
    REPITA = 262,                  /* REPITA  */
    FIM = 263,                     /* FIM  */
    VAR = 264,                     /* VAR  */
    INTEIRO = 265,                 /* INTEIRO  */
    BOOLEANO = 266,                /* BOOLEANO  */
    TEXTO = 267,                   /* TEXTO  */
    CONFIGURAR = 268,              /* CONFIGURAR  */
    COMO = 269,                    /* COMO  */
    SAIDA = 270,                   /* SAIDA  */
    ENTRADA = 271,                 /* ENTRADA  */
    LIGAR = 272,                   /* LIGAR  */
    DESLIGAR = 273,                /* DESLIGAR  */
    CONECTAR_WIFI = 274,           /* CONECTAR_WIFI  */
    CONFIGURAR_SERIAL = 275,       /* CONFIGURAR_SERIAL  */
    ESCREVER_SERIAL = 276,         /* ESCREVER_SERIAL  */
    LER_SERIAL = 277,              /* LER_SERIAL  */
    ENVIAR_HTTP = 278,             /* ENVIAR_HTTP  */
    ESPERAR = 279,                 /* ESPERAR  */
    LER_DIGITAL = 280,             /* LER_DIGITAL  */
    LER_ANALOGICO = 281,           /* LER_ANALOGICO  */
    CONFIGURAR_PWM = 282,          /* CONFIGURAR_PWM  */
    FREQUENCIA = 283,              /* FREQUENCIA  */
    RESOLUCAO = 284,               /* RESOLUCAO  */
    AJUSTAR_PWM = 285,             /* AJUSTAR_PWM  */
    VALOR = 286,                   /* VALOR  */
    COM = 287,                     /* COM  */
    SE = 288,                      /* SE  */
    ENTRADA_PULLDOWN = 289,        /* ENTRADA_PULLDOWN  */
    SENAO = 290,                   /* SENAO  */
    ENTAO = 291,                   /* ENTAO  */
    ENQUANTO = 292,                /* ENQUANTO  */
    IGUAL = 293,                   /* IGUAL  */
    DIFERENTE = 294,               /* DIFERENTE  */
    MENOR_IGUAL = 295,             /* MENOR_IGUAL  */
    MAIOR_IGUAL = 296,             /* MAIOR_IGUAL  */
    MENOR = 297,                   /* MENOR  */
    MAIOR = 298,                   /* MAIOR  */
    SOMA = 299,                    /* SOMA  */
    SUBTRACAO = 300,               /* SUBTRACAO  */
    MULTIPLICACAO = 301,           /* MULTIPLICACAO  */
    DIVISAO = 302,                 /* DIVISAO  */
    IGUALDADE = 303,               /* IGUALDADE  */
    DOIS_PONTOS = 304,             /* DOIS_PONTOS  */
    VIRGULA = 305,                 /* VIRGULA  */
    PONTO_E_VIRGULA = 306          /* PONTO_E_VIRGULA  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 71 "linguagem.y"

    char* str;
    int num;

#line 120 "linguagem.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_LINGUAGEM_TAB_H_INCLUDED  */
