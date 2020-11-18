#include <string>
#include <iostream>

using namespace std;

class Multiplexer
{

public:
    Multiplexer();                                   // default / typical use constructor
    string get();                                    // gets the decision from the multiplexer
    void setControl(int control);                    // set the value of the control line
    void setChoices(string choice1, string choice2); // set both choices for mux
    string getChoice1();
    string getChoice2();
    int getControl();
    void toString();

private:
    string output;  // store the output
    string choice1; // store choice 1
    string choice2; // store choice 2
    int control;    // store control
    void decide();  // Decide which output based on control
};