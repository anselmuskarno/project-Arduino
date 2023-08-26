const int trigPin = 7;
const int echoPin = 6;

void setup() {
  Serial.begin(9600); 
}

long duration, cm;
 
void loop()
{
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  Serial.println(cm);
  cm = microsecondsKeCenti(duration);
  Serial.println();
}
long microsecondsKeCenti(long microseconds)
{
  return microseconds / 29 / 2;
}
