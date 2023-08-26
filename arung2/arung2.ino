
//tengah
const int trigPin = 19; 
const int echoPin = 21;

const int in1 = 26;
const int in2 = 25;
const int in3 = 33;
const int in4 = 32;
const int enA = 18;
const int enB = 5;

#define PWM 200
#define DIS 15

void setup() 
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
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
  Serial.println("Sensor =");
  Serial.println(FrontSensor());
  
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
