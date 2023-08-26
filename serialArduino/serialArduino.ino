#include <SoftwareSerial.h>
SoftwareSerial arduino(4,3);

void setup() {
// put your setup code here, to run once:
Serial.begin(9600);
arduino.begin(9600);

}
int dataku=1;
void loop() {
// put your main code here, to run repeatedly:
arduino.println(dataku);
}
