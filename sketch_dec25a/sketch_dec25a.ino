#include <WiFi.h>;

void setup() {
 Serial.begin(9600);
 WiFi.begin("BERLIAN AMARISE","0819292819YSWKS2108");
 Serial.println("Connecting to Wifi");

while (WiFi.status() != WL_CONNECTED){
  Serial.print(".");
  delay(500);
}
 Serial.println("Berhasil");
}

void loop() {
  // put your main code here, to run repeatedly:

}
