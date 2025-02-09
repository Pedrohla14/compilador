#!/bin/bash
# Gera os arquivos do parser
bison -d -o linguagem.tab.c linguagem.y

# Gera os arquivos do lexer
flex -o lex.yy.c linguagem.l

# Compila tudo
gcc -o tradutor linguagem.tab.c lex.yy.c -lfl

# Executa o tradutor
./tradutor exemplo.txt > exemplo.cpp

echo "Compilação concluída! Arquivo exemplo.cpp gerado."