#include <Wire.h> 
#include <Adafruit_Fingerprint.h>
#if (defined(__AVR__) || defined(ESP8266)) && !defined(__AVR_ATmega2560__)
SoftwareSerial mySerial(2, 3);
#else
#define mySerial Serial1
#endif
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);
#include <LiquidCrystal_I2C.h>
#include "DS3231_Simple.h"
DS3231_Simple Clock;
LiquidCrystal_I2C lcd(0x27, 16, 2);
int jam = 24;
int parameter = 0;

void setup()
{
   pinMode(5, OUTPUT); 
  Serial.begin(9600);
  Serial.println("CLEARDATA");
  Serial.println("LABEL,NAMA GURU,JAM MASUK,JAM KELUAR,KETERANGAN,"); //ubah nama judul kolom
  Serial.println("RESETTIMER");
  
  Clock.begin();
   lcd.begin();
   lcd.setCursor(0,0);
  lcd.print("Loading ...");
  lcd.setCursor(0,1);
  lcd.print("Powered By : Rob");
  lcd.setCursor(0,1);
  delay(1000);
  lcd.print("owered By : Robo");
  lcd.setCursor(0,1);
  delay(500);
  lcd.print("wered By : Robot");
  lcd.setCursor(0,1);
  delay(500);
  lcd.print("ered By : Roboti");
  lcd.setCursor(0,1);
  delay(500);
  lcd.print("red By : Robotik");
  lcd.setCursor(0,1);
  delay(500);
  lcd.print("ed By : Robotika");
   lcd.setCursor(0,1);
   delay(500);
  lcd.print("d By : Robotika ");
   lcd.setCursor(0,1);
   delay(500);
  lcd.print(" By : Robotika E");
  lcd.setCursor(0,1);
  delay(500);
  lcd.print(" y : Robotika Er");
  lcd.setCursor(0,1);
  delay(500);
  lcd.print("  : Robotika Erb");
  lcd.setCursor(0,1);
  delay(500);
  lcd.print(" : Robotika Erba");
  lcd.setCursor(0,1);
  delay(500);
  lcd.print("Robotika Erba    ");
  delay(1500);
  while (!Serial);  // For Yun/Leo/Micro/Zero/...
  delay(100);
  Serial.println("\n\nAdafruit finger detect test");

  // set the data rate for the sensor serial port
  finger.begin(57600);
  delay(5);
  if (finger.verifyPassword()) {
    Serial.println("Found fingerprint sensor!");
  } else {
    Serial.println("Did not find fingerprint sensor :(");
    while (1) { delay(1); }
  }

  Serial.println(F("Reading sensor parameters"));
  finger.getParameters();
  Serial.print(F("Status: 0x")); Serial.println(finger.status_reg, HEX);
  Serial.print(F("Sys ID: 0x")); Serial.println(finger.system_id, HEX);
  Serial.print(F("Capacity: ")); Serial.println(finger.capacity);
  Serial.print(F("Security level: ")); Serial.println(finger.security_level);
  Serial.print(F("Device address: ")); Serial.println(finger.device_addr, HEX);
  Serial.print(F("Packet len: ")); Serial.println(finger.packet_len);
  Serial.print(F("Baud rate: ")); Serial.println(finger.baud_rate);

  finger.getTemplateCount();

  if (finger.templateCount == 0) {
    Serial.print("Sensor doesn't contain any fingerprint data. Please run the 'enroll' example.");
  }
  else {
    Serial.println("Waiting for valid finger...");
      Serial.print("Sensor contains "); Serial.print(finger.templateCount); Serial.println(" templates");
  }
}
int nilai = 0;
int nilaiAdi = 0;
int nilaiMaria = 0;
int nilaiEster = 0;
int nilaiSelti = 0;
int nilaiNona = 0;
int nilaiYeheskiel = 0;

void loop()                     // run over and over again
{
  getFingerprintID();
  delay(50);            //don't ned to run this at full speed.
}

