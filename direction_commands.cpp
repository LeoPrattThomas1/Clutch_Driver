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

<<<<<<< Updated upstream
=======
//maximum number of rows for the 2D array
const int MAX_ROWS = 100; //change to # of rows desired from CSV file

//maximum number of columns for the 2D array
const int MAX_COLS = 2; 


>>>>>>> Stashed changes
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


void read_file(){ //this reads the CSV file and stores the data in a 2D array
    //file pointer
    fstream fin;

    //open an existing file
    ifstream file("data.csv");

    //define a 2D array to store the CSV data
    string data[MAX_ROWS][MAX_COLS];
    string line;
    int row = 0;

    //Store the CSV data from the CSV file to the 2D array
    while (getline(fin, line) && row < MAX_ROWS) {
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