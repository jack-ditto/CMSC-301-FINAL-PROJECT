#include "Control.h"
#include <iostream>

// Default constructor
Control::Control() {}


/**
 * Set control flags based on first 6 bits of instruction (left to write)
 *
 * @param instruction bits 31-26 of the instruction
 */
void Control::setInstruction(string instruction)
{
    // Set the various instance variables here

    // R-Type (add, sub, slt)
    if (instruction == "000000")
        setValues(1, 0, 0, 1, 0, 0, 0, instruction, 0);

    // Load word (lw)
    else if (instruction == "100011")
        setValues(0, 1, 1, 1, 1, 0, 0, instruction, 0);

    // Store word (sw)
    else if (instruction == "101011")
        setValues(-1, 1, -1, 0, 0, 1, 0, instruction, 0);

    // Branch if equal to (beq)
    else if (instruction == "000100")
        setValues(-1, 0, -1, 0, 0, 0, 1, instruction, 0);

    // Add Immediate (addi)
    else if (instruction == "001000")
        setValues(0, 1, 0, 1, 0, 0, 0, instruction, 0);

    // Jump (j)
    else if (instruction == "000010")
        setValues(-1, -1, -1, 0, 0, 0, 0, instruction, 1);
}

/**
 * Sets all values of instance variables.
 */
void Control::setValues(int regDst, int aluSrc, int memToReg, int regWrite, int memRead,
                     int memWrite, int branch, string aluOp, int jump)
{
    this->regDst = regDst;
    this->aluSrc = aluSrc;
    this->memToReg = memToReg;
    this->regWrite = regWrite;
    this->memRead = memRead;
    this->memWrite = memWrite;
    this->branch = branch;
    this->aluOp = aluOp;
    this->jump = jump;
}

// Getters
int Control::getRegDst()
{
    return this->regDst;
}

int Control::getJump()
{
    return this->jump;
}

int Control::getBranch()
{
    return this->branch;
}

int Control::getMemWrite()
{
    return this->memWrite;
}

int Control::getMemRead()
{
    return this->memRead;
}

int Control::getMemToReg()
{
    return this->memToReg;
}

string Control::getAluOp()
{
    return this->aluOp;
}

int Control::getAluSrc()
{
    return this->aluSrc;
}

int Control::getRegWrite()
{
    return this->regWrite;
}

void Control::toString()
{
    cout << "Contents of Control: " << endl;
    cout << "---------------------" << endl;
    cout << "regDst => 0x" << hex << this->regDst << endl;
    cout << "aluSrc => 0x" << hex << this->aluSrc << endl;
    cout << "memToReg => 0x" << hex << this->memToReg << endl;
    cout << "regWrite => 0x" << hex << this->regWrite << endl;
    cout << "memRead => 0x" << hex << this->memRead << endl;
    cout << "memWrite => 0x" << hex << this->memWrite << endl;
    cout << "branch => 0x" << hex << this->branch << endl;
    cout << "aluOp => 0x" << hex << stol(this->aluOp,nullptr,2) << endl;
    cout << "jump => 0x" << hex << this->jump << endl;
    cout << "---------------------" << endl;
    cout << endl;    
}