uint8_t getFingerprintID() {
   DateTime waktu;
  waktu = Clock.read();
  lcd.setCursor(0,0);
  lcd.print("Tempelkan               ");
  lcd.setCursor(0,1);
  lcd.print("Jari Anda      ");
  if(waktu.Hour>=10){
    lcd.setCursor(11,1);
  lcd.print(waktu.Hour);
//   lcd.setCursor(11,1);
//  lcd.print(""); 
  }
  lcd.setCursor(13,1);
  lcd.print(":");
  if(waktu.Second < 10){
  lcd.setCursor(15,0);
  lcd.print(" ");  
  }
  if(waktu.Minute < 10){
     lcd.setCursor(15,1);
  lcd.print(waktu.Minute);
  lcd.setCursor(14,1);
  lcd.print("0");  
  }
   if(waktu.Hour < 10){
    lcd.setCursor(11,1);
  lcd.print("0");  
  lcd.setCursor(12,1);
  lcd.print(waktu.Hour);  
  }
  if(waktu.Minute>=10){
    lcd.setCursor(14,1);
  lcd.print(waktu.Minute);
  }
  
  lcd.setCursor(14,0);
  lcd.print(waktu.Second);
  uint8_t p = finger.getImage();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image taken");
      break;
    case FINGERPRINT_NOFINGER:
      Serial.println("No finger detected");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_IMAGEFAIL:
      Serial.println("Imaging error");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }

  // OK success!

  p = finger.image2Tz();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image converted");
      break;
    case FINGERPRINT_IMAGEMESS:
      Serial.println("Image too messy");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_FEATUREFAIL:
      Serial.println("Could not find fingerprint features");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      Serial.println("Could not find fingerprint features");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }

  // OK converted!
  p = finger.fingerSearch();
  if (p == FINGERPRINT_OK) {
    Serial.println("Found a print match!");
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Communication error");
    return p;
  } else if (p == FINGERPRINT_NOTFOUND) {
    digitalWrite(5, HIGH);
      lcd.setCursor(0,0);
    lcd.println("Sidik Jari                 ");
    lcd.setCursor(0,1);
    lcd.println("BELUM DIDAFTAR                 ");
    delay(5000);
    digitalWrite(5, LOW);
    return p;
  } else {
    Serial.println("Unknown error");
    return p;
  }

  // found a match!
  Serial.print("Found ID #"); Serial.print(finger.fingerID);
  Serial.print(" with confidence of "); Serial.println(finger.confidence);

if (finger.fingerID == 1 && nilai == 2){
  digitalWrite(5, HIGH);
     lcd.setCursor(0,0);
  lcd.print("Lakukan Absensi             ");
    lcd.setCursor(0,1);
  lcd.print("ESOK HARI !!!              ");
 nilai = 2;
    delay(5000);
    digitalWrite(5, LOW);
  }

if (finger.fingerID == 1 && nilai == 1){
  digitalWrite(7, HIGH);
    nilai = 2;
    Serial.print("DATA,ANSELMUS KARNO S.KOM,");
    Serial.print(" ");
    Serial.print(",");
    Serial.print(waktu.Hour, DEC);
    Serial.print(".");
    Serial.print(waktu.Minute, DEC);
    Serial.print(",");
    Serial.println("SMK ERAN BATU 3 SANGGALANGI");
     lcd.setCursor(0,0);
  lcd.print("ANSELMUS KARNO   ");
    lcd.setCursor(0,1);
  lcd.print("Jam Keluar  ");
  if(waktu.Hour>=10){
    lcd.setCursor(11,1);
  lcd.print(waktu.Hour);
   lcd.setCursor(10,1);
  lcd.print(""); 
  }
  lcd.setCursor(13,1);
  lcd.print(":");
  
  if(waktu.Minute < 10){
     lcd.setCursor(15,1);
  lcd.print(waktu.Minute);
  lcd.setCursor(14,1);
  lcd.print("0");  
  }
   if(waktu.Hour < 10){
    lcd.setCursor(11,1);
  lcd.print("0");  
  lcd.setCursor(12,1);
  lcd.print(waktu.Hour);  
  }
  if(waktu.Minute>=10){
    lcd.setCursor(14,1);
  lcd.print(waktu.Minute);
  }
  
    delay(5000);
     digitalWrite(7, LOW);
  }

  if (finger.fingerID == 1 && nilai == 0){
    digitalWrite(7, HIGH);
    Serial.print("DATA,ANSELMUS KARNO S.KOM,");
    Serial.print(waktu.Hour, DEC);
    Serial.print(".");
    Serial.print(waktu.Minute, DEC);
    Serial.print(",");
    Serial.print(" ");
    Serial.print(",");
    Serial.println("SMK ERAN BATU 3 SANGGALANGI");
     lcd.setCursor(0,0);
  lcd.print("ANSELMUS KARNO   ");
    lcd.setCursor(0,1);
  lcd.print("Jam Masuk  ");
  if(waktu.Hour>=10){
    lcd.setCursor(12,1);
  lcd.print(waktu.Hour);
   lcd.setCursor(11,1);
  lcd.print(""); 
  }
  lcd.setCursor(13,1);
  lcd.print(":");
  
  if(waktu.Minute < 10){
     lcd.setCursor(15,1);
  lcd.print(waktu.Minute);
  lcd.setCursor(14,1);
  lcd.print("0");  
  }
   if(waktu.Hour < 10){
    lcd.setCursor(11,1);
  lcd.print("0");  
  lcd.setCursor(12,1);
  lcd.print(waktu.Hour);  
  }
  if(waktu.Minute>=10){
    lcd.setCursor(14,1);
  lcd.print(waktu.Minute);
  }
  
    delay(5000);
    nilai=1;
    digitalWrite(7, LOW);
  }
