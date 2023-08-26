const int relay = 7;
const int relay2 = 6;
const int relayHeater = 5;
const int LDR_a = A0;
int input_val_a = 0;
const int LDR_b = A1;
int input_val_b = 0;
const int LDR_c = A2;
int input_val_c = 0;

void setup()
{
  Serial.begin(9600);
        pinMode(relay, OUTPUT); //relay
    pinMode(relay2, OUTPUT); // relay2
      pinMode(relayHeater, OUTPUT); //relay heater
}

void loop()
{
//a (abu-abu hijau) = relay
//b (hijau hijau) = relay2
//c (kuning kuning) = relayHeater
  Serial.println("======================================================");
  input_val_a = analogRead(LDR_a);
  Serial.println(input_val_a);
   input_val_b = analogRead(LDR_b);
  Serial.println(input_val_b);
   input_val_c = analogRead(LDR_c);
  Serial.println(input_val_c);
if( input_val_a < 100 && input_val_b > 100 && input_val_c < 100){
  Serial.println("RELAY A");
    digitalWrite(relay, LOW); 
  digitalWrite(relay2, HIGH); 
  digitalWrite(relayHeater, HIGH);  
} 
else if(input_val_a > 100 && input_val_b < 100 && input_val_c < 100){
   Serial.println("RELAY B");
    digitalWrite(relay, HIGH); 
  digitalWrite(relay2, LOW); 
  digitalWrite(relayHeater, HIGH);  
} 
else if(input_val_a < 100 && input_val_b < 100 && input_val_c > 100){
   Serial.println("RELAY HEATER");
    digitalWrite(relay, HIGH); 
  digitalWrite(relay2, HIGH); 
  digitalWrite(relayHeater, LOW);  
} else if(input_val_a < 100 && input_val_b < 100 && input_val_c < 100){
   Serial.println("RELAY MATI");
    digitalWrite(relay, HIGH); 
  digitalWrite(relay2, HIGH); 
  digitalWrite(relayHeater, LOW);  
} 
delay(1000);
}
