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

#include "stepper.h"
#include "clutch_driver_system.h"
#include <Arduino.h>

//=====[Declaration of private defines]========================================

#define ENABLE_WT_TIME 200  //us
#define DIR_FLIP_WT_TIME 10 //us 
#define STARTUP_TIME 200    //ms
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

void initStepperControl()
{
    pinMode(pulPin,OUTPUT);
    pinMode(dirPin,OUTPUT);

    //set dir and pul
    digitalWrite(pulPin,HIGH);
    digitalWrite(dirPin,HIGH);
    delay(STARTUP_TIME); //fix this later
}

void updateStepperControl(){
    pulseDelayTimeIncrement = pulseDelayTimeIncrement + SYSTEM_TIME_INCREMENT_US;
    stepperUpdateStep();
    updatePulseDir();
}

void stepperRotationsWrite(float rotations) {
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

    //IF NEGATIVE THEN GO BACKWARDS 

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