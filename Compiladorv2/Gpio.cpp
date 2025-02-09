#include <Arduino.h>

int ledPin;
int ledPin2;


void setup() {
ledPin = 13;
ledpin2 = 14;
pinMode(ledPin, OUTPUT);
pinMode(ledPin2, INPUT);
}

void loop() {
digitalWrite(ledPin, HIGH);
delay(1000);
digitalWrite(ledPin, LOW);
delay(1000);
}
