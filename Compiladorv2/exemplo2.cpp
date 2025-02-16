#include <Arduino.h>
#include <WiFi.h>

int canalPWM;
int ledPin;
int brilho;
String ssid;
String senha;


void setup() {
canalPWM = 2;
ledPin = 2;
ssid = "MinhaRedeWiFi";
senha = "MinhaSenhaWiFi";
pinMode(ledPin, OUTPUT);
ledcSetup(canalPWM, 5000, 8);
ledcAttachPin(canalPWM, canalPWM);WiFi.begin(ssid.c_str(), senha.c_str());
while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Conectando ao WiFi...");
}
Serial.println("Conectado ao WiFi!");
}

void loop() {
brilho = 128;
ledcWrite(canalPWM, brilho);
delay(1000);
brilho = 0;
ledcWrite(canalPWM, brilho);
delay(1000);
}
