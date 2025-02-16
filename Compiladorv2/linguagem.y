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

typedef struct PinConfig {
    char *pin_name;
    char *mode; // "OUTPUT", "INPUT", "PWM"
    struct PinConfig *next;
} PinConfig;

PinConfig *pin_table = NULL;

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

void check_compatibility(const char *var_name, const char *expected_type) {
    Symbol *current = symbol_table;
    while (current != NULL) {
        if (strcmp(current->name, var_name) == 0) {
            if (strcmp(current->type, expected_type) != 0) {
                error_count++;
                fprintf(stderr, "Erro semantico na linha %d: tipo de variavel '%s' incompatível. Esperado '%s', encontrado '%s'.\n", 
                        yylineno, var_name, expected_type, current->type);
            }
            return;
        }
        current = current->next;
    }
}

int pin_configured(const char *pin_name) {
    PinConfig *current = pin_table;
    while (current != NULL) {
        if (strcmp(current->pin_name, pin_name) == 0) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

void declare_pin(const char *pin_name, const char *mode) {
    
    PinConfig *p = (PinConfig *) malloc(sizeof(PinConfig));
    p->pin_name = strdup(pin_name);
    p->mode = strdup(mode);
    p->next = pin_table;
    pin_table = p;
}

const char* get_pin_mode(const char *pin_name) {
    PinConfig *current = pin_table;
    while (current != NULL) {
        if (strcmp(current->pin_name, pin_name) == 0) {
            return current->mode;
        }
        current = current->next;
    }
    return NULL; // Pino não configurado
}

// Inicio ATS
typedef struct node {
    char *value;
    struct node *left;
    struct node *right;
} node;

struct node *nval;

node* create_node(const char *value, node *left, node *right) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->value = strdup(value);  // Garantir que a string seja copiada
    new_node->left = left;
    new_node->right = right;
    return new_node;
}

void print_tree(node *root, int level) {
    if (root == NULL)
        return;

    // Adiciona indentação proporcional ao nível do nó
    for (int i = 0; i < level; i++)
        printf("    ");

    // Imprime o valor do nó
    printf("|-- %s\n", root->value);

    // Chama recursivamente para os filhos esquerdo e direito
    print_tree(root->left, level + 1);
    print_tree(root->right, level + 1);
}

void free_tree(node *root) {
    if (root == NULL) {
        return;
    }

    // Recursivamente libera os filhos esquerdo e direito
    free_tree(root->left);
    free_tree(root->right);

    // Libera o valor do nó, se necessário
    free((char*)root->value);  // Aqui você pode liberar a string armazenada no nó

    // Libera o próprio nó
    free(root);
}

// Fim ATS

extern FILE *yyin;
void yyerror(const char *s);
int yylex();
%}

%union {
    char* str;
    struct node *nval;
    int num;
}

%token <num> NUM
%token <str> STRING
%token CONFIG REPITA FIM VAR INTEIRO BOOLEANO TEXTO
%token CONFIGURAR COMO SAIDA ENTRADA LIGAR DESLIGAR
%token CONECTAR_WIFI CONFIGURAR_SERIAL ESCREVER_SERIAL LER_SERIAL
%token ENVIAR_HTTP ESPERAR LER_DIGITAL LER_ANALOGICO
%token CONFIGURAR_PWM FREQUENCIA RESOLUCAO AJUSTAR_PWM VALOR COM
%token SE ENTRADA_PULLDOWN SENAO ENTAO ENQUANTO
%token IGUAL DIFERENTE MENOR_IGUAL MAIOR_IGUAL MENOR MAIOR
%token SOMA SUBTRACAO MULTIPLICACAO DIVISAO
%token IGUALDADE DOIS_PONTOS VIRGULA PONTO_E_VIRGULA
%token IDENTIFICADOR
/* Declaração dos não-terminais com tipo <str> */
/*
%type <str> programa declaracoes declaracao tipo 
%type <str> lista_ids config bloco_config repita bloco_repita comando condicao
%type <str> operando comparador bloco_cmd senao_cmd_opt
*/

%type <nval> programa declaracoes declaracao tipo 
%type <nval> lista_ids config bloco_config repita bloco_repita comando condicao
%type <nval> operando comparador bloco_cmd senao_cmd_opt
%type <nval> IDENTIFICADOR

