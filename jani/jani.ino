#include <LiquidCrystal_I2C.h>

byte sensorPir = 7;

 #define trigPin 12
 #define echoPin 13
 #define trigPinB 2
 #define echoPinB 3

LiquidCrystal_I2C lcd(0x27, 16, 2);
 
 void setup() {
  Serial.begin(9600);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode(trigPinB, OUTPUT);
 pinMode(echoPinB, INPUT);
 pinMode(sensorPir, INPUT);
 lcd.begin();
  lcd.setCursor(0, 0);
  lcd.print("LOADING....                  ");
  lcd.setCursor(0, 1);
  lcd.print("                  ");
  delay(3000);
   lcd.setCursor(0, 0);
  lcd.print("JUMLAH JEMAAT :");
 
  delay(5000);
 } 

int ulang = 0;
int terdeteksi = HIGH;
int tidakTerdeteksi = LOW;
 
 void loop() {
 long duration,durationB, distance,distanceB;
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 distance = (duration/2) / 29.1;

digitalWrite(trigPinB, LOW); 
 delayMicroseconds(2); 
 digitalWrite(trigPinB, HIGH);
 delayMicroseconds(10); 
 digitalWrite(trigPinB, LOW);
 durationB = pulseIn(echoPinB, HIGH);
 distanceB = (durationB/2) / 29.1;
 
 lcd.backlight();
 Serial.print("Jarak Masuk : ");
 Serial.println(distance);
Serial.print("Jarak Keluar : ");
Serial.println(distanceB);

// && digitalRead(sensorPir) == terdeteksi
 // Awal Kode Masuk Ruangan
 if(distance <= 1000 && digitalRead(sensorPir) == terdeteksi){
//  delay(2000);

    ulang=ulang+1;
      lcd.setCursor(8, 1);
  lcd.print(ulang);

  delay(2000);
  Serial.print(ulang);
  Serial.println("OK");
  }
 
// Akhir Kode Masuk Ruangan

// Awal Kode Keluar Ruangan
if(distanceB <= 1000 && ulang>0 && digitalRead(sensorPir) == terdeteksi){
//  delay(2000);
    ulang=ulang-1;
  delay(1000);
    lcd.setCursor(8, 1);
  lcd.print(ulang);

  delay(2000);
 }
// Akhir Kode Keluar Ruangan 


 }
