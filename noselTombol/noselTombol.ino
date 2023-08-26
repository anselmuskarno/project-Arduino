#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
const int relay = 7;
const int relay2 = 6;
#include "HX711.h"
#include <Stepper.h>
#include <Wire.h>
// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 2;
const int LOADCELL_SCK_PIN = 3;

int tombolPin = 13; // Pin input
int tombol = LOW; // diberi logika high yang berarti tidak ada halangan

HX711 scale;
// Number of steps per output rotation
const int stepsPerRevolution = 500;

// Create Instance of Stepper library
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

void setup() {
   pinMode(tombolPin, INPUT);
  Serial.begin(9600);
   lcd.begin();
   lcd.setCursor(0,0);
  lcd.print("LOADING...");
  delay(5000);
  lcd.clear();
    lcd.setCursor(0,0);
  lcd.print("PENGERING GABAH");
  lcd.setCursor(0,1);
  lcd.print("OTOMATIS");
  delay(5000);
  lcd.clear();
//   set the speed at 60 rpm:
  myStepper.setSpeed(60);
  pinMode(relay,OUTPUT);
    pinMode(relay2,OUTPUT);
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
}
int berat = 0;
void loop() {
   tombol = digitalRead(tombolPin);
   digitalWrite(relay2, LOW);
if (!scale.is_ready()) {
  Serial.println("HX711 not found.");
  }
//   myStepper.step(-stepsPerRevolution); //Membuka     
  if (scale.is_ready()) {
    long reading = scale.read();
    Serial.print("HX711 reading: ");
    reading=reading*-1;
    Serial.println(reading);
    
     if(reading<=669358 ){
      berat=0;
       Serial.println("0 KG");
        lcd.setCursor(0,0);
  lcd.print("Berat : 0 KG           ");
      }  
else if(reading>=670005 && reading<=789995){
  berat = 500;
       Serial.println("0.5 KG");
         lcd.setCursor(0,0);
  lcd.print("Berat : 0.5 KG           ");
      }
      else if(reading>=773517 && reading<=854117){
        berat = 1000;
       Serial.println("1.0 KG");
         lcd.setCursor(0,0);
  lcd.print("Berat : 1.0 KG           ");
      } 

    else if(reading>890296 && reading<=929999){
      berat = 1500;
        lcd.setCursor(0,0);
  lcd.print("Berat : 1.5 KG           ");
      Serial.println("1.5 KG");
    }
    else if(reading>1200000 && reading<=1500000){
        lcd.setCursor(0,0);
  lcd.print("Berat : 2 KG           ");
      Serial.println("2KG");
    }
    else if(reading>1500000 && reading<=1800000){
        lcd.setCursor(0,0);
  lcd.print("Berat : 3 KG           ");
      Serial.println("3KG");
    } 
  } else {
    berat = 0;
    Serial.println("HX711 not found.");
  }
if(berat > 0 && tombol == HIGH){
  lcd.clear();
   lcd.setCursor(0,0);
  lcd.print("Berat Awal : ");
  if(berat == 500){
    lcd.print("0.5");
  } else if(berat == 1000){
    lcd.print("1");
  } else if(berat == 1500){
    lcd.print("1.5");
  } 
  
  lcd.setCursor(0,1);
  lcd.print("PROSES PENGERINGAN");
  delay(10000);
    lcd.clear();
     lcd.setCursor(0,0);
  lcd.print("SELESAI.");
  delay(5000);
  lcd.clear();
}

if(berat == 0 && tombol == HIGH){
  lcd.clear();
   lcd.setCursor(0,0);
  lcd.print("SILAHKAN MASUKKAN");
  lcd.setCursor(0,1);
  lcd.print("GABAH!");
  delay(3000);
  lcd.clear();
}
  delay(1000);
  
}
