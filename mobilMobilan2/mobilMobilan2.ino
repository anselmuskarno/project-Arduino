#define m1 3
#define m2 5
#define m3 9
#define m4 10

int arrow =0;
void setup() {

pinMode(m1,OUTPUT);
pinMode(m2,OUTPUT);
pinMode(m3,OUTPUT);
pinMode(m4,OUTPUT);
pinMode(12,INPUT);
pinMode(13,INPUT);

}

void loop() {

//int lsensor=digitalRead(1);
//int rsensor=digitalRead(2);
int lsensor=digitalRead(A3);
int rsensor=digitalRead(A4);
//int lsensor=digitalRead(5);

if((lsensor == LOW)&&(rsensor== HIGH))
{
motorOut(100,100,2);
}
if((lsensor== HIGH)&&(rsensor== LOW))
{
//belok kiri
motorOut(0,100,2);

}

if((lsensor==HIGH)&&(rsensor== HIGH))
{
motorOut(0,100,2);

//belok kiri

}
if((lsensor== LOW)&&(rsensor==LOW))
{
//belok kanan
motorOut(100,0,2);
}
}

//Fungsi untuk menggerakkan motor
void motorOut(unsigned char lpwm, unsigned char rpwm, int arrow){
//arrow =1 mundur, 2 maju,
if(arrow==1){
digitalWrite(m3,HIGH);
digitalWrite(m1,LOW);
analogWrite(m4,255-lpwm);
analogWrite(m2,rpwm);
}
else if (arrow==2)
{
digitalWrite(m3,LOW);
digitalWrite(m1,HIGH);
analogWrite(m4,lpwm);
analogWrite(m2,255-rpwm);
}
}
