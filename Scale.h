#ifndef SCALE_H
#define SCALE_H
#include <Arduino.h>
#include "HX711.h"
#include "constants.h"
#include "Enes100.h"

class Scale {
  
  private:
    byte doutPin;
    byte sckPin;
    HX711 hx711_scale;
    
  public:
    Scale(byte doutPin, byte sckPin);
    void init();
    int read();
    int read(byte numReadings);
    byte getWeight();
};
#endif