
const int servoPin = 13;
const int channelPin = 14;

unsigned long currentMillis;
unsigned long prevMillis = 0;
unsigned long secondMillis = 0;

void setup() {
  pinMode(servoPin, OUTPUT);
  ledcSetup(13, 50, 16);
  ledcAttachPin(servoPin, channelPin);
  
  Serial.begin(9600);
  
}



void loop() {

  ledcWrite(channelPin, 1000);
  Serial.println("180");

  delay(1000);

  Serial.println("0");
  ledcWrite(channelPin, -1000);
  delay(1000);
  /*

  currentMillis = millis();
  if(currentMillis - prevMillis >= 20){
    prevMillis = currentMillis;

    if(prevMillis - secondMillis >= 2){
      secondMillis = prevMillis;
      
      }
    

    }
    */

  
  
}
