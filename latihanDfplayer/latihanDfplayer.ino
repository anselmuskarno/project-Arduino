

#include <SoftwareSerial.h>    //memasukan library Software Serial
#include <DFPlayer_Mini_Mp3.h> //memasukan library DFPlayermini

SoftwareSerial mySerial(2, 3); //pin RX dan TX

void setup () { 
  Serial.begin (9600); //baud komunikasi pada 9600
  mp3_set_serial (Serial); 
  delay(5); 
  mp3_set_volume (90);
}

void loop () {   
  Serial.println("Memainkan lagu nomor 1");
mp3_play (1); //memainkan lagu 1 pada folder mp3 yang sudah direname dengan nama 0001.mp3
delay (10000); //jeda 10 detik

mp3_next (); //memainkan lagu 2 dengan mode next
Serial.println("Memainkan lagu nomor 2");
delay (10000);

mp3_play (3); //memainkan lagu 3
Serial.println("Memainkan lagu nomor 3");
delay (6000);
}
