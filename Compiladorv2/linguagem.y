/*
    Extensão .y refere-se a gramática
    - Inclusões de bibliotecas
    - Variáveis globais
    - Estruturas de dados
    - Funções auxiliares
*/
%{
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

void declare_variable(const char *name, const char *type) {
    if (variable_declared(name)) {
        error_count++;
        fprintf(stderr, "Erro semantico na linha %d: variavel '%s' ja foi declarada\n", yylineno, name);
        return;
    }

    Symbol *s = (Symbol *) malloc(sizeof(Symbol));
    s->name = strdup(name);
    s->type = strdup(type);
    s->next = symbol_table;
    symbol_table = s;
}

void check_variable(const char *name) {
    if (!variable_declared(name)) {
        error_count++;
        fprintf(stderr, "Erro semantico na linha %d: variavel '%s' nao foi declarada\n", yylineno, name);
    }
}

/*Inclusao para gerar ATS*/
// Estrutura de um nó da AST
typedef struct Node {
    char *label;           // Nome do nó (ex: "Programa", "Config")
    struct Node **children; // Filhos (lista de nós)
    int num_children;       // Número de filhos
} Node;

// Função para criar um nó
Node* create_node(char *label, int num_children, ...) {
    Node *node = (Node*) malloc(sizeof(Node));
    node->label = strdup(label);
    node->num_children = num_children;
    node->children = (Node**) malloc(num_children * sizeof(Node*));

    va_list args;
    va_start(args, num_children);
    for (int i = 0; i < num_children; i++) {
        node->children[i] = va_arg(args, Node*);
    }
    va_end(args);

    return node;
}

// Função para imprimir a AST
void print_ast(Node *node, int level) {
    if (!node) return;
    for (int i = 0; i < level; i++) printf("  ");
    printf("%s\n", node->label);
    for (int i = 0; i < node->num_children; i++) {
        print_ast(node->children[i], level + 1);
    }
}

// Raiz da AST
Node *syntax_tree = NULL;
%}

extern FILE *yyin;
void yyerror(const char *s);
int yylex();
%} 

%union {
    char* str;
    int num;
    Node *node;
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
/*Inclusão tokens da ATS*/
%token <str> ID CONFIG REPITA
%type <node> programa declaracoes declaracao config repita bloco_cmd comando condicao operando comparador


/* Declaração dos não-terminais com tipo <str> */
%type <str> programa declaracoes declaracao tipo lista_ids config bloco_config repita bloco_repita comando condicao operando comparador bloco_cmd senao_cmd_opt

%start programa
/*Definição da gramática*/
%%

programa:
   declaracoes config repita
    { 
        printf("#include <Arduino.h>\n");
        printf("#include <WiFi.h>\n\n");  /* Inclui o header do WiFi */
        printf("%s\n\nvoid setup() {\n%s}\n\nvoid loop() {\n%s}\n", $1, $2, $3);

        // Construção da AST
        $$ = create_node("Programa", $1, $2, $3);

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
        
        // Construção da AST
        $$ = create_node("Declaracoes", $1, $2);
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
        
        // Construção da AST
        $$ = create_node("Declaracao", create_node("Tipo", $2), create_node("Identificadores", $4));
    }
    ;

tipo:
    INTEIRO   { $$ = create_node("Tipo", "int"); }
  | BOOLEANO { $$ = create_node("Tipo", "bool"); }
  | TEXTO    { $$ = create_node("Tipo", "String"); }
  ;

lista_ids:
    IDENTIFICADOR 
    { $$ = create_node("Identificador", $1); free($1); }
    | lista_ids VIRGULA IDENTIFICADOR 
    { 
        char* temp = (char*) malloc(strlen($1) + strlen($3) + 3);
        sprintf(temp, "%s, %s", $1, $3);
        free($1); free($3);
        
        // Construção da AST
        $$ = create_node("ListaIdentificadores", $1, create_node("Identificador", $3));
    }
    ;

config:
    CONFIG bloco_config FIM 
    { 
        // Construção da AST
        $$ = create_node("Config", $2); 
    }
    ;

bloco_config:
    { $$ = strdup(""); }
    | bloco_config comando 
    { 
        char* temp = (char*) malloc(strlen($1) + strlen($2) + 1);
        strcpy(temp, $1);
        strcat(temp, $2);
        free($1); free($2);
        
        // Construção da AST
        $$ = create_node("BlocoConfig", $1, $2);
    }
    ;

repita:
    REPITA bloco_repita FIM 
    { $$ = create_node("Repita", $2); }
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

        // Construção da AST
        $$ = create_node("BlocoRepita", $1, $2);
    }
    ;

