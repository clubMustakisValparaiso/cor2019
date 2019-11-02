#include "colorSensor.hpp"


ColorSensor::ColorSensor()
{
  apds = SparkFun_APDS9960();
}


bool ColorSensor::init()
{
  setMux(4);
  apds.init();
  if ( apds.enableLightSensor(false) ) {
    Serial.println("ok coloSensor 1");
  } else {
    Serial.println("colorSensor not ok");
    return false;
  }

  setMux(6);
  apds.init();
  if ( apds.enableLightSensor(false) ) {
    Serial.println("ok coloSensor 2");
  } else {
    Serial.println("colorSensor not ok");
    return false;
  }

  return true;


}


color ColorSensor::readColor(side side_)
{
  if (side_ == DER) {
    setMux(4);
  }
  else if (side_ == IZ) {
    setMux(6);
  } else {
    Serial.println("lado ingresado es incorrecto");
    return COLOR_ERROR;
  }


  uint16_t ambient_light = 0;
  uint16_t red_light = 0;
  uint16_t green_light = 0;
  uint16_t blue_light = 0;

  if (  !apds.readAmbientLight(ambient_light) ||
        !apds.readRedLight(red_light) ||
        !apds.readGreenLight(green_light) ||
        !apds.readBlueLight(blue_light) ) {
    Serial.println("Error reading light values");
    return COLOR_ERROR;
  }

  float rojo = 1.0 * red_light / ambient_light;
  float verde = 1.0 * green_light / ambient_light;
  float azul = 1.0 * blue_light / ambient_light;

  switch (side_)
  {
    case DER: {
        if (rojo > 0.3) {
          Serial.println("rojo der");
          delay(500);
          return RED;
        }


        break;
      }
    case IZ:
      {
        if (rojo > 0.35) {
          Serial.println("rojo iz");
          delay(500);
          return RED;
        }
        break;
      }
    default:
      Serial.println("blanco");
      return WHITE;
      break;
  }
}

void ColorSensor::debugColor(side side_)
{
  if (side_ == DER)
  {
    setMux(4);
  }
  else if (side_ == IZ)
  {
    setMux(6);
  }
  else
  {
    Serial.println("lado ingresado es incorrecto");
    return;
  }


  uint16_t ambient_light = 0;
  uint16_t red_light = 0;
  uint16_t green_light = 0;
  uint16_t blue_light = 0;

  if (  !apds.readAmbientLight(ambient_light) ||
        !apds.readRedLight(red_light) ||
        !apds.readGreenLight(green_light) ||
        !apds.readBlueLight(blue_light) ) {
    Serial.println("Error reading light values");
  }


  else {

    float rojo = 1.0 * red_light / ambient_light;
    float verde = 1.0 * green_light / ambient_light;
    float azul = 1.0 * blue_light / ambient_light;


    Serial.print("Ambient: ");
    Serial.print(ambient_light);
    Serial.print(" Red: ");
    Serial.print(rojo);
    Serial.print(" Green: ");
    Serial.print(verde);
    Serial.print(" Blue: ");
    Serial.println(azul);
  }
}
