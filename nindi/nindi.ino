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
     lcd.setCursor(3,0);
  lcd.print("LOADING...");
  lcd.setCursor(0,1);
  lcd.print(" ");
  delay(5000);
     lcd.setCursor(0,0);
  lcd.print("MESIN                                    ");
  lcd.setCursor(0,1);
  lcd.print("PENETAS TELUR");
  delay(5000);
pinMode(relayDinamo,OUTPUT);
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
  lcd.print("DET : ");
  lcd.setCursor(4,1);
  lcd.print(detik);
  lcd.print(" ");

  lcd.setCursor(7,1);
  lcd.print("MENIT : ");
  lcd.setCursor(14,1);
  lcd.print(menit);
  lcd.print(" ");

digitalWrite(relayDinamo, HIGH); 
digitalWrite(relayLampu, HIGH); 

if(celcius_1 < 36){
  digitalWrite(relayLampu, LOW); 
}

if(celcius_1 > 38){
  digitalWrite(relayLampu, HIGH); 
}

if(detik == 60){
menit++;
detik = 0;
}

if(menit == 30){
digitalWrite(relayDinamo, LOW);
delay(9000);
digitalWrite(relayDinamo, HIGH); 
menit=0;
}

delay(1000);  //menunggu beberapa detik untuk pembacaan
detik++;
}
