#define trigPin 36 //pasang pin D2 Arduino ke pin Triger HC-SR04
#define echoPin 38 // pasang pin D3 Arduino ke pin Echo HC-SR04

long duration; // variabel untuk durasi perjalanan gelombang suara
int distance; // variabel untuk pengukuran jarak

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <MFRC522.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);
const int PIN_RST = 8;  
const int PIN_SS  = 9; 
int pinBuzzer= 7;
const int ledMC = 22;
const int ledHC = 24;
const int ledMB = 26;
const int ledHB = 28;
const int ledMA = 30;
const int ledHA = 32;
String uidTag = "";     
#include <Servo.h>
int blockAPin = 2; // Pin input
int blockA = HIGH; // diberi logika high yang berarti tidak ada halangan
int blockCPin = 6; // Pin input
int blockC = HIGH; // diberi logika high yang berarti tidak ada halangan
int blockB1Pin = 3; // Pin input
int blockB1 = HIGH; // diberi logika high yang berarti tidak ada halangan
int blockB2Pin = 4; // Pin input
int blockB2 = HIGH; // diberi logika high yang berarti tidak ada halangan

Servo myservo;  // create servo object to control a servo
// Pembuatan objek MFRC522 
MFRC522 mfrc(PIN_SS, PIN_RST); 
//sketch created by Akshay Joseph
#include <Wire.h> 
int ulang=0;
int nilaiServo=0;
void setup() {
    myservo.attach(10);  // attaches the servo on pin 9 to the servo object
    pinMode(ledMC, OUTPUT);
    pinMode(ledHC, OUTPUT);
    pinMode(ledMB, OUTPUT);
    pinMode(ledHB, OUTPUT);
    pinMode(ledMA, OUTPUT);
    pinMode(ledHA, OUTPUT);
     pinMode(blockAPin, INPUT);
       pinMode(blockCPin, INPUT);
       pinMode(blockB1Pin, INPUT);
       pinMode(blockB2Pin, INPUT);
  pinMode(pinBuzzer, OUTPUT);
   pinMode(trigPin, OUTPUT); // Menetapkan trigPin sebagai OUTPUT
  pinMode(echoPin, INPUT); // Menetapkan echoPin sebagai INPUTINPUT
    lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0);
   lcd.print("    ");
  lcd.setCursor(3, 0);
  lcd.print("SMART PARKING");
  lcd.setCursor(2, 1);
  lcd.print("UNIV. TEKNOLOGI");
  lcd.setCursor(3, 2);
  lcd.print("AKBA MAKASSAR");
  lcd.setCursor(2, 3);
  lcd.print("AFRIANTO ISMAIL");
  delay(5000);
  lcd.clear();
  Serial.begin(9600);
  SPI.begin();  
  mfrc.PCD_Init(); 

  // Cek versi software MFRC555
  byte versi = mfrc.PCD_ReadRegister(mfrc.VersionReg);
  if (versi == 0x00 || versi == 0xFF) {
    Serial.println("Modul tidak ada!");
    while (true);    
  }
  
  Serial.print("Tempelkan Kartu!");

}
int nilaiA=10;  //Nilai awal Block A
int nilaiB=10;  //Nilai awal Block B
int nilaiC=10;  //Nilai awal Block C
int parameter=0;  // 0 berarti kartu belum ditempel
                  //parameter untuk deteksi kartu
                  // 0 = kartu belum ditempel
                  // 1 = kartu sudah terdeteksi


void loop() {
    digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Menyetel trigPin TINGGI (AKTIF) selama 10 mikrodetik
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW); 
 duration = pulseIn(echoPin, HIGH);
  // Menghitung jarak
  distance = duration * 0.034 / 2; // Kecepatan gelombang suara dibagi 2 (pergi dan kembali)
  // Menampilkan jarak pada Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
 
