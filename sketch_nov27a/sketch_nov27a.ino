

#include <Servo.h>

Servo kaki1,kaki2,kaki3,kaki4,sendi1,sendi2,sendi3,sendi4;

int pos = 0;
void setup() {
  Serial.begin(9600);

  kaki1.attach(2);  // attaches the servo on pin 9 to the servo object
  kaki2.attach(4);  // attaches the servo on pin 9 to the servo object
  kaki3.attach(6);  // attaches the servo on pin 9 to the servo object
  kaki4.attach(8);  // attaches the servo on pin 9 to the servo object
  
  sendi1.attach(10);  // attaches the servo on pin 9 to the servo object
  sendi2.attach(12);  // attaches the servo on pin 9 to the servo object
  sendi3.attach(13);  // attaches the servo on pin 9 to the servo object
  sendi4.attach(11);
}

void loop() {
  Serial.println("ok");
    kaki4.write(135);
 sendi1.write(120);
kaki3.write(60);
sendi2.write(105);
kaki2.write(160);
sendi3.write(75);
kaki1.write(160);
sendi4.write(60);
delay(500);

Serial.println("LANGKAH 1");
    kaki4.write(135);
 sendi1.write(120);
kaki3.write(60);
sendi2.write(105);
kaki2.write(180);
sendi3.write(75);
kaki1.write(160);
sendi4.write(60);
delay(500);

Serial.println("LANGKAH 2");
  kaki4.write(180);
 sendi1.write(120);
kaki3.write(60);
sendi2.write(105);
kaki2.write(180);
sendi3.write(75);
kaki1.write(160);
sendi4.write(60);
delay(500);

Serial.println("LANGKAH 3");
 kaki4.write(180);
 sendi1.write(45);
kaki3.write(60);
sendi2.write(105);
kaki2.write(180);
sendi3.write(75);
kaki1.write(160);
sendi4.write(60);
delay(500);

Serial.println("LANGKAH 4");
 kaki4.write(135);
 sendi1.write(45);
kaki3.write(60);
sendi2.write(105);
kaki2.write(180);
sendi3.write(75);
kaki1.write(160);
sendi4.write(60);
delay(500);

Serial.println("LANGKAH 5");

 kaki4.write(135);
 sendi1.write(45);
kaki3.write(60);
sendi2.write(105);
kaki2.write(160);
sendi3.write(75);
kaki1.write(160);
sendi4.write(60);
delay(500);

Serial.println("LANGKAH 6");

 kaki4.write(135);
 sendi1.write(45);
kaki3.write(0);
sendi2.write(105);
kaki2.write(160);
sendi3.write(75);
kaki1.write(180);
sendi4.write(60);
delay(500);

Serial.println("LANGKAH 7");

 kaki4.write(135);
 sendi1.write(45);
kaki3.write(45);
sendi2.write(105);
kaki2.write(160);
sendi3.write(75);
kaki1.write(180);
sendi4.write(60);
delay(500);

Serial.println("LANGKAH 8");

 kaki4.write(135);
 sendi1.write(45);
kaki3.write(45);
sendi2.write(70);
kaki2.write(160);
sendi3.write(75);
kaki1.write(180);
sendi4.write(60);
delay(500);

Serial.println("LANGKAH 9");

 kaki4.write(135);
 sendi1.write(45);
kaki3.write(80);
sendi2.write(70);
kaki2.write(160);
sendi3.write(75);
kaki1.write(180);
sendi4.write(60);
delay(500);

Serial.println("LANGKAH 10");

 
}
