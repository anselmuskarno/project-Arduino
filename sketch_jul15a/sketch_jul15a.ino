#include <Servo.h>
Servo servo2;
void setup() {
  // put your setup code here, to run once:
      servo2.attach(31);
}

void loop() {
  // put your main code here, to run repeatedly:
servo2.write(100);// buka
delay(2000);
servo2.write(180); // tutup
delay(2000);
}
