
#ifndef __COLOR__
#define __COLOR__

#include <Arduino.h>
#include <Wire.h>
#include <SparkFun_APDS9960.h>

#include "funciones.hpp"

enum color{RED,GREEN,BLUE,WHITE,BLACK,COLOR_ERROR};

class ColorSensor
{
public:  
  ColorSensor();
  bool init();
  color readColor(side side_);
  void debugColor(side side_);


private:
  SparkFun_APDS9960 apds;  
  
};


#endif
