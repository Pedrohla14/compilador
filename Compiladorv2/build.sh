#!/bin/bash

# Verifica se os parâmetros de entrada foram passados
if [ $# -ne 2 ]; then
    echo "Uso: $0 <arquivo_entrada> <arquivo_saida>"
    exit 1
fi

INPUT_FILE=$1
OUTPUT_FILE=$2

# Remove arquivos gerados anteriormente
rm -f parser.tab.c parser.tab.h lex.yy.c "$OUTPUT_FILE" tradutor parser.output

# Executa o Bison para gerar o parser (gera também o relatório parser.output)
bison -d -v parser.y

# Executa o Flex para gerar o scanner
flex scanner.l

# Compila o tradutor utilizando o GCC e a biblioteca do flex (-lfl)
gcc -o tradutor parser.tab.c lex.yy.c -lfl

# Executa o tradutor redirecionando a entrada para gerar o arquivo de saída
./tradutor < "$INPUT_FILE" > "$OUTPUT_FILE"

echo "Código C++ gerado em $OUTPUT_FILE"
