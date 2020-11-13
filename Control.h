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
        string getAluOp();
        bool getAluSrc();
        bool getRegWrite();

    private:
        void setAll(bool regDst, bool aluSrc, bool memToReg, bool regWrite, bool memRead,
            bool memWrite, bool branch, string aluOp);
        bool regDst;
        bool jump;
        bool branch;
        bool memWrite;
        bool memRead;
        bool memToReg;
        string aluOp;
        bool aluSrc;
        bool regWrite;

};