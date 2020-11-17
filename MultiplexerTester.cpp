#include <string>
#include <iostream>
#include "Multiplexer.h"
#include <bitset>

#define RED "\033[31m"    /* Red */
#define GREEN "\033[32m"  /* Green */
#define YELLOW "\033[33m" /* Yellow */
#define RESET "\033[0m"

using namespace std;

int main()
{

    // ######## Testing Constructor ############
    cout << "############ Testing Multiplexer #############" << endl
         << endl;

    // ######### Constructor ###################
    cout << "Testing Constructor..." << endl;
    Multiplexer *testMux = new Multiplexer();
    cout << GREEN << "Success." << RESET << endl
         << endl;
    // #########################################

    // ############# setChoices() ##############
    cout << "Testing setChoices()..." << endl;
    string choice1 = "choice1";
    string choice2 = "choice2";
    testMux->setChoices(choice1, choice2);

    if (testMux->getChoice1() == choice1 && testMux->getChoice2() == choice2)
    {
        cout << GREEN << "Success." << RESET << endl;
    }
    else
    {
        cout << RED << "Failed." << RESET << endl;
        cout << "Expected (choice1): " << choice1 << endl;
        cout << "Got: " << testMux->getChoice1() << endl;
        cout << "Expected (choice2): " << choice2 << endl;
        cout << "Got: " << testMux->getChoice2() << endl;
    }
    cout << endl;

    // #########################################

    // ############ setControl() ###############
    cout << "Testing setControl()..." << endl;
    int testControl = 1;
    testMux->setControl(testControl);

    if(testMux->getControl() == testControl) {
        cout << GREEN << "Success." << RESET << endl;
    } else {
        cout << RED << "Failed." << RESET << endl;
        cout << "Expected: " << testControl << endl;
        cout << "Got: " << testMux->getControl() << endl;
    }
    cout << endl;
    // #########################################


    // ############## get() ####################
    cout << "Testing get()..." << endl;
    testControl = 1;
    choice1 = "c1";
    choice2 = "c2";
    testMux->setChoices(choice1, choice2);
    testMux->setControl(testControl);

    if(testMux->get() == "c2") {
        cout << GREEN << "Success." << RESET << endl;
    } else {
        cout << RED << "Failed." << RESET << endl;
        cout << "Expected: " << choice2 << endl;
        cout << "Got: " << testMux->get() << endl;
    }
    cout << endl;

    // #########################################

    return 0;
}