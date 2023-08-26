/* Code made by miliohm.com
     Visit our Youtube channel miliohm for more tutorials */

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display

float rpm = 0;

int pid;
unsigned long millisBefore;
volatile int holes;

void setup()
{
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Speed Sensor");
  lcd.setCursor(0, 1);
  lcd.print("Test");
  pinMode(2, INPUT);
  attachInterrupt(digitalPinToInterrupt(2), count, FALLING);
  delay(1000);
  lcd.clear();
}

void loop()
{
  print_to_LCD();
  if (millis() - millisBefore > 60000) {
    rpm = holes / 12.0;
    holes = 0;
    millisBefore = millis();
  }
  delay(200);
}

void print_to_LCD() {
  lcd.setCursor(0, 0);
  lcd.print("Holes : ");
  lcd.print(holes);
  lcd.print("    ");
  lcd.setCursor(0, 1);
  lcd.print("RPM   : ");
  lcd.print(rpm);
  lcd.print("    ");
}

void count() {
  holes++;
}
