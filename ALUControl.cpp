#include "ALUControl.h"

/**
 * Default / typical use constructor
 */
ALUControl::ALUControl()
{
    this->opCode = "";
    this->func = "";
    this->output = -1;
}

/**
 * Execute and return value of op number for ALU
 */
int ALUControl::get()
{

    // return ALU op num based on op code and function code
    // add = 0, subtract = 1

    // ADD
    if (this->opCode == "000000" && this->func == "100000")
    {
        this->output = 0;
    }

    // SUB
    if (this->opCode == "000000" && this->func == "100010")
    {
        this->output = 1;
    }

    // LW & SW
    if (this->opCode == "100011" || this->opCode == "101011")
    {
        this->output = 0;
    }

    // BEQ
    if (this->opCode == "000100")
    {
        this->output = 1;
    }

    // ADDI
    if (this->opCode == "001000")
    {
        this->output = 0;
    }

    // J - there should be no ALU operation on a jump
    if (this->opCode == "000010")
    {
        this->output = -1;
    }

    // SLT
    if(this->opCode == "000000" && this->func == "101010") {
        this->output = 2;
    }

    return this->output;
}

/**
 * Set opCode and function code
 */
void ALUControl::set(string opCode, string func)
{
    this->opCode = opCode;
    this->func = func;
}

void ALUControl::toString() {
    cout << "Contents of ALU Control:" << endl;
    cout << "------------------------" << endl;
    cout << "Op code => 0x" << hex << stol(this->opCode, nullptr, 2) << endl;
    cout << "Func code=> 0x" << hex << stol(this->func, nullptr, 2) << endl;
    cout << "Output=> 0x" << hex << this->output << endl;
    cout << "-----------------------" << endl;
    cout << endl;
}

/**
 * Operation code getter
 */
string ALUControl::getOpCode() {
    return this->opCode;
}

string ALUControl::getFunctionCode() {
    return this->func;
}