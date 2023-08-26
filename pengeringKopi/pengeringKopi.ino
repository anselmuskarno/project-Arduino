#include "DHT.h"
#define DHTPIN 2   
#define DHTTYPE DHT11  

DHT dht(DHTPIN, DHTTYPE);

const int relayMotor = 8;
const int relayHeater = 9;

#include <LiquidCrystal.h>
LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);

void setup() {
   lcd.begin(16,2);
pinMode(relayMotor,OUTPUT);
pinMode(relayHeater,OUTPUT);
  Serial.begin(9600); //baud komunikasi serial
  Serial.println("Pengujian DHT11!"); //penulisan di serial monitor
  dht.begin(); //prosedur memulai pembacaan module sensor

}
int parameter=0;
int detik;
int menit=0;
void loop() {

  
  delay(2000);  //menunggu beberapa detik untuk pembacaan
  detik+=2;
  //pembacaan sensor membutuhkan detik 250ms

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
  
lcd.setCursor(0,1);
  lcd.print("KEL :                             ");
  lcd.setCursor(8,1);
  lcd.print(humidity_1);
  lcd.print(" %");

if(celcius_1 < 35 && parameter == 0){
  digitalWrite(relayMotor, HIGH);
digitalWrite(relayHeater, LOW);
Serial.println("  heater menyala");
}
 if(celcius_1 >=35){
  digitalWrite(relayHeater, HIGH);
digitalWrite(relayMotor, LOW); 
Serial.println("  motor menyala 5 detik");
delay(5000);
detik+=5;
digitalWrite(relayHeater, HIGH);
digitalWrite(relayMotor, HIGH); 
Serial.println("  motor mati 20 detik");
parameter=1;
delay(20000);
detik+=20;
 }

if(celcius_1 < 35 && parameter == 1){
  digitalWrite(relayMotor, HIGH);
digitalWrite(relayHeater, HIGH);
Serial.println("  heater mati saat suhu dibawah 35");
} 
if(celcius_1 == 28 && parameter == 1){
  digitalWrite(relayMotor, HIGH);
digitalWrite(relayHeater, LOW);
Serial.println("  heater menyala");
}
if(detik==60){
  menit++;
  detik=0;
}
if(menit==30){    // waktu bekerja 30 menit
  digitalWrite(relayHeater, HIGH);
digitalWrite(relayMotor, HIGH); 
  delay(10000000000000000000);
}
Serial.print("Menit ke : ");
Serial.print(menit);
Serial.print("   detik = ");
Serial.println(detik);
}
