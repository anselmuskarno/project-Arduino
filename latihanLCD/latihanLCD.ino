#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

#include "DHT.h"
#define DHTPIN 8     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 11
DHT dht(DHTPIN, DHTTYPE);
void setup() {
  lcd.begin();
   Serial.println(F("DHTxx test!"));
  dht.begin();
}
 
void loop(){
//    delay(2000);
//      float t = dht.readTemperature();
//
//      Serial.print(F("%  Temperature: "));
//  Serial.print(t);
//  Serial.print(F("C "));
    
  lcd.setCursor(0,0);
  lcd.print("Coba");

  lcd.setCursor(0,1);
    lcd.print("LCD");

}
