/*
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <Arduino.h>
#include "button.h"
#include "stepper.h"
#include "direction_commands.h"
#include "engaged_light.h"

// #include <fstream> //for read_file
// #include <iostream> //for read_file
// #include <sstream> //for read_file


//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration and initialization of private global variables]============

//maximum number of rows for the 2D array
const int MAX_ROWS = 100; //change to # of rows desired from CSV file

//maximum number of columns for the 2D array
const int MAX_COLS = 2; 

directions curDirection;
 

//=====[Declarations (prototypes) of private functions]========================

void commandsOnEngage();
void commandsOnDisengage();

//=====[Implementations of public functions]===================================
/*
void read_file(){ //this reads the CSV file and stores the data in a 2D array
    //file pointer
    fstream fin;

    //open an existing file
    fin.open("Direction_Command_Files/engage.csv", std::ios::in); //insert file name here. used for only reading file, not writing in it

    //define a 2D array to store the CSV data
    string data[MAX_ROWS][MAX_COLS];
    string line;
    int row = 0;

    //Store the CSV data from the CSV file to the 2D array
    while (getline(file, line) && row < MAX_ROWS) {
        stringstream ss(line);
        string cell;
        int col = 0;
        while (getline(ss, cell, ',') && col < MAX_COLS) {
            data[row][col] = cell;
            col++;
        }
        row++;
    }
    //close the file after read operation is complete
    fin.close();
}
*/

void initDirectionCommands(){
}

void updateDirectionCommands() {
    curDirection = getDirection();

    if ( buttonFalling() && isStepperReady() && (curDirection == DOWN)) {
        commandsOnEngage();
    }

    if ( buttonRising() && isStepperReady() && (curDirection == UP)) {
        commandsOnDisengage();
    }
}


//=====[Implementations of private functions]==================================





//these are the commands that run on the event trigger engage 
void commandsOnEngage() {    
    Serial.println();
    Serial.println("Engaged");
    stepperRotationsWrite(3); 
}

//these are the commands that run on the event trigger disengadge 
void commandsOnDisengage() {
    Serial.println();
    Serial.println("Disengaged");
    stepperRotationsWrite(-3); 
}