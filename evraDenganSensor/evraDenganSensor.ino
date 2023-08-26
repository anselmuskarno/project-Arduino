#include <Wire.h>
#include "RTClib.h"
const int LDR_a = A0;
int input_val_a = 0;
const int LDR_b = A1;
int input_val_b = 0;
const int LDR_c = A2;
int input_val_c = 0;
const int LDR_d = A3;
int input_val_d = 0;
//int hasil;
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
     DateTime future (now + TimeSpan(0,17,50,0));
  input_val_a = analogRead(LDR_a);
  input_val_b = analogRead(LDR_b);
  input_val_c = analogRead(LDR_c);
  input_val_d = analogRead(LDR_d);

Serial.print("A = "); Serial.println(input_val_a);
Serial.print("B = "); Serial.println(input_val_b);
Serial.print("C = "); Serial.println(input_val_c);
Serial.print("D = "); Serial.println(input_val_d);

    Serial.println();
    lcd.setCursor(4, 0);
  lcd.print(future.hour());
  lcd.print(":");
  lcd.print(future.minute());
  lcd.print(":");
  lcd.print(future.second());
 //=================================================================  
//KODE PERBAIKAN
//==============================
 if(future.hour()==10 && future.minute()==17){
  if(input_val_a > 50 || input_val_b > 50 || input_val_c > 50 || input_val_d > 50){
  if(parameter==0){
    parameter = 1;
Serial.println("Pukul 07.30");
   lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("1");
myservo.write(0);
delay(10000);
myservo.write(90);
Serial.println("Sudut 9 derajat");
for(int i=0; i<11; i++){
     DateTime future (now + TimeSpan(0,17,50,0));
   lcd.setCursor(4, 0);
  lcd.print(future.hour());
  lcd.print(":");
  lcd.print(future.minute());
  lcd.print(":");
  lcd.print(future.second());
//  Serial.print("Ulangan ke ");
//  Serial.println(i);
    lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("1");
  delay(1000);
  lcd.clear();
} 
  }
  }
 }
 
//AKHIR KODE PERBAIKAN 
//==============================
 if(future.hour()==8 && future.minute()==0){
   if(input_val_a > 100 || input_val_b > 100 || input_val_c > 100 || input_val_d > 100){
   if(parameter == 1){
parameter = 2;
lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("2");
Serial.println("Pukul 08.00");
myservo.write(0);
delay(10000);
myservo.write(90);
Serial.println("Sudut 18 derajat");
for(int i=0; i<11; i++){
     DateTime now = rtc.now();
   lcd.setCursor(4, 0);
  lcd.print(future.hour());
  lcd.print(":");
  lcd.print(future.minute());
  lcd.print(":");
  lcd.print(future.second());
//  Serial.print("Ulangan ke ");
//  Serial.println(i);
     lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("2");
  delay(1000);
  lcd.clear();
    
   }
}
 }
 }

 
//==============================
 if(future.hour()==8 && future.minute()==30){
   if(input_val_a > 150 || input_val_b > 150 || input_val_c > 150 || input_val_d > 150){
   if(parameter == 2){
parameter = 3;
lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("3");
Serial.println("Pukul 08.30");
myservo.write(0);
delay(10000);
myservo.write(90);
Serial.println("Sudut 27 derajat");
for(int i=0; i<11; i++){
     DateTime now = rtc.now();
   lcd.setCursor(4, 0);
  lcd.print(future.hour());
  lcd.print(":");
  lcd.print(future.minute());
  lcd.print(":");
  lcd.print(future.second());
  Serial.print("Ulangan ke ");
  Serial.println(i);
//      lcd.setCursor(0, 1);
//  lcd.print("Putaran ke ");
  lcd.print("3");
  delay(1000);
  lcd.clear();
    
   }    
}
 }
 }
 
//==============================
 if(future.hour()==9 && future.minute()==0){
  if(input_val_a > 200 || input_val_b > 200 || input_val_c > 200 || input_val_d > 200){
 if(parameter == 3){
parameter = 4;
lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("4");
Serial.println("Pukul 09.00");
myservo.write(0);
delay(10000);
myservo.write(90);
Serial.println("Sudut 36 derajat");
for(int i=0; i<11; i++){
   DateTime now = rtc.now();
   lcd.setCursor(4, 0);
  lcd.print(future.hour());
  lcd.print(":");
  lcd.print(future.minute());
  lcd.print(":");
  lcd.print(future.second());
//  Serial.print("Ulangan ke ");
//  Serial.println(i);
      lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("4");
  delay(1000);
  lcd.clear();
   
  }
}
 }
 }
 
