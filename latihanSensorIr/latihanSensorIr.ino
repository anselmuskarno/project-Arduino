//A = 2
//B1 = 3
//B2 = 4
//C = 6


int blockAPin = 2; // Pin input
int blockA = HIGH; // diberi logika high yang berarti tidak ada halangan

void setup() {

 pinMode(blockAPin, INPUT);
 Serial.begin(9600);

}



void loop() {
  
 blockA = digitalRead(blockAPin);
 if (blockA == LOW) {

//  delay(1000);
 Serial.println("ada benda didepan!!");

 } else if (blockA == HIGH) {
  
   
  
 Serial.println("didepan kosong");
// digitalWrite(LED, LOW);
//  delay(500);
  
 }
 delay(1000);
}
