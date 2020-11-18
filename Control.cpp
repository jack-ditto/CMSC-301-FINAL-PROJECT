#include "Control.h"

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

    // R-Type (add, slt)
    if (instruction == "00000")
        setValues(true, false, false, true, false, false, false, instruction, false);

    // Load word (lw)
    else if (instruction == "100011")
        setValues(0, 1, 1, 1, 1, 0, 0, instruction, 0);

    // Store word (sw)
    else if (instruction == "101011") 
        setValues(-1, 1, -1, 0, 0, 1, 0, instruction, 0);
    
    // Branch if equal to (beq)
    else if (instruction == "000100") 
        setValues(-1, 0, -1, 0, 0, 0, 1, instruction, 1);

    // Add Immediate (addi)
    else if (instruction == "001000")
        setValues(1, 0, 0, 1, 0, 0, 0, instruction, 0);
    
    // Jump (j)
    else if (instruction == "000010")
        setValues(0, 0, 0, 0, 0, 0, 0, instruction, 1);
}

/**
 * Sets all values of instance variables. 
 */
void Control::setValues(bool regDst, bool aluSrc, bool memToReg, bool regWrite, bool memRead,
                     bool memWrite, bool branch, string aluOp, bool jump)
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
bool Control::getRegDst()
{
    return this->regDst;
}

bool Control::getJump()
{
    return this->jump;
}

bool Control::getBranch()
{
    return this->branch;
}

bool Control::getMemWrite()
{
    return this->memWrite;
}

bool Control::getMemRead()
{
    return this->memRead;
}

bool Control::getMemToReg()
{
    return this->memToReg;
}

string Control::getAluOp()
{
    return this->aluOp;
}

bool Control::getAluSrc()
{
    return this->aluSrc;
}

bool Control::getRegWrite()
{
    return this->regWrite;
}