%start programa

%%

programa:
   declaracoes config repita
    { 
        $$ = create_node("programa", $1, create_node("setup", $2, $3));

        char *setup_value = strdup($2->value);
        char *loop_value = strdup($3->value);

        asprintf(&( ($$)->value ), "#include <Arduino.h>\n#include <WiFi.h>\n\nvoid setup() {\n%s}\n\nvoid loop() {\n%s}\n", setup_value, loop_value);

        // Libere as strings duplicadas depois de usá-las
        free(setup_value);
        free(loop_value);
    }
    ;

declaracoes:
    { 
        $$ = create_node("declaracoes", NULL, NULL);  // Criação de um nó vazio para declaracoes
    }
    | declaracoes declaracao 
    { 
        $$ = create_node("declaracoes", $1, $2);  // Criação de um nó com os filhos $1 e $2
        free($1); // Libera o nó anterior, se necessário
        free($2); // Libera o nó da declaracao, se necessário
    }
    ;


declaracao: VAR tipo DOIS_PONTOS lista_ids PONTO_E_VIRGULA
    {
        $$ = create_node("declaracao", $2, $4);
        asprintf(&($$->value), "%s %s;\n", $2->value, $4->value);
    }
    ;

tipo:
    INTEIRO   { 
        $$ = create_node("tipo", create_node("int", NULL, NULL), NULL); 
    }
  | BOOLEANO { 
        $$ = create_node("tipo", create_node("bool", NULL, NULL), NULL); 
    }
  | TEXTO    { 
        $$ = create_node("tipo", create_node("String", NULL, NULL), NULL); 
    }
  ;


lista_ids:
    IDENTIFICADOR 
    { 
        $$ = create_node($1->value, NULL, NULL); 
        free($1);  // Libera a memória de $1 após usá-lo
    }
  | lista_ids VIRGULA IDENTIFICADOR 
    { 
        char* temp = (char*) malloc(strlen($1->value) + strlen($3->value) + 3);
        sprintf(temp, "%s, %s", $1->value, $3->value);
        free($1->value); free($3->value);
        free($1); free($3);

        node* temp_node = create_node(temp, NULL, NULL);  // Criar nó para a string
        $$ = create_node("lista_ids", create_node("identificador", temp_node, NULL), NULL);
    }
  ;


config:
    CONFIG bloco_config FIM 
    { $$ = $2; }
    ;

bloco_config:
    //{ $$ = strdup(""); }
    { $$ = create_node("", NULL, NULL); } // node vazio
    | bloco_config comando 
    { 
        char* temp = (char*) malloc(strlen($1->value) + strlen($2->value) + 1);
        strcpy(temp, $1->value);
        strcat(temp, $2->value);
        free($1->value); free($2->value);

        $$ = create_node(temp, NULL, NULL);
        free(temp); // Liberar memória temporária

        //$$ = temp;
    }
    ;

repita:
    REPITA bloco_repita FIM 
    { $$ = $2; }
    ;

bloco_repita:
    { $$ = create_node("", NULL, NULL); } // node vazio
    | bloco_repita comando 
    { 
        char* temp = (char*) malloc(strlen($1->value) + strlen($2->value) + 1);
        strcpy(temp, $1->value);
        strcat(temp, $2->value);
        free($1->value); free($2->value);
        //$$ = temp;

        $$ = create_node(temp, NULL, NULL); // Criar um nó para temp
        free(temp); // Liberar memória de temp
    }
    ;

