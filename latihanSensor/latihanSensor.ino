#define SENSOR2 44
#define SENSOR3 46
//#define ACTION 35
#include <Servo.h>
Servo servo2;
Servo servo3;
//int pos, ulang;
void setup() {
Serial.begin(9600);
  pinMode(SENSOR2, INPUT_PULLUP);
    pinMode(SENSOR3, INPUT_PULLUP);
//    pinMode(ACTION, OUTPUT);// define pin as OUTPUT for ACTION

// servo2.attach(40);
//    servo3.attach(36);
}

void loop() {
   int L =digitalRead(SENSOR2);
     int N =digitalRead(SENSOR3);


// if(L == 0){
//  for ( ulang=1; ulang<=3;  ulang+=1){
//       Serial.println(" Sensor 2 mendeteksi objek");
//       for( pos=1; pos<=3; pos+=1){
//       servo2.write(pos);
//       }
//       digitalWrite(ACTION,HIGH);
//  }
//    }
   
    if(N == 0){
//       Serial.println(" Sensor 3 mendeteksi objek");
//       servo3.write(0);
//       digitalWrite(ACTION,HIGH);
       Serial.println(" Sensor N mendeteksi objek");
    } 
    
    else{
      Serial.println(" Sensor tidak mendeteksi objek");
//         servo2.write(90);
//       servo3.write(90);
//       digitalWrite(ACTION,LOW);
      
    }

}
