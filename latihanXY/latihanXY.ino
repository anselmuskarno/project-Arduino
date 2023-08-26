//KB1UIF (A.Tedds)
//Paint Sketch for Arduino LCD TFT 3.5" TFT Display 
#include <Adafruit_GFX.h>
//#include <Adafruit_ILI9341.h>
#include <TouchScreen.h>
#include <MCUFRIEND_kbv.h>
MCUFRIEND_kbv tft;  


#define YP A3  // must be an analog pin.
#define XM A2  // must be an analog pin.
#define YM 9   // can be a digital pin.
#define XP 8   // can be a digital pin.

#define TS_MINX 116
#define TS_MINY 955
#define TS_MAXX 893
#define TS_MAXY 102

#define BOXSIZE 40
#define PENRADIUS 3

int oldcolor, currentcolor;

// For better pressure precision, we need to know the resistance
// between X+ and X- Use any multimeter to read it
// Its about 300 ohms across the X plate on mine.


TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);

// Assign human-readable names to some common 16-bit color values:
#define BLACK   0xFFFF
#define BLUE    0xFFE0
#define GREEN   0xF81F
#define CYAN    0xF800
#define GRAY1   0x8410
#define RED     0x07FF
#define GRAY2   0x4208
#define MAGENTA 0x07E0
#define YELLOW  0x001F
#define WHITE   0x0000
#define PINK   0x07E0
#define MINPRESSURE 5
#define MAXPRESSURE 1500

 
 int X,Y;
 long Num1,Num2,Number;
 char action;
 boolean result = false;

void setup() {
  
Serial.begin(9600);
  Serial.println(F("Paint!"));
pinMode(31, OUTPUT); 
  tft.reset();
  uint16_t identifier = tft.readID();

  Serial.print(F("LCD driver chip: "));
  Serial.println(identifier,HEX);

 
  tft.begin(0x9486);
  tft.fillScreen(WHITE);
  tft.setRotation(2);
  tft.fillRect(10, 10, 80, 80, RED); //fillReact(x,y,panjang,lebar )
  
}

void loop() {

pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);
  TSPoint p;

  do {
    p = ts.getPoint(); 
    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);
  } while((p.z < MINPRESSURE )|| (p.z > MAXPRESSURE));
  p.x = map(p.x, TS_MINX, TS_MAXX, 0, 320);
  p.y = map(p.y, TS_MINY, TS_MAXY, 0, 480);

   Y = p.x; 
  X = p.y;

  if(Y>0 && Y<100){
    tft.fillRect(10, 10, 80, 80, YELLOW); //fillReact(x,y,panjang,lebar )
  } else {
    tft.fillRect(10, 10, 80, 80, BLUE); //fillReact(x,y,panjang,lebar )
  }

}
