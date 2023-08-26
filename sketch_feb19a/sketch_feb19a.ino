
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include "DS3231_Simple.h"
DS3231_Simple Clock;
LiquidCrystal_I2C lcd(0x27, 16, 2); 
void setup() {
  Serial.begin(9600);
  Clock.begin();
  lcd.begin();

}

void loop() {
  DateTime waktu;
  waktu = Clock.read();

  
  lcd.setCursor(0,0);
  lcd.print("Tgl  : ");
  lcd.print(waktu.Day);
  lcd.print("/");
  lcd.print(waktu.Month);
  lcd.print("/");
  lcd.print(waktu.Year);
  lcd.print(" ");

  lcd.setCursor(0,1);
  lcd.print("Jam  : ");
  lcd.print(waktu.Hour);
  lcd.print(":");
  lcd.print(waktu.Minute);
  lcd.print(":");
  lcd.print(waktu.Second);
  lcd.println("    ");


  
  Serial.print(waktu.Day);
  Serial.print("/");
  Serial.print(waktu.Month);
  Serial.print("/");
  Serial.print(waktu.Year);
  Serial.print(" ");
  Serial.print(waktu.Hour);
  Serial.print(":");
  Serial.print(waktu.Minute);
  Serial.print(":");
  Serial.println(waktu.Second);

  delay(1000);

   if ((waktu.Hour == 0 && waktu.Minute == 0 && waktu.Second == 0) || (waktu.Hour == 1 && waktu.Minute == 0 && waktu.Second == 0) || (waktu.Hour == 2 && waktu.Minute == 0 && waktu.Second == 0) ||
      (waktu.Hour == 3 && waktu.Minute == 0 && waktu.Second == 0) || (waktu.Hour == 4 && waktu.Minute == 0 && waktu.Second == 0) || (waktu.Hour == 5 && waktu.Minute == 0 && waktu.Second == 0) ||
      (waktu.Hour == 6 && waktu.Minute == 0 && waktu.Second == 0) || (waktu.Hour == 7 && waktu.Minute == 0 && waktu.Second == 0) || (waktu.Hour == 8 && waktu.Minute == 0 && waktu.Second == 0) ||
      (waktu.Hour == 9 && waktu.Minute == 0 && waktu.Second == 0) || (waktu.Hour == 10 && waktu.Minute == 0 && waktu.Second == 0) || (waktu.Hour == 11 && waktu.Minute == 0 && waktu.Second == 0) ||
      (waktu.Hour == 12 && waktu.Minute == 0 && waktu.Second == 0) || (waktu.Hour == 13 && waktu.Minute == 0 && waktu.Second == 0) || (waktu.Hour == 14 && waktu.Minute == 0 && waktu.Second == 0) ||
      (waktu.Hour == 15 && waktu.Minute == 0 && waktu.Second == 0) || (waktu.Hour == 16 && waktu.Minute == 0 && waktu.Second == 0) || (waktu.Hour == 17 && waktu.Minute == 0 && waktu.Second == 0) ||
      (waktu.Hour == 18 && waktu.Minute == 0 && waktu.Second == 0) || (waktu.Hour == 19 && waktu.Minute == 0 && waktu.Second == 0) || (waktu.Hour == 20 && waktu.Minute == 0 && waktu.Second == 0) ||
      (waktu.Hour == 21 && waktu.Minute == 0 && waktu.Second == 0) || (waktu.Hour == 22 && waktu.Minute == 0 && waktu.Second == 0) || (waktu.Hour == 23 && waktu.Minute == 0 && waktu.Second == 0)) {
    digitalWrite(13, HIGH);
    delay (300);                                // Buzzer Berbunyi Otomastis Setiap Jam
    digitalWrite(13, LOW);
    delay (300);
    digitalWrite(13, HIGH);
    delay (300);
    digitalWrite(13, LOW);
    delay (100);
}

  }
