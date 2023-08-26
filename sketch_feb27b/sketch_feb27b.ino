//MEGA

const int relay = 21;
#define motorkif 5  //motor kiri maju
#define motorkib 18  //motor kiri mundur
#define motorkaf 19  //motor kanan maju
#define motorkab 23  //motor kanan mundur
int parameter = 0;
String data;
void setup() {
  // put your setup code here, to run once:
  Serial2.begin(9600);
  Serial.begin(9600);
  pinMode(motorkif, OUTPUT);
  pinMode(motorkib, OUTPUT);
  pinMode(motorkaf, OUTPUT);
  pinMode(motorkab, OUTPUT);
  pinMode(relay, OUTPUT);
}
void loop() {
  String ancis = "";
  while (Serial2.available() > 0) {
    ancis += char(Serial2.read());
  }
  int A = digitalRead(2);
  int B = digitalRead(15);
  int C = digitalRead(22);
  int D = digitalRead(4);
  int E = digitalRead(14);

  //Serial.print("A : ");Serial.println(A);
  //Serial.print("B : ");Serial.println(B);
  //Serial.print("C : ");Serial.println(C);
  //Serial.print("D : ");Serial.println(D);
  //Serial.print("E : ");Serial.println(E);Serial.println();
  //delay(1000);


  Serial.println(ancis);
  while (A == 1) {
    Serial2.println("1");
    digitalWrite(relay, LOW);
    int A = digitalRead(2);
    int B = digitalRead(15);
    int C = digitalRead(22);
    int D = digitalRead(4);
    int E = digitalRead(27);
    String ancis = "";
    while (Serial2.available() > 0) {
      ancis += char(Serial2.read());
    }
    //Serial.println("Meja A");

    if (ancis == "f") {
      Serial.println("Serial2 Mati");
      digitalWrite(motorkaf, HIGH);
      digitalWrite(motorkab, HIGH);
      digitalWrite(motorkif, HIGH);
      digitalWrite(motorkib, HIGH);
      delay(2000);
    } else if (ancis == "a") {
      Serial.println("Serial2 Mati");
      //sensor kanan mendeteksi garis hitam
      //belok kanan
      digitalWrite(motorkaf, HIGH);
      digitalWrite(motorkab, HIGH);
      digitalWrite(motorkif, HIGH);
      digitalWrite(motorkib, HIGH);
      delay(5000);
      digitalWrite(motorkaf, LOW);
      digitalWrite(motorkab, HIGH);
      digitalWrite(motorkif, LOW);
      digitalWrite(motorkib, HIGH);
      delay(500);

      String ancis = "";
      while (Serial2.available() > 0) {
        ancis += char(Serial2.read());
      }

      for (int i = 1; ancis != "a"; i++) {
        while (Serial2.available() > 0) {
          ancis += char(Serial2.read());
        }
        digitalWrite(motorkaf, HIGH);
        digitalWrite(motorkab, LOW);
        digitalWrite(motorkif, LOW);
        digitalWrite(motorkib, HIGH);
        delay(1000);
      }
    }
    else if (ancis == "b") {
      Serial.println("Serial2 Lurus");
      //sensor kanan mendeteksi garis hitam
      //belok kanan
      digitalWrite(motorkaf, LOW);
      digitalWrite(motorkab, HIGH);
      digitalWrite(motorkif, HIGH);
      digitalWrite(motorkib, LOW);
      delay(500);
      digitalWrite(motorkaf, HIGH);
      digitalWrite(motorkab, LOW);
      digitalWrite(motorkif, HIGH);
      digitalWrite(motorkib, LOW);
      delay(500);
    }
    else if (ancis == "c")
    {
      Serial.println("Belok KANAN");
      //sensor kiri mendeteksi garis hitam
      //belok kiri
      digitalWrite(motorkaf, LOW);
      digitalWrite(motorkab, HIGH);
      digitalWrite(motorkif, HIGH);
      digitalWrite(motorkib, LOW);
    }
    else if (ancis == "d")
    {
      Serial.println("Belok KIRI");
      //sensor kiri mendeteksi garis hitam
      //belok kiri
      digitalWrite(motorkaf, HIGH);
      digitalWrite(motorkab, LOW);
      digitalWrite(motorkif, LOW);
      digitalWrite(motorkib, HIGH);
    }
    else  if (ancis == "e")
    {
      Serial.println("Serial2 Maju");
      //kedua sensor tidak mengenai garis hitam
      //gerak maju
      digitalWrite(motorkaf, HIGH);
      digitalWrite(motorkab, LOW);
      digitalWrite(motorkif, HIGH);
      digitalWrite(motorkib, LOW);
    }

  }

  while (B == 1) {
    int A = digitalRead(2);
    int B = digitalRead(15);
    int C = digitalRead(22);
    int D = digitalRead(4);
    int E = digitalRead(27);
    String ancis = "";
    while (Serial2.available() > 0) {
      ancis += char(Serial2.read());
    }
    //Serial.println("Meja A");
    if (ancis == "f") {
      digitalWrite(motorkaf, HIGH);
      digitalWrite(motorkab, HIGH);
      digitalWrite(motorkif, HIGH);
      digitalWrite(motorkib, HIGH);
      delay(2000);
    } else if (ancis == "a") {
      Serial.println("Serial2 Mati");
      //sensor kanan mendeteksi garis hitam
      //belok kanan
      digitalWrite(motorkaf, HIGH);
      digitalWrite(motorkab, HIGH);
      digitalWrite(motorkif, HIGH);
      digitalWrite(motorkib, HIGH);
    }

    else if (ancis == "b") {
      Serial.println("Serial2 Lurus");
      //sensor kanan mendeteksi garis hitam
      //belok kanan
      digitalWrite(motorkaf, HIGH);
      digitalWrite(motorkab, LOW);
      digitalWrite(motorkif, LOW);
      digitalWrite(motorkib, HIGH);
      delay(700);
      digitalWrite(motorkaf, HIGH);
      digitalWrite(motorkab, LOW);
      digitalWrite(motorkif, HIGH);
      digitalWrite(motorkib, LOW);
      delay(500);
    }
    else if (ancis == "c")
    {
      Serial.println("Belok KANAN");
      //sensor kiri mendeteksi garis hitam
      //belok kiri
      digitalWrite(motorkaf, LOW);
      digitalWrite(motorkab, HIGH);
      digitalWrite(motorkif, HIGH);
      digitalWrite(motorkib, LOW);
    }
    else if (ancis == "d")
    {
      Serial.println("Belok KIRI");
      //sensor kiri mendeteksi garis hitam
      //belok kiri
      digitalWrite(motorkaf, HIGH);
      digitalWrite(motorkab, LOW);
      digitalWrite(motorkif, LOW);
      digitalWrite(motorkib, HIGH);
    }
    else  if (ancis == "e")
    {
      Serial.println("Serial2 Maju");
      //kedua sensor tidak mengenai garis hitam
      //gerak maju
      digitalWrite(motorkaf, HIGH);
      digitalWrite(motorkab, LOW);
      digitalWrite(motorkif, HIGH);
      digitalWrite(motorkib, LOW);
    }

  }

  while (C == 1) {
    int A = digitalRead(2);
    int B = digitalRead(15);
    int C = digitalRead(22);
    int D = digitalRead(4);
    int E = digitalRead(27);
    String ancis = "";
    while (Serial2.available() > 0) {
      ancis += char(Serial2.read());
    }
    //Serial.println("Meja A");
    if (ancis == "f") {
      digitalWrite(motorkaf, HIGH);
      digitalWrite(motorkab, HIGH);
      digitalWrite(motorkif, HIGH);
      digitalWrite(motorkib, HIGH);
      delay(2000);
    } else if (ancis == "a") {
      Serial.println("Serial2 Mati");
      //sensor kanan mendeteksi garis hitam
      //belok kanan
      digitalWrite(motorkaf, HIGH);
      digitalWrite(motorkab, HIGH);
      digitalWrite(motorkif, HIGH);
      digitalWrite(motorkib, HIGH);
    }

    else if (ancis == "b" && parameter == 1) {
      Serial.println("Serial2 Lurus");
      //sensor kanan mendeteksi garis hitam
      //belok kanan
      digitalWrite(motorkaf, LOW);
      digitalWrite(motorkab, HIGH);
      digitalWrite(motorkif, HIGH);
      digitalWrite(motorkib, LOW);
      delay(500);
      digitalWrite(motorkaf, HIGH);
      digitalWrite(motorkab, LOW);
      digitalWrite(motorkif, HIGH);
      digitalWrite(motorkib, LOW);
      delay(500);
    } else if (ancis == "b" && parameter == 0) {
      parameter = 1;
      Serial.println("Serial2 Lurus");
      //sensor kanan mendeteksi garis hitam
      //belok kanan

      digitalWrite(motorkaf, HIGH);
      digitalWrite(motorkab, LOW);
      digitalWrite(motorkif, HIGH);
      digitalWrite(motorkib, LOW);
      delay(500);
    }
    else if (ancis == "c")
    {
      Serial.println("Belok KANAN");
      //sensor kiri mendeteksi garis hitam
      //belok kiri
      digitalWrite(motorkaf, LOW);
      digitalWrite(motorkab, HIGH);
      digitalWrite(motorkif, HIGH);
      digitalWrite(motorkib, LOW);
    }
    else if (ancis == "d")
    {
      Serial.println("Belok KIRI");
      //sensor kiri mendeteksi garis hitam
      //belok kiri
      digitalWrite(motorkaf, HIGH);
      digitalWrite(motorkab, LOW);
      digitalWrite(motorkif, LOW);
      digitalWrite(motorkib, HIGH);
    }
    else  if (ancis == "e")
    {
      Serial.println("Serial2 Maju");
      //kedua sensor tidak mengenai garis hitam
      //gerak maju
      digitalWrite(motorkaf, HIGH);
      digitalWrite(motorkab, LOW);
      digitalWrite(motorkif, HIGH);
      digitalWrite(motorkib, LOW);
    }

  }

  while (D == 1) {
    int A = digitalRead(2);
    int B = digitalRead(15);
    int C = digitalRead(22);
    int D = digitalRead(4);
    int E = digitalRead(27);
    String ancis = "";
    while (Serial2.available() > 0) {
      ancis += char(Serial2.read());
    }
    //Serial.println("Meja A");
    if (ancis == "f") {
      digitalWrite(motorkaf, HIGH);
      digitalWrite(motorkab, HIGH);
      digitalWrite(motorkif, HIGH);
      digitalWrite(motorkib, HIGH);
      delay(2000);
    } else if (ancis == "a") {
      Serial.println("Serial2 Mati");
      //sensor kanan mendeteksi garis hitam
      //belok kanan
      digitalWrite(motorkaf, HIGH);
      digitalWrite(motorkab, HIGH);
      digitalWrite(motorkif, HIGH);
      digitalWrite(motorkib, HIGH);

    }


    else if (ancis == "b" && parameter == 1) {
      Serial.println("Serial2 Lurus");
      //sensor kanan mendeteksi garis hitam
      //belok kanan
      digitalWrite(motorkaf, HIGH);
      digitalWrite(motorkab, LOW);
      digitalWrite(motorkif, LOW);
      digitalWrite(motorkib, HIGH);
      delay(700);
      digitalWrite(motorkaf, HIGH);
      digitalWrite(motorkab, LOW);
      digitalWrite(motorkif, HIGH);
      digitalWrite(motorkib, LOW);
      delay(500);
    } else if (ancis == "b" && parameter == 0) {
      parameter = 1;
      Serial.println("Serial2 Lurus");
      //sensor kanan mendeteksi garis hitam
      //belok kanan

      digitalWrite(motorkaf, HIGH);
      digitalWrite(motorkab, LOW);
      digitalWrite(motorkif, HIGH);
      digitalWrite(motorkib, LOW);
      delay(500);
    }
    else if (ancis == "c")
    {
      Serial.println("Belok KANAN");
      //sensor kiri mendeteksi garis hitam
      //belok kiri
      digitalWrite(motorkaf, LOW);
      digitalWrite(motorkab, HIGH);
      digitalWrite(motorkif, HIGH);
      digitalWrite(motorkib, LOW);
    }
    else if (ancis == "d")
    {
      Serial.println("Belok KIRI");
      //sensor kiri mendeteksi garis hitam
      //belok kiri
      digitalWrite(motorkaf, HIGH);
      digitalWrite(motorkab, LOW);
      digitalWrite(motorkif, LOW);
      digitalWrite(motorkib, HIGH);
    }
    else  if (ancis == "e")
    {
      Serial.println("Serial2 Maju");
      //kedua sensor tidak mengenai garis hitam
      //gerak maju
      digitalWrite(motorkaf, HIGH);
      digitalWrite(motorkab, LOW);
      digitalWrite(motorkif, HIGH);
      digitalWrite(motorkib, LOW);
    }

  }
}
