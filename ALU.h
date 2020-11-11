#include <iostream>
#include <string>

using namespace std;

class ALU
{

public:
    ALU();                         // Constructor
    void setOperation(int opNum);  // Set op number
    string getResult();            // get result of operation
    void setInput1(string input1); // set first input
    void setInput2(string input2); // set second input

private:
    string input1; // binary string input one
    string input2; // binary string input two
    string result; // binary string result
    // bool zeroFlag;
    int operationNum;
    void addInputs();
    void subtractInputs();
};