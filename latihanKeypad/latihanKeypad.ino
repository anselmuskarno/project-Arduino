/* @file CustomKeypad.pde
  || @version 1.0
  || @author Alexander Brevig
  || @contact alexanderbrevig@gmail.com
  ||
  || @description
  || | Demonstrates changing the keypad size and key values.
  || #
*/
#include <Keypad.h>
const int relayD = 2;
const int relayC = 11;
const int relayB = 12;
const int relayA = 13;
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'2', '1', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {10, 9, 8, 7}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {6, 5, 4, 3}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);
  pinMode(relayD,OUTPUT);
pinMode(relayC,OUTPUT);
pinMode(relayB,OUTPUT);
pinMode(relayA,OUTPUT);
 digitalWrite(relayA, HIGH);
  digitalWrite(relayB, HIGH);
   digitalWrite(relayC, HIGH);
    digitalWrite(relayD, HIGH);
}
int parameterA=0;
int parameterB=0;
int parameterC=0;
int parameterD=0;
int parameterBintang=0;
int parameterPagar=0;

void loop() {
 char customKey = customKeypad.getKey();
 
  Serial.println(parameterA);
   if (customKey == 'A' && parameterA==1) {
  Serial.println("ok");
  digitalWrite(relayA, HIGH);
  Serial.println(customKey);
  Serial.println("ok");
  parameterA=2;
  }
  
  if (customKey == 'A' && parameterA==0) {
  Serial.println("ok");
  digitalWrite(relayA, LOW);
  Serial.println(customKey);
  Serial.println("ok");
  parameterA=1;
    
  }

if (parameterA==2) {
  
  parameterA=0;
    
  }

//===================================================

   if (customKey == '*' && parameterBintang==1) {
  Serial.println("ok");
  digitalWrite(relayA, HIGH);
  digitalWrite(relayB, HIGH);
  digitalWrite(relayC, HIGH);
  digitalWrite(relayD, HIGH);
  Serial.println(customKey);
  Serial.println("ok");
  parameterBintang=2;
  }
  
  if (customKey == '*' && parameterBintang==0) {
  Serial.println("ok");
  digitalWrite(relayA, LOW);
  digitalWrite(relayB, LOW);
  digitalWrite(relayC, LOW);
  digitalWrite(relayD, LOW);
  Serial.println(customKey);
  Serial.println("ok");
  parameterBintang=1;
    
  }

if (parameterBintang==2) {
  
  parameterBintang=0;
    
  }

//===================================================

 if (customKey == '4' && parameterPagar==1) {
  Serial.println("ok");
  digitalWrite(relayA, HIGH);
  digitalWrite(relayB, HIGH);
  digitalWrite(relayC, HIGH);
  digitalWrite(relayD, HIGH);
  Serial.println(customKey);
  Serial.println("ok");
  parameterPagar=2;
  }
  
  if (customKey == '4' && parameterPagar==0) {
  Serial.println("ok");
  digitalWrite(relayA, LOW);
  digitalWrite(relayB, LOW);
  digitalWrite(relayC, LOW);
  digitalWrite(relayD, LOW);
  Serial.println(customKey);
  Serial.println("ok");
  parameterPagar=1;
    
  }

if (parameterPagar==2) {
  
  parameterPagar=0;
    
  }

//===================================================


  Serial.println(parameterB);
   if (customKey == '3' && parameterB==1) {
  Serial.println("ok");
  digitalWrite(relayB, HIGH);
  Serial.println(customKey);
  Serial.println("ok");
  parameterB=2;
  }
  
  if (customKey == '3' && parameterB==0) {
  Serial.println("ok");
  digitalWrite(relayB, LOW);
  Serial.println(customKey);
  Serial.println("ok");
  parameterB=1;
    
  }

if (parameterB==2) {
  
  parameterB=0;
    
  }

//===================================================

  Serial.println(parameterC);
   if (customKey == '2' && parameterC==1) {
  Serial.println("ok");
  digitalWrite(relayC, HIGH);
  Serial.println(customKey);
  Serial.println("ok");
  parameterC=2;
  }
  
  if (customKey == '2' && parameterC==0) {
  Serial.println("ok");
  digitalWrite(relayC, LOW);
  Serial.println(customKey);
  Serial.println("ok");
  parameterC=1;
    
  }

if (parameterC==2) {
  
  parameterC=0;
    
  }

//===================================================

  Serial.println(parameterD);
   if (customKey == '1' && parameterD==1) {
  Serial.println("ok");
  digitalWrite(relayD, HIGH);
  Serial.println(customKey);
  Serial.println("ok");
  parameterD=2;
  }
  
  if (customKey == '1' && parameterD==0) {
  Serial.println("ok");
  digitalWrite(relayD, LOW);
  Serial.println(customKey);
  Serial.println("ok");
  parameterD=1;
    
  }

if (parameterD==2) {
  
  parameterD=0;
    
  }

//===================================================

}
