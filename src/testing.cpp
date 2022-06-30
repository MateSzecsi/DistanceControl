#include "testing.h"
#include <Arduino.h>
#include "NewPing.h"
#include "motor.h"
#include "config.h"

void motorTest();

void testing(){
    motorTest();
}

void motorTest(){
    NewPing sonar(PIN_SENSOR_TRIGGER, PIN_SENSOR_ECHO, 40);
    int distance = sonar.ping_cm();
    //setSpeed((int)((float)(distance)/40*255), 1);
    setLoad(85,0);
}

void sensorTest(){
    NewPing sonar(PIN_SENSOR_TRIGGER, PIN_SENSOR_ECHO, 40);
    int distance = sonar.ping_cm();
    Serial.println(distance);
    delay(100);
}