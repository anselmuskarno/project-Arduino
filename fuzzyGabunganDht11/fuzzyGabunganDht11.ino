#include "DHT.h"
#define DHTPIN 8   
#define DHTTYPE DHT11  

DHT dht(DHTPIN, DHTTYPE);

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
const int relayDinamo = 10;
const int relayLampu = 7;

float suhu;
float dingin,hangat,panas;
float kelembaban;
float kering,normal,basah;
unsigned char suhuDingin(){
  if (suhu <= 30){dingin =1;}
  else if (suhu >=30 && suhu <=35){dingin=(35-suhu)/5;}
  else if (suhu >= 6.5){dingin =0;}
  return dingin;
}
unsigned char suhuHangat(){
  if (suhu <= 30 || suhu <= 40){hangat =0;}
  else if (suhu >=30 && suhu <=35){hangat=(suhu-30)/5;}
  else if (suhu >=38 && suhu <=40){hangat=(49-suhu)/2;}
  else if (suhu >=35 && suhu <=38){hangat =1;}
  return hangat;
}
unsigned char suhuPanas (){
  if (suhu <=38 ){panas =0;}
  else if (suhu >=38 && suhu <=40){panas=(suhu-38)/2;}
  else if (suhu >= 40){panas =1;}
  return panas;
}

unsigned char keadaanKering (){
  if (kelembaban <= 30){kering =1;}
  else if (kelembaban >=30 && kelembaban <=40){kering=(40-kelembaban)/10;}
  else if (kelembaban >= 40){kering =0;}
  return kering;
}
unsigned char keadaanNormal(){
  if (kelembaban <= 30 || kelembaban <= 60){normal =0;}
  else if (kelembaban >=30 && kelembaban <=40){normal=(kelembaban-30)/10;}
  else if (kelembaban >=40 && kelembaban <=50){normal=1;}
  else if (kelembaban >=50 && kelembaban <=60){normal =(60-kelembaban)/10;}
  return normal;
}
unsigned char keadaanBasah (){
  if (kelembaban <=50 ){basah =0;}
  else if (kelembaban >=50 && kelembaban <=60){basah=(kelembaban-50)/10;}
  else if (kelembaban >= 60){basah =1;}
  return basah;
}

void fuzzifikasi(){
  suhuDingin();
  suhuHangat();
  suhuPanas();
  keadaanKering();
  keadaanNormal();
  keadaanBasah();
}
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
  
  // put your setup code here, to run once:
Serial.begin(9600);
}

int detik,menit;

void loop() {


  //pembacaan sensor membutuhkan waktu 250ms

  //Pembacaan untuk data kelembaban
  float humidity_1 = dht.readHumidity();
  //Pembacaan dalam format celcius (c)
  float celcius_1 = dht.readTemperature();
Serial.println("==============Fuzzy Logic=====================");
Serial.println(" ");
suhu = celcius_1; // contoh kita memasukan nilai suhu 54 derajat
kelembaban = humidity_1;
fuzzifikasi(); // memanggil fungsi fuzzifikasi untuk menghitung keanggotaan masing2 variable
Serial.print("dingin : ");
Serial.print(dingin);
Serial.println("t");
Serial.print("hangat : ");
Serial.println(hangat);
Serial.print("t");
Serial.print("panas : ");
Serial.println(panas);

Serial.print("kering : ");
Serial.print(kering);
Serial.println("t");
Serial.print("normal : ");
Serial.println(normal);
Serial.print("t");
Serial.print("basah : ");
Serial.println(basah);
Serial.println("=============================================");

  //pembacaan nilai pembacaan data suhu
  Serial.print("Suhu : ");
  Serial.println(celcius_1); //format derajat celcius

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
