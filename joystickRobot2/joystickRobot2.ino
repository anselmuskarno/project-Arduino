int xValue = 0 ;
int yValue = 0 ; 
int bValue = 0 ;

#include <Servo.h>

Servo kaki1;
Servo kaki2;
Servo kaki3;
Servo kaki4;

Servo sendi1;
Servo sendi2;
Servo sendi3;
Servo sendi4;

int pos = 0;
void setup() {
  Serial.begin(9600);
  pinMode(A2,INPUT); 
  digitalWrite(A2,HIGH); 
  kaki1.attach(2);  // attaches the servo on pin 9 to the servo object
  kaki2.attach(4);  // attaches the servo on pin 9 to the servo object
  kaki3.attach(6);  // attaches the servo on pin 9 to the servo object
  kaki4.attach(8);  // attaches the servo on pin 9 to the servo object
  
  sendi1.attach(10);  // attaches the servo on pin 9 to the servo object
  sendi2.attach(12);  // attaches the servo on pin 9 to the servo object
  sendi3.attach(13);  // attaches the servo on pin 9 to the servo object
  sendi4.attach(11);

//   kaki4.write(90);
// sendi1.write(90);
//kaki3.write(100);
//sendi2.write(70);
//kaki2.write(100);
//sendi3.write(120);
//kaki1.write(120);
//sendi4.write(90);
delay(3000);
}

void loop() {
  Serial.println("ok");
    kaki4.write(135);
 sendi1.write(120);
kaki3.write(60);
sendi2.write(105);
kaki2.write(160);
sendi3.write(75);
kaki1.write(160);
sendi4.write(60);

 
}
