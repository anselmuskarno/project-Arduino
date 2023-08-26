void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int A=digitalRead(2); 
int B=digitalRead(15); 
int C=digitalRead(22); 
int D=digitalRead(4); 
int E=digitalRead(14); 

Serial.print("A");Serial.println(A);
Serial.print("B");Serial.println(B);
Serial.print("C");Serial.println(C);
Serial.print("D");Serial.println(D);
Serial.print("E");Serial.println(E);
Serial.println("===================================================");
delay(500);

}
