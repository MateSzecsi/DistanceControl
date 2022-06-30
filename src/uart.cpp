#include "uart.h"
#include <Arduino.h>

volatile bool uartReadFlag = false;

void setUartReadFlag(){
    uartReadFlag = true;
}

void sendDistance(unsigned distance){
    Serial.write((uint8_t)1);
    Serial.write((uint8_t) distance);
}

void sendLoad(int load){
    Serial.write((uint8_t)2);
    uint8_t array[2];
    array[0] = (uint8_t)(load >> 8);
    array[1] = (uint8_t)(load);
    Serial.write(array, 2);
}

unsigned readReferenceDistance(){
    if(Serial.available()){
        return (unsigned) Serial.read();
    }
    else
        return 0;
}

unsigned uartCycle(unsigned distance, int load){
    sendDistance(distance);
    sendLoad(load);
    return readReferenceDistance();
}