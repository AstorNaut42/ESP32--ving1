/*
  ESP32 Web Server - STA Mode
  modified on 25 MAy 2019
  by Mohammadreza Akbari @ Electropeak
  Home
*/

#include <WiFi.h>
#include <WebServer.h>

const int fotoPin = 32;

// Channels
const int channelFOTO = 0;

float sensorDataArr[2];
String HTMLdata;

// SSID & Password
const char* ssid = "Daniel's Galaxy S10";  // Enter your SSID here
const char* password = "Passord1337";  //Enter your Password here

WebServer server(80);  // Object of WebServer(HTTP port, 80 is defult)

void setup() {

  pinMode(fotoPin, INPUT);
  ledcSetup(0, 2000, 8);
  ledcAttachPin(fotoPin, channelFOTO);


  Serial.begin(115200);
  Serial.println("Try Connecting to ");
  Serial.println(ssid);

  // Connect to your wi-fi modem
  WiFi.begin(ssid, password);

  // Check wi-fi is connected to wi-fi network
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected successfully");
  Serial.print("Got IP: ");
  Serial.println(WiFi.localIP());  //Show ESP32 IP on serial

  server.on("/", handle_root);

  server.begin();
  Serial.println("HTTP server started");
  delay(100);
}

float mapfloat(long x, long in_min, long in_max, long out_min, long out_max) {
  return (float)(x - in_min) * (out_max - out_min) / (float)(in_max - in_min) + out_min;
}

// Handle root url (/)
void handle_root() {
  server.send(200, "text/html", html());
}


String html() {
  // HTML & CSS contents which display on web server
  String HTMLdata = "<!DOCTYPE html>"
                "<html>"
                "<head>"
                "<title>Sensordata</title>"
                "<meta http-equiv='refresh' content='2'>"
                "</head>"
                "<body>"
                "<h1>Sensordata:</h1>"
                "</body>"
                "</html>";

  HTMLdata += "<h2>Sensor 1: ";
  HTMLdata += sensorDataArr[0];
  HTMLdata += "</h2>";

  HTMLdata += "<h2>Sensor 2: ";
  HTMLdata += sensorDataArr[1];
  HTMLdata += "</h2>";

  return HTMLdata;

}


void loop() {
  
  float fotoValue = analogRead(fotoPin);
  sensorDataArr[0] = mapfloat(fotoValue, 0, 4096, 0, 3.3);

  server.handleClient();
  html();
}
