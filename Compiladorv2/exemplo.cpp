#include <Arduino.h>

int ledPin;
int botao;
int estadoBotao;
int estadoBotao2;
int brilho;
String ssid;
String senha;


void setup() {
ledPin = 13;
pinMode(ledPin, OUTPUT);
botao = 12;
pinMode(botao, INPUT);
brilho = 128;
ssid = "MinhaRedeWiFi";
senha = "MinhaSenhaWiFi";
}

void loop() {
estadoBotao = digitalRead(botao);
estadoBotao2 = analogRead(botao);
ledcWrite(ledPin, brilho);
digitalWrite(ledPin, HIGH);
delay(1000);
digitalWrite(ledPin, LOW);
delay(1000);
}
