#include <Chrono.h>
#include "FastLED.h"

const int PUMPKIN_COUNT = 12;
const int LIGHT_COUNT = 7;
const int MAX_LIGHTS = LIGHT_COUNT * PUMPKIN_COUNT+1;
Chrono switchColor;
int currentColor = 0;
struct TimerObj {
  int timer;
  Chrono chrono;
};

CRGB leds[MAX_LIGHTS];
Chrono chronos[PUMPKIN_COUNT];
TimerObj timers[PUMPKIN_COUNT];

void setup() {
  currentColor = 1;
  // put your setup code here, to run once:
  FastLED.addLeds<WS2811, 2, RGB>(leds, MAX_LIGHTS);
  for (int i=0; i < PUMPKIN_COUNT; i++){
    timers[i].timer = random(100) + 20;
  }
  leds[0] = CRGB(0,255,255);
  for (int i=1; i < MAX_LIGHTS; i++){
    leds[i] = ColorChoiceGreen();
  }
}

void loop() {
  // put your main code here, to run repeatedly:
//  if (switchColor.hasPassed(5000)){
//    currentColor = 1;
//    switchColor.restart();
//  }
  
  for (int i=0; i < PUMPKIN_COUNT; i++) {
    if (timers[i].chrono.hasPassed(timers[i].timer)){
      int start = i * LIGHT_COUNT+1;
      int end = start + LIGHT_COUNT+1;
      updateLights(leds, start, end, currentColor);
      timers[i].chrono.restart();
      timers[i].timer = randomTimerRange(i);
    }
  }
  FastLED.show();
}

void updateLights(CRGB leds[], int start, int end, int colorSelection){
  for (int i=start; i<end; i++) {
    switch(colorSelection){
     case 0:
      leds[i]=ColorChoiceGreen();
      break;
     case 1:
     default:
      leds[i]=ColorChoiceRed();
      break;
    }        
  }
}

int randomTimerRange(int i){
  int choice = i % 4;
  switch(choice){
    case 0:
      return random(100) + 60;
    case 1:
      return random(250) + 250;
    case 2:
      return random(200) + 180;
    case 3:
      return random(50) + random(40) + 40;
  }
}

CRGB ColorChoiceGreen(){
  int choice = random(4);
  switch(choice){
    case 0:
      return CRGB(100,255,0);
    case 1:
      return CRGB(100,255,30);
    case 2:
      return CRGB(80,255,130);
    case 3:
    default:
      return CRGB(100,255,40);
  } 
}
//red green blue - blue green red
CRGB ColorChoiceRed() {
  int choice = random(4);
    switch(choice){
      case 0:
        return CRGB(255,100,0);
      case 1:
        return CRGB(255,10,0);
      case 2:
        return CRGB(151,170,0);
      case 3:
        return CRGB(250,60,0);
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
