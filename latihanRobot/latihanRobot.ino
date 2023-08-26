
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
}

void loop() {
kaki3.write(100);
sendi2.write(70);
kaki2.write(180);
sendi3.write(120);
kaki1.write(120);
sendi4.write(90);
kaki4.write(180);

 for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    sendi3.write(pos);              // tell servo to go to position in variable 'pos'
    delay(4);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    sendi3.write(pos);              // tell servo to go to position in variable 'pos'
    delay(4);                       // waits 15ms for the servo to reach the position
  }
for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    sendi3.write(pos);              // tell servo to go to position in variable 'pos'
    delay(4);                       // waits 15ms for the servo to reach the position
  }
  setup();
//==========================================================================

kaki4.write(90);
 sendi1.write(90);
kaki3.write(10);
sendi2.write(70);
kaki2.write(100);
sendi3.write(120);
kaki1.write(180);
 for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    sendi4.write(pos);              // tell servo to go to position in variable 'pos'
    delay(4);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    sendi4.write(pos);              // tell servo to go to position in variable 'pos'
    delay(4);                       // waits 15ms for the servo to reach the position
  }
for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    sendi4.write(pos);              // tell servo to go to position in variable 'pos'
    delay(4);                       // waits 15ms for the servo to reach the position
  }
  setup();
delay(3000);
//==========================================================================

kaki4.write(180);
sendi1.write(90);
kaki3.write(10);
sendi2.write(70);
kaki2.write(180);
sendi3.write(120);
kaki1.write(180);
sendi4.write(90);
delay(500);
kaki4.write(0);
sendi1.write(90);
kaki3.write(180);
sendi2.write(70);
kaki2.write(0);
sendi3.write(120);
kaki1.write(0);
sendi4.write(90);
delay(500);
kaki4.write(180);
sendi1.write(90);
kaki3.write(10);
sendi2.write(70);
kaki2.write(180);
sendi3.write(120);
kaki1.write(180);
sendi4.write(90);
delay(500);
kaki4.write(0);
sendi1.write(90);
kaki3.write(180);
sendi2.write(70);
kaki2.write(0);
sendi3.write(120);
kaki1.write(0);
sendi4.write(90);
delay(3000);
}
