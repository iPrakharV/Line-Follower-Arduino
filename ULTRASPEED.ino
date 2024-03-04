

#define leftCenterSensor  A4
#define leftNearSensor     A6
#define leftFarSensor      A7
#define rightCenterSensor  A3
#define rightNearSensor    A1
#define rightFarSensor     A0

int leftCenterReading;
int leftNearReading;
int leftFarReading;
int rightCenterReading;
int rightNearReading;                      
int rightFarReading;
int leftNudge;
int replaystage;
int rightNudge;

#define leapTime 150
#define leftMotor1  10
#define leftMotor2  11
#define rightMotor1 9
#define rightMotor2 6
#define led 13

char path[40] = {};
int pathLength;
int readLength;
void setup(){

  pinMode(leftCenterSensor, INPUT);
  pinMode(leftNearSensor, INPUT);
  pinMode(leftFarSensor, INPUT);
  pinMode(rightCenterSensor, INPUT);
  pinMode(rightNearSensor, INPUT);
  pinMode(rightFarSensor, INPUT);
  pinMode(leftMotor1, OUTPUT);
  pinMode(leftMotor2, OUTPUT);
  pinMode(rightMotor1, OUTPUT);
  pinMode(rightMotor2, OUTPUT);
  pinMode(led, OUTPUT);
  
  Serial.begin(9600);
  digitalWrite(led, LOW);
  delay(1000);

}
void loop(){
 
 readSensors();                                                                                     
 
 if(leftFarReading>49 && rightFarReading>49 && //center sensors on
   (leftCenterReading>49 || rightCenterReading>49) ){ 
    straight();                                                                                      
  }
 
  else{                                                                                              
    leftHandWall();                                                                                   
  }

}

void readSensors(){
  
  leftCenterReading  = analogRead(leftCenterSensor);
  leftNearReading    = analogRead(leftNearSensor);
  leftFarReading     = analogRead(leftFarSensor);
  rightCenterReading = analogRead(rightCenterSensor);
  rightNearReading   = analogRead(rightNearSensor);
  rightFarReading    = analogRead(rightFarSensor);  

}


void leftHandWall(){
          

  if( leftFarReading>49 && rightFarReading>49){//to check maze is finishef or not
    analogWrite(leftMotor1,120);
    analogWrite(leftMotor2, 0);
    analogWrite(rightMotor1,120);
    analogWrite(rightMotor2, 0);
    delay(150);
    readSensors();
    
    if(leftFarReading>49 && rightFarReading>49){
      done();
    }
    if(leftFarReading>49 && rightFarReading>49){ 
      turnLeft();
    }
    
  }
  
  if(leftFarReading>49){ // if you can turn left then turn left
    analogWrite(leftMotor1,120);
    analogWrite(leftMotor2, 0);
    analogWrite(rightMotor1,120);
    analogWrite(rightMotor2, 0);
    delay(150);
    readSensors();
      
      if(leftFarReading>49 && rightFarReading>49){
        turnLeft();
      }
      else{
        done();
      }
  }
   
  if(rightFarReading>49){//right
    analogWrite(leftMotor1,120);
    analogWrite(leftMotor2,0);
    analogWrite(rightMotor1,120);
    analogWrite(rightMotor2,0);
    delay(25);
    readSensors();
    
    if(leftFarReading>49){//left
      delay(leapTime-30);
      readSensors();
      
      if(rightFarReading>49 && leftFarReading>49){
        done();
      }
      else{
        turnLeft();
        return;
      }
    }
    delay(leapTime-30);
    readSensors();
    if(leftFarReading>49 && leftCenterReading>49 &&
      rightCenterReading>49 && rightFarReading>49){
      turnRight();
      return;
    }
    path[pathLength]='S';
    Serial.println("s");
    pathLength++;
    Serial.print("Path length: ");
    Serial.println(pathLength);
    if(path[pathLength-2]=='B'){
    Serial.println("shortening path");
    shortPath();
     }
    straight();
  }
  readSensors();
  if(leftFarReading>49 && leftCenterReading>49 && rightCenterReading>49 
    && rightFarReading>49 && leftNearReading>49 && rightNearReading>49)
    {
    turnAround();
  }
  
}
void done(){
  digitalWrite(leftMotor1, LOW);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, LOW);
    digitalWrite(rightMotor2, LOW);
  replaystage=1;
  path[pathLength]='D';
  pathLength++;
 while(analogRead(leftFarSensor)>49){
   digitalWrite(led, HIGH);
  
 }
 delay(5000);
  replay();
}

