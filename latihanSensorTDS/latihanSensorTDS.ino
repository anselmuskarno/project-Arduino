const int sensorPin  = A0;
float Po                        = 0;  
void setup()
{ 
  pinMode (sensorPin, INPUT); 
  Serial.begin(9600);
}
void loop()
{
   int pengukuranPh = analogRead(sensorPin);
   Serial.print("Nilai ADC Ph: ");
   Serial.println(pengukuranPh);
   double TeganganPh = 5 / 1024.0 * pengukuranPh;
   Serial.print("TeganganPh: ");
   Serial.println(TeganganPh, 3);
      ///Po = 7.00 + ((teganganPh7 - TeganganPh) / PhStep);
   Po = 7.00 + ((2.6 - TeganganPh) / 0.17);
   Serial.print("Nilai PH cairan: ");
   Serial.println(Po, 3);

   delay(1000);

}
