int RED_LIGHT = 3;
int YELLOW_LIGHT = 2;
bool isRedLightOn = false;
bool isYellowLightOn = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  pinMode(RED_LIGHT, OUTPUT);
  pinMode(YELLOW_LIGHT, OUTPUT);
}

void loop() {
  static int delayTime = 100;
  static int timer = 0;
  static int yellowLightDelay =1500;
  static int redLightDelay = 1000;
  if (timer % redLightDelay == 0) {
    Serial.println("TOGGLE RED LIGHT");
    toggleRedLight();
  }
  if (timer % yellowLightDelay == 0) {
    Serial.println("TOGGLE YELLOW LIGHT");
    toggleYellowLight();
  }
  delay(delayTime);
  if (timer == 32000) {
    timer = 0;
  }
  timer = timer+100;
}

void toggleRedLight() {
  if (isRedLightOn) {
    digitalWrite(RED_LIGHT, LOW);
  } else {
    digitalWrite(RED_LIGHT, HIGH);
  }
  isRedLightOn = !isRedLightOn;
}

void toggleYellowLight() {
  if (isYellowLightOn) {
    digitalWrite(YELLOW_LIGHT, LOW);
  } else {
    digitalWrite(YELLOW_LIGHT, HIGH);
  }
  isYellowLightOn = !isYellowLightOn;
}
