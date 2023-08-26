
//#define trigPin 7 //pasang pin D2 Arduino ke pin Triger HC-SR04
//#define echoPin 8 // pasang pin D3 Arduino ke pin Echo HC-SR04

//#define trigPin 9 //pasang pin D2 Arduino ke pin Triger HC-SR04
//#define echoPin 10 // pasang pin D3 Arduino ke pin Echo HC-SR04

#define trigPin 11 //pasang pin D2 Arduino ke pin Triger HC-SR04
#define echoPin 12 // pasang pin D3 Arduino ke pin Echo HC-SR04

// defines variables
long duration; // variabel untuk durasi perjalanan gelombang suara
int distance; // variabel untuk pengukuran jarak
#include <Servo.h>
Servo myservo; 
void setup() {

  pinMode(trigPin, OUTPUT); // Menetapkan trigPin sebagai OUTPUT
  pinMode(echoPin, INPUT); // Menetapkan echoPin sebagai INPUTINPUT
  Serial.begin(9600); // // Komunikasi Serial dimulai dengan kecepatan baudrate 9600
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // cetak beberapa teks di Serial Monitor
  Serial.println("with Arduino UNO R3");
}
void loop() {
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

  }
//-----------------------------------------------end program--------------------------------------------
