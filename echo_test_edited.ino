const int trigpin0 = A0;
const int echopin0 = A1;
const int trigpin1 = A2;
const int echopin1 = A3;
const int trigpin2 = A4;
const int echopin2 = A5;
const int in1 = 3;
const int in2 = 4;
const int in3 = 5;
const int in4 = 6;
const int enA = 2;
const int enB = 7;
long duration0, duration1, duration2;
int d0, d1, d2;
void setup() {
  pinMode(trigpin0, OUTPUT);
  pinMode(echopin0, INPUT);
  pinMode(trigpin1, OUTPUT);
  pinMode(echopin1, INPUT);
  pinMode(trigpin2, OUTPUT);
  pinMode(echopin2, INPUT);
  Serial.begin(9600);

}

void loop() {
  digitalWrite(trigpin0, LOW);
  digitalWrite(trigpin0, HIGH);
  delay(10);
  digitalWrite(trigpin0, LOW);
  duration0 = pulseIn(echopin0, HIGH);
  d0 = duration0 * 0.034 / 2;
  Serial.println(d0);
  
  digitalWrite(trigpin1, LOW);
  digitalWrite(trigpin1, HIGH);
  delay(10);
  digitalWrite(trigpin1, LOW);
  duration1 = pulseIn(echopin1, HIGH);
  d1 = duration1 * 0.034 / 2;
  Serial.println(d1);
  
  digitalWrite(trigpin2, LOW);
  digitalWrite(trigpin2, HIGH);
  delay(10);
  digitalWrite(trigpin2, LOW);
  Serial.println(d2);
  Serial.println();

}


void forward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 150);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 150);

}
void right() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 120);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 120);

}
void left() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 120);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 120);
}
void stop1() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 0);

}


