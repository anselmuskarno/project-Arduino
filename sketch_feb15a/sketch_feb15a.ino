// Include the Arduino Stepper Library
const int relay3 = 7;
#include <Stepper.h>
#include <Wire.h>

const int LDR = A0;
int cahayaMatahari = 0;

// Number of steps per output rotation
const int stepsPerRevolution = 200;

// Create Instance of Stepper library
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);


void setup()
{
  pinMode(relay3,OUTPUT);
  // set the speed at 60 rpm:
  myStepper.setSpeed(60);
  // initialize the serial port:
  Serial.begin(9600);
 
}

void loop() 
{
  cahayaMatahari = analogRead(LDR);
  
      Serial.println(cahayaMatahari);
  // step one revolution in one direction:
   
    digitalWrite(relay3, LOW);
  Serial.println("berputar");
  myStepper.step(-stepsPerRevolution);
  digitalWrite(relay3, HIGH);
  
   
  // step one revolution in the other direction:
//  Serial.println("counterclockwise");
//  myStepper.step(-stepsPerRevolution);
//  delay(500);
}
