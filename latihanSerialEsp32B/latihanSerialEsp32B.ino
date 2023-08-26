#include <SoftwareSerial.h>
SoftwareSerial mobil (3, 2); // 2 rx, 3 tx

String data;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
mobil.begin(9600);
}
void loop() {
String ancis = "";
while(mobil.available() > 0){
  ancis += char(mobil.read());
}
Serial.println(ancis);
delay(250);
}