// ================================================== //
  if (finger.fingerID == 7 && nilaiAdi == 2){
     lcd.setCursor(0,0);
  lcd.print("Lakukan Absensi             ");
    lcd.setCursor(0,1);
  lcd.print("ESOK HARI !!!              ");
 nilaiAdi = 2;
    delay(5000);
  }

if (finger.fingerID == 7 && nilaiAdi == 1){
    nilaiAdi = 2;
    Serial.print("DATA,ADI PAIRUNAN S.KOM,");
    Serial.print(" ");
    Serial.print(",");
    Serial.print(waktu.Hour, DEC);
    Serial.print(".");
    Serial.print(waktu.Minute, DEC);
    Serial.print(",");
    Serial.println("SMK ERAN BATU 3 SANGGALANGI");
     lcd.setCursor(0,0);
  lcd.print("ADI PAIRUNAN   ");
    lcd.setCursor(0,1);
  lcd.print("Jam Keluar  ");
  if(waktu.Hour>=10){
    lcd.setCursor(11,1);
  lcd.print(waktu.Hour);
   lcd.setCursor(10,1);
  lcd.print(""); 
  }
  lcd.setCursor(13,1);
  lcd.print(":");
  
  if(waktu.Minute < 10){
     lcd.setCursor(15,1);
  lcd.print(waktu.Minute);
  lcd.setCursor(14,1);
  lcd.print("0");  
  }
   if(waktu.Hour < 10){
    lcd.setCursor(11,1);
  lcd.print("0");  
  lcd.setCursor(12,1);
  lcd.print(waktu.Hour);  
  }
  if(waktu.Minute>=10){
    lcd.setCursor(14,1);
  lcd.print(waktu.Minute);
  }
  
    delay(5000);
  }

  if (finger.fingerID == 7 && nilaiAdi == 0){
   
    Serial.print("DATA,ADI PAIRUNAN S.KOM,");
    Serial.print(waktu.Hour, DEC);
    Serial.print(".");
    Serial.print(waktu.Minute, DEC);
    Serial.print(",");
    Serial.print(" ");
    Serial.print(",");
    Serial.println("SMK ERAN BATU 3 SANGGALANGI");
     lcd.setCursor(0,0);
  lcd.print("ADI PAIRUNAN   ");
    lcd.setCursor(0,1);
  lcd.print("Jam Masuk  ");
  if(waktu.Hour>=10){
    lcd.setCursor(12,1);
  lcd.print(waktu.Hour);
   lcd.setCursor(11,1);
  lcd.print(""); 
  }
  lcd.setCursor(13,1);
  lcd.print(":");
  
  if(waktu.Minute < 10){
     lcd.setCursor(15,1);
  lcd.print(waktu.Minute);
  lcd.setCursor(14,1);
  lcd.print("0");  
  }
   if(waktu.Hour < 10){
    lcd.setCursor(11,1);
  lcd.print("0");  
  lcd.setCursor(12,1);
  lcd.print(waktu.Hour);  
  }
  if(waktu.Minute>=10){
    lcd.setCursor(14,1);
  lcd.print(waktu.Minute);
  }
  
    delay(5000);
    nilaiAdi=1;
  }
// ================================================== //
  if (finger.fingerID == 8 && nilaiMaria == 2){
     lcd.setCursor(0,0);
  lcd.print("Lakukan Absensi             ");
    lcd.setCursor(0,1);
  lcd.print("ESOK HARI !!!              ");
 nilaiMaria = 2;
    delay(5000);
  }

