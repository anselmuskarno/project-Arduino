// Include the Arduino Stepper Library
const int relay3 = 7;
#include <Stepper.h>
#include <Wire.h>
#include "RTClib.h"
const int LDR = A0;
int cahayaMatahari = 0;
RTC_DS3231 rtc;
const int relay = 13;

char namaHari[7][12] = {"Minggu", "Senin", "Selasa", "Rabu", "Kamis", "Jumat", "Sabtu"};

// Number of steps per output rotation
const int stepsPerRevolution = 500;

// Create Instance of Stepper library
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);


void setup()
{
  pinMode(relay3,OUTPUT);
  // set the speed at 60 rpm:
  myStepper.setSpeed(60);
  pinMode(relay,OUTPUT);
  // initialize the serial port:
  Serial.begin(9600);
    if (! rtc.begin()) {
    Serial.println("RTC TIDAK TERBACA");
    while (1);
  }

 
}
int ulang = 1;
void loop() 
{
  Serial.println(ulang);
  cahayaMatahari = analogRead(LDR);
  
    DateTime now = rtc.now();
    int jamSekarang = now.hour();
      Serial.println(cahayaMatahari);
  Serial.println(jamSekarang);
  // step one revolution in one direction:

digitalWrite(relay, LOW);
  Serial.println("berputar");
  
  myStepper.step(stepsPerRevolution); //Menutup
//   myStepper.step(-stepsPerRevolution); //Membuka          
  
  
    Serial.println("Tidak berputar");
  
}
