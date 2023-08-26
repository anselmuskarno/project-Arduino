#include "DHT.h"
#define DHTPIN 8   
#define DHTTYPE DHT11  

DHT dht(DHTPIN, DHTTYPE);

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
const int relay3 = 10;
const int relay2 = 7;

void setup() {
   lcd.begin();
pinMode(relay3,OUTPUT);
pinMode(relay2,OUTPUT);
  Serial.begin(9600); //baud komunikasi serial
  Serial.println("Pengujian DHT11!"); //penulisan di serial monitor
  dht.begin(); //prosedur memulai pembacaan module sensor

}

void loop() {

  
  delay(2000);  //menunggu beberapa detik untuk pembacaan

  //pembacaan sensor membutuhkan waktu 250ms

  //Pembacaan untuk data kelembaban
  float humidity_1 = dht.readHumidity();
  //Pembacaan dalam format celcius (c)
  float celcius_1 = dht.readTemperature();
  //pembacaan dalam format Fahrenheit
  float fahrenheit_1 = dht.readTemperature(true);

  //mengecek pembacaan apakah terjadi kegagalan atau tidak
  if (isnan(humidity_1) || isnan(celcius_1) || isnan(fahrenheit_1)) {
    Serial.println("Pembacaan data dari module sensor gagal!");
    return;
  }

  float htof = dht.computeHeatIndex(fahrenheit_1, humidity_1); 
  //Prosedur pembacaaan data indeks panas dalam bentuk fahreheit
  float htoc = dht.computeHeatIndex(celcius_1, humidity_1, false);
 //Prosedur pembacaaan data indeks panas dalam bentuk celcius

  //pembacaan nilai pembacaan data suhu
  Serial.print("Suhu : ");
  Serial.print(celcius_1); //format derajat celcius

lcd.setCursor(0,0);
  lcd.print("SUHU :                             ");
  lcd.setCursor(8,0);
  lcd.print(celcius_1);
  lcd.print(" C");

if(celcius_1 > 32){
  digitalWrite(relay2, LOW); 
  digitalWrite(relay3, HIGH); 
Serial.println("relay kipas menyala");
Serial.println("relay lampu mati");
 lcd.setCursor(0,1);
  lcd.print("PANAS     ");

}
if(
  celcius_1 < 33 && celcius_1 > 26){
  digitalWrite(relay2, HIGH); 
  digitalWrite(relay3, HIGH); 
Serial.println("relay kipas menyala");
Serial.println("relay lampu mati");
 lcd.setCursor(0,1);
  lcd.print("NORMAL     ");

}
  if(celcius_1 < 27){
  digitalWrite(relay2, HIGH); 
  digitalWrite(relay3, LOW); 
Serial.println("relay kipas mati");
Serial.println("relay lampu menyala");
 lcd.setCursor(0,1);
  lcd.print("DINGIN");
}

  Serial.print("°"); //simbol derajat
  Serial.print("C / ");
  Serial.print(fahrenheit_1); //format derajat fahrenheit
  Serial.print("°");
  Serial.print("F\t");

  Serial.print("Indeks Panas: ");
  Serial.print(htof); 
  Serial.print("°");
  Serial.print("F / ");
  Serial.print(htoc);
  Serial.print("°");
  Serial.println("C ");

}
