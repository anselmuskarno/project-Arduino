#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup()
{
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0);
   lcd.print("    ");
  lcd.setCursor(3, 0);
  lcd.print("SMART PARKING");
  lcd.setCursor(2, 1);
  lcd.print("UNIV. TEKNOLOGI");
  lcd.setCursor(3, 2);
  lcd.print("AKBA MAKASSAR");
  lcd.setCursor(2, 3);
  lcd.print("AFRIANTO ISMAIL");
}

void loop()
{
  // Do nothing here...
}
