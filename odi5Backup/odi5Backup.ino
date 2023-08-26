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

#define PWM 85
#define DIS 2   //jarak

void setup() 
{
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  
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

    Serial.print("Sensor 1=");
  Serial.println(SensorKiri());
  Serial.print("Sensor 2=");
  Serial.println(SensorTengah());
  Serial.print("Sensor 3=");
  Serial.println(SensorKanan());   
//   if(SensorTengah() < 15 && SensorKiri() < 15 && SensorKanan() < 15){
//        reverse();
//     delay(400);
//   }
//   if(SensorTengah() < 15 && SensorKiri() < 10 && SensorKanan() > 10){
//        turn_left (); 
//    delay(300);
//   }
//  if(SensorTengah() < 15 && SensorKiri() > 10 && SensorKanan() < 10){
//        turn_right (); 
//    delay(300);
////    forward();
//   }
   
//   else 
   if (  SensorTengah() < 20 ) 
  {
    Serial.println("kondisi 3");
    stop(); 
    Serial.print("Sensor 1=");
  Serial.println(SensorKiri());
  Serial.print("Sensor 2=");
  Serial.println(SensorTengah());
  Serial.print("Sensor 3=");
  Serial.println(SensorKanan());   
//    delay(200);
//    forward();
    delay(100);
    
//    reverse();
//     delay(10);

if(SensorTengah() < 5){
  reverse();
//  delay(250);
//  turn_right (); 
//    delay(250);
  delay(500);
}

if(SensorKiri() > 20 && SensorKanan() > 20){
  reverse();
  delay(500);
}

   else if (  SensorKanan() < SensorKiri()) 
  { 
    Serial.println("kondisi 1");
    turn_right (); 
    delay(250);
    forward();
  } else  if (  SensorKiri() < SensorKanan()) 
  {  
    Serial.println("kondisi 2");
    turn_left (); 
    delay(250);
    forward();
    delay(500);
  }
  }  
   else if (  SensorKanan() < 11) 
  {
    Serial.println("kondisi 1");
    turn_right (); 
    delay(180);
    forward();
  } else  if (  SensorKiri() < 11) 
  {
    Serial.println("kondisi 2");
    turn_left (); 
    delay(200);
    forward();
//    delay(500);
  } else{
      forward(); 
  }
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

long SensorKiri ()
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

long SensorTengah () 
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

long SensorKanan ()    
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
