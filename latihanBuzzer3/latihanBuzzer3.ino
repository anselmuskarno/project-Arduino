int pinBuzzer= 9;



void setup(){

pinMode(pinBuzzer, OUTPUT);

}



void loop(){

digitalWrite(pinBuzzer, HIGH);

delay(500);

digitalWrite(pinBuzzer, LOW);

delay(500);

}