//lcd.setCursor(0,0);
//  lcd.print("Jarak: ");
//  lcd.print(distance);
//  lcd.print(" cm                        ");
//  delay(100);
//  delay(500);   //Jeda stengah detik
  if(nilaiC == 0){
   digitalWrite(ledMC, HIGH);
   digitalWrite(ledHC, LOW); 
  }
  if(nilaiB == 0){
   digitalWrite(ledMB, HIGH);
   digitalWrite(ledHB, LOW); 
  }  
  if(nilaiA == 0){
   digitalWrite(ledMA, HIGH);
   digitalWrite(ledHA, LOW); 
  }
  if(nilaiC > 0){
   digitalWrite(ledMC, LOW);
   digitalWrite(ledHC, HIGH); 
  }
 if(nilaiB > 0){
   digitalWrite(ledMB, LOW);
   digitalWrite(ledHB, HIGH); 
  }
  if(nilaiA > 0){
   digitalWrite(ledMA, LOW);
   digitalWrite(ledHA, HIGH); 
  }
  Serial.print("Parameter = ");
  Serial.println(parameter);
     blockA = digitalRead(blockAPin);  // proses deteksi sensor block A
     blockC = digitalRead(blockCPin); // proses deteksi sensor block C
      blockB1 = digitalRead(blockB1Pin); // proses deteksi sensor block B1
     blockB2 = digitalRead(blockB2Pin);  // proses deteksi sensor block B2

if(parameter==4 && distance>=2 && distance<=10){
  nilaiA+=1;
   lcd.clear();
 lcd.setCursor(3, 1);
  lcd.print("TERIMA");
      lcd.setCursor(3, 2);
  lcd.print("KASIH");
  lcd.setCursor(5, 3);
  lcd.print("");
   digitalWrite(pinBuzzer, HIGH);

delay(3000);

digitalWrite(pinBuzzer, LOW);

  delay(2000);
  myservo.write(90);   


//awal===========================================================================
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}

perhitungan();
if(distance<10){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
 if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10 ){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();

if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}

perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance<10){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
 if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10 ){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();

if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}

perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}

if(nilaiServo>0 && ulang>0){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}



 //akhir===========================================================================

 
 lcd.clear();
 parameter=0;
}

if(parameter==5 && distance>=2 && distance<=10){
  nilaiB+=1;
   lcd.clear();
 lcd.setCursor(3, 1);
  lcd.print("TERIMA");
      lcd.setCursor(3, 2);
  lcd.print("KASIH");
  lcd.setCursor(5, 3);
  lcd.print("");
   digitalWrite(pinBuzzer, HIGH);

delay(3000);

digitalWrite(pinBuzzer, LOW);

  delay(2000);
  myservo.write(90);   


//awal===========================================================================
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}

perhitungan();
if(distance<10){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
 if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10 ){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();

if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}

perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance<10){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
 if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10 ){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();

if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}

perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}

if(nilaiServo>0 && ulang>0){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}



 //akhir===========================================================================

 
 lcd.clear();
 parameter=0;
}

if(parameter==6 && distance>=2 && distance<=10){
  nilaiC+=1;
   lcd.clear();
 lcd.setCursor(3, 1);
  lcd.print("TERIMA");
      lcd.setCursor(3, 2);
  lcd.print("KASIH");
  lcd.setCursor(5, 3);
  lcd.print("");
   digitalWrite(pinBuzzer, HIGH);

delay(3000);

digitalWrite(pinBuzzer, LOW);

  delay(2000);
  myservo.write(90);   


//awal===========================================================================
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}

perhitungan();
if(distance<10){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
 if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10 ){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();

if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}

perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance<10){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
 if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10 ){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();

if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}

perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}

if(nilaiServo>0 && ulang>0){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}



 //akhir===========================================================================

  
 lcd.clear();
 parameter=0;
}
     
 if (blockA == LOW && parameter==0 && nilaiA<10) {   // LOW berarti terdeteksi
                                      //Maksimal jumlah slot A adalah 10
//  delay(1000);
 Serial.println("ada benda didepan!!");

parameter=4;
delay(1000);
 }
 if (blockA == LOW && parameter==1) {

//  delay(1000);
 Serial.println("ada benda didepan!!");
nilaiA-=1;
delay(1000);  //Jeda 1 detik
parameter=0;  //reset parameter
 }

 if (blockB1 == LOW && parameter==0 && nilaiB<10) {

Serial.println("ada benda didepan!!");

parameter=5;
delay(1000);
 }
 if (blockB1 == LOW && parameter==1) {

//  delay(1000);
 Serial.println("ada benda didepan!!");
nilaiB-=1;
delay(1000);
parameter=0;
 }

 if (blockB2 == LOW && parameter==0 && nilaiB<10) {
Serial.println("ada benda didepan!!");

parameter=5;
delay(1000);
 }
 if (blockB2 == LOW && parameter==1) {

//  delay(1000);
 Serial.println("ada benda didepan!!");
nilaiB-=1;
delay(1000);
parameter=0;
 }

 if (blockC == LOW && parameter==0 && nilaiC<10) {
Serial.println("ada benda didepan!!");

parameter=6;
delay(1000);
 }
 if (blockC == LOW && parameter==1 && nilaiC>=1) {
 Serial.println("ada benda didepan!!");
nilaiC-=1;
delay(1000);
parameter=0;
 }
 
