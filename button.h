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

#ifndef _BUTTON_H_
#define _BUTTON_H_

//=====[Declaration of public defines]=========================================

//=====[Declaration of public data types]======================================

typedef enum { BUTTON_UP, BUTTON_FALLING, BUTTON_DOWN, BUTTON_RISING } buttonState_t; 

//=====[Declarations (prototypes) of public functions]=========================

void initButton();
void updateButton();

bool readButton();
bool buttonFalling();
bool buttonRising();

//=====[#include guards - end]=================================================

#endif