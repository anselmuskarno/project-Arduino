#define tombolMedium 13 // merah
#define tombolDark 7 // kuning
#define tombolLight 8 // biru
#define tombolMode 4 // putih

const int relayDinamo = 10;
const int relaySaklar = 11;

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

#include <Wire.h>
#include "Adafruit_TCS34725.h"
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_614MS, TCS34725_GAIN_1X);


void setup(void) {
   lcd.begin();
  Serial.begin(9600);
  if (tcs.begin()) {
    Serial.println("Found sensor");
  } else {
    Serial.println("No TCS34725 found ... check your connections");
    while (1);
  }
    pinMode(relayDinamo,OUTPUT);
pinMode(relaySaklar,OUTPUT);
}

void mode(){
uint16_t r, g, b, c, colorTemp, lux;

  tcs.getRawData(&r, &g, &b, &c);
  // colorTemp = tcs.calculateColorTemperature(r, g, b);
  colorTemp = tcs.calculateColorTemperature_dn40(r, g, b, c);
  lux = tcs.calculateLux(r, g, b);

  Serial.print("Color Temp: "); Serial.print(colorTemp, DEC); Serial.print(" K - ");
  Serial.print("Lux: "); Serial.print(lux, DEC); Serial.print(" - ");
  Serial.print("R: "); Serial.print(r, DEC); Serial.print(" ");
  Serial.print("G: "); Serial.print(g, DEC); Serial.print(" ");
  Serial.print("B: "); Serial.print(b, DEC); Serial.print(" ");
  Serial.print("C: "); Serial.print(c, DEC); Serial.print(" ");
  Serial.println(" ");
 
if(lux > 10 && lux <= 90 ){
  Serial.println("DARK");
  lcd.setCursor(0,1);
  lcd.print("Kopi DARK     ");
} else if(lux > 210 ){
  Serial.println("LIGHT");
  lcd.setCursor(0,1);
  lcd.print("Kopi LIGHT     ");
} else if(lux > 90 && lux <= 200 ){
  Serial.println("MEDIUM");
  lcd.setCursor(0,1);
  lcd.print("Kopi MEDIUM     ");
}
  lcd.setCursor(0,0);
  lcd.print("Nilai  :    ");lcd.print(lux);lcd.print(" ");
 
}

