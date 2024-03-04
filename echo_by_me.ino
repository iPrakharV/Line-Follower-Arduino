const int pin1=8,pin2=9;
long waqt;
int dis;
 void setup() {
  pinMode(pin1,OUTPUT);
  pinMode(pin2,INPUT);
  Serial.begin(9600);

}

void loop() {

  digitalWrite(pin1,HIGH);
  
  digitalWrite(pin1,LOW);
  
  waqt=pulseIn(pin2,HIGH);
  dis=waqt*0.034/2;
  Serial.print("distance:");
  Serial.println(dis);
  delay(1000);
}
