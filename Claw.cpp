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
<<<<<<< HEAD
        servo1.write(i);
        servo2.write(180-i);
=======
        servo1.write(105 - i);
        servo2.write(75 + i);
>>>>>>> fbf7ddfdb9fa473d2300aa5b3fbe43a46d00b575
        delay(50);
    }
}

void Claw::release()
{
    servo3.write(40);
}

void Claw::resetRotation()
{
<<<<<<< HEAD
    servo1.write(0);
    servo2.write(180);
=======
    servo1.write(105);
    servo2.write(75);
>>>>>>> fbf7ddfdb9fa473d2300aa5b3fbe43a46d00b575
}

void Claw::end()
{
    servo1.detach();
    servo2.detach();
    servo3.detach();
}