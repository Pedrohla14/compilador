# Projeto Compilador(C++\ESP32):

## Parte 1: Análise Léxica e Sintática

**a)**  **Tradução para C++:** A linguagem personalizada deverá ser traduzida para código C++ compatı́vel com o ESP32, utilizando bibliotecas padrão como a WiFi.h e Arduino.h. 

**b)**  **Implementação do Tradutor:** O tradutor será implementado usando Flex e Bison. Ele será dividido em analisador léxico, analisador sintático e gerador de código.

**c)** Caso haja algum erro léxico,sintático ou semântico, deverá ser informado.

**d)** Mostre a árvore sintática criada para cada análise

**e)** Crie um arquivo .sh que automatize o processo.

**f)** Gere um arquivo em linguagem C++ a partir do código programado na linguagem personalizada.

**g)** Crie três programas de exemplo em linguagem personalizada, converta para linguagem C++ e teste seu código no ESP32. Você também poderá usar um simulador online: wokwi.

## Parte 2 : Análise Semântica
### Declaração e Uso de Variáveis:

**1.)** Todas as variáveis usadas no programa devem ser previamente declaradas.

**2.)** Não é permitido declarar uma variável com o mesmo nome duas vezes no mesmo escopo

### Erro semântico: Variável ’ledPin’ não foi declarada antes do uso.
### Tipos de Variáveis:
**1.)** Operações realizadas devem ser compatı́veis com os tipos das variáveis (por exemplo, não se pode usar operações aritméticas com variáveis do tipo texto).

**2.)** Os valores atribuı́dos às variáveis devem ser do tipo correto.

### Erro Semântico: Tentativa de usar ’texto’ para armazenar um valor numérico

### Compatibilidade de Comandos:
**1.)** Comandos como ligar, desligar, ajustar PWM só podem ser usados com pinos configurados como saida ou PWM.

**2.)** Comandos como lerDigital ou lerAnalogico só podem ser usados com pinos configurados como entrada.
