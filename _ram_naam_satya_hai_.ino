char t;
char sp;
 int usSpeed = 255;  //default motor speed
 int usSpeed1 = 80;
 
void setup() {
pinMode(9,OUTPUT);   //left motors forward
pinMode(10,OUTPUT);   //left motors reverse
pinMode(11,OUTPUT);   //right motors forward
pinMode(12,OUTPUT);   //right motors reverse
pinMode(6,OUTPUT); //enA
pinMode(7,OUTPUT); //enB

Serial.begin(9600);
 
}
 
void loop() {
if(Serial.available()){
  t = Serial.read();
  Serial.println(t);
}
/**if(Serial.available()){
  sp = Serial.read();
  Serial.println(sp);  
}
 */
if (t=='1')
usSpeed =50;
  
if (t=='2')
usSpeed =60;

if (t=='3')
usSpeed =75;

if (t=='4')
usSpeed =100;
 
 if (t=='5')
usSpeed =125;

if (t=='6')
usSpeed =140;

if (t=='7')
usSpeed =165;

if (t=='8')
usSpeed =190;

if (t=='9')
usSpeed =225;



if(t == 'B'){            //move backward(all motors rotate in forward direction)
  digitalWrite(7,usSpeed);
  digitalWrite(6,usSpeed);
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
  digitalWrite(11,HIGH);
  digitalWrite(12,LOW);
}
 
else if(t == 'F'){      //move forward (all motors rotate in reverse direction)
  digitalWrite(7,usSpeed);
  digitalWrite(6,usSpeed);
  digitalWrite(9,LOW);
  digitalWrite(10,HIGH);
  digitalWrite(11,LOW);
  digitalWrite(12,HIGH);
}
 
else if(t == 'R'){      //turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
  digitalWrite(7,usSpeed1);
  digitalWrite(6,usSpeed1);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,HIGH);
}
 
else if(t == 'L'){      //turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
  digitalWrite(7,usSpeed1);
  digitalWrite(6,usSpeed1);
  digitalWrite(9,LOW);
  digitalWrite(10,HIGH);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
}
 
else if(t =='S'){      //STOP (all motors stop)
  digitalWrite(7,0);
  digitalWrite(6,0);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
}

/**else if(t=='I'){
  digitalWrite(7,70);
  digitalWrite(6,70);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,HIGH);
  digitalWrite(12,HIGH); 
}

else if(t=='G'){
  digitalWrite(7,70);
  digitalWrite(6,70);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,HIGH);
  digitalWrite(12,HIGH); 
}

if (sp=='0'){
  digitalWrite(7,0);
  digitalWrite(6,0);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW); 
}

if (sp=='5'){
  digitalWrite(7,100);
  digitalWrite(6,100);
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
  digitalWrite(11,HIGH);
  digitalWrite(12,LOW); 
}


if (t=='w'){
  digitalWrite(9,HIGH);
}
  else {
  digitalWrite(9,LOW);
}*/

  
}

  


