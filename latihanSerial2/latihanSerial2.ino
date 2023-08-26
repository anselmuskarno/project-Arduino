char userInput;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available()>0){
  userInput = Serial.read();
  if(userInput == '1'){
    Serial.println("Led Nyala");
  }
  else if(userInput == '0'){
    Serial.println("Led Mati");
  }
}
}
