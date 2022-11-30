#include "constants.h"
#include "Enes100.h"
#include "HX711.h"
#include "Motor.h"
#include "Drivetrain.h"
#include "Scale.h"
#include "Ultrasonic.h"
#include "Claw.h"

VisionSystemClient Enes100;
Mission mission(TEAM_NAME, MATERIAL, ARUCO_ID, WIFI_RX, WIFI_TX, Enes100);
Scale scale(WEIGHT_SENSOR_DOUT, WEIGHT_SENSOR_SCK);
Ultrasonic leftUltrasonic(ULTRASONIC_TRIG, ULTRASONIC_3_ECHO);
Ultrasonic backUltrasonic(ULTRASONIC_TRIG, ULTRASONIC_2_ECHO);
Ultrasonic rightUltrasonic(ULTRASONIC_TRIG, ULTRASONIC_1_ECHO);
Claw claw(SERVO_1_CONTROL, SERVO_2_CONTROL, SERVO_3_CONTROL);
Motor leftMotor(MOTOR_1_DIRECTION, MOTOR_1_SPEED);
Motor rightMotor(MOTOR_2_DIRECTION, MOTOR_2_SPEED);
Drivetrain drivetrain(leftMotor, rightMotor, mission);

void setup() {
  Serial.begin(9600);
  mission.init();
  backUltrasonic.init();
  rightUltrasonic.init();
  //claw.init();
  //scale.init();
}


void loop() {
  completeMission();
  delay(1000);
}

void completeMission(){
  navigateToMissionSite();
  navigatePastFirstRowOfObstacles();
  navigatePastSecondRowOfObstacles();
  navigatePastBar();
}

double getYPositionOfMissionSite(double offset = 0.05){
  if(mission.getY() > 1 ){
    return 0.55 + offset;
  }
  return 1.55 - offset;
}

double getXPositionOfMissionSite(double offset = 0.0){
  if(mission.getY() > 1 ){
    return 0.50 + offset;
  }
  return 0.6 - offset;
}

double getAngleTowardsMissionSite(){
  if(mission.getY() > 1){
    return -90.0;
  }
  return 90.0;
}

void navigateToMissionSite(){
  mission.println("BEGIN Navigate to mission site");
  drivetrain.goTo(getXPositionOfMissionSite(), getYPositionOfMissionSite(), getAngleTowardsMissionSite());
  mission.println("END Navigate to mission site");
}

void navigatePastFirstRowOfObstacles(){
  mission.println("BEGIN Navigate past first row of obstacles");
  drivetrain.goTo(1.0, 0.5, 179);
  mission.println("IP Drove to first obstacle");
  if(backUltrasonic.obstacleInView()){
    mission.println("IP First obstacle exists; ultrasonic value " + String(backUltrasonic.getDistance()));
    drivetrain.goTo(1.0, 1.0, 179);
    mission.println("IP Drove to second obstacle");
    if(backUltrasonic.obstacleInView()){
      mission.println("IP Second obstacle exists; ultrasonic value " + String(backUltrasonic.getDistance()));
      drivetrain.goTo(1.0, 1.5, 179);
      mission.println("IP Drove to third obstacle");
    }
  }
  mission.println("IP Driving past first row of obstacles");
  drivetrain.goTo(1.9, mission.getY(), 90);
  mission.println("END Navigate past first row of obstacles");
}

void navigatePastSecondRowOfObstacles(){
  mission.println("BEGIN Navigate past second row of obstacles");
  drivetrain.goTo(1.9, 0.5, 179);
  mission.println("IP Drove to first obstacle");
  if(backUltrasonic.obstacleInView()){
    mission.println("IP First obstacle exists; ultrasonic value " + String(backUltrasonic.getDistance()));
    drivetrain.goTo(1.9, 1.0, 179);
    mission.println("IP Drove to second obstacle");
    if(backUltrasonic.obstacleInView()){
      mission.println("IP Second obstacle exists; ultrasonic value " + String(backUltrasonic.getDistance()));
      drivetrain.goTo(1.9, 1.5, 179);
      mission.println("IP Drove to third obstacle");
    }
  }
  mission.println("IP Driving past second row of obstacles");
  drivetrain.goTo(3.0, mission.getY(), 90);
  mission.println("END Navigate past second row of obstacles");
}

void navigatePastBar(){
  mission.println("BEGIN Navigate past bar");
  drivetrain.goTo(3.0, 1.5, 0);
  drivetrain.goTo(3.7, 1.5, 0);
  mission.println("END Navigate past bar");
}