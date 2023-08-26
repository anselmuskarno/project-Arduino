/*********
  Rui Santos
  Complete project details at https://randomnerdtutorials.com  
*********/

#include <ESP32Servo.h>

Servo myservo; 

// Motor A

//tengah
const int trigPin = 19; 
const int echoPin = 21;

int motor1Pin1 = 26; 
int motor1Pin2 = 25; 
int enable1Pin = 18; 
int motor2Pin1 = 33; 
int motor2Pin2 = 32; 
int enable2Pin = 5; 

// Setting PWM properties
const int freq = 30000;
const int pwmChannel = 0;
const int resolution = 8;
int dutyCycle = 200;

void setup() {
    pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  // sets the pins as outputs:
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(enable1Pin, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  pinMode(enable2Pin, OUTPUT);
  
  // configure LED PWM functionalitites
  ledcSetup(pwmChannel, freq, resolution);
  
  // attach the channel to the GPIO to be controlled
  ledcAttachPin(enable1Pin, pwmChannel);
  ledcAttachPin(enable2Pin, pwmChannel);

  Serial.begin(115200);

 
}

void maju(){
    // Move the DC motor forward at maximum speed
  Serial.println("Moving Forward");
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH); 
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH); 
}

void berhenti(){
    // Move the DC motor forward at maximum speed
  Serial.println("Moving Forward");
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW); 
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW); 
}

void loop() {
     myservo.write(180);
     long dur;
     long jarak;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(5); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  dur = pulseIn(echoPin, HIGH);
  jarak = dur* 0.034 / 2;
  Serial.println(jarak);
    if(jarak >= 21){
maju();      
    } else if(jarak <= 20){
      berhenti();
      delay(1000);
        myservo.write(11);
        delay(1000);
        myservo.write(90);
         delay(1000);
        myservo.write(180);
         delay(1000);
    }

//  delay(2000);

  // Stop the DC motor
//  Serial.println("Motor stopped");
//  digitalWrite(motor1Pin1, LOW);
//  digitalWrite(motor1Pin2, LOW);
//  delay(1000);
//
//  // Move DC motor backwards at maximum speed
//  Serial.println("Moving Backwards");
//  digitalWrite(motor1Pin1, HIGH);
//  digitalWrite(motor1Pin2, LOW); 
//  delay(2000);
//
//  // Stop the DC motor
//  Serial.println("Motor stopped");
//  digitalWrite(motor1Pin1, LOW);
//  digitalWrite(motor1Pin2, LOW);
//  delay(1000);
//
//  // Move DC motor forward with increasing speed
//  digitalWrite(motor1Pin1, HIGH);
//  digitalWrite(motor1Pin2, LOW);
   ledcWrite(pwmChannel, dutyCycle);   

  dutyCycle = 255;
}

long FrontSensor ()
{
  long dur;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(5); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  dur = pulseIn(echoPin, HIGH);
  return (dur* 0.034 / 2);
}

void tengokKiri(){
   myservo.write(90);
   
}
