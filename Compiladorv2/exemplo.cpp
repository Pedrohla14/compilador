#include <Arduino.h>

int ledPin;


void setup() {
ledPin = 13;
pinMode(ledPin, OUTPUT);
}

void loop() {
digitalWrite(ledPin, HIGH);
delay(1000);
digitalWrite(ledPin, LOW);
delay(1000);
}
