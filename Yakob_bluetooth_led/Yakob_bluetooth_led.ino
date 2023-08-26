#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
const int led=13;
const int relaySelenoid = 7;
void setup() {
  lcd.begin();
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  pinMode(relaySelenoid,OUTPUT);
     lcd.setCursor(0,0);
  lcd.print("LOADING....");
delay(5000);
lcd.clear();
 lcd.setCursor(0,0);
  lcd.print("SISTEM KEAMANAN");
   lcd.setCursor(0,1);
  lcd.print("BRANKAS");
  delay(5000);
  
}

void loop() {
//  Serial.println("conek");
  if(Serial.available()>0){
    Serial.println("conek2");
    
//  delay(5000);
    char data = Serial.read();
//  if(data != '7' || data != '1'){
    
//  }
    Serial.println(data);
    switch(data){

case '0':
    lcd.clear();
      Serial.println("conek");
        digitalWrite(led,LOW);
        lcd.setCursor(0,0);
  lcd.print("PASSWORD");
  lcd.setCursor(0,1);
  lcd.print("SALAH");
  delay(5000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("COBA LAGI");
  
  
//  delay(3000);
//  lcd.clear();
  digitalWrite(relaySelenoid, LOW); 
        break;

case '2':
    lcd.clear();
      Serial.println("conek");
        digitalWrite(led,LOW);
        lcd.setCursor(0,0);
  lcd.print("PASSWORD");
  lcd.setCursor(0,1);
  lcd.print("SALAH");
  delay(5000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("COBA LAGI");
  
  
//  delay(3000);
//  lcd.clear();
  digitalWrite(relaySelenoid, LOW); 
        break;

case '8':
    lcd.clear();
      Serial.println("conek");
        digitalWrite(led,LOW);
        lcd.setCursor(0,0);
  lcd.print("PASSWORD");
  lcd.setCursor(0,1);
  lcd.print("SALAH");
  delay(5000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("COBA LAGI");
  
  
//  delay(3000);
//  lcd.clear();
  digitalWrite(relaySelenoid, LOW); 
        break;

case '9':
    lcd.clear();
      Serial.println("conek");
        digitalWrite(led,LOW);
        lcd.setCursor(0,0);
  lcd.print("PASSWORD");
  lcd.setCursor(0,1);
  lcd.print("SALAH");
  delay(5000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("COBA LAGI");
  
  
//  delay(3000);
//  lcd.clear();
  digitalWrite(relaySelenoid, LOW); 
        break;

case '6':
    lcd.clear();
      Serial.println("conek");
        digitalWrite(led,LOW);
        lcd.setCursor(0,0);
  lcd.print("PASSWORD");
  lcd.setCursor(0,1);
  lcd.print("SALAH");
  delay(5000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("COBA LAGI");
  
  
//  delay(3000);
//  lcd.clear();
  digitalWrite(relaySelenoid, LOW); 
        break;

case '5':
    lcd.clear();
      Serial.println("conek");
        digitalWrite(led,LOW);
        lcd.setCursor(0,0);
  lcd.print("PASSWORD");
  lcd.setCursor(0,1);
  lcd.print("SALAH");
  delay(5000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("COBA LAGI");
  
  
//  delay(3000);
//  lcd.clear();
  digitalWrite(relaySelenoid, LOW); 
        break;

case '4':
    lcd.clear();
      Serial.println("conek");
        digitalWrite(led,LOW);
        lcd.setCursor(0,0);
  lcd.print("PASSWORD");
  lcd.setCursor(0,1);
  lcd.print("SALAH");
  delay(5000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("COBA LAGI");
  
  
//  delay(3000);
//  lcd.clear();
  digitalWrite(relaySelenoid, LOW); 
        break;

case '3':
    lcd.clear();
      Serial.println("conek");
        digitalWrite(led,LOW);
        lcd.setCursor(0,0);
  lcd.print("PASSWORD");
  lcd.setCursor(0,1);
  lcd.print("SALAH");
  delay(5000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("COBA LAGI");
  
  
//  delay(3000);
//  lcd.clear();
  digitalWrite(relaySelenoid, LOW); 
        break;

//============================================================      
      case '7':  //PASSWORD BRANKAS ADALAH ANGKA 7
      lcd.clear();
      Serial.println("conek");
        digitalWrite(led,LOW);
        lcd.setCursor(0,0);
  lcd.print("BRANKAS");
  lcd.setCursor(0,1);
  lcd.print("TERBUKA");
//  delay(3000);
//  lcd.clear();
  digitalWrite(relaySelenoid, HIGH); 
        break;
        
      case '1':
      lcd.clear();
      Serial.println("conek");
        digitalWrite(led,HIGH);
        lcd.setCursor(0,0);
  lcd.print("BRANKAS");
  lcd.setCursor(0,1);
  lcd.print("TERTUTUP");
  digitalWrite(relaySelenoid, LOW); 
        break;
      default:
        break;
    }
  }
}
