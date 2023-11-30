int pinAlarm = 3;
int pinGetar = 2;

void setup(){
  Serial.begin(9600);
  pinMode(pinAlarm, OUTPUT);
  pinMode(pinGetar, INPUT);
}

void loop(){
  long nilaigetar =nilai();
  Serial.print(nilaigetar);
  if(nilaigetar == 00){
    Serial.println(nilaigetar);
    Serial.println("tidak ada getaran");
    digitalWrite(pinAlarm, LOW);
  }else if(nilaigetar > 5000){
    Serial.println(nilaigetar);
    Serial.println("getaran tinggi");
    digitalWrite(pinAlarm, HIGH);
  }
  delay(10);
  Serial.println("");
}

long nilai(){
  delay(100);
  long nilaigetar=pulseIn (pinGetar, HIGH);
  return nilaigetar;
}