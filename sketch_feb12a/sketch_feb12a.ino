#include "SIM900.h"
#include <SoftwareSerial.h>
#include "sms.h"
SMSGSM sms;
boolean started=false;

void setup() {
  Serial.begin(9600);
  Serial.println("Mona Ok");

  if (gsm.begin(2400)){
    Serial.println("\nstatus=READY");
    started=true;  
  }
  else Serial.println("\nstatus=IDLE");
  
  if(started){
    if (sms.SendSMS("+6282192279025", "Halo BoArduino :)"))
      Serial.println("\nSMS sent OK");
  }
};

void loop() 
{
}