if (finger.fingerID == 8 && nilaiMaria == 1){
    nilaiMaria = 2;
    Serial.print("DATA,MARIA LIMBONG BUA,");
    Serial.print(" ");
    Serial.print(",");
    Serial.print(waktu.Hour, DEC);
    Serial.print(".");
    Serial.print(waktu.Minute, DEC);
    Serial.print(",");
    Serial.println("SMK ERAN BATU 3 SANGGALANGI");
     lcd.setCursor(0,0);
  lcd.print("MARIA LIMBONG BUA   ");
    lcd.setCursor(0,1);
  lcd.print("Jam Keluar  ");
  if(waktu.Hour>=10){
    lcd.setCursor(11,1);
  lcd.print(waktu.Hour);
   lcd.setCursor(10,1);
  lcd.print(""); 
  }
  lcd.setCursor(13,1);
  lcd.print(":");
  
  if(waktu.Minute < 10){
     lcd.setCursor(15,1);
  lcd.print(waktu.Minute);
  lcd.setCursor(14,1);
  lcd.print("0");  
  }
   if(waktu.Hour < 10){
    lcd.setCursor(11,1);
  lcd.print("0");  
  lcd.setCursor(12,1);
  lcd.print(waktu.Hour);  
  }
  if(waktu.Minute>=10){
    lcd.setCursor(14,1);
  lcd.print(waktu.Minute);
  }
  
    delay(5000);
  }

  if (finger.fingerID == 8 && nilaiMaria == 0){
   
    Serial.print("DATA,MARIA LIMBONG BUA,");
    Serial.print(waktu.Hour, DEC);
    Serial.print(".");
    Serial.print(waktu.Minute, DEC);
    Serial.print(",");
    Serial.print(" ");
    Serial.print(",");
    Serial.println("SMK ERAN BATU 3 SANGGALANGI");
     lcd.setCursor(0,0);
  lcd.print("MARIA LIMBONG BUA   ");
    lcd.setCursor(0,1);
  lcd.print("Jam Masuk  ");
  if(waktu.Hour>=10){
    lcd.setCursor(12,1);
  lcd.print(waktu.Hour);
   lcd.setCursor(11,1);
  lcd.print(""); 
  }
  lcd.setCursor(13,1);
  lcd.print(":");
  
  if(waktu.Minute < 10){
     lcd.setCursor(15,1);
  lcd.print(waktu.Minute);
  lcd.setCursor(14,1);
  lcd.print("0");  
  }
   if(waktu.Hour < 10){
    lcd.setCursor(11,1);
  lcd.print("0");  
  lcd.setCursor(12,1);
  lcd.print(waktu.Hour);  
  }
  if(waktu.Minute>=10){
    lcd.setCursor(14,1);
  lcd.print(waktu.Minute);
  }
  
    delay(5000);
    nilaiMaria=1;
  }

// ================================================== //
  if (finger.fingerID == 9 && nilaiEster == 2){
     lcd.setCursor(0,0);
  lcd.print("Lakukan Absensi             ");
    lcd.setCursor(0,1);
  lcd.print("ESOK HARI !!!              ");
 nilaiEster = 2;
    delay(5000);
  }

if (finger.fingerID == 9 && nilaiEster == 1){
    nilaiEster = 2;
    Serial.print("DATA,ESTER PALOLO S.Pd.,");
    Serial.print(" ");
    Serial.print(",");
    Serial.print(waktu.Hour, DEC);
    Serial.print(".");
    Serial.print(waktu.Minute, DEC);
    Serial.print(",");
    Serial.println("SMK ERAN BATU 3 SANGGALANGI");
     lcd.setCursor(0,0);
  lcd.print("ESTER PALOLO      ");
    lcd.setCursor(0,1);
  lcd.print("Jam Keluar  ");
  if(waktu.Hour>=10){
    lcd.setCursor(11,1);
  lcd.print(waktu.Hour);
   lcd.setCursor(10,1);
  lcd.print(""); 
  }
  lcd.setCursor(13,1);
  lcd.print(":");
  
  if(waktu.Minute < 10){
     lcd.setCursor(15,1);
  lcd.print(waktu.Minute);
  lcd.setCursor(14,1);
  lcd.print("0");  
  }
   if(waktu.Hour < 10){
    lcd.setCursor(11,1);
  lcd.print("0");  
  lcd.setCursor(12,1);
  lcd.print(waktu.Hour);  
  }
  if(waktu.Minute>=10){
    lcd.setCursor(14,1);
  lcd.print(waktu.Minute);
  }
  
    delay(5000);
  }

  if (finger.fingerID == 9 && nilaiEster == 0){
   
    Serial.print("DATA,ESTER PALOLO S.Pd,");
    Serial.print(waktu.Hour, DEC);
    Serial.print(".");
    Serial.print(waktu.Minute, DEC);
    Serial.print(",");
    Serial.print(" ");
    Serial.print(",");
    Serial.println("SMK ERAN BATU 3 SANGGALANGI");
     lcd.setCursor(0,0);
  lcd.print("ESTER PALOLO     ");
    lcd.setCursor(0,1);
  lcd.print("Jam Masuk  ");
  if(waktu.Hour>=10){
    lcd.setCursor(12,1);
  lcd.print(waktu.Hour);
   lcd.setCursor(11,1);
  lcd.print(""); 
  }
  lcd.setCursor(13,1);
  lcd.print(":");
  
  if(waktu.Minute < 10){
     lcd.setCursor(15,1);
  lcd.print(waktu.Minute);
  lcd.setCursor(14,1);
  lcd.print("0");  
  }
   if(waktu.Hour < 10){
    lcd.setCursor(11,1);
  lcd.print("0");  
  lcd.setCursor(12,1);
  lcd.print(waktu.Hour);  
  }
  if(waktu.Minute>=10){
    lcd.setCursor(14,1);
  lcd.print(waktu.Minute);
  }
  
    delay(5000);
    nilaiEster=1;
  }

