void setup() {
  Serial.begin(9600);

}

void loop() {
  Serial.println("Berhasil");
  //baca data dari NodeMCU
  //sediakan variabel untuk menampung data
String data = "";
//selama data serial ada atau tersedia
while(Serial.available()>0){
  //ambil data kemudian masukan ke dalam variabel data
  data += char(Serial.read());
}
//tampilkan di serial monitor
Serial.println(data);
delay(500);
}