/* Regras para comandos individuais */

comando:
    IDENTIFICADOR IGUALDADE NUM PONTO_E_VIRGULA 
    { 
        check_variable($1);
        asprintf(&$$, "%s = %d;\n", $1, $3);
        $$ = create_node("Atribuicao", $1, $3);
    }
    | IDENTIFICADOR IGUALDADE STRING PONTO_E_VIRGULA 
    { 
        check_variable($1);
        asprintf(&$$, "%s = %s;\n", $1, $3);
        $$ = create_node("Atribuicao", $1, $3);
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

            // Construção da AST
        $$ = create_node("ConectarWiFi", $2, $3);
    }
    | AJUSTAR_PWM IDENTIFICADOR COM VALOR IDENTIFICADOR PONTO_E_VIRGULA 
    {
        check_variable($2);  
        check_variable($5); 
        asprintf(&$$, "ledcWrite(%s, %s);\n", $2, $5); 
        // Construção da AST
        $$ = create_node("AjustarPWM", $2, $5);
    }
    | AJUSTAR_PWM IDENTIFICADOR COM VALOR NUM PONTO_E_VIRGULA 
    {
        check_variable($2);  
        asprintf(&$$, "ledcWrite(%s, %d);\n", $2, $5); 
        // Construção da AST
        $$ = create_node("AjustarPWM", $2, $5);

    }
    | CONFIGURAR_PWM IDENTIFICADOR COM FREQUENCIA NUM RESOLUCAO NUM PONTO_E_VIRGULA
    { 
        check_variable($2);
        asprintf(&$$, "ledcSetup(%s, %d, %d);\nledcAttachPin(%s, %s);", 
                $2, $5, $7, $2, $2); 
        $$ = create_node("AjustarPWM", $2, $5);
    }
    | CONFIGURAR IDENTIFICADOR COMO SAIDA PONTO_E_VIRGULA 
    {
        check_variable($2);
        asprintf(&$$, "pinMode(%s, OUTPUT);\n", $2);
        $$ = create_node("ConfigurarSaida", $2);
    }
    | CONFIGURAR IDENTIFICADOR COMO ENTRADA PONTO_E_VIRGULA 
    {
        check_variable($2);
        asprintf(&$$, "pinMode(%s, INPUT);\n", $2);
        $$ = create_node("ConfigurarEntrada", $2);
    }
    | LIGAR IDENTIFICADOR PONTO_E_VIRGULA 
    {
        check_variable($2);
        asprintf(&$$,"digitalWrite(%s, HIGH);\n", $2);
        $$ = create_node("Ligar", $2);
    }
    | DESLIGAR IDENTIFICADOR PONTO_E_VIRGULA 
    {
        check_variable($2);
        asprintf(&$$, "digitalWrite(%s, LOW);\n", $2);
        $$ = create_node("Desligar", $2);
    }
    | ESPERAR NUM PONTO_E_VIRGULA 
    {
        asprintf(&$$, "delay(%d);\n", $2);
        $$ = create_node("Esperar", $2);
    }
    | IDENTIFICADOR IGUALDADE LER_DIGITAL IDENTIFICADOR PONTO_E_VIRGULA 
    {
        check_variable($1);
        check_variable($4);
        asprintf(&$$, "%s = digitalRead(%s);\n", $1, $4);
        $$ = create_node("LerDigital", $1, $4);
    }
    | IDENTIFICADOR IGUALDADE LER_ANALOGICO IDENTIFICADOR PONTO_E_VIRGULA 
    {
        check_variable($1);
        check_variable($4);
        asprintf(&$$, "%s = analogRead(%s);\n", $1, $4);
        $$ = create_node("LerAnalogico", $1, $4);
    }
    | CONFIGURAR_SERIAL NUM PONTO_E_VIRGULA
    {
        asprintf(&$$, "Serial.begin(%d);\n", $2);
        $$ = create_node("ConfigurarSerial", $2);
    }
    | ESCREVER_SERIAL STRING PONTO_E_VIRGULA
    {
        asprintf(&$$, "Serial.println(%s);\n", $2);
        $$ = create_node("EscreverSerial", $2);
    }
    | IDENTIFICADOR IGUALDADE LER_SERIAL PONTO_E_VIRGULA
    {
        check_variable($1);
        asprintf(&$$, "%s = Serial.readString();\n", $1);
        $$ = create_node("LerSerial", $1);
    }
    | SE condicao ENTAO bloco_cmd senao_cmd_opt FIM
    {
        if (strlen($5) > 0) {
            asprintf(&$$, "if (%s) {\n%s} else {\n%s}\n", $2, $4, $5);
            $$ = create_node("IfElse", $2, $4, $5);
        } else {
            asprintf(&$$, "if (%s) {\n%s}\n", $2, $4);
            $$ = create_node("If", $2, $4);
        }
    }
    | ENQUANTO bloco_cmd FIM
    {
        asprintf(&$$, "while (true) {\n%s}\n", $2);
        $$ = create_node("Loop", $2);
    }
    ;

