/* Code made by miliohm.com
     Visit our Youtube channel miliohm for more tutorials */

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
#define sensor 2
boolean kondisi = false;
int rpm = 0;

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include "RTClib.h"
RTC_DS3231 rtc;
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
#define tahun now.year()
#define bulan now.month()
#define tanggal now.day()
#define hari daysOfTheWeek[now.dayOfTheWeek()]
#define jam now.hour()
#define menit now.minute()
#define detik now.second()
char buff[10];

void setup()
{
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Speed Sensor");
  lcd.setCursor(0, 1);
  
  //lcd.print("Test");
  pinMode(sensor, INPUT);
  attachInterrupt(digitalPinToInterrupt(sensor), hitung_putaran, RISING);
  delay(1000);
  lcd.clear();
}


void loop()
{
 //hitung_putaran();
 cetak();
  DateTime now = rtc.now();
//  lcd.clear ();
  if (jam < 10 && menit < 10) {
    sprintf (buff, "0%d:0%d", jam, menit);
  }
  else  if (jam < 10 && menit >= 10) {
    sprintf (buff, "0%d:%d", jam, menit);
  }
  else  if (jam >= 10 && menit < 10) {
    sprintf (buff, "%d:0%d", jam, menit);
  }
  else  if (jam >= 10 && menit >= 10) {
    sprintf (buff, "%d:%d", jam, menit);
  }
  lcd.setCursor (0, 0);
  lcd.print(buff);
  if (tanggal < 10 && bulan < 10) {
    sprintf (buff, "0%d-0%d-22", tanggal, bulan, tahun);
  }
  else  if (tanggal < 10 && bulan >= 10) {
    sprintf (buff, "0%d-%d-22", tanggal, bulan, tahun);
  }
  else  if (tanggal >= 10 && bulan < 10) {
    sprintf (buff, "%d-0%d-22", tanggal, bulan, tahun);
  }
  else  if (tanggal >= 10 && bulan >= 10) {
    sprintf (buff, "%d-%d-22", tanggal, bulan, tahun);
  }
  lcd.setCursor(8, 0);
  lcd.print(buff);
  delay(100);
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
