/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo servo2;  // create servo object to control a servo
Servo servo3;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  servo3.attach(34);  // attaches the servo on pin 9 to the servo object
  servo2.attach(40);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
}

void loop() {
delay(4000);

servo3.write(30);
delay(200);
servo3.write(90);
delay(200);
servo3.write(360);
delay(200);
servo3.write(90);
delay(200);
}
