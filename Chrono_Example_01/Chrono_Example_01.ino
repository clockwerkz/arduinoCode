#include <Chrono.h>
int light = 13;

int ledState = 0;

Chrono ledChrono;

void setup() {
  // put your setup code here, to run once:
  pinMode(light, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (ledChrono.hasPassed(1000)) {
    ledChrono.restart();
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }
    digitalWrite(light, ledState);
  }
}
