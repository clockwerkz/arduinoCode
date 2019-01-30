
const int buttonPin = 12;
int buttonState = 0;
int BLUE = 11;
void setup() {
  // put your setup code here, to run once:
pinMode(buttonPin, INPUT);
pinMode(BLUE,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin);
  
  if(buttonState == 0){
    digitalWrite(BLUE,HIGH);
  }else {
   digitalWrite(BLUE,LOW);
  }
}
