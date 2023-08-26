
#define tombolDark 7 // kuning
#define tombolLight 8 // biru

void setup() {
Serial.begin(9600);
}

void loop(){

int tombolDarkDitekan = digitalRead(tombolDark);
int tombolLightDitekan = digitalRead(tombolLight);

if(tombolDarkDitekan == HIGH){
  Serial.println("Tombol dark HIGH");
 
  delay(2000);
 
} 

if(tombolLightDitekan == HIGH){
  Serial.println("Tombol Light HIGH");
 
  delay(2000);
 
} 

 
}
