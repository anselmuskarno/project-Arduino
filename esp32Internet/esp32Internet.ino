#include <WiFi.h>

const char* ssid = "TEACHER";
const char* password = "passwordbaru";

void setup() {
  Serial.begin(9600);
 
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid,password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  
}
void loop() {
  
}
