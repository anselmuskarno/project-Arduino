// Memasukkan library Motor Kontrol (AFMotor)
#include <AFMotor.h>
#include <Servo.h>
Servo myservo;  // Mendeskripsikan servo
const int trigPin = 10; // Triger pin (sensor Ultrasonik tengah) dipasang pada pin 10
const int echoPin = 9;  // Echo pin (sensor Ultrasonik tengah) dipasang pada pin 9
const int trigPinKiri = A3; // Triger pin (sensor Ultrasonik kiri) dipasang pada pin A3
const int echoPinKiri = A2; // Echo pin (sensor Ultrasonik kiri) dipasang pada pin A2
const int trigPinKanan = A5; // Triger pin (sensor Ultrasonik kanan) dipasang pada pin A5
const int echoPinKanan = A4; // Echo pin (sensor Ultrasonik kanan) dipasang pada pin A4

// DC motor M1 dan M2
AF_DCMotor motor1(1); // dipasang pada M1 di motor control L293D
AF_DCMotor motor2(3); // dipasang pada M3 di motor control L293D

void setup() {
 myservo.attach(A1);  // servo dipasang pada pin A1
  motor1.run(RELEASE); // mengaktifkan motor DC 1
  motor2.run(RELEASE); // mengaktifkan motor DC 2

  Serial.begin(9600); // Memulai perintah untuk serial monitor
  
}

long duration,durationKiri, durationKanan, cm, cmKiri, cmKanan, cm2, cm3; // mendefinisikan variabel yang akan digunakan pada sensor ultrasonik
 

void loop() {
//  delay(500);
Serial.println("============================================================================");
   motor1.setSpeed(95); //mengatur kecepatan motor1 menjadi 95
   motor2.setSpeed(150); //mengatur kecepatan motor2 menjadi 150
   motor1.run(FORWARD); //Perputaran roda (motor1 DC) ke depan
   motor2.run(FORWARD); //Perputaran roda (motor2 DC) ke depan

// AWAL ULTRASONIK TENGAH
pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  cm = microsecondsKeCenti(duration); //mengubah durasi sensor ultrasonik tengah menjadi centimeter
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
  cmKiri = microsecondsKeCenti(durationKiri); //mengubah durasi sensor ultrasonik kiri menjadi centimeter
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
  cmKanan = microsecondsKeCenti(durationKanan); //mengubah durasi sensor ultrasonik kanan menjadi centimeter
// AKHIR ULTRASONIK KANAN

  Serial.print("Depan : ");
  Serial.print(cm);   // menampilkan jarak sensor ultrasonik tengah ke monitor
  Serial.print(" cm");
  Serial.println();

  Serial.print("Kiri : ");
  Serial.print(cmKiri);  // menampilkan jarak sensor ultrasonik kiri ke monitor
  Serial.print(" cm");
  Serial.println();

  Serial.print("Kanan : ");
  Serial.print(cmKanan);  // menampilkan jarak sensor ultrasonik kanan ke monitor
  Serial.print(" cm");
  Serial.println();
  
 if (cm <= 13){ // jika jaraknya kurang atau sama dengan 13, maka motor akan berhenti
  Serial.print("Waktu pertama = ");
  Serial.print(cm);
  Serial.println(" cm");
  Serial.println("Sekarang dalam waktu delay");
// motor1 dan motor2 akan berhenti
 motor1.setSpeed(0);
   motor2.setSpeed(0);
   motor2.run(FORWARD);

myservo.write(0); // servo berputar ke sudut 0 derajat (kiri)
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
    myservo.write(180); //Servo berputar ke sudut 180 derajat (kanan)          
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
    
    myservo.write(90); //Servo berputar ke sudut 90 derajat (tengah)
    delay(1500);

if (cm2 > cm3 ){ // jika jarak ke kiri lebih besar dari yang kanan, maka .....
  
   motor1.setSpeed(120);
   motor2.setSpeed(120);
      motor1.run(BACKWARD);
   motor2.run(BACKWARD); // motor akan berputar mundur dengan kecepatan 120

   if(cm > 7){ // jika jaraknya ke depan lebih dari 7 cm, maka motor akan berputar mundur selama 0.150 detik
   delay(150);
   } 
   if(cm<=7){  // jika jaraknya ke depan kurang dari 7 cm, maka motor akan berputar mundur selama 0.300 detik
    delay(300);
   }
  Serial.println("Belok kiri"); 
  motor1.setSpeed(120); //Berputar ke kiri selama 0.120 detik
   motor2.setSpeed(0);
   motor1.run(FORWARD);
   motor2.run(FORWARD);
   delay(800);
} else if (cm2 < cm3){ // jika jarak ke kiri lebih kecil dari yang kanan, maka .....
  motor1.setSpeed(120);
   motor2.setSpeed(120);
      motor1.run(BACKWARD);
   motor2.run(BACKWARD); // motor akan berputar mundur dengan kecepatan 120

 if(cm > 7){  // jika jaraknya ke depan lebih dari 7 cm, maka motor akan berputar mundur selama 0.150 detik
   delay(150);
   } 
   if(cm<=7){ // jika jaraknya ke depan kurang dari 7 cm, maka motor akan berputar mundur selama 0.300 detik
    delay(300);
   }
   
  Serial.println("Belok kanan");  //Berputar ke kanan selama 0.120 detik
  motor1.setSpeed(0);
   motor2.setSpeed(120);
   motor1.run(FORWARD);
   motor2.run(FORWARD);
   delay(800);
}
  
  }  
else if (cmKanan<= 5  && cm>15) { // jika sensor ultrasonik yang ada di kanan mendeteksi objek kurang dari 5 cm dan jarak ke depan lebih dari 15 cm, maka .....
 Serial.println("KIRI ada benda didepan!!");
 motor1.setSpeed(0);
   motor2.setSpeed(60); // Ban akan berputar masuk ke tengah (berputar ke kanan) dengan kecepatan 60
      motor1.run(FORWARD);
   motor2.run(FORWARD);
   delay(0);
 }
  
 else if (cmKiri <= 10 && cm>15) {
 Serial.println("KANAN ada benda didepan!!");
 motor1.setSpeed(70); // Ban akan berputar masuk ke tengah (berputar ke kiri) dengan kecepatan 70
   motor2.setSpeed(0);
      motor1.run(FORWARD);
   motor2.run(FORWARD);
   delay(50);
 }

}

long microsecondsKeCenti(long microseconds) // Function yang akan merubah durasi ke jarak
{
  return microseconds / 29 / 2;
}
