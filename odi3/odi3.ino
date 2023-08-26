int Echo1 = 8;
int Trig1 = 7;
int Echo2 = 10;
int Trig2 = 9;
int Echo3 = 12;
int Trig3 = 11;

int in1 = 3;
int in2 = 4;
int in3 = 5;
int in4 = 6;
int ENA = 2;
int ENB = 13;

int ABS = 200;
int Left_Distance = 0, Right_Distance = 0, Middle_Distance = 0;

void _mForward(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(ENA, 130);
  analogWrite(ENB, 130);
  Serial.println("ROBOT_MOVING_FARWARD");
}

void _mBack(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(ENA, 130);
  analogWrite(ENB, 130);
  Serial.println("ROBOT_MOVING_BACKWARD");
}

void _mleft(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(ENA, 130);
  analogWrite(ENB, 130);
  Serial.println("ROBOT_MOVING_LEFT");
}

void _mright(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(ENA, 130);
  analogWrite(ENB, 130);
  Serial.println("ROBOT_MOVING_RIGHT");
}

void _mStop(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(ENA, LOW);
  analogWrite(ENB, LOW);
  Serial.println("ROBOT_STOP");
}

//Ultrasonic distance measurement:
int Left_Distance_test(){
  digitalWrite(Trig2, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig2, HIGH);
  delayMicroseconds(20);
  digitalWrite(Trig2, LOW);
  float Fdistance = pulseIn(Echo2, HIGH);
  delay(10);

  Fdistance = Fdistance / 29 / 2;
  return (int)Fdistance;
}

int Middle_Distance_test(){
  digitalWrite(Trig3, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig3, HIGH);
  delayMicroseconds(20);
  digitalWrite(Trig3, LOW);
  float Fdistance = pulseIn(Echo3, HIGH);
  delay(10);

  Fdistance = Fdistance / 29 / 2;
  return (int)Fdistance;
}

int Right_Distance_test(){
  digitalWrite(Trig1, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig1, HIGH);
  delayMicroseconds(20);
  digitalWrite(Trig1, LOW);
  float Fdistance = pulseIn(Echo1, HIGH);
  delay(10);

  Fdistance = Fdistance / 29 / 2;
  return (int)Fdistance;
}

void setup() {
  Serial.begin(9600);
  pinMode(Echo1, INPUT);
  pinMode(Trig1, OUTPUT);
  pinMode(Echo2, INPUT);
  pinMode(Trig2, OUTPUT);
  pinMode(Echo3, INPUT);
  pinMode(Trig3, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  _mStop();
}

void loop() {
  
  Left_Distance = Left_Distance_test();
  delay(10);
  Middle_Distance = Middle_Distance_test();
  delay(10);
  Right_Distance = Right_Distance_test();
  delay(10);

  if(Middle_Distance <= 20){
    if(Right_Distance > Left_Distance){
      if((Right_Distance <= 20) && (Left_Distance <= 20)){
        _mStop();
        delay(200);
        _mBack();
        delay(1000);
      }
      else{
        _mright();
        delay(500);
      }
      }
      else if(Right_Distance < Left_Distance){
        if((Right_Distance <= 20) && (Left_Distance <= 20)){
        _mStop();
        delay(200);
        _mBack();
        delay(1000);
      }
      else{
        _mleft();
        delay(500);
      }
    }
    }

    else if(Right_Distance <= 15){
      _mleft();
      delay(500);
    }

    else if(Left_Distance <= 15){
      _mright();
      delay(500);
    }

    else{
      _mForward();
    }
}
