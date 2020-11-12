#include<string>

using namespace std;

class Control {

    public:

        // Constructor
        Control();

        // Set the instruction
        void setInstruction(string instruction);

        // Getters
        bool getRegDst();
        bool getJump();
        bool getBranch();
        bool getMemWrite();
        bool getMemRead();
        bool getMemToReg();
        bool getAluOp();
        bool getAluSrc();
        bool getRegWrite();

    private:

        bool regDst;
        bool jump;
        bool branch;
        bool memWrite;
        bool memRead;
        bool memToReg;
        bool aluOp;
        bool aluSrc;
        bool regWrite;

};