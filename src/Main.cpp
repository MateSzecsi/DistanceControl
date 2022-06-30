#include <TimerOne.h>
#include "testing.h"
#include "config.h"
#include <Arduino.h>
#include <NewPing.h>
#include "controller.h"
#include "uart.h"

// Timer interrupt flag, and handler function

volatile bool SamplingRateFlag;

void setSamplingRateFlag(){
    SamplingRateFlag = true;
}

Controller controller;

void setup(){
    Serial.begin(9600);

    // Initialize pins
    pinMode(PIN_SENSOR_TRIGGER, OUTPUT);
    pinMode(PIN_SENSOR_ECHO, INPUT);
    pinMode(H_BRIDGE1_IN_A, OUTPUT);
    pinMode(H_BRIDGE1_IN_B, OUTPUT);
    pinMode(H_BRIDGE1_PWM, OUTPUT);

    // Initialize timer interrupt function
    Timer1.initialize();
    Timer1.attachInterrupt(setSamplingRateFlag, 20000);
}

void loop(){
    unsigned newReferenceDistance;
    if(SamplingRateFlag){
        controller.calculateAndSetLoad(); //updates control values, than calculates load
        //send and receive data to and from control panel
        newReferenceDistance = uartCycle(controller.getCurrentDistance(), controller.getCurrentLoad());
        if(newReferenceDistance != 0){
            controller.setReferenceDistance(newReferenceDistance);
        }
        SamplingRateFlag = false;
    }
#if(IS_TESTING)
    testing();
    delay(1);
#endif
}

