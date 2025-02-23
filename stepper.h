//=====[#include guards - begin]===============================================

#ifndef _STEPPER_H_
#define _STEPPER_H_

//=====[Declaration of public defines]=========================================

//=====[Declaration of public data types]======================================

//=====[Declarations (prototypes) of public functions]=========================

void stepperControlInit();
void stepperControlUpdate();
void stepperRotationsWrite(int rotations);
bool stepperReady();

//=====[#include guards - end]=================================================

#endif