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
Servo myServo;
int pos = 0;

void setup() {
  scale.begin(WEIGHT_SENSOR_DOUT, WEIGHT_SENSOR_SCK);
  myServo.attach(9);
}


void loop() {
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myServo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myServo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  //leftMotor.forward(DEFAULT_SPEED);
  //rightMotor.forward(DEFAULT_SPEED);
}
