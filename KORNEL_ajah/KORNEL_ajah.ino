byte led1= 8;
#define tombolKornel 3 // merah
#define tombolRombe 2 // Hijau
const int LED=13;
const int GSR=A0;
//int sensorValue;
int sensorValue;
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  Serial.begin(9600);
  lcd.backlight();
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

int parameter = 0;

void loop()
{
  sensorValue=analogRead(GSR);
  int vol1=sensorValue*0.2;      //resistansi x 0,2
   int vol2=vol1+100;      //resistansi x 0,2
  //int vol=sensorValue*0.2;

Serial.println("nilai = ");
  Serial.println(sensorValue);
if(vol1 <350 ){
  sensorValue=analogRead(GSR);
  int vol1=sensorValue*0.2;    
  lcd.setCursor(0,0);
    lcd.print("SOPIR RELAX    ");
    lcd.setCursor(0,1);
    lcd.print("R=");
  if(vol1 < 10){
  lcd.setCursor(2,1);
    lcd.print("00"); 
}
    lcd.print(sensorValue);
    lcd.setCursor(6,1);
    lcd.print(" "); 
    lcd.print("V=");
    if(vol1<100){
      lcd.print("0"); 
    }
    lcd.print(vol1);

 lcd.setCursor(13,1);
   if(vol1<100){
      lcd.print("0"); 
    }
  lcd.print(vol1);
    
    //lcd.setCursor(1,1);
    //lcd.print(sensorValue);
    delay(100);

Serial.print("SOPIR RELAX    ");
    Serial.print("R=");
    Serial.print(sensorValue);
    Serial.print("V=");
    Serial.println(vol1);

}

if(vol1 >350 ){
  sensorValue=analogRead(GSR);
  int vol1=sensorValue*0.2;    
  lcd.setCursor(0,0);
    lcd.print("SOPIR LETIH    ");
    lcd.setCursor(0,1);
    lcd.print("R=");
    lcd.print(sensorValue);
    lcd.setCursor(6,1);
    lcd.print("V=");
    lcd.print(vol1);

Serial.print("SOPIR LETIH    ");
    Serial.print("R=");
    Serial.print(sensorValue);
    Serial.print("V=");
    Serial.println(vol1);
    
    //lcd.setCursor(1,1);
    //lcd.print(sensorValue);
    delay(100);
}

   delay(1000);
}
