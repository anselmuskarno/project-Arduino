float suhu;
float dingin,hangat,panas;
float pwm;
float Lambat,Sedang,Cepat;
unsigned char suhuDingin(){
  if (suhu <= 35){dingin =1;}
  else if (suhu >=35 && suhu <=45){dingin=(45-suhu)/15;}
  else if (suhu >= 45){dingin =0;}
  return dingin;
}
unsigned char suhuHangat(){
  if (suhu <= 35){hangat =0;}
  else if (suhu >=35 && suhu <=45){hangat=(suhu-35)/15;}
  else if (suhu >=45 && suhu <=60){hangat=(60-suhu)/15;}
  else if (suhu >= 60){hangat =0;}
  return hangat;
}
unsigned char suhuPanas (){
  if (suhu <=45 ){panas =0;}
  else if (suhu >=45 && suhu <=60){panas=(suhu-45)/15;}
  else if (suhu >= 60){panas =1;}
  return panas;
}

void fuzzifikasi(){
  suhuDingin();
  suhuHangat();
  suhuPanas();
}
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
suhu = 54; // contoh kita memasukan nilai suhu 54 derajat
pwm = 104; // contoh kita memasukan nilai pwm 104
fuzzifikasi(); // memanggil fungsi fuzzifikasi untuk menghitung keanggotaan masing2 variable
Serial.print("dingin : ");
Serial.print(dingin);
Serial.print("t");
Serial.print("hangat : ");
Serial.print(hangat);
Serial.print("t");
Serial.print("panas : ");
Serial.println(panas);
}
void loop() {
  // put your main code here, to run repeatedly:
}
