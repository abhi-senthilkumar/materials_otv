#ifndef SERVO_H
#define SERVO_H
#include <Arduino.h>
class Servo
{

private:
    byte pin;

public:
    Servo(byte pin);
    void init();
    void reset();
    void setPos(byte angle);
};
#endif