#include <Chrono.h>
#include "FastLED.h"

const int PUMPKIN_COUNT = 4;
const int LIGHT_COUNT = 7;
const int MAX_LIGHTS = LIGHT_COUNT * PUMPKIN_COUNT;

struct TimerObj {
  int timer;
  Chrono chrono;
};

CRGB leds[MAX_LIGHTS];
Chrono chronos[PUMPKIN_COUNT];
TimerObj timers[PUMPKIN_COUNT];

void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<WS2811, 2, RGB>(leds, MAX_LIGHTS);
  for (int i=0; i < PUMPKIN_COUNT; i++){
    timers[i].timer = random(100) + 20;
  }
  for (int i=0; i < MAX_LIGHTS; i++){
    leds[i] = ColorChoice();
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i=0; i < PUMPKIN_COUNT; i++) {
    if (timers[i].chrono.hasPassed(timers[i].timer)){
      int start = i * LIGHT_COUNT;
      int end = start + LIGHT_COUNT;
       updateLights(leds, start, end);
       timers[i].timer = random(100) + 60;
       timers[i].chrono.restart();
    }
  }
  FastLED.show();
}
//remove the colorChoiceBlue logic
void updateLights(CRGB leds[], int start, int end){
  int mid = end - 3;
  for (int i=start; i < mid; i++) {
      leds[i]=ColorChoice();      
  }
  for (int i=mid; i < end; i++){
    leds[i] = CRGB(255,0,0);
  }
}
//red green blue - blue green red
CRGB ColorChoice() {
  int choice = random(4);
    switch(choice){
      case 0:
        return CRGB(255,100,0);
      case 1:
        return CRGB(255,10,0);
      case 2:
        return CRGB(151,17,0);
    } 
  return CRGB(51,17,0); 
}

CRGB ColorChoiceBlue() {
  int choice = random(3);
    switch(choice){
      case 0:
        return CRGB(0,0,255);
      case 1:
        return CRGB(0,255,00);
      case 2:
        return CRGB(0,255,251);
    } 
  return CRGB(51,17,0); 
}
