#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SimpleTimer.h>
const int relay = 8;
const int relay2 = 6;
const int relayKapur = 9;
SimpleTimer timer;
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

// SENSOR PH = PIN A0
// SUHU = PIN 7
// RELAY = PIN 8
// RELAY2 = PIN 6
// RELAYKAPUR = 9

float calibration_value = 21.34 - 0.7;
int phval = 0; 
unsigned long int avgval; 
int buffer_arr[10],temp;

float ph_act;
// for the OLED display

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
 
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#include <OneWire.h>
#include <DallasTemperature.h>
 
// sensor diletakkan di pin 2
#define ONE_WIRE_BUS 7
 
// setup sensor
OneWire oneWire(ONE_WIRE_BUS);
 
// berikan nama variabel,masukkan ke pustaka Dallas
DallasTemperature sensorSuhu(&oneWire);
 
float suhuSekarang;
 

void setup() 
{
  Wire.begin();
 Serial.begin(9600);
   sensorSuhu.begin();
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextColor(WHITE); 
pinMode(relay,OUTPUT);
pinMode(relay2,OUTPUT);
pinMode(relayKapur,OUTPUT);
 
timer.setInterval(500L, display_pHValue);
 lcd.begin();
  lcd.setCursor(0, 0);
  lcd.print("LOADING....                  ");
  lcd.setCursor(0, 1);
  lcd.print("                  ");
  delay(3000);
   lcd.setCursor(0, 0);
  lcd.print("PENGENDALIAN");
    lcd.setCursor(0, 1);
  lcd.print("KUALITAS AIR");
 delay(5000);
 lcd.clear();
}
void loop() {
    
  digitalWrite(relay, LOW);
    digitalWrite(relay2, HIGH);
    digitalWrite(relayKapur, HIGH);
  timer.run(); // Initiates SimpleTimer
 for(int i=0;i<10;i++) 
 { 
 buffer_arr[i]=analogRead(A0);
 delay(30);
 }
 for(int i=0;i<9;i++)
 {
 for(int j=i+1;j<10;j++)
 {
 if(buffer_arr[i]>buffer_arr[j])
 {
 temp=buffer_arr[i];
 buffer_arr[i]=buffer_arr[j];
 buffer_arr[j]=temp;
 }
 }
 }
 avgval=0;
 for(int i=2;i<8;i++)
 avgval+=buffer_arr[i];
 float volt=(float)avgval*5.0/1024/6; 
  ph_act = -5.70 * volt + calibration_value;

 Serial.print("Nilai PH: ");
 Serial.println(ph_act);
  suhuSekarang = ambilSuhu();
 Serial.print("Suhu : "); Serial.println(suhuSekarang);   

 lcd.setCursor(0, 0);
  lcd.print("Suhu : ");
   lcd.print(suhuSekarang);
    lcd.setCursor(0, 1);
  lcd.print("PH : ");
  if(ph_act < 0){
  ph_act = ph_act*(-1);    
  }

   lcd.print(ph_act);
   if (suhuSekarang >= 30){
      digitalWrite(relay, HIGH);
       digitalWrite(relay2, LOW);
      delay(10000);
   }
     if (ph_act < 6){
       digitalWrite(relayKapur, LOW);
//       digitalWrite(relay2, LOW);
      delay(3000);
   }
 delay(1000);
 lcd.clear();
}

float ambilSuhu()
{
   sensorSuhu.requestTemperatures();
   float suhu = sensorSuhu.getTempCByIndex(0);
   return suhu;   
}

void display_pHValue()
{
     // display on Oled display

   // Oled display
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(0,0); // column row
  display.print("pH:");

  display.setTextSize(2);
  display.setCursor(55, 0);
  display.print(ph_act);

/*
    display.setTextSize(2);
  display.setCursor(0,30);
  display.print("EC:");

  display.setTextSize(2);
  display.setCursor(60, 30);
  display.print(345);
  display.setCursor(95, 50);
*/
 display.display();
}
