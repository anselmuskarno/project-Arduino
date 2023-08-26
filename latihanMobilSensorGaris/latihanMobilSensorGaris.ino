#define enA 9
#define in1 5
#define in2 18
#define enB 10
#define in3 19
#define in4 23
int motorSpeedA = 0;
int motorSpeedB = 0;

#include <LiquidCrystal_I2C.h>
// set the LCD number of columns and rows
int lcdColumns = 16;
int lcdRows = 2;

LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);  

// Inisialisasi 5 pin sensor 
int sensor1 = 25;
int sensor2 = 26;
int sensor3 = 14;
int sensor4 = 27;
int sensor5 = 12;

// Inisialisasi pembacaan sensor
int menyala = 1;
int mati = 0;

void setup() {
  // Menjadikan sensor 1 sampai 5 sebagai input
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);
  pinMode(sensor4, INPUT);
  pinMode(sensor5, INPUT);
  
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // Mengaktifkan serial monitor
  Serial.begin(9600);
    // initialize LCD
  lcd.begin();
  // turn on LCD backlight                      
  lcd.backlight();
}


void loop() {

// set cursor to first column, first row
  lcd.setCursor(0, 0);
  // print message
  lcd.print("Hello, World!");
  delay(100);
  // clears the display to print new message
  lcd.clear();
  // set cursor to first column, second row
  lcd.setCursor(0,1);
  lcd.print("Hello, World!");
  delay(100);
  lcd.clear(); 
  
// Membaca sensor garis 1 sampai 5
int lampuSensor1 = digitalRead(sensor1);
int lampuSensor2 = digitalRead(sensor2);
int lampuSensor3 = digitalRead(sensor3);
int lampuSensor4 = digitalRead(sensor4);
int lampuSensor5 = digitalRead(sensor5);

    motorSpeedA = 80; //bisa diambil dari joystick, tapi sekarang kita input manual aja yak; 0-255
    motorSpeedB = 80; //bisa diambil dari joystick, tapi sekarang kita input manual aja yak; 0-255
//    analogWrite(enA, motorSpeedA); // Send PWM signal to motor A
//    analogWrite(enB, motorSpeedB); // Send PWM signal to motor B
    if ( 
lampuSensor1 == mati && lampuSensor2 == menyala && lampuSensor3 == mati && lampuSensor4 == menyala && lampuSensor5 == mati ||
//lampuSensor1 == mati && lampuSensor2 == mati && lampuSensor3 == menyala && lampuSensor4 == menyala && lampuSensor5 == mati ||
lampuSensor1 == menyala && lampuSensor2 == menyala && lampuSensor3 == mati && lampuSensor4 == menyala && lampuSensor5 == menyala ||
//lampuSensor1 == mati && lampuSensor2 == menyala && lampuSensor3 == menyala && lampuSensor4 == menyala && lampuSensor5 == menyala ||
lampuSensor1 == menyala && lampuSensor2 == mati && lampuSensor3 == menyala && lampuSensor4 == menyala && lampuSensor5 == menyala ||
lampuSensor1 == menyala && lampuSensor2 == menyala && lampuSensor3 == menyala && lampuSensor4 == mati && lampuSensor5 == menyala){
  Serial.println("Motor DC (ban) Tidak berjalan");
  // Set Motor A backward
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
     // Set Motor B backward
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
}
if(lampuSensor1 == mati && lampuSensor2 == mati && lampuSensor3 == mati && lampuSensor4 == mati && lampuSensor5 == mati){
 Serial.println("Mundur");
 // Set Motor A backward
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
     // Set Motor B backward
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    
}
else if (
lampuSensor1 == menyala && lampuSensor2 == menyala && lampuSensor3 == menyala && lampuSensor4 == menyala && lampuSensor5 == menyala ||
  lampuSensor1 == mati && lampuSensor2 == mati && lampuSensor3 == menyala && lampuSensor4 == mati && lampuSensor5 == mati ||
lampuSensor1 == mati && lampuSensor2 == menyala && lampuSensor3 == menyala && lampuSensor4 == menyala && lampuSensor5 == mati ||
lampuSensor1 == mati && lampuSensor2 == menyala && lampuSensor3 == menyala && lampuSensor4 == mati && lampuSensor5 == mati ||
lampuSensor1 == mati && lampuSensor2 == menyala && lampuSensor3 == mati && lampuSensor4 == mati && lampuSensor5 == mati ||
lampuSensor1 == mati && lampuSensor2 == mati && lampuSensor3 == mati && lampuSensor4 == menyala && lampuSensor5 == mati ||
lampuSensor1 == mati && lampuSensor2 == mati && lampuSensor3 == menyala && lampuSensor4 == menyala && lampuSensor5 == mati) {
  Serial.println("Jalan Lurus");
  // Set Motor A forward MOTOR KANAN
   digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
     // Set Motor B backward
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    
} 
else  if (lampuSensor1 == mati && lampuSensor2 == menyala && lampuSensor3 == menyala && lampuSensor4 == menyala && lampuSensor5 == menyala ||
  lampuSensor1 == mati && lampuSensor2 == mati && lampuSensor3 == mati && lampuSensor4 == mati && lampuSensor5 == menyala ||
lampuSensor3 == menyala && lampuSensor4 == menyala && lampuSensor5 == menyala ||
lampuSensor3 == mati && lampuSensor4 == menyala && lampuSensor5 == menyala){
 Serial.println("Belok kiri");
  // Set Motor A backward
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
     // Set Motor B backward
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);   
   }
   else if (lampuSensor1 == menyala && lampuSensor2 == mati && lampuSensor3 == mati && lampuSensor4 == mati && lampuSensor5 == mati ||
lampuSensor1 == menyala && lampuSensor2 == menyala && lampuSensor3 == menyala ||
lampuSensor1 == menyala && lampuSensor2 == menyala && lampuSensor3 == mati ){
Serial.println("Belok kanan");
 // Set Motor A backward
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
     // Set Motor B backward
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH); 
}

}
