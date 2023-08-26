#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
#include <SoftwareSerial.h>
SoftwareSerial nosel (2, 3); 
#define trigPin 10 //pasang pin D2 Arduino ke pin Triger HC-SR04
#define echoPin 11 // pasang pin D3 Arduino ke pin Echo HC-SR04
long duration; // variabel untuk durasi perjalanan gelombang suara
int distance; // variabel untuk pengukuran jarak
String data;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
nosel.begin(9600);
pinMode(trigPin, OUTPUT); // Menetapkan trigPin sebagai OUTPUT
  pinMode(echoPin, INPUT); // Menetapkan echoPin sebagai INPUTINPUT
}
void loop() {

  int sensorki=digitalRead(9); //baca sensor kiri
int sensorkiA=digitalRead(4); //baca sensor kiri
int sensorta=digitalRead(8); //baca sensor kanan
int sensorkaA=digitalRead(6); //baca sensor kanan
int sensorka=digitalRead(7); //baca sensor kanan
//Serial.print("A : ");Serial.println(sensorki);
//Serial.print("B : ");Serial.println(sensorkiA);
//Serial.print("C : ");Serial.println(sensorta);
//Serial.print("D : ");Serial.println(sensorkaA);
//Serial.print("E : ");Serial.println(sensorka);Serial.println();

 digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Menyetel trigPin TINGGI (AKTIF) selama 10 mikrodetik
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW); 
 duration = pulseIn(echoPin, HIGH);
  // Menghitung jarak
  distance = duration * 0.034 / 2; // Kecepatan gelombang suara dibagi 2 (pergi dan kembali)

Serial.println(distance);
if(distance <= 50){
    Serial.println("Mobil Mati");
     nosel.println("f");
} else if((sensorki==0) && (sensorkiA==0) && (sensorka==0) && (sensorkaA==0)&& (sensorta==0)){
          Serial.println("Mobil Mati");
//sensor kanan mendeteksi garis hitam
//belok kanan
 nosel.println("a");
 
//delay(250);
      }
      else if((sensorki==1) && (sensorkiA==1) && (sensorka==1) && (sensorkaA==1)&& (sensorta==1)){
          Serial.println("Mobil lurus");
//sensor kanan mendeteksi garis hitam
//belok kanan
 nosel.println("b");
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
 nosel.println("c"); 
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
 nosel.println("d"); 
// delay(250);
} 
else  if( (sensorki==0) && (sensorkiA==0) && (sensorta==1) && (sensorkaA==0)&& (sensorka==0)||
(sensorki==0) && (sensorkiA==1) && (sensorta==1) && (sensorkaA==0)&& (sensorka==0) ||
(sensorki==0) && (sensorkiA==0) && (sensorta==1) && (sensorkaA==1)&& (sensorka==0) ||
(sensorki==0) && (sensorkiA==1) && (sensorta==1) && (sensorkaA==1)&& (sensorka==0))
      {
        Serial.println("Mobil Maju");
      //kedua sensor tidak mengenai garis hitam
      //gerak maju
      nosel.println("e");
//      delay(250);
      }
}
