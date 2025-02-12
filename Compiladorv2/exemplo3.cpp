#include <Arduino.h>
#include <WiFi.h>

int ledPin;
int brilho;


void setup() {
ledPin = 18;
pinMode(ledPin, OUTPUT);
brilho = 128;
}

void loop() {
digitalWrite(ledPin, HIGH);
delay(1000);
digitalWrite(ledPin, LOW);
delay(1000);
}
