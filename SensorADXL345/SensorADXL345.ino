#include "CTBot.h"
CTBot myBot;

String ssid = "lontemart";
String pass = "tidakada";
String token = "5897636923:AAEadUgThwvNq2D1JgltxmHNW_FTI-1Vas0";
const int id = 1026209843;
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
const int trigPin = 3;
const int echoPin = 5;

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>

/* Assign a unique ID to this sensor at the same time */
Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);
long duration, cm;
void displaySensorDetails(void)
{
  sensor_t sensor;
  accel.getSensor(&sensor);
  Serial.println("------------------------------------");
  Serial.print  ("Sensor:       "); Serial.println(sensor.name);
  Serial.print  ("Driver Ver:   "); Serial.println(sensor.version);
  Serial.print  ("Unique ID:    "); Serial.println(sensor.sensor_id);
  Serial.print  ("Max Value:    "); Serial.print(sensor.max_value); Serial.println(" m/s^2");
  Serial.print  ("Min Value:    "); Serial.print(sensor.min_value); Serial.println(" m/s^2");
  Serial.print  ("Resolution:   "); Serial.print(sensor.resolution); Serial.println(" m/s^2");  
  Serial.println("------------------------------------");
  Serial.println("");
  delay(500);
}

long microsecondsKeCenti(long microseconds)
{
  return microseconds / 29 / 2;
}

void displayDataRate(void)
{
  Serial.print  ("Data Rate:    "); 
  
  switch(accel.getDataRate())
  {
    case ADXL345_DATARATE_3200_HZ:
      Serial.print  ("3200 "); 
      break;
    case ADXL345_DATARATE_1600_HZ:
      Serial.print  ("1600 "); 
      break;
    case ADXL345_DATARATE_800_HZ:
      Serial.print  ("800 "); 
      break;
    case ADXL345_DATARATE_400_HZ:
      Serial.print  ("400 "); 
      break;
    case ADXL345_DATARATE_200_HZ:
      Serial.print  ("200 "); 
      break;
    case ADXL345_DATARATE_100_HZ:
      Serial.print  ("100 "); 
      break;
    case ADXL345_DATARATE_50_HZ:
      Serial.print  ("50 "); 
      break;
    case ADXL345_DATARATE_25_HZ:
      Serial.print  ("25 "); 
      break;
    case ADXL345_DATARATE_12_5_HZ:
      Serial.print  ("12.5 "); 
      break;
    case ADXL345_DATARATE_6_25HZ:
      Serial.print  ("6.25 "); 
      break;
    case ADXL345_DATARATE_3_13_HZ:
      Serial.print  ("3.13 "); 
      break;
    case ADXL345_DATARATE_1_56_HZ:
      Serial.print  ("1.56 "); 
      break;
    case ADXL345_DATARATE_0_78_HZ:
      Serial.print  ("0.78 "); 
      break;
    case ADXL345_DATARATE_0_39_HZ:
      Serial.print  ("0.39 "); 
      break;
    case ADXL345_DATARATE_0_20_HZ:
      Serial.print  ("0.20 "); 
      break;
    case ADXL345_DATARATE_0_10_HZ:
      Serial.print  ("0.10 "); 
      break;
    default:
      Serial.print  ("???? "); 
      break;
  }  
  Serial.println(" Hz");  
}

void displayRange(void)
{
  Serial.print  ("Range:         +/- "); 
  
  switch(accel.getRange())
  {
    case ADXL345_RANGE_16_G:
      Serial.print  ("16 "); 
      break;
    case ADXL345_RANGE_8_G:
      Serial.print  ("8 "); 
      break;
    case ADXL345_RANGE_4_G:
      Serial.print  ("4 "); 
      break;
    case ADXL345_RANGE_2_G:
      Serial.print  ("2 "); 
      break;
    default:
      Serial.print  ("?? "); 
      break;
  }  
  Serial.println(" g");  
}


