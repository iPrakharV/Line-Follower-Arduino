 #define BRAKE 0
 #define CW    1
 #define CCW   2
 #define CS_THRESHOLD 15   // Definition of safety current (Check: "1.3 Monster Shield Example").
 //MOTOR 1
 #define MOTOR_A1_PIN 7
 #define MOTOR_B1_PIN 8
 //MOTOR 2
 #define MOTOR_A2_PIN 9
 #define MOTOR_B2_PIN 4
 #define PWM_MOTOR_1 5
 #define PWM_MOTOR_2 6
 #define MOTOR_1 0
 #define MOTOR_2 1
 short usSpeed = 255;  //default motor speed
 short usSpeed1 = 80;
 unsigned short usMotor_Status = BRAKE;
 void setup(){
 Serial.begin(9600);
 pinMode(MOTOR_A1_PIN, OUTPUT);
 pinMode(MOTOR_B1_PIN, OUTPUT);

 pinMode(MOTOR_A2_PIN, OUTPUT);
 pinMode(MOTOR_B2_PIN, OUTPUT);
 pinMode(PWM_MOTOR_1, OUTPUT);
 pinMode(PWM_MOTOR_2, OUTPUT);

}
void loop(){
  if (Serial.available()){
  char bt = Serial.read();
if (bt=='1')
usSpeed =50;
  
if (bt=='2')
usSpeed =60;

if (bt=='3')
usSpeed =75;

if (bt=='4')
usSpeed =100;
 
 if (bt=='5')
usSpeed =125;

if (bt=='6')
usSpeed =140;

if (bt=='7')
usSpeed =165;

if (bt=='8')
usSpeed =190;

if (bt=='9')
usSpeed =225;



  
  if(bt == 'B'){            //move forwards
usMotor_Status = CCW;
  motorGo(MOTOR_1, usMotor_Status, usSpeed);
  motorGo(MOTOR_2, usMotor_Status, usSpeed);

  if(bt == 'J'){            //move forwards
usMotor_Status = CCW;
  motorGo(MOTOR_1, usMotor_Status, usSpeed);
  motorGo(MOTOR_2, usMotor_Status, usSpeed-25);
  }

  if (bt == 'I'){       //move backwards
usMotor_Status = CW;
  motorGo(MOTOR_1, usMotor_Status, usSpeed);
  motorGo(MOTOR_2, usMotor_Status, usSpeed-25);
 }

  
  }

  
 /* else if(bt == 'G'){            //move forwards
usMotor_Status = CCW;
  motorGo(MOTOR_1, usMotor_Status, usSpeed-25);
  motorGo(MOTOR_2, usMotor_Status, usSpeed);
  }

   else if(bt == 'H'){            //move forwards
usMotor_Status = CCW;
  motorGo(MOTOR_1, usMotor_Status, usSpeed-25);
  motorGo(MOTOR_2, usMotor_Status, usSpeed);
  }

 else if(bt == 'J'){            //move forwards
usMotor_Status = CCW;
  motorGo(MOTOR_1, usMotor_Status, usSpeed);
  motorGo(MOTOR_2, usMotor_Status, usSpeed-25);
  }


 else if (bt == 'I'){       //move backwards
usMotor_Status = CW;
  motorGo(MOTOR_1, usMotor_Status, usSpeed);
  motorGo(MOTOR_2, usMotor_Status, usSpeed-25);
 }*/
  
 else if (bt == 'F'){       //move backwards
usMotor_Status = CW;
  motorGo(MOTOR_1, usMotor_Status, usSpeed);
  motorGo(MOTOR_2, usMotor_Status, usSpeed);


 if(bt == 'G'){            //move forwards
usMotor_Status = CCW;
  motorGo(MOTOR_1, usMotor_Status, usSpeed-25);
  motorGo(MOTOR_2, usMotor_Status, usSpeed);
  }

  if(bt == 'H'){            //move forwards
usMotor_Status = CCW;
  motorGo(MOTOR_1, usMotor_Status, usSpeed-25);
  motorGo(MOTOR_2, usMotor_Status, usSpeed);
  }
  
 }
 else if (bt == 'S'){       //stop!!
usMotor_Status = BRAKE;
  motorGo(MOTOR_1, usMotor_Status, 0);
  motorGo(MOTOR_2, usMotor_Status, 0);
 }
 else if (bt == 'R'){       //right
usMotor_Status = CCW;
motorGo(MOTOR_1, usMotor_Status, usSpeed1);
usMotor_Status = CW;
motorGo(MOTOR_2, usMotor_Status, usSpeed1);
 }
 
  else if (bt == 'L'){  
   usMotor_Status = CW;
motorGo(MOTOR_1, usMotor_Status, usSpeed1);
usMotor_Status = CCW;
motorGo(MOTOR_2, usMotor_Status, usSpeed1);//LEFT
  }



 
 }
}
void motorGo(uint8_t motor, uint8_t direct, uint8_t pwm)         //Function that controls the variables: motor(0 ou 1), direction (cw ou ccw) e pwm (entra 0 e 255);
{
  if(motor == MOTOR_1)
  {
    if(direct == CW)
    {
      digitalWrite(MOTOR_A1_PIN, LOW); 
      digitalWrite(MOTOR_B1_PIN, HIGH);
    }
    else if(direct == CCW)
    {
      digitalWrite(MOTOR_A1_PIN, HIGH);
      digitalWrite(MOTOR_B1_PIN, LOW);      
    }
    else
    {
      digitalWrite(MOTOR_A1_PIN, LOW);
      digitalWrite(MOTOR_B1_PIN, LOW);            
    }
    
    analogWrite(PWM_MOTOR_1, pwm); 
  }
  else if(motor == MOTOR_2)
  {
    if(direct == CW)    
    {
      digitalWrite(MOTOR_A2_PIN, LOW);
      digitalWrite(MOTOR_B2_PIN, HIGH);
    }
    else if(direct == CCW)
    {
      digitalWrite(MOTOR_A2_PIN, HIGH);
      digitalWrite(MOTOR_B2_PIN, LOW);      
    }
    else
    {
      digitalWrite(MOTOR_A2_PIN, LOW);
      digitalWrite(MOTOR_B2_PIN, LOW);            
    }
    
    analogWrite(PWM_MOTOR_2, pwm);
  }
  
  }

