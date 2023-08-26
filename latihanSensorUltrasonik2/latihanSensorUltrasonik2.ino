const int trigPin = A3;
const int echoPin = A2;

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
  cm = microsecondsKeCenti(duration);
  Serial.print(cm);
  Serial.print(" cm");
  Serial.println();
}
long microsecondsKeCenti(long microseconds)
{
  return microseconds / 29 / 2;
}
