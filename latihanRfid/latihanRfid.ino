
#include <SPI.h>
#include <MFRC522.h>

const int PIN_RST = 8;  
const int PIN_SS  = 9; 

String uidTag = "";     

// Pembuatan objek MFRC522 
MFRC522 mfrc(PIN_SS, PIN_RST); 
//sketch created by Akshay Joseph
#include <Wire.h> 

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
  
  Serial.print("Tempelkan Kartu!");

}

void loop() {

    
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
  if(uidTag == "9C8ED76D"){
    
  Serial.print("Akses Diterima");
  
   
  }
  if(uidTag != "9C8ED76D"){
    
  Serial.print("Tempelkan Kartu!");
  } 
    
  else {
   
    // Kasi Delay 2 detik
    Serial.println("LOW selama 5 detik (TUTUP PINTU)");
    delay(1000);
  }
 
  // Change status kartu
  mfrc.PICC_HaltA();
}
