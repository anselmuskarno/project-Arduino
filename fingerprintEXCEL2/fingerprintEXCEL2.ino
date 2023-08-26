#include <Wire.h> 
#include "RTClib.h"
RTC_DS1307 rtc;
#include <Adafruit_Fingerprint.h>
#if (defined(__AVR__) || defined(ESP8266)) && !defined(__AVR_ATmega2560__)
SoftwareSerial mySerial(2, 3);
#else
#define mySerial Serial1
#endif
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
int jam = 24;
String parameter;
String parameter2;
//#include "RTClib.h"
//RTC_DS1307 rtc;
char namaHari[7][12] = {"Minggu", "Senin", "Selasa", "Rabu", "Kamis", "Jumat", "Sabtu"};

void setup()
{
  pinMode(5, OUTPUT); 
  Serial.begin(9600);
  Serial.println(F("CLEARDATA"));
  Serial.println(F("LABEL,HARI TANGGAL,NAMA GURU,JAM MASUK,JAM KELUAR,KETERANGAN,")); //ubah nama judul kolom
  Serial.println(F("RESETTIMER"));
  
  rtc.begin();
   lcd.begin();
//   lcd.setCursor(0,0);
//  lcd.print("Loading ...");
//  lcd.setCursor(0,1);
//  lcd.print("Powered By : Rob");
//  lcd.setCursor(0,1);
//  delay(1000);
//  lcd.print("owered By : Robo");
//  lcd.setCursor(0,1);
//  delay(500);
//  lcd.print("wered By : Robot");
//  lcd.setCursor(0,1);
//  delay(500);
//  lcd.print("ered By : Roboti");
//  lcd.setCursor(0,1);
//  delay(500);
//  lcd.print("red By : Robotik");
//  lcd.setCursor(0,1);
//  delay(500);
//  lcd.print("ed By : Robotika");
//   lcd.setCursor(0,1);
//   delay(500);
//  lcd.print("d By : Robotika ");
//   lcd.setCursor(0,1);
//   delay(500);
//  lcd.print(" By : Robotika E");
//  lcd.setCursor(0,1);
//  delay(500);
//  lcd.print(" y : Robotika Er");
//  lcd.setCursor(0,1);
//  delay(500);
//  lcd.print("  : Robotika Erb");
//  lcd.setCursor(0,1);
//  delay(500);
//  lcd.print(" : Robotika Erba");
//  lcd.setCursor(0,1);
//  delay(500);
//  lcd.print("Robotika Erba    ");
//  delay(1500);
  while (!Serial);  // For Yun/Leo/Micro/Zero/...
  delay(100);
  Serial.println(F("\n\nAdafruit finger detect test"));

  // set the data rate for the sensor serial port
  finger.begin(57600);
  delay(5);
  finger.getParameters();

  finger.getTemplateCount();

}
int nilai = 0;
int nilaiPabalik = 0;
int nilaiMarthen = 0;
int nilaiEster = 0;
int nilaiSelti = 0;
int nilaiMaya = 0;
int nilaiHengki = 0;
int nilaiGerar = 0;
int nilaiHenny = 0;
int nilaiMaria = 0;
int nilaiYulius = 0;
int nilaiJoice = 0;
int nilaiMelda = 0;

void loop()                     // run over and over again
{
  getFingerprintID();
  delay(50);            //don't ned to run this at full speed.
}

uint8_t getFingerprintID() {
   DateTime now;
  now = rtc.now();
  lcd.setCursor(0,0);
  lcd.print("Tempelkan               ");
  lcd.setCursor(0,1);
  lcd.print("Jari Anda      ");
  if(now.hour() >=10){
    lcd.setCursor(11,1);
  lcd.print(now.hour());
//   lcd.setCursor(11,1);
//  lcd.print(""); 
  }
  lcd.setCursor(13,1);
  lcd.print(":");
  if(now.second() < 10){
  lcd.setCursor(15,0);
  lcd.print(" ");  
  }
  if(now.minute() < 10){
     lcd.setCursor(15,1);
  lcd.print(now.minute());
  lcd.setCursor(14,1);
  lcd.print("0");  
  }
   if(now.hour() < 10){
    lcd.setCursor(11,1);
  lcd.print("0");  
  lcd.setCursor(12,1);
  lcd.print(now.hour());  
  }
  if(now.minute()>=10){
    lcd.setCursor(14,1);
  lcd.print(now.minute());
  }
  
  lcd.setCursor(14,0);
  lcd.print(now.second());
  uint8_t p = finger.getImage();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println(F("Image taken"));
      break;
    case FINGERPRINT_NOFINGER:
      Serial.println(F("No finger detected"));
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println(F("Communication error"));
      return p;
    case FINGERPRINT_IMAGEFAIL:
      Serial.println(F("Imaging error"));
      return p;
    default:
      Serial.println(F("Unknown error"));
      return p;
  }

  // OK success!

  p = finger.image2Tz();
 

  // OK converted!
  p = finger.fingerSearch();
  if (p == FINGERPRINT_OK) {
    Serial.println(F("Found a print match!"));
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println(F("Communication error"));
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
    Serial.println(F("Unknown error"));
    return p;
  }

  // found a match!
  Serial.print(F("Found ID #")); Serial.print(finger.fingerID);
  Serial.print(F(" with confidence of ")); Serial.println(finger.confidence);

