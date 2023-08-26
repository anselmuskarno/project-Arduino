#include <ESP8266WiFi.h> //library wemos utk wifi
#include "HX711.h" // library loadcell

//inisialisasi jaringan
const char* ssid     = "Gigabyte";
const char* password = "qwerty123";
const char* host = "192.168.91.101";

//inisialisasi pin sensor load cell
#define DOUT  0 //D3 pada wemos dihubungkan pada DT loadcell
#define CLK  2 //D4 pada wemos dihubungkan ke CLK loadcell

HX711 scale;

float calibration_factor = 1000; //Hasil Kalibrasi
float units; // variabel untukj menampung berat
int id_pasien = 1; //1-4 pasien


void setup()
{
  Serial.begin(9600);// baudrate komunikasi serial
  
  //Proses koneksi ke jaringan
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.mode(WIFI_STA); // wemos sebagai station // client biasa
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  // proses koneksi loadcell
  scale.begin(DOUT, CLK);
  scale.set_scale();
  scale.tare();  //Reset the scale to 0

  long zero_factor = scale.read_average(); //Get a baseline reading
  Serial.print("Zero factor: "); //This can be used to remove the need to tare the scale. Useful in permanent scale projects.
  Serial.println(zero_factor);

  delay(10);
  
}

void baca_data(){
  scale.set_scale(calibration_factor); //Adjust to this calibration factor

  Serial.print("Reading: ");
  units = scale.get_units(), 1;
  if (units < 0)
  {
    units = 0.00;
  }
  Serial.print("Berat: ");
  Serial.print(units);
  Serial.print(" Gram");
  Serial.println();
  delay(1000);
  }


void kirim() {
  Serial.print("connecting to ");
  Serial.println(host);
  
  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }
  
  String url = "/monitor_infus/simpan.php?"; // alamat file PHP yang akan capture/ menangkap data yang dikirim kemudian menyimpan ke database
  url += "id=";
  url += id_pasien; //berat yang akan dikirim
  url += "&";
  url += "berat=";
  url += units; //berat yang akan dikirim
  url +="\r\n";
  
  Serial.print("Requesting URL: ");
  Serial.println(url);
  
  // This will send the request to the server 
  String pesan = "GET ";
         pesan += url;   
         pesan +="HTTP/1.1\r\n";
         pesan +="Host: ";
         pesan += host;
         pesan +="\r\n"; 
         pesan +="User-Agent: Arduino/1.0"; // alamat pengirim
         pesan +="Connection: close\r\n";
         pesan +="Content-Type: application/x-www-form-urlencoded;\r\n";
  client.print(pesan);

  unsigned long timeout = millis();
  while (client.available() == 0) {
    if (millis() - timeout > 1000) {
      Serial.println(">>> Client Timeout !");
      client.stop();
      return;
    }
  }
  
  // Read all the lines of the reply from server and print them to Serial
  while(client.available()){
    String line = client.readStringUntil('\r');
    Serial.print(line);
  } 
  Serial.println("closing connection");
}
void loop(){
  baca_data();
  kirim();
  delay(10000);// mengirim interval 10 detik

}
