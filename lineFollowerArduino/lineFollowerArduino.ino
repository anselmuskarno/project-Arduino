#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
#include <SoftwareSerial.h>
SoftwareSerial Serial2(3, 2);
#define trigPin 10 //pasang pin D2 Arduino ke pin Triger HC-SR04
#define echoPin 11 // pasang pin D3 Arduino ke pin Echo HC-SR04
long duration; // variabel untuk durasi perjalanan gelombang suara
int distance; // variabel untuk pengukuran jarak
void setup() {
    lcd.begin();
//  delay(100);
  Serial.begin(9600);
Serial2.begin(9600);
  pinMode(trigPin, OUTPUT); // Menetapkan trigPin sebagai OUTPUT
  pinMode(echoPin, INPUT); // Menetapkan echoPin sebagai INPUTINPUT
  lcd.setCursor(0,0);
  lcd.print("Robot Pengantar");
  lcd.setCursor(5,1);
    lcd.print("MAKANAN");
}


void loop() {
//  Serial.println("ok");
  int E=digitalRead(12); 



//E=0;
//Serial.print("Kembali : ");Serial.println(E);
//  Serial2.println("coba123");
//String ancis = ""; 
// while(Serial2.available() > 0){
//  ancis += char(Serial2.read());
//}

//if(ancis == "1"){
//   lcd.setCursor(0,0);
//  lcd.print("   PESANAN    ");
//  lcd.setCursor(0,1);
//  lcd.print("    MEJA A    ");
//} else if(ancis == "2"){
//   lcd.setCursor(0,0);
//  lcd.print("   PESANAN    ");
//  lcd.setCursor(0,1);
//  lcd.print("    MEJA B    ");
//} else if(ancis == "2"){
//   lcd.setCursor(0,0);
//  lcd.print("   PESANAN    ");
//  lcd.setCursor(0,1);
//  lcd.print("    MEJA C    ");
//} else if(ancis == "2"){
//   lcd.setCursor(0,0);
//  lcd.print("   PESANAN    ");
//  lcd.setCursor(0,1);
//  lcd.print("    MEJA D    ");
//}

int sensorki=digitalRead(9); //baca sensor kiri
int sensorkiA=digitalRead(4); //baca sensor kiri
int sensorta=digitalRead(8); //baca sensor kanan
int sensorkaA=digitalRead(6); //baca sensor kanan
int sensorka=digitalRead(7); //baca sensor kanan    
// digitalWrite(trigPin, LOW);
//  delayMicroseconds(2);
//  // Menyetel trigPin TINGGI (AKTIF) selama 10 mikrodetik
//  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(10);
//  digitalWrite(trigPin, LOW); 
 
//Serial.print("A : ");Serial.println(sensorki);
//Serial.print("B : ");Serial.println(sensorkiA);
//Serial.print("C : ");Serial.println(sensorta);
//Serial.print("D : ");Serial.println(sensorkaA);
//Serial.print("E : ");Serial.println(sensorka);Serial.println();
 if((sensorki==0) && (sensorkiA==0) && (sensorka==0) && (sensorkaA==0)&& (sensorta==0)){
          Serial.println("Serial2 mati");
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
      } else{
        Serial2.println("gagal"); 
      }

}
