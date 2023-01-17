#include <math.h> 
#include <Servo.h>

Servo servo_q1;  
Servo servo_q2;  
Servo servo_q3;  

double L2,L3;
int i=0;
int lastpos1=0;
int lastpos2=0;
int lastpos3=0;

#define const PI=3.14;

double cin_inv_q1(double px,double py);
double cin_inv_q2_b(double px,double py,double pz,double q3);
double cin_inv_q3_b(double px,double py,double pz);

double conv_q1(double q1);
double conv_q2(double q2);
double conv_q3(double q3);

void moverservo(int numservo, int posicion);

double r,t_m,x,y;

double q1,q2,q3,px,py,pz;
int q1g,q2g,q3g;

double t_s=0;

void setup() {
  servo_q1.attach(6); 
  servo_q2.attach(9); 
  servo_q3.attach(10); 
  Serial.begin(9600);
  Serial.println("Ok");
  delay(500);
  Serial.println("Desplazándose al punto inicial, espere...");  
  Serial.println("Listo para comenzar rutina...");
  servo_q1.write(90);
  servo_q2.write(90);
  servo_q3.write(180);    
  L2=0.08;    //Robot naranja
  L3=0.15;     //Robot naranja
  r=0.05;
  x=0;
  y=0;
  delay(3000);      
}

void loop() {

  py=0.0;
  px=0.0;
  pz=L2+L3;

  /*
  // Programación para crear una línea recta 
  if (t_s<10){
    px=0.1;
    py=0.1-0.2*(t_s/10);
    pz=0.1;
  }
  */

  /*
  // Ecuación para crear un círculo
  px=0.08;
  py=0.1+r*cos(t_s/2);
  pz=r*sin(t_s/2);
  */

  q1=cin_inv_q1(px,py);
  q3=cin_inv_q3_b(px,py,pz);
  q2=cin_inv_q2_b(px,py,pz,q3);

  q1g=int(conv_q1(q1));
  q2g=int(conv_q2(q2));
  q3g=int(conv_q3(q3));

  q1g=q1g+90;
  q3g=-q3g+90;    //Escalamiento considerando que el motor está en sentido inverso

  moverservo(1,q1g);
  moverservo(2,q2g);
  moverservo(3,q3g);

  Serial.println("Movimiento listo");

  delay(10);

  t_m=millis();
  t_s=t_m/1000;

}

double cin_inv_q1(double px,double py){
  double qq1=atan2(py,px);
  return(qq1);
}

double cin_inv_q2_b(double px,double py,double pz,double q3){
  double s_px=square(px);
  double s_py=square(py);
  double s_pz=square(pz);
  double s_L2=square(L2);
  double s_L3=square(L3);
  double cq3=(s_px+s_py+s_pz-s_L2-s_L3)/(2*L2*L3);  
  double r=sqrt(s_px+s_py);
  double beta=atan2(pz,r);
  double alfa=atan2((L3*sin(q3)),(L2+L3*cq3));
  double qq2=beta-alfa;
  return(qq2);  
}

double cin_inv_q3_b(double px,double py,double pz){
  double s_px=square(px);
  double s_py=square(py);
  double s_pz=square(pz);
  double s_L2=square(L2);
  double s_L3=square(L3);
  //double cq3=(s_px+s_py+s_pz-s_L2-s_L3)/(2*L2*L3);
  double cq3=(px*px+py*py+pz*pz-L2*L2-L3*L3)/(2*L2*L3);
  double arg_sqrt_cq3=1-cq3*cq3;
  double num_q3=sqrt(arg_sqrt_cq3);
  num_q3=-num_q3;   //Codo arriba
  double qq3=atan2(num_q3,cq3);
  return(qq3);
}

double conv_q1(double q1){
  double qq1=(q1*180)/PI;
  return(qq1);
}

double conv_q2(double q2){
  double qq2=(q2*180)/PI;
  return(qq2);
}

double conv_q3(double q3){
  double qq3=(q3*180)/PI;
  return(qq3);
}

void moverservo(int numservo, int posicion){
  
  if (posicion>=0){
    if (numservo==1){
      Serial.print("numservo: ");Serial.println(numservo);
      Serial.print("ultima posicion: ");Serial.println(lastpos1);
      Serial.print("nueva posicion: ");Serial.println(posicion);  
      for (i=lastpos1;i<=posicion;i++){
         servo_q1.write(i);        
      }
      lastpos1=posicion;         
    }
    if (numservo==2){
      Serial.print("numservo: ");Serial.println(numservo);
      Serial.print("ultima posicion: ");Serial.println(lastpos2);
      Serial.print("nueva posicion: ");Serial.println(posicion);  
      for (i=lastpos2;i<=posicion;i++){
         servo_q2.write(i);        
      }
      lastpos2=posicion;         
    }
    if (numservo==3){
      Serial.print("numservo: ");Serial.println(numservo);
      Serial.print("ultima posicion: ");Serial.println(lastpos3);
      Serial.print("nueva posicion: ");Serial.println(posicion);  
      for (i=lastpos3;i<=posicion;i++){
         servo_q3.write(i);        
      }
      lastpos3=posicion;         
    }
    delay(50);
  }
  if (posicion<0){
    if (numservo==1){
      Serial.print("numservo: ");Serial.println(numservo);
      Serial.print("ultima posicion: ");Serial.println(lastpos1);
      Serial.print("nueva posicion: ");Serial.println(posicion);  
      for (i=lastpos1;i>=posicion;i--){
         servo_q1.write(i);        
      }
      lastpos1=posicion;         
    }
    if (numservo==2){
      Serial.print("numservo: ");Serial.println(numservo);
      Serial.print("ultima posicion: ");Serial.println(lastpos2);
      Serial.print("nueva posicion: ");Serial.println(posicion);  
      for (i=lastpos2;i>=posicion;i--){
         servo_q2.write(i);        
      }
      lastpos2=posicion;         
    }
    if (numservo==3){
      Serial.print("numservo: ");Serial.println(numservo);
      Serial.print("ultima posicion: ");Serial.println(lastpos3);
      Serial.print("nueva posicion: ");Serial.println(posicion);  
      for (i=lastpos3;i>=posicion;i--){
         servo_q3.write(i);        
      }
      lastpos3=posicion;         
    }
    delay(50);
  }
}



