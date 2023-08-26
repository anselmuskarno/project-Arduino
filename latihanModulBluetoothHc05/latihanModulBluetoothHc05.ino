//sketch created by Akshay Joseph
char inputByte;
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() {
 Serial.begin(9600);
   lcd.begin();
 pinMode(13,OUTPUT);

}

void loop() {
while(Serial.available()>0){
  inputByte= Serial.read();
  Serial.println(inputByte);
  if (inputByte=='Z'){
  digitalWrite(13,HIGH);
    lcd.setCursor(0,0);
  lcd.print("Lampu ");
  lcd.setCursor(0,1);
  lcd.print("Aktif");
  delay(3000);

  }
  else if (inputByte=='z'){
    lcd.setCursor(0,0);
  lcd.print("Lampu ");
  lcd.setCursor(0,1);
  lcd.print("NonAktif");
  digitalWrite(13,LOW);
  delay(3000);
  } 
  }
}
