#include"funcionesobstaculos.hpp"
void giroDer()
{
  mover(100, -100);
  delay(1500);
}

void giroIz()
{
  mover(-100, 100);
  delay(1600);
}

void detenerBoton()
{
  setMux(2);
  while (1)
  {
    mover(0, 0);
    if (analogRead(4) > 300)
    {
      break;
    }
  }
  setMux(1);
}


void obstaculoIz()
{
  mover(0, 0);
  delay(1000);
  giroIz();
  ajustarAtras();
  mover(200, 200);
  delay(2000);
  mover(0, 0);
  giroDer();
  mover(200, 200);
  delay(3800);
  mover(0, 0);
  delay(500);
  giroDer();

  while (analogRead(0) < 500 && analogRead(1) < 500 && analogRead(2) < 500 && analogRead(3) < 500 && analogRead(6) < 500 && analogRead(7) < 500 && digitalRead(12)&& digitalRead(13) )
  {
    mover(100, 100);
    
  }
  ajustarAdelante();
  mover(100, 100);
  delay(250);
  giroIz();
  


}

void obstaculoDer()
{
  mover(0, 0);
  delay(1000);
  giroDer();
  ajustarAtras();
  mover(200, 200);
  delay(2000);
  mover(0, 0);
  giroIz();
  mover(200, 200);
  delay(3800);
  mover(0, 0);
  delay(1000);
  giroIz();

  while (analogRead(0) < 500 && analogRead(1) < 500 && analogRead(2) < 500 && analogRead(3) < 500 && analogRead(6) < 500 && analogRead(7) < 500)
  {
    mover(100, 100);
  }
  ajustarAdelante();
  mover(100, 100);
  delay(250);
  giroDer();
  

}