/* Regras para comandos individuais */
comando:
    IDENTIFICADOR IGUALDADE NUM PONTO_E_VIRGULA 
    { 
        check_variable($1->value);
        check_compatibility($1->value, "int");

        // Criação da string formatada
        char* temp;
        asprintf(&temp, "%s = %d;\n", $1->value, $3);

        //asprintf(&$$, "%s = %d;\n", $1->value, $3->value);

        // Criando um nó para armazenar a string formatada
        $$ = create_node(temp, NULL, NULL);

        // Liberar a memória temporária
        free(temp);
    }
    | IDENTIFICADOR IGUALDADE STRING PONTO_E_VIRGULA 
    { 
        check_variable($1->value);
        check_compatibility($1->value, "String");
        //asprintf(&$$, "%s = %s;\n", $1->value, $3);

        // Criação da string formatada
        char* temp;
        asprintf(&temp, "%s = %s;\n", $1->value, $3);  // $3 é um char* diretamente

        // Agora cria um nó para armazenar a string formatada
        $$ = create_node(temp, NULL, NULL);  // Armazenando a string formatada em um nó

        // Liberar a memória temporária (caso necessário)
        free(temp);
    }
    | CONECTAR_WIFI IDENTIFICADOR IDENTIFICADOR PONTO_E_VIRGULA
    {
        check_variable($2->value);
        check_variable($3->value);
        char* temp;
        asprintf(&temp, 
            "WiFi.begin(%s.c_str(), %s.c_str());\n"
            "while (WiFi.status() != WL_CONNECTED) {\n"
            "    delay(500);\n"
            "    Serial.println(\"Conectando ao WiFi...\");\n"
            "}\n"
            "Serial.println(\"Conectado ao WiFi!\");\n",
            $2->value, $3->value);

        // Agora cria um nó para armazenar a string formatada
        $$ = create_node(temp, NULL, NULL);  // Armazenando a string formatada em um nó

        // Liberar a memória temporária (caso necessário)
        free(temp);
    }

    | AJUSTAR_PWM IDENTIFICADOR COM VALOR IDENTIFICADOR PONTO_E_VIRGULA {
        check_variable($2->value);
        check_variable($5->value);
        const char *mode = get_pin_mode($2->value);
        if (mode == NULL || strcmp(mode, "PWM") != 0) {
            error_count++;
            fprintf(stderr, 
                "Erro semantico na linha %d: pino '%s' nao configurado como 'PWM'\n", yylineno, $2->value);
        }
        char* temp;
        asprintf(&temp, "ledcWrite(%s, %s);\n", $2->value, $5->value);
        // Agora cria um nó para armazenar a string formatada
        $$ = create_node(temp, NULL, NULL);  // Armazenando a string formatada em um nó 

        // Liberar a memória temporária (caso necessário)
        free(temp);
    }   

    | AJUSTAR_PWM IDENTIFICADOR COM VALOR NUM PONTO_E_VIRGULA 
    {
        check_variable($2->value);
        char* temp;
        asprintf(&temp, "ledcWrite(%s, %d);\n", $2->value, $5);

        // Agora cria um nó para armazenar a string formatada
        $$ = create_node(temp, NULL, NULL);  // Armazenando a string formatada em um nó

        // Liberar a memória temporária (caso necessário)
        free(temp);

    }
    | CONFIGURAR_PWM IDENTIFICADOR COM FREQUENCIA NUM RESOLUCAO NUM PONTO_E_VIRGULA
    { 
        check_variable($2->value);
        declare_pin($2->value, "PWM");
        char* temp;
        asprintf(&temp, "ledcSetup(%s, %d, %d);\nledcAttachPin(%s, %s);", 
                $2->value, $5, $7, $2->value, $2->value);

        // Agora cria um nó para armazenar a string formatada
        $$ = create_node(temp, NULL, NULL);  // Armazenando a string formatada em um nó

        // Liberar a memória temporária (caso necessário)
        free(temp);

    }
    | CONFIGURAR IDENTIFICADOR COMO SAIDA PONTO_E_VIRGULA 
    {
        check_variable($2->value);
        declare_pin($2->value, "OUTPUT");
        char* temp;
        asprintf(&temp, "pinMode(%s, OUTPUT);\n", $2->value);

        // Agora cria um nó para armazenar a string formatada
        $$ = create_node(temp, NULL, NULL);  // Armazenando a string formatada em um nó

        // Liberar a memória temporária (caso necessário)
        free(temp);
    }

    | CONFIGURAR IDENTIFICADOR COMO ENTRADA PONTO_E_VIRGULA 
    {
        check_variable($2->value);
        declare_pin($2->value, "INPUT");
        char* temp;
        asprintf(&temp, "pinMode(%s, INPUT);\n", $2->value);

        // Agora cria um nó para armazenar a string formatada
        $$ = create_node(temp, NULL, NULL);  // Armazenando a string formatada em um nó

        // Liberar a memória temporária (caso necessário)
        free(temp);
    }

    | LIGAR IDENTIFICADOR PONTO_E_VIRGULA {
        check_variable($2->value);
        const char *mode = get_pin_mode($2->value);
        if (mode == NULL || strcmp(mode, "OUTPUT") != 0) {
            error_count++;
            fprintf(stderr, "Erro semantico na linha %d: pino '%s' nao configurado como 'OUTPUT'\n", yylineno, $2->value);
        }
        char* temp;
        asprintf(&temp,"digitalWrite(%s, HIGH);\n", $2->value);

        // Agora cria um nó para armazenar a string formatada
        $$ = create_node(temp, NULL, NULL);  // Armazenando a string formatada em um nó

        // Liberar a memória temporária (caso necessário)
        free(temp);

    }

    | DESLIGAR IDENTIFICADOR PONTO_E_VIRGULA {
        check_variable($2->value);
        const char *mode = get_pin_mode($2->value);
        if (mode == NULL || strcmp(mode, "OUTPUT") != 0) {
            error_count++;
            fprintf(stderr, "Erro semantico na linha %d: pino '%s' nao configurado como 'OUTPUT'\n", yylineno, $2->value);
        }
        char* temp;
        asprintf(&temp, "digitalWrite(%s, LOW);\n", $2->value);

        // Agora cria um nó para armazenar a string formatada
        $$ = create_node(temp, NULL, NULL);  // Armazenando a string formatada em um nó

        // Liberar a memória temporária (caso necessário)
        free(temp);
    }

    | ESPERAR NUM PONTO_E_VIRGULA 
    {
        char* temp;
        asprintf(&temp, "delay(%d);\n", $2);

        // Agora cria um nó para armazenar a string formatada
        $$ = create_node(temp, NULL, NULL);  // Armazenando a string formatada em um nó

        // Liberar a memória temporária (caso necessário)
        free(temp);
    }

    | IDENTIFICADOR IGUALDADE LER_DIGITAL IDENTIFICADOR PONTO_E_VIRGULA {
        check_variable($1->value);
        check_variable($4->value);
        const char *mode = get_pin_mode($4->value);
        if (mode == NULL || strcmp(mode, "INPUT") != 0) {
            error_count++;
            fprintf(stderr, "Erro semantico na linha %d: pino '%s' nao configurado como 'INPUT'\n", yylineno, $4->value);
        }
        char* temp;
        asprintf(&temp, "%s = digitalRead(%s);\n", $1->value, $4->value);

        // Agora cria um nó para armazenar a string formatada
        $$ = create_node(temp, NULL, NULL);  // Armazenando a string formatada em um nó

        // Liberar a memória temporária (caso necessário)
        free(temp);
    }

    | IDENTIFICADOR IGUALDADE LER_ANALOGICO IDENTIFICADOR PONTO_E_VIRGULA {
        check_variable($1->value);
        check_variable($4->value);
        const char *mode = get_pin_mode($4->value);
        if (mode == NULL || strcmp(mode, "INPUT") != 0) {
            error_count++;
            fprintf(stderr, "Erro semantico na linha %d: pino '%s' nao configurado como 'INPUT'\n", yylineno, $4->value);
        }
        char* temp;
        asprintf(&temp, "%s = analogRead(%s);\n", $1->value, $4->value);

        // Agora cria um nó para armazenar a string formatada
        $$ = create_node(temp, NULL, NULL);  // Armazenando a string formatada em um nó

        // Liberar a memória temporária (caso necessário)
        free(temp);

    }

    | CONFIGURAR_SERIAL NUM PONTO_E_VIRGULA
    {
        char* temp;
        asprintf(&temp, "Serial.begin(%d);\n", $2);

        // Agora cria um nó para armazenar a string formatada
        $$ = create_node(temp, NULL, NULL);  // Armazenando a string formatada em um nó

        // Liberar a memória temporária (caso necessário)
        free(temp);

    }

    | ESCREVER_SERIAL STRING PONTO_E_VIRGULA
    {
        char* temp;
        asprintf(&temp, "Serial.println(%s);\n", $2);

        // Agora cria um nó para armazenar a string formatada
        $$ = create_node(temp, NULL, NULL);  // Armazenando a string formatada em um nó

        // Liberar a memória temporária (caso necessário)
        free(temp);
    }

    | IDENTIFICADOR IGUALDADE LER_SERIAL PONTO_E_VIRGULA
    {
        check_variable($1->value);
        char* temp;
        asprintf(&temp, "%s = Serial.readString();\n", $1->value);

        // Agora cria um nó para armazenar a string formatada
        $$ = create_node(temp, NULL, NULL);  // Armazenando a string formatada em um nó

        // Liberar a memória temporária (caso necessário)
        free(temp);
    }

    | SE condicao ENTAO bloco_cmd senao_cmd_opt FIM
    {
        $$ = create_node("if", $2, create_node("then", $4, $5));
        
        if (strlen($5->value) > 0) {
            asprintf(&($$->value), "if (%s) {\n%s} else {\n%s}\n", $2->value, $4->value, $5->value);
        } else {
            asprintf(&($$->value), "if (%s) {\n%s}\n", $2->value, $4->value);
        }
    }

    | ENQUANTO bloco_cmd FIM
    {
        char* temp;
        asprintf(&temp, "while (true) {\n%s}\n", $2->value);

         // Agora cria um nó para armazenar a string formatada
        $$ = create_node(temp, NULL, NULL);  // Armazenando a string formatada em um nó

        // Liberar a memória temporária (caso necessário)
        free(temp);

    }
    ;