int parameter = 0;
int waktu=0;
void loop(void) {
    digitalWrite(relayDinamo, LOW); 
digitalWrite(relaySaklar, LOW);
  lcd.setCursor(0,0);
  lcd.print("Pilih Kopi :                 ");
  lcd.setCursor(0,1);
  lcd.print("                              ");
  
int tombolDarkDitekan = digitalRead(tombolDark);
int tombolLightDitekan = digitalRead(tombolLight);
int tombolModeDitekan = digitalRead(tombolMode);
int tombolMediumDitekan = digitalRead(tombolMedium);

if(tombolMediumDitekan == HIGH){
  waktu++;
  digitalWrite(relayDinamo, HIGH); 
digitalWrite(relaySaklar, HIGH);
  Serial.println("Tombol medium HIGH");
  lcd.setCursor(0,1);
  lcd.print("Medium                   ");
  delay(2000);

// =========================================

 uint16_t r, g, b, c, colorTemp, lux;
  tcs.getRawData(&r, &g, &b, &c);
  // colorTemp = tcs.calculateColorTemperature(r, g, b);
  colorTemp = tcs.calculateColorTemperature_dn40(r, g, b, c);
  lux = tcs.calculateLux(r, g, b);

 
if(lux <900){
  Serial.println("Input Kopi");
  lcd.setCursor(0,1);
  lcd.print("Masukkan Kopi     ");
}
if(lux < 1000 && lux >= 900 ){
  Serial.println("DARK");
} else if(lux > 1100 ){
  Serial.println("LIGHT");
} else if(lux >= 1000 && lux <= 1100 ){
  Serial.println("MEDIUM");
}
  lcd.setCursor(0,0);
  lcd.print("Nilai  :    ");lcd.print(lux);lcd.print(" ");

  
  while(waktu<11){
    Serial.println(waktu);
    waktu++;
    delay(1000);
    lcd.setCursor(0,0);
  lcd.print("Permintaan               ");
  lcd.setCursor(0,1);
  lcd.print("Diproses ......             ");
//  delay(10000); //proses sangrai
  }


// =========================================
  
   lcd.setCursor(0,0);
  lcd.print("KOPI MEDIUM               ");
  lcd.setCursor(0,1);
  lcd.print("Selesai.            ");
   digitalWrite(relayDinamo, LOW); 
digitalWrite(relaySaklar, LOW);
  delay(3000);
}

if(tombolDarkDitekan == HIGH){
  digitalWrite(relayDinamo, HIGH); 
digitalWrite(relaySaklar, HIGH);
  Serial.println("Tombol dark HIGH");
  lcd.setCursor(0,1);
  lcd.print("DARK                   ");
  delay(2000);
  lcd.setCursor(0,0);
  lcd.print("Permintaan               ");
  lcd.setCursor(0,1);
  lcd.print("Diproses ......             ");
  delay(10000); //proses sangrai
   lcd.setCursor(0,0);
  lcd.print("KOPI DARK               ");
  lcd.setCursor(0,1);
  lcd.print("Selesai.            ");
   digitalWrite(relayDinamo, LOW); 
digitalWrite(relaySaklar, LOW);
  delay(3000);
} 

if(tombolLightDitekan == HIGH){
   digitalWrite(relayDinamo, HIGH); 
digitalWrite(relaySaklar, HIGH);
  Serial.println("Tombol Light HIGH");
  lcd.setCursor(0,1);
  lcd.print("LIGHT                   ");
  delay(2000);
  lcd.setCursor(0,0);
  lcd.print("Permintaan               ");
  lcd.setCursor(0,1);
  lcd.print("Diproses ......             ");
  delay(10000); //proses sangrai
   lcd.setCursor(0,0);
  lcd.print("KOPI LIGHT               ");
  lcd.setCursor(0,1);
  lcd.print("Selesai.            ");
   digitalWrite(relayDinamo, LOW); 
digitalWrite(relaySaklar, LOW);
  delay(3000);
} 

while(tombolModeDitekan == HIGH){
  uint16_t r, g, b, c, colorTemp, lux;
  tcs.getRawData(&r, &g, &b, &c);
  // colorTemp = tcs.calculateColorTemperature(r, g, b);
  colorTemp = tcs.calculateColorTemperature_dn40(r, g, b, c);
  lux = tcs.calculateLux(r, g, b);
if(lux > 10 && lux <= 90 ){
  Serial.println("DARK");
} else if(lux > 210 ){
  Serial.println("LIGHT");
} else if(lux > 90 && lux <= 200 ){
  Serial.println("MEDIUM");
}
  Serial.print("Color Temp: "); Serial.print(colorTemp, DEC); Serial.print(" K - ");
  Serial.print("Lux: "); Serial.print(lux, DEC); Serial.print(" - ");
  Serial.print("R: "); Serial.print(r, DEC); Serial.print(" ");
  Serial.print("G: "); Serial.print(g, DEC); Serial.print(" ");
  Serial.print("B: "); Serial.print(b, DEC); Serial.print(" ");
  Serial.print("C: "); Serial.print(c, DEC); Serial.print(" ");
  Serial.println(" ");
if(lux <900){
  Serial.println("Input Kopi");
  lcd.setCursor(0,1);
  lcd.print("Masukkan Kopi     ");
}
if(lux < 1000 && lux >= 900 ){
  Serial.println("DARK");
  lcd.setCursor(0,1);
  lcd.print("Kopi DARK     ");
} else if(lux > 1100 ){
  Serial.println("LIGHT");
  lcd.setCursor(0,1);
  lcd.print("Kopi LIGHT     ");
} else if(lux >= 1000 && lux <= 1100 ){
  Serial.println("MEDIUM");
  lcd.setCursor(0,1);
  lcd.print("Kopi MEDIUM     ");
}
  lcd.setCursor(0,0);
  lcd.print("Nilai  :    ");lcd.print(lux);lcd.print(" ");


}

  Serial.println(" ");
  delay(1000);
}
