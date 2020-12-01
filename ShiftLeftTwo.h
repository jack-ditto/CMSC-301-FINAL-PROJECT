#include <string>
#include <bitset>
#include <iostream>

using namespace std;

class ShiftLeftTwo
{

public:
    ShiftLeftTwo();            // default constructor
    ShiftLeftTwo(int unitNum); // constructor to which ShiftLeftTwo unit
    string get();              // get the shifted left input binary string as binary string
    void set(string input);    // set the input binary string
    void toString();

private:
    string output;       // store output
    string input;        // store input
    int unitNum;         // store output bit string size
    void shiftLeftTwo(); // perform shift function
};