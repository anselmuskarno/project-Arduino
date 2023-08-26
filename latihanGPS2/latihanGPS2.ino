#include <SoftwareSerial.h>
int RXPin = 3;
int TXPin = 4;
int GPSBaud = 9600;
SoftwareSerial gpsSerial(RXPin, TXPin);

void setup() {
  Serial.begin(9600);
  gpsSerial.begin(GPSBaud);

}

void loop() {
  while(gpsSerial.available()>0)
  Serial.write(gpsSerial.read());

}