// ==========================================================//
if (finger.fingerID == 20){
  parameter = namaHari[now.dayOfTheWeek()];
  if(nilai == 2){
    parameter2 = namaHari[now.dayOfTheWeek()];
    digitalWrite(5, HIGH);
    lcd.setCursor(0,0);
    lcd.print("Lakukan Absensi             ");
    lcd.setCursor(0,1);
    lcd.print("ESOK HARI !!!              ");
    if(parameter != parameter2){
      Serial.println(F("Hari yang baru"));
    nilai = 0;
    }
     if(parameter == parameter2){
      Serial.println(F("Eitss... tidak boleh"));
    nilai = 2;
    }
    delay(5000);
    digitalWrite(5, LOW);  
  } 
  if (nilai == 1){
    digitalWrite(7, HIGH);
    nilai = 2;
    Serial.print(F("DATA,"));
    Serial.print(namaHari[now.dayOfTheWeek()]);  
    Serial.print('.');    
    Serial.print(now.day(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.year(), DEC);
    Serial.print(F(" "));
    Serial.print(",");
    Serial.print("ANSELMUS KARNO S.KOM,");
    Serial.print(F(" "));
    Serial.print(",");
    Serial.print(now.hour(), DEC);
    Serial.print(F("."));
    Serial.print(now.minute(), DEC);
    Serial.print(",");
    Serial.println(F("SMK ERAN BATU 3 SANGGALANGI"));
    lcd.setCursor(0,0);
    lcd.print("ANSELMUS KARNO   ");  
    lcd.setCursor(0,1);
    lcd.print("Jam Keluar  ");
    if(now.hour() >=10){
      lcd.setCursor(11,1);
      lcd.print(now.hour());
      lcd.setCursor(10,1);
      lcd.print(""); 
    }
    lcd.setCursor(13,1);
    lcd.print(":");
  
    if(now.minute() < 10){
      lcd.setCursor(15,1);
      lcd.print(now.minute());
      lcd.setCursor(14,1);
      lcd.print("0");  
    }
    if(now.hour() < 10){
      lcd.setCursor(11,1);
      lcd.print("0");  
      lcd.setCursor(12,1);
      lcd.print(now.hour());  
    }
    if(now.minute()>=10){
      lcd.setCursor(14,1);
      lcd.print(now.minute());
    }
    delay(5000);
    digitalWrite(7, LOW);
  } 
  if (nilai == 0){
    digitalWrite(7, HIGH);
    Serial.print(F("DATA,"));
    Serial.print(namaHari[now.dayOfTheWeek()]);  
    Serial.print('.');    
    Serial.print(now.day(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.year(), DEC);
    Serial.print(F(" "));
    
    Serial.print(",");
    Serial.print("ANSELMUS KARNO S.KOM,");
    Serial.print(now.hour(), DEC);
    Serial.print(F("."));
    Serial.print(now.minute(), DEC);
    Serial.print(",");
    Serial.print(F(" "));
    Serial.print(",");
    Serial.println(F("SMK ERAN BATU 3 SANGGALANGI"));
    lcd.setCursor(0,0);
    lcd.print("ANSELMUS KARNO   ");
    lcd.setCursor(0,1);
    lcd.print("Jam Masuk  ");
    if(now.hour() >=10){
      lcd.setCursor(11,1);
      lcd.print(now.hour());
      lcd.setCursor(10,1);
      lcd.print(""); 
    }
    lcd.setCursor(13,1);
    lcd.print(":");  
    if(now.minute() < 10){
      lcd.setCursor(15,1);
      lcd.print(now.minute());
      lcd.setCursor(14,1);
      lcd.print("0");  
     }
    if(now.hour() < 10){
      lcd.setCursor(11,1);
      lcd.print("0");  
      lcd.setCursor(12,1);
      lcd.print(now.hour());  
    }
    if(now.minute()>=10){
      lcd.setCursor(14,1);
      lcd.print(now.minute());
    }
    delay(5000);
    nilai=1;
    digitalWrite(7, LOW); 
  }
  
}

// ==========================================================//
if (finger.fingerID == 1){
  
  if(nilaiSelti == 2){
    digitalWrite(5, HIGH);
    lcd.setCursor(0,0);
    lcd.print("Lakukan Absensi             ");
    lcd.setCursor(0,1);
    lcd.print("ESOK HARI !!!              ");
    nilaiSelti = 2;
    delay(5000);
    digitalWrite(5, LOW);  
  } 
  if (nilaiSelti == 1){
    digitalWrite(7, HIGH);
    nilaiSelti = 2;
    Serial.print(F("DATA,SELTIANA RERUNG S.Th,"));
    Serial.print(F(" "));
    Serial.print(",");
    Serial.print(now.hour(), DEC);
    Serial.print(F("."));
    Serial.print(now.minute(), DEC);
    Serial.print(",");
    Serial.println(F("SMK ERAN BATU 3 SANGGALANGI"));
    lcd.setCursor(0,0);
    lcd.print("SELTIANA RERUNG   ");  
    lcd.setCursor(0,1);
    lcd.print("Jam Keluar  ");
    if(now.hour() >=10){
      lcd.setCursor(11,1);
      lcd.print(now.hour());
      lcd.setCursor(10,1);
      lcd.print(""); 
    }
    lcd.setCursor(13,1);
    lcd.print(":");
  
    if(now.minute() < 10){
      lcd.setCursor(15,1);
      lcd.print(now.minute());
      lcd.setCursor(14,1);
      lcd.print("0");  
    }
    if(now.hour() < 10){
      lcd.setCursor(11,1);
      lcd.print("0");  
      lcd.setCursor(12,1);
      lcd.print(now.hour());  
    }
    if(now.minute()>=10){
      lcd.setCursor(14,1);
      lcd.print(now.minute());
    }
    delay(5000);
    digitalWrite(7, LOW);
  } 
  if (nilaiSelti == 0){
    digitalWrite(7, HIGH);
    Serial.print(F("DATA,SELTIANA RERUNG S.Th,"));
    Serial.print(now.hour(), DEC);
    Serial.print(F("."));
    Serial.print(now.minute(), DEC);
    Serial.print(",");
    Serial.print(F(" "));
    Serial.print(",");
    Serial.println(F("SMK ERAN BATU 3 SANGGALANGI"));
    lcd.setCursor(0,0);
    lcd.print("SELTIANA RERUNG   ");
    lcd.setCursor(0,1);
    lcd.print("Jam Masuk  ");
    if(now.hour() >=10){
      lcd.setCursor(12,1);
      lcd.print(now.hour());
      lcd.setCursor(11,1);
      lcd.print(""); 
    }
    lcd.setCursor(13,1);
    lcd.print(":");  
    if(now.minute() < 10){
      lcd.setCursor(15,1);
      lcd.print(now.minute());
      lcd.setCursor(14,1);
      lcd.print("0");  
     }
    if(now.hour() < 10){
      lcd.setCursor(11,1);
      lcd.print("0");  
      lcd.setCursor(12,1);
      lcd.print(now.hour());  
    }
    if(now.minute()>=10){
      lcd.setCursor(14,1);
      lcd.print(now.minute());
    }
    delay(5000);
    nilaiSelti=1;
    digitalWrite(7, LOW); 
  }
  
}

// ==========================================================//
if (finger.fingerID == 2){
  
  if(nilaiPabalik == 2){
    digitalWrite(5, HIGH);
    lcd.setCursor(0,0);
    lcd.print("Lakukan Absensi             ");
    lcd.setCursor(0,1);
    lcd.print("ESOK HARI !!!              ");
    nilaiPabalik = 2;
    delay(5000);
    digitalWrite(5, LOW);  
  } 
  if (nilaiPabalik == 1){
    digitalWrite(7, HIGH);
    nilaiPabalik = 2;
    Serial.print(F("DATA,DANIEL PABALIK,"));
    Serial.print(F(" "));
    Serial.print(",");
    Serial.print(now.hour(), DEC);
    Serial.print(F("."));
    Serial.print(now.minute(), DEC);
    Serial.print(",");
    Serial.println(F("SMK ERAN BATU 3 SANGGALANGI"));
    lcd.setCursor(0,0);
    lcd.print("DANIEL PABALIK   ");  
    lcd.setCursor(0,1);
    lcd.print("Jam Keluar  ");
    if(now.hour() >=10){
      lcd.setCursor(11,1);
      lcd.print(now.hour());
      lcd.setCursor(10,1);
      lcd.print(""); 
    }
    lcd.setCursor(13,1);
    lcd.print(":");
  
    if(now.minute() < 10){
      lcd.setCursor(15,1);
      lcd.print(now.minute());
      lcd.setCursor(14,1);
      lcd.print("0");  
    }
    if(now.hour() < 10){
      lcd.setCursor(11,1);
      lcd.print("0");  
      lcd.setCursor(12,1);
      lcd.print(now.hour());  
    }
    if(now.minute()>=10){
      lcd.setCursor(14,1);
      lcd.print(now.minute());
    }
    delay(5000);
    digitalWrite(7, LOW);
  } 
  if (nilaiPabalik == 0){
    digitalWrite(7, HIGH);
    Serial.print(F("DATA,DANIEL PABALIK,"));
    Serial.print(now.hour(), DEC);
    Serial.print(F("."));
    Serial.print(now.minute(), DEC);
    Serial.print(",");
    Serial.print(F(" "));
    Serial.print(",");
    Serial.println(F("SMK ERAN BATU 3 SANGGALANGI"));
    lcd.setCursor(0,0);
    lcd.print("DANIEL PABALIK   ");
    lcd.setCursor(0,1);
    lcd.print("Jam Masuk  ");
    if(now.hour() >=10){
      lcd.setCursor(12,1);
      lcd.print(now.hour());
      lcd.setCursor(11,1);
      lcd.print(""); 
    }
    lcd.setCursor(13,1);
    lcd.print(":");  
    if(now.minute() < 10){
      lcd.setCursor(15,1);
      lcd.print(now.minute());
      lcd.setCursor(14,1);
      lcd.print("0");  
     }
    if(now.hour() < 10){
      lcd.setCursor(11,1);
      lcd.print("0");  
      lcd.setCursor(12,1);
      lcd.print(now.hour());  
    }
    if(now.minute()>=10){
      lcd.setCursor(14,1);
      lcd.print(now.minute());
    }
    delay(5000);
    nilaiPabalik=1;
    digitalWrite(7, LOW); 
  }
  
}

// ==========================================================//
if (finger.fingerID == 3){
  
  if(nilaiMarthen == 2){
    digitalWrite(5, HIGH);
    lcd.setCursor(0,0);
    lcd.print("Lakukan Absensi             ");
    lcd.setCursor(0,1);
    lcd.print("ESOK HARI !!!              ");
    nilai = 2;
    delay(5000);
    digitalWrite(5, LOW);  
  } 
  if (nilaiMarthen == 1){
    digitalWrite(7, HIGH);
    nilaiMarthen = 2;
    Serial.print(F("DATA,MARTHEN BUA,"));
    Serial.print(F(" "));
    Serial.print(",");
    Serial.print(now.hour(), DEC);
    Serial.print(F("."));
    Serial.print(now.minute(), DEC);
    Serial.print(",");
    Serial.println(F("SMK ERAN BATU 3 SANGGALANGI"));
    lcd.setCursor(0,0);
    lcd.print("MARTHEN BUA          ");  
    lcd.setCursor(0,1);
    lcd.print("Jam Keluar  ");
    if(now.hour() >=10){
      lcd.setCursor(11,1);
      lcd.print(now.hour());
      lcd.setCursor(10,1);
      lcd.print(""); 
    }
    lcd.setCursor(13,1);
    lcd.print(":");
  
    if(now.minute() < 10){
      lcd.setCursor(15,1);
      lcd.print(now.minute());
      lcd.setCursor(14,1);
      lcd.print("0");  
    }
    if(now.hour() < 10){
      lcd.setCursor(11,1);
      lcd.print("0");  
      lcd.setCursor(12,1);
      lcd.print(now.hour());  
    }
    if(now.minute()>=10){
      lcd.setCursor(14,1);
      lcd.print(now.minute());
    }
    delay(5000);
    digitalWrite(7, LOW);
  } 
  if (nilaiMarthen == 0){
    digitalWrite(7, HIGH);
    Serial.print(F("DATA,MARTHEN BUA,"));
    Serial.print(now.hour(), DEC);
    Serial.print(F("."));
    Serial.print(now.minute(), DEC);
    Serial.print(",");
    Serial.print(F(" "));
    Serial.print(",");
    Serial.println(F("SMK ERAN BATU 3 SANGGALANGI"));
    lcd.setCursor(0,0);
    lcd.print("MARTHEN BUA         ");
    lcd.setCursor(0,1);
    lcd.print("Jam Masuk  ");
    if(now.hour() >=10){
      lcd.setCursor(12,1);
      lcd.print(now.hour());
      lcd.setCursor(11,1);
      lcd.print(""); 
    }
    lcd.setCursor(13,1);
    lcd.print(":");  
    if(now.minute() < 10){
      lcd.setCursor(15,1);
      lcd.print(now.minute());
      lcd.setCursor(14,1);
      lcd.print("0");  
     }
    if(now.hour() < 10){
      lcd.setCursor(11,1);
      lcd.print("0");  
      lcd.setCursor(12,1);
      lcd.print(now.hour());  
    }
    if(now.minute()>=10){
      lcd.setCursor(14,1);
      lcd.print(now.minute());
    }
    delay(5000);
    nilaiMarthen=1;
    digitalWrite(7, LOW); 
  }
  
}

// ==========================================================//
if (finger.fingerID == 4){
  
  if(nilaiMaya == 2){
    digitalWrite(5, HIGH);
    lcd.setCursor(0,0);
    lcd.print("Lakukan Absensi             ");
    lcd.setCursor(0,1);
    lcd.print("ESOK HARI !!!              ");
    nilaiMaya = 2;
    delay(5000);
    digitalWrite(5, LOW);  
  } 
  if (nilaiMaya == 1){
    digitalWrite(7, HIGH);
    nilaiMaya = 2;
    Serial.print(F("DATA,MAYA A. T. S.Pd,"));
    Serial.print(F(" "));
    Serial.print(",");
    Serial.print(now.hour(), DEC);
    Serial.print(F("."));
    Serial.print(now.minute(), DEC);
    Serial.print(",");
    Serial.println(F("SMK ERAN BATU 3 SANGGALANGI"));
    lcd.setCursor(0,0);
    lcd.print("MAYA A. T.        ");  
    lcd.setCursor(0,1);
    lcd.print("Jam Keluar  ");
    if(now.hour() >=10){
      lcd.setCursor(11,1);
      lcd.print(now.hour());
      lcd.setCursor(10,1);
      lcd.print(""); 
    }
    lcd.setCursor(13,1);
    lcd.print(":");
  
    if(now.minute() < 10){
      lcd.setCursor(15,1);
      lcd.print(now.minute());
      lcd.setCursor(14,1);
      lcd.print("0");  
    }
    if(now.hour() < 10){
      lcd.setCursor(11,1);
      lcd.print("0");  
      lcd.setCursor(12,1);
      lcd.print(now.hour());  
    }
    if(now.minute()>=10){
      lcd.setCursor(14,1);
      lcd.print(now.minute());
    }
    delay(5000);
    digitalWrite(7, LOW);
  } 
  if (nilaiMaya == 0){
    digitalWrite(7, HIGH);
    Serial.print(F("DATA,MAYA A. T. S.Pd,"));
    Serial.print(now.hour(), DEC);
    Serial.print(F("."));
    Serial.print(now.minute(), DEC);
    Serial.print(",");
    Serial.print(F(" "));
    Serial.print(",");
    Serial.println(F("SMK ERAN BATU 3 SANGGALANGI"));
    lcd.setCursor(0,0);
    lcd.print("MAYA A. T.      ");
    lcd.setCursor(0,1);
    lcd.print("Jam Masuk  ");
    if(now.hour() >=10){
      lcd.setCursor(12,1);
      lcd.print(now.hour());
      lcd.setCursor(11,1);
      lcd.print(""); 
    }
    lcd.setCursor(13,1);
    lcd.print(":");  
    if(now.minute() < 10){
      lcd.setCursor(15,1);
      lcd.print(now.minute());
      lcd.setCursor(14,1);
      lcd.print("0");  
     }
    if(now.hour() < 10){
      lcd.setCursor(11,1);
      lcd.print("0");  
      lcd.setCursor(12,1);
      lcd.print(now.hour());  
    }
    if(now.minute()>=10){
      lcd.setCursor(14,1);
      lcd.print(now.minute());
    }
    delay(5000);
    nilaiMaya=1;
    digitalWrite(7, LOW); 
  }
  
}

// ==========================================================//
if (finger.fingerID == 5){
  
  if(nilaiHengki == 2){
    digitalWrite(5, HIGH);
    lcd.setCursor(0,0);
    lcd.print("Lakukan Absensi             ");
    lcd.setCursor(0,1);
    lcd.print("ESOK HARI !!!              ");
    nilaiHengki = 2;
    delay(5000);
    digitalWrite(5, LOW);  
  } 
  if (nilaiHengki == 1){
    digitalWrite(7, HIGH);
    nilaiHengki = 2;
    Serial.print(F("DATA,HENGKI SULLE S.Pd,"));
    Serial.print(F(" "));
    Serial.print(",");
    Serial.print(now.hour(), DEC);
    Serial.print(F("."));
    Serial.print(now.minute(), DEC);
    Serial.print(",");
    Serial.println(F("SMK ERAN BATU 3 SANGGALANGI"));
    lcd.setCursor(0,0);
    lcd.print("HENGKI SULLE      ");  
    lcd.setCursor(0,1);
    lcd.print("Jam Keluar  ");
    if(now.hour() >=10){
      lcd.setCursor(11,1);
      lcd.print(now.hour());
      lcd.setCursor(10,1);
      lcd.print(""); 
    }
    lcd.setCursor(13,1);
    lcd.print(":");
  
    if(now.minute() < 10){
      lcd.setCursor(15,1);
      lcd.print(now.minute());
      lcd.setCursor(14,1);
      lcd.print("0");  
    }
    if(now.hour() < 10){
      lcd.setCursor(11,1);
      lcd.print("0");  
      lcd.setCursor(12,1);
      lcd.print(now.hour());  
    }
    if(now.minute()>=10){
      lcd.setCursor(14,1);
      lcd.print(now.minute());
    }
    delay(5000);
    digitalWrite(7, LOW);
  } 
  if (nilaiHengki == 0){
    digitalWrite(7, HIGH);
    Serial.print(F("DATA,HENGKI SULLE S. Pd,"));
    Serial.print(now.hour(), DEC);
    Serial.print(F("."));
    Serial.print(now.minute(), DEC);
    Serial.print(",");
    Serial.print(F(" "));
    Serial.print(",");
    Serial.println(F("SMK ERAN BATU 3 SANGGALANGI"));
    lcd.setCursor(0,0);
    lcd.print("HENGKI SULLE       ");
    lcd.setCursor(0,1);
    lcd.print("Jam Masuk  ");
    if(now.hour() >=10){
      lcd.setCursor(12,1);
      lcd.print(now.hour());
      lcd.setCursor(11,1);
      lcd.print(""); 
    }
    lcd.setCursor(13,1);
    lcd.print(":");  
    if(now.minute() < 10){
      lcd.setCursor(15,1);
      lcd.print(now.minute());
      lcd.setCursor(14,1);
      lcd.print("0");  
     }
    if(now.hour() < 10){
      lcd.setCursor(11,1);
      lcd.print("0");  
      lcd.setCursor(12,1);
      lcd.print(now.hour());  
    }
    if(now.minute()>=10){
      lcd.setCursor(14,1);
      lcd.print(now.minute());
    }
    delay(5000);
    nilaiHengki=1;
    digitalWrite(7, LOW); 
  }
  
}

// ==========================================================//
if (finger.fingerID == 6){
  
  if(nilaiGerar == 2){
    digitalWrite(5, HIGH);
    lcd.setCursor(0,0);
    lcd.print("Lakukan Absensi             ");
    lcd.setCursor(0,1);
    lcd.print("ESOK HARI !!!              ");
    nilaiGerar = 2;
    delay(5000);
    digitalWrite(5, LOW);  
  } 
  if (nilaiGerar == 1){
    digitalWrite(7, HIGH);
    nilaiGerar = 2;
    Serial.print(F("DATA,GERARDUS KAMBIRA S. Pd.,"));
    Serial.print(F(" "));
    Serial.print(",");
    Serial.print(now.hour(), DEC);
    Serial.print(F("."));
    Serial.print(now.minute(), DEC);
    Serial.print(",");
    Serial.println(F("SMK ERAN BATU 3 SANGGALANGI"));
    lcd.setCursor(0,0);
    lcd.print("GERARDUS KAMBIRA     ");  
    lcd.setCursor(0,1);
    lcd.print("Jam Keluar  ");
    if(now.hour() >=10){
      lcd.setCursor(11,1);
      lcd.print(now.hour());
      lcd.setCursor(10,1);
      lcd.print(""); 
    }
    lcd.setCursor(13,1);
    lcd.print(":");
  
    if(now.minute() < 10){
      lcd.setCursor(15,1);
      lcd.print(now.minute());
      lcd.setCursor(14,1);
      lcd.print("0");  
    }
    if(now.hour() < 10){
      lcd.setCursor(11,1);
      lcd.print("0");  
      lcd.setCursor(12,1);
      lcd.print(now.hour());  
    }
    if(now.minute()>=10){
      lcd.setCursor(14,1);
      lcd.print(now.minute());
    }
    delay(5000);
    digitalWrite(7, LOW);
  } 
  if (nilaiGerar == 0){
    digitalWrite(7, HIGH);
    Serial.print(F("DATA,GERARDUS KAMBIRA S. Pd.,"));
    Serial.print(now.hour(), DEC);
    Serial.print(F("."));
    Serial.print(now.minute(), DEC);
    Serial.print(",");
    Serial.print(F(" "));
    Serial.print(",");
    Serial.println(F("SMK ERAN BATU 3 SANGGALANGI"));
    lcd.setCursor(0,0);
    lcd.print("GERARDUS KAMBIRA     ");
    lcd.setCursor(0,1);
    lcd.print("Jam Masuk  ");
    if(now.hour() >=10){
      lcd.setCursor(12,1);
      lcd.print(now.hour());
      lcd.setCursor(11,1);
      lcd.print(""); 
    }
    lcd.setCursor(13,1);
    lcd.print(":");  
    if(now.minute() < 10){
      lcd.setCursor(15,1);
      lcd.print(now.minute());
      lcd.setCursor(14,1);
      lcd.print("0");  
     }
    if(now.hour() < 10){
      lcd.setCursor(11,1);
      lcd.print("0");  
      lcd.setCursor(12,1);
      lcd.print(now.hour());  
    }
    if(now.minute()>=10){
      lcd.setCursor(14,1);
      lcd.print(now.minute());
    }
    delay(5000);
    nilaiGerar=1;
    digitalWrite(7, LOW); 
  }
  
}

// ==========================================================//
if (finger.fingerID == 7){
  
  if(nilai == 2){
    digitalWrite(5, HIGH);
    lcd.setCursor(0,0);
    lcd.print("Lakukan Absensi             ");
    lcd.setCursor(0,1);
    lcd.print("ESOK HARI !!!              ");
    nilai = 2;
    delay(5000);
    digitalWrite(5, LOW);  
  } 
  if (nilai == 1){
    digitalWrite(7, HIGH);
    nilai = 2;
    Serial.print(F("DATA,ESTER PALOLO S. Pd.,"));
    Serial.print(F(" "));
    Serial.print(",");
    Serial.print(now.hour(), DEC);
    Serial.print(F("."));
    Serial.print(now.minute(), DEC);
    Serial.print(",");
    Serial.println(F("SMK ERAN BATU 3 SANGGALANGI"));
    lcd.setCursor(0,0);
    lcd.print("ESTER PALOLO     ");  
    lcd.setCursor(0,1);
    lcd.print("Jam Keluar  ");
    if(now.hour() >=10){
      lcd.setCursor(11,1);
      lcd.print(now.hour());
      lcd.setCursor(10,1);
      lcd.print(""); 
    }
    lcd.setCursor(13,1);
    lcd.print(":");
  
    if(now.minute() < 10){
      lcd.setCursor(15,1);
      lcd.print(now.minute());
      lcd.setCursor(14,1);
      lcd.print("0");  
    }
    if(now.hour() < 10){
      lcd.setCursor(11,1);
      lcd.print("0");  
      lcd.setCursor(12,1);
      lcd.print(now.hour());  
    }
    if(now.minute()>=10){
      lcd.setCursor(14,1);
      lcd.print(now.minute());
    }
    delay(5000);
    digitalWrite(7, LOW);
  } 
  if (nilai == 0){
    digitalWrite(7, HIGH);
    Serial.print(F("DATA,ESTER PALOLO S. Pd.,"));
    Serial.print(now.hour(), DEC);
    Serial.print(F("."));
    Serial.print(now.minute(), DEC);
    Serial.print(",");
    Serial.print(F(" "));
    Serial.print(",");
    Serial.println(F("SMK ERAN BATU 3 SANGGALANGI"));
    lcd.setCursor(0,0);
    lcd.print("ESTER PALOLO     ");
    lcd.setCursor(0,1);
    lcd.print("Jam Masuk  ");
    if(now.hour() >=10){
      lcd.setCursor(12,1);
      lcd.print(now.hour());
      lcd.setCursor(11,1);
      lcd.print(""); 
    }
    lcd.setCursor(13,1);
    lcd.print(":");  
    if(now.minute() < 10){
      lcd.setCursor(15,1);
      lcd.print(now.minute());
      lcd.setCursor(14,1);
      lcd.print("0");  
     }
    if(now.hour() < 10){
      lcd.setCursor(11,1);
      lcd.print("0");  
      lcd.setCursor(12,1);
      lcd.print(now.hour());  
    }
    if(now.minute()>=10){
      lcd.setCursor(14,1);
      lcd.print(now.minute());
    }
    delay(5000);
    nilai=1;
    digitalWrite(7, LOW); 
  }
  
}

// ==========================================================//
if (finger.fingerID == 8){
  
  if(nilai == 2){
    digitalWrite(5, HIGH);
    lcd.setCursor(0,0);
    lcd.print("Lakukan Absensi             ");
    lcd.setCursor(0,1);
    lcd.print("ESOK HARI !!!              ");
    nilai = 2;
    delay(5000);
    digitalWrite(5, LOW);  
  } 
  if (nilai == 1){
    digitalWrite(7, HIGH);
    nilai = 2;
    Serial.print(F("DATA,ANDI HENNY M. S.Pd.,"));
    Serial.print(F(" "));
    Serial.print(",");
    Serial.print(now.hour(), DEC);
    Serial.print(F("."));
    Serial.print(now.minute(), DEC);
    Serial.print(",");
    Serial.println(F("SMK ERAN BATU 3 SANGGALANGI"));
    lcd.setCursor(0,0);
    lcd.print("ANDI HENNY M.   ");  
    lcd.setCursor(0,1);
    lcd.print("Jam Keluar  ");
    if(now.hour() >=10){
      lcd.setCursor(11,1);
      lcd.print(now.hour());
      lcd.setCursor(10,1);
      lcd.print(""); 
    }
    lcd.setCursor(13,1);
    lcd.print(":");
  
    if(now.minute() < 10){
      lcd.setCursor(15,1);
      lcd.print(now.minute());
      lcd.setCursor(14,1);
      lcd.print("0");  
    }
    if(now.hour() < 10){
      lcd.setCursor(11,1);
      lcd.print("0");  
      lcd.setCursor(12,1);
      lcd.print(now.hour());  
    }
    if(now.minute()>=10){
      lcd.setCursor(14,1);
      lcd.print(now.minute());
    }
    delay(5000);
    digitalWrite(7, LOW);
  } 
  if (nilai == 0){
    digitalWrite(7, HIGH);
    Serial.print(F("DATA,ANDI HENNY M. S. Pd.,"));
    Serial.print(now.hour(), DEC);
    Serial.print(F("."));
    Serial.print(now.minute(), DEC);
    Serial.print(",");
    Serial.print(F(" "));
    Serial.print(",");
    Serial.println(F("SMK ERAN BATU 3 SANGGALANGI"));
    lcd.setCursor(0,0);
    lcd.print("ANDI HENNY M.     ");
    lcd.setCursor(0,1);
    lcd.print("Jam Masuk  ");
    if(now.hour() >=10){
      lcd.setCursor(12,1);
      lcd.print(now.hour());
      lcd.setCursor(11,1);
      lcd.print(""); 
    }
    lcd.setCursor(13,1);
    lcd.print(":");  
    if(now.minute() < 10){
      lcd.setCursor(15,1);
      lcd.print(now.minute());
      lcd.setCursor(14,1);
      lcd.print("0");  
     }
    if(now.hour() < 10){
      lcd.setCursor(11,1);
      lcd.print("0");  
      lcd.setCursor(12,1);
      lcd.print(now.hour());  
    }
    if(now.minute()>=10){
      lcd.setCursor(14,1);
      lcd.print(now.minute());
    }
    delay(5000);
    nilai=1;
    digitalWrite(7, LOW); 
  }
  
}

// ==========================================================//
if (finger.fingerID == 9){
  
  if(nilai == 2){
    digitalWrite(5, HIGH);
    lcd.setCursor(0,0);
    lcd.print("Lakukan Absensi             ");
    lcd.setCursor(0,1);
    lcd.print("ESOK HARI !!!              ");
    nilai = 2;
    delay(5000);
    digitalWrite(5, LOW);  
  } 
  if (nilai == 1){
    digitalWrite(7, HIGH);
    nilai = 2;
    Serial.print(F("DATA,MARIA LIMBONG BUA S.PdK.,"));
    Serial.print(F(" "));
    Serial.print(",");
    Serial.print(now.hour(), DEC);
    Serial.print(F("."));
    Serial.print(now.minute(), DEC);
    Serial.print(",");
    Serial.println(F("SMK ERAN BATU 3 SANGGALANGI"));
    lcd.setCursor(0,0);
    lcd.print("MARIA LIMBONG B.   ");  
    lcd.setCursor(0,1);
    lcd.print("Jam Keluar  ");
    if(now.hour() >=10){
      lcd.setCursor(11,1);
      lcd.print(now.hour());
      lcd.setCursor(10,1);
      lcd.print(""); 
    }
    lcd.setCursor(13,1);
    lcd.print(":");
  
    if(now.minute() < 10){
      lcd.setCursor(15,1);
      lcd.print(now.minute());
      lcd.setCursor(14,1);
      lcd.print("0");  
    }
    if(now.hour() < 10){
      lcd.setCursor(11,1);
      lcd.print("0");  
      lcd.setCursor(12,1);
      lcd.print(now.hour());  
    }
    if(now.minute()>=10){
      lcd.setCursor(14,1);
      lcd.print(now.minute());
    }
    delay(5000);
    digitalWrite(7, LOW);
  } 
  if (nilai == 0){
    digitalWrite(7, HIGH);
    Serial.print(F("DATA,MARIA LIMBONG BUA S.PdK,"));
    Serial.print(now.hour(), DEC);
    Serial.print(F("."));
    Serial.print(now.minute(), DEC);
    Serial.print(",");
    Serial.print(F(" "));
    Serial.print(",");
    Serial.println(F("SMK ERAN BATU 3 SANGGALANGI"));
    lcd.setCursor(0,0);
    lcd.print("MARIA LIMBONG B.   ");
    lcd.setCursor(0,1);
    lcd.print("Jam Masuk  ");
    if(now.hour() >=10){
      lcd.setCursor(12,1);
      lcd.print(now.hour());
      lcd.setCursor(11,1);
      lcd.print(""); 
    }
    lcd.setCursor(13,1);
    lcd.print(":");  
    if(now.minute() < 10){
      lcd.setCursor(15,1);
      lcd.print(now.minute());
      lcd.setCursor(14,1);
      lcd.print("0");  
     }
    if(now.hour() < 10){
      lcd.setCursor(11,1);
      lcd.print("0");  
      lcd.setCursor(12,1);
      lcd.print(now.hour());  
    }
    if(now.minute()>=10){
      lcd.setCursor(14,1);
      lcd.print(now.minute());
    }
    delay(5000);
    nilai=1;
    digitalWrite(7, LOW); 
  }
  
}

// ==========================================================//
if (finger.fingerID == 10){
  
  if(nilai == 2){
    digitalWrite(5, HIGH);
    lcd.setCursor(0,0);
    lcd.print("Lakukan Absensi             ");
    lcd.setCursor(0,1);
    lcd.print("ESOK HARI !!!              ");
    nilai = 2;
    delay(5000);
    digitalWrite(5, LOW);  
  } 
  if (nilai == 1){
    digitalWrite(7, HIGH);
    nilai = 2;
    Serial.print(F("DATA,YULIUS S. Th.,"));
    Serial.print(F(" "));
    Serial.print(",");
    Serial.print(now.hour(), DEC);
    Serial.print(F("."));
    Serial.print(now.minute(), DEC);
    Serial.print(",");
    Serial.println(F("SMK ERAN BATU 3 SANGGALANGI"));
    lcd.setCursor(0,0);
    lcd.print("YULIUS         ");  
    lcd.setCursor(0,1);
    lcd.print("Jam Keluar  ");
    if(now.hour() >=10){
      lcd.setCursor(11,1);
      lcd.print(now.hour());
      lcd.setCursor(10,1);
      lcd.print(""); 
    }
    lcd.setCursor(13,1);
    lcd.print(":");
  
    if(now.minute() < 10){
      lcd.setCursor(15,1);
      lcd.print(now.minute());
      lcd.setCursor(14,1);
      lcd.print("0");  
    }
    if(now.hour() < 10){
      lcd.setCursor(11,1);
      lcd.print("0");  
      lcd.setCursor(12,1);
      lcd.print(now.hour());  
    }
    if(now.minute()>=10){
      lcd.setCursor(14,1);
      lcd.print(now.minute());
    }
    delay(5000);
    digitalWrite(7, LOW);
  } 
  if (nilai == 0){
    digitalWrite(7, HIGH);
    Serial.print(F("DATA,YULIUS S.Th.,"));
    Serial.print(now.hour(), DEC);
    Serial.print(F("."));
    Serial.print(now.minute(), DEC);
    Serial.print(",");
    Serial.print(F(" "));
    Serial.print(",");
    Serial.println(F("SMK ERAN BATU 3 SANGGALANGI"));
    lcd.setCursor(0,0);
    lcd.print("YULIUS             ");
    lcd.setCursor(0,1);
    lcd.print("Jam Masuk  ");
    if(now.hour() >=10){
      lcd.setCursor(12,1);
      lcd.print(now.hour());
      lcd.setCursor(11,1);
      lcd.print(""); 
    }
    lcd.setCursor(13,1);
    lcd.print(":");  
    if(now.minute() < 10){
      lcd.setCursor(15,1);
      lcd.print(now.minute());
      lcd.setCursor(14,1);
      lcd.print("0");  
     }
    if(now.hour() < 10){
      lcd.setCursor(11,1);
      lcd.print("0");  
      lcd.setCursor(12,1);
      lcd.print(now.hour());  
    }
    if(now.minute()>=10){
      lcd.setCursor(14,1);
      lcd.print(now.minute());
    }
    delay(5000);
    nilai=1;
    digitalWrite(7, LOW); 
  }
  
}

// ==========================================================//
if (finger.fingerID == 11){
  
  if(nilai == 2){
    digitalWrite(5, HIGH);
    lcd.setCursor(0,0);
    lcd.print("Lakukan Absensi             ");
    lcd.setCursor(0,1);
    lcd.print("ESOK HARI !!!              ");
    nilai = 2;
    delay(5000);
    digitalWrite(5, LOW);  
  } 
  if (nilai == 1){
    digitalWrite(7, HIGH);
    nilai = 2;
    Serial.print(F("DATA,JOICE RANDE P. S.Pdk M.Pdk.,"));
    Serial.print(F(" "));
    Serial.print(",");
    Serial.print(now.hour(), DEC);
    Serial.print(F("."));
    Serial.print(now.minute(), DEC);
    Serial.print(",");
    Serial.println(F("SMK ERAN BATU 3 SANGGALANGI"));
    lcd.setCursor(0,0);
    lcd.print("JOICE RANDE P.       ");  
    lcd.setCursor(0,1);
    lcd.print("Jam Keluar  ");
    if(now.hour() >=10){
      lcd.setCursor(11,1);
      lcd.print(now.hour());
      lcd.setCursor(10,1);
      lcd.print(""); 
    }
    lcd.setCursor(13,1);
    lcd.print(":");
  
    if(now.minute() < 10){
      lcd.setCursor(15,1);
      lcd.print(now.minute());
      lcd.setCursor(14,1);
      lcd.print("0");  
    }
    if(now.hour() < 10){
      lcd.setCursor(11,1);
      lcd.print("0");  
      lcd.setCursor(12,1);
      lcd.print(now.hour());  
    }
    if(now.minute()>=10){
      lcd.setCursor(14,1);
      lcd.print(now.minute());
    }
    delay(5000);
    digitalWrite(7, LOW);
  } 
  if (nilai == 0){
    digitalWrite(7, HIGH);
    Serial.print(F("DATA,JOICE RANDE P. S.Pdk M.Pdk,"));
    Serial.print(now.hour(), DEC);
    Serial.print(F("."));
    Serial.print(now.minute(), DEC);
    Serial.print(",");
    Serial.print(F(" "));
    Serial.print(",");
    Serial.println(F("SMK ERAN BATU 3 SANGGALANGI"));
    lcd.setCursor(0,0);
    lcd.print("JOICE RANDE P.      ");
    lcd.setCursor(0,1);
    lcd.print("Jam Masuk  ");
    if(now.hour() >=10){
      lcd.setCursor(12,1);
      lcd.print(now.hour());
      lcd.setCursor(11,1);
      lcd.print(""); 
    }
    lcd.setCursor(13,1);
    lcd.print(":");  
    if(now.minute() < 10){
      lcd.setCursor(15,1);
      lcd.print(now.minute());
      lcd.setCursor(14,1);
      lcd.print("0");  
     }
    if(now.hour() < 10){
      lcd.setCursor(11,1);
      lcd.print("0");  
      lcd.setCursor(12,1);
      lcd.print(now.hour());  
    }
    if(now.minute()>=10){
      lcd.setCursor(14,1);
      lcd.print(now.minute());
    }
    delay(5000);
    nilai=1;
    digitalWrite(7, LOW); 
  }
  
}

// ==========================================================//
if (finger.fingerID == 12){
  
  if(nilai == 2){
    digitalWrite(5, HIGH);
    lcd.setCursor(0,0);
    lcd.print("Lakukan Absensi             ");
    lcd.setCursor(0,1);
    lcd.print("ESOK HARI !!!              ");
    nilai = 2;
    delay(5000);
    digitalWrite(5, LOW);  
  } 
  if (nilai == 1){
    digitalWrite(7, HIGH);
    nilai = 2;
    Serial.print(F("DATA,MELDA PALI S.E.,"));
    Serial.print(F(" "));
    Serial.print(",");
    Serial.print(now.hour(), DEC);
    Serial.print(F("."));
    Serial.print(now.minute(), DEC);
    Serial.print(",");
    Serial.println(F("SMK ERAN BATU 3 SANGGALANGI"));
    lcd.setCursor(0,0);
    lcd.print("MELDA PALI       ");  
    lcd.setCursor(0,1);
    lcd.print("Jam Keluar  ");
    if(now.hour()>=10){
      lcd.setCursor(11,1);
      lcd.print(now.hour());
      lcd.setCursor(10,1);
      lcd.print(""); 
    }
    lcd.setCursor(13,1);
    lcd.print(":");
  
    if(now.minute() < 10){
      lcd.setCursor(15,1);
      lcd.print(now.minute());
      lcd.setCursor(14,1);
      lcd.print("0");  
    }
    if(now.hour() < 10){
      lcd.setCursor(11,1);
      lcd.print("0");  
      lcd.setCursor(12,1);
      lcd.print(now.hour());  
    }
    if(now.minute()>=10){
      lcd.setCursor(14,1);
      lcd.print(now.minute());
    }
    delay(5000);
    digitalWrite(7, LOW);
  } 
  if (nilai == 0){
    digitalWrite(7, HIGH);
    Serial.print(F("DATA,MELDA PALI S.E.,"));
    Serial.print(now.hour(), DEC);
    Serial.print(F("."));
    Serial.print(now.minute(), DEC);
    Serial.print(",");
    Serial.print(F(" "));
    Serial.print(",");
    Serial.println(F("SMK ERAN BATU 3 SANGGALANGI"));
    lcd.setCursor(0,0);
    lcd.print("MELDA PALI        ");
    lcd.setCursor(0,1);
    lcd.print("Jam Masuk  ");
    if(now.hour()>=10){
      lcd.setCursor(12,1);
      lcd.print(now.hour());
      lcd.setCursor(11,1);
      lcd.print(""); 
    }
    lcd.setCursor(13,1);
    lcd.print(":");  
    if(now.minute() < 10){
      lcd.setCursor(15,1);
      lcd.print(now.minute());
      lcd.setCursor(14,1);
      lcd.print("0");  
     }
    if(now.hour() < 10){
      lcd.setCursor(11,1);
      lcd.print("0");  
      lcd.setCursor(12,1);
      lcd.print(now.hour());  
    }
    if(now.minute()>=10){
      lcd.setCursor(14,1);
      lcd.print(now.minute());
    }
    delay(5000);
    nilai=1;
    digitalWrite(7, LOW); 
  }
  
}

// ================================================

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
  Serial.print(F("Found ID #")); Serial.print(finger.fingerID);
  
  Serial.print(F(" with confidence of ")); Serial.println(finger.confidence);
  return finger.fingerID;

  
}