/* Regra para construir uma condição simples (do tipo: operando comparador operando) */
condicao:
    operando comparador operando
   { 
        $$ = create_node($2->value, $1, $3);
        asprintf(&($$->value), "%s %s %s", $1->value, $2->value, $3->value);
    }
    ;

/* Operando pode ser uma variável ou um número */
operando:
    IDENTIFICADOR 
    { 
        check_variable($1->value); 
        $$ = $1; 
    }
    | NUM 
    { 
        char temp[32];
        sprintf(temp, "%d", $1);
        //$$ = strdup(temp);

        // Criação de um nó para armazenar o número como string
        $$ = create_node(strdup(temp), NULL, NULL);
    }
    ;

/* Converte os operadores relacionais para a sintaxe C */
comparador:
    IGUAL { $$ = create_node(strdup("=="), NULL, NULL); }
    | DIFERENTE { $$ = create_node(strdup("!="), NULL, NULL); }
    | MENOR_IGUAL { $$ = create_node(strdup("<="), NULL, NULL); }
    | MAIOR_IGUAL { $$ = create_node(strdup(">="), NULL, NULL); }
    | MENOR { $$ = create_node(strdup("<"), NULL, NULL); }
    | MAIOR { $$ = create_node(strdup(">"), NULL, NULL); }
    ;

