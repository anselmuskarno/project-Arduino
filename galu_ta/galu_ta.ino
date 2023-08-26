#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
const int LDR = A0;
int input_val = 0;
const int relay1 = 4;
const int relay2 = 5;
const int relay3 = 6;
const int relay4 = 7;
void setup() {
 lcd.begin();  
   lcd.setCursor(0,0);
  lcd.print("Loading ... "); 
  delay(5000);
lcd.clear();
pinMode(relay1,OUTPUT);
pinMode(relay2,OUTPUT);
pinMode(relay3,OUTPUT);
pinMode(relay4,OUTPUT);
Serial.begin(9600);

}

void loop() {
 
  input_val = analogRead(LDR);
    lcd.setCursor(0,1);
  Serial.println(input_val);
   
  lcd.setCursor(0,0);
 
  if(input_val>20){
    Serial.println("Kondisi 1");
     lcd.print("Relay 1 Aktif");
     digitalWrite(relay1, HIGH);
digitalWrite(relay2, HIGH);
digitalWrite(relay3, LOW);
digitalWrite(relay4, LOW);
delay(5000);
lcd.clear();
  } 
  if(input_val<20){
    Serial.println("Kondisi 2");
     lcd.print("Relay 3 Aktif");
     digitalWrite(relay1, LOW);
digitalWrite(relay2, LOW);
digitalWrite(relay3, HIGH);
digitalWrite(relay4, HIGH);
delay(5000);
lcd.clear();
  }
}
