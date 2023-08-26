#include <Wire.h>
#include "RTClib.h"
const int LDR = A0;
int cahayaMatahari = 0;
RTC_DS1307 rtc;

char namaHari[7][12] = {"Minggu", "Senin", "Selasa", "Rabu", "Kamis", "Jumat", "Sabtu"};

void setup () {



  Serial.begin(9600);
  if (! rtc.begin()) {
    Serial.println("RTC TIDAK TERBACA");
    while (1);
  }

  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));//update rtc dari waktu komputer
  }
}

void loop () {
  cahayaMatahari = analogRead(LDR);
  
    DateTime now = rtc.now();
    int jamSekarang = now.hour();
    Serial.print(namaHari[now.dayOfTheWeek()]);  
    Serial.print(',');    
    Serial.print(now.day(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.year(), DEC);
    Serial.print(" ");   
    Serial.print(now.hour());
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();

    if(jamSekarang == 18 && cahayaMatahari > 500){
      Serial.println("berputar 18 derajat");
    } else{
     Serial.println("Tidak berputar");
    }
   
    delay(1000);
}
