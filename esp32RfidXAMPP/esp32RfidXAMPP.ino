
#include <SPI.h>
#include <MFRC522.h>
#include <WiFi.h>

#include "WiFi.h"
#include "HTTPClient.h"

const char* ssid = "LABKOM 1 NAKAMA";
const char* password = "nakama123";

const char* host = "192.168.0.100"; // atau Diganti alamat hosting


#define SS_PIN  5  // ESP32 pin GIOP5 
#define RST_PIN 27 // ESP32 pin GIOP27 
String uidTag = "";     

// Pembuatan objek MFRC522 
MFRC522 mfrc(SS_PIN, RST_PIN); 

void setup() {
  Serial.begin(9600);
  
 WiFi.begin(ssid, password); // proses menghubungkan ke WiFi
  Serial.println("Connecting ....");
  while(WiFi.status() != WL_CONNECTED){ // Selama ESP32 tdk terhubung ke WiFi, maka tampilkan karakter "."
    Serial.print(".");
    delay(500);
  }
  Serial.println("Connected."); // Esp32 sudah terhubung dengan WiFi
  
  SPI.begin(); // RFID Reader Mulai Berproses
  mfrc.PCD_Init(); 

  // Cek versi software MFRC555
  byte versi = mfrc.PCD_ReadRegister(mfrc.VersionReg);
  if (versi == 0x00 || versi == 0xFF) { // Jika RFID Reader belum terbaca, maka tampilkan tulisan "Modul tidak ada"
    Serial.println("Modul tidak ada!");
    while (true);    
  }
  Serial.println ("Tempelkan Kartu "); // Akan ditampilkan jika RFID Reader siap digunakan
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
  // Change status kartu
  mfrc.PICC_HaltA();

  WiFiClient client;
  const int httpPort = 80;
  if(!client.connect(host, httpPort)){
    Serial.println("Connection Failed.");
    return;
  }

String Link;  
HTTPClient http; 
Link = "http://"+String(host)+ "/multisensor/kirimdata.php?suhu="+String(uidTag); // Proses persiapan link data yang akan dikirim ke internet (localhost) 
http.begin(Link); // Proses pengiriman dimulai
http.GET();   // Menggunakan metode GET
String respon = http.getString(); // String yang akan menampilkan respon dari pengiriman
Serial.println(respon);    // Proses menampilkan respon dari pengiriman data
http.end(); // Proses diakhiri
//  delay(3000);
}
