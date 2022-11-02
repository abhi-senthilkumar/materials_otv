#include "constants.h"
#include "Enes100.h"
#include "HX711.h"
#include "Motor.h"
#include "Drivetrain.h"
#include "Scale.h"

VisionSystemClient Enes100;
Mission mission(TEAM_NAME, MATERIAL, ARUCO_ID, WIFI_RX, WIFI_TX, Enes100);
//Scale scale(WEIGHT_SENSOR_DOUT, WEIGHT_SENSOR_SCK);
Motor leftMotor(MOTOR_1_DIRECTION, MOTOR_1_SPEED);
Motor rightMotor(MOTOR_2_DIRECTION, MOTOR_2_SPEED);
Drivetrain drivetrain(leftMotor, rightMotor, mission);

void setup() {
  Serial.begin(9600);
  //scale.init();
}


void loop() {
  //leftMotor.drive(DEFAULT_SPEED);
  //delay(5000);
  //leftMotor.drive(-1 * DEFAULT_SPEED / 2);
  //delay(5000);
  drivetrain.driveFor(DEFAULT_SPEED, 5000);
  drivetrain.turnFor(DEFAULT_SPEED, 1000);
  drivetrain.driveFor(-1 * DEFAULT_SPEED, 5000);
  drivetrain.turnFor(-1 * DEFAULT_SPEED, 1000);
  /*Serial.print("HX711 reading: ");
  Serial.println(scale.read(5));
  delay(100);
  Serial.println(scale.getWeight());
  delay(1000);*/
}
