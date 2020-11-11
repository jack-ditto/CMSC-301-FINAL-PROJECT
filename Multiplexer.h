#include<string>
#include<iostream>

using namespace std;

class Multiplexer
{

public:
    // Constructor
    Multiplexer(int control, string choice1, string choice2);

    // Get the decision
    string get();

private:
    string output;  // Store the output
    string choice1; // Store choice 1
    string choice2; // Store choice 2
    int control;    // Store control

    // Decide which output based on control
    void decide();
};