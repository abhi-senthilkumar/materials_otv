#ifndef MOTOR_H
#define MOTOR_H
#include <Arduino.h>
class Motor {
  
  private:
    byte directionPin;
    byte speedPin;
    
  public:
    Motor(byte directionPin, byte speedPin);
    void init();
    void drive();
    void off();
};
#endif
