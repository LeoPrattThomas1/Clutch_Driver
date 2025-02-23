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