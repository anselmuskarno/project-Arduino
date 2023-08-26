
#define motorkif 5  //motor kiri maju
#define motorkib 18  //motor kiri mundur
#define motorkaf 19  //motor kanan maju
#define motorkab 23  //motor kanan mundur
int parameter=0;

void setup() {
  Serial.begin(9600);
//Menentukan mode untuk masing-masing pin
pinMode(motorkif,OUTPUT);
pinMode(motorkib,OUTPUT);
pinMode(motorkaf,OUTPUT);
pinMode(motorkab,OUTPUT);
pinMode(25,INPUT);
pinMode(14,INPUT);
pinMode(12,INPUT);
}
int nilai = 0;
int bacaA=0;
int bacaB=0;
int bacaC=0;
int bacaD=0;
int bacaE=0;

void loop() {

int A=digitalRead(2); 
int B=digitalRead(15); 
int C=digitalRead(22); 
int D=digitalRead(21); 
int E=digitalRead(4); 
 
int sensorki=digitalRead(3); //baca sensor kiri
int sensorkiA=digitalRead(4); //baca sensor kiri
int sensorta=digitalRead(8); //baca sensor kanan
int sensorkaA=digitalRead(6); //baca sensor kanan
int sensorka=digitalRead(7); //baca sensor kanan

Serial.print("A : ");Serial.println(sensorki);
Serial.print("B : ");Serial.println(sensorkiA);
Serial.print("C : ");Serial.println(sensorta);
Serial.print("D : ");Serial.println(sensorkaA);
Serial.print("E : ");Serial.println(sensorka);
delay(1000);
//
//if(A==1){
//  bacaA = 1;
//}
//if(B==1){
//  bacaB = 1;
//}
//if(C==1){
//  bacaC = 1;
//}
//if(D==1){
//  bacaD = 1;
//}
//if(E==1){
//  bacaA = 0;
//   bacaB = 0;
//    bacaC = 0;
//     bacaD = 0;
//      bacaE = 0;
//}
//
//Serial.print("Meja A : ");Serial.println(bacaA);
//Serial.print("Meja B : ");Serial.println(bacaB);
//Serial.print("Meja C : ");Serial.println(bacaC);
//Serial.print("Meja D : ");Serial.println(bacaD);
//
//if(bacaA != 1 || bacaB != 1 || bacaC != 1 || bacaD != 1 ){
//  digitalWrite(motorkaf,HIGH);
//digitalWrite(motorkab,HIGH);
//digitalWrite(motorkif,HIGH);
//digitalWrite(motorkib,HIGH); 
//}
//
//while(bacaA == 1){
//  
//int A=digitalRead(2); 
//int B=digitalRead(15); 
//int C=digitalRead(22); 
//int D=digitalRead(21); 
//int E=digitalRead(4); 
// 
//int sensorki=digitalRead(12); //baca sensor kiri
//int sensorkiA=digitalRead(27); //baca sensor kiri
//int sensorta=digitalRead(14); //baca sensor kanan
//int sensorkaA=digitalRead(25); //baca sensor kanan
//int sensorka=digitalRead(13); //baca sensor kanan
//
//if(A==1){
//  bacaA = 1;
//}
//if(B==1){
//  bacaB = 1;
//}
//if(C==1){
//  bacaC = 1;
//}
//if(D==1){
//  bacaD = 1;
//}
//if(E==1){
//  bacaA = 0;
//   bacaB = 0;
//    bacaC = 0;
//     bacaD = 0;
//      bacaE = 0;
//}
//  Serial.println("Kondisi ke 1");
//    if((sensorki==1) && (sensorkiA==1) && (sensorka==1) && (sensorkaA==1)&& (sensorta==1)){
//          Serial.println("Belok Kanan");
////sensor kanan mendeteksi garis hitam
////belok kanan
//digitalWrite(motorkaf,LOW);
//digitalWrite(motorkab,HIGH);
//digitalWrite(motorkif,HIGH);
//digitalWrite(motorkib,LOW); 
//      } else if((sensorki==HIGH) && (sensorka==LOW) && (sensorkaA==LOW)&& (sensorta==LOW) || 
//(sensorki==HIGH) && (sensorka==LOW) && (sensorkaA==LOW)&& (sensorta==HIGH) || 
//(sensorki==HIGH) && (sensorka==LOW) && (sensorkaA==HIGH)&& (sensorta==HIGH))
//{
//   Serial.println("Belok Kiri");
////sensor kiri mendeteksi garis hitam
////belok kiri
//digitalWrite(motorkaf,HIGH);
//digitalWrite(motorkab,LOW);
//digitalWrite(motorkif,LOW);
//digitalWrite(motorkib,HIGH);
//} else  if((sensorkiA==1) && (sensorkaA==1) && (sensorta==1)||(sensorkiA==HIGH) && (sensorkaA==LOW) && (sensorta==HIGH) ||
//(sensorkiA==HIGH) && (sensorkaA==LOW) && (sensorta==LOW) || (sensorkiA==LOW) && (sensorkaA==LOW) && (sensorta==HIGH))
//      {
//        Serial.println("Maju");
//      //kedua sensor tidak mengenai garis hitam
//      //gerak maju
//      digitalWrite(motorkaf,HIGH);
//      digitalWrite(motorkab,LOW);
//      digitalWrite(motorkif,HIGH);
//      digitalWrite(motorkib,LOW);
//      } 
// 
//}


}