void setup(void) 
{
  Serial.begin(9600);
  lcd.begin();
lcd.setCursor(0,0);
  lcd.print("MON. KEMIRINGAN");
  lcd.setCursor(0,1);
  lcd.print("Loading ");
  delay(500);
  lcd.setCursor(7,1);
  lcd.print(".");
  delay(500);
  lcd.print(".");
   delay(500);
  lcd.print(".");
   delay(500);
  lcd.print(".");
   delay(500);
  lcd.print(".");
   delay(500);
  lcd.print(".");
   delay(500);
   lcd.print(".");
   delay(500);
  lcd.print(".");
   delay(500);
  lcd.print(".");

delay(3000);
lcd.setCursor(0,0);
  lcd.print("SELAMAT DATANG                    ");
  lcd.setCursor(0,1);
  lcd.print("WELCOME..........                   ");
delay(200);
lcd.setCursor(0,0);
  lcd.print("                               ");
  lcd.setCursor(0,1);
  lcd.print("                                 ");
  delay(200);
lcd.setCursor(0,0);
  lcd.print("SELAMAT DATANG                    ");
  lcd.setCursor(0,1);
  lcd.print("WELCOME..........                   ");
delay(200);
lcd.setCursor(0,0);
  lcd.print("                               ");
  lcd.setCursor(0,1);
  lcd.print("                                 ");
    delay(200);
lcd.setCursor(0,0);
  lcd.print("SELAMAT DATANG                    ");
  lcd.setCursor(0,1);
  lcd.print("WELCOME..........                   ");
delay(200);
lcd.setCursor(0,0);
  lcd.print("                               ");
  lcd.setCursor(0,1);
  lcd.print("                                 ");
  lcd.setCursor(0,0);
  lcd.print("SELAMAT DATANG                    ");
  lcd.setCursor(0,1);
  lcd.print("WELCOME..........                   ");
delay(200);
lcd.setCursor(0,0);
  lcd.print("                               ");
  lcd.setCursor(0,1);
  lcd.print("                                 ");
  delay(200);
lcd.setCursor(0,0);
  lcd.print("SELAMAT DATANG                    ");
  lcd.setCursor(0,1);
  lcd.print("WELCOME..........                   ");
delay(200);
lcd.setCursor(0,0);
  lcd.print("                               ");
  lcd.setCursor(0,1);
  lcd.print("                                 ");
    delay(200);
lcd.setCursor(0,0);
  lcd.print("SELAMAT DATANG                    ");
  lcd.setCursor(0,1);
  lcd.print("WELCOME..........                   ");
  delay(3000);
  lcd.setCursor(0,0);
  lcd.print("                               ");
  lcd.setCursor(0,1);
  lcd.print("                                 ");
  
#ifndef ESP8266
  while (!Serial); // for Leonardo/Micro/Zero
#endif
  Serial.begin(9600);
  Serial.println("Starting TelegramBot...");
myBot.wifiConnect(ssid,pass);
myBot.setTelegramToken(token);

  Serial.println("Accelerometer Test"); Serial.println("");
  
  /* Initialise the sensor */
  if(!accel.begin())
  {
    /* There was a problem detecting the ADXL345 ... check your connections */
    Serial.println("Ooops, no ADXL345 detected ... Check your wiring!");
    while(1);
  }

  /* Set the range to whatever is appropriate for your project */
  accel.setRange(ADXL345_RANGE_16_G);
  // accel.setRange(ADXL345_RANGE_8_G);
  // accel.setRange(ADXL345_RANGE_4_G);
  // accel.setRange(ADXL345_RANGE_2_G);
  
  /* Display some basic information on this sensor */
  displaySensorDetails();
  
  /* Display additional settings (outside the scope of sensor_t) */
  displayDataRate();
  displayRange();
  Serial.println("");
}

void loop(void) 
{
  if(myBot.testConnection()){
  Serial.println("Koneksi Bagus");
} else {
  Serial.println("Koneksi Jelek");
  lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("PERIKSA");
      lcd.setCursor(1,1);
   lcd.print("KONEKSI");
   delay(10000);
}
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  cm = microsecondsKeCenti(duration);
  /* Get a new sensor event */ 
  sensors_event_t event; 
  accel.getEvent(&event);
  Serial.print(cm);
  Serial.print(" cm");
  Serial.println();
lcd.setCursor(0,0);
  lcd.print("X:");
  lcd.print(event.acceleration.x);
  
lcd.setCursor(9,0);
  lcd.print("Y:");
  lcd.print(event.acceleration.y);
  
  lcd.setCursor(9,1);
   lcd.print("Z:");
  lcd.print(event.acceleration.z);

 if(event.acceleration.x > 9.00){
 
  lcd.setCursor(0,1);
   lcd.print("Warning");
   myBot.sendMessage(id,"Warning");
}
else if(event.acceleration.x > -11.00 || event.acceleration.y <0.20){


  lcd.setCursor(0,1);
   lcd.print("Aman   ");
   myBot.sendMessage(id,"Aman");
}
  /* Display the results (acceleration is measured in m/s^2) */
  Serial.print("X: "); Serial.print(event.acceleration.x); Serial.print("  ");
  Serial.print("Y: "); Serial.print(event.acceleration.y); Serial.print("  ");
  Serial.print("Z: "); Serial.print(event.acceleration.z); Serial.print("  ");Serial.println("m/s^2 ");
  delay(500);
}
