/*
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

//=====[#include guards - begin]===============================================

#ifndef _STEPPER_H_
#define _STEPPER_H_

//=====[Declaration of public defines]=========================================


//=====[Declaration of public data types]======================================

typedef enum { UP, DOWN } directions; 

//=====[Declarations (prototypes) of public functions]=========================

void initStepperControl();
void updateStepperControl();


//stepper commands

void stepperEngage();//engage stepper driver 
void stepperDisengage();//disengage stepper driver
bool isStepperReady(); //ouputs if steper driver is done with commands
void stepperRotationsWrite(float rotations);

//=====[#include guards - end]=================================================

#endif