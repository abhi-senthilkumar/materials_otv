#include "Claw.h"

Claw::Claw(byte rotateL, byte rotateR, byte grab)
{
    this->pwm1 = rotateL;
    this->pwm2 = rotateR;
    this->pwm3 = grab;
    init();
}

void Claw::init()
{
    resetRotation();
    release();
}

void Claw::grab()
{
    servo3.attach(pwm3);
    servo3.write(20);
    servo3.detach();
}

void Claw::rotateBack()
{
    servo1.attach(pwm1);
    servo2.attach(pwm2);
    servo1.write(180);
    servo2.write(180);
    servo1.detach();
    servo2.detach();
}

void Claw::release()
{
    servo3.attach(pwm3);
    servo3.write(0);
    servo3.detach();
}

void Claw::resetRotation()
{
    servo1.attach(pwm1);
    servo2.attach(pwm2);
    servo1.write(0);
    servo2.write(0);
    servo1.detach();
    servo2.detach();
}