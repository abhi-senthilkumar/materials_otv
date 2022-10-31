#ifndef MISSION_H
#define MISSION_H
#include <Arduino.h>
#include "Enes100.h"

class Mission {
  
  private:
    char* teamName;
    byte missionType;
    byte arucoID;
    byte txPin;
    byte rxPin;

  public:
    Mission(char* teamName, byte missionType, byte arucoID, byte rxPin, byte txPin);
    void init();
    void updateLocation();
    double getX();
    double getY();
    double getAngle(bool degrees = true);
    void updateBlockWeight(byte weight);
    void updateBlockMaterial(byte material);
};
#endif
