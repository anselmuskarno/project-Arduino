int piezoPin = 5;

void setup() {

}//close setup

void loop() {

  /*Tone needs 2 arguments, but can take three
    1) Pin#
    2) Frequency - this is in hertz (cycles per second) which determines the pitch of the noise made
    3) Duration - how long teh tone plays
  */
   tone(piezoPin, 1000, 500);
  delay(1000);
  tone(piezoPin, 1000, 500);
  delay(1000);
  tone(piezoPin, 1000, 500);
  
delay(5000);
}
