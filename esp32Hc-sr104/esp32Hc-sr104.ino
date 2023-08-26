const int trigPinSensor1 = 2;
const int echoPinSensor1 = 4;
const int trigPinSensor2 = 5;
const int echoPinSensor2 = 18;
const int trigPinSensor3 = 19;
const int echoPinSensor3 = 21;
const int trigPinSensor4 = 13;
const int echoPinSensor4 = 12;
const int trigPinSensor5 = 27;
const int echoPinSensor5 = 26;

//define sound speed in cm/uS
#define SOUND_SPEED 0.034
#define CM_TO_INCH 0.393701

long durationSensor1;
float distanceCmSensor1;
long durationSensor2;
float distanceCmSensor2;
long durationSensor3;
float distanceCmSensor3;
long durationSensor4;
float distanceCmSensor4;
long durationSensor5;
float distanceCmSensor5;

float distanceInch;

void setup() {
  Serial.begin(9600); // Kecepatan Transfer data
  pinMode(trigPinSensor1, OUTPUT); // Menjadikan pin triger sensor 1 sebagai OUTPUT
  pinMode(echoPinSensor1, INPUT); // Sets the echoPinSensor1 as an Input
    pinMode(trigPinSensor2, OUTPUT); // Sets the trigPinSensor1 as an Output
  pinMode(echoPinSensor2, INPUT); // Sets the echoPinSensor1 as an Input
    pinMode(trigPinSensor3, OUTPUT); // Sets the trigPinSensor1 as an Output
  pinMode(echoPinSensor3, INPUT); // Sets the echoPinSensor1 as an Input
    pinMode(trigPinSensor4, OUTPUT); // Sets the trigPinSensor1 as an Output
  pinMode(echoPinSensor4, INPUT); // Sets the echoPinSensor1 as an Input
    pinMode(trigPinSensor5, OUTPUT); // Sets the trigPinSensor1 as an Output
  pinMode(echoPinSensor5, INPUT); // Sets the echoPinSensor1 as an Input
}

void loop() {
//  =====================SENSOR 1============================
  // Clears the trigPinSensor1
  digitalWrite(trigPinSensor1, LOW);
  delayMicroseconds(2);
  // Sets the trigPinSensor1 on HIGH state for 10 micro seconds
  digitalWrite(trigPinSensor1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinSensor1, LOW);
  
  // Reads the echoPinSensor1, returns the sound wave travel time in microseconds
  durationSensor1 = pulseIn(echoPinSensor1, HIGH);
  
  // Calculate the distance
  distanceCmSensor1 = durationSensor1 * SOUND_SPEED/2;
  
  // Prints the distance in the Serial Monitor
  Serial.print("Jarak Sensor 1 (cm): ");
  Serial.println(distanceCmSensor1);

  //  =====================SENSOR 2============================
  // Clears the trigPinSensor2
  digitalWrite(trigPinSensor2, LOW);
  delayMicroseconds(2);
  // Sets the trigPinSensor1 on HIGH state for 10 micro seconds
  digitalWrite(trigPinSensor2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinSensor2, LOW);
  
  // Reads the echoPinSensor1, returns the sound wave travel time in microseconds
  durationSensor2 = pulseIn(echoPinSensor2, HIGH);
  
  // Calculate the distance
  distanceCmSensor2 = durationSensor2 * SOUND_SPEED/2;
  
  // Prints the distance in the Serial Monitor
  Serial.print("Jarak Sensor 2 (cm): ");
  Serial.println(distanceCmSensor2);

//  =====================SENSOR 3============================
  // Clears the trigPinSensor1
  digitalWrite(trigPinSensor3, LOW);
  delayMicroseconds(2);
  // Sets the trigPinSensor1 on HIGH state for 10 micro seconds
  digitalWrite(trigPinSensor3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinSensor3, LOW);
  
  // Reads the echoPinSensor1, returns the sound wave travel time in microseconds
  durationSensor3 = pulseIn(echoPinSensor3, HIGH);
  
  // Calculate the distance
  distanceCmSensor3 = durationSensor3 * SOUND_SPEED/2;
  
  // Prints the distance in the Serial Monitor
  Serial.print("Jarak Sensor 3 (cm): ");
  Serial.println(distanceCmSensor3);

//  =====================SENSOR 4============================
  // Clears the trigPinSensor1
  digitalWrite(trigPinSensor4, LOW);
  delayMicroseconds(2);
  // Sets the trigPinSensor1 on HIGH state for 10 micro seconds
  digitalWrite(trigPinSensor4, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinSensor4, LOW);
  
  // Reads the echoPinSensor1, returns the sound wave travel time in microseconds
  durationSensor4 = pulseIn(echoPinSensor4, HIGH);
  
  // Calculate the distance
  distanceCmSensor4 = durationSensor4 * SOUND_SPEED/2;
  
  // Prints the distance in the Serial Monitor
  Serial.print("Jarak Sensor 4 (cm): ");
  Serial.println(distanceCmSensor4);

//  =====================SENSOR 5============================
  // Clears the trigPinSensor1
  digitalWrite(trigPinSensor5, LOW);
  delayMicroseconds(2);
  // Sets the trigPinSensor1 on HIGH state for 10 micro seconds
  digitalWrite(trigPinSensor5, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinSensor5, LOW);
  
  // Reads the echoPinSensor1, returns the sound wave travel time in microseconds
  durationSensor5 = pulseIn(echoPinSensor5, HIGH);
  
  // Calculate the distance
  distanceCmSensor5 = durationSensor5 * SOUND_SPEED/2;
  
  // Prints the distance in the Serial Monitor
  Serial.print("Jarak Sensor 5 (cm): ");
  Serial.println(distanceCmSensor5);

if(distanceCmSensor1 < 10){
  Serial.println("Tempat sampah 1 PENUH");
}
  
  delay(1000);
}
