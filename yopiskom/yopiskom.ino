#define enA 6
#define in1 8
#define in2 9
#define enB 7
#define in3 10
#define in4 11
int motorSpeedA = 0;
int motorSpeedB = 0;

void setup() {
  
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // Mengaktifkan serial monitor
  Serial.begin(9600);

}


void loop() {
    motorSpeedA = 80; //bisa diambil dari joystick, tapi sekarang kita input manual aja yak; 0-255
    motorSpeedB = 80; //bisa diambil dari joystick, tapi sekarang kita input manual aja yak; 0-255
//    analogWrite(enA, motorSpeedA); // Send PWM signal to motor A
//    analogWrite(enB, motorSpeedB); // Send PWM signal to motor B
   

 Serial.println("Mundur");
 // Set Motor A backward
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
     // Set Motor B backward
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    
//
//else if (
//lampuSensor1 == menyala && lampuSensor2 == menyala && lampuSensor3 == menyala && lampuSensor4 == menyala && lampuSensor5 == menyala ||
//  lampuSensor1 == mati && lampuSensor2 == mati && lampuSensor3 == menyala && lampuSensor4 == mati && lampuSensor5 == mati ||
//lampuSensor1 == mati && lampuSensor2 == menyala && lampuSensor3 == menyala && lampuSensor4 == menyala && lampuSensor5 == mati ||
//lampuSensor1 == mati && lampuSensor2 == menyala && lampuSensor3 == menyala && lampuSensor4 == mati && lampuSensor5 == mati ||
//lampuSensor1 == mati && lampuSensor2 == menyala && lampuSensor3 == mati && lampuSensor4 == mati && lampuSensor5 == mati ||
//lampuSensor1 == mati && lampuSensor2 == mati && lampuSensor3 == mati && lampuSensor4 == menyala && lampuSensor5 == mati ||
//lampuSensor1 == mati && lampuSensor2 == mati && lampuSensor3 == menyala && lampuSensor4 == menyala && lampuSensor5 == mati) {
//  Serial.println("Jalan Lurus");
//  // Set Motor A forward
//   digitalWrite(in1, HIGH);
//    digitalWrite(in2, LOW);
//     // Set Motor B backward
//    digitalWrite(in3, HIGH);
//    digitalWrite(in4, LOW);
//    
//} 
//else  if (lampuSensor1 == mati && lampuSensor2 == menyala && lampuSensor3 == menyala && lampuSensor4 == menyala && lampuSensor5 == menyala ||
//  lampuSensor1 == mati && lampuSensor2 == mati && lampuSensor3 == mati && lampuSensor4 == mati && lampuSensor5 == menyala ||
//lampuSensor3 == menyala && lampuSensor4 == menyala && lampuSensor5 == menyala ||
//lampuSensor3 == mati && lampuSensor4 == menyala && lampuSensor5 == menyala){
// Serial.println("Belok kiri");
//  // Set Motor A backward
//    digitalWrite(in1, HIGH);
//    digitalWrite(in2, LOW);
//     // Set Motor B backward
//    digitalWrite(in3, LOW);
//    digitalWrite(in4, HIGH);  
//   }
//   else if (lampuSensor1 == menyala && lampuSensor2 == mati && lampuSensor3 == mati && lampuSensor4 == mati && lampuSensor5 == mati ||
//lampuSensor1 == menyala && lampuSensor2 == menyala && lampuSensor3 == menyala ||
//lampuSensor1 == menyala && lampuSensor2 == menyala && lampuSensor3 == mati ){
//Serial.println("Belok kanan");
//  // Set Motor A backward
//    digitalWrite(in1, LOW);
//    digitalWrite(in2, HIGH);
//     // Set Motor B backward
//    digitalWrite(in3, HIGH);
//    digitalWrite(in4, LOW);  
//}

}
