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
  //mission.println("driving for " + String(driveTime) + " milliseconds at " + String(driveSpeed) + " m/s");
  delay(driveTime);
  brake();
}

//positive means right and negative means left
void Drivetrain::turn(int driveSpeed){
  leftMotor.drive(-1 * driveSpeed);
  rightMotor.drive(driveSpeed);
}

void Drivetrain::turnFor(int driveSpeed, int driveTime){
  turn(driveSpeed);
  delay(driveTime);
  brake();
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

double Drivetrain::getTimeToTurn(double angle, double turnFrac){
  //mission.println("angle: " + String(angle) + ", dps: " + String(MAX_DPS) + ", turnFrac: " + String(turnFrac) + ", time: " + String(1000 * angle / (MAX_DPS * turnFrac)));
  return 1000 * abs(angle) / (MAX_DPS * turnFrac);
}

void Drivetrain::turnTo(double finalAngle, double turnFrac){
  double dist = abs(mission.getAngle() - finalAngle);
  mission.println("turning");
  while(dist > TURN_SENSITIVITY){
    dist = abs(mission.getAngle() - finalAngle);
    //mission.println("angle diff: " + String(dist) + ", speed: " + String(getSpeed(dist, true)));
    turn(getTurnDirection(mission.getAngle(), finalAngle) * MAX_SPEED * turnFrac * getSpeed(dist, true));
  }
}

double Drivetrain::getTimeToDrive(double distance, double driveFrac){
  //mission.println("distance: " + String(distance) + ", mps: " + String(MAX_MPS) + ", driveFrac: " + String(driveFrac) + ", time: " + String(1000 * distance / (MAX_MPS * driveFrac)));
  return 1000 * distance / (MAX_MPS * driveFrac);
}

double Drivetrain::getSpeed(double dist, bool turn){
  if(turn) return dist <= 45 ? max(min(1, dist / (45 * 1.2)), 0.4) : 1;
  else return dist <= 1 ? max(min(1, dist * 3), 0.4) : 1;
}

double Drivetrain::getCorrectionAmount(double currentX, double currentY, double currentAngle, double finalX, double finalY){
  double correctAngle = atan2(finalY - currentY, finalX - currentX) * 180 / 3.1415;
  if(abs(correctAngle - currentAngle) > TURN_SENSITIVITY) {
    return getTurnDirection(currentAngle, correctAngle);
  }
  else return 0;
}

void Drivetrain::goTo(double finalX, double finalY, double finalAngle, double driveFrac, int forward){
  double startX = mission.getX();
  double startY = mission.getY();
  double startAngle = mission.getAngle();
  double turnAngle = atan2(finalY - startY,finalX - startX) * 180 / 3.1415;
  if(forward != 1){
    turnAngle = turnAngle + 180 > 180 ? turnAngle - 180 : turnAngle + 180;
  }
  mission.println("y: " + String(finalY - startY) + ", x: " + String(finalX - startX) + ", atan2: " + String(turnAngle));
  turnTo(turnAngle);
  double dist = sqrt(pow(mission.getX() - finalX, 2)+ pow(mission.getY() - finalY, 2));
  while(dist > DRIVE_SENSITIVITY){
    double curX = mission.getX();
    double curY = mission.getY();
    double curAngle = mission.getAngle();
    dist = sqrt(pow(curX - finalX, 2)+ pow(curY - finalY, 2));
    //mission.println("dist: " + String(dist) + ", getSpeed: " + String(getSpeed(dist)) + "speed: " + String(forward * MAX_SPEED * driveFrac * getSpeed(dist)));
    double speed = forward * MAX_SPEED * driveFrac * getSpeed(dist);
    double correction = getCorrectionAmount(curX, curY, curAngle, finalX, finalY);
    driveTank(min(speed - correction * 30, 255), min(speed + correction * 30, 255));
	}
  //mission.println("stopped moving");
	brake();
  turnTo(finalAngle);
}