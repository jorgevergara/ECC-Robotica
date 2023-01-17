#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial BT(13,12);

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

int anguloservo1 = 90;//posicion inicial
int anguloservo2 = 90;
int anguloservo3 = 90;
int anguloservo4 = 0;
int anguloservo5 = 90;


void setup() {
  Serial.begin(9600);
  BT.begin(9600);
  
  servo1.attach(10);//pinza
  servo2.attach(9);//muñeca
  servo3.attach(6);//codo
  servo4.attach(5);//hombro
  servo5.attach(3);//base

  servo1.write(anguloservo1);
  servo2.write(anguloservo2);
  servo3.write(anguloservo3);
  servo4.write(anguloservo4);
  servo5.write(anguloservo5);
  
}

void loop() {
if (BT.available()) {
    
    char texto = BT.read();
    
        switch (texto) {
          
  case '1':
    anguloservo1 = anguloservo1 + 10;
    anguloservo1 = constrain(anguloservo1,0,180);
    servo1.write(anguloservo1);
    Serial.print("garra ");
    Serial.println(anguloservo1);
    BT.print("garra ");
    BT.println(anguloservo1);
    break;
  
  case '2':
    anguloservo1 = anguloservo1 - 10;
    anguloservo1 = constrain(anguloservo1,0,180);
    servo1.write(anguloservo1);
    Serial.print("garra ");
    Serial.println(anguloservo1);
    BT.print("garra ");
    BT.println(anguloservo1);
    break;

  case 'q':
    anguloservo2 = anguloservo2 + 10;
    anguloservo2 = constrain(anguloservo2,0,180);
    servo2.write(anguloservo2);
    Serial.print("muñeca ");
    Serial.println(anguloservo2);
    break;
  
  case 'w':
    anguloservo2 = anguloservo2 - 10;
    anguloservo2 = constrain(anguloservo2,0,180);
    servo2.write(anguloservo2);
    Serial.print("muñeca ");
    Serial.println(anguloservo2);
    break;

  case 'a':
    anguloservo3 = anguloservo3 + 10;
    anguloservo3 = constrain(anguloservo3,0,180);
    servo3.write(anguloservo3);
    Serial.print("codo ");
    Serial.println(anguloservo3);
    break;
  
  case 's':
    anguloservo3 = anguloservo3 - 10;
    anguloservo3 = constrain(anguloservo3,0,180);
    servo3.write(anguloservo3);
    Serial.print("codo ");
    Serial.println(anguloservo3);
    break;

  case 'z':
    anguloservo4 = anguloservo4 + 10;
    anguloservo4 = constrain(anguloservo4,0,180);
    servo4.write(anguloservo4);
    Serial.print("hombro ");
    Serial.println(anguloservo4);
    break;
  
  case 'x':
    anguloservo4 = anguloservo4 - 10;
    anguloservo4 = constrain(anguloservo4,0,180);
    servo4.write(anguloservo4);
    Serial.print("hombro ");
    Serial.println(anguloservo4);
    break;

  case '3':
    anguloservo5 = anguloservo5 + 10;
    anguloservo5 = constrain(anguloservo5,0,180);
    servo5.write(anguloservo5);
    Serial.print("cadera ");
    Serial.println(anguloservo5);
    break;
  
  case '4':
    anguloservo5 = anguloservo5 - 10;
    anguloservo5 = constrain(anguloservo5,0,180);
    servo5.write(anguloservo5);
    Serial.print("cadera ");
    Serial.println(anguloservo5);
    break;
    }
   }
  }
