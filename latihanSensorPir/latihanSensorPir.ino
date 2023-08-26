const int relay3 = 8;
byte sensorPir = 7;
void setup() {
  pinMode(relay3,OUTPUT);
  pinMode(sensorPir, INPUT);
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(sensorPir) == HIGH)
{
  digitalWrite(relay3,LOW);
 Serial.println("Objek Terdeteksi"); 
} else {
  Serial.println("Objek Tidak Terdeteksi");
  digitalWrite(relay3,HIGH);
}

}
