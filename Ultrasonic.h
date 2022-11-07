#ifndef ULTRASONIC_H
#define ULTRASONIC_H
#include <Arduino.h>
#include "constants.h"

class Ultrasonic {
  
  private:
    byte trigPin;
    byte echoPin;
    
  public:
    Ultrasonic(byte trigPin, byte echoPin);
    void init();
    int getDistance();
    bool obstacleInView();
};
#endif