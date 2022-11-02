#include "Drivetrain.h"

Drivetrain::Drivetrain(Motor& refLeftMotor, Motor& refRightMotor, Mission& refMission)
  :leftMotor(refLeftMotor), 
  rightMotor(refRightMotor),
  mission(refMission){
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

void Drivetrain::turnTo(double finalAngle){
  double startAngle = mission.getAngle();
  double turnAngle;
  //figuring out whether to turn left or right
  
}

void Drivetrain::goTo(double finalX, double finalY, double finalAngle){
  //first we will turn to point towards the new x and y location
  double startX = mission.getX();
  double startY = mission.getY();
  double startAngle = mission.getAngle();
  double driveAngle = atan2(finalY - startY,finalX - startX);
  
}
