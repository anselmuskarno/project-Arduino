#define SENSOR 26 // define pint 7 for sensor
#define ACTION 35 // define pin 10 as for ACTION
#define SENSOR2 32
#define SENSOR3 34
#include <Servo.h>
#include <OneWire.h>
#include <DallasTemperature.h>
float incomingByte = 0;
Servo servo1;
Servo servo2;
Servo servo3;
int pos;
const int stepPin = 28; 
const int dirPin = 30;

const int stepPin2 = 39; 
const int dirPin2 = 37; 

// Data wire is plugged into digital pin 2 on the Arduino
#define ONE_WIRE_BUS 24

// Setup a oneWire instance to communicate with any OneWire device
OneWire oneWire(ONE_WIRE_BUS);  

// Pass oneWire reference to DallasTemperature library
DallasTemperature sensors(&oneWire);


void setup() {
  Serial.begin(9600);// setup Serial Monitor to display information
//  Serial1.begin(9600);// setup Serial Monitor to display information
  pinMode(SENSOR, INPUT_PULLUP);// define pin as Input  sensor
  pinMode(SENSOR2, INPUT_PULLUP);
  pinMode(SENSOR3, INPUT_PULLUP);
  pinMode(ACTION, OUTPUT);// define pin as OUTPUT for ACTION

  servo1.attach(31);
  servo2.attach(22);
  servo3.attach(36);

  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);

 pinMode(stepPin2,OUTPUT); 
  pinMode(dirPin2,OUTPUT);

   sensors.begin();  // Start up the library
}

void loop() {

//if(Serial1.available()>0){
//  incomingByte = Serial1.read();
//  Serial.println(incomingByte);
//}

  int M =digitalRead(SENSOR);// read the sensor 
  int L =digitalRead(SENSOR2);
  int N =digitalRead(SENSOR3);
      if(L == 0){
    Serial.println(" Sensor1 mendeteksi objek");
    servo3.write(0);
    digitalWrite(ACTION,HIGH);// send singal

 digitalWrite(dirPin,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 400; x++) {
    digitalWrite(stepPin,HIGH); 
    delayMicroseconds(0); 
    digitalWrite(stepPin,LOW); 
    delayMicroseconds(0); 
     }
  
     digitalWrite(dirPin2,HIGH); // Enables the motor to move in a particular direction
  // Makes 200 pulses for making one full cycle rotation
  for(int y = 0; y < 600; y++) {
    digitalWrite(stepPin2,HIGH); 
    delayMicroseconds(0); 
    digitalWrite(stepPin2,LOW); 
    delayMicroseconds(0); 
     }
    
     }
     else if(M == 0){
     
    Serial.println(" Sensor2 mendeteksi objek, Servo berputar 2 kali");
      servo1.write(pos);
      digitalWrite(ACTION,HIGH);
     
     }else if(N == 0){
    Serial.println(" Sensor3 mendeteksi objek, Servo berputar 1 kali");
      servo2.write(0);
      
      digitalWrite(ACTION,HIGH);
     }
     
     else{
    servo1.write(90);
    servo2.write(90);
    servo3.write(90);

 digitalWrite(dirPin,HIGH); // Enables the motor to move in a particular direction
 digitalWrite(dirPin2,HIGH);
  // Makes 200 pulses for making one full cycle rotation
  for(int x = 0; x < 900; x++) {
    digitalWrite(stepPin,HIGH); 
    digitalWrite(stepPin2,HIGH); 
    delayMicroseconds(700); 
    digitalWrite(stepPin,LOW); 
    digitalWrite(stepPin2,LOW); 
    delayMicroseconds(700); 
  
     }

    
     Serial.println("  === Sensor tidak mendeteksi objek ");
    
     digitalWrite(ACTION,LOW);// turn the relay OFF
     }

 
}
