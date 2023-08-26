/*
 * This ESP32 code is created by esp32io.com
 *
 * This ESP32 code is released in the public domain
 *
 * For more detail (instruction and wiring diagram), visit https://esp32io.com/tutorials/esp32-rfid-nfc
 */

#include <SPI.h>
#include <MFRC522.h>



#define SS_PIN  18  // ESP32 pin GIOP5 
#define RST_PIN 23 // ESP32 pin GIOP27 
String uidTag = "";     

// Pembuatan objek MFRC522 
MFRC522 mfrc(SS_PIN, RST_PIN); 

void setup() {
  Serial.begin(9600);
  SPI.begin();  
  mfrc.PCD_Init(); 

  // Cek versi software MFRC555
  byte versi = mfrc.PCD_ReadRegister(mfrc.VersionReg);
  if (versi == 0x00 || versi == 0xFF) {
    Serial.println("Modul tidak ada!");
    while (true);    
  }
  Serial.println ("Tempelkan Kartu ");
}

void loop() {

  // Periksa tag 
  if (!mfrc.PICC_IsNewCardPresent())
    return;

  // Jika nomor tag tidak terdeteksi
  if (!mfrc.PICC_ReadCardSerial())
    return;

  // UID terdeteksi
  uidTag = "";
  for (byte j = 0; j < mfrc.uid.size; j++) {
    char teks[3];
    sprintf(teks, "%02X", mfrc.uid.uidByte[j]);
    uidTag += teks;
  }
  Serial.print(" Nomor UID : ");
  Serial.println(uidTag);
  if(uidTag == "A711A128"){
    Serial.println("");
    // Kasi Delay 2 detik
    Serial.println("Akses Diterima");
    Serial.println("Nama : Adi");
    Serial.println("Jurusan : TI");
    Serial.println("====================================");
    Serial.println("");
    delay(5000);
  } else {
   
    // Kasi Delay 2 detik
    Serial.println("LOW selama 5 detik (TUTUP PINTU)");
    delay(1000);
  }
  // Change status kartu
  mfrc.PICC_HaltA();
}
