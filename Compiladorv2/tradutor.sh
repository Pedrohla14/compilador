#!/bin/bash
# Gera os arquivos do parser
bison -d -o linguagem.tab.c linguagem.y

# Gera os arquivos do lexer
flex -o lex.yy.c linguagem.l

# Compila tudo
g++ -o tradutor linguagem.tab.c lex.yy.c -lfl

# Executa o tradutor
./tradutor exemplo.txt > exemplo.cpp

./tradutor exemplo2.txt > exemplo2.cpp

./tradutor exemplo3.txt > exemplo3.cpp


echo "Compilação concluída! Arquivo exemplo.cpp gerado."