//#ifndef _CONFIG_H_
#define _CONFIG_H_

// Physics constants
#define SPEED_OF_SOUND 331 //m/s

// Environment
#define IS_TESTING 0

// Properties of controller
#define CONTROL_VARIABLE_KI 0.3
#define CONTROL_VARIABLE_KP 10


// Properties of the ultrasound sensor (in mm)
#define SENSOR_MIN_DISTANCE 20
#define SENSOR_MAX_DISTANCE 4000
#define NUM_OF_SENSOR_DATA 10

// Properties of the motor controller
#define MAX_SPEED 4 //[km/h]
#define MIN_TRAVELLED_DISTANCE 5 //cm
#define MIN_LOAD 50
#define MAX_LOAD 100

#define ANALOG_WRITE_MAX 255

// Properties of project implementation
#define MAX_DISTANCE SENSOR_MAX_DISTANCE
#define MIN_DISTANCE SENSOR_MIN_DISTANCE

// Pin configs
//positions of ultrasound sensor pins
#define PIN_SENSOR_TRIGGER 3
#define PIN_SENSOR_ECHO 47

//positions of h-bridge pins for controlling the dc motor
#define H_BRIDGE1_IN_A 26
#define H_BRIDGE1_IN_B 27
#define H_BRIDGE1_PWM 4

//#endif