#include "controller.h"
#include "NewPing.h"
#include <Arduino.h>
#include "config.h"
#include "motor.h"

    void Controller::updateData(){
        NewPing sonar(PIN_SENSOR_TRIGGER, PIN_SENSOR_ECHO, 40);
        int distance = SPEED_OF_SOUND * ((float)(sonar.ping_median()) / 10000 / 2);
        currentDistance = distance;
        error = (int)currentDistance - referenceDistance;
        integralValue += error;
    }

    void Controller::calculateAndSetLoad(){
        updateData();
        if((currentLoad == 0 && abs(error) < MIN_TRAVELLED_DISTANCE) || currentDistance == 0){
            integralValue = 0;
            currentLoad = 0;
        }
        else{
            if(integralValue * CONTROL_VARIABLE_KI <= (-MAX_LOAD))
                integralValue = (int)((float)(-MAX_LOAD) / CONTROL_VARIABLE_KI);
            else if(integralValue * CONTROL_VARIABLE_KI >= MAX_LOAD)
                integralValue = (int)((float)(MAX_LOAD) / CONTROL_VARIABLE_KI);
            currentLoad = CONTROL_VARIABLE_KI * integralValue + CONTROL_VARIABLE_KP * (error);
        }
        
        if(currentLoad != 0){
            setLoad(abs(currentLoad), currentLoad/abs(currentLoad));
        }  
        else
            setLoad(0, 0);
    }

    unsigned Controller::getCurrentDistance(){
        return currentDistance;
    }
    int Controller::getCurrentLoad(){
        return currentLoad;
    }

    void Controller::setReferenceDistance(unsigned referenceDistance_p){
        referenceDistance = referenceDistance_p;
    }