digitalWrite(pinBuzzer, LOW);
    lcd.setCursor(0, 0);
  lcd.print("TEMPELKAN KARTU");
  lcd.setCursor(0, 1);
  lcd.print("BLOCK A SISA : ");
  lcd.print(nilaiA);
  if(nilaiA<10){
    lcd.setCursor(16, 1);
  lcd.print("  ");
  }
  lcd.setCursor(0, 2);
  lcd.print("BLOCK B SISA : ");
  lcd.print(nilaiB);
  if(nilaiB<10){
    lcd.setCursor(16, 2);
  lcd.print("  ");
  }
  lcd.setCursor(0, 3);
  lcd.print("BLOCK C SISA : ");
  lcd.print(nilaiC);
  if(nilaiC<10){
    lcd.setCursor(16, 3);
  lcd.print("  ");
  }
   myservo.write(180); 
   
   //awal masuk pembacaan kartu 
  if (!mfrc.PICC_IsNewCardPresent())
    return;
Serial.print("Ada kartu 2");
parameter=1;
nilaiServo=1;
  // Jika nomor tag tidak terdeteksi
  if (!mfrc.PICC_ReadCardSerial())
    return;
Serial.print("Ada kartu 1");
  // UID terdeteksi
  uidTag = "";
  for (byte j = 0; j < mfrc.uid.size; j++) {
    char teks[3];
    sprintf(teks, "%02X", mfrc.uid.uidByte[j]);
    uidTag += teks;
  }
  Serial.print(" Nomor UID : ");
  Serial.println(uidTag);
//akhir masuk pembacaan kartu
if(uidTag=="C80D3A27"){
  parameter=0;
  lcd.clear();
 lcd.setCursor(3, 1);
  lcd.print("AKSES ADMIN");
      lcd.setCursor(3, 2);
  lcd.print("DITERIMA");
  lcd.setCursor(5, 3);
  lcd.print("");
   digitalWrite(pinBuzzer, HIGH);

delay(3000);

digitalWrite(pinBuzzer, LOW);

  delay(2000);
  myservo.write(90);   

//awal===========================================================================
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}

perhitungan();
if(distance<10){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
 if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10 ){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();

if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}

perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance<10){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
 if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10 ){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();

if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}

perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}

if(nilaiServo>0 && ulang>0){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}



 //akhir===========================================================================

  
 lcd.clear();
}

 if(parameter==1 && uidTag=="818B5426"){
lcd.clear();
 lcd.setCursor(3, 0);
  lcd.print("MOHON MAAF");
      lcd.setCursor(0, 2);
  lcd.print("ID TIDAK TERDAFTAR");
  lcd.setCursor(5, 3);
  lcd.print("");
  digitalWrite(pinBuzzer, HIGH);

delay(3000);

digitalWrite(pinBuzzer, LOW);

  delay(2000);
 myservo.write(180);   
 delay(2000);
  
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("SILAHKAN");
      lcd.setCursor(0, 2);
  lcd.print("MENGHUBUNGI ADMIN");
  delay(3000);
  parameter=0;
  lcd.clear();
  Serial.print("Akses Diterima");
   blockB1 = digitalRead(blockB1Pin);
 blockB2 = digitalRead(blockB2Pin);
  }
  //awal masuk block A
  if(parameter==1 && nilaiA>0 && nilaiC>0 && nilaiB>0){ 
lcd.clear();

 lcd.setCursor(6, 0);
  lcd.print("WELCOME");
      lcd.setCursor(7, 2);
  lcd.print("AKSES");
  lcd.setCursor(5, 3);
  lcd.print("DITERIMA");
  digitalWrite(pinBuzzer, HIGH);

delay(500);

digitalWrite(pinBuzzer, LOW);

delay(500);
digitalWrite(pinBuzzer, HIGH);

delay(500);

digitalWrite(pinBuzzer, LOW);

delay(500);
digitalWrite(pinBuzzer, HIGH);

delay(500);

digitalWrite(pinBuzzer, LOW);

delay(500);
myservo.write(90);

//awal===========================================================================
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}
perhitungan();
if(distance>10){
  ulang++;
  Serial.print("ulang = ");Serial.print(ulang);
  delay(1000);
}