void turnLeft()
{
  while(analogRead(rightCenterSensor)>49 ||analogRead(leftCenterSensor)>49){
     analogWrite(leftMotor1, 0);
    analogWrite(leftMotor2, 220);
    analogWrite(rightMotor1, 220);
    analogWrite(rightMotor2, 0);
    delay(2);
     digitalWrite(leftMotor1, LOW);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, LOW);
    digitalWrite(rightMotor2, LOW);
    delay(3);
  }
    
  while(analogRead(rightCenterSensor)>49 ) {
    analogWrite(leftMotor1, 0);
    analogWrite(leftMotor2, 220);
    analogWrite(rightMotor1, 220);
    analogWrite(rightMotor2, 0);
    delay(2);
    digitalWrite(leftMotor1, LOW);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, LOW);
    digitalWrite(rightMotor2, LOW);
    delay(3);
  }
 
  if(replaystage==0){
    path[pathLength]='L';
    Serial.println("l");
    pathLength++;
    Serial.print("Path length: ");
    Serial.println(pathLength);
      if(path[pathLength-2]=='B'){
    Serial.println("shortening path");
        shortPath();
      }
  }
}

void turnRight(){

    
  while(analogRead(rightCenterSensor)>49){
    analogWrite(leftMotor1, 220);
    analogWrite(leftMotor2, 0);
    analogWrite(rightMotor1, 0);
    analogWrite(rightMotor2, 220);
    delay(2);
     digitalWrite(leftMotor1, LOW);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, LOW);
    digitalWrite(rightMotor2, LOW);
    delay(3);
  }
   while(analogRead(rightCenterSensor)>49){
     analogWrite(leftMotor1, 220);
    analogWrite(leftMotor2, 0);
    analogWrite(rightMotor1, 0);
    analogWrite(rightMotor2, 220);
    delay(2);
     digitalWrite(leftMotor1, LOW);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, LOW);
    digitalWrite(rightMotor2, LOW);
    delay(3);
  }
   while(analogRead(leftCenterSensor)>49){
analogWrite(leftMotor1, 220);
  analogWrite(leftMotor2,0);
    analogWrite(rightMotor1,10);
    analogWrite(rightMotor2,220);
    delay(2);
    digitalWrite(leftMotor1, LOW);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, LOW);
    digitalWrite(rightMotor2, LOW);
    delay(3);
  }
  
  if(replaystage==0){
  path[pathLength]='R';
  Serial.println("r");
  pathLength++;
  Serial.print("Path length: ");
  Serial.println(pathLength);
    if(path[pathLength-2]=='B'){
      Serial.println("shortening path");
      shortPath();
    }
  }
 
}

void straight(){
  if( analogRead(leftCenterSensor)>49){
   analogWrite(leftMotor1, 240);
    analogWrite(leftMotor2, 0);
    analogWrite(rightMotor1, 240);
    analogWrite(rightMotor2, 0);
    delay(2);
    digitalWrite(leftMotor1, HIGH);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, LOW);
    digitalWrite(rightMotor2, LOW);
    delay(5);
    return;
  }
  if(analogRead(rightCenterSensor)>49){
   analogWrite(leftMotor1, 240);
    analogWrite(leftMotor2, 0);
    analogWrite(rightMotor1, 240);
    analogWrite(rightMotor2, 0);
    delay(2);
    digitalWrite(leftMotor1, LOW);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, HIGH);
    digitalWrite(rightMotor2, LOW);
    delay(5);
    return;
  }
  
   analogWrite(leftMotor1, 240);
    analogWrite(leftMotor2, 0);
    analogWrite(rightMotor1, 240);
    analogWrite(rightMotor2, 0);
    delay(4);
    digitalWrite(leftMotor1, LOW);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, LOW);
    digitalWrite(rightMotor2, LOW);
    delay(1);
  
}

