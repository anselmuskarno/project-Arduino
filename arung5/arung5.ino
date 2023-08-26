#include <Servo.h>

Servo myservo;  // create servo object to control a servo

//kiri
const int trigPin = 3;
const int echoPin = 4;
int blockAPin = 12; // Pin input
int blockBPin = 2; // Pin input
int blockCPin = 13; // Pin input
//int blockA = HIGH; // diberi logika high yang berarti tidak ada halangan
const int in1 = 8;
const int in2 = 7;
const int in3 = 9;
const int in4 = 10;
const int enA = 5;
const int enB = 6;

#define PWM 110
#define DIS 15

void setup() 
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
   pinMode(blockAPin, INPUT);
     pinMode(blockBPin, INPUT);
     pinMode(blockCPin, INPUT);
  pinMode (in1, OUTPUT);
  pinMode (in2, OUTPUT);
  pinMode (in3, OUTPUT);
  pinMode (in4, OUTPUT);
  pinMode (enA, OUTPUT);
  pinMode (enB, OUTPUT);
  myservo.attach(11);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600); 
}

//servo 

void loop()
{

//  Serial.println(digitalRead(blockAPin));
 
  Serial.println(FrontSensor ());
  if(digitalRead(blockCPin) == 0){
    stop();
    if(FrontSensor ()<6 && FrontSensor ()>0 ||FrontSensor ()>100 && FrontSensor ()>0){
      reverse();
      delay(200);
       stop();
    }
    
     Serial.println(digitalRead(blockAPin));
    
    int jarakKiri, jarakKanan;
    FrontSensor();
    Serial.print("Jarak Kiri: ");
    jarakKiri = FrontSensor();
    Serial.println(jarakKiri);
    myservo.write(180);
    delay(1000);
    myservo.write(100);
    delay(1000);
    myservo.write(10);
    delay(1000);
    FrontSensor();
    Serial.print("Jarak Kanan: ");   
    jarakKanan = FrontSensor();
     Serial.println(jarakKanan);
    delay(1000);
    myservo.write(100); 
    if(jarakKiri<15 && jarakKanan<15 ){
      turn_left ();
      delay(900);  
    }
    else if(jarakKiri>jarakKanan){
      Serial.println("KIRI");
        digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, 200); 
  analogWrite(enB, 200);
      delay(300); 
    } else {
      Serial.println("KANAN");
        digitalWrite(in1, LOW); 
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, 200);
  analogWrite(enB, 200);
      delay(300); 
    }
    
  }
   if(digitalRead(blockAPin) == 0){
    turn_right ();
    delay(80);
  }
  if(digitalRead(blockBPin) == 0){
    turn_left ();
    delay(80);
  }
   myservo.write(100); 
  forward();
  
}

void forward ()
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, PWM); 
  analogWrite(enB, PWM);
}

void turn_left () 
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, PWM); 
  analogWrite(enB, PWM);
}

void turn_right () 
{
  digitalWrite(in1, LOW); 
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, PWM);
  analogWrite(enB, PWM);
}

void reverse ()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, 180);
  analogWrite(enB, 180);
}

void stop()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enA, LOW);
  analogWrite(enB, LOW);
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
