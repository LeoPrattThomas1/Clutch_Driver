//=====[Libraries]=============================================================

#include "button.h"
#include "clutch_driver_system.h"
#include <Arduino.h>

//=====[Declaration of private defines]========================================

#define DEBOUNCE_BUTTON_TIME_MS   40//40ms

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

int buttonPin = 4;
bool isButtonFalling = false; 
bool enterButton = false;

// debounceButton variables
int accumulatedDebounceButtonTime = 0; 
int numberOfEnterButtonReleasedEvents = 0; 
buttonState_t enterButtonState; 
bool lastButtonState;


//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

bool debounceButtonUpdate(); 
void debounceButtonInit();


//=====[Implementations of public functions]===================================

void initButton() {
    pinMode(buttonPin,INPUT);
    Serial.begin(9600);


    // setup debounce
    enterButton = digitalRead(buttonPin);
    debounceButtonInit();
}

void updateButton() {
    enterButton = digitalRead(buttonPin);
    
    debounceButtonUpdate(); 

    if (lastButtonState != readButton()){
      Serial.println("New direction");
    }

    // Serial.println(enterButtonState);

    //funtion at end of code
    if (enterButtonState == BUTTON_UP){
      lastButtonState = true;
    } else if (enterButtonState == BUTTON_DOWN) {
      lastButtonState = false;
    }
}

bool readButton(){
    if (enterButtonState == BUTTON_UP){
      return true;
    } else if (enterButtonState == BUTTON_DOWN) {
      return false;
    } else {
      return lastButtonState;
    }
}

bool buttonFalling(){
    return isButtonFalling; 
}

//=====[Implementations of private functions]==================================

void debounceButtonInit(){ 
    if( enterButton ) {
        enterButtonState = BUTTON_DOWN;    
    } else {
        enterButtonState = BUTTON_UP;    
    }
}


bool debounceButtonUpdate() { 
    bool enterButtonReleasedEvent = false;
    switch( enterButtonState ) {
        case BUTTON_UP:
            if( enterButton ) {
                enterButtonState = BUTTON_FALLING;            
                accumulatedDebounceButtonTime = 0;        
            }         
            break;    
        case BUTTON_FALLING:
            if( accumulatedDebounceButtonTime >= DEBOUNCE_BUTTON_TIME_MS ) {}
                if( enterButton ) { 
                    Serial.println("Button Falling");
                    enterButtonState = BUTTON_DOWN;
                } else {
                    enterButtonState = BUTTON_UP;
                }
            accumulatedDebounceButtonTime = accumulatedDebounceButtonTime + SYSTEM_TIME_INCREMENT_US;
            break;
        case BUTTON_DOWN: 
            if( !enterButton ) {
                enterButtonState = BUTTON_RISING; 
                accumulatedDebounceButtonTime = 0; 
            }  
            break;
        case BUTTON_RISING: 
            if( accumulatedDebounceButtonTime >= DEBOUNCE_BUTTON_TIME_MS ) {
                if( !enterButton ) {
                     Serial.println("Button Rising");
                    enterButtonState = BUTTON_UP;
                    enterButtonReleasedEvent = true;
                } 
            } else {
                enterButtonState = BUTTON_DOWN;
            }
            accumulatedDebounceButtonTime = accumulatedDebounceButtonTime + SYSTEM_TIME_INCREMENT_US; 
            break;
        default:
            debounceButtonInit(); 
            break;
    } 
    return enterButtonReleasedEvent;
}