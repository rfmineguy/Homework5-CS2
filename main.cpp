#include "DateTime.hpp"
#include "Calendar.hpp"
#include <iomanip>
#include <iostream>

#include <chrono> //testing if = assignment operator works with a pause
#include <thread>
using namespace std;

/*******************************************************************************
 *  Function prototypes
*******************************************************************************/
void printMenu();
unsigned getUserChoice(const unsigned);
void branch(unsigned, Calendar*);

/*******************************************************************************
 *  Description:
 *      Starting point of the program.
 *
 *  Input(s):
 *      N/A
 *
 *  Output:
 *      An integer that signals the exit code to the operating system (OS)
*******************************************************************************/
int main() {
    // variables
    DateTime test = DateTime(); //testing if underlined constructor is working
    cout << test.getTime() << endl;
    //std::cout << "Waiting 1 seconds" << std::endl;
    //std::chrono::seconds dura( 1);
    //std::this_thread::sleep_for( dura );
    DateTime test2 = DateTime(); //testing if comparison operator is working
    test = test2;
    cout << test.getTime() << endl; 
    // cout << test.getDate().substr(4,3) << endl;
    // cout << test.getTime() << endl;

    unsigned userChoice = 0;
    const unsigned EXIT_CHOICE = 5;
    Calendar cal;

    // greeting
    cout << "Welcome to my calendar program!\n\n";

    // menu loop
    do {
        printMenu();
        userChoice = getUserChoice(EXIT_CHOICE);
        branch(userChoice, &cal);
    } while (userChoice != EXIT_CHOICE);

    // farewell
    cout << "Thanks for using my program, hope you enjoyed :)\n";

    // terminate
    return 0;
}

/*******************************************************************************
 *  Description:
 *      Prints the menu options available in this program to the screen.
 *
 *  Input(s):
 *      N/A
 *
 *  Output:
 *      N/A
*******************************************************************************/
void printMenu() {
    const int WIDTH = 50;
    const char FILL = '+';

    cout << setfill(FILL) << setw(WIDTH) << "" << endl;
    cout << "\t1. Add an event\n";
    cout << "\t2. Remove an event\n";
    cout << "\t3. Display calendar\n";
    cout << "\t4. Display current date and time\n";
    cout << "\t5. Exit program\n";
    cout << setfill(FILL) << setw(WIDTH) << "" << endl;
}

/*******************************************************************************
 *  Description:
 *      Gets a valid user choice for the menu.
 *
 *  Input(s):
 *      EXIT_CHOICE - a constant unsigned integer that represents the last menu
 *                    option (exiting the program)
 *
 *  Output:
 *      The user's choice from the menu
*******************************************************************************/
unsigned getUserChoice(const unsigned EXIT_CHOICE) {
    unsigned uc = 0;

    do {
        cout << "Enter the menu option you wish to execute: ";
        cin >> uc;
    } while (!(uc >= 1 && uc <= EXIT_CHOICE));
    cout << endl;

    return uc;
}

/*******************************************************************************
 *  Description:
 *      Handles branching to the different menu options and handling each case.
 *
 *  Input(s):
 *      userChoice - an unsigned integer that holds the user's choice
 *      calPtr     - a pointer to a `Calendar` object
 *
 *  Output:
 *      N/A
*******************************************************************************/
void branch(unsigned userChoice, Calendar* calPtr) {
    switch (userChoice) {
        // add event
        case 1: {
            calPtr->addEvent();
            break;
        }

        // remove event
        case 2: {
            calPtr->removeEvent();
            break;
        }

        // display calendar
        case 3: {
            cout << *calPtr;
            break;
        }

        // display current date and time
        case 4: {
            cout << "Current date: " << DateTime::currentDate() << endl;
            cout << "Current time: " << DateTime::currentTime() << endl;
            break;
        }

        // exit
        case 5: break;

        // invalid
        default: {
            cout << "Error! Invalid case reached.\n";
        }
    }
    cout << endl;
}
