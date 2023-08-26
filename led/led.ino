// Menyalakan LED Menggunakan Arduino UNO
// Menyalakan LED dengan Aktif HIGH
int pin1 = 8;
int pin2 = 9;
int pin3 = 10;

void setup()
{
   // menjadikan PIN 4 sebagai OUTPUT
   pinMode(13, OUTPUT); 
    pinMode(pin1, OUTPUT); 
     pinMode(pin2, OUTPUT); 
      pinMode(pin3, OUTPUT); 
}
void loop()
{
   // Menyalakan PIN 4 (HIGH = Memberi tegangan pada PIN 4)
   digitalWrite(pin2, HIGH); 
   delay(2000);
    digitalWrite(pin2, LOW); 
    delay(2000);

 

}
