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
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
#define relayPin 7
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'7','8','9','C'},
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {A3, A2, A1, A0}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
int position = 0;
int salah = 0;
void setup(){
  lcd.begin();
    pinMode(relayPin, OUTPUT);
  Serial.begin(9600);
}
  
void loop(){
  Serial.println("masuk");
     digitalWrite(relayPin, LOW);
  char* password = "159";
  char customKey = customKeypad.getKey();
   lcd.setCursor(0,0);
  lcd.print("Input Password  ");
  lcd.setCursor(0,1);
  lcd.print(customKey);
  lcd.setCursor(0,1);
  lcd.print("                ");
  if (customKey){
  lcd.setCursor(0,0);
  lcd.print("Input Password");
  lcd.setCursor(0,1);
  lcd.print(customKey);
  if(salah==0){
   lcd.setCursor(0,1);
  lcd.print(" *");delay(500);
  }if(salah==1){
   lcd.setCursor(0,1);
  lcd.print(" **");delay(500);
  }if(salah==2){
   lcd.setCursor(0,1);
  lcd.print(" ***");delay(500);
  }

  }
  if (
    customKey == '2' ||
    customKey == '3' ||
    customKey == 'A' ||
    customKey == '4' ||
    customKey == '6' ||
    customKey == 'B' ||
    customKey == '7' ||
    customKey == '8' ||
    customKey == 'C' ||
    customKey == '*' ||
    customKey == '0' ||
    customKey == '#' ||
    customKey == 'D' 
    
    ){
    salah++;
    
  }  if (salah == 3){
     salah = 0;
    lcd.setCursor(0,0);
  lcd.print("AKSES DITOLAK   ");
  lcd.setCursor(0,1);
  lcd.print("Password Salah");
  delay(5000);
    position = 0;
  }
  if (customKey == password[position] ){
    position++;
  } if (position == 3){
   Serial.print(password[0]);
    Serial.print(password[1]);
    Serial.print(password[2]);
     lcd.setCursor(0,0);
  lcd.print("AKSES DITERIMA  ");
  lcd.setCursor(0,1);
  lcd.print("Pintu Terbuka");
    digitalWrite(relayPin, HIGH);
    // Kasi Delay 2 detik
    Serial.println("HIGH selama 5 detik (BUKA PINTU)");
    delay(5000);
  }
  if(position == 4){
    position = 0;
  }
  
}
