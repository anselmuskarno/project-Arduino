const int relay = 21;

void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);
pinMode(relay,OUTPUT);
//pinMode(relay2,OUTPUT);
Serial.println("loading");
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(relay, LOW);
Serial.println("LOW");
delay(3000);
digitalWrite(relay, HIGH);
Serial.println("HIGH");
delay(1000);
}
