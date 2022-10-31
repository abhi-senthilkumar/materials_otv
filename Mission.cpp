#include "Mission.h"

Mission::Mission(char* teamName, byte missionType, byte arucoID, byte rxPin, byte txPin){
    this->teamName = teamName;
    this->missionType = missionType;
    this->arucoID = arucoID;
    this->rxPin = rxPin;
    this->txPin = txPin;
    init();
}

void Mission::init(){
    Enes100.begin(teamName, missionType, arucoID, rxPin, txPin);
}

void updateLocation(){
    while(!Enes100.updateLocation()){

    }
}

double getX(){
    updateLocation();
    return Enes100.location.x;
}

double getY(){
    updateLocation();
    return Enes100.location.y;
}

double getAngle(bool degrees){
    updateLocation();
    if(degrees){
        return Enes100.location.theta * 180 / 3.14;
    }
    return Enes100.location.theta;
}

void updateBlockWeight(byte weight){
    Enes100.mission(WEIGHT, weight);
}

void updateBlockMaterial(byte material){
    Enes100.mission(MATERIAL, material);
}