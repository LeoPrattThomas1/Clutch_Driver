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
#include "direction_commands.h"
#include "engaged_light.h"
#include "stepper.h"
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
    initDirectionCommands();

    //this funtion has a delay so the stepper can have time to enable on boot.
    initStepperControl(); 

    //start system with one rotation (testing purposes)
    stepperRotationsWrite(1);
}
void updateClutchDriverSystem(){

  //main  control systems
  updateStepperControl();
  updateButton();

  //run these commands after button and stepper are updated
  updateDirectionCommands();
  updateEngagedLight();

  delayMicroseconds(SYSTEM_TIME_INCREMENT_US);
}

//=====[Implementations of private functions]==================================
