#include <LiquidCrystal_I2C.h>

 #define trigPin 12
 #define echoPin 13

LiquidCrystal_I2C lcd(0x27, 16, 2);
 int counter = 0;
 int currentState = 0;
 int previousState = 0;
 
 void setup() {
  Serial.begin(9600);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 lcd.begin();
 lcd.setCursor(2, 0);
// lcd.print("Jumlah Orang");
 }

int ulang = 0;
 
 void loop() {
 long duration, distance;
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 distance = (duration/2) / 29.1;
 lcd.backlight();
 Serial.println(distance);
 if(distance <= 30){
  ulang++;
  delay(1000);
 }
  lcd.setCursor(0, 0);
  lcd.print(ulang);
  lcd.setCursor(0, 1);
 }
