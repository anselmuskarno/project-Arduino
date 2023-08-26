#include <Wire.h> // Library for I2C communication
#include <SPI.h>  // not used here, but needed to prevent a RTClib compile error
#include "RTClib.h"
#include <LiquidCrystal_I2C.h> // Library for LCD
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);
#define sensor 2
boolean kondisi = false;
int rpm = 0;
 
RTC_DS1307 RTC;     // Setup an instance of DS1307 naming it RTC
 
void setup () 
{
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Speed Sensor");
  lcd.setCursor(0, 1);
  
  //lcd.print("Test");
 
//  delay(1000);
  lcd.clear();
}
 
void loop () {
   pinMode(sensor, INPUT);
  attachInterrupt(digitalPinToInterrupt(sensor), hitung_putaran, RISING);
int hasil;
lcd.setCursor(0, 1);
  lcd.print("Putaran: ");
  if(rpm%2==0){
//    Serial.println("ok");
  }
  hasil=rpm/2;
  lcd.print(hasil);

//  cetak();
//  DateTime now = RTC.now();
// 
//  Serial.print(now.year(), DEC);
//  Serial.print('/');
//  Serial.print(now.month(), DEC);
//  Serial.print('/');
//  Serial.print(now.day(), DEC);
//  Serial.print(' ');
//  Serial.print(now.hour(), DEC);
//  Serial.print(':');
//  Serial.print(now.minute(), DEC);
//  Serial.print(':');
//  Serial.print(now.second(), DEC);
//  Serial.println();
// 
//  
//  lcd.setCursor(0, 0);
//  lcd.print("Date: ");
//  lcd.setCursor(0, 1);
//  lcd.print("Time: ");
//  
//  lcd.setCursor(6, 0);
//  lcd.print(now.year(), DEC);
//  lcd.print(":");
//  lcd.print(now.month(), DEC);
//  lcd.print(":");
//  lcd.print(now.day(), DEC);
// 
//  lcd.setCursor(6, 1);
//  lcd.print(now.hour(), DEC);
//  lcd.print(":");
//  lcd.print(now.minute(), DEC);
//  lcd.print(":");
//  lcd.print(now.second(), DEC); 
//  delay(1000);
  
}

int hasil;
void cetak() {
  lcd.setCursor(0, 1);
  lcd.print("Putaran: ");
  if(rpm%2==0){
//    Serial.println("ok");
  }
  hasil=rpm/2;
  lcd.print(hasil);
//   Serial.println(hasil);
}

void hitung_putaran() {
  if(kondisi){
    kondisi = false;
    rpm++;
    //Serial.println(kondisi);
//    Serial.println(rpm);
    
  }
  else 
  kondisi = true;
}
