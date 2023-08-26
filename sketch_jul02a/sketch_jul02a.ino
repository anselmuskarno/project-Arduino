/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo servo2;  // create servo object to control a servo
Servo myservo;  // create servo object to control a servo


void setup() {
  servo2.attach(40);  // attaches the servo on pin 9 to the servo object
  myservo.attach(34);  // attaches the servo on pin 9 to the servo object
}

void loop() {
servo2.write(30);
delay(300);
servo2.write(50);
delay(300);

myservo.write(360);
delay(400);
myservo.write(90);
delay(1000);
myservo.write(30);
delay(500);
myservo.write(90);
delay(200);

}
