#include <SoftwareSerial.h>
SoftwareSerial nosel (2, 3); // 2 rx, 3 tx
const int relay = 7;
const int relay2 = 6;
const int relayHeater = 5;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
nosel.begin(9600);
pinMode(relayHeater,OUTPUT);
pinMode(relay,OUTPUT);
pinMode(relay2,OUTPUT);
}

void loop() {
  String bung;
while(nosel.available() > 0){
  bung += char(nosel.read());
  }
  Serial.println(bung);
   digitalWrite(relay, HIGH);
  if(bung == "coba"){
    Serial.println("ok=================================================================");
     digitalWrite(relay, LOW);
     delay(3000);
  }
}
