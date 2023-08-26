
#include <SoftwareSerial.h>
SoftwareSerial nosel (2, 3); 
String data;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
nosel.begin(9600);
}
void loop() {
 nosel.println("Relay dinamo 1 Aktif");
}
