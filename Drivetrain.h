#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H
#include <Arduino.h>
#include "Motor.h"

class Drivetrain {
  
  private:
    Motor& leftMotor;
    Motor& rightMotor;
    
  public:
    Drivetrain(Motor& leftMotor, Motor& rightMotor);
    void init();
    void brake();
    void drive(int driveSpeed, int driveTime);
    void turn(int driveSpeed, int driveTime);
};
#endif
