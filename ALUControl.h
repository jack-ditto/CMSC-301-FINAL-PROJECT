#include<string>

using namespace std;

class ALUControl {


    public:

        // Default contructor
        ALUControl();

        bool get();
        void set(string aluOp, string inst);

    private:

        string inst;
        string aluOp;
        bool output;

};