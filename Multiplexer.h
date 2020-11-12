#include<string>
#include<iostream>

using namespace std;

class Multiplexer
{

public:
    // Constructor
    Multiplexer();

    // Get the decision
    string get();
    void setControl(int control);
    void setChoices(string choice1, string choice2);

private:
    string output;  // Store the output
    string choice1; // Store choice 1
    string choice2; // Store choice 2
    int control;    // Store control

    // Decide which output based on control
    void decide();
};