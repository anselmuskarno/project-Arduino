// Memasukkan library Motor Kontrol (AFMotor)
#include <AFMotor.h>
#include <Servo.h>
Servo myservo;  // create servo object to control a servo
const int trigPin = 10;
const int echoPin = 9;
const int trigPinKiri = A3;
const int echoPinKiri = A2;
const int trigPinKanan = A5;
const int echoPinKanan = A4;

// DC motor M1 dan M2
AF_DCMotor motor1(1);
AF_DCMotor motor2(3);

void setup() {
 myservo.attach(A1);  // attaches the servo on pin 9 to the servo object
  motor1.run(RELEASE);
  motor2.run(RELEASE);

  // Mengaktifkan serial monitor
  Serial.begin(9600);
  
}

long duration,durationKiri, durationKanan, cm, cmKiri, cmKanan, cm2, cm3;
 

void loop() {
//  delay(500);
Serial.println("============================================================================");
   motor1.setSpeed(95);
   motor2.setSpeed(150);
   motor1.run(FORWARD);
   motor2.run(FORWARD);

// AWAL ULTRASONIK TENGAH
pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  cm = microsecondsKeCenti(duration);
// AKHIR ULTRASONIK TENGAH

// AWAL ULTRASONIK KIRI
  pinMode(trigPinKiri, OUTPUT);
  digitalWrite(trigPinKiri, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinKiri, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinKiri, LOW);
  pinMode(echoPinKiri, INPUT);
  durationKiri = pulseIn(echoPinKiri, HIGH);
  cmKiri = microsecondsKeCenti(durationKiri);
// AKHIR ULTRASONIK KIRI

// AWAL ULTRASONIK KANAN
  pinMode(trigPinKanan, OUTPUT);
  digitalWrite(trigPinKanan, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinKanan, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinKanan, LOW);
   pinMode(echoPinKanan, INPUT);
  durationKanan = pulseIn(echoPinKanan, HIGH);
  cmKanan = microsecondsKeCenti(durationKanan);
// AKHIR ULTRASONIK KANAN

  Serial.print("Depan : ");
  Serial.print(cm);
  Serial.print(" cm");
  Serial.println();

  Serial.print("Kiri : ");
  Serial.print(cmKiri);
  Serial.print(" cm");
  Serial.println();

  Serial.print("Kanan : ");
  Serial.print(cmKanan);
  Serial.print(" cm");
  Serial.println();
  
 if (cm <= 13){
  Serial.print("Waktu pertama = ");
  Serial.print(cm);
  Serial.println(" cm");
  Serial.println("Sekarang dalam waktu delay");
//delay(1000);
 motor1.setSpeed(0);
   motor2.setSpeed(0);
   motor2.run(FORWARD);

myservo.write(0);
Serial.println("Melihat ke kiri");
delay(700);          
pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  cm2 = microsecondsKeCenti(duration);
  Serial.print(cm2);
  Serial.print(" cm2");
  Serial.println();                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
    delay(700); 
    myservo.write(180);              // tell servo to go to position in variable 'pos'  
    Serial.println("Melihat ke kanan");
    delay(300);
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  cm3 = microsecondsKeCenti(duration);
  Serial.print(cm3);
  Serial.print(" cm3");
  Serial.println();                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
    delay(550); 
    
    myservo.write(90);
    delay(1500);

if (cm2 > cm3 ){
  
   motor1.setSpeed(120);
   motor2.setSpeed(120);
      motor1.run(BACKWARD);
   motor2.run(BACKWARD);

   if(cm > 7){
   delay(150);
   } 
   if(cm<=7){
    delay(300);
   }
  Serial.println("Belok kiri");
  motor1.setSpeed(120);
   motor2.setSpeed(0);
   motor1.run(FORWARD);
   motor2.run(FORWARD);
   delay(800);
} else if (cm2 < cm3){
  motor1.setSpeed(120);
   motor2.setSpeed(120);
      motor1.run(BACKWARD);
   motor2.run(BACKWARD);

 if(cm > 7){
   delay(150);
   } 
   if(cm<=7){
    delay(300);
   }
   
  Serial.println("Belok kanan");
  motor1.setSpeed(0);
   motor2.setSpeed(120);
   motor1.run(FORWARD);
   motor2.run(FORWARD);
   delay(800);
}
  
  }  
else if (cmKanan<= 5  && cm>15) {
 Serial.println("KIRI ada benda didepan!!");
 motor1.setSpeed(0);
   motor2.setSpeed(60);
      motor1.run(FORWARD);
   motor2.run(FORWARD);
   delay(0);
 }
  
 else if (cmKiri <= 10 && cm>15) {
 Serial.println("KANAN ada benda didepan!!");
 motor1.setSpeed(70);
   motor2.setSpeed(0);
      motor1.run(FORWARD);
   motor2.run(FORWARD);
   delay(50);
 }

// motor1.setSpeed(70);
//   motor2.setSpeed(60);
//   motor1.run(FORWARD);
//   motor2.run(FORWARD);
//delay(100);
}

long microsecondsKeCenti(long microseconds)
{
  return microseconds / 29 / 2;
}
