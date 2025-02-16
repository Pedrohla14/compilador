#include <Arduino.h>
#include <WiFi.h>

int botao;
int estado;


void setup() {
botao = 12;
pinMode(botao, INPUT);
Serial.begin(115200);
}

void loop() {
estado = digitalRead(botao);
if (estado == 1) {
Serial.println("Botao pressionado!");
}
}
