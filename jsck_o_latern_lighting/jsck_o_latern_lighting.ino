#include <Chrono.h>
#include "FastLED.h"

const int PUMPKIN_COUNT = 4;
const int LIGHT_COUNT = 4;
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
  FastLED.addLeds<WS2812, 2, GRB>(leds, MAX_LIGHTS);
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
       timers[i].timer = random(100) + 20;
       timers[i].chrono.restart();
    }
  }
  FastLED.show();
}

void updateLights(CRGB leds[], int start, int end){
  for (int i=start; i < end; i++) {
    if ((i / LIGHT_COUNT) % 2 == 0) {
      leds[i]=ColorChoice();  
    } else {
      leds[i]=ColorChoiceBlue();
    }
     
  }
}

CRGB ColorChoice() {
  int choice = random(3);
    switch(choice){
      case 0:
        return CRGB(255,0,0);
      case 1:
        return CRGB(51,10,0);
      case 2:
        return CRGB(51,17,0);
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
