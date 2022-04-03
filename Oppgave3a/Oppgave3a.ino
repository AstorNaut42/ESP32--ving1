const int fotoPin = 32;

const int channelLED = 0;

void setup() {
  pinMode(fotoPin, INPUT);
  
  ledcSetup(0, 2000, 8);
  ledcAttachPin(fotoPin, channelLED);
  Serial.begin(9600);
}

float mapfloat(long x, long in_min, long in_max, long out_min, long out_max){
  return (float)(x - in_min) * (out_max - out_min) / (float)(in_max - in_min) + out_min;
}



void loop() {
  float fotoValue = analogRead(fotoPin);
  fotoValue = mapfloat(fotoValue, 0, 4096, 0, 3.3);
  Serial.println(fotoValue);

}
