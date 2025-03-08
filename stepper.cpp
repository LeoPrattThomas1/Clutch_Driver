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

#define ENABLE_WT_TIME 200000  //us
#define DIR_FLIP_WT_TIME 10 //us 
#define STARTUP_TIME 200    //ms
#define PERIOD 170          //us
#define PULSE_PER_REV 1000  //us



//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

int enaPin = 10;
int dirPin = 9;
int pulPin = 8;



//variables for pulse
int pulseDelayTimeIncrement = 0;
int stepsLeft = 0;
bool pulseDir = true;
bool isDone = true;

//variables for direction
directions setDirection = UP;
directions direction = UP; 

//varibles for enable
int timeSinceEnable = 0;


//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

void stepperUpdateStep();
void updatePulseDir();

void updateDirection();

//=====[Implementations of public functions]===================================

void initStepperControl()
{
    pinMode(pulPin,OUTPUT);
    pinMode(dirPin,OUTPUT);
    pinMode(enaPin,OUTPUT);

    //set inital values of system
    digitalWrite(pulPin,HIGH);
    digitalWrite(enaPin,LOW);
    updateDirection();

    delay(STARTUP_TIME); //fix this later
}




void updateStepperControl(){
    //update counters
    pulseDelayTimeIncrement = pulseDelayTimeIncrement + SYSTEM_TIME_INCREMENT_US;

    //to avoid random high ints after waiting for enable wait time plus some is stops incrementing
    if (timeSinceEnable <= ENABLE_WT_TIME*2){
      timeSinceEnable = timeSinceEnable + SYSTEM_TIME_INCREMENT_US;
    }

    stepperUpdateStep();
    updatePulseDir();

    if (stepsLeft <= 0 and timeSinceEnable > ENABLE_WT_TIME){
      isDone = true;
    }
}

//take a float and rotates that stepper in that di 
void stepperRotationsWrite(float rotations) {
  //times two because we measure on the rising and falling edge
  if (isDone){
    isDone = false;
    stepsLeft += abs(rotations) * PULSE_PER_REV*2;

    if (rotations > 0) { // if the value rotations is positive
      setDirection = UP;
      Serial.println("UP");
    } else if (rotations < 0) { // if the value rotations is negative
      setDirection = DOWN;
      Serial.println("DOWN");
    }
  } else {
    Serial.println("Error: Sent instruction while Stepper is running");
  }
  
  
}


//engage stepper driver 
void stepperEngage(){
  isDone = false;
  timeSinceEnable = 0;
  
  digitalWrite(enaPin,LOW);
}

//disengage stepper driver
void stepperDisengage(){
  isDone = false;
  digitalWrite(enaPin,HIGH);
  //disengage code goes here
}

//outputs if stepper driver is done with commands
bool isStepperReady(){
  return isDone;
}


//=====[Implementations of private functions]==================================



// this function runs a Pulse step every period
void stepperUpdateStep() {

    //IF NEGATIVE THEN GO BACKWARDS 

    // will only run if time inc is correct and there are steps left
    if (pulseDelayTimeIncrement >= PERIOD/2 && stepsLeft >= 0 && timeSinceEnable > ENABLE_WT_TIME) {

      //to switch direction skip one pulse to change directions.
      if (direction != setDirection){
        direction = setDirection;
        Serial.println("NEW DIRECTION!");
        updateDirection();

      // if direction is the same flip pulse of system, to make PWM
      } else {
        pulseDir = !pulseDir; //flips pulse
        stepsLeft = stepsLeft - 1; //remove a step from the system
      }
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

//update direction based off of instructions
void updateDirection(){
  if (direction == UP) {
    Serial.println("UP");
    digitalWrite(dirPin,LOW);
  } else {
    Serial.println("DOWN");
    digitalWrite(dirPin,HIGH);
  }
}