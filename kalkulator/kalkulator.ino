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


/*
String symbol[4][4] = {
  { "7", "8", "9", "/" },
  { "4", "5", "6", "*" },
  { "1", "2", "3", "-" },
  { "C", "0", "=", "+" }
};

*/

String symbol[4][4] = {
  { "/", "*", "-", "+" },
  { "9", "6", "3", "=" },
  { "8", "5", "2", "0" },
  { "7", "4", "1", "C" }
};




 int X,Y;
 long Num1,Num2,Number;
 char action;
 boolean result = false;



void setup(void) 
{
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
  
  
    Screen();
  
  drawButtons(); 

  
}

void loop()
{
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

Serial.println(p.x);
Serial.println(p.y);

   Y = p.x; 
  X = p.y;
  
  
  DetectButtons();

if (result==true)
CalculateResult();

DisplayResult();   

  delay(300);
  
}

void DetectButtons()
{
  
  if (X<80 && X>0) //Deteksi tombol pada kolom ke 1 (angka 7, 4, 1, C)
  {
    if (Y>0 && Y<85) //If cancel Button is pressed
    {
      
      digitalWrite(31, LOW); 
      Number=Num1=Num2=0; 
      result=false;}
    
     if (Y>85 && Y<160) //If Button 1 is pressed
    {
    digitalWrite(31, HIGH); 
    if (Number==0)
    Number=1;
    else
    Number = (Number*10) + 1; //Pressed twice
    }
    
    
     if (Y>160 && Y<240) //If Button 4 is pressed
    {Serial.println ("Button 4"); 
    if (Number==0)
    Number=4;
    else
    Number = (Number*10) + 4; //Pressed twice
    }
    
     if (Y>240 && Y<320) //If Button 7 is pressed
    {Serial.println ("Button 7");
    if (Number==0)
    Number=7;
    else
    Number = (Number*10) + 7; //Pressed twice
    } 
  }

    if (X<160 && X>80) //Detecting Buttons on Column 2
  {
    if (Y>0 && Y<85)
    {Serial.println ("Button 0"); //Button 0 is Pressed
    if (Number==0)
    Number=0;
    else
    Number = (Number*10) + 0; //Pressed twice
    }
    
     if (Y>85 && Y<160)
    {Serial.println ("Button 2"); 
     if (Number==0)
    Number=2;
    else
    Number = (Number*10) + 2; //Pressed twice
    }
    
     if (Y>160 && Y<240)
    {Serial.println ("Button 5"); 
     if (Number==0)
    Number=5;
    else
    Number = (Number*10) + 5; //Pressed twic
    }
    
     if (Y>240 && Y<320)
    {Serial.println ("Button 8"); 
     if (Number==0)
    Number=8;
    else
    Number = (Number*10) + 8; //Pressed twic
    }   
  }

    if (X<240 && X>160) //Detecting Buttons on Column 3
  {
    if (Y>0 && Y<85)
    {Serial.println ("Button Equal"); 
    Num2=Number;
    result = true;
    }
    
     if (Y>85 && Y<160)
    {Serial.println ("Button 3"); 
     if (Number==0)
    Number=3;
    else
    Number = (Number*10) + 3; //Pressed twice
    }
    
     if (Y>160 && Y<240)
    {Serial.println ("Button 6"); 
    if (Number==0)
    Number=6;
    else
    Number = (Number*10) + 6; //Pressed twice
    }
    
     if (Y>240 && Y<320)
    {Serial.println ("Button 9");
    if (Number==0)
    Number=9;
    else
    Number = (Number*10) + 9; //Pressed twice
    }   
  }


     if (X<320 && X>240) //Detecting Buttons on Column 3
  {

    Num1 = Number;    
    Number =0;

    tft.setCursor(200, 20);
    tft.setTextColor(RED);
    if (Y>0 && Y<85)

    
    {
      Serial.println ("Addition Button"); 
    
    Serial.println ("Addition");
    action = 1;
    tft.println('+');
    
    }
    
     if (Y>85 && Y<160)
    {
      
      Serial.println ("substraction Button"); 
   
       Serial.println ("substraction");
    action = 2;
    tft.println('-');

    }
    
     if (Y>160 && Y<240)
    {
      Serial.println ("multiplication Button"); 
      Serial.println ("multiplication");
    action = 3;
    tft.println('*');

    }
    
     if (Y>240 && Y<320)
    {
      Serial.println ("Division Button");
     Serial.println ("Division");
    action = 4;
    tft.println('/');

    }   
  }

  


/*
      if (X<320 && X>400) //Detecting Buttons on Column 3
  {
    Num1 = Number;    
    Number =0;
    tft.setCursor(200, 20);
    tft.setTextColor(RED);
    if (Y>0 && Y<85)
    {Serial.println ("Addition"); action = 1; tft.println('+');}
     if (Y>85 && Y<160)
    {Serial.println ("Subtraction"); action = 2; tft.println('-');}
     if (Y>160 && Y<240)
    {Serial.println ("Multiplication"); action = 3; tft.println('*');}
     if (Y>240 && Y<320)
    {Serial.println ("Devesion"); action = 4; tft.println('/');}  

    delay(300);
  }  

  */
}





