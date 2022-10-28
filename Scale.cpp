#include "Scale.h"

Scale::Scale(byte doutPin, byte sckPin){
  this->doutPin = doutPin;
  this->sckPin = sckPin;
  init();
}

void Scale::init(){
    hx711_scale.begin(doutPin, sckPin);
    hx711_scale.set_scale(SCALE_SCALE);
    hx711_scale.tare();
}

long Scale::read(){
    if(hx711_scale.is_ready()){
        long reading = hx711_scale.get_units();
        return reading;
    }
    else return 0;
}

long Scale::read(byte num_readings){
    if(hx711_scale.is_ready()){
        long reading = hx711_scale.get_units(num_readings);
        return reading;
    }
    else return 0;
}

byte Scale::getWeight(){
    long reading = read(5);
    long lightDistance = abs(reading - LIGHT_AVG);
    long mediumDistance = abs(reading - MEDIUM_AVG);
    long heavyDistance = abs(reading - HEAVY_AVG);
    if(lightDistance < mediumDistance && lightDistance < heavyDistance){
        return LIGHT;
    }
    else if(mediumDistance < lightDistance && mediumDistance < heavyDistance){
        return MEDIUM;
    }
    else{
        return HEAVY;
    }
}