//=================================================//
  if (finger.fingerID == 2 && nilaiSelti == 2){
     lcd.setCursor(0,0);
  lcd.print("Lakukan Absensi             ");
    lcd.setCursor(0,1);
  lcd.print("ESOK HARI !!!              ");
 nilaiSelti = 2;
    delay(5000);
  }

if (finger.fingerID == 2 && nilaiSelti == 1){
    nilaiSelti = 2;
    Serial.print("DATA,SELTIANA RERUNG S.TH,");
    Serial.print(" ");
    Serial.print(",");
    Serial.print(waktu.Hour, DEC);
    Serial.print(".");
    Serial.print(waktu.Minute, DEC);
    Serial.print(",");
    Serial.println("SMK ERAN BATU 3 SANGGALANGI");
     lcd.setCursor(0,0);
  lcd.print("SELTIANA RERUNG        ");
    lcd.setCursor(0,1);
  lcd.print("Jam Keluar  ");
  if(waktu.Hour>=10){
    lcd.setCursor(11,1);
  lcd.print(waktu.Hour);
   lcd.setCursor(10,1);
  lcd.print(""); 
  }
  lcd.setCursor(13,1);
  lcd.print(":");
  
  if(waktu.Minute < 10){
     lcd.setCursor(15,1);
  lcd.print(waktu.Minute);
  lcd.setCursor(14,1);
  lcd.print("0");  
  }
   if(waktu.Hour < 10){
    lcd.setCursor(11,1);
  lcd.print("0");  
  lcd.setCursor(12,1);
  lcd.print(waktu.Hour);  
  }
  if(waktu.Minute>=10){
    lcd.setCursor(14,1);
  lcd.print(waktu.Minute);
  }
  
    delay(5000);
  }

  if (finger.fingerID == 2 && nilaiSelti == 0){
   
    Serial.print("DATA,SELTIANA RERUNG S.TH,");
    Serial.print(waktu.Hour, DEC);
    Serial.print(".");
    Serial.print(waktu.Minute, DEC);
    Serial.print(",");
    Serial.print(" ");
    Serial.print(",");
    Serial.println("SMK ERAN BATU 3 SANGGALANGI");
     lcd.setCursor(0,0);
  lcd.print("SELTIANA RERUNG       ");
    lcd.setCursor(0,1);
  lcd.print("Jam Masuk  ");
  if(waktu.Hour>=10){
    lcd.setCursor(12,1);
  lcd.print(waktu.Hour);
   lcd.setCursor(11,1);
  lcd.print(""); 
  }
  lcd.setCursor(13,1);
  lcd.print(":");
  
  if(waktu.Minute < 10){
     lcd.setCursor(15,1);
  lcd.print(waktu.Minute);
  lcd.setCursor(14,1);
  lcd.print("0");  
  }
   if(waktu.Hour < 10){
    lcd.setCursor(11,1);
  lcd.print("0");  
  lcd.setCursor(12,1);
  lcd.print(waktu.Hour);  
  }
  if(waktu.Minute>=10){
    lcd.setCursor(14,1);
  lcd.print(waktu.Minute);
  }
  
    delay(5000);
    nilaiSelti=1;
  }

//=================================================//

  
  return finger.fingerID;
}


// returns -1 if failed, otherwise returns ID #
int getFingerprintIDez() {
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK)  return -1;

  // found a match!
  Serial.print("Found ID #"); Serial.print(finger.fingerID);
  
  Serial.print(" with confidence of "); Serial.println(finger.confidence);
  return finger.fingerID;

  
}
