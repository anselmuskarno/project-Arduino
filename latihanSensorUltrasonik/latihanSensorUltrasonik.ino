const int trigPin = 3;
const int echoPin = 5;
//const int trigPin = 10;
//const int echoPin = 9;
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600); 
  pinMode(11,OUTPUT);
  lcd.begin();
}

long duration, cm;
 
void loop()
{
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

 lcd.setCursor(0, 0);
  lcd.print("Jumlah Jemaat : ");
  

  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  Serial.println(cm);
  cm = microsecondsKeCenti(duration);
  Serial.println();
}
long microsecondsKeCenti(long microseconds)
{
  return microseconds / 29 / 2;
}
