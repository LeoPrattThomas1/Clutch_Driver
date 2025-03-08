/*
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

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
bool isButtonRising = false;
bool enterButton = false;

// debounceButton variables
int accumulatedDebounceButtonTime = 0; 
int numberOfEnterButtonReleasedEvents = 0; 
buttonState_t enterButtonState; 
bool lastButtonState;


//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

void debounceButtonUpdate(); 
void debounceButtonInit();
void updateEnterButton();


//=====[Implementations of public functions]===================================

void initButton() {
    pinMode(buttonPin,INPUT);


    // setup debounce
    updateEnterButton();
    debounceButtonInit();
}

void updateButton() {


    updateEnterButton();
    debounceButtonUpdate(); 

    // Serial.println(enterButtonState);

    //funtion at end of code
    if (enterButtonState == BUTTON_UP){
      lastButtonState = true;
    } else if (enterButtonState == BUTTON_DOWN) {
      lastButtonState = false;
    }
}

//gives the state of the button debounced
bool readButton(){
    if (enterButtonState == BUTTON_UP){
      return true;
    } else if (enterButtonState == BUTTON_DOWN) {
      return false;
    } else {
      return lastButtonState;
    }
}

//is only true when the button is done falling
bool buttonFalling(){
    return isButtonFalling; 
}

//is only true when the button is rising
bool buttonRising(){
    return isButtonRising; 
}

//=====[Implementations of private functions]==================================

//updates enterbutton into a boolean varible
void updateEnterButton(){
  int button = digitalRead(buttonPin);
  if (button == 1){
    enterButton = true;
  } else {
    enterButton = false;
  }
}

void debounceButtonInit(){ 
    if( enterButton ) {
        enterButtonState = BUTTON_DOWN;    
    } else {
        enterButtonState = BUTTON_UP;    
    }
}

void debounceButtonUpdate() { 
    isButtonFalling = false;
    isButtonRising = false; 

    switch( enterButtonState ) {
        case BUTTON_UP:
            if( !enterButton ) {
                enterButtonState = BUTTON_FALLING;            
                accumulatedDebounceButtonTime = 0;        
            }         
            break;    
        case BUTTON_FALLING:
            if( accumulatedDebounceButtonTime >= DEBOUNCE_BUTTON_TIME_MS * 1000 ) {}
                if( !enterButton ) { 
                    isButtonFalling = true;
                    enterButtonState = BUTTON_DOWN;
                } else {
                    enterButtonState = BUTTON_UP;
                }
            accumulatedDebounceButtonTime = accumulatedDebounceButtonTime + SYSTEM_TIME_INCREMENT_US;
            break;
        case BUTTON_DOWN: 
            if( enterButton ) {
                enterButtonState = BUTTON_RISING; 
                accumulatedDebounceButtonTime = 0; 
            }  
            break;
        case BUTTON_RISING: 
            if( accumulatedDebounceButtonTime >= DEBOUNCE_BUTTON_TIME_MS * 1000 ) {
                if( enterButton ) {
                    enterButtonState = BUTTON_UP;
                    isButtonRising = true;
                } else {
                 enterButtonState = BUTTON_DOWN;
                }
            }
            accumulatedDebounceButtonTime = accumulatedDebounceButtonTime + SYSTEM_TIME_INCREMENT_US; 
            break;
        default:
            debounceButtonInit(); 
            Serial.println("FAIL ON DEBOUNCE");
            break;
    } 
}