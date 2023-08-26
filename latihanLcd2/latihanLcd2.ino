int pinBuzzer= 6;
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
const int trigPin = 3;
const int echoPin = 2;

void setup() {
    Serial.begin(9600); 
pinMode(pinBuzzer, OUTPUT);
  lcd.begin();
   pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);
}

long duration, cm;

void loop(){ 
  
  lcd.setCursor(0,0);
  lcd.print("JARAK : ");
  lcd.setCursor(0,1);
  lcd.print(cm);

}
