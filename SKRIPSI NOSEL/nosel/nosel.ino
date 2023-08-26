#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
const int relay = 7;
const int relay2 = 6;
#include "HX711.h"
#include <Stepper.h>
#include <Wire.h>
// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 12;
const int LOADCELL_SCK_PIN = 13;

HX711 scale;
// Number of steps per output rotation
const int stepsPerRevolution = 500;

// Create Instance of Stepper library
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

void setup() {
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
  // set the speed at 60 rpm:
  myStepper.setSpeed(60);
  pinMode(relay,OUTPUT);
    pinMode(relay2,OUTPUT);
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
}

void loop() {
   digitalWrite(relay2, LOW);
if (!scale.is_ready()) {
  Serial.println("HX711 not found.");
  }
//   myStepper.step(-stepsPerRevolution); //Membuka     
  if (scale.is_ready()) {
    long reading = scale.read();
    Serial.print("HX711 reading: ");
    Serial.println(reading);
    reading=reading*-1;
    if(reading<950000){
        lcd.setCursor(0,0);
  lcd.print("Berat : 0 KG           ");
      Serial.println("Berat : 0 KG");
    }  else if(reading>=950000 && reading<=959585){
       Serial.println("0.1 KG");
        lcd.setCursor(0,0);
  lcd.print("Berat : 0.1 KG           ");
      }
    else if(reading>=959585 && reading<=979151){
       Serial.println("0.2 KG");
         lcd.setCursor(0,0);
  lcd.print("Berat : 0.2 KG           ");
      }  else if(reading>=979151 && reading<=1001670){
       Serial.println("0.3 KG");
         lcd.setCursor(0,0);
  lcd.print("Berat : 0.3 KG           ");
      } 
      else if(reading>=1001670 && reading<=1003670){
       Serial.println("0.4 KG");
         lcd.setCursor(0,0);
  lcd.print("Berat : 0.4 KG           ");
      } else if(reading>=1003670 && reading<=1029845){
       Serial.println("0.5 KG");
         lcd.setCursor(0,0);
  lcd.print("Berat : 0.5 KG           ");
      } else if(reading>=1029845 && reading<=1059845){
       Serial.println("0.6 KG");
         lcd.setCursor(0,0);
  lcd.print("Berat : 0.6 KG           ");
      }
      else if(reading>=1059845 && reading<=1089512){
       Serial.println("0.7 KG");
         lcd.setCursor(0,0);
  lcd.print("Berat : 0.7 KG           ");
      }  else if(reading>=1089512 && reading<=1109577){
       Serial.println("0.8 KG");
         lcd.setCursor(0,0);
  lcd.print("Berat : 0.8 KG           ");
      } else if(reading>=1109577 && reading<=1129702){
       Serial.println("0.9 KG");
         lcd.setCursor(0,0);
  lcd.print("Berat : 0.9 KG           ");
      } else if(reading>=1129702 && reading<=1149814){
       Serial.println("1.0 KG");
         lcd.setCursor(0,0);
  lcd.print("Berat : 1.0 KG           ");
      } else if(reading>=1149814 && reading<=1159362){
       Serial.println("1.1 KG");
         lcd.setCursor(0,0);
  lcd.print("Berat : 1.1 KG           ");
      } 
    else if(reading>=1159362 && reading<=1189038){
        lcd.setCursor(0,0);
  lcd.print("Berat : 1.2 KG           ");
      Serial.println("1.2 KG");
//  for(int i=1; i<=20; i++){ 
//      long reading = scale.read();  
//      digitalWrite(relay, LOW);
//  Serial.println("berputar");
//  myStepper.step(stepsPerRevolution); //Membuka
//  }
//   digitalWrite(relay, HIGH);
//  delay(30000); 
////  delay(300000);// 5 menit
//   for(int i=1; i<=20; i++){   
//      digitalWrite(relay, LOW);
//  Serial.println("berputar");
//  myStepper.step(-stepsPerRevolution); //Menutup
//  } 
//   digitalWrite(relay2, HIGH);
//    digitalWrite(relay, HIGH);
//  delay(30000);
//   digitalWrite(relay2, LOW);
////  delay(300000);// 5 menit
    } else if(reading>1189038 && reading<=1210621){
        lcd.setCursor(0,0);
  lcd.print("Berat : 1.3 KG           ");
      Serial.println("1.3 KG");
    }
    else if(reading>1210621 && reading<=1225714){
        lcd.setCursor(0,0);
  lcd.print("Berat : 1.4 KG           ");
      Serial.println("1.4 KG");
    }  else if(reading>1225714 && reading<=1259538){
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
    } else if(reading>1800000 && reading<=2100000){
        lcd.setCursor(0,0);
  lcd.print("Berat : 4 KG           ");
      Serial.println("4KG");
    } else if(reading>2100000 && reading<=2400000){
        lcd.setCursor(0,0);
  lcd.print("Berat : 5 KG           ");
      Serial.println("5KG");
    } else if(reading>2400000 && reading<=2700000){
        lcd.setCursor(0,0);
  lcd.print("Berat : 6 KG           ");
      Serial.println("6KG");
    }
  } else {
    Serial.println("HX711 not found.");
  }

  delay(1000);
  
}
