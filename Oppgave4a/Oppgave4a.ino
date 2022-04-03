
const int ledPin = 4;
const int channelLED = 5;
int lysstyrke = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  ledcSetup(5, 2000, 8);
  ledcAttachPin(ledPin, channelLED);
  ledcWrite(ledPin, 0);

  Serial.begin(9600);
  
}

void blinkLed(){
  while(lysstyrke < 254){
    Serial.println(lysstyrke);
    lysstyrke += 1;
    ledcWrite(channelLED, lysstyrke);
    delay(15);
    }
  while(lysstyrke > 1){
    Serial.println(lysstyrke);
    lysstyrke -= 1;
    ledcWrite(channelLED, lysstyrke);
    delay(15);
    }
  }

void loop() {

  blinkLed();

  /*
  analogWrite(ledPin, 255);
  delay(500);
  analogWrite(ledPin, 0);
  delay(500); 
  */
}