/* Regra para construir uma condição simples (do tipo: operando comparador operando) */
condicao:
    operando comparador operando
    { 
        asprintf(&$$, "%s %s %s", $1, $2, $3);

        // Construção da AST
        $$ = create_node("Condicao", $1, $2, $3);
    }
    ;

/* Operando pode ser uma variável ou um número */
operando:
    IDENTIFICADOR 
    { 
        check_variable($1); 
        $$ = $1;
        $$ = create_node("Identificador", $1);
    }
    | NUM 
    { 
        char temp[32];
        sprintf(temp, "%d", $1);
        $$ = strdup(temp);
        $$ = create_node("Numero", temp);
    }
    ;

/* Converte os operadores relacionais para a sintaxe C */
comparador:
    IGUAL { $$ = create_node("Comparador", "=="); }
    | DIFERENTE { $$ = create_node("Comparador", "!="); }
    | MENOR_IGUAL { $$ = create_node("Comparador", "<="); }
    | MAIOR_IGUAL { $$ = create_node("Comparador", ">="); }
    | MENOR { $$ = create_node("Comparador", "<"); }
    | MAIOR { $$ = create_node("Comparador", ">"); }
    ;

/* Bloco de comandos (sequência de comandos) */
bloco_cmd:
    { $$ = strdup(""); }
    | bloco_cmd comando
    { 
        char* temp = (char*) malloc(strlen($1) + strlen($2) + 1);
        strcpy(temp, $1);
        strcat(temp, $2);
        free($1); free($2);
        $$ = temp;

        // Construção da AST
        $$ = create_node("BlocoCmd", $1, $2);
    }
    ;

/* Bloco opcional para o senao; se não houver senao, retorna string vazia */
senao_cmd_opt:
    SENAO bloco_cmd { $$ = $2; }
    | /* vazio */ { $$ = strdup(""); }
    ;

%%

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

    // Imprimir a AST se a análise sintática for bem-sucedida
    if (parse_result == 0 && root) {
        printf("Arvore Sintatica Abstrata (AST):\n");
        print_ast(root, 0);
    }
    
    return parse_result;
}
