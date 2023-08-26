
const int relay1 = 9;
void setup() {
pinMode(relay1,OUTPUT);
Serial.begin(9600);
}

void loop() {
  
digitalWrite(relay1, LOW);
delay(6000);
digitalWrite(relay1, HIGH);
delay(7000);
}