void turnAround(){
    analogWrite(leftMotor1, 160);
    analogWrite(leftMotor2, 0);
    analogWrite(rightMotor1,160);
    analogWrite(rightMotor2, 0);
    delay(60);
    
   while(analogRead(rightCenterSensor)>49){
     analogWrite(leftMotor1, 0);
    analogWrite(leftMotor2, 160);
    analogWrite(rightMotor1,160);
    analogWrite(rightMotor2, 0);
    delay(4);
     digitalWrite(leftMotor1, LOW);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, LOW);
    digitalWrite(rightMotor2, LOW);
    delay(3);
  }
  path[pathLength]='B';
  pathLength++;
  straight();
  Serial.println("b");
  Serial.print("Path length: ");
  Serial.println(pathLength);
}

void shortPath(){
 int shortDone=0;
  if(path[pathLength-3]=='L' && path[pathLength-1]=='R'){
    pathLength-=3;
    path[pathLength]='B';
  Serial.println("test1");
    shortDone=1;
  }
   
  if(path[pathLength-3]=='L' && path[pathLength-1]=='S' && shortDone==0){
    pathLength-=3;
    path[pathLength]='R';
  Serial.println("test2");
    shortDone=1;
  }
   
  if(path[pathLength-3]=='R' && path[pathLength-1]=='L' && shortDone==0){
    pathLength-=3;
    path[pathLength]='B';
  Serial.println("test3");
    shortDone=1;
  }
  
   
  if(path[pathLength-3]=='S' && path[pathLength-1]=='L' && shortDone==0){
    pathLength-=3;
    path[pathLength]='R';
  Serial.println("test4");
    shortDone=1;
  }
     
  if(path[pathLength-3]=='S' && path[pathLength-1]=='S' && shortDone==0){
    pathLength-=3;
    path[pathLength]='B';
  Serial.println("test5");
    shortDone=1;
  }
    if(path[pathLength-3]=='L' && path[pathLength-1]=='L' && shortDone==0){
    pathLength-=3;
    path[pathLength]='S';
  Serial.println("test6");
    shortDone=1;
  }
  
  path[pathLength+1]='D';
  path[pathLength+2]='D';
  pathLength++;
  Serial.print("Path length: ");
  Serial.println(pathLength);
  printPath();
}




void printPath(){
  Serial.println("+++++++++++++++++");
  int x;
  while(x>=pathLength){
  Serial.println(path[x]);
  x++;
  }
  Serial.println("+++++++++++++++++");
}


void replay(){
   readSensors();
  if(leftFarReading>49 && rightFarReading>49){
    straight();
  }
  else{
    if(path[readLength]=='D'){
       digitalWrite(leftMotor1, HIGH);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, HIGH);
  digitalWrite(rightMotor2, LOW);
    delay(160);
    digitalWrite(leftMotor1, LOW);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, LOW);
    digitalWrite(rightMotor2, LOW);
      endMotion();
    }
    if(path[readLength]=='L'){
     analogWrite(leftMotor1, 120);
     analogWrite(leftMotor2, 0);
    analogWrite(rightMotor1, 120);
    analogWrite(rightMotor2,0);
    delay(leapTime);
      turnLeft();
    }
    if(path[readLength]=='R'){
       analogWrite(leftMotor1, 120);
    analogWrite(leftMotor2, 0);
    analogWrite(rightMotor1, 120);
    analogWrite(rightMotor2, 0);
    delay(leapTime);
    turnRight();
    }
    if(path[readLength]=='S'){
       analogWrite(leftMotor1, 240);
    analogWrite(leftMotor2, 0);
    analogWrite(rightMotor1,240);
    analogWrite(rightMotor2,0);
    delay(leapTime);
    straight();
    }
    
    readLength++;
  }
    
  replay();
  
}

void endMotion(){
    digitalWrite(led, LOW);
    delay(500);
    digitalWrite(led, HIGH);
    delay(200);
      digitalWrite(led, LOW);
    delay(200);
    digitalWrite(led, HIGH);
    delay(500);
  endMotion();
}

