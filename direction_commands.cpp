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

#include <Arduino.h>
#include "button.h"
#include "direction_commands.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============


//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

void commandsOnEngage();
void commandsOnDisengage();

//=====[Implementations of public functions]===================================

void initDirectionCommands() {
    Serial.begin(9600);
}


void updateDirectionCommands() {
    if ( buttonFalling() ) {
        commandsOnEngage();
    }

    if ( buttonRising() ) {
        commandsOnDisengage();
    }
}


//=====[Implementations of private functions]==================================


void commandsOnEngage() {
    Serial.println("engaged");`
    turnOnEngagedLight();
}

void commandsOnDisengage() {
    Serial.println("disengaged");
}