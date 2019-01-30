#include <Chrono.h>
int redLed = 3;
int redLedState = LOW;
int greenLed = 4;
int greenLedState = HIGH;
int blueLed = 5;
int blueLedState = LOW;
int yellowLed = 6;
int yellowLedState = HIGH;

int delaySeq[] = {200, 210, 225, 400, 415, 200, 501, 504, 600, 700, 800, 250, 500, 750, 500};
int delaySeq2[] = {150, 150, 150, 300, 200, 250, 300, 210, 100, 50, 50, 50, 50, 50, 100, 100, 150, 150};
Chrono ledChrono;
Chrono ledChrono2;
void setup() {
  // put your setup code here, to run once:
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  static int index = 0;
  static int index2 = 0;
  if (ledChrono.hasPassed(delaySeq[index])) {
    ledChrono.restart();
    redLedState=toggleLed(redLedState);
    greenLedState=toggleLed(greenLedState);
    digitalWrite(redLed, redLedState);
    digitalWrite(greenLed, greenLedState);
    index++;
    if (index >= sizeof(delaySeq)) {
      index=0;
    }
  }
  if (ledChrono2.hasPassed(delaySeq2[index2])) {
    ledChrono2.restart();
    blueLedState = toggleLed(blueLedState);
    yellowLedState = toggleLed(yellowLedState);
    digitalWrite(blueLed, blueLedState);
    digitalWrite(yellowLed, yellowLedState);
    index2++;
    if (index2 >= sizeof(delaySeq2)) {
      index2=0;
    }
  }
}

int toggleLed(int state) {
  if (state==1) {
    return 0;
  } else {
    return 1;
  }
}
