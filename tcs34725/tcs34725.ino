#define tombolDark 7 // kuning
#define tombolLight 8 // biru

const int relayDinamo = 10;
const int relaySaklar = 11;

//10  
//11

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

#include <Wire.h>
#include "Adafruit_TCS34725.h"
Adafruit_TCS34725 tcs = Adafruit_TCS34725();

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

void loop(void) {
  digitalWrite(relayDinamo, LOW); 
digitalWrite(relaySaklar, LOW);
  lcd.setCursor(0,0);
  lcd.print("Pilih Kopi :                 ");
  lcd.setCursor(0,1);
  lcd.print("                              ");
  
int tombolDarkDitekan = digitalRead(tombolDark);
int tombolLightDitekan = digitalRead(tombolLight);

if(tombolDarkDitekan == HIGH){
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
  delay(3000);
} 

if(tombolLightDitekan == HIGH){
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
  delay(3000);
} 

  
  uint16_t r, g, b, c, colorTemp, lux;
  tcs.getRawData(&r, &g, &b, &c);
//  lcd.setCursor(0,0);
//  lcd.print("R:");lcd.print(r);lcd.print(" ");
//  lcd.print("G:");lcd.print(g);lcd.print(" ");
//  lcd.print("B:");lcd.print(b);lcd.print(" ");
  Serial.print("R: "); Serial.print(r, DEC); Serial.print(" ");
  Serial.print("G: "); Serial.print(g, DEC); Serial.print(" ");
  Serial.print("B: "); Serial.print(b, DEC); Serial.print(" ");
  Serial.print("C: "); Serial.print(c, DEC); Serial.print(" ");

//  if(c>1){
//    lcd.setCursor(0,1);
//      lcd.print("Kopi LIGHT     ");
//        Serial.print("Kopi LIGHT     ");
//  } else if(c<1 || c==1){
//    lcd.setCursor(0,1);
//     lcd.print("Kopi DARK     ");
//      Serial.print("Kopi DARK    ");
//  }
  Serial.println(" ");
  delay(1000);
}
