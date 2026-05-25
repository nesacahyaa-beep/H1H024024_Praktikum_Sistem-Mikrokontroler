#include <Arduino.h>

const int ledMerah = 13; 
const int ledHijau = 12; 
int merahState = LOW;     
int hijauState = LOW;     
unsigned long previousMillisMerah = 0; 
unsigned long previousMillisHijau = 0; 
const long intervalMerah = 1000; 
const long intervalHijau = 500;  

void setup() {
  pinMode(ledMerah, OUTPUT);
  pinMode(ledHijau, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillisMerah >= intervalMerah) {
    previousMillisMerah = currentMillis;
    merahState = !merahState;
    digitalWrite(ledMerah, merahState);
  }

  if (currentMillis - previousMillisHijau >= intervalHijau) {
    previousMillisHijau = currentMillis;
    hijauState = !hijauState;
    digitalWrite(ledHijau, hijauState);
  }
}