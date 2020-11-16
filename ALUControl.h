#include <string>

using namespace std;

class ALUControl
{

public:
    ALUControl();                         // default / typical use constructor
    int get();                            // gets the operation number corresponding to the correct ALU op for an instruction
    void set(string opCode, string func); // sets the op code and function code

private:
    string opCode; // operation code
    string func;   // function code
    int output;    // result
};