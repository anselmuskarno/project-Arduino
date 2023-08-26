#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>

const char* ssid = "huawei";
const char* password = "123456789";
const char* host = "192.168.43.252";

#define PIN_LED 5

void setup() {
  Serial.begin(9600);

  WiFi.hostname("coba");
  WiFi.begin(ssid, password);

// selama wifinya tidak terkoneksi
  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(500);
  } 

// berhasil konek
Serial.println("Wifi Connected");
}

void loop() {
 int sensor = 1;
//cek koneksi ke server
WiFiClient client;
if(!client.connect(host, 80)){
  Serial.println("Connection Failed");
  return;
} else {
  Serial.println("Connection Success");
  return;
}

//pengiriman data ke server
String Link;
HTTPClient http;
Link = "http://localhost/websensor/kirimdata.php?data=" + String(sensor);

// eksekusi link
http.begin(Link);

 //mode GET
http.GET();
http.end();
 
delay(100);
}
