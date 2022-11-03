#include "Servo.h"

Servo::Servo(byte pin)
{
    this->pin = pin;
    init();
}

void Servo::init()
{
    pinMode(pin, OUTPUT);
}

void Servo::reset()
{
    digitalWrite(pin, 0);
}

void Servo::setPos(byte angle)
{
    byte pAngle = (angle / 180) * 255;
    digitalWrite(pin, pAngle);
}