//==============================
 if(future.hour()==9 && future.minute()==30){
  if(input_val_a > 250 || input_val_b > 250 || input_val_c > 250 || input_val_d > 250){
if(parameter == 4){
parameter = 5;
lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("5");
Serial.println("Pukul 09.30");
myservo.write(0);
delay(10000);
myservo.write(90);
Serial.println("Sudut 45 derajat");
for(int i=0; i<11; i++){
   DateTime now = rtc.now();
   lcd.setCursor(4, 0);
  lcd.print(future.hour());
  lcd.print(":");
  lcd.print(future.minute());
  lcd.print(":");
  lcd.print(future.second());
//  Serial.print("Ulangan ke ");
//  Serial.println(i);
      lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("5");
  delay(1000);
  lcd.clear();
  
  }
}
 }
 }
 
//==============================
 if(future.hour()==10 && future.minute()==0){
  if(input_val_a > 300 || input_val_b > 300 || input_val_c > 300 || input_val_d > 300){
if(parameter == 5){
  parameter = 6;
lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("6");
Serial.println("Pukul 10.00");
myservo.write(0);
delay(10000);
myservo.write(90);
Serial.println("Sudut 54 derajat");
for(int i=0; i<11; i++){
   DateTime now = rtc.now();
   lcd.setCursor(4, 0);
  lcd.print(future.hour());
  lcd.print(":");
  lcd.print(future.minute());
  lcd.print(":");
  lcd.print(future.second());
//  Serial.print("Ulangan ke ");
//  Serial.println(i);
      lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("6");
  delay(1000);
  lcd.clear();
  }    
}
 }
 }
 
//==============================
 if(future.hour()==10 && future.minute()==30){
  if(input_val_a > 350 || input_val_b > 350 || input_val_c > 350 || input_val_d > 350){
if(parameter == 6){
  parameter = 7;
lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("7");
Serial.println("Pukul 10.30");
myservo.write(0);
delay(10000);
myservo.write(90);
Serial.println("Sudut 63 derajat");
for(int i=0; i<11; i++){
   DateTime now = rtc.now();
   lcd.setCursor(4, 0);
  lcd.print(future.hour());
  lcd.print(":");
  lcd.print(future.minute());
  lcd.print(":");
  lcd.print(future.second());
//  Serial.print("Ulangan ke ");
//  Serial.println(i);
      lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("7");
  delay(1000);
  lcd.clear();
  }
}
 }
 }
 
//==============================
 if(future.hour()==11 && future.minute()==0){
  if(input_val_a > 400 || input_val_b > 400 || input_val_c > 400 || input_val_d > 400){
if(parameter == 7){
parameter = 8;
lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("8");
Serial.println("Pukul 11.00");
myservo.write(0);
delay(10000);
myservo.write(90);
Serial.println("Sudut 72 derajat");
for(int i=0; i<11; i++){
   DateTime now = rtc.now();
   lcd.setCursor(4, 0);
  lcd.print(future.hour());
  lcd.print(":");
  lcd.print(future.minute());
  lcd.print(":");
  lcd.print(future.second());
//  Serial.print("Ulangan ke ");
//  Serial.println(i);
     lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("8");
  delay(1000);
  lcd.clear();
  
  }   
}
 }
 }
 
//==============================
 if(future.hour()==11 && future.minute()==30){
  if(input_val_a > 450 || input_val_b > 450 || input_val_c > 450 || input_val_d > 450){
if(parameter == 8){
parameter = 9;
lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("9");
Serial.println("Pukul 11.30");
myservo.write(0);
delay(10000);
myservo.write(90);
Serial.println("Sudut 81 derajat");
for(int i=0; i<11; i++){
   DateTime now = rtc.now();
   lcd.setCursor(4, 0);
  lcd.print(future.hour());
  lcd.print(":");
  lcd.print(future.minute());
  lcd.print(":");
  lcd.print(future.second());
//  Serial.print("Ulangan ke ");
//  Serial.println(i);
      lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("9");
  delay(1000);
  lcd.clear();
  
  }
}
 }
 }
 
//==============================
 if(future.hour()==12 && future.minute()==0){
  if(input_val_a > 500 || input_val_b > 500 || input_val_c > 500 || input_val_d > 500){
if(parameter == 9){
  parameter = 10;
lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("10");
Serial.println("Pukul 12.00");
myservo.write(0);
delay(10000);
myservo.write(90);
Serial.println("Sudut 90 derajat");
for(int i=0; i<11; i++){
   DateTime now = rtc.now();
   lcd.setCursor(4, 0);
  lcd.print(future.hour());
  lcd.print(":");
  lcd.print(future.minute());
  lcd.print(":");
  lcd.print(future.second());
//  Serial.print("Ulangan ke ");
//  Serial.println(i);
     lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("10");
  delay(1000);
  lcd.clear();
  }
}
 }
 }
 
