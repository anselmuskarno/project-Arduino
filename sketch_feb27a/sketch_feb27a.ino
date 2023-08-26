//UNO

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
#define trigPin 10 //pasang pin D2 Arduino ke pin Triger HC-SR04
#define echoPin 11 // pasang pin D3 Arduino ke pin Echo HC-SR04
long duration; // variabel untuk durasi perjalanan gelombang suara
int distance; // variabel untuk pengukuran jarak
#include <SoftwareSerial.h>
SoftwareSerial Serial2(3, 2);
void setup() {
  // put your setup code here, to run once:
Serial2.begin(9600);
Serial.begin(9600);
  pinMode(trigPin, OUTPUT); // Menetapkan trigPin sebagai OUTPUT
  pinMode(echoPin, INPUT); // Menetapkan echoPin sebagai INPUTINPUT

}
void loop() {
  // put your main code here, to run repeatedly:

int sensorki=digitalRead(9); //baca sensor kiri
int sensorkiA=digitalRead(4); //baca sensor kiri
int sensorta=digitalRead(8); //baca sensor kanan
int sensorkaA=digitalRead(6); //baca sensor kanan
int sensorka=digitalRead(7); //baca sensor kanan    
 digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Menyetel trigPin TINGGI (AKTIF) selama 10 mikrodetik
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW); 
 duration = pulseIn(echoPin, HIGH);
  // Menghitung jarak
  distance = duration * 0.034 / 2; // Kecepatan gelombang suara dibagi 2 (pergi dan kembali)
//Serial.print("A : ");Serial.println(sensorki);
//Serial.print("B : ");Serial.println(sensorkiA);
//Serial.print("C : ");Serial.println(sensorta);
//Serial.print("D : ");Serial.println(sensorkaA);
//Serial.print("E : ");Serial.println(sensorka);Serial.println();
//delay(1000);
Serial.println(distance);
if(distance <= 50){
    Serial.println("Serial2 Mati");
     Serial2.println("f");
} else if((sensorki==0) && (sensorkiA==0) && (sensorka==0) && (sensorkaA==0)&& (sensorta==0)){
          Serial.println("Serial2 Mati");
//sensor kanan mendeteksi garis hitam
//belok kanan
 Serial2.println("a");
 
//delay(250);
      }
      else if((sensorki==1) && (sensorkiA==1) && (sensorka==1) && (sensorkaA==1)&& (sensorta==1)){
          Serial.println("Serial2 lurus");
//sensor kanan mendeteksi garis hitam
//belok kanan
 Serial2.println("b");
//delay(250);
      } 
      else if((sensorki==1) && (sensorkiA==1) && (sensorka==1) && (sensorkaA==1)&& (sensorta==1) ||
      (sensorki==1) && (sensorkiA==0) && (sensorta==0) && (sensorkaA==0)&& (sensorka==0) ||
       (sensorki==1) && (sensorkiA==1) && (sensorta==0) && (sensorkaA==0)&& (sensorka==0) ||
        (sensorki==1) && (sensorkiA==1) && (sensorta==1) && (sensorkaA==0)&& (sensorka==0))
{
   Serial.println("Belok KANAN");
//sensor kiri mendeteksi garis hitam
//belok kiri
 Serial2.println("c"); 
//delay(250);
}
else if((sensorki==0) && (sensorkiA==0) && (sensorta==1) && (sensorkaA==1)  && (sensorka==1) ||
      (sensorki==0) && (sensorkiA==0) && (sensorta==0) && (sensorkaA==1)&& (sensorka==1) ||
       (sensorki==0) && (sensorkiA==0) && (sensorta==0) && (sensorkaA==1)&& (sensorka==1) ||
        (sensorki==0) && (sensorkiA==0) && (sensorta==0) && (sensorkaA==0)&& (sensorka==1))
{
   Serial.println("Belok KIRI");
//sensor kiri mendeteksi garis hitam
//belok kiri
 Serial2.println("d"); 
// delay(250);
} 
else  if( (sensorki==0) && (sensorkiA==0) && (sensorta==1) && (sensorkaA==0)&& (sensorka==0)||
(sensorki==0) && (sensorkiA==1) && (sensorta==1) && (sensorkaA==0)&& (sensorka==0) ||
(sensorki==0) && (sensorkiA==0) && (sensorta==1) && (sensorkaA==1)&& (sensorka==0) ||
(sensorki==0) && (sensorkiA==1) && (sensorta==1) && (sensorkaA==1)&& (sensorka==0))
      {
        Serial.println("Serial2 Maju");
      //kedua sensor tidak mengenai garis hitam
      //gerak maju
      Serial2.println("e");
//      delay(250);
      } 
}
