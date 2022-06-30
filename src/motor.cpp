#include "motor.h"
#include "Arduino.h"
#include "config.h"

// Set the speed (range of 0, minimum load-maximum load), and direction ("1" forward else backwords direction) of the motor
void setLoad(uint16_t load, int sign){
    if(sign == 1){
        digitalWrite(H_BRIDGE1_IN_A, HIGH);
        digitalWrite(H_BRIDGE1_IN_B, LOW);
    }
    else{
        digitalWrite(H_BRIDGE1_IN_A, LOW);
        digitalWrite(H_BRIDGE1_IN_B, HIGH);
    }
    if(load >= MIN_LOAD) //motor operational range
    {
        if(load >= MAX_LOAD)
            analogWrite(H_BRIDGE1_PWM, ANALOG_WRITE_MAX);
        else
            analogWrite(H_BRIDGE1_PWM, (int)((float)(load) / MAX_LOAD * ANALOG_WRITE_MAX));
    }
    else
        analogWrite(H_BRIDGE1_PWM, 0);
}