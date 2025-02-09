%{
#include "linguagem.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void yyerror(const char *s);
%}

%option noyywrap

%%

"config"              { return CONFIG; }
"repita"              { return REPITA; }
"fim"                 { return FIM; }
"var"                 { return VAR; }
"inteiro"             { return INTEIRO; }
"booleano"            { return BOOLEANO; }
"texto"               { return TEXTO; }
"configurar"          { return CONFIGURAR; }
"como"                { return COMO; }
"saida"               { return SAIDA; }
"entrada"             { return ENTRADA; }
"ligar"               { return LIGAR; }
"desligar"            { return DESLIGAR; }
"conectarWifi"        { return CONECTAR_WIFI; }
"configurarSerial"    { return CONFIGURAR_SERIAL; }
"escreverSerial"      { return ESCREVER_SERIAL; }
"lerSerial"           { return LER_SERIAL; }
"enviarHttp"          { return ENVIAR_HTTP; }
"esperar"             { return ESPERAR; }
"lerDigital"          { return LER_DIGITAL; }
"lerAnalogico"        { return LER_ANALOGICO; }
"configurarPWM"       { return CONFIGURAR_PWM; }
"frequencia"          { return FREQUENCIA; }
"resolucao"           { return RESOLUCAO; }
"ajustarPWM"          { return AJUSTAR_PWM; }
"valor"               { return VALOR; }
"com"                 { return COM; }
"se"                  { return SE; }
"entradaPullDown"     { return ENTRADA_PULLDOWN; }
"senao"               { return SENAO; }
"entao"               { return ENTAO; }
"enquanto"            { return ENQUANTO; }
"=="                  { return IGUAL; }
"!="                  { return DIFERENTE; }
"<="                  { return MENOR_IGUAL; }
">="                  { return MAIOR_IGUAL; }
"<"                   { return MENOR; }
">"                   { return MAIOR; }
"+"                   { return SOMA; }
"-"                   { return SUBTRACAO; }
"*"                   { return MULTIPLICACAO; }
"/"                   { return DIVISAO; }
"="                   { return IGUALDADE; }
":"                   { return DOIS_PONTOS; }
","                   { return VIRGULA; }
";"                   { return PONTO_E_VIRGULA; }
[0-9]+                { yylval.num = atoi(yytext); return NUM; }
\"[^\"]*\"            { yylval.str = strdup(yytext); return STRING; }
[a-zA-Z_][a-zA-Z0-9_]* { yylval.str = strdup(yytext); return IDENTIFICADOR; }
[ \t\n]               { /* Ignorar espaços */ }
.                     { yyerror("Caractere inválido"); }

%%