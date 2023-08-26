
#include <Servo.h>

Servo kaki1;
Servo kaki2;
Servo kaki3;
Servo kaki4;

Servo sendi1;
Servo sendi2;
Servo sendi3;
Servo sendi4;

int pos = 0;
void setup() {
  kaki1.attach(2);  // attaches the servo on pin 9 to the servo object
  kaki2.attach(4);  // attaches the servo on pin 9 to the servo object
  kaki3.attach(6);  // attaches the servo on pin 9 to the servo object
  kaki4.attach(8);  // attaches the servo on pin 9 to the servo object
  
  sendi1.attach(10);  // attaches the servo on pin 9 to the servo object
  sendi2.attach(12);  // attaches the servo on pin 9 to the servo object
  sendi3.attach(13);  // attaches the servo on pin 9 to the servo object
  sendi4.attach(11);

   kaki4.write(90);
 sendi1.write(90);
kaki3.write(100);
sendi2.write(70);
kaki2.write(100);
sendi3.write(120);
kaki1.write(120);
sendi4.write(90);
delay(3000);
Serial.begin(9600);
}

void loop() {
kaki3.write(100);
sendi2.write(70);
kaki2.write(180);
sendi3.write(120);
kaki1.write(120);
sendi4.write(90);
kaki4.write(180);
sendi3.write(0);
Serial.println("maju");
delay(500);
Serial.println("tutup");
kaki2.write(100);
delay(500);
}
