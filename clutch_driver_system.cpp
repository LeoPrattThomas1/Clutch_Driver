//=====[Libraries]=============================================================

#include "clutch_driver_system.h"
#include "stepper.h"
#include "button.h"
#include "engaged_light.h"
#include <Arduino.h>


//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

void initClutchDriverSystem(){
    initButton();
    initEngagedLight();

    stepperControlInit();
    stepperRotationsWrite(1);
}
void updateClutchDriverSystem(){
    stepperControlUpdate();
    updateButton();


    //testing purpes will move to engadged light system
    if (buttonFalling()) {
        // Serial.println("button falling");
    }

    if (readButton()) {
      turnOnEngagedLight();
    } else {
      turnOffEngagedLight();
    }
    updateEngagedLight();

    delayMicroseconds(SYSTEM_TIME_INCREMENT_US);
}

//=====[Implementations of private functions]==================================
