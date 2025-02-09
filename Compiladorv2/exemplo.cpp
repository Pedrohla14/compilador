#include <Arduino.h>

int ledPin;
int botao;
int estadoBotao;
int estadoBotao2;


void setup() {
ledPin = 13;
pinMode(ledPin, OUTPUT);
botao = 12;
pinMode(botao, INPUT);
}

void loop() {
estadoBotao = digitalRead(botao);
estadoBotao2 = analogRead(botao);
digitalWrite(ledPin, HIGH);
delay(1000);
digitalWrite(ledPin, LOW);
delay(1000);
}
