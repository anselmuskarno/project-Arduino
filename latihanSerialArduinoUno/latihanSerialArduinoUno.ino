#include <SoftwareSerial.h>
SoftwareSerial mobil (2, 3); // 2 rx, 3 tx
//(34,35) esp32

String data;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
mobil.begin(9600);
}
void loop() {
// berikut data yang dibaca dari serial monitor sendiri, kemudian dikirim ke perangkat lain
 mobil.println("Sensorku");
 delay(1000);
}
