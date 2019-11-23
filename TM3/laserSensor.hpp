

#ifndef __LASER__
#define __LASER__

#include <Arduino.h>
#include "funciones.hpp"
#include <Wire.h>
#include <VL53L0X.h>


class LaserSensor
{
public:
  LaserSensor();
  bool init();
  int readLaser(side side_);

private:
  VL53L0X sensors[3];
};

#endif
