#include "funciones.hpp"

void initMux()
{
  pinMode(MUX_A,OUTPUT);
  pinMode(MUX_B,OUTPUT);
  pinMode(MUX_C,OUTPUT);
}

void setMux(byte salida){ 
 bool a = salida & 4;
 bool b = salida & 2;
 bool c = salida & 1;

 digitalWrite(MUX_A,a);
 digitalWrite(MUX_B,b);
 digitalWrite(MUX_C,c);

 delay(5);
 
}


void mover(int pot_iz, int pot_der)
{
  /*------------------------ Motor iz -----------------------*/
  if(pot_iz >= 0){
    digitalWrite(MA1,1);
    digitalWrite(MA2,0);
  }else{
    digitalWrite(MA1,0);
    digitalWrite(MA2,1);
  }
  if(abs(pot_iz) > 255){
    pot_iz = 255*int(pot_iz/abs(pot_iz));
  }

  
  analogWrite(ENA, abs(pot_iz));

  /*------------------------ Motor der -----------------------*/
  if(pot_der >= 0){
    digitalWrite(MB1,1);
    digitalWrite(MB2,0);
  }else{
    digitalWrite(MB1,0);
    digitalWrite(MB2,1);
  }

  if(abs(pot_der > 255)){
    pot_der = 255*int(pot_der/abs(pot_der));
  }

  analogWrite(ENB, abs(pot_der));
  
}
void debugQTR(){
  
  Serial.print(analogRead(0));
  Serial.print("  ");
  Serial.print(analogRead(1));
  Serial.print("  ");
  Serial.print(analogRead(2));
  Serial.print("  ");
  Serial.print(analogRead(3));
  Serial.print("  ");
  Serial.print(analogRead(6));
  Serial.print("  ");
  Serial.print(analogRead(7));
  Serial.println("  ");
  delay(50);

}
void boton(){

   bool a = 0;
   setMux(2);
   
   if(analogRead(4) > 500){
     mover(0,0);
     a = 1;
     delay(500); 
   }

   while(a)
   {
    if(analogRead(4) > 500){
    delay(200); 
    a = 0;
   }
    
 
  }
}
