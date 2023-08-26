#include <Servo.h>                    // menggunakan library
Servo motorKu;                          // motor servo diberi nama motorKu
const int pinIR = 8;

void setup()
{
     pinMode(pinIR, INPUT);
     motorKu.attach(7);               // motor servo dihubungkan ke pin digital 3
     motorKu.write(0);                 // set motor servo ke posisi 0 derajat
     delay(1000);                           // tunggu hingga posisi 0 derajat
     Serial.begin(9600);
}
//int timeDelay = 500;
void loop()
{    
//     while (timeDelay > 0) {
     int sensorState = digitalRead(pinIR);

     if(sensorState == LOW){
      Serial.println("Tedeteksi");
     motorKu.write(135);            // set motor servo ke posisi 180 derajat (ke kanan 45 derajat)
     delay(2000);         
     motorKu.write(45);            // set motor servo ke posisi 135 derajat (ke kiri 45 derajat)
     delay(2000);         
     } else {
      Serial.println("Tidak terdeteksi");
     }
     
//      timeDelay=timeDelay-100;
//      Serial.println(timeDelay);
//     }

          
              
}
