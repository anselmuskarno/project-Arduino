const int sensor = 12;
const int sensor2 = 13;
#define enA 9
#define in1 4
#define in2 5
#define enB 10
#define in3 6
#define in4 7
int motorSpeedA = 0;
int motorSpeedB = 0;

void setup() {

 pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

pinMode(sensor, INPUT);
pinMode(sensor2, INPUT);
Serial.begin(9600);
}

void loop() {
  int TCRTpin = digitalRead(sensor);
  int TCRTpin2 = digitalRead(sensor2);
  if (TCRTpin == LOW && TCRTpin2 == HIGH){
  Serial.println("Sensor 1 Terdeteksi");

motorSpeedA = 0; 
    motorSpeedB = 255; 
    analogWrite(enA, motorSpeedA); // Send PWM signal to motor A
    analogWrite(enB, motorSpeedB); // Send PWM signal to motor B
    // Set Motor A backward
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    // Set Motor B backward
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);

  
  } else if (TCRTpin == HIGH && TCRTpin2 == LOW){
  Serial.println("Sensor 2 Terdeteksi");

motorSpeedA = 255; 
    motorSpeedB = 0; 
    analogWrite(enA, motorSpeedA); // Send PWM signal to motor A
    analogWrite(enB, motorSpeedB); // Send PWM signal to motor B
    // Set Motor A backward
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    // Set Motor B backward
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);

  
} else if (TCRTpin == LOW && TCRTpin2 == LOW){
  Serial.println("2 sensor");
  motorSpeedA = 255; 
    motorSpeedB = 255; 
    analogWrite(enA, motorSpeedA); // Send PWM signal to motor A
    analogWrite(enB, motorSpeedB); // Send PWM signal to motor B
    // Set Motor A backward
    digitalWrite(in1, HIGH);
        digitalWrite(in3, HIGH);
    digitalWrite(in2, LOW);
    // Set Motor B backward

    digitalWrite(in4, LOW);
  }
else{
  Serial.println("Tidak Terdeteksi");
  motorSpeedA = 0; 
    motorSpeedB = 0; 
 analogWrite(enA, motorSpeedA); // Send PWM signal to motor A
    analogWrite(enB, motorSpeedB); // Send PWM signal to motor B
    // Set Motor A backward
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    // Set Motor B backward
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
}

}
