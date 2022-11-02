#ifndef MISSION_H
#define MISSION_H
#include <Arduino.h>
#include "Enes100.h"

class Mission {
  
  private:
    String teamName;
    byte missionType;
    byte arucoID;
    byte txPin;
    byte rxPin;
    VisionSystemClient& Enes100;

  public:
    Mission(String teamName, byte missionType, byte arucoID, byte rxPin, byte txPin, VisionSystemClient& Enes100);
    void init();
    void updateLocation();
    double getX();
    double getY();
    double getAngle(bool degrees = true);
    void updateBlockWeight(byte weight);
    void updateBlockMaterial(byte material);
};
#endif
