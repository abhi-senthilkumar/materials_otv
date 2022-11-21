#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H
#include <Arduino.h>
#include "Motor.h"
#include "Mission.h"
#include "Constants.h"

class Drivetrain {
  
  private:
    Motor& leftMotor;
    Motor& rightMotor;
    Mission& mission;
    
  public:
    Drivetrain(Motor& leftMotor, Motor& rightMotor, Mission& mission);
    void init();
    void brake();
    void drive(int driveSpeed);
    void driveFor(int driveSpeed, int driveTime);
    void driveTank(int leftSpeed, int rightSpeed);
    double getTimeToTurn(double angle, double turnSpeed);
    int getTurnDirection(double startAngle, double finalAngle);
    double getSpeed(double dist, bool turn = false);
    double getCorrectionAmount(double currentX, double currentY, double currentAngle, double finalX, double finalY);
    void turn(int driveSpeed);
    void turnFor(int driveSpeed, int driveTime);
    void turnTo(double finalAngle, double turnFrac = DEFAULT_SPEED);
    double getTimeToDrive(double distance, double driveFrac);
    void goTo(double finalX, double finalY, double finalAngle, double driveFrac = DEFAULT_SPEED, int forward = 1);
};
#endif
