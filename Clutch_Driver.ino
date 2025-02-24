/*
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

/*
TODO (on hold due to board malfunction)

Serial.end();: 
  program if the step is backwards reverse direction of the motor

Direction Commands:
  implement servo code to direction commands
  make it programible with file (mabey?)

Engaged Light: 
  make lights 3 state system
    - ON
    - OFF
    - ERROR


implement error Module *or have it in engaged light*
  get error codes from RPM, and error codes from stepper,
*/


//=====[Libraries]=============================================================

#include "clutch_driver_system.h"


//=====[Implementations of public functions]===================================

void setup() {
  initClutchDriverSystem();
}

void loop() {
  updateClutchDriverSystem();
}