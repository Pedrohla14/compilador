#include <Arduino.h>
#include <WiFi.h>

int ledPin;
int brilho;
String ssid;
String senha;


void setup() {
ledPin = 2;
ssid = "MinhaRedeWiFi";
senha = "MinhaSenhaWiFi";
pinMode(ledPin, OUTPUT);
ledcSetup(ledPin, 5000, 8);
ledcAttachPin(ledPin, ledPin);WiFi.begin(ssid.c_str(), senha.c_str());
while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Conectando ao WiFi...");
}
Serial.println("Conectado ao WiFi!");
}

void loop() {
brilho = 128;
ledcWrite(ledPin, brilho);
delay(1000);
brilho = 0;
ledcWrite(ledPin, brilho);
delay(1000);
}
