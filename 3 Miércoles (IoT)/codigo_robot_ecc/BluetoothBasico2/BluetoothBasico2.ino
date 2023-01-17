#include <SoftwareSerial.h>
#include <Servo.h>


SoftwareSerial BT(13,12);
int pos = 0; 
Servo servo1;

void setup() {
  BT.begin(9600);       // Inicializamos el puerto serie BT que hemos creado
  Serial.begin(9600);   // Inicializamos  el puerto serie  
    servo1.attach(10);//pinza
}

void loop() {
  if(BT.available()){  // lectura de dato desde la app
    int DATO=BT.read();
    
    Serial.print("Dato: ");
    Serial.println(DATO);
 
    if (DATO == '1'){
      pos = pos + 10;
        servo1.write(pos);
      Serial.println(pos);
      //BT.write(pos);
      
      BT.println(pos);
    }
    if (DATO == '2'){
      pos = pos - 10;
      servo1.write(pos);
      Serial.println(pos);
      BT.print("Posicion actual:");
      BT.println(pos);     
      }
    }
 
  }
