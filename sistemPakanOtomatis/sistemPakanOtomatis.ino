#include <Servo.h>
Servo myservo; 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
#define trigPin 6 //pasang pin D2 Arduino ke pin Triger HC-SR04
#define echoPin 7 // pasang pin D3 Arduino ke pin Echo HC-SR04

// defines variables
long duration; // variabel untuk durasi perjalanan gelombang suara
int distance; // variabel untuk pengukuran jarak

void setup() {
  
  lcd.begin();
  pinMode(trigPin, OUTPUT); // Menetapkan trigPin sebagai OUTPUT
  pinMode(echoPin, INPUT); // Menetapkan echoPin sebagai INPUTINPUT
  Serial.begin(9600); // // Komunikasi Serial dimulai dengan kecepatan baudrate 9600
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // cetak beberapa teks di Serial Monitor
  Serial.println("with Arduino UNO R3");
myservo.attach(9);
}
void loop() {
  myservo.write(0);
  // Menghapus kondisi trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Menyetel trigPin TINGGI (AKTIF) selama 10 mikrodetik
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW); 
 duration = pulseIn(echoPin, HIGH);
  // Menghitung jarak
  distance = duration * 0.034 / 2; // Kecepatan gelombang suara dibagi 2 (pergi dan kembali)
  // Menampilkan jarak pada Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
lcd.setCursor(0,0);
  lcd.print("Jarak: ");
  lcd.print(distance);
  lcd.print(" cm                        ");
  delay(100);
//lcd.clear();
  if(distance<=15){
    myservo.write(90);
    delay(5000);
    myservo.write(0);
  }
  }
//-----------------------------------------------end program--------------------------------------------
