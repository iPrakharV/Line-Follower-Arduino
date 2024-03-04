//L298N Balant˝s˝   
  const int motorA1  = 10;  // L298N'in IN3 Giri˛i
  const int motorA2  = 9;  // L298N'in IN1 Giri˛i
  const int motorB1  = 11; // L298N'in IN2 Giri˛i
  const int motorB2  = 12;  // L298N'in IN4 Giri˛i


  int i=0; //Dˆng¸ler iÁin atanan rastgele bir dei˛ken
  int j=0; //Dˆng¸ler iÁin atanan rastgele bir dei˛ken
  int state; //Bluetooth cihaz˝ndan gelecek sinyalin dei˛keni
  int vSpeed=255;     // Standart H˝z, 0-255 aras˝ bir deer alabilir

void setup() {
    // Pinlerimizi belirleyelim
    pinMode(motorA1, OUTPUT);
    pinMode(motorA2, OUTPUT);
    pinMode(motorB1, OUTPUT);
    pinMode(motorB2, OUTPUT);    
    // 9600 baud h˝z˝nda bir seri port aÁal˝m
    Serial.begin(9600);
}
 
void loop() {
  /*Bluetooth balant˝s˝ koptuunda veya kesildiinde arabay˝ durdur.
 (Aktif etmek iÁin alt sat˝r˝n "//" lar˝n˝ kald˝r˝n.)*/
//     if(digitalRead(BTState)==LOW) { state='S'; }

  //Gelen veriyi 'state' dei˛kenine kaydet
    if(Serial.available() > 0){     
      state = Serial.read();   
    }
  
  /* Uygulamadan ayarlanabilen 4 h˝z seviyesi.(Deerler 0-255 aras˝nda olmal˝)*/
    if (state == '0'){
      vSpeed=0;}
    else if (state == '1'){
      vSpeed=100;}
    else if (state == '2'){
      vSpeed=180;}
    else if (state == '3'){
      vSpeed=200;}
    else if (state == '4'){
      vSpeed=255;}
     
  /***********************›leri****************************/
  //Gelen veri 'F' ise araba ileri gider.
    if (state == 'F') {
      analogWrite(motorA1, vSpeed); analogWrite(motorA2, 0);
        analogWrite(motorB1, vSpeed);      analogWrite(motorB2, 0); 
    }
  /**********************›leri Sol************************/
  //Gelen veri 'G' ise araba ileri sol(Áapraz) gider.
    else if (state == 'G') {
      analogWrite(motorA1,vSpeed ); analogWrite(motorA2, 0);  
        analogWrite(motorB1, 100);    analogWrite(motorB2, 0); 
    }
  /**********************›leri Sa************************/
  //Gelen veri 'I' ise araba ileri sa(Áapraz) gider.
    else if (state == 'I') {
        analogWrite(motorA1, 100); analogWrite(motorA2, 0); 
        analogWrite(motorB1, vSpeed);      analogWrite(motorB2, 0); 
    }
  /***********************Geri****************************/
  //Gelen veri 'B' ise araba geri gider.
    else if (state == 'B') {
      analogWrite(motorA1, 0);   analogWrite(motorA2, vSpeed); 
        analogWrite(motorB1, 0);   analogWrite(motorB2, vSpeed); 
    }
  /**********************Geri Sol************************/
  //Gelen veri 'H' ise araba geri sol(Áapraz) gider
    else if (state == 'H') {
      analogWrite(motorA1, 0);   analogWrite(motorA2, 100); 
        analogWrite(motorB1, 0); analogWrite(motorB2, vSpeed); 
    }
  /**********************Geri Sa************************/
  //Gelen veri 'J' ise araba geri sa(Áapraz) gider
    else if (state == 'J') {
      analogWrite(motorA1, 0);   analogWrite(motorA2, vSpeed); 
        analogWrite(motorB1, 0);   analogWrite(motorB2, 100); 
    }
  /***************************Sol*****************************/
  //Gelen veri 'L' ise araba sola gider.
    else if (state == 'L') {
      analogWrite(motorA1, vSpeed);   analogWrite(motorA2, 150); 
        analogWrite(motorB1, 0); analogWrite(motorB2, 0); 
    }
  /***************************Sa*****************************/
  //Gelen veri 'R' ise araba saa gider
    else if (state == 'R') {
      analogWrite(motorA1, 0);   analogWrite(motorA2, 0); 
        analogWrite(motorB1, vSpeed);   analogWrite(motorB2, 150);     
    }
  
  /************************Stop*****************************/
  //Gelen veri 'S' ise arabay˝ durdur.
    else if (state == 'S'){
        analogWrite(motorA1, 0);  analogWrite(motorA2, 0); 
        analogWrite(motorB1, 0);  analogWrite(motorB2, 0);
    }  
}
