#include <string>

using namespace std;

class Control
{

public:
    Control();                               // default / typical use constructor
    void setInstruction(string instruction); // set the instruction
    int getRegDst();                        // get destination register
    int getJump();                          // get if jump instruction
    int getBranch();                        // get if branch instruction
    int getMemWrite();                      // get if memory write
    int getMemRead();                       // get if memory read
    int getMemToReg();                      // get if mem to register
    string getAluOp();                       // get the op code of the instruction for ALU control
    int getAluSrc();                        // get source for ALU
    int getRegWrite();                      // get if register write

    void toString();

private:
    // set values helper method
    void setValues(int regDst, int aluSrc, int memToReg, int regWrite, int memRead,
                   int memWrite, int branch, string aluOp, int jump);
    int regDst;
    int jump;
    int branch;
    int memRead;
    int memToReg;
    string aluOp;
    int memWrite;
    int aluSrc;
    int regWrite;
};