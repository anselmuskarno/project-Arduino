const int trigPin = 19;
const int echoPin = 21;

#include <Servo.h>

#define SERVO_PIN 27 // ESP32 pin GIOP26 connected to servo motor

Servo servoMotor;

//define sound speed in cm/uS
#define SOUND_SPEED 0.034
#define CM_TO_INCH 0.393701

long duration;
int distanceCm;
float distanceInch;

#define motorkif 26  //motor kiri maju
#define motorkib 25  //motor kiri mundur
#define motorkaf 33  //motor kanan maju
#define motorkab 32  //motor kanan mundur

void setup() {
    Serial.begin(115200); // Starts the serial communication
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
//Menentukan mode untuk masing-masing pin
  servoMotor.attach(SERVO_PIN);  // attaches the servo on ESP32 pin
pinMode(motorkif,OUTPUT);
pinMode(motorkib,OUTPUT);
pinMode(motorkaf,OUTPUT);
pinMode(motorkab,OUTPUT);
}

void loop() {

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

 if(distanceCm >= 0 && distanceCm < 11){
//kedua sensor tidak mengenai garis hitam
//gerak maju 
Serial.println("Mati");
digitalWrite(motorkaf,LOW);
digitalWrite(motorkab,LOW);
digitalWrite(motorkif,LOW);
digitalWrite(motorkib,LOW);
servoMotor.write(10);
   delay(1000);
   servoMotor.write(90);
   delay(1000);
   servoMotor.write(170);
   delay(1000);
   servoMotor.write(90);
   Serial.print("OKMBAIK");
   delay(3000);
 } else if( distanceCm > 11){
//kedua sensor tidak mengenai garis hitam
//gerak maju
digitalWrite(motorkaf,HIGH);
digitalWrite(motorkab,LOW);
digitalWrite(motorkif,HIGH);
digitalWrite(motorkib,LOW);
 }
}
