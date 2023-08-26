#include "Adafruit_GFX.h"
#include "MCUFRIEND_kbv.h"
MCUFRIEND_kbv tft;

#include "Fonts/FreeSans9pt7b.h"
#include "Fonts/FreeSans12pt7b.h"
#include "Fonts/FreeSerif12pt7b.h"
#include "FreeDefaultFonts.h"

#define PI 3.1415926535897932384626433832795

int col[8];

void showmsgXY(int x, int y, int sz, const GFXfont *f, const char *msg)
{
  int16_t x1, y1;
  uint16_t wid, ht;


  tft.setFont(f);
  tft.setCursor(x, y);
  tft.setTextColor(0x0000);
  tft.setTextSize(sz);
  tft.print(msg);
}

void setup() {
  tft.reset();
  Serial.begin(9600);
  uint16_t ID = tft.readID();
  tft.begin(ID);
  tft.setRotation(1);
  tft.invertDisplay(true);
  tft.fillScreen(tft.color565(100, 100, 0));
//  showmsgXY(170, 250, 2, &FreeSans9pt7b, "Loading...");
  col[0] = tft.color565(155, 50, 0);
  col[1] = tft.color565(170, 80, 30);
  col[2] = tft.color565(195, 110, 60);
  col[3] = tft.color565(215, 140, 90);
  col[4] = tft.color565(230, 170, 120);
  col[5] = tft.color565(250, 200, 150);
  col[6] = tft.color565(255, 220, 180);
  col[7] = tft.color565(255, 240, 210);
  Serial.begin(9600);

}

void loop() {
  for (int i = 8; i > 0; i--) {
//                (
int a = 40 * (cos(-i * PI / 4));
int b = 40 * (cos(-(i + 1)*PI / 4));
int c = 40 * (cos(-(i + 2)*PI / 4));
int d = 40 * (cos(-(i + 3)*PI / 4));
int e = 40 * (cos(-(i + 4)*PI / 4));
int f = 40 * (cos(-(i + 5)*PI / 4));
int g = 40 * (cos(-(i + 6)*PI / 4));
int h = 40 * (cos(-(i + 7)*PI / 4));

   tft.fillCircle(340 + 40 * (cos(-i * PI / 4)), 220 + 40 * (sin(-i * PI / 4)), 5,  col[0]); delay(15);
    tft.fillCircle(340 + 40 * (cos(-(i + 1)*PI / 4)), 220 + 40 * (sin(-(i + 1)*PI / 4)), 5,  col[1]); delay(15);
    tft.fillCircle(340 + 40 * (cos(-(i + 2)*PI / 4)), 220 + 40 * (sin(-(i + 2)*PI / 4)), 5,  col[2]); delay(15); 
    tft.fillCircle(340 + 40 * (cos(-(i + 3)*PI / 4)), 220 + 40 * (sin(-(i + 3)*PI / 4)), 5,  col[3]); delay(15);
    tft.fillCircle(340 + 40 * (cos(-(i + 4)*PI / 4)), 220 + 40 * (sin(-(i + 4)*PI / 4)), 5,  col[4]); delay(15); 
    tft.fillCircle(340 + 40 * (cos(-(i + 5)*PI / 4)), 220 + 40 * (sin(-(i + 5)*PI / 4)), 5,  col[5]); delay(15);
    tft.fillCircle(340 + 40 * (cos(-(i + 6)*PI / 4)), 220 + 40 * (sin(-(i + 6)*PI / 4)), 5,  col[6]); delay(15);
    tft.fillCircle(340 + 40 * (cos(-(i + 7)*PI / 4)), 220 + 40 * (sin(-(i + 7)*PI / 4)), 5,  col[7]); delay(15);
  delay(3000);
  }
  Serial.println("-----------------------------------------------------");
}