/* Bloco de comandos (sequência de comandos) */
bloco_cmd:
   { $$ = create_node("", NULL, NULL); }  // Cria um nó vazio
    | bloco_cmd comando
    { 
        char* temp = (char*) malloc(strlen($1->value) + strlen($2->value) + 1);
        strcpy(temp, $1->value);
        strcat(temp, $2->value);
        free($1->value); free($2->value);
        //$$ = temp;

        // Cria um novo nó para armazenar a string concatenada
        $$ = create_node(temp, NULL, NULL);  // Armazena o resultado em um novo nó

        free(temp);  // Libera a memória temporária
    }
    ;

/* Bloco opcional para o senao; se não houver senao, retorna string vazia */
senao_cmd_opt:
    SENAO bloco_cmd { $$ = $2; }
    | /* vazio */ { $$ = create_node("", NULL, NULL); }
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

    // Inicia a análise sintática
    yyparse();

    // Exibe a Árvore Sintática Abstrata (AST)
    printf("\n=== Árvore Sintática Abstrata ===\n");
    print_tree(nval, 0); // Assume que 'root' é a raiz da AST

    // Exibe o código C++ gerado
    printf("\n=== Código C++ Gerado ===\n");
    printf("%s\n", nval->value);

    // Libera memória da AST
    free_tree(nval);

    fclose(yyin);
    return 0;
}
