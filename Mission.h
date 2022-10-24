#ifndef MISSION_H
#define MISSION_H
#include <Arduino.h>
#include "Enes100.h"

class Drivetrain {
  
  private:
    Motor leftMotor;
    Motor rightMotor;
    
  public:
    Drivetrain(Motor leftMotor, Motor rightMotor);
    void init();
    void brake();
    void drive();
    void turn();
};
#endif
