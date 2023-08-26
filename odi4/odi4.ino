#define IN1 10 // deklarasi pin IN1
#define IN2 9  // deklarasi pin IN2
#define IN3 5  // deklarasi pin IN3
#define IN4 4  // deklarasi pin IN4
#define ENA 11 // deklarasi pin ENA
#define ENB 3  // deklarasi pin ENB

void setup() {
  // Konfigurasi pin-pin sebagai Output
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
}

void loop() {
  // Motor A dan B berputar ke kanan 2000 ms (2 detik) dengan kecepatan penuh
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(ENA, 10); // Mengatur kecepatan motor A (0-255) kiri
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  digitalWrite(ENB, 240); // Mengatur kecepatan motor B (0-255) kanan
//  delay(2000); // Jeda 2 detik

//  // Motor A dan B berputar ke kiri 2000 ms (2 detik) dengan kecepatan penuh
//  digitalWrite(IN1, LOW);
//  digitalWrite(IN2, HIGH);
//  digitalWrite(ENA, 255); // Mengatur kecepatan motor A (255 = 100%)
//  digitalWrite(IN3, LOW);
//  digitalWrite(IN4, HIGH);
//  digitalWrite(ENB, 255); // Mengatur kecepatan motor B (255 = 100%)
//  delay(2000); // Jeda 2 detik;
//
//  // Motor A ke kiri dan motor B ke kanan 2000 ms (2 detik) dengan kecepatan 50%
//  digitalWrite(IN1, LOW);
//  digitalWrite(IN2, HIGH);
//  digitalWrite(ENA, 128); // Mengatur kecepatan motor A (128 = 50%)
//  digitalWrite(IN3, HIGH);
//  digitalWrite(IN4, LOW);
//  digitalWrite(ENB, 128); // Mengatur kecepatan motor B (128 = 50%)
//  delay(2000); // Jeda 2 detik;
//
//  // Motor A dan motor B berhenti selama 2000 ms (2 detik)
//  digitalWrite(IN1, LOW);
//  digitalWrite(IN2, LOW);
//  digitalWrite(ENA, LOW);
//  digitalWrite(IN3, LOW);
//  digitalWrite(IN4, LOW);
//  digitalWrite(ENB, LOW);
//  delay(2000);
}
