int data_random;
char userInput;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
userInput = Serial.read();
if(userInput=='1'){
Serial.println("coba");
delay(10000);  
}

}
