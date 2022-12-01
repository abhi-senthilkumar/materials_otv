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
    servo3.write(10);
}

void Claw::rotateBack()
{
    for (int i = 0; i <= 105; i++)
    {
        servo1.write(105 - i);
        servo2.write(75 + i);
        delay(50);
    }
}

void Claw::release()
{
    servo3.write(40);
}

void Claw::resetRotation()
{
    servo1.write(105);
    servo2.write(75);
}

void Claw::end()
{
    servo1.detach();
    servo2.detach();
    servo3.detach();
}