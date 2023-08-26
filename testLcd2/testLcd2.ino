#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.begin();
   lcd.setCursor(0,0);
  lcd.print("LOADING ....");
delay(5000);
lcd.clear();
 lcd.setCursor(0,0);
  lcd.print("PENGERING GABAH");
  lcd.setCursor(0,1);
  lcd.print("OTOMATIS");
  delay(5000);
lcd.clear();
}

void loop(){
  lcd.setCursor(0,0);
  lcd.print("Berat:   1 KG");
delay(1000000000000000000);
}