void CalculateResult()
{
  if (action==1)
    Number = Num1+Num2;

  if (action==2)
    Number = Num1-Num2;

  if (action==3)
    Number = Num1*Num2;

  if (action==4)
    Number = Num1/Num2; 
}

void DisplayResult()
{
    tft.fillRect(0, 0, 320, 160, CYAN);  //clear result box
    tft.setCursor(10, 20);
    tft.setTextSize(4);
    tft.setTextColor(BLACK);
    tft.println(Number); //update new value
}

void Screen()
{
  tft.setCursor (105, 120);
  tft.setTextSize (3);
  tft.setTextColor(BLUE);
  tft.println("ARDUINO");
  tft.setCursor (50, 160);
  tft.println("CALCULATOR");
  tft.setCursor (50, 220);
  tft.setTextSize (2);
  tft.setTextColor(BLUE);
  
  delay(1800);
}

void drawButtons()
{
  //Draw the Result Box
  tft.fillRect(0, 0, 320, 160, CYAN);

 //Draw First Column
  tft.fillRect  (0,400,80,80,BLACK);
  tft.fillRect  (0,320,80,80,BLACK);
  tft.fillRect  (0,240,80,80,BLACK);
  tft.fillRect  (0,160,80,80,MAGENTA);



 //Draw SECOND Column  
  tft.fillRect  (80,400,80,80,BLACK);
  tft.fillRect  (80,320,80,80,BLACK);
  tft.fillRect  (80,240,80,80,BLACK);
  tft.fillRect  (80,160,80,80,BLUE);




 //Draw Third Column  
  tft.fillRect  (160,400,80,80,BLACK);
  tft.fillRect  (160,320,80,80,BLACK);
  tft.fillRect  (160,240,80,80,BLACK);
  tft.fillRect  (160,160,80,80,MAGENTA);



  tft.fillRect  (240,400,80,80,RED);
  tft.fillRect  (240,320,80,80,BLACK);
  tft.fillRect  (240,240,80,80,GREEN);
  tft.fillRect  (240,160,80,80,BLUE);

/*
  //Draw Horizontal Lines
  for (int h=160; h<=400; h+=80)
  tft.drawFastHLine(0, h, 400, WHITE);

  //Draw Vertical Lines
  for (int v=0; v<=320; v+=80)
  tft.drawFastVLine(v, 80, 320, WHITE);

  */
  
  //Display keypad lables 
  for (int j=0;j<4;j++) {
    for (int i=0;i<4;i++) {
      tft.setCursor(22 + (80*i),  180 + (80*j));
      tft.setTextSize(3);
      tft.setTextColor(WHITE);
      tft.println(symbol[j][i]);
    }
  }


}
