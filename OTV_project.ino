#include "Enes100.h"
#include "constants.h"
#include "HX711.h"
#include "Motor.h"
#include "Drivetrain.h"
#include <Servo.h>

// https://roboticsbackend.com/arduino-object-oriented-programming-oop/
// CREATE CLASS FOR THE MOTORS, DRIVETRAIN

HX711 scale;
Motor leftMotor(MOTOR_1_DIRECTION, MOTOR_1_SPEED);
Motor rightMotor(MOTOR_2_DIRECTION, MOTOR_2_SPEED);
Drivetrain drivetrain(leftMotor, rightMotor);
int pos = 0;

void setup() {
  scale.begin(WEIGHT_SENSOR_DOUT, WEIGHT_SENSOR_SCK);
}


void loop() {
  
}
