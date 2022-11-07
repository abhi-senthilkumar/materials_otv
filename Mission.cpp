#include "Mission.h"

Mission::Mission(String teamName, byte missionType, byte arucoID, byte rxPin, byte txPin, VisionSystemClient& refEnes100)
    :Enes100(refEnes100){
    this->teamName = teamName;
    this->missionType = missionType;
    this->arucoID = arucoID;
    this->rxPin = rxPin;
    this->txPin = txPin;
    //init();
}

void Mission::init(){
    const char *teamName_char = teamName.c_str();
    bool a = Enes100.begin(teamName_char, missionType, arucoID, rxPin, txPin);
    Serial.println(a);
}

void Mission::updateLocation(){
    while(!Enes100.updateLocation()){
        Serial.println("updating location");
    }
}

double Mission::getX(){
    updateLocation();
    return Enes100.location.x;
}

double Mission::getY(){
    updateLocation();
    return Enes100.location.y;
}

double Mission::getAngle(bool degrees){
    updateLocation();
    if(degrees){
        return Enes100.location.theta * 180 / 3.1415;
    }
    return Enes100.location.theta;
}

void Mission::updateBlockWeight(byte weight){
    Enes100.mission(WEIGHT, weight);
}

void Mission::updateBlockMaterial(byte material){
    Enes100.mission(MATERIAL, material);
}