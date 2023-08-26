
void setup() {
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  if (sensorValue > 70)

  {
    digitalWrite(8, HIGH);
    //  delay(1000);
  }
  else {
    digitalWrite(8, LOW);
    //  delay(1000);
  }
  delay(10);
}
