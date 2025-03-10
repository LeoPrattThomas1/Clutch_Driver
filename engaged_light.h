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

#ifndef _ENGAGED_LIGHT_H_
#define _ENGAGED_LIGHT_H_

//=====[Declaration of public defines]=========================================

//=====[Declaration of public data types]======================================

typedef enum { ON, OFF, ERROR } lightStates; 

//=====[Declarations (prototypes) of public functions]=========================

void initEngagedLight();
void updateEngagedLight();
void turnOnEngagedLight();
void turnOffEngagedLight();
void raiseLightError();


//=====[#include guards - end]=================================================

#endif