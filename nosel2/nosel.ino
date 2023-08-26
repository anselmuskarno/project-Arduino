#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
#include <SoftwareSerial.h>
SoftwareSerial nosel (8, 9); 

const int relay = 7;
const int relay2 = 6;
const int relayHeater = 5;
#include "HX711.h"
// HX711 circuit wiring
int tombol = 13;
int bacaTombol = HIGH;
const int LOADCELL_DOUT_PIN = 10;
const int LOADCELL_SCK_PIN = 11;
int i = 1;
long hasil = 0;
long hasilAkhir = 0; 
HX711 scale;

void setup() {
  Serial.begin(9600);
  nosel.begin(9600);
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
      pinMode(4, OUTPUT);
   lcd.begin();
   lcd.setCursor(0,0);
  lcd.print("LOADING...");
  delay(5000);
  lcd.clear();
    lcd.setCursor(0,0);
  lcd.print("PENGERING GABAH");
  lcd.setCursor(0,1);
  lcd.print("OTOMATIS");
  delay(5000);
  lcd.clear();
  // set the speed at 60 rpm:
 pinMode(tombol, INPUT);

  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
}
int berat = 0;
void loop() {
Serial.print("Nilai : ");  Serial.println(i);
  digitalWrite(2, LOW); 
  digitalWrite(3, LOW); 
  digitalWrite(4, LOW);  
 bacaTombol = digitalRead(tombol);

if (!scale.is_ready()) {
  Serial.println("HX711 not found.");
  }
//   myStepper.step(-stepsPerRevolution); //Membuka     
  if (scale.is_ready()) {
    long reading = scale.read();
    Serial.print("HX711 reading: ");
    reading=reading*-1;
    Serial.println(reading);
    
// =========================================================================    
// KODE UNTUK TAMPILKAN BERAT    
    
// kode untuk 0 gram     
     if(reading<451825 ){
      berat=0;
       nosel.println("0");
       Serial.println("0 KG");
        lcd.setCursor(0,0);
  lcd.print("Berat : 0 KG           ");
      }  

//kode untuk 500 gram
else if(reading>=469786 && reading<684226){
//   nosel.println("500");
  berat = 500;
  hasil=reading;
//  proses = 0.9 * hasil;
  hasilAkhir = 0.09 * hasil;
  hasilAkhir = hasil - hasilAkhir;
       Serial.println("0.5 KG");
         lcd.setCursor(0,0);
  lcd.print("Berat : 0.5 KG           ");
      }

// kode untuk 1.5 KG  
else if( reading>1129461 && reading<=1329461 || 
    reading>872705 && reading<=912705 ||
     reading>827743 && reading<=867743 ||
    reading>850140 && reading<=890140 ){
       nosel.println("1500");
      berat = 1500;
               hasil=reading;
         hasilAkhir = 0.09 * hasil;
  hasilAkhir = hasil - hasilAkhir;
        lcd.setCursor(0,0);
  lcd.print("Berat : 1.5 KG           ");
      Serial.println("1.5 KG");
    } 


// Kode untuk 1 KG    
      else if(reading>=753692 && reading<=793692 ||
        reading>=913583 && reading<=953583 ||
        reading>=970661 && reading<=1370661 ||
        reading>=858675 && reading<=888675 ||
        reading>=785009 && reading<=825009 ||
        reading>=664226 && reading<=704226 ||reading>=811391 && reading<=851391 || reading>=1342972 && reading<=1742972){
        nosel.println("1000");
        berat = 1000;
          hasil=reading;
         hasilAkhir = 0.09 * hasil;
  hasilAkhir = hasil - hasilAkhir;
       Serial.println("1.0 KG");
         lcd.setCursor(0,0);
  lcd.print("Berat : 1.0 KG           ");
      } 
  
    
   
  } else {
    Serial.println("HX711 not found.");
  }

if(bacaTombol == HIGH && berat>0){
  
if(berat==1500){
 nosel.println("a");
 
    Serial.print("HASIL AWAL : ");Serial.print(hasil);Serial.println(" 1.50 KG");
  Serial.print("HASIL AKHIR : ");Serial.print(hasilAkhir);Serial.println(" 1.35 KG");
  lcd.clear();
   lcd.setCursor(0,0);
  lcd.print("Awal : 1.50 KG           ");
   lcd.setCursor(0,1);
  lcd.print("PROCESSING");

Serial.println("Coba1");

  digitalWrite(2, LOW); 
  digitalWrite(3, HIGH); 
  digitalWrite(4, LOW); 
Serial.println("Berputar 25 detik");
for(int i=1; i<26; i++){
  Serial.print("Ulang ke : ");Serial.println(i);
  delay(1000);
}
  digitalWrite(2, LOW); 
  digitalWrite(3, LOW); 
  digitalWrite(4, LOW); 
Serial.println("mati 3 detik");
for(int i=1; i<4; i++){
  Serial.print("Ulang ke : ");Serial.println(i);
  delay(1000);
}
digitalWrite(relay, LOW);
digitalWrite(relay2, HIGH);
  digitalWrite(2, HIGH); 
  digitalWrite(3, LOW); 
  digitalWrite(4, LOW); 
Serial.println("Berputar 25 detik");
for(int i=1; i<26; i++){
  Serial.print("Ulang ke : ");Serial.println(i);
  delay(1000);
}
  digitalWrite(2, LOW); 
  digitalWrite(3, LOW); 
  digitalWrite(4, LOW); 
Serial.println("mati 3 menit");
//delay(180000);
for(int i=1; i<180; i++){
  Serial.print("Ulang ke : ");Serial.println(i);
  delay(1000);
}

Serial.println("Coba2");
  digitalWrite(2, LOW); 
  digitalWrite(3, HIGH); 
  digitalWrite(4, LOW); 
Serial.println("Berputar 25 detik");
for(int i=1; i<26; i++){
  Serial.print("Ulang ke : ");Serial.println(i);
  delay(1000);
}
  digitalWrite(2, LOW); 
  digitalWrite(3, LOW); 
  digitalWrite(4, LOW); 
Serial.println("mati 3 detik");
for(int i=1; i<4; i++){
  Serial.print("Ulang ke : ");Serial.println(i);
  delay(1000);
}
  digitalWrite(2, HIGH); 
  digitalWrite(3, LOW); 
  digitalWrite(4, LOW); 
Serial.println("Berputar 25 detik");
for(int i=1; i<26; i++){
  Serial.print("Ulang ke : ");Serial.println(i);
  delay(1000);
}
  digitalWrite(2, LOW); 
  digitalWrite(3, LOW); 
  digitalWrite(4, LOW); 
Serial.println("mati 3 menit");
//delay(180000);
for(int i=1; i<180; i++){
  Serial.print("Ulang ke : ");Serial.println(i);
  delay(1000);
}

Serial.println("Coba3");
  digitalWrite(2, LOW); 
  digitalWrite(3, HIGH); 
  digitalWrite(4, LOW); 
Serial.println("Berputar 25 detik");
for(int i=1; i<26; i++){
  Serial.print("Ulang ke : ");Serial.println(i);
  delay(1000);
}
  digitalWrite(2, LOW); 
  digitalWrite(3, LOW); 
  digitalWrite(4, LOW); 
Serial.println("mati 3 detik");
for(int i=1; i<4; i++){
  Serial.print("Ulang ke : ");Serial.println(i);
  delay(1000);
}
  digitalWrite(2, HIGH); 
  digitalWrite(3, LOW); 
  digitalWrite(4, LOW); 
Serial.println("Berputar 25 detik");
for(int i=1; i<26; i++){
  Serial.print("Ulang ke : ");Serial.println(i);
  delay(1000);
}
  digitalWrite(2, LOW); 
  digitalWrite(3, LOW); 
  digitalWrite(4, LOW); 
Serial.println("mati 3 menit");
//delay(180000);
for(int i=1; i<180; i++){
  Serial.print("Ulang ke : ");Serial.println(i);
  delay(1000);
}

Serial.println("Coba4");
  digitalWrite(2, LOW); 
  digitalWrite(3, HIGH); 
  digitalWrite(4, LOW); 
Serial.println("Berputar 25 detik");
for(int i=1; i<26; i++){
  Serial.print("Ulang ke : ");Serial.println(i);
  delay(1000);
}
  digitalWrite(2, LOW); 
  digitalWrite(3, LOW); 
  digitalWrite(4, LOW); 
Serial.println("mati 3 detik");
for(int i=1; i<4; i++){
  Serial.print("Ulang ke : ");Serial.println(i);
  delay(1000);
}
  digitalWrite(2, HIGH); 
  digitalWrite(3, LOW); 
  digitalWrite(4, LOW); 
Serial.println("Berputar 25 detik");
for(int i=1; i<26; i++){
  Serial.print("Ulang ke : ");Serial.println(i);
  delay(1000);
}
  digitalWrite(2, LOW); 
  digitalWrite(3, LOW); 
  digitalWrite(4, LOW); 
Serial.println("mati 3 menit");
//delay(180000);
for(int i=1; i<180; i++){
  Serial.print("Ulang ke : ");Serial.println(i);
  delay(1000);
}

Serial.println("Coba5");
digitalWrite(relay, HIGH);
digitalWrite(relay2, LOW);  
digitalWrite(2, LOW); 
  digitalWrite(3, HIGH); 
  digitalWrite(4, LOW); 
Serial.println("Berputar 25 detik");
for(int i=1; i<26; i++){
  Serial.print("Ulang ke : ");Serial.println(i);
  delay(1000);
}
  digitalWrite(2, LOW); 
  digitalWrite(3, LOW); 
  digitalWrite(4, LOW); 
Serial.println("mati 3 detik");
for(int i=1; i<4; i++){
  Serial.print("Ulang ke : ");Serial.println(i);
  delay(1000);
}
  digitalWrite(2, HIGH); 
  digitalWrite(3, LOW); 
  digitalWrite(4, LOW); 
Serial.println("Berputar 25 detik");
for(int i=1; i<26; i++){
  Serial.print("Ulang ke : ");Serial.println(i);
  delay(1000);
}
  digitalWrite(2, LOW); 
  digitalWrite(3, LOW); 
  digitalWrite(4, LOW); 
Serial.println("mati 3 menit");
//delay(180000);
for(int i=1; i<180; i++){
  Serial.print("Ulang ke : ");Serial.println(i);
  delay(1000);
}



Serial.println("Coba6");
  digitalWrite(2, LOW); 
  digitalWrite(3, HIGH); 
  digitalWrite(4, LOW); 
Serial.println("Berputar 25 detik");
for(int i=1; i<26; i++){
  Serial.print("Ulang ke : ");Serial.println(i);
  delay(1000);
}
  digitalWrite(2, LOW); 
  digitalWrite(3, LOW); 
  digitalWrite(4, LOW); 
Serial.println("mati 3 detik");
for(int i=1; i<4; i++){
  Serial.print("Ulang ke : ");Serial.println(i);
  delay(1000);
}
  digitalWrite(2, HIGH); 
  digitalWrite(3, LOW); 
  digitalWrite(4, LOW); 
Serial.println("Berputar 25 detik");
for(int i=1; i<26; i++){
  Serial.print("Ulang ke : ");Serial.println(i);
  delay(1000);
}
  digitalWrite(2, LOW); 
  digitalWrite(3, LOW); 
  digitalWrite(4, LOW); 
Serial.println("mati 3 menit");

//delay(180000);
for(int i=1; i<180; i++){
  Serial.print("Ulang ke : ");Serial.println(i);
  delay(1000);
}
Serial.println("Coba7");
digitalWrite(relay, HIGH);
digitalWrite(relay2, LOW);
  digitalWrite(2, LOW); 
  digitalWrite(3, HIGH); 
  digitalWrite(4, LOW); 
Serial.println("Berputar 25 detik");
for(int i=1; i<26; i++){
  Serial.print("Ulang ke : ");Serial.println(i);
  delay(1000);
}
  digitalWrite(2, LOW); 
  digitalWrite(3, LOW); 
  digitalWrite(4, LOW); 
Serial.println("mati 3 detik");
for(int i=1; i<4; i++){
  Serial.print("Ulang ke : ");Serial.println(i);
  delay(1000);
}
  digitalWrite(2, HIGH); 
  digitalWrite(3, LOW); 
  digitalWrite(4, LOW); 
Serial.println("Berputar 25 detik");
for(int i=1; i<26; i++){
  Serial.print("Ulang ke : ");Serial.println(i);
  delay(1000);
}
  digitalWrite(2, LOW); 
  digitalWrite(3, LOW); 
  digitalWrite(4, LOW); 
Serial.println("mati 3 menit");

//delay(180000);
for(int i=1; i<180; i++){
  Serial.print("Ulang ke : ");Serial.println(i);
  delay(1000);
}

Serial.println("Coba8");
  digitalWrite(2, LOW); 
  digitalWrite(3, HIGH); 
  digitalWrite(4, LOW); 
Serial.println("Berputar 25 detik");
for(int i=1; i<26; i++){
  Serial.print("Ulang ke : ");Serial.println(i);
  delay(1000);
}
  digitalWrite(2, LOW); 
  digitalWrite(3, LOW); 
  digitalWrite(4, LOW); 
Serial.println("mati 3 detik");
for(int i=1; i<4; i++){
  Serial.print("Ulang ke : ");Serial.println(i);
  delay(1000);
}
  digitalWrite(2, HIGH); 
  digitalWrite(3, LOW); 
  digitalWrite(4, LOW); 
Serial.println("Berputar 25 detik");
for(int i=1; i<26; i++){
  Serial.print("Ulang ke : ");Serial.println(i);
  delay(1000);
}
  digitalWrite(2, LOW); 
  digitalWrite(3, LOW); 
  digitalWrite(4, LOW); 
Serial.println("mati 3 menit");
//delay(180000);
for(int i=1; i<180; i++){
  Serial.print("Ulang ke : ");Serial.println(i);
  delay(1000);
}

Serial.println("Coba9");
  digitalWrite(2, LOW); 
  digitalWrite(3, HIGH); 
  digitalWrite(4, LOW); 
Serial.println("Berputar 25 detik");
for(int i=1; i<26; i++){
  Serial.print("Ulang ke : ");Serial.println(i);
  delay(1000);
}
  digitalWrite(2, LOW); 
  digitalWrite(3, LOW); 
  digitalWrite(4, LOW); 
Serial.println("mati 3 detik");
for(int i=1; i<4; i++){
  Serial.print("Ulang ke : ");Serial.println(i);
  delay(1000);
}

  digitalWrite(2, HIGH); 
  digitalWrite(3, LOW); 
  digitalWrite(4, LOW); 
Serial.println("Berputar 25 detik");
for(int i=1; i<26; i++){
  Serial.print("Ulang ke : ");Serial.println(i);
  delay(1000);
}

  digitalWrite(2, LOW); 
  digitalWrite(3, LOW); 
  digitalWrite(4, LOW); 
Serial.println("mati 3 menit");
//delay(180000);
for(int i=1; i<180; i++){
  Serial.print("Ulang ke : ");Serial.println(i);
  delay(1000);
}


 Serial.println("SELESAI");
  delay(2000);
  digitalWrite(2, LOW); 
  digitalWrite(3, LOW); 
  digitalWrite(4, HIGH); 
   lcd.clear();
   lcd.setCursor(0,0);
  lcd.print("Akhir : 1.35 KG           ");
   lcd.setCursor(0,1);
  lcd.print("SELESAI!");
for(int i=1; i<61; i++){
  Serial.print("Ulang ke : ");Serial.println(i);
  delay(1000);
}
  lcd.clear();
//  delay(180000);

} 

else if(berat==1000){
   nosel.println("b");
    Serial.print("HASIL AWAL : ");Serial.print(hasil);Serial.println(" 1.0 KG");
  Serial.print("HASIL AKHIR : ");Serial.print(hasilAkhir);Serial.println(" 0.90 KG");
  lcd.clear();
   lcd.setCursor(0,0);
  lcd.print("Awal : 1.00 KG           ");
   lcd.setCursor(0,1);
  lcd.print("PROCESSING");

Serial.println("Coba1");
  digitalWrite(2, LOW); 
  digitalWrite(3, HIGH); 
  digitalWrite(4, LOW); 
Serial.println("Berputar 25 detik");
for(int i=1; i<26; i++){
  Serial.print("Ulang ke : ");Serial.println(i);
  delay(1000);
}
  digitalWrite(2, LOW); 
  digitalWrite(3, LOW); 
  digitalWrite(4, LOW); 
Serial.println("mati 3 detik");
for(int i=1; i<4; i++){
  Serial.print("Ulang ke : ");Serial.println(i);
  delay(1000);
}
digitalWrite(relay, LOW);
digitalWrite(relay2, HIGH);
  digitalWrite(2, HIGH); 
  digitalWrite(3, LOW); 
  digitalWrite(4, LOW); 
Serial.println("Berputar 25 detik");
for(int i=1; i<26; i++){
  Serial.print("Ulang ke : ");Serial.println(i);
  delay(1000);
}
  digitalWrite(2, LOW); 
  digitalWrite(3, LOW); 
  digitalWrite(4, LOW); 
Serial.println("mati 3 menit");

for(int i=1; i<180; i++){
  Serial.print("Ulang ke : ");Serial.println(i);
  delay(1000);
}

Serial.println("Coba2");
  digitalWrite(2, LOW); 
  digitalWrite(3, HIGH); 
  digitalWrite(4, LOW); 
Serial.println("Berputar 25 detik");
for(int i=1; i<26; i++){
  Serial.print("Ulang ke : ");Serial.println(i);
  delay(1000);
}
  digitalWrite(2, LOW); 
  digitalWrite(3, LOW); 
  digitalWrite(4, LOW); 
Serial.println("mati 3 detik");
for(int i=1; i<4; i++){
  Serial.print("Ulang ke : ");Serial.println(i);
  delay(1000);
}
  digitalWrite(2, HIGH); 
  digitalWrite(3, LOW); 
  digitalWrite(4, LOW); 
Serial.println("Berputar 25 detik");
for(int i=1; i<26; i++){
  Serial.print("Ulang ke : ");Serial.println(i);
  delay(1000);
}
  digitalWrite(2, LOW); 
  digitalWrite(3, LOW); 
  digitalWrite(4, LOW); 
Serial.println("mati 3 menit");
//delay(180000);
for(int i=1; i<180; i++){
  Serial.print("Ulang ke : ");Serial.println(i);
  delay(1000);
}

Serial.println("Coba3");
  digitalWrite(2, LOW); 
  digitalWrite(3, HIGH); 
  digitalWrite(4, LOW); 
Serial.println("Berputar 25 detik");
for(int i=1; i<26; i++){
  Serial.print("Ulang ke : ");Serial.println(i);
  delay(1000);
}
  digitalWrite(2, LOW); 
  digitalWrite(3, LOW); 
  digitalWrite(4, LOW); 
Serial.println("mati 3 detik");
for(int i=1; i<4; i++){
  Serial.print("Ulang ke : ");Serial.println(i);
  delay(1000);
}
  digitalWrite(2, HIGH); 
  digitalWrite(3, LOW); 
  digitalWrite(4, LOW); 
Serial.println("Berputar 25 detik");
for(int i=1; i<26; i++){
  Serial.print("Ulang ke : ");Serial.println(i);
  delay(1000);
}
  digitalWrite(2, LOW); 
  digitalWrite(3, LOW); 
  digitalWrite(4, LOW); 
Serial.println("mati 3 menit");

//delay(180000);
for(int i=1; i<180; i++){
  Serial.print("Ulang ke : ");Serial.println(i);
  delay(1000);
}
Serial.println("Coba4");
  digitalWrite(2, LOW); 
  digitalWrite(3, HIGH); 
  digitalWrite(4, LOW); 
Serial.println("Berputar 25 detik");
for(int i=1; i<26; i++){
  Serial.print("Ulang ke : ");Serial.println(i);
  delay(1000);
}
  digitalWrite(2, LOW); 
  digitalWrite(3, LOW); 
  digitalWrite(4, LOW); 
Serial.println("mati 3 detik");
for(int i=1; i<4; i++){
  Serial.print("Ulang ke : ");Serial.println(i);
  delay(1000);
}
  digitalWrite(2, HIGH); 
  digitalWrite(3, LOW); 
  digitalWrite(4, LOW); 
Serial.println("Berputar 25 detik");
for(int i=1; i<26; i++){
  Serial.print("Ulang ke : ");Serial.println(i);
  delay(1000);
}
  digitalWrite(2, LOW); 
  digitalWrite(3, LOW); 
  digitalWrite(4, LOW); 
Serial.println("mati 3 menit");

//delay(180000);
for(int i=1; i<180; i++){
  Serial.print("Ulang ke : ");Serial.println(i);
  delay(1000);
}

Serial.println("Coba5");
  digitalWrite(2, LOW); 
  digitalWrite(3, HIGH); 
  digitalWrite(4, LOW); 
Serial.println("Berputar 25 detik");
for(int i=1; i<26; i++){
  Serial.print("Ulang ke : ");Serial.println(i);
  delay(1000);
}
  digitalWrite(2, LOW); 
  digitalWrite(3, LOW); 
  digitalWrite(4, LOW); 
Serial.println("mati 3 detik");
for(int i=1; i<4; i++){
  Serial.print("Ulang ke : ");Serial.println(i);
  delay(1000);
}
  digitalWrite(2, HIGH); 
  digitalWrite(3, LOW); 
  digitalWrite(4, LOW); 
Serial.println("Berputar 25 detik");
for(int i=1; i<26; i++){
  Serial.print("Ulang ke : ");Serial.println(i);
  delay(1000);
}
  digitalWrite(2, LOW); 
  digitalWrite(3, LOW); 
  digitalWrite(4, LOW); 
Serial.println("mati 3 menit");
//delay(180000);
for(int i=1; i<180; i++){
  Serial.print("Ulang ke : ");Serial.println(i);
  delay(1000);
}

Serial.println("Coba6");
  digitalWrite(2, LOW); 
  digitalWrite(3, HIGH); 
  digitalWrite(4, LOW); 
Serial.println("Berputar 25 detik");
for(int i=1; i<26; i++){
  Serial.print("Ulang ke : ");Serial.println(i);
  delay(1000);
}
  digitalWrite(2, LOW); 
  digitalWrite(3, LOW); 
  digitalWrite(4, LOW); 
Serial.println("mati 3 detik");
for(int i=1; i<4; i++){
  Serial.print("Ulang ke : ");Serial.println(i);
  delay(1000);
}
  digitalWrite(2, HIGH); 
  digitalWrite(3, LOW); 
  digitalWrite(4, LOW); 
Serial.println("Berputar 25 detik");
for(int i=1; i<26; i++){
  Serial.print("Ulang ke : ");Serial.println(i);
  delay(1000);
}
  digitalWrite(2, LOW); 
  digitalWrite(3, LOW); 
  digitalWrite(4, LOW); 
Serial.println("mati 3 menit");
//delay(180000);
for(int i=1; i<180; i++){
  Serial.print("Ulang ke : ");Serial.println(i);
  delay(1000);
}


 Serial.println("SELESAI");
  delay(2000);
  digitalWrite(relay, HIGH);
digitalWrite(relay2, HIGH);
digitalWrite(relayHeater, LOW);
  digitalWrite(2, LOW); 
  digitalWrite(3, LOW); 
  digitalWrite(4, HIGH);  
   lcd.clear();
   lcd.setCursor(0,0);
  lcd.print("Akhir : 0.90 KG           ");
   lcd.setCursor(0,1);
  lcd.print("SELESAI!");
for(int i=1; i<61; i++){
  Serial.print("Ulang ke : ");Serial.println(i);
  delay(1000);
}
  lcd.clear();
//  delay(180000);

}

else if(berat==500 && i == 1){
   nosel.println("coba");
  Serial.print("HASIL AWAL : ");Serial.print(hasil);Serial.println("0.5 KG");
  Serial.print("HASIL AKHIR : ");Serial.println(hasilAkhir);Serial.println("0.45 KG");
  lcd.clear();
   lcd.setCursor(0,0);
  lcd.print("Awal : 0.50 KG           ");
   lcd.setCursor(0,1);
  lcd.print("PROCESSING");
  
 if (i==1){
//    Serial.print("Nilai : ");  Serial.println(i);
Serial.println("Coba1");
  digitalWrite(2, LOW); 
  digitalWrite(3, HIGH); 
  digitalWrite(4, LOW); 
Serial.println("Berputar");
delay(50000);
  digitalWrite(2, LOW); 
  digitalWrite(3, LOW); 
  digitalWrite(4, LOW); 
Serial.println("Mati 3 menit");
for(int i=1; i<180; i++){
  Serial.print("Ulang ke : ");Serial.println(i);
  delay(1000);
}

Serial.println("Coba2");
  digitalWrite(2, LOW); 
  digitalWrite(3, HIGH); 
  digitalWrite(4, LOW); 
Serial.println("Berputar");
delay(25000);
  digitalWrite(2, LOW); 
  digitalWrite(3, LOW); 
  digitalWrite(4, LOW); 
Serial.println("mati");
delay(3000);
  digitalWrite(2, HIGH); 
  digitalWrite(3, LOW); 
  digitalWrite(4, LOW); 
Serial.println("Berputar");
delay(25000);
  digitalWrite(2, LOW); 
  digitalWrite(3, LOW); 
  digitalWrite(4, LOW); 
Serial.println("Mati 3 menit");
for(int i=1; i<180; i++){
  Serial.print("Ulang ke : ");Serial.println(i);
  delay(1000);
}

Serial.println("Coba3");
  digitalWrite(2, LOW); 
  digitalWrite(3, HIGH); 
  digitalWrite(4, LOW); 
Serial.println("Berputar");
delay(25000);
  digitalWrite(2, LOW); 
  digitalWrite(3, LOW); 
  digitalWrite(4, LOW); 
Serial.println("mati");
delay(3000);
  digitalWrite(2, HIGH); 
  digitalWrite(3, LOW); 
  digitalWrite(4, LOW); 
Serial.println("Berputar");
delay(25000);
  digitalWrite(2, LOW); 
  digitalWrite(3, LOW); 
  digitalWrite(4, LOW); 
Serial.println("Mati 3 menit");
for(int i=1; i<180; i++){
  Serial.print("Ulang ke : ");Serial.println(i);
  delay(1000);
}
Serial.println("SELESAI");
  delay(2000);
  digitalWrite(relay, HIGH);
digitalWrite(relay2, HIGH);
digitalWrite(relayHeater, LOW); 
  digitalWrite(2, LOW); 
  digitalWrite(3, LOW); 
  digitalWrite(4, HIGH); 
   lcd.clear();
   lcd.setCursor(0,0);
  lcd.print("Akhir : 0.90 KG           ");
   lcd.setCursor(0,1);
  lcd.print("SELESAI!");
for(int i=1; i<61; i++){
  Serial.print("Ulang ke : ");Serial.println(i);
  delay(1000);
}
  lcd.clear();
//  delay(180000);

  }


 
}

  }

// else if(bacaTombol == HIGH && berat==0 ){
// 
//  lcd.clear();
//   lcd.setCursor(0,0);
//  lcd.print("Awal : 0.00 KG           ");
//   lcd.setCursor(0,1);
//  lcd.print("PROCESSING");
//  
// if (i==1){
////    Serial.print("Nilai : ");  Serial.println(i);
//Serial.println("Coba1");
//digitalWrite(relay, HIGH);
//digitalWrite(relay2, LOW);
//Serial.println("Berputar");
//delay(25000);
//digitalWrite(relay, HIGH);
//digitalWrite(relay2, HIGH);
//Serial.println("mati");
//delay(3000);
//digitalWrite(relay, LOW);
//digitalWrite(relay2, HIGH);
//Serial.println("Berputar");
//delay(25000);
//digitalWrite(relay, HIGH);
//digitalWrite(relay2, HIGH);
//Serial.println("Mati 3 menit");
//for(int i=1; i<180; i++){
//  Serial.print("Ulang ke : ");Serial.println(i);
//  delay(1000);
//}
//
//Serial.println("Coba2");
//digitalWrite(relay, HIGH);
//digitalWrite(relay2, LOW);
//Serial.println("Berputar");
//delay(25000);
//digitalWrite(relay, HIGH);
//digitalWrite(relay2, HIGH);
//Serial.println("mati");
//delay(3000);
//digitalWrite(relay, LOW);
//digitalWrite(relay2, HIGH);
//Serial.println("Berputar");
//delay(25000);
//digitalWrite(relay, HIGH);
//digitalWrite(relay2, HIGH);
//Serial.println("Mati 3 menit");
//for(int i=1; i<180; i++){
//  Serial.print("Ulang ke : ");Serial.println(i);
//  delay(1000);
//}
//
//Serial.println("Coba3");
//digitalWrite(relay, HIGH);
//digitalWrite(relay2, LOW);
//Serial.println("Berputar");
//delay(25000);
//digitalWrite(relay, HIGH);
//digitalWrite(relay2, HIGH);
//Serial.println("mati");
//delay(3000);
//digitalWrite(relay, LOW);
//digitalWrite(relay2, HIGH);
//Serial.println("Berputar");
//delay(25000);
//digitalWrite(relay, HIGH);
//digitalWrite(relay2, HIGH);
//
//Serial.println("Mati 3 menit");
//for(int i=1; i<180; i++){
//  Serial.print("Ulang ke : ");Serial.println(i);
//  delay(1000);
//}
//Serial.println("SELESAI");
//  delay(2000);
//  digitalWrite(relay, HIGH);
//digitalWrite(relay2, HIGH);
//digitalWrite(relayHeater, LOW); 
//   lcd.clear();
//   lcd.setCursor(0,0);
//  lcd.print("Akhir : 0.00 KG           ");
//   lcd.setCursor(0,1);
//  lcd.print("SELESAI!");
//for(int i=1; i<61; i++){
//  Serial.print("Ulang ke : ");Serial.println(i);
//  delay(1000);
//}
//  lcd.clear();
////  delay(180000);
//
//  }
//
//
// 
//}


  
}
