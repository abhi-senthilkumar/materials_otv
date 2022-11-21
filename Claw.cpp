#include "Claw.h"

Claw::Claw(byte rotateL, byte rotateR, byte grab)
{
    this->pwm1 = rotateL;
    this->pwm2 = rotateR;
    this->pwm3 = grab;
}

void Claw::init()
{
    servo1.attach(pwm1);
    servo2.attach(pwm2);
    servo3.attach(pwm3);
    resetRotation();
    release();
}

void Claw::grab()
{
    servo3.write(20);
}

void Claw::rotateBack()
{
    for (int i = 0; i < 100; i++)
    {
        servo1.write(90 - i);
        servo2.write(i);
        delay(50);
    }
}

void Claw::release()
{
    servo3.write(40);
}

void Claw::resetRotation()
{
    servo1.write(90);
    servo2.write(0);
}

void Claw::end()
{
    servo1.detach();
    servo2.detach();
    servo3.detach();
}