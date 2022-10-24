#include "Motor.h"

Motor::Motor(byte directionPin, byte speedPin){
  this->directionPin = directionPin;
  this->speedPin = speedPin;
  init();
}

void Motor::init(){
  pinMode(directionPin, OUTPUT);
  pinMode(speedPin, OUTPUT);
  off();
}

void Motor::drive(int motorSpeed){
  if(motorSpeed > 0) forward(motorSpeed);
  else if(motorSpeed < 0) backward(abs(motorSpeed));
  else off();
}

void Motor::forward(int motorSpeed){
  digitalWrite(directionPin, HIGH);
  analogWrite(speedPin, motorSpeed);
}

void Motor::backward(int motorSpeed){
  digitalWrite(directionPin, LOW);
  analogWrite(speedPin, motorSpeed);
}

void Motor::off(){
  analogWrite(speedPin, 0);
}
