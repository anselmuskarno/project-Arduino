const int GSR=A0;
int sensorValue=0;
int gsr_average=0;
void setup() {
 Serial.begin(9600);
}

void loop() {
  long sum=0;
  for(int i=0;i<10;i++){
    sensorValue=analogRead(GSR);
    sum += sensorValue;
    delay(5);
  }
  gsr_average = sum/10;
  Serial.print("Gsr average = ");
  Serial.println(gsr_average);
  int human_resistance = ((1024+2*gsr_average)*10000)/(516-gsr_average);
  Serial.print("human resistance = ");
  Serial.println(human_resistance);
}
