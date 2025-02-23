//=====[#include guards - begin]===============================================

#ifndef _BUTTON_H_
#define _BUTTON_H_

//=====[Declaration of public defines]=========================================

//=====[Declaration of public data types]======================================

typedef enum { BUTTON_UP, BUTTON_FALLING, BUTTON_DOWN, BUTTON_RISING } buttonState_t; 

//=====[Declarations (prototypes) of public functions]=========================

void initButton();
void updateButton();
bool readButton();
bool buttonFalling();

//=====[#include guards - end]=================================================

#endif