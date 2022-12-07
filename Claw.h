#ifndef CLAW_H
#define CLAW_H
#include <Arduino.h>
#include "constants.h"
#include <Servo.h>

class Claw
{

private:
    byte pwm1;
    byte pwm2;
    byte pwm3;
    Servo servo1;
    Servo servo2;
    Servo servo3;

public:
    Claw(byte rotateL, byte rotateR, byte grab);
    void init();
    void grab();
    void rotateBack();
    void release();
    void open();
    void smallRotate();
    void resetRotation();
    void end();
};
#endif