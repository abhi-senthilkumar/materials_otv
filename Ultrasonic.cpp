#include "Ultrasonic.h"

Ultrasonic::Ultrasonic(byte trigPin, byte echoPin){
    this->trigPin = trigPin;
    this->echoPin = echoPin;
    init();
}

void Ultrasonic::init(){
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

int Ultrasonic::getDistance(){
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    long duration = pulseIn(echoPin, HIGH);
    int distance = duration * ULTRASONIC_CONSTANT;
    return distance;
}

bool Ultrasonic::obstacleInView(){
    if(getDistance() <= OBSTACLE_CONSTANT) return true;
    return false;
}