#include <Arduino.h>
#include <WiFi.h>

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
Serial.begin(115200);
WiFi.begin(ssid.c_str(), senha.c_str());
while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Conectando ao WiFi...");
}
Serial.println("Conectado ao WiFi!");
}

void loop() {
estadoBotao = digitalRead(botao);
estadoBotao2 = analogRead(botao);
ledcWrite(ledPin, brilho);
digitalWrite(ledPin, HIGH);
delay(1000);
digitalWrite(ledPin, LOW);
delay(1000);
Serial.println("Botão pressionado!");
}
