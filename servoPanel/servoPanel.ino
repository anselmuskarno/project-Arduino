const int relay = 10;
#include <Servo.h>
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
  pinMode(relay,OUTPUT);
  Serial.println("Delay 5 detik");
  delay(5000);
}

void loop() {
// myservo.write(0); //tutup 
// myservo.write(90); //henti 
// myservo.write(0); //buka 


//==============================
Serial.println("Pukul 07.30");
myservo.write(0);
delay(7250);
myservo.write(90);
for(int i=0; i<11; i++){
  Serial.print("Ulangan ke ");
  Serial.println(i);
  delay(1000);
}
//==============================
Serial.println("Pukul 08.00");
myservo.write(0);
delay(7250);
myservo.write(90);
for(int i=0; i<11; i++){
  Serial.print("Ulangan ke ");
  Serial.println(i);
   delay(1000);
}
//==============================
Serial.println("Pukul 08.30");
myservo.write(0);
delay(7250);
myservo.write(90);
for(int i=0; i<11; i++){
  Serial.print("Ulangan ke ");
  Serial.println(i);
   delay(1000);
}
//==============================
Serial.println("Pukul 09.00");
myservo.write(0);
delay(7250);
myservo.write(90);
for(int i=0; i<11; i++){
  Serial.print("Ulangan ke ");
  Serial.println(i);
   delay(1000);
}
//==============================
Serial.println("Pukul 09.30");
myservo.write(0);
delay(7250);
myservo.write(90);
for(int i=0; i<11; i++){
  Serial.print("Ulangan ke ");
  Serial.println(i);
   delay(1000);
}
//==============================
Serial.println("Pukul 10.00");
myservo.write(0);
delay(7250);
myservo.write(90);
for(int i=0; i<11; i++){
  Serial.print("Ulangan ke ");
  Serial.println(i);
   delay(1000);
}
//==============================
Serial.println("Pukul 10.30");
myservo.write(0);
delay(7250);
myservo.write(90);
for(int i=0; i<11; i++){
  Serial.print("Ulangan ke ");
  Serial.println(i);
   delay(1000);
}
//==============================
Serial.println("Pukul 11.00");
myservo.write(0);
delay(7250);
myservo.write(90);
for(int i=0; i<11; i++){
  Serial.print("Ulangan ke ");
  Serial.println(i);
   delay(1000);
}
//==============================
Serial.println("Pukul 11.30");
myservo.write(0);
delay(7250);
myservo.write(90);
for(int i=0; i<11; i++){
  Serial.print("Ulangan ke ");
  Serial.println(i);
   delay(1000);
}
//==============================
Serial.println("Pukul 12.00");
myservo.write(0);
delay(7250);
myservo.write(90);
for(int i=0; i<11; i++){
  Serial.print("Ulangan ke ");
  Serial.println(i);
   delay(1000);
}
//==============================
Serial.println("Pukul 12.30");
myservo.write(0);
delay(7250);
myservo.write(90);
for(int i=0; i<11; i++){
  Serial.print("Ulangan ke ");
  Serial.println(i);
   delay(1000);
}
//==============================
Serial.println("Pukul 13.00");
myservo.write(0);
delay(7250);
myservo.write(90);
for(int i=0; i<11; i++){
  Serial.print("Ulangan ke ");
  Serial.println(i);
   delay(1000);
}
//==============================
Serial.println("Pukul 13.30");
myservo.write(0);
delay(7250);
myservo.write(90);
for(int i=0; i<11; i++){
  Serial.print("Ulangan ke ");
  Serial.println(i);
   delay(1000);
}
//==============================
Serial.println("Pukul 14.00");
myservo.write(0);
delay(7250);
myservo.write(90);
for(int i=0; i<11; i++){
  Serial.print("Ulangan ke ");
  Serial.println(i);
   delay(1000);
}
//==============================
Serial.println("Pukul 14.30");
myservo.write(0);
delay(7250);
myservo.write(90);
for(int i=0; i<11; i++){
  Serial.print("Ulangan ke ");
  Serial.println(i);
   delay(1000);
}
//==============================
Serial.println("Pukul 15.00");
myservo.write(0);
delay(7250);
myservo.write(90);
for(int i=0; i<11; i++){
  Serial.print("Ulangan ke ");
  Serial.println(i);
   delay(1000);
}
//==============================
Serial.println("Pukul 15.30");
myservo.write(0);
delay(7250);
myservo.write(90);
for(int i=0; i<11; i++){
  Serial.print("Ulangan ke ");
  Serial.println(i);
   delay(1000);
}
//==============================
Serial.println("Pukul 16.00");
myservo.write(0);
delay(7250);
myservo.write(90);
for(int i=0; i<11; i++){
  Serial.print("Ulangan ke ");
  Serial.println(i);
   delay(1000);
}
//==============================
Serial.println("Pukul 16.30");
myservo.write(0);
delay(7250);
myservo.write(90);
for(int i=0; i<11; i++){
  Serial.print("Ulangan ke ");
  Serial.println(i);
   delay(1000);
}
//==============================
Serial.println("Pukul 17.00");
myservo.write(0);
delay(7250);
myservo.write(90);
for(int i=0; i<11; i++){
  Serial.print("Ulangan ke ");
  Serial.println(i);
   delay(1000);
}
//==============================
Serial.println("Kembali");
myservo.write(180);
delay(151000);
myservo.write(90);
for(int i=0; i<61; i++){
  Serial.print("Ulangan ke ");
  Serial.println(i);
   delay(1000);
}
}
