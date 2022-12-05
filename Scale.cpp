#include "Scale.h"

Scale::Scale(byte doutPin, byte sckPin){
  this->doutPin = doutPin;
  this->sckPin = sckPin;
}

void Scale::init(){
    //Serial.println("started");
    hx711_scale.begin(doutPin, sckPin);
    hx711_scale.set_scale(SCALE_CONSTANT);
    hx711_scale.tare();
    //Serial.println("done");
}

int Scale::read(){
    if(hx711_scale.is_ready()){
        int reading = hx711_scale.get_units();
        return reading;
    }
    else{
        //Serial.println("scale not ready");
        delay(50);
        read();
    };
}

int Scale::read(byte num_readings){
    if(hx711_scale.is_ready()){
        int reading = hx711_scale.get_units(num_readings);
        return reading;
    }
    else{
        //Serial.println("scale not ready");
        delay(50);
        read(num_readings);
    }
}

byte Scale::getWeight(){
    int reading = read(5);
    int lightDistance = abs(reading - LIGHT_AVG);
    int mediumDistance = abs(reading - MEDIUM_AVG);
    int heavyDistance = abs(reading - HEAVY_AVG);

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