#include "CTBot.h"
CTBot myBot;

String ssid = "lontemart";
String pass = "tidakada";
String token = "5897636923:AAEadUgThwvNq2D1JgltxmHNW_FTI-1Vas0";
const int id = 1026209843;

void setup() {
 Serial.begin(9600);
Serial.println("Starting TelegramBot...");
myBot.wifiConnect(ssid,pass);
myBot.setTelegramToken(token);

if(myBot.testConnection()){
  Serial.println("Koneksi Bagus");
} else {
  Serial.println("Koneksi Jelek");
}

myBot.sendMessage(id,"Hello User NodeMCU, yuk Belajar");
Serial.println("Pesan Terkirim");

}

void loop() {
if(myBot.testConnection()){
  Serial.println("Koneksi Bagus");
} else {
  Serial.println("Koneksi Jelek");
}
myBot.sendMessage(id,"okmbaik");
}
