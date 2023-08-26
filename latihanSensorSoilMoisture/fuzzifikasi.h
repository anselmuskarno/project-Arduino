void fuzzifikasi(int x, float hasil){
const int relayPompa = 7;
const int SoilSensor = A0;
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
float keanggotaanFuzzy;
  Serial.print("x = ");  Serial.println(x);
//#include "inferensi.h";


//=====FUZZIFIKASI=======================================================================================================================================================================================================================
  float x_kering, x_basah, notUsed, kering, basah, x_notUsed;
  x_notUsed = x;
  x_kering = x;
  x_basah = x;

if(x_notUsed >= 59){

  notUsed = 0;
} else if(x_notUsed >= 49 && x_notUsed <= 59){

  notUsed = (59-x);
  notUsed = notUsed/10;

} else if(x_notUsed <= 49){

  notUsed = 1;
}

if(x_kering <= 49 || x_kering >= 60){
  kering = 0;
} else if(x_kering >= 49 && x_kering <= 59){
//  kering = (x-49)/(59-49);
  kering = (x-49);
  kering = kering/10;
} else if(x_kering >= 59 && x_kering <= 60){
//  kering = (60-x)/(60-59);
  kering = (60-x);
  kering = kering/1;
}

if(x_basah <= 59){
  basah = 0;
} else if(x_basah >= 59 && x_basah <= 60){
  basah = (x-59)/(60-59);
  basah = x-59;
  basah = basah/1;
} else if(x_basah >= 60){
  basah = 1;
}

//=====INFERENSI=======================================================================================================================================================================================================================

  float aPredikat_notUsed = notUsed;
  float aPredikat_kering = kering;
  float aPredikat_basah = basah;

int z1 = 0;
int z2 = 1;
int z3 = 0;



//=====DEFFUZIFIKASI=======================================================================================================================================================================================================================

float predikatN, predikatK, predikatB;
predikatK = (aPredikat_notUsed * z1)+(aPredikat_kering * z2) + (aPredikat_basah * z3);
predikatN = (aPredikat_notUsed + (aPredikat_kering) + (aPredikat_basah));
hasil = predikatK / predikatN;


Serial.print("Hasil ");Serial.println(hasil);

if(hasil > 0){
  //[R2] Relay akan aktif
  Serial.println("Kondisi 1");
    lcd.clear();

    lcd.setCursor(0,0);
  lcd.print("Kelemb : ");
   lcd.print(x);
   lcd.print("%");
    Serial.println("Kering");
  lcd.setCursor(0,1);
  lcd.print("KERING   ");lcd.print(hasil);
  
  digitalWrite(relayPompa, HIGH);
} else if (hasil == 0){
    Serial.println("Kondisi 2");
    lcd.clear();

    lcd.setCursor(0,0);
  lcd.print("Kelemb : ");
   lcd.print(x);
   lcd.print("%");
    Serial.println("Basah/TS");
  lcd.setCursor(0,1);
  lcd.print("BASAH/TS   ");lcd.print(hasil);
  
    
  //[R1][R3] Relay tidak aktif
  digitalWrite(relayPompa, LOW);
}

}
