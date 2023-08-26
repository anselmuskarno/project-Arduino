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
}
int parameter=0;
void loop () 
{
  delay(1000);
    DateTime now = rtc.now();
    cahayaMatahari = analogRead(LDR);
//    Serial.println("Current Date & Time: ");
//    Serial.print(now.year(), DEC);
//    Serial.print('/');
//    Serial.print(now.month(), DEC);
//    Serial.print('/');
//    Serial.print(now.day(), DEC);
//    Serial.print(" (");
//    Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
//    Serial.print(") ");
//    Serial.print(now.hour(), DEC);
//    Serial.print(':');
//    Serial.print(now.minute(), DEC);
//    Serial.print(':');
//    Serial.print(now.second(), DEC);
//    Serial.println();
//    
//    Serial.println("Unix Time: ");
//    Serial.print("elapsed ");
//    Serial.print(now.unixtime());
//    Serial.print(" seconds/");
//    Serial.print(now.unixtime() / 86400L);
//    Serial.println(" days since 1/1/1970");
//    
//    // calculate a date which is 7 days & 30 seconds into the future
//    DateTime future (now + TimeSpan(7,0,0,30));
//    
//    Serial.println("Future Date & Time (Now + 7days & 30s): ");
//    Serial.print(future.year(), DEC);
//    Serial.print('/');
//    Serial.print(future.month(), DEC);
//    Serial.print('/');
//    Serial.print(future.day(), DEC);
//    Serial.print(' ');
//    Serial.print(future.hour(), DEC);
//    Serial.print(':');
//    Serial.print(future.minute(), DEC);
//    Serial.print(':');
//    Serial.print(future.second(), DEC);
//    Serial.println();
    
    Serial.println();
    lcd.setCursor(4, 0);
  lcd.print(now.hour());
  lcd.print(":");
  lcd.print(now.minute());
  lcd.print(":");
  lcd.print(now.second());
 //=================================================================  
 if(now.hour()==7){
  if(now.minute()==30 && parameter==0){
    parameter++;
      myservo.write(9);
  Serial.println("Sudut 9");
 lcd.setCursor(4, 1);
  lcd.print("ke jam 8");    
  delay(3000);  
  
  }
 }
 if(now.hour()==8){
  if(now.minute()==0 && parameter==1){
    myservo.write(18);
  Serial.println("Sudut 18");
 lcd.setCursor(4, 1);
  lcd.print("ok");  
  delay(3000);  
  parameter=2;
  }
 }
 //=================================================================
 if(now.hour()==8){
  if(now.minute()==30 && parameter==2){
    myservo.write(27);
  Serial.println("Sudut 27");
 lcd.setCursor(4, 1);
  lcd.print("ok");  
  delay(3000);  
  parameter=3;
  }
 }
 if(now.hour()==9){
  if(now.minute()==0 && parameter==3){
    myservo.write(36);
  Serial.println("Sudut 38");
 lcd.setCursor(4, 1);
  lcd.print("ok");  
  delay(3000);  
  parameter=4;
  }
 }
 //=================================================================
 if(now.hour()==9){
  if(now.minute()==30 && parameter==4){
    myservo.write(45);
  Serial.println("Sudut 45");
 lcd.setCursor(4, 1);
  lcd.print("ok");  
  delay(3000);  
  parameter=5;
  }
 }
 if(now.hour()==10){
  if(now.minute()==0 && parameter==5){
    myservo.write(54);
  Serial.println("Sudut 54");
 lcd.setCursor(4, 1);
  lcd.print("ok");  
  delay(3000);  
  parameter=6;
  }
 }
 //=================================================================
 if(now.hour()==10){
  if(now.minute()==30 && parameter==6){
    myservo.write(63);
  Serial.println("Sudut 63");
 lcd.setCursor(4, 1);
  lcd.print("ok");  
  delay(3000);  
  parameter=7;
  }
 }
 if(now.hour()==11){
  if(now.minute()==0 && parameter==7){
    myservo.write(72);
  Serial.println("Sudut 72");
 lcd.setCursor(4, 1);
  lcd.print("ok");  
  delay(3000);  
  parameter=8;
  }
 }
 //=================================================================
 if(now.hour()==11){
  if(now.minute()==30 && parameter==8){
    myservo.write(81);
  Serial.println("Sudut 81");
 lcd.setCursor(4, 1);
  lcd.print("ok");  
  delay(3000);  
  parameter=9;
  }
 }
 if(now.hour()==12){
  if(now.minute()==0 && parameter==9){
      myservo.write(90);
  Serial.println("Sudut 90");
 lcd.setCursor(4, 1);
  lcd.print("ok");  
  delay(3000);  
  parameter=10;
  }
 }
 //=================================================================
 if(now.hour()==12){
  if(now.minute()==30 && parameter==10){
    myservo.write(99);
  Serial.println("Sudut 99");
 lcd.setCursor(4, 1);
  lcd.print("ok");  
  delay(3000);  
  parameter=11;
  }
 }
 if(now.hour()==13){
  if(now.minute()==0 && parameter==11){
    myservo.write(108);
  Serial.println("Sudut 108");
 lcd.setCursor(4, 1);
  lcd.print("ok");  
  delay(3000);  
  parameter=12;
  }
 }
 //=================================================================
 if(now.hour()==13){
  if(now.minute()==30 && parameter==12){
     myservo.write(117);
  Serial.println("Sudut 117");
 lcd.setCursor(4, 1);
  lcd.print("ok");  
  delay(3000);  
  parameter=13;
  }
 }
 if(now.hour()==14){
  if(now.minute()==0 && parameter==13){
     myservo.write(126);
  Serial.println("Sudut 126");
 lcd.setCursor(4, 1);
  lcd.print("ok");  
  delay(3000);  
  parameter=14;
  }
 }
 //=================================================================
 if(now.hour()==14){
  if(now.minute()==30 && parameter==14){
     myservo.write(135);
  Serial.println("Sudut 135");
 lcd.setCursor(4, 1);
  lcd.print("ok");  
  delay(3000);  
  parameter=15;
  }
 }
 if(now.hour()==15){
  if(now.minute()==0 && parameter==15){
     myservo.write(144);
  Serial.println("Sudut 144");
 lcd.setCursor(4, 1);
  lcd.print("ok");  
  delay(3000);  
  parameter=16;
  }
 }
 //=================================================================
 if(now.hour()==15){
  if(now.minute()==30 && parameter==16){
     myservo.write(153);
  Serial.println("Sudut 153");
 lcd.setCursor(4, 1);
  lcd.print("ok");  
  delay(3000);  
  parameter=17;
  }
 }
 if(now.hour()==16){
  if(now.minute()==0 && parameter==17){
     myservo.write(162);
  Serial.println("Sudut 162");
 lcd.setCursor(4, 1);
  lcd.print("ok");  
  delay(3000);  
  parameter=18;
  }
 }
 //=================================================================
 if(now.hour()==16){
  if(now.minute()==30 && parameter==18){
      myservo.write(171);
  Serial.println("Sudut 171");
 lcd.setCursor(4, 1);
  lcd.print("ok");  
  delay(3000);  
  parameter=19;
  }
 }
 if(now.hour()==17){
  if(now.minute()==0 && parameter==19){
    myservo.write(180);
  Serial.println("Sudut 180");
 lcd.setCursor(4, 1);
  lcd.print("ok");  
  delay(3000);  
  parameter=0;
  }
 }
 //=================================================================
 if(
  now.hour()==1 ||
  now.hour()==2 ||
  now.hour()==3 ||
  now.hour()==4 ||
  now.hour()==5 ||
  now.hour()==6 ||
  now.hour()==18 ||
  now.hour()==19 ||
  now.hour()==20 ||
  now.hour()==21 ||
  now.hour()==22 ||
  now.hour()==23 ||
  now.hour()==24 ||
  now.hour()==0 ){
    myservo.write(0);
 Serial.println("Sudut 0");
  parameter=0;
 }
 lcd.setCursor(0, 1);
  lcd.print(parameter);
//    delay(1000);
//    lcd.clear();
}
