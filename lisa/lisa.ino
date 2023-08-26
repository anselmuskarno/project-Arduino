#include "DHT.h"
#define DHTPIN 8   
#define DHTTYPE DHT11  

DHT dht(DHTPIN, DHTTYPE);

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
const int relayKipas = 10;
const int relayLampu = 7;

void setup() {

   lcd.begin();
     lcd.setCursor(3,0);
  lcd.print("Sponsored :");
  lcd.setCursor(4,1);
  lcd.print("ADI Farm");
  delay(5000);
     lcd.setCursor(0,0);
  lcd.print("MESIN                                    ");
  lcd.setCursor(0,1);
  lcd.print("INKUBATOR    ");
  delay(5000);
pinMode(relayKipas,OUTPUT);
pinMode(relayLampu,OUTPUT);
  Serial.begin(9600); //baud komunikasi serial
  Serial.println("Pengujian DHT11!"); //penulisan di serial monitor
  dht.begin(); //prosedur memulai pembacaan module sensor
}

int detik,menit;

void loop() {
  //pembacaan sensor membutuhkan waktu 250ms

  //Pembacaan untuk data kelembaban
  float humidity_1 = dht.readHumidity();
  //Pembacaan dalam format celcius (c)
  float celcius_1 = dht.readTemperature();
celcius_1=celcius_1-4;
  //pembacaan nilai pembacaan data suhu
  Serial.print("Suhu : ");
  Serial.print(celcius_1); //format derajat celcius

lcd.setCursor(0,0);
  lcd.print("S:                             ");
  lcd.setCursor(2,0);
  lcd.print(celcius_1);
  lcd.setCursor(4,0);
  lcd.print("'C  ");

lcd.setCursor(7,0);
  lcd.print("K:                             ");
  lcd.setCursor(9,0);
  lcd.print(humidity_1);
  lcd.setCursor(11,0);
  lcd.print("%   ");


if(celcius_1 > 40){
    digitalWrite(relayKipas, HIGH); 
    digitalWrite(relayLampu, HIGH); 
  lcd.setCursor(0,1);
  lcd.print("PANAS         ");
}

if(celcius_1 == 34){
    digitalWrite(relayKipas, LOW); 
    digitalWrite(relayLampu, HIGH); 
  lcd.setCursor(0,1);
  lcd.print("NORMAL         ");
}

if(celcius_1 < 34){
     digitalWrite(relayKipas, LOW); 
    digitalWrite(relayLampu, HIGH); 
  lcd.setCursor(0,1);
  lcd.print("DINGIN         ");
  
}
delay(1000);

}
