
#include "funciones.hpp"
#include "colorSensor.hpp"
#include "laserSensor.hpp"

ColorSensor pal;
//LaserSensor laser;

int p_base = 150;
float kp = -0.095;  //-0.0655
float kd = 0;

int last_error;

void setup() {

  Serial.begin(9600);
  Serial.println("ok");
  Wire.begin();

  last_error = 0;
  initMux();
  //laser.init();
  pal.init();

  //pinMode(7,INPUT);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(MA1, OUTPUT);
  pinMode(MA2, OUTPUT);
  pinMode(MB1, OUTPUT);
  pinMode(MB2, OUTPUT);
  pinMode(12, INPUT);
  pinMode(13, INPUT);
  pinMode(7, INPUT);
}

void loop() {
  

  boton();
  //-------------------------------------------------Prints de valores-----------------------------------------------------------------------//
  //-----------------------------------------------------------------------------------------------------------------------------------------//
  /*
    Serial.println(digitalRead(12));
    delay(200);
  */
  /*
  Serial.print(analogRead(0));
  Serial.print(" ");
  Serial.print(analogRead(1));
  Serial.print(" ");
  Serial.print(analogRead(2));
  Serial.print(" ");
  Serial.print(analogRead(3));
  Serial.print(" ");
  Serial.print(analogRead(6));
  Serial.print(" ");
  Serial.println(analogRead(7));
  delay(500);
*/

  //-------------------------------------------------Intersecciones y color-------------------------------------------------------------------//
  //-----------------------------------------------------------------------------------------------------------------------------------------//


  /*
    if(analogRead(0) > 400 && analogRead(1) > 400 && analogRead(2) > 400 && analogRead(3) > 400 && analogRead(6) > 400 && analogRead(7) > 400) {
    mover(0,0);
    delay(1000);
    for(int i = 0 ; i > 20 ; i++){
    ajustarAdelante();
    }
    mover(150,150);
    delay(100);
    mover(0,0);
    delay(1000);

    color der = pal.readColor(DER);
    color izq = pal.readColor(IZ);

    mover(0,0);
    delay(2000);
    
  
    if (der == GREEN && izq == GREEN) {
    Serial.println("DAR VUELTA");
    mover(-200, -200);
    delay(2000);
    }
    else if (der == GREEN) {
    Serial.println("Girar hacia derecha");
    mover(200, 200);
    delay(300);
    mover(200, -200);
    delay(1200);
    mover(200, 200);
    delay(200);
    return 0;
    }
    else if (izq == GREEN) {
    Serial.println("Girar hacia izquierda");
    mover(200, 200);
    delay(300);
    mover(-200, 200);
    delay(1200);
    mover(200, 200);
    delay(200);
    }
    else{
    mover(200,200);
    delay(500);
    }
  */
  
    /*
    if (!digitalRead(12) && analogRead(0) > 300 && analogRead(1) > 300 && analogRead(7) < 300) {
    Serial.println("Semi interseccion izq");
    mover(0, 0);
    delay(1500);
    mover(150, 150);
    delay(200);
    mover(0, 0);
    delay(500); 
    color der = pal.readColor(DER);
    color izq = pal.readColor(IZ);
    if (der == GREEN && izq == GREEN) {
    Serial.println("DAR VUELTA");
    mover(-200, 200);
    delay(2000);
    }
    else if (der == GREEN) {
    Serial.println("Girar hacia derecha");
    mover(200, 200);
    delay(200);
    mover(200, -200);
    delay(1100);
    mover(200, 200);
    delay(200);
    return 0;
    }

    else if (izq == GREEN) {
    Serial.println("Girar hacia izquierda");
    mover(200, 200);
    delay(200);
    mover(-200, 200);
    delay(1100);
    mover(200, 200);
    delay(200);
    }
    }
  
  */
    if (!digitalRead(13) && analogRead(7) > 500 && analogRead(6) > 500 && analogRead(0) < 500) {
    Serial.println("Semi interseccion der");
    mover(0, 0);
    delay(1500);
    mover(200, 200);
    delay(100);
    mover(0, 0);
    color der = pal.readColor(DER);
    color izq = pal.readColor(IZ);
    if (der == GREEN && izq == GREEN) {
      Serial.println("DAR VUELTA");
      mover(-200, 200);
      delay(2000);
    }
    else if (der == GREEN) {
      Serial.println("Girar hacia derecha");
      mover(200, 200);
      delay(200);
      mover(200, -200);
      delay(1100);
      mover(200, 200);
      delay(200);
      return 0;
    }

    else if (izq == GREEN) {
      Serial.println("Girar hacia izquierda");
      mover(200, 200);
      delay(200);
      mover(-200, 200);
      delay(1100);
      mover(200, 200);
      delay(200);
    }
    }
  
  //-------------------------------------------------Seguidor de linea-----------------------------------------------------------------------//
  //-----------------------------------------------------------------------------------------------------------------------------------------//
    
    int error = 4 * analogRead(0) + 2 * analogRead(1) + 1 * analogRead(2) + -1 * analogRead(3) + -2 * analogRead(6) + -4 * analogRead(7);
    int dif_error = error - last_error;
    last_error = error;
    mover(p_base + int(kp * error) + int(dif_error * kd) , p_base - int(kp * error) - int(dif_error * kd));
    
  
}
void ajustarAtras()
{
  while (1)
  {
    bool iz = digitalRead(12);
    bool der = digitalRead(13);

    Serial.print(iz);
    Serial.print(" ");
    Serial.println(der);
    if (iz && der)
    {
      mover(-100, -100);
    }
    else if (!iz && der)
    {
      mover(100, 0);
    }
    else if (iz && !der)
    {
      mover(0, 100);
    }
    else if (!iz && !der)
    {
      break;
    }
  }
}

void ajustarAdelante()
{
  while (1)
  {
    bool iz = digitalRead(12);
    bool der = digitalRead(13);


    if (iz && der)
    {
      mover(100, 100);
    }
    else if (!iz && der)
    {
      mover(-100, 0);
    }
    else if (iz && !der)
    {
      mover(0, -100);
    }
    else if (!iz && !der)
    {
      break;

    }
  }
}
