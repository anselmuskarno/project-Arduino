byte led1= 8;
#define tombolKornel 3 // merah
#define tombolRombe 2 // Hijau
const int LED=13;
const int GSR=A0;
int sensorValue;
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
   pinMode(led1, OUTPUT);
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
//  lcd.setCursor(0,1);
//  lcd.print("Rombe Kornel S.T");
  delay(3000);
  lcd.clear();
}

void loop()
{
int tombolMerahDitekan = digitalRead(tombolKornel);
int tombolHijauDitekan = digitalRead(tombolRombe);
lcd.setCursor(0,0);
  lcd.print("Tekan Tombol    ");
while(tombolMerahDitekan == HIGH){
     
  int temp;
float conductivevoltage;
sensorValue=analogRead(GSR);
conductivevoltage = sensorValue*(5.0/1023.0);
sensorValue = sensorValue-330;
if(sensorValue>180){
  lcd.setCursor(0,0);
  lcd.print("Tempelkan Jari                 ");
  lcd.setCursor(5,1);
  lcd.print("0                              ");
}

  if(sensorValue<100){
    lcd.setCursor(0,0);
  lcd.print("    NORMAL                 ");
  lcd.setCursor(5,1);
  lcd.print(sensorValue);
 lcd.setCursor(7,1);
 lcd.print("    ");
  delay(100);
  }
  
  if(sensorValue>=100 && sensorValue<150){
lcd.setCursor(0,0);
  lcd.print("    LETIH                 ");
  lcd.setCursor(5,1);
  lcd.print(sensorValue);
}
Serial.print("sensorValue=");
Serial.println(sensorValue);
delay(100);
}


while(tombolHijauDitekan == HIGH){
        
  int temp;
float conductivevoltage;
sensorValue=analogRead(GSR);
conductivevoltage = sensorValue*(5.0/1023.0);
if(sensorValue>650){
  lcd.setCursor(0,0);
  lcd.print("Tempelkan Jari                 ");
  lcd.setCursor(5,1);
  lcd.print("0                              ");
}

  if(sensorValue<400){
    lcd.setCursor(0,0);
  lcd.print(" KADAR GULA                 ");
  lcd.setCursor(5,1);
  lcd.print(sensorValue);
 
    digitalWrite(led1, HIGH);
  delay(100);
  digitalWrite(led1, LOW);

  delay(100);
  }
  if(sensorValue>400 && sensorValue<640){
lcd.setCursor(0,0);
  lcd.print("  KADAR GULA                 ");
  lcd.setCursor(5,1);
  lcd.print(sensorValue);

//  }
  
}
Serial.print("sensorValue=");
Serial.println(sensorValue);
delay(100);
}
}
