#include<string>

using namespace std;

class ALUControl {
    
    
    public:

        // Default contructor
        ALUControl();

        // Typical use contructor
        ALUControl(string aluOp, string inst);

        bool get();

    private:

        string inst;
        string aluOp;
        bool output;

};