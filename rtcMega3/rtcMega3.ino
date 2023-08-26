#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
#include "RTClib.h"
#include <Servo.h>
Servo myservo;
const int LDR = A0;
int cahayaMatahari = 0;

RTC_DS3231 rtc;

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

void setup () 
{
  Serial.begin(9600);
  lcd.begin();
   myservo.attach(9);
  delay(3000); // wait for console opening

  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (rtc.lostPower()) {
    Serial.println("RTC lost power, lets set the time!");
  
  // Comment out below lines once you set the date & time.
    // Following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  
    // Following line sets the RTC with an explicit date & time
    // for example to set January 27 2017 at 12:56 you would call:
    // rtc.adjust(DateTime(2017, 1, 27, 12, 56, 0));
  }
   
   Serial.println("Delay 5 detik");
  delay(5000);
}
int parameter=0;
void loop () 
{
  delay(1000);
    DateTime now = rtc.now();
    cahayaMatahari = analogRead(LDR);

    Serial.println();
    lcd.setCursor(4, 0);
  lcd.print(now.hour());
  lcd.print(":");
  lcd.print(now.minute());
  lcd.print(":");
  lcd.print(now.second());
 //=================================================================  

//==============================
Serial.println("Pukul 07.30");
   lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("1");
myservo.write(0);
delay(10000);
myservo.write(90);
for(int i=0; i<11; i++){
     DateTime now = rtc.now();
   lcd.setCursor(4, 0);
  lcd.print(now.hour());
  lcd.print(":");
  lcd.print(now.minute());
  lcd.print(":");
  lcd.print(now.second());
  Serial.print("Ulangan ke ");
  Serial.println(i);
    lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("1");
  delay(1000);
  lcd.clear();
}
//==============================
lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("2");
Serial.println("Pukul 08.00");
myservo.write(0);
delay(10000);
myservo.write(90);
for(int i=0; i<11; i++){
     DateTime now = rtc.now();
   lcd.setCursor(4, 0);
  lcd.print(now.hour());
  lcd.print(":");
  lcd.print(now.minute());
  lcd.print(":");
  lcd.print(now.second());
  Serial.print("Ulangan ke ");
  Serial.println(i);
     lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("2");
  delay(1000);
  lcd.clear();
}
//==============================
lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("3");
Serial.println("Pukul 08.30");
myservo.write(0);
delay(10000);
myservo.write(90);
for(int i=0; i<11; i++){
     DateTime now = rtc.now();
   lcd.setCursor(4, 0);
  lcd.print(now.hour());
  lcd.print(":");
  lcd.print(now.minute());
  lcd.print(":");
  lcd.print(now.second());
  Serial.print("Ulangan ke ");
  Serial.println(i);
      lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("3");
  delay(1000);
  lcd.clear();
}
//==============================
lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("4");
Serial.println("Pukul 09.00");
myservo.write(0);
delay(10000);
myservo.write(90);
for(int i=0; i<11; i++){
   DateTime now = rtc.now();
   lcd.setCursor(4, 0);
  lcd.print(now.hour());
  lcd.print(":");
  lcd.print(now.minute());
  lcd.print(":");
  lcd.print(now.second());
  Serial.print("Ulangan ke ");
  Serial.println(i);
      lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("4");
  delay(1000);
  lcd.clear();
}
//==============================
lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("5");
Serial.println("Pukul 09.30");
myservo.write(0);
delay(10000);
myservo.write(90);
for(int i=0; i<11; i++){
   DateTime now = rtc.now();
   lcd.setCursor(4, 0);
  lcd.print(now.hour());
  lcd.print(":");
  lcd.print(now.minute());
  lcd.print(":");
  lcd.print(now.second());
  Serial.print("Ulangan ke ");
  Serial.println(i);
      lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("5");
  delay(1000);
  lcd.clear();
}
//==============================
lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("6");
Serial.println("Pukul 10.00");
myservo.write(0);
delay(10000);
myservo.write(90);
for(int i=0; i<11; i++){
   DateTime now = rtc.now();
   lcd.setCursor(4, 0);
  lcd.print(now.hour());
  lcd.print(":");
  lcd.print(now.minute());
  lcd.print(":");
  lcd.print(now.second());
  Serial.print("Ulangan ke ");
  Serial.println(i);
      lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("6");
  delay(1000);
  lcd.clear();
}
//==============================
lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("7");
Serial.println("Pukul 10.30");
myservo.write(0);
delay(10000);
myservo.write(90);
for(int i=0; i<11; i++){
   DateTime now = rtc.now();
   lcd.setCursor(4, 0);
  lcd.print(now.hour());
  lcd.print(":");
  lcd.print(now.minute());
  lcd.print(":");
  lcd.print(now.second());
  Serial.print("Ulangan ke ");
  Serial.println(i);
      lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("7");
  delay(1000);
  lcd.clear();
}
//==============================
lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("8");
Serial.println("Pukul 11.00");
myservo.write(0);
delay(10000);
myservo.write(90);
for(int i=0; i<11; i++){
   DateTime now = rtc.now();
   lcd.setCursor(4, 0);
  lcd.print(now.hour());
  lcd.print(":");
  lcd.print(now.minute());
  lcd.print(":");
  lcd.print(now.second());
  Serial.print("Ulangan ke ");
  Serial.println(i);
     lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("8");
  delay(1000);
  lcd.clear();
}
//==============================
lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("9");
Serial.println("Pukul 11.30");
myservo.write(0);
delay(10000);
myservo.write(90);
for(int i=0; i<11; i++){
   DateTime now = rtc.now();
   lcd.setCursor(4, 0);
  lcd.print(now.hour());
  lcd.print(":");
  lcd.print(now.minute());
  lcd.print(":");
  lcd.print(now.second());
  Serial.print("Ulangan ke ");
  Serial.println(i);
      lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("9");
  delay(1000);
  lcd.clear();
}
//==============================
lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("10");
Serial.println("Pukul 12.00");
myservo.write(0);
delay(10000);
myservo.write(90);
for(int i=0; i<11; i++){
   DateTime now = rtc.now();
   lcd.setCursor(4, 0);
  lcd.print(now.hour());
  lcd.print(":");
  lcd.print(now.minute());
  lcd.print(":");
  lcd.print(now.second());
  Serial.print("Ulangan ke ");
  Serial.println(i);
     lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("10");
  delay(1000);
  lcd.clear();
}
//==============================
lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("11");
Serial.println("Pukul 12.30");
myservo.write(0);
delay(7000);
myservo.write(90);
for(int i=0; i<11; i++){
   DateTime now = rtc.now();
   lcd.setCursor(4, 0);
  lcd.print(now.hour());
  lcd.print(":");
  lcd.print(now.minute());
  lcd.print(":");
  lcd.print(now.second());
  Serial.print("Ulangan ke ");
  Serial.println(i);
     lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("11");
  delay(1000);
  lcd.clear();
}
//==============================
lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("12");
Serial.println("Pukul 13.00");
myservo.write(0);
delay(7000);
myservo.write(90);
for(int i=0; i<11; i++){
   DateTime now = rtc.now();
   lcd.setCursor(4, 0);
  lcd.print(now.hour());
  lcd.print(":");
  lcd.print(now.minute());
  lcd.print(":");
  lcd.print(now.second());
  Serial.print("Ulangan ke ");
  Serial.println(i);
      lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("12");
  delay(1000);
  lcd.clear();
}
//==============================
lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("13");
Serial.println("Pukul 13.30");
myservo.write(0);
delay(7000);
myservo.write(90);
for(int i=0; i<11; i++){
   DateTime now = rtc.now();
   lcd.setCursor(4, 0);
  lcd.print(now.hour());
  lcd.print(":");
  lcd.print(now.minute());
  lcd.print(":");
  lcd.print(now.second());
  Serial.print("Ulangan ke ");
  Serial.println(i);
      lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("13");
  delay(1000);
  lcd.clear();
}
//==============================
lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("14");
Serial.println("Pukul 14.00");
myservo.write(0);
delay(7000);
myservo.write(90);
for(int i=0; i<11; i++){
   DateTime now = rtc.now();
   lcd.setCursor(4, 0);
  lcd.print(now.hour());
  lcd.print(":");
  lcd.print(now.minute());
  lcd.print(":");
  lcd.print(now.second());
  Serial.print("Ulangan ke ");
  Serial.println(i);
      lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("14");
  delay(1000);
  lcd.clear();
}
//==============================
lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("15");
Serial.println("Pukul 14.30");
myservo.write(0);
delay(7000);
myservo.write(90);
for(int i=0; i<11; i++){
   DateTime now = rtc.now();
   lcd.setCursor(4, 0);
  lcd.print(now.hour());
  lcd.print(":");
  lcd.print(now.minute());
  lcd.print(":");
  lcd.print(now.second());
  Serial.print("Ulangan ke ");
  Serial.println(i);
      lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("15");
  delay(1000);
  lcd.clear();
}
//==============================
lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("16");
Serial.println("Pukul 15.00");
myservo.write(0);
delay(7000);
myservo.write(90);
for(int i=0; i<11; i++){
   DateTime now = rtc.now();
   lcd.setCursor(4, 0);
  lcd.print(now.hour());
  lcd.print(":");
  lcd.print(now.minute());
  lcd.print(":");
  lcd.print(now.second());
  Serial.print("Ulangan ke ");
  Serial.println(i);
      lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("16");
  delay(1000);
  lcd.clear();
}
//==============================
lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("17");
Serial.println("Pukul 15.30");
myservo.write(0);
delay(7000);
myservo.write(90);
for(int i=0; i<11; i++){
   DateTime now = rtc.now();
   lcd.setCursor(4, 0);
  lcd.print(now.hour());
  lcd.print(":");
  lcd.print(now.minute());
  lcd.print(":");
  lcd.print(now.second());
  Serial.print("Ulangan ke ");
  Serial.println(i);
      lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("17");
  delay(1000);
  lcd.clear();
}
//==============================
lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("18");
Serial.println("Pukul 16.00");
myservo.write(0);
delay(7000);
myservo.write(90);
for(int i=0; i<11; i++){
   DateTime now = rtc.now();
   lcd.setCursor(4, 0);
  lcd.print(now.hour());
  lcd.print(":");
  lcd.print(now.minute());
  lcd.print(":");
  lcd.print(now.second());
  Serial.print("Ulangan ke ");
  Serial.println(i);
     lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("18");
  delay(1000);
  lcd.clear();
}
//==============================
lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("19");
Serial.println("Pukul 16.30");
myservo.write(0);
delay(7000);
myservo.write(90);
for(int i=0; i<11; i++){
   DateTime now = rtc.now();
   lcd.setCursor(4, 0);
  lcd.print(now.hour());
  lcd.print(":");
  lcd.print(now.minute());
  lcd.print(":");
  lcd.print(now.second());
  Serial.print("Ulangan ke ");
  Serial.println(i);
      lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("19");
  delay(1000);
  lcd.clear();
}
//==============================
lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("20");
Serial.println("Pukul 17.00");
myservo.write(0);
delay(7000);
myservo.write(90);
for(int i=0; i<11; i++){
   DateTime now = rtc.now();
   lcd.setCursor(4, 0);
  lcd.print(now.hour());
  lcd.print(":");
  lcd.print(now.minute());
  lcd.print(":");
  lcd.print(now.second());
  Serial.print("Ulangan ke ");
  Serial.println(i);
     lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("20");
  delay(1000);
  lcd.clear();
}
//==============================
lcd.setCursor(0, 1);
  lcd.print("Menutup            ");
Serial.println("Kembali");
myservo.write(180);
for(int i=0; i<171; i++){
   DateTime now = rtc.now();
   lcd.setCursor(4, 0);
  lcd.print(now.hour());
  lcd.print(":");
  lcd.print(now.minute());
  lcd.print(":");
  lcd.print(now.second());
  Serial.print("Ulangan ke ");
  Serial.println(i);
      lcd.setCursor(0, 1);
  lcd.print("MENUTUP               ");
  delay(1000);
  lcd.clear();
}
myservo.write(90);
for(int i=0; i<61; i++){
 DateTime now = rtc.now();
   lcd.setCursor(4, 0);
  lcd.print(now.hour());
  lcd.print(":");
  lcd.print(now.minute());
  lcd.print(":");
  lcd.print(now.second());
  Serial.print("Ulangan ke ");
  Serial.println(i);
    lcd.setCursor(0, 1);
  lcd.print("SELESAI");
  delay(1000);
  lcd.clear();
}

}
