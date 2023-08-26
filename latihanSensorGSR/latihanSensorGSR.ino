const int LED=13;
const int GSR=A0;
int sensorValue;
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  lcd.begin();
Serial.begin(9600);
pinMode(LED,OUTPUT);
digitalWrite(LED,LOW);
lcd.setCursor(0,0);
  lcd.print("LOADING ....");
  lcd.setCursor(0,1);
  lcd.print("");
delay(3000);
lcd.setCursor(0,0);
  lcd.print("SENSOR GSR V.1.2");
  lcd.setCursor(0,1);
  lcd.print("Rombe Kornel S.T");
  delay(3000);
  lcd.clear();
}

void loop()
{
int temp;
float conductivevoltage;
sensorValue=analogRead(GSR);
conductivevoltage = sensorValue*(5.0/1023.0);

lcd.setCursor(0,0);
  lcd.print("  Kadar Gula         ");
  lcd.setCursor(5,1);
  lcd.print(sensorValue);
Serial.print("sensorValue=");
Serial.println(sensorValue);
delay(100);
}
