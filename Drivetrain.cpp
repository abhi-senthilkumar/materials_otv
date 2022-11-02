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

void Drivetrain::drive(int driveSpeed){
  leftMotor.drive(driveSpeed);
  rightMotor.drive(driveSpeed);
}

void Drivetrain::driveFor(int driveSpeed, int driveTime){
  drive(driveSpeed);
  delay(driveTime);
}

//positive means right and negative means left
void Drivetrain::turn(int driveSpeed){
  leftMotor.drive(driveSpeed);
  rightMotor.drive(-1 * driveSpeed);
}

void Drivetrain::turnFor(int driveSpeed, int driveTime){
  turn(driveSpeed);
  delay(driveTime);
}

//really bs way of doing it until i can think of a better way
//just rotate right until we are at the right angle
void Drivetrain::turnTo(double finalAngle){
  double startAngle = mission.getAngle();
  while(abs(mission.getAngle() - finalAngle) > 3){
    if(abs(mission.getAngle() - finalAngle) > 30){
      turn(DEFAULT_SPEED);
    }
    else{
      turn(DEFAULT_SPEED / 2);
    }
  }  
}

//really bs way of doing this until i come up with a better way
//rotate right until correct angle and then drive until within ballpark of point 
void Drivetrain::goTo(double finalX, double finalY, double finalAngle){
  //first we will turn to point towards the new x and y location
  double startX = mission.getX();
  double startY = mission.getY();
  double startAngle = mission.getAngle();
  double driveAngle = atan2(finalY - startY,finalX - startX);
  turnTo(driveAngle);
  while(abs(mission.getX() - finalX) > 5 && abs(mission.getY() - finalY) > 5){
    if(abs(mission.getX() - finalX) > 5 && abs(mission.getY() - finalY) > 30){
      drive(DEFAULT_SPEED);
    }
    else{
      drive(DEFAULT_SPEED / 2);
    }
  }
}
