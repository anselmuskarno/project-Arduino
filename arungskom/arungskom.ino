const int trigPin = 19;
const int echoPin = 21;
#include <Servo.h>

#define SERVO_PIN 27 // ESP32 pin GIOP26 connected to servo motor

Servo servoMotor;

//define sound speed in cm/uS
#define SOUND_SPEED 0.034
#define CM_TO_INCH 0.393701

long duration;
float distanceCm;
float distanceInch;

void setup() {
  Serial.begin(115200); // Starts the serial communication
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
    servoMotor.attach(SERVO_PIN);  // attaches the servo on ESP32 pin
}

void loop() {
   servoMotor.write(90);
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance
  distanceCm = duration * SOUND_SPEED/2;
  
  // Convert to inches
  distanceInch = distanceCm * CM_TO_INCH;
  
  // Prints the distance in the Serial Monitor
  Serial.print("Distance (cm): ");
  Serial.println(distanceCm);
  Serial.print("Distance (inch): ");
  Serial.println(distanceInch);

if(distanceCm<10.00){
   digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance
  distanceCm = duration * SOUND_SPEED/2;
  
  // Convert to inches
  distanceInch = distanceCm * CM_TO_INCH;
  
  // Prints the distance in the Serial Monitor
  Serial.print("Distance (cm): ");
  Serial.println(distanceCm);
  Serial.print("Distance (inch): ");
  Serial.println(distanceInch);
   Serial.print("OKMBAIK");
   for (int pos = 0; pos <= 70; pos += 1) {
    // in steps of 1 degree
    servoMotor.write(2);
    delay(15); // waits 15ms to reach the position
  }
servoMotor.write(90); delay(3000);
  // rotates from 180 degrees to 0 degrees
  for (int pos = 70; pos >= 0; pos -= 1) {
    servoMotor.write(170);
    delay(15); // waits 15ms to reach the position
  }
} 
  
  delay(1000);
}
