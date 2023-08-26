/*
PINOUT:
RC522 MODULE    Uno/Nano     MEGA
SDA             D10          D9
SCK             D13          D52
MOSI            D11          D51
MISO            D12          D50
IRQ             N/A          N/A
GND             GND          GND
RST             D9           D8
3.3V            3.3V         3.3V
*/
/* Include the standard Arduino SPI library */
#include <SPI.h>
/* Include the RFID library */
#include <RFID.h>

/* Define the DIO used for the SDA (SS) and RST (reset) pins. */
#define SDA_DIO 9
#define RESET_DIO 8
/* Create an instance of the RFID library */
RFID RC522(SDA_DIO, RESET_DIO); 
String uidTag = "";  
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
void setup()
{ 
  lcd.begin();
  Serial.begin(9600);
  /* Enable the SPI interface */
  SPI.begin(); 
  /* Initialise the RFID reader */
  RC522.init();
}



  
void loop() {
  /* Has a card been detected? */
  if (RC522.isCard())
  {
      // UID terdeteksi
  uidTag = "";
    /* If so then get its serial number */
    RC522.readCardSerial();
    
    Serial.print("Kode kartu:");
    for(int i=0;i<5;i++)
    {
//    Serial.print(RC522.serNum[i],DEC);
//    Serial.print(RC522.serNum[i],HEX); //to print card detail in Hexa Decimal format
    uidTag += RC522.serNum[i];
    }
    Serial.println(uidTag);
    if(uidTag == "200135839216"){
      lcd.setCursor(0,0);    // (kesamping, kebawah)
      lcd.println("akses diterima             ");       
       lcd.setCursor(0,1);    // (kesamping, kebawah)
      lcd.println("YEHESKIEL                        ");
    }

 Serial.println(uidTag);
    if(uidTag == "3511550296"){
      lcd.setCursor(0,1);
      lcd.println("YOGY                           ");
    }

     Serial.println(uidTag);
    if(uidTag == "172206125238"){
      lcd.setCursor(0,1);
      lcd.println("PETRY                         ");
    }
    
   Serial.println(uidTag);
    if(uidTag == "1365134239228"){
      lcd.setCursor(0,1);
      lcd.println("CANDRA                         ");    
   } 

  delay(1000);}
