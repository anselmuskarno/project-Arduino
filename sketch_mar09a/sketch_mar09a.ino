#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

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

void setup()
{ 
  lcd.begin();
  Serial.begin(9600);
  /* Enable the SPI interface */
  SPI.begin(); 
  /* Initialise the RFID reader */
  RC522.init();
}

String gabung;

void loop()
{
    lcd.setCursor(0,0);
  lcd.print("SISTEM PENDETEKSI");
  lcd.setCursor(0,1);
  lcd.print("KARTU       ");
  /* Has a card been detected? */
  if (RC522.isCard())
  {
    /* If so then get its serial number */
    RC522.readCardSerial();
    Serial.println("Card detected:");
    for(int i=0;i<5;i++)
    {
    Serial.print(RC522.serNum[i],DEC);
    //Serial.print(RC522.serNum[i],HEX); //to print card detail in Hexa Decimal format
    gabung+=RC522.serNum[i];
    }
    Serial.print("Nilai= ");
    Serial.println(gabung);
    if(gabung == "200135839216"){
       lcd.setCursor(0,0);
  lcd.print("Akses Diterima   ");
  lcd.setCursor(0,1);
  lcd.print("PETRI           ");
  delay(3000);
    } 
    if(gabung == "3511550296"){
      lcd.setCursor(0,0);
  lcd.print("Akses Diterima   ");
  lcd.setCursor(0,1);
  lcd.print("SAPIRA       ");
   delay(3000);
    }
     if(gabung == "172206125238"){
      lcd.setCursor(0,0);
  lcd.print("Akses DITOLAK    ");
   lcd.setCursor(0,1);
  lcd.print("                ");
   delay(3000);

    }
    gabung="";
    Serial.println();
    Serial.println();
  }
  delay(1000);
}
