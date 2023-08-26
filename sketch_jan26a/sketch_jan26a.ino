
void setup()
{
   // menjadikan PIN 4 sebagai OUTPUT
   pinMode(8, OUTPUT); 
}
void loop()
{
   // Menyalakan PIN 4 (HIGH = Memberi tegangan pada PIN 4)
   digitalWrite(8, HIGH); //menyala 
   delay(3000); // waktu
   digitalWrite(8, LOW);
   delay(2000); 
}
