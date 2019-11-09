
#include "funciones.hpp"
#include "colorSensor.hpp"
#include "laserSensor.hpp"

ColorSensor pal;
//LaserSensor laser;

int p_base = 150;
float kp = -0.0655;  //-0.0655
float kd = 0.46;

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
  //-------------------------------------------------Prints de valores-----------------------------------------------------------------------//
  //-----------------------------------------------------------------------------------------------------------------------------------------//
  /*
    Serial.println(digitalRead(12));
    delay(200);
  */
  //    Serial.print(analogRead(0));
  //       Serial.print(" ");
  //       Serial.print(analogRead(1));
  //       Serial.print(" ");
  //       Serial.print(analogRead(2));
  //       Serial.print(" ");
  //       Serial.print(analogRead(3));
  //       Serial.print(" ");
  //       Serial.print(analogRead(6));
  //       Serial.print(" ");
  //       Serial.println(analogRead(7));


  //-------------------------------------------------Intersecciones y color-------------------------------------------------------------------//
  //-----------------------------------------------------------------------------------------------------------------------------------------//
  //  if (analogRead(0) > 300 && analogRead(1) > 300 && analogRead(2) > 300 && analogRead(3) > 300 && analogRead(6) > 300 && analogRead(7) > 300) {
  //    mover(0, 0);
  //    delay(1500);
  //    mover(200, 200);
  //    delay(100);
  //    mover(0, 0);
  //    Serial.println("Interseccion");
  //    color der = pal.readColor(DER);
  //    color izq = pal.readColor(IZ);
  //    if (der == GREEN && izq == GREEN) {
  //      Serial.println("DAR VUELTA");
  //      mover(-200, 200);
  //      delay(2000);
  //    }
  //    else if (der == GREEN) {
  //      Serial.println("Girar hacia derecha");
  //      mover(200, 200);
  //      delay(200);
  //      mover(200, -200);
  //      delay(1100);
  //      mover(200, 200);
  //      delay(200);
  //      return 0;
  //    }
  //
  //  else if (izq == GREEN) {
  //    Serial.println("Girar hacia izquierda");
  //    mover(200, 200);
  //    delay(200);
  //    mover(-200, 200);
  //    delay(1100);
  //    mover(200, 200);
  //    delay(200);
  //  }
  //  }

  if (!digitalRead(12) && analogRead(0) > 300 && analogRead(1) > 300 && analogRead(7) < 300) {
    Serial.println("Semi interseccion izq");
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
  //    if (DER == GREEN) {
  //      Serial.println("Girar hacia derecha");
  //      mover(200, -200);
  //      delay(1000);
  //    }
  //    if (IZ == GREEN) {
  //      Serial.println("Girar hacia Izquierda");
  //      mover(-200, 200);
  //      delay(1000);
  //    }
  //  }
  else if (!digitalRead(13) && analogRead(6) > 300 && analogRead(0) < 300) {
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
  //    if (DER == GREEN) {
  //      Serial.println("Girar hacia derecha");
  //      mover(200, -200);
  //      delay(1000);
  //    }
  //    if (IZ == GREEN) {
  //      Serial.println("Girar hacia Izquierda");
  //      mover(-200, 200);
  //      delay(1000);
  //    }
  //  }
  //-------------------------------------------------Seguidor de linea-----------------------------------------------------------------------//
  //-----------------------------------------------------------------------------------------------------------------------------------------//
  int error = 4 * analogRead(0) + 3 * analogRead(1) + 1 * analogRead(2) + -1 * analogRead(3) + -3 * analogRead(6) + -4 * analogRead(7);
  int dif_error = error - last_error;
  last_error = error;
  mover(p_base + int(kp * error) + int(dif_error * kd) , p_base - int(kp * error) - int(dif_error * kd));
}
