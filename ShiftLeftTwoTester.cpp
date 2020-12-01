#include "ShiftLeftTwo.h"
#include <string>
#include <iostream>

#define RED "\033[31m"    /* Red */
#define GREEN "\033[32m"  /* Green */
#define YELLOW "\033[33m" /* Yellow */
#define RESET "\033[0m"

using namespace std;

int main()
{

    // ######## Testing Constructor #############
    cout << "############ Testing ShiftLeftTwo #############" << endl
         << endl;

    // ######### Constructor ################
    cout << "Testing Constructor..." << endl;
    ShiftLeftTwo *testShiftLeftTwo = new ShiftLeftTwo();
    cout << GREEN << "Success." << RESET << endl
         << endl;
    // ######################################

    // ######### set() ################
    cout << "Testing set()..." << endl;

    string input = "101010";
    string shiftedOutput = "00000000000000000000000010101000";

    testShiftLeftTwo->set(input);

    if (testShiftLeftTwo->get() == shiftedOutput)
    {
        cout << GREEN << "Success." << RESET << endl;
    }
    else
    {
        cout << RED << "Failed." << RESET << endl;
        cout << "Expected: " << shiftedOutput << endl;
        cout << "Got: " << testShiftLeftTwo->get() << endl;
    }
    cout << endl;
    // ######################################
}