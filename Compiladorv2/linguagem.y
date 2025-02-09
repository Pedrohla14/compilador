%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        fprintf(stderr, "Erro semantico: variavel '%s' nao foi declarada\n", name);
    }
}

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
        printf("#include <Arduino.h>\n");
        printf("#include <WiFi.h>\n\n");  // Adiciona o include do WiFi.h
        printf("%s\n\nvoid setup() {\n%s}\n\nvoid loop() {\n%s}\n", $1, $2, $3);
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
        char *ids = strdup($4);
        char *token = strtok(ids, ", ");
        while (token != NULL) {
            declare_variable(token, $2);
            token = strtok(NULL, ", ");
        }
        free(ids);
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
        check_variable($1);
        $$ = (char*) malloc(50);  
        sprintf($$, "%s = %d;\n", $1, $3);
        free($1);
    }
    | IDENTIFICADOR IGUALDADE STRING PONTO_E_VIRGULA 
    { 
        check_variable($1);
        $$ = (char*) malloc(strlen($1) + strlen($3) + 4);
        sprintf($$, "%s = %s;\n", $1, $3);  // Atribui a string diretamente
        free($1); free($3);
    }
   
    | CONECTAR_WIFI IDENTIFICADOR IDENTIFICADOR PONTO_E_VIRGULA
    {
        check_variable($2);
        check_variable($3);
        asprintf(&$$, 
            "WiFi.begin(%s.c_str(), %s.c_str());\n"
            "while (WiFi.status() != WL_CONNECTED) {\n"
            "    delay(500);\n"
            "    Serial.println(\"Conectando ao WiFi...\");\n"
            "}\n"
            "Serial.println(\"Conectado ao WiFi!\");\n",
            $2, $3);
        free($2); 
        free($3);
    }
    |AJUSTAR_PWM IDENTIFICADOR COM VALOR IDENTIFICADOR PONTO_E_VIRGULA {
    check_variable($2);  
    check_variable($5); 
    asprintf(&$$, "ledcWrite(%s, %s);\n", $2, $5); 
    free($2);  
    free($5);  
    }
    | AJUSTAR_PWM IDENTIFICADOR COM VALOR NUM PONTO_E_VIRGULA {
        check_variable($2);  
        asprintf(&$$, "ledcWrite(%s, %d);\n", $2, $5); 
        free($2);  
    }
    | CONFIGURAR_PWM IDENTIFICADOR COM FREQUENCIA NUM RESOLUCAO NUM PONTO_E_VIRGULA
    { 
        check_variable($2);
        $$ = (char*) malloc(100);  
        sprintf($$, "ledcSetup(%s, %d, %d);\nledcAttachPin(%s, %s);", 
                $2, $5, $7, $2, $2); 
        free($2);  
    }
    | CONFIGURAR IDENTIFICADOR COMO SAIDA PONTO_E_VIRGULA 
    {
        check_variable($2);
        $$ = (char*) malloc(50);  
        sprintf($$, "pinMode(%s, OUTPUT);\n", $2);
        free($2);
    }
    | CONFIGURAR IDENTIFICADOR COMO ENTRADA PONTO_E_VIRGULA 
    {
        check_variable($2);
        $$ = (char*) malloc(50);  
        sprintf($$, "pinMode(%s, INPUT);\n", $2);
        free($2);
    }
    | LIGAR IDENTIFICADOR PONTO_E_VIRGULA 
    {
        check_variable($2);
        $$ = (char*) malloc(50);  
        sprintf($$, "digitalWrite(%s, HIGH);\n", $2);
        free($2);
    }
    | DESLIGAR IDENTIFICADOR PONTO_E_VIRGULA 
    {
        check_variable($2);
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
        check_variable($1);
        check_variable($4);
        asprintf(&$$, "%s = digitalRead(%s);\n", $1, $4);
        free($1); free($4);
    }
    | IDENTIFICADOR IGUALDADE LER_ANALOGICO IDENTIFICADOR PONTO_E_VIRGULA 
    {
        check_variable($1);
        check_variable($4);
        asprintf(&$$, "%s = analogRead(%s);\n", $1, $4);
        free($1); free($4);
    }

    
    |CONFIGURAR_SERIAL NUM PONTO_E_VIRGULA
    {
        $$ = (char*) malloc(50);
        sprintf($$, "Serial.begin(%d);\n", $2);  // Configura o baud rate
    }
    | ESCREVER_SERIAL STRING PONTO_E_VIRGULA
    {
        $$ = (char*) malloc(100);
        sprintf($$, "Serial.println(%s);\n", $2);  // Envia mensagem pela serial
    }
    | IDENTIFICADOR IGUALDADE LER_SERIAL PONTO_E_VIRGULA
    {
        check_variable($1);
        $$ = (char*) malloc(50);
        sprintf($$, "%s = Serial.readString();\n", $1);  // Lê mensagem da serial
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