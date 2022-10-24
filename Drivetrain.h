#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H
#include <Arduino.h>
#include "Motor.h"

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
