// Stepper Motor Nema17 dan Driver A4988
const int stepPin = 28; 
const int dirPin = 30;
const int stepPin2 = 39; 
const int dirPin2 = 37; 
void setup() {
  // put your setup code here, to run once:
   pinMode(stepPin,OUTPUT); 
    pinMode(dirPin,OUTPUT);

    pinMode(stepPin2,OUTPUT); 
    pinMode(dirPin2,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int x = 0; x < 900; x++) {         
       digitalWrite(stepPin,HIGH); 
       digitalWrite(stepPin2,HIGH); 
       delayMicroseconds(700); 
       digitalWrite(stepPin,LOW); 
       digitalWrite(stepPin2,LOW);
       delayMicroseconds(700);        
       } 

}
