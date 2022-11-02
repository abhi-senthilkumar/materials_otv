#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H
#include <Arduino.h>
#include "Motor.h"
#include "Mission.h"

class Drivetrain {
  
  private:
    Motor& leftMotor;
    Motor& rightMotor;
    Mission& mission;
    
  public:
    Drivetrain(Motor& leftMotor, Motor& rightMotor, Mission& mission);
    void init();
    void brake();
    void drive(int driveSpeed, int driveTime);
    void turn(int driveSpeed, int driveTime);
    void turnTo(double finalAngle);
    void goTo(double finalX, double finalY, double finalAngle);
};
#endif
