//=====[Libraries]=============================================================

#include "engaged_light.h"
#include <Arduino.h>

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

bool lightState = false;
int lightPin = 7;

//=====[Implementations of public functions]===================================

void initEngagedLight() {
    pinMode(lightPin,OUTPUT);

    digitalWrite(lightPin, LOW);
}

void updateEngagedLight() {

}

void turnOnEngagedLight() {
    lightState = true;
    digitalWrite(lightPin, HIGH);
}

void turnOffEngagedLight() {
    lightState = false;
    digitalWrite(lightPin, LOW);
}
//=====[Implementations of private functions]==================================