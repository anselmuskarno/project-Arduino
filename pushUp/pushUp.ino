
#include <Servo.h>

Servo kaki1;
Servo kaki2;
Servo kaki3;
Servo kaki4;

Servo sendi1;
Servo sendi2;
Servo sendi3;
Servo sendi4;

int ulang = 0;
int pos = 0;
void setup() {
  Serial.begin(9600); 
  kaki1.attach(2);  // kaki 1 dipasang pada pin ke 2
  kaki2.attach(4);  // attaches the servo on pin 9 to the servo object
  kaki3.attach(6);  // attaches the servo on pin 9 to the servo object
  kaki4.attach(8);  // attaches the servo on pin 9 to the servo object
  
  sendi1.attach(10);  // attaches the servo on pin 9 to the servo object
  sendi2.attach(12);  // attaches the servo on pin 9 to the servo object
  sendi3.attach(13);  // attaches the servo on pin 9 to the servo object
  sendi4.attach(11);

}

void loop() { // pengulangan
  ulang++; // ulang ditambah 1
// ke bawah
kaki4.write(180);
sendi1.write(90);
kaki3.write(0);
sendi2.write(70);
kaki2.write(180);
sendi3.write(120);
kaki1.write(180);
sendi4.write(90);
delay(1000);

// ke atas
kaki4.write(0);
sendi1.write(90);
kaki3.write(180);
sendi2.write(70);
kaki2.write(0);
sendi3.write(120);
kaki1.write(0);
sendi4.write(90);
delay(1000);

Serial.print("Push Up ke : "); Serial.println(ulang);
if(ulang == 5 ){
  Serial.println("Berhenti");
  delay(10000);
  ulang = 0;
}
}
