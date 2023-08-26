/*
 * This ESP32 code is created by esp32io.com
 *
 * This ESP32 code is released in the public domain
 *
 * For more detail (instruction and wiring diagram), visit https://esp32io.com/tutorials/esp32-servo-motor
 */

#include <Servo.h>

#define SERVO_PIN 27 // ESP32 pin GIOP26 connected to servo motor

Servo servoMotor;

void setup() {
  servoMotor.attach(SERVO_PIN);  // attaches the servo on ESP32 pin
}

void loop() {
servoMotor.write(10);
   delay(1000);
   servoMotor.write(90);
   delay(1000);
   servoMotor.write(170);
   delay(1000);
   servoMotor.write(90);
   Serial.print("OKMBAIK");
   delay(3000);
}