//==============================
 if(future.hour()==12 && future.minute()==30){
  if(input_val_a > 450 || input_val_b > 450 || input_val_c > 450 || input_val_d > 450){
  if(parameter == 10){
  parameter == 11;
lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("11");
Serial.println("Pukul 12.30");
myservo.write(0);
delay(7000);
myservo.write(90);
Serial.println("Sudut 99 derajat");
for(int i=0; i<11; i++){
   DateTime now = rtc.now();
   lcd.setCursor(4, 0);
  lcd.print(future.hour());
  lcd.print(":");
  lcd.print(future.minute());
  lcd.print(":");
  lcd.print(future.second());
//  Serial.print("Ulangan ke ");
//  Serial.println(i);
     lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("11");
  delay(1000);
  lcd.clear();
    
  }
}
 }
 }
 
//==============================
 if(future.hour()==13 && future.minute()==0){
  if(input_val_a > 400 || input_val_b > 400 || input_val_c > 400 || input_val_d > 400){
if(parameter == 11){
parameter = 12;
lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("12");
Serial.println("Pukul 13.00");
myservo.write(0);
delay(7000);
myservo.write(90);
Serial.println("Sudut 108 derajat");
for(int i=0; i<11; i++){
   DateTime now = rtc.now();
   lcd.setCursor(4, 0);
  lcd.print(future.hour());
  lcd.print(":");
  lcd.print(future.minute());
  lcd.print(":");
  lcd.print(future.second());
//  Serial.print("Ulangan ke ");
//  Serial.println(i);
      lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("12");
  delay(1000);
  lcd.clear();
  
  }
}
 }
 }
 
//==============================
 if(future.hour()==13 && future.minute()==30){
  if(input_val_a > 350 || input_val_b > 350 || input_val_c > 350 || input_val_d > 350){
  if(parameter == 12){
parameter = 13;
lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("13");
Serial.println("Pukul 13.30");
myservo.write(0);
delay(7000);
myservo.write(90);
Serial.println("Sudut 117 derajat");
for(int i=0; i<11; i++){
   DateTime now = rtc.now();
   lcd.setCursor(4, 0);
  lcd.print(future.hour());
  lcd.print(":");
  lcd.print(future.minute());
  lcd.print(":");
  lcd.print(future.second());
//  Serial.print("Ulangan ke ");
//  Serial.println(i);
      lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("13");
  delay(1000);
  lcd.clear();
    
  }  
}
 }
 }
 
//==============================
 if(future.hour()==14 && future.minute()==0){
  if(input_val_a > 300 || input_val_b > 300 || input_val_c > 300 || input_val_d > 300){
  if(parameter == 13){
parameter == 14;
lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("14");
Serial.println("Pukul 14.00");
myservo.write(0);
delay(7000);
myservo.write(90);
Serial.println("Sudut 126 derajat");
for(int i=0; i<11; i++){
   DateTime now = rtc.now();
   lcd.setCursor(4, 0);
  lcd.print(future.hour());
  lcd.print(":");
  lcd.print(future.minute());
  lcd.print(":");
  lcd.print(future.second());
//  Serial.print("Ulangan ke ");
//  Serial.println(i);
      lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("14");
  delay(1000);
  lcd.clear();
    
  }
}
 }
 }
 
//==============================
 if(future.hour()==14 && future.minute()==30){
  if(input_val_a > 250 || input_val_b > 250 || input_val_c > 250 || input_val_d > 250){
  if(parameter == 14){
parameter == 15;
lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("15");
Serial.println("Pukul 14.30");
myservo.write(0);
delay(7000);
myservo.write(90);
Serial.println("Sudut 135 derajat");
for(int i=0; i<11; i++){
   DateTime now = rtc.now();
   lcd.setCursor(4, 0);
  lcd.print(future.hour());
  lcd.print(":");
  lcd.print(future.minute());
  lcd.print(":");
  lcd.print(future.second());
//  Serial.print("Ulangan ke ");
//  Serial.println(i);
      lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("15");
  delay(1000);
  lcd.clear();
    
  }
}
 }
 }
 
//==============================
 if(future.hour()==15 && future.minute()==0){
  if(input_val_a > 200 || input_val_b > 200 || input_val_c > 200 || input_val_d > 200){
  if(parameter == 15){
parameter = 16;
lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("16");
Serial.println("Pukul 15.00");
myservo.write(0);
delay(7000);
myservo.write(90);
Serial.println("Sudut 144 derajat");
for(int i=0; i<11; i++){
   DateTime now = rtc.now();
   lcd.setCursor(4, 0);
  lcd.print(future.hour());
  lcd.print(":");
  lcd.print(future.minute());
  lcd.print(":");
  lcd.print(future.second());
//  Serial.print("Ulangan ke ");
//  Serial.println(i);
      lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("16");
  delay(1000);
  lcd.clear();    
  }
}
 }
 }

