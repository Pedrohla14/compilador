%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern FILE *yyin;
void yyerror(const char *s);
int yylex();

%}

%union {
    char* str;
    int num;
}

%token <num> NUM
%token <str> STRING IDENTIFICADOR
%token CONFIG REPITA FIM VAR INTEIRO BOOLEANO TEXTO
%token CONFIGURAR COMO SAIDA ENTRADA LIGAR DESLIGAR
%token CONECTAR_WIFI CONFIGURAR_SERIAL ESCREVER_SERIAL LER_SERIAL
%token ENVIAR_HTTP ESPERAR LER_DIGITAL LER_ANALOGICO
%token CONFIGURAR_PWM FREQUENCIA RESOLUCAO AJUSTAR_PWM VALOR COM
%token SE ENTRADA_PULLDOWN SENAO ENTAO ENQUANTO
%token IGUAL DIFERENTE MENOR_IGUAL MAIOR_IGUAL MENOR MAIOR
%token SOMA SUBTRACAO MULTIPLICACAO DIVISAO
%token IGUALDADE DOIS_PONTOS VIRGULA PONTO_E_VIRGULA

%type <str> programa declaracoes declaracao tipo lista_ids config bloco_config repita bloco_repita comando

%start programa

%%

programa:
    declaracoes config repita
    { 
        printf("#include <Arduino.h>\n\n%s\n\nvoid setup() {\n%s}\n\nvoid loop() {\n%s}\n", $1, $2, $3);
        free($1); free($2); free($3);
    }
    ;

declaracoes:
    { $$ = strdup(""); }
    | declaracoes declaracao 
    { 
        char* temp = (char*) malloc(strlen($1) + strlen($2) + 1);
        strcpy(temp, $1);
        strcat(temp, $2);
        free($1); free($2);
        $$ = temp;
    }
    ;

declaracao:
    VAR tipo DOIS_PONTOS lista_ids PONTO_E_VIRGULA
    {
        char* buffer = (char*) malloc(strlen($2) + strlen($4) + 4);
        sprintf(buffer, "%s %s;\n", $2, $4);
        free($2); free($4);
        $$ = buffer;
    }
    ;

tipo:
    INTEIRO   { $$ = strdup("int"); }
    | BOOLEANO { $$ = strdup("bool"); }
    | TEXTO    { $$ = strdup("String"); }
    ;

lista_ids:
    IDENTIFICADOR 
    { $$ = strdup($1); free($1); }
    | lista_ids VIRGULA IDENTIFICADOR 
    { 
        char* temp = (char*) malloc(strlen($1) + strlen($3) + 3);
        sprintf(temp, "%s, %s", $1, $3);
        free($1); free($3);
        $$ = temp;
    }
    ;

config:
    CONFIG bloco_config FIM 
    { $$ = $2; }
    ;

bloco_config:
    { $$ = strdup(""); }
    | bloco_config comando 
    { 
        char* temp = (char*) malloc(strlen($1) + strlen($2) + 1);
        strcpy(temp, $1);
        strcat(temp, $2);
        free($1); free($2);
        $$ = temp;
    }
    ;

repita:
    REPITA bloco_repita FIM 
    { $$ = $2; }
    ;

bloco_repita:
    { $$ = strdup(""); }
    | bloco_repita comando 
    { 
        char* temp = (char*) malloc(strlen($1) + strlen($2) + 1);
        strcpy(temp, $1);
        strcat(temp, $2);
        free($1); free($2);
        $$ = temp;
    }
    ;

comando:
    IDENTIFICADOR IGUALDADE NUM PONTO_E_VIRGULA 
    { 
        $$ = (char*) malloc(50);  
        sprintf($$, "%s = %d;\n", $1, $3);
        free($1);
    }
    | CONFIGURAR IDENTIFICADOR COMO SAIDA PONTO_E_VIRGULA 
    {
        $$ = (char*) malloc(50);  
        sprintf($$, "pinMode(%s, OUTPUT);\n", $2);
        free($2);
    }
    | CONFIGURAR IDENTIFICADOR COMO ENTRADA PONTO_E_VIRGULA 
    {
        $$ = (char*) malloc(50);  
        sprintf($$, "pinMode(%s, INPUT);\n", $2);
        free($2);
    }
    | LIGAR IDENTIFICADOR PONTO_E_VIRGULA 
    {
        $$ = (char*) malloc(50);  
        sprintf($$, "digitalWrite(%s, HIGH);\n", $2);
        free($2);
    }
    | DESLIGAR IDENTIFICADOR PONTO_E_VIRGULA 
    {
        $$ = (char*) malloc(50);  
        sprintf($$, "digitalWrite(%s, LOW);\n", $2);
        free($2);
    }
    | ESPERAR NUM PONTO_E_VIRGULA 
    {
        $$ = (char*) malloc(50);  
        sprintf($$, "delay(%d);\n", $2);
    }
    | IDENTIFICADOR IGUALDADE LER_DIGITAL IDENTIFICADOR PONTO_E_VIRGULA 
    {
        asprintf(&$$, "%s = digitalRead(%s);\n", $1, $4);
        free($1); free($4);
    }
    | IDENTIFICADOR IGUALDADE LER_ANALOGICO IDENTIFICADOR PONTO_E_VIRGULA 
    {
        asprintf(&$$, "%s = analogRead(%s);\n", $1, $4);
        free($1); free($4);
    }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Erro: %s\n", s);
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
    
    yyparse();
    fclose(yyin);
    return 0;
}
