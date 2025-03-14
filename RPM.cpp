//=====[Libraries]=============================================================

#include <Arduino.h>

//=====[Declaration of private defines]========================================

#define RPM_PIN A7

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

bool isRPMLow;

//=====[Declarations (prototypes) of private functions]========================

void updateRPMState();

//=====[Implementations of public functions]===================================


void initRPM() {
    pinMode(RPM_PIN,INPUT);
}
  
void updateRPM() {
    updateRPMState();
}

bool readRPM(){
    return isRPMLow;
}

//=====[Implementations of private functions]==================================

void updateRPMState(){
    int button = digitalRead(RPM_PIN);
    if (button == 1){
        isRPMLow = true;
    } else {
        isRPMLow = false;
    }
}
