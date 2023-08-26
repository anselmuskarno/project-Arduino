#include <SoftwareSerial.h>
SoftwareSerial arduino(4, 3);
#include "ESP8266HTTPClient.h"
#include "ESP8266WiFi.h"
WiFiClient client;
#include <ThingSpeak.h>
String apikey ="P0PEVKCWEKKPE22E";
const char* ssid = "Vivo y20s";
const char* password = "senyumdulu";
const char* server = "api.thingspeak.com";
unsigned long myChannelNumber=1840303;
const char * myWriteAPIKey ="P0PEVKCWEKKPE22E";


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  arduino.begin(9600);
   Serial.println("connected");
  WiFi.begin(ssid, password);
  ThingSpeak.begin(client);
}
void loop() {

  delay(100);
  // put your main code here, to run repeatedly:
  String data = "";
  while (arduino.available() > 0) {
    data += char(arduino.read());
  }
  Serial.println(data);
  ThingSpeak.writeField(myChannelNumber, 1, data, myWriteAPIKey);
}
