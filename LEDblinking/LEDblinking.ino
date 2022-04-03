// Terminaler
const int LED = 32;

// Kanal
const int channelLED = 0;  // LED PWM kanal

void setup() {
  Serial.begin(9600);

  pinMode(LED, OUTPUT);

  ledcSetup(channelLED, 2000, 8);
  ledcAttachPin(LED, channelLED);
  ledcWrite(channelLED, 0);
}

void loop() {
  ledcWrite(channelLED, 0);
  delay(500);
  ledcWrite(channelLED, 200);
  delay(500);
}