perhitungan();
if(distance<10){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
 if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10 ){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();

if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}

perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance<10){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
 if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10 ){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();

if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}

perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}
perhitungan();
if(distance>10){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}
if(distance<10 && ulang>0){
  nilaiServo++;
  Serial.print("nilaiServo = ");Serial.print(nilaiServo);
delay(1000);
}

if(nilaiServo>0 && ulang>0){
myservo.write(180);   
   Serial.println("tertutup");
 nilaiServo=0;
 ulang=0;   
}



 //akhir===========================================================================
 delay(1000);
  lcd.clear();
  Serial.print("Akses Diterima");
   blockA = digitalRead(blockAPin);
   blockC = digitalRead(blockCPin);

  } //akhir masuk block A

 if(parameter==1 && nilaiB==0 && nilaiC==0 && nilaiA==0){
lcd.clear();
 lcd.setCursor(3, 0);
  lcd.print("MOHON MAAF");
      lcd.setCursor(2, 2);
  lcd.print("AKSES DITOLAK");
  lcd.setCursor(5, 3);
  lcd.print("");
  digitalWrite(pinBuzzer, HIGH);

delay(3000);

digitalWrite(pinBuzzer, LOW);

  delay(2000);
 myservo.write(180);   
 delay(2000);
  
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("PARKIRAN PENUH");
      lcd.setCursor(3, 2);
  lcd.print("SILAHKAN TUNGGU");
  delay(3000);
  parameter=0;
  lcd.clear();
  Serial.print("Akses Diterima");
   blockB1 = digitalRead(blockB1Pin);
 blockB2 = digitalRead(blockB2Pin);
  } 

   if(parameter==1 && nilaiA==0 && nilaiB>0 && nilaiC>0){
lcd.clear();
 lcd.setCursor(3, 0);
  lcd.print("MOHON MAAF");
      lcd.setCursor(0, 2);
  lcd.print("PARKIRAN BLOCK A");
  lcd.setCursor(5, 3);
  lcd.print("PENUH");
  digitalWrite(pinBuzzer, HIGH);

delay(3000);

digitalWrite(pinBuzzer, LOW);

  delay(2000);
 myservo.write(180);   
 delay(2000);
  
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("SILAHKAN");
      lcd.setCursor(0, 2);
  lcd.print("MENUJU KE BLOCK");
  lcd.setCursor(0, 3);
  lcd.print("YANG MASIH KOSONG");
  delay(3000);
  myservo.write(90);   
  delay(3000);
 myservo.write(180);   
 delay(2000);
  lcd.clear();
  Serial.print("Akses Diterima");
   blockA = digitalRead(blockAPin);

  } 

  if(parameter==1 && nilaiB==0 && nilaiC==0){
lcd.clear();
 lcd.setCursor(3, 0);
  lcd.print("MOHON MAAF");
      lcd.setCursor(0, 2);
  lcd.print("PARKIRAN B DAN C");
  lcd.setCursor(5, 3);
  lcd.print("PENUH");
  digitalWrite(pinBuzzer, HIGH);

delay(3000);

digitalWrite(pinBuzzer, LOW);

  delay(2000);
 myservo.write(180);   
 delay(2000);
  
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("SILAHKAN");
      lcd.setCursor(0, 2);
  lcd.print("MENUJU KE BLOCK A");
  lcd.setCursor(0, 3);
  lcd.print("YANG MASIH KOSONG");
  delay(3000);
  myservo.write(90);   
  delay(3000);
 myservo.write(180);   
 delay(2000);
  lcd.clear();
  Serial.print("Akses Diterima");
   blockB1 = digitalRead(blockB1Pin);
 blockB2 = digitalRead(blockB2Pin);
  } 

 if(parameter==1 && nilaiA==0 && nilaiC==0){
lcd.clear();
 lcd.setCursor(3, 0);
  lcd.print("MOHON MAAF");
      lcd.setCursor(0, 2);
  lcd.print("PARKIRAN A DAN C");
  lcd.setCursor(5, 3);
  lcd.print("PENUH");
  digitalWrite(pinBuzzer, HIGH);

delay(3000);

digitalWrite(pinBuzzer, LOW);

  delay(2000);
 myservo.write(180);   
 delay(2000);
  
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("SILAHKAN");
      lcd.setCursor(0, 2);
  lcd.print("MENUJU KE BLOCK B");
  lcd.setCursor(0, 3);
  lcd.print("YANG MASIH KOSONG");
  delay(3000);
  myservo.write(90);   
  delay(3000);
 myservo.write(180);   
 delay(2000);
  lcd.clear();
  Serial.print("Akses Diterima");
   blockB1 = digitalRead(blockB1Pin);
 blockB2 = digitalRead(blockB2Pin);
  } 

  if(parameter==1 && nilaiA==0 && nilaiB==0){
lcd.clear();
 lcd.setCursor(3, 0);
  lcd.print("MOHON MAAF");
      lcd.setCursor(0, 2);
  lcd.print("PARKIRAN A DAN B");
  lcd.setCursor(5, 3);
  lcd.print("PENUH");
  digitalWrite(pinBuzzer, HIGH);

delay(3000);

digitalWrite(pinBuzzer, LOW);

  delay(2000);
 myservo.write(180);   
 delay(2000);
  
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("SILAHKAN");
      lcd.setCursor(0, 2);
  lcd.print("MENUJU KE BLOCK C");
  lcd.setCursor(0, 3);
  lcd.print("YANG MASIH KOSONG");
  delay(3000);
  myservo.write(90);   
  delay(3000);
 myservo.write(180);   
 delay(2000);
  lcd.clear();
  Serial.print("Akses Diterima");
   blockB1 = digitalRead(blockB1Pin);
 blockB2 = digitalRead(blockB2Pin);
  } 

  if(parameter==1 && nilaiB==0 && nilaiA>0 && nilaiC>0){
lcd.clear();
 lcd.setCursor(3, 0);
  lcd.print("MOHON MAAF");
      lcd.setCursor(0, 2);
  lcd.print("PARKIRAN BLOCK B");
  lcd.setCursor(5, 3);
  lcd.print("PENUH");
  digitalWrite(pinBuzzer, HIGH);

delay(3000);

digitalWrite(pinBuzzer, LOW);

  delay(2000);
 myservo.write(180);   
 delay(2000);
  
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("SILAHKAN");
      lcd.setCursor(0, 2);
  lcd.print("MENUJU KE BLOCK");
  lcd.setCursor(0, 3);
  lcd.print("YANG MASIH KOSONG");
  delay(3000);
  myservo.write(90);   
  delay(3000);
 myservo.write(180);   
 delay(2000);
  lcd.clear();
  Serial.print("Akses Diterima");
   blockB1 = digitalRead(blockB1Pin);
 blockB2 = digitalRead(blockB2Pin);
  } 

     if(parameter==1 && nilaiC==0 && nilaiB>0 && nilaiA>0){
lcd.clear();
 lcd.setCursor(3, 0);
  lcd.print("MOHON MAAF");
      lcd.setCursor(0, 2);
  lcd.print("PARKIRAN BLOCK C");
  lcd.setCursor(5, 3);
  lcd.print("PENUH");
  digitalWrite(pinBuzzer, HIGH);

delay(3000);

digitalWrite(pinBuzzer, LOW);

  delay(2000);
 myservo.write(180);   
 delay(2000);
  
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("SILAHKAN");
      lcd.setCursor(0, 2);
  lcd.print("MENUJU KE BLOCK");
  lcd.setCursor(0, 3);
  lcd.print("YANG MASIH KOSONG");
  delay(3000);
  myservo.write(90);   
  delay(3000);
 myservo.write(180);   
 delay(2000);
  lcd.clear();
  Serial.print("Akses Diterima");
   blockC = digitalRead(blockAPin);

  } 
 
  // Change status kartu
  mfrc.PICC_HaltA();
  
}

void perhitungan(){

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Menyetel trigPin TINGGI (AKTIF) selama 10 mikrodetik
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW); 
 duration = pulseIn(echoPin, HIGH);
  // Menghitung jarak
  distance = duration * 0.034 / 2; // Kecepatan gelombang suara dibagi 2 (pergi dan kembali)
  // Menampilkan jarak pada Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
}
