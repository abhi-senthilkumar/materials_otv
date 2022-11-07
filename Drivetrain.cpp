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

void Drivetrain::driveTank(int leftSpeed, int rightSpeed){
  leftMotor.drive(leftSpeed);
  rightMotor.drive(rightSpeed);
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

//d is finalAngle - startAngle
//s is sign(d)
//m is + if |d| > 180, else -
//t is + if turn right, else -
//s m t
//- - +
//+ + +
//- + -
//+ - -
//from this we can see that t is just s * m 
int Drivetrain::getTurnDirection(double startAngle, double finalAngle){
    int diff = int(finalAngle - startAngle);
    int sign = abs(diff) / diff;
    int gt180 = abs(diff) > 180 ? 1 : -1;
    return sign * gt180;
}

void Drivetrain::turnTo(double finalAngle){
  while(abs(mission.getAngle() - finalAngle > TURN_SENSITIVITY)){
    turn(getTurnDirection(mission.getAngle(), finalAngle) * DEFAULT_SPEED);
  }
  brake();
}

void Drivetrain::goTo(double finalX, double finalY, double finalAngle){
  double startX = mission.getX();
  double startY = mission.getY();
  double startAngle = mission.getAngle();
  double driveAngle = atan2(finalY - startY,finalX - startX);
  turnTo(driveAngle);
  while(sqrt(pow(mission.getX() - finalX, 2)+ pow(mission.getY() - finalY, 2)) > DRIVE_SENSITIVITY){
    drive(DEFAULT_SPEED);
	}
	brake();
}