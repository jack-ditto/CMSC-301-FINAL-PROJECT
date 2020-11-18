#include <string>

using namespace std;

class Control
{

public:
    Control();                               // default / typical use constructor
    void setInstruction(string instruction); // set the instruction
    bool getRegDst();                        // get destination register
    bool getJump();                          // get if jump instruction
    bool getBranch();                        // get if branch instruction
    bool getMemWrite();                      // get if memory write
    bool getMemRead();                       // get if memory read
    bool getMemToReg();                      // get if mem to register
    string getAluOp();                       // get the op code of the instruction for ALU control
    bool getAluSrc();                        // get source for ALU
    bool getRegWrite();                      // get if register write

    void toString();

private:
    // set values helper method
    void setValues(bool regDst, bool aluSrc, bool memToReg, bool regWrite, bool memRead,
                   bool memWrite, bool branch, string aluOp, bool jump);
    bool regDst;
    bool jump;
    bool branch;
    bool memRead;
    bool memToReg;
    string aluOp;
    bool memWrite;
    bool aluSrc;
    bool regWrite;
};