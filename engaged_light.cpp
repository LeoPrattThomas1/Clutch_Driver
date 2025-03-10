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

#include "engaged_light.h"
#include "button.h"
#include "stepper.h"
#include "clutch_driver_system.h"
#include <Arduino.h>

//=====[Declaration of private defines]========================================

#define LED_PULSE_TIME_US 100000

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

lightStates lightState = OFF;
int lightPin = 7;
int lightTimeInc = 0;
bool lightStateLogic = false;


//=====[Declarations (prototypes) of private functions]========================

void updateLightState();
void loadEngagedLight();

//=====[Implementations of public functions]===================================

void initEngagedLight() {
    pinMode(lightPin,OUTPUT);

    digitalWrite(lightPin, LOW);
}


void updateEngagedLight() {
    lightTimeInc = lightTimeInc + SYSTEM_TIME_INCREMENT_US;
    updateLightState();
    loadEngagedLight();
}


//set light engaged steps
void turnOnEngagedLight() {
    lightState = ON;
    digitalWrite(lightPin, HIGH);
}

void turnOffEngagedLight() {
    lightState = OFF;
    digitalWrite(lightPin, LOW);
}

void raiseLightError() {
    lightState = ERROR;
    digitalWrite(lightPin, LOW);
    lightStateLogic = false;
}



//=====[Implementations of private functions]==================================

void loadEngagedLight(){
    if (isStepperReady()){
        if (getDirection() == UP){
            turnOnEngagedLight();
        
        } else if (getDirection() == DOWN){
            turnOffEngagedLight();
        
        }
    }
}

void updateLightState(){
    if (lightState == ERROR && lightTimeInc >= LED_PULSE_TIME_US){
        lightStateLogic = !lightStateLogic;
        
        if (lightStateLogic) { digitalWrite(lightPin, HIGH); }
        else { digitalWrite(lightPin, HIGH); }

    }
}
