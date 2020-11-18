#include <iostream>
#include <string>
#include <bitset>

using namespace std;

class ALU
{

public:
    ALU();                                                   // constructor
    void setValues(int opNum, string input1, string input2); // set all values for ALU
    void setOperation(int opNum);                            // set op number
    string getResult();                                      // get result of operation
    void setInput1(string input1);                           // set first input
    void setInput2(string input2);                           // set second input
    bool getZeroFlag();                                      // return the zero flag
    int getOpNum();                                          // getter for opNum
    string getInput1();                                      // getter for input1
    string getInput2();                                      // getter for inpur2

private:
    string input1;            // binary string input one
    string input2;            // binary string input two
    string result;            // binary string result
    bool zeroFlag;            // zero flag set if inputs are equal for Branch if Equal (and other branches I believe)
    int operationNum;         // integer specifying what operation to perform. See .cpp file for index
    void addInputs();         // add the two binary strings
    void subtractInputs();    // subtract - input1 minus input2
    void subtractInputsSlt(); // subtract for SLT
};