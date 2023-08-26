#include <SoftwareSerial.h>

SoftwareSerial mySerial(7,8);

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  Serial.println("Initializing....");
  delay(1000);
  mySerial.println("AT"); updateSerial();
  mySerial.println("AT+CSQ"); updateSerial();
  mySerial.println("AT+CCID"); updateSerial();
  mySerial.println("AT+GREG?"); updateSerial();

}

void loop() {
updateSerial();
}

void updateSerial(){
  delay(500);
  while(Serial.available()){
    mySerial.write(Serial.read());
  }
  
  while(mySerial.available()){
    Serial.write(mySerial.read());
  }
}
