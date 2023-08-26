const int relayPompa = 7;
const int SoilSensor = A0;
#include <LiquidCrystal_I2C.h>
#include "fuzzifikasi.h"
//#include "inferensi.h"
//#include "deffuzifikasi.h"
LiquidCrystal_I2C lcd(0x27, 16, 2);
float keanggotaanFuzzy;

void setup()
{
  pinMode(relayPompa,OUTPUT);
  lcd.begin();
  Serial.begin(9600);
}
float hasil=0;
void loop()
{
  
  float kelembaban;
  int hasilPembacaan = analogRead(SoilSensor);
 kelembaban = (100 - ((hasilPembacaan/1023.00)*100));
fuzzifikasi(kelembaban, hasil);
Serial.print("Coba = ");Serial.println(hasil);
delay(500);

}