//==============================
 if(future.hour()==15 && future.minute()==30 ){
  if(input_val_a > 150 || input_val_b > 150 || input_val_c > 150 || input_val_d > 150){
  if(parameter == 16){
parameter = 17;
lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("17");
Serial.println("Pukul 15.30");
myservo.write(0);
delay(7000);
myservo.write(90);
Serial.println("Sudut 153 derajat");
for(int i=0; i<11; i++){
   DateTime now = rtc.now();
   lcd.setCursor(4, 0);
  lcd.print(future.hour());
  lcd.print(":");
  lcd.print(future.minute());
  lcd.print(":");
  lcd.print(future.second());
//  Serial.print("Ulangan ke ");
//  Serial.println(i);
      lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("17");
  delay(1000);
  lcd.clear();
    
  }
}
 }
 }

//==============================
 if(future.hour()==16 && future.minute()==0){
  if(input_val_a > 100 || input_val_b > 100 || input_val_c > 100 || input_val_d > 100){
  if(parameter == 17){
parameter = 18;
lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("18");
Serial.println("Pukul 16.00");
myservo.write(0);
delay(7000);
myservo.write(90);
Serial.println("Sudut 162 derajat");
for(int i=0; i<11; i++){
   DateTime now = rtc.now();
   lcd.setCursor(4, 0);
  lcd.print(future.hour());
  lcd.print(":");
  lcd.print(future.minute());
  lcd.print(":");
  lcd.print(future.second());
//  Serial.print("Ulangan ke ");
//  Serial.println(i);
     lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("18");
  delay(1000);
  lcd.clear();
    
  }
}
 }
 }
 
//==============================
 if(future.hour()==16 && future.minute()==30){
  if(input_val_a > 50 || input_val_b > 50 || input_val_c > 50 || input_val_d > 50){
  if(parameter == 18){
parameter = 19;
lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("19");
Serial.println("Pukul 16.30");
myservo.write(0);
delay(7000);
myservo.write(90);
Serial.println("Sudut 171 derajat");
for(int i=0; i<11; i++){
   DateTime now = rtc.now();
   lcd.setCursor(4, 0);
  lcd.print(future.hour());
  lcd.print(":");
  lcd.print(future.minute());
  lcd.print(":");
  lcd.print(future.second());
//  Serial.print("Ulangan ke ");
//  Serial.println(i);
      lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("19");
  delay(1000);
  lcd.clear();
  }
}
 }
 }
 
//==============================
 if(future.hour()==17 && future.minute()==0){
  if(input_val_a > 50 || input_val_b > 50 || input_val_c > 50 || input_val_d > 50){
  if(parameter == 19){
parameter = 20;
lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("20");
Serial.println("Pukul 17.00");
myservo.write(0);
delay(7000);
myservo.write(90);
Serial.println("Sudut 180 derajat");
for(int i=0; i<11; i++){
   DateTime now = rtc.now();
   lcd.setCursor(4, 0);
  lcd.print(future.hour());
  lcd.print(":");
  lcd.print(future.minute());
  lcd.print(":");
  lcd.print(future.second());
//  Serial.print("Ulangan ke ");
//  Serial.println(i);
     lcd.setCursor(0, 1);
  lcd.print("Putaran ke ");
  lcd.print("20");
  delay(1000);
  lcd.clear();
   }
}
 }
 }
 
//==============================
 if(future.hour()==17 && future.minute()==30 && parameter == 20){
  parameter = 0;
lcd.setCursor(0, 1);
  lcd.print("Menutup            ");
Serial.println("Kembali");
myservo.write(180);
for(int i=0; i<171; i++){
   DateTime now = rtc.now();
   lcd.setCursor(4, 0);
  lcd.print(future.hour());
  lcd.print(":");
  lcd.print(future.minute());
  lcd.print(":");
  lcd.print(future.second());
  Serial.print("Ulangan ke ");
  Serial.println(i);
      lcd.setCursor(0, 1);
  lcd.print("MENUTUP               ");
  delay(1000);
  lcd.clear();
  myservo.write(90);
}
 }
//for(int i=0; i<61; i++){
// DateTime now = rtc.now();
//   lcd.setCursor(4, 0);
//  lcd.print(future.hour());
//  lcd.print(":");
//  lcd.print(future.minute());
//  lcd.print(":");
//  lcd.print(future.second());
//  Serial.print("Ulangan ke ");
//  Serial.println(i);
//    lcd.setCursor(0, 1);
//  lcd.print("SELESAI");
//  delay(1000);
//  lcd.clear();
//}

}
