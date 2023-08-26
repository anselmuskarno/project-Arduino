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

forward();
if (SensorKiri() < 4 ){
  turn_right();
//  delay(200);
}
//else if (SensorKiri() < 4 ){
//  turn_left();
////  delay(200);
//}
//else
if (SensorTengah() < 4 ){
    reverse();
    delay(500);
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
