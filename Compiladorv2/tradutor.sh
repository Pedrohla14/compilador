#!/bin/bash
set -e  # Encerra o script se ocorrer algum erro

echo "Iniciando a compilação do tradutor..."

# Gera os arquivos do parser
bison -d -o linguagem.tab.c linguagem.y
echo "Bison gerado com sucesso!"

# Gera os arquivos do lexer
flex -o lex.yy.c linguagem.l
echo "Flex gerado com sucesso!"

# Compila tudo
g++ -o tradutor linguagem.tab.c lex.yy.c -lfl
echo "Código compilado com sucesso!"

# Executa o tradutor para os arquivos de exemplo
./tradutor exemplo.txt > exemplo.cpp
./tradutor exemplo2.txt > exemplo2.cpp
./tradutor exemplo3.txt > exemplo3.cpp

echo "Compilação concluída! Arquivos exemplo.cpp, exemplo2.cpp e exemplo3.cpp gerados."
