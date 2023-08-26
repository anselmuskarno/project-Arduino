void setup() {
  Serial.begin(9600);
 pinMode(A4, INPUT);//left sensor 1
 pinMode(A3, INPUT);//left sensor 2
 pinMode(A2, INPUT);//middle sensor 3
 pinMode(A1, INPUT);//right sensor 4
 pinMode(A0, INPUT);//right sensor 5
 pinMode(3, OUTPUT);//LEFT MOTOR: EN_A
 pinMode(1, OUTPUT);//IN_1
 pinMode(2, OUTPUT);//IN_2
 pinMode(6, OUTPUT);//RIGHT MOTOR : EN_B
 pinMode(5, OUTPUT);//IN_3
 pinMode(4, OUTPUT);//IN_4
}

void loop() {
  int a = digitalRead(A4);
  int b = digitalRead(A3);
  int c = digitalRead(A2);
  int d = digitalRead(A1);
  int e = digitalRead(A0);
if (
(a == HIGH && b == HIGH && c == LOW && d==HIGH && e== HIGH)||
(a == HIGH && b == LOW && c == LOW && d==LOW && e== HIGH)||
(a == LOW && b == LOW && c == LOW && d==LOW && e== LOW))//FORWARD

{
  Serial.println("Semua sensor LOW");
analogWrite(3, 110);
digitalWrite(2, HIGH);
digitalWrite(1, LOW);
analogWrite(6, 110);
digitalWrite(4, HIGH);
digitalWrite(5, LOW);
}
if ((a == HIGH && b == LOW && c == HIGH && d==HIGH && e==HIGH)) //LEFT TURN
{
    Serial.println("B Low");
analogWrite(3, 110);
digitalWrite(2, LOW);
digitalWrite(1, HIGH);
analogWrite(6, 110);
digitalWrite(4, HIGH);
digitalWrite(5, LOW);
}
if ((a==LOW && b== LOW && c==HIGH &&d==HIGH &&e==HIGH)||(a==LOW && b== LOW && c==LOW &&d== HIGH &&e==HIGH)||(a==LOW && b== HIGH &&
c==HIGH &&d== HIGH &&e==HIGH)||(a==HIGH && b== LOW && c==LOW &&d== HIGH &&e==HIGH)||(a==LOW &&b== LOW && c==LOW && d==LOW && e==HIGH)) //FULL LEFT TURN
{
  Serial.println("A dan B Low");
analogWrite(3, 110);
digitalWrite(2, LOW);
digitalWrite(1, HIGH);
analogWrite(6, 110);
digitalWrite(4, HIGH);
digitalWrite(5, LOW);
}
if ((a == HIGH && b == HIGH && c == HIGH && d==LOW && e==HIGH)) //RIGHT TURN
{
    Serial.println("D Low");
analogWrite(3, 110);
digitalWrite(2, HIGH);
digitalWrite(1, LOW);
analogWrite(6, 110);
digitalWrite(4, LOW);
digitalWrite(5, HIGH);
}
if ((a==HIGH && b== HIGH && c==HIGH &&d==LOW &&e==LOW)||(a==HIGH && b== HIGH && c==LOW &&d== LOW &&e==LOW)||(a==HIGH && b== HIGH &&
c==HIGH &&d== HIGH &&e==LOW)||(a==HIGH && b== LOW && c==LOW &&d== LOW &&e==LOW)||(a==HIGH &&
b== HIGH && c==LOW &&d== LOW &&e==HIGH) ) //FULL RIGHT TURN
{
    Serial.println("ABC High");
analogWrite(3, 110);
digitalWrite(2, HIGH);
digitalWrite(1, LOW);
analogWrite(6, 110);
digitalWrite(4, LOW);
digitalWrite(5, HIGH);
}
if (a == HIGH && b == HIGH && c == HIGH && d==HIGH && e== HIGH) // BACK
{
    Serial.println("Semua sensor HIGH");
analogWrite(3, 110);
digitalWrite(2, LOW);
digitalWrite(1, HIGH);
analogWrite(6, 110);
digitalWrite(4, LOW);
digitalWrite(5, HIGH);
}
}
