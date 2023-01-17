#include <Servo.h>

Servo myservo3;  // creo un objeto del tipo servo para controlar el servomotor de la muñeca
void setup() {

  myservo3.attach(9);  // Pin para conectar el servo motor de la muñeca
}

void loop() {

  myservo3.write(0);                   // Posición a la cual se moverá el servo motor de la muñeca
  delay(3000);                          // Retardo en mili segundos
  myservo3.write(90);
  delay(3000);
}
