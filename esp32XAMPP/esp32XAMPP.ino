#include "WiFi.h"
#include "HTTPClient.h"

const char* ssid = "TEACHER";
const char* password = "passwordbaru";

const char* host = "192.168.1.4"; // Diganti alamat hosting

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  Serial.println("Connecting ....");
  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }
  Serial.println("Connected.");
}

void loop() {
  int suhu = 11;
  WiFiClient client;
  const int httpPort = 80;
  if(!client.connect(host, httpPort)){
    Serial.println("Connection Failed.");
    return;
  }

String Link;
HTTPClient http;
Link = "http://"+String(host)+ "/multisensor/kirimdata.php?suhu="+String(suhu);
http.begin(Link);
http.GET();
String respon = http.getString();
Serial.println(respon);
http.end();

  delay(1000);

}
