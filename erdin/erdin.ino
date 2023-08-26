/* Code made by miliohm.com
     Visit our Youtube channel miliohm for more tutorials */

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display

float rpm = 0;

int pid;
unsigned long millisBefore;
volatile int holes;
int hasil;
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
int ulang=0;
int holesLama,holesBaru;
void loop()
{
 
  if (millis() - millisBefore > 500) {
    print_to_LCD();
    millisBefore = millis();
  }
  delay(200);
  Serial.println(ulang);
  ulang++;
//  if (ulang)
}

void print_to_LCD() {
  lcd.setCursor(0, 0);
  lcd.print("Holes : ");
  holesBaru=holes;

   
   hasil=holesBaru-holesLama;
   Serial.println("================================================");

  lcd.print(holes);

}

void count() {
  holes++;
}
