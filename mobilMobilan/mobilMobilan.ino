// Memasukkan library Motor Kontrol (AFMotor)
#include <AFMotor.h>

// Inisialisasi 5 pin sensor 
int sensor1 = A1;
int sensor2 = A2;
int sensor3 = A3;
int sensor4 = A4;
int sensor5 = A5;

// Inisialisasi pembacaan sensor
int menyala = 1;
int mati = 0;

// DC motor M1 dan M2
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);

void setup() {

  // Menjadikan sensor 1 sampai 5 sebagai input
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);
  pinMode(sensor4, INPUT);
  pinMode(sensor5, INPUT);

  motor1.run(RELEASE);
  motor2.run(RELEASE);

  // Mengaktifkan serial monitor
  Serial.begin(9600);
}

void loop() {
Serial.println("Jalan Lurus");
  motor1.setSpeed(150);
   motor2.setSpeed(150);
   motor1.run(BACKWARD);
   motor2.run(BACKWARD);
// Membaca sensor garis 1 sampai 5
int lampuSensor1 = digitalRead(sensor1);
int lampuSensor2 = digitalRead(sensor2);
int lampuSensor3 = digitalRead(sensor3);
int lampuSensor4 = digitalRead(sensor4);
int lampuSensor5 = digitalRead(sensor5);


// Kondisi yang menjadikan motor DC tidak berputar (berhenti)
if ( 
lampuSensor1 == mati && lampuSensor2 == menyala && lampuSensor3 == mati && lampuSensor4 == menyala && lampuSensor5 == mati ||
//lampuSensor1 == mati && lampuSensor2 == mati && lampuSensor3 == menyala && lampuSensor4 == menyala && lampuSensor5 == mati ||
lampuSensor1 == menyala && lampuSensor2 == menyala && lampuSensor3 == mati && lampuSensor4 == menyala && lampuSensor5 == menyala ||
//lampuSensor1 == mati && lampuSensor2 == menyala && lampuSensor3 == menyala && lampuSensor4 == menyala && lampuSensor5 == menyala ||
lampuSensor1 == menyala && lampuSensor2 == mati && lampuSensor3 == menyala && lampuSensor4 == menyala && lampuSensor5 == menyala ||
lampuSensor1 == menyala && lampuSensor2 == menyala && lampuSensor3 == menyala && lampuSensor4 == mati && lampuSensor5 == menyala){
  Serial.println("Motor DC (ban) Tidak berjalan");
  motor1.setSpeed(0);
   motor2.setSpeed(0);
   motor2.run(BACKWARD);
}

if(lampuSensor1 == mati && lampuSensor2 == mati && lampuSensor3 == mati && lampuSensor4 == mati && lampuSensor5 == mati){
  motor1.setSpeed(120);
   motor2.setSpeed(120);
      motor1.run(FORWARD);
   motor2.run(FORWARD);
   delay(100);
}


// Kondisi yang menjadikan mobil belok ke kiri
else  if (lampuSensor1 == mati && lampuSensor2 == menyala && lampuSensor3 == menyala && lampuSensor4 == menyala && lampuSensor5 == menyala ||
  lampuSensor1 == mati && lampuSensor2 == mati && lampuSensor3 == mati && lampuSensor4 == mati && lampuSensor5 == menyala ||
lampuSensor3 == menyala && lampuSensor4 == menyala && lampuSensor5 == menyala ||
lampuSensor3 == mati && lampuSensor4 == menyala && lampuSensor5 == menyala){
 Serial.println("Belok kiri");
  motor1.setSpeed(140);
   motor2.setSpeed(0);
   motor1.run(BACKWARD);
   motor2.run(BACKWARD);
   }


// Kondisi yang menjadikan mobil belok ke kanan 
else if (lampuSensor1 == menyala && lampuSensor2 == mati && lampuSensor3 == mati && lampuSensor4 == mati && lampuSensor5 == mati ||
lampuSensor1 == menyala && lampuSensor2 == menyala && lampuSensor3 == menyala ||
lampuSensor1 == menyala && lampuSensor2 == menyala && lampuSensor3 == mati ){
Serial.println("Belok kanan");
motor1.setSpeed(0);
motor2.setSpeed(140);
motor2.run(BACKWARD);   
}


// Kondisi yang menjadikan mobil jalan lurus
else if (
lampuSensor1 == menyala && lampuSensor2 == menyala && lampuSensor3 == menyala && lampuSensor4 == menyala && lampuSensor5 == menyala ||
  lampuSensor1 == mati && lampuSensor2 == mati && lampuSensor3 == menyala && lampuSensor4 == mati && lampuSensor5 == mati ||
lampuSensor1 == mati && lampuSensor2 == menyala && lampuSensor3 == menyala && lampuSensor4 == menyala && lampuSensor5 == mati ||
lampuSensor1 == mati && lampuSensor2 == menyala && lampuSensor3 == menyala && lampuSensor4 == mati && lampuSensor5 == mati ||
lampuSensor1 == mati && lampuSensor2 == menyala && lampuSensor3 == mati && lampuSensor4 == mati && lampuSensor5 == mati ||
lampuSensor1 == mati && lampuSensor2 == mati && lampuSensor3 == mati && lampuSensor4 == menyala && lampuSensor5 == mati ||
lampuSensor1 == mati && lampuSensor2 == mati && lampuSensor3 == menyala && lampuSensor4 == menyala && lampuSensor5 == mati) {
  Serial.println("Jalan Lurus");
  motor1.setSpeed(150);
   motor2.setSpeed(150);
   motor1.run(BACKWARD);
   motor2.run(BACKWARD);
} 


else {
  motor1.setSpeed(0);
   motor2.setSpeed(0);
   motor2.run(BACKWARD);
}
 
}
