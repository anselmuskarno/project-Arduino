//kiri
const int trigPin1 = A1;
const int echoPin1 = A0;

//tengah
const int trigPin2 = A3; 
const int echoPin2 = A2;

//kanan
const int trigPin3 = 12;
const int echoPin3 = 11;

const int in1 = 4;
const int in2 = 5;
const int in3 = 7;
const int in4 = 6;
const int enA = 3;
const int enB = 9;
int blockAPin = 8; // Pin input

#define PWM 80
#define DIS 2   //jarak

void setup() 
{
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
    pinMode(blockAPin, INPUT);
  
  pinMode (in1, OUTPUT);
  pinMode (in2, OUTPUT);
  pinMode (in3, OUTPUT);
  pinMode (in4, OUTPUT);
  pinMode (enA, OUTPUT);
  pinMode (enB, OUTPUT);
  Serial.begin(9600); 
}

void loop()
{

    Serial.println("Sensor 1 Front =");
  Serial.println(FrontSensor());
  Serial.println("Sensor 2 Right=");
  Serial.println(RightSensor());
  Serial.println("Sensor 3 Left=");
  Serial.println(LeftSensor());   
Serial.println("==========================================================");
  //Maju


//if(digitalRead(blockAPin) == 0){
//  Serial.println("Kondisi 1");
//   turn_left();
//   delay(550);
//   forward();
//   delay(400);
//}
  //Apabila 
//  if(LeftSensor() > 20){
//   Serial.println("Kondisi 2");
////    turn_right();
////    delay(500);
//////    turn_left();
//////    delay(300);
////    forward();
////    delay(700);
// digitalWrite(in1, LOW);
//  digitalWrite(in2, HIGH);
//  digitalWrite(in3, HIGH);
//  digitalWrite(in4, LOW);
//  analogWrite(enA, 120); 
//  analogWrite(enB, PWM);
//  delay(200);
//  forward();
//  delay(200);
//  } 
//   else if(LeftSensor() < 10){
//   Serial.println("Kondisi 4");
//   digitalWrite(in1, LOW);
//  digitalWrite(in2, HIGH);
//  digitalWrite(in3, HIGH);
//  digitalWrite(in4, LOW);
//  analogWrite(enA, 120); 
//  analogWrite(enB, 80);
//  delay(300);
////   digitalWrite(in1, HIGH);
////  digitalWrite(in2, LOW);
////  digitalWrite(in3, LOW);
////  digitalWrite(in4, HIGH);
////  analogWrite(enA, PWM); 
////  analogWrite(enB, PWM);
////  delay(500);
// forward();
//  delay(800);
////  analogWrite(enA, PWM); 
////  analogWrite(enB, PWM);
////  delay(3000);
//  }
//else
if(RightSensor() < 10 || digitalRead(blockAPin) == 0){
  
   Serial.println("Kondisi 2");
   reverse();
   delay(200);
   //belok masuk
    digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, PWM); 
  analogWrite(enB, PWM);
  delay(1000);
//   digitalWrite(in1, LOW);
//  digitalWrite(in2, HIGH);
//  digitalWrite(in3, HIGH);
//  digitalWrite(in4, LOW);
//  analogWrite(enA, PWM); 
//  analogWrite(enB, PWM);
//  delay(100);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, PWM); 
  analogWrite(enB, PWM);
  delay(100);
  }
//Jika jarak ke kiri terlalu jauh, belok ke kiri
else if(FrontSensor() > 20){
   Serial.println("Kondisi 1");
   //belok masuk
    digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, PWM); 
  analogWrite(enB, PWM);
  delay(300);
//   digitalWrite(in1, LOW);
//  digitalWrite(in2, HIGH);
//  digitalWrite(in3, HIGH);
//  digitalWrite(in4, LOW);
//  analogWrite(enA, PWM); 
//  analogWrite(enB, PWM);
//  delay(100);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, PWM); 
  analogWrite(enB, PWM);
  delay(500);
  }
  // Jika jarak ke tengah kurang dari 12, maka putar balik

else if(LeftSensor() < 6){
   Serial.println("Kondisi 3");
   //belok masuk
    digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, PWM); 
  analogWrite(enB, PWM);
  delay(200);
//   digitalWrite(in1, LOW);
//  digitalWrite(in2, HIGH);
//  digitalWrite(in3, HIGH);
//  digitalWrite(in4, LOW);
//  analogWrite(enA, PWM); 
//  analogWrite(enB, PWM);
//  delay(100);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, PWM); 
  analogWrite(enB, PWM);
  delay(100);
  }
  //Jika jarak ke kiri kurang, maka putar ke kanan
else if(FrontSensor() < 4){
   Serial.println("Kondisi 3");
   //belok masuk
    digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, PWM); 
  analogWrite(enB, PWM);
  delay(200);
//   digitalWrite(in1, LOW);
//  digitalWrite(in2, HIGH);
//  digitalWrite(in3, HIGH);
//  digitalWrite(in4, LOW);
//  analogWrite(enA, PWM); 
//  analogWrite(enB, PWM);
//  delay(100);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, PWM); 
  analogWrite(enB, PWM);
  delay(100);
  } else {
    Serial.println("Kondisi 0");
      forward();
  }
 
//  else if(LeftSensor() < 6){
//     Serial.println("Kondisi 4");
//    digitalWrite(in1, HIGH);
//  digitalWrite(in2, LOW);
//  digitalWrite(in3, LOW);
//  digitalWrite(in4, HIGH);
//  analogWrite(enA, 90); 
//  analogWrite(enB, 110);
//  }
}

void forward ()
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, PWM); 
  analogWrite(enB, PWM);
}

void turn_left () 
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, PWM); 
  analogWrite(enB, PWM);
}

void turn_right () 
{
  digitalWrite(in1, LOW); 
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, PWM);
  analogWrite(enB, PWM);
}

void reverse ()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, PWM);
  analogWrite(enB, PWM);
}

void stop()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enA, LOW);
  analogWrite(enB, LOW);
}

long FrontSensor ()
{
  long dur;
  digitalWrite(trigPin1, LOW); 
  delayMicroseconds(5); 
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin1, LOW);
  dur = pulseIn(echoPin1, HIGH);
  return (dur* 0.034 / 2);
}

long RightSensor () 
{
  long dur;
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(5); 
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin2, LOW);
  dur = pulseIn(echoPin2, HIGH);
  return (dur* 0.034 / 2);
}

long LeftSensor ()    
{
  long dur;
  digitalWrite(trigPin3, LOW); 
  delayMicroseconds(5);
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);
  dur = pulseIn(echoPin3, HIGH);
  return (dur* 0.034 / 2);
}
