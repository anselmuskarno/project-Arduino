#include "Adafruit_GFX.h"    // Core graphics library
#include "MCUFRIEND_kbv.h"   // Hardware-specific library
MCUFRIEND_kbv tft;

#define BLACK   0x0000
#define RED     0xF800
#define GREEN   0x07E0
#define WHITE   0xFFFF
#define GREY    0x8410

#include "images.h"

#include "Fonts/FreeSans9pt7b.h"
#include "Fonts/FreeSans12pt7b.h"
#include "Fonts/FreeSerif12pt7b.h"
#include "FreeDefaultFonts.h"

int a = 3000;
int b = 4000;
int j, j2;
int i, i2;

void showmsgXY(int x, int y, int sz, const GFXfont *f, const char *msg)
{
    int16_t x1, y1;
    uint16_t wid, ht;
   // tft.drawFastHLine(0, y, tft.width(), 0xffff);
    tft.setFont(f);
    tft.setCursor(x, y);
    tft.setTextColor(WHITE);
    tft.setTextSize(sz);
    tft.print(msg);
    delay(1000);
}

void setup()
{
  Serial.begin(9600);
  uint16_t ID = tft.readID();
  tft.begin(ID);
  tft.invertDisplay(true);
  tft.setRotation(1);
}

void loop(void)
{
  tft.invertDisplay(true);
  tft.fillScreen(BLACK);

  tft.drawRGBBitmap(0, 0, test, 480, 320);

  tft.drawBitmap(20, 20, Line1, 45, 45, 0xffff);//battery
  tft.drawBitmap(65, 20, Line2, 45, 45, 0xffff);//wifi
  tft.drawBitmap(125, 25, Line3, 45, 45, 0xffff);//mail
  tft.drawBitmap(185, 25, Line4, 45, 45, 0xffff);//instagram
  tft.drawBitmap(245, 25, Line6, 45, 45, 0xffff);//power
  tft.drawBitmap(20, 260, Line5, 45, 45, 0xffff);//twitter

  tft.drawBitmap(410, 140, Line7, 45, 45, 0xffff);//rain

  tft.setTextSize(6);
  tft.setTextColor(0xffff);
  tft.setCursor(280, 210);
  tft.print("20:45"); 
    tft.setTextSize(2);
  tft.setTextColor(0xffff);
  showmsgXY(330, 280, 1, &FreeSans12pt7b, "Saturday");
  showmsgXY(300, 305, 1, &FreeSans12pt7b, "6 October 2018");
  
  while (1);
}
