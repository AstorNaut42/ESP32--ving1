const int LedPin = 5;

const int channelLED = 0;

void setup() {
  pinMode(LedPin, OUTPUT);
  
  ledcSetup(0, 2000, 8);
  ledcAttachPin(LedPin, channelLED);
  ledcWrite(channelLED, 0);
  Serial.begin(9600);


}

void loop() {
  delay(500);
  Serial.println("Hello World!");
  ledcWrite(channelLED, 0);
  delay(500);
  ledcWrite(channelLED, 255);

}
