static float kekeruhan;
static float teg;
void setup() {
 Serial.begin(9600);

}

void loop() {
int val = analogRead(A0);
teg = val*(5.0/1024);
kekeruhan = 100.00 - (teg/4.16)*100.00;
Serial.print(teg);
Serial.print("     ");
Serial.print("Nilai Adc = ");
Serial.print(val);
Serial.print("     ");
Serial.print("Nilai Kekeruhan = ");
Serial.print(kekeruhan);
Serial.println("   NTU");
delay(100);
}
