//=====[Libraries]=============================================================

#include "stepper.h"
#include "clutch_driver_system.h"
#include <Arduino.h>

//=====[Declaration of private defines]========================================

#define ENABLE_WT_TIME 200  //us
#define DIR_FLIP_WT_TIME 10 //us 
#define STARTUP_TIME 200    //s
#define PERIOD 170          //us
#define PULSE_PER_REV 1000  //us



//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

int dirPin = 9;
int pulPin = 8;

int pulseDelayTimeIncrement = 0;
int stepsLeft = 0;
bool pulseDir = true;

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

void stepperUpdateStep();
void updatePulseDir();

//=====[Implementations of public functions]===================================

void stepperControlInit()
{


    pinMode(pulPin,OUTPUT);
    pinMode(dirPin,OUTPUT);

    //set dir and pul
    digitalWrite(pulPin,HIGH);
    digitalWrite(dirPin,HIGH);
    delay(STARTUP_TIME); //fix this later
}

void stepperControlUpdate(){
    pulseDelayTimeIncrement = pulseDelayTimeIncrement + SYSTEM_TIME_INCREMENT_US;
    stepperUpdateStep();
    updatePulseDir();
}

void stepperRotationsWrite(int rotations) {
    //times two because we measure on the rising and falling edge
    stepsLeft += rotations * PULSE_PER_REV*2;
}


//is true if the servo is not busy
bool stepperReady(){
    return stepsLeft <= 0;
}

//=====[Implementations of private functions]==================================


// this function runs a Pulse step every period
void stepperUpdateStep() {

    // will only run if time inc is correct and there are steps left
    if (pulseDelayTimeIncrement >= PERIOD/2 && stepsLeft >= 0) {

        pulseDir = !pulseDir; //flips pulse

        stepsLeft = stepsLeft - 1; //remove a step from the system

        pulseDelayTimeIncrement = 0; //reset time inc

    }
}

//set the pulse state to the pulseDir var
void updatePulseDir(){
    if (pulseDir) {
        digitalWrite(pulPin,HIGH);
    } else {
        digitalWrite(pulPin,LOW);
    }
}

/*motorDirection_t motorDirectionRead()
{
    return motorDirection;
}

void motorDirectionWrite( motorDirection_t direction )
{
    motorDirection = direction;
}

void motorControlUpdate()
{
    static int motorUpdateCounter = 0;
    
    motorUpdateCounter++;
    
    if ( motorUpdateCounter > MOTOR_UPDATE_TIME ) {
        
        motorUpdateCounter = 0;
        
        switch ( motorState ) {
            case DIRECTION_1:
                if ( motorDirection == DIRECTION_2 || 
                     motorDirection == STOPPED ) {
                    motorM1Pin.input();
                    motorM2Pin.input();
                    motorState = STOPPED;
                }
            break;
    
            case DIRECTION_2:
                if ( motorDirection == DIRECTION_1 || 
                     motorDirection == STOPPED ) {
                    motorM1Pin.input();
                    motorM2Pin.input();
                    motorState = STOPPED;
                }
            break;
    
            case STOPPED:
            default:
                if ( motorDirection == DIRECTION_1 ) {
                    motorM2Pin.input();
                    motorM1Pin.output();
                    motorM1Pin = LOW;
                    motorState = DIRECTION_1;
                }
                
                if ( motorDirection == DIRECTION_2 ) {
                    motorM1Pin.input();
                    motorM2Pin.output();
                    motorM2Pin = LOW;
                    motorState = DIRECTION_2;
                }
            break;
        }
    }        
}*/
