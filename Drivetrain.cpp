#include "Drivetrain.h"

Drivetrain::Drivetrain(Motor& refLeftMotor, Motor& refRightMotor)
  :leftMotor(refLeftMotor), 
  rightMotor(refRightMotor){
  init();
}

void Drivetrain::init(){
  brake();
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
