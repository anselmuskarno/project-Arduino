#include "DHT.h"
#define DHTPIN 8   
#define DHTTYPE DHT11  

DHT dht(DHTPIN, DHTTYPE);

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
const int relayDinamo = 10;
const int relayLampu = 7;

void setup() {
   lcd.begin();
pinMode(relayDinamo,OUTPUT);
pinMode(relayLampu,OUTPUT);
  Serial.begin(9600); //baud komunikasi serial
  Serial.println("Pengujian DHT11!"); //penulisan di serial monitor
  dht.begin(); //prosedur memulai pembacaan module sensor
}

int detik;

void loop() {

  
  delay(1000);  //menunggu beberapa detik untuk pembacaan

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


lcd.setCursor(0,1);
  lcd.print("Putar : ");
  lcd.setCursor(8,1);
  lcd.print(detik);
  lcd.print(" detik");

digitalWrite(relayDinamo, LOW); 
digitalWrite(relayLampu, LOW); 

if(celcius_1 < 36){
  digitalWrite(relayLampu, HIGH); 
}

if(celcius_1 > 38){
  digitalWrite(relayLampu, LOW); 
}

if(detik == 8){
  digitalWrite(relayDinamo, HIGH);
  digitalWrite(relayLampu, HIGH); 
delay(9000);
digitalWrite(relayDinamo, LOW); 
digitalWrite(relayLampu, LOW); 
detik = 0;
}
//if(
//  celcius_1 == 32 || celcius_1 == 31 || celcius_1 == 30 ||
//  celcius_1 == 29 || celcius_1 == 28 || celcius_1 == 27
//  || celcius_1 == 26 || celcius_1 == 25){
//  digitalWrite(relay2, LOW); 
//  digitalWrite(relay3, LOW); 
//Serial.println("relay kipas menyala");
//Serial.println("relay lampu mati");
// lcd.setCursor(0,1);
//  lcd.print("NORMAL     ");
//
//}
//  if(celcius_1 < 25){
//  digitalWrite(relay2, LOW); 
//  digitalWrite(relay3, HIGH); 
//Serial.println("relay kipas mati");
//Serial.println("relay lampu menyala");
// lcd.setCursor(0,1);
//  lcd.print("DINGIN");
//}

  
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
detik++;
}
