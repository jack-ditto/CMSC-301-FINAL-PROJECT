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