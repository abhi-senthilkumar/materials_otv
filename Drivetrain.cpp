#include "Drivetrain.h"

Drivetrain::Drivetrain(Motor leftMotor, Motor rightMotor){
  this->leftMotor = leftMotor;
  this->rightMotor = rightMotor;
  init();
}

void Drivetrain::init(){
  off();
}

void Drivetrain::brake(){
  leftMotor.off();
  rightMotor.off();
}

void Drivetrain::drive(int driveSpeed, int driveTime){
  leftMotor.drive(driveSpeed);
  rightMotor.drive(driveSpeed);
  delay(driveTime);
}

void Drivetrain::turn(int driveSpeed, int driveTime){
  leftMotor.drive(driveSpeed);
  rightMotor.drive(-1 * driveSpeed);
  delay(driveTime);
}
