#include "Control.h"

// Default constructor
Control::Control() {}

void Control::setInstruction(string instruction) {
    // Set the various instance variables here
    if (instruction == "00000") // R type
        setAll(1,0,0,1,0,0,0,"0");
    else if (instruction == "100011") //lw
        setAll(1,0,0,1,0,0,0,"0");
    else if(instruction == "101011") // sw
        setAll(1,0,0,1,0,0,0,"0");
    else if(instruction == "000100") // beq
        setAll(1,0,0,1,0,0,0,"0");
    else if(instruction == "001000") //ADDI
        setAll(1,0,0,1,0,0,0,"0");
    else if(instruction == "000010") // jump
        setAll(1,0,0,1,0,0,0,"0");

}

void Control::setAll(bool regDst, bool aluSrc, bool memToReg, bool regWrite, bool memRead,
bool memWrite, bool branch, string aluOp){
    this->regDst = regDst;
    this->aluSrc = aluSrc;
    this->memToReg = memToReg;
    this->regWrite = regWrite;
    this->memRead = memRead;
    this->memWrite = memWrite;
    this->branch = branch;
    this->aluOp = aluOp;
}
// Getters
bool Control::getRegDst() {
    return this->regDst;
}

bool Control::getJump() {
    return this->jump;
}

bool Control::getBranch() {
    return this->branch;
}

bool Control::getMemWrite() {
    return this->memWrite;
}

bool Control::getMemRead() {
    return this->memRead;
}

bool Control::getMemToReg() {
    return this->memToReg;
}

string Control::getAluOp() {
    return this->aluOp;
}

bool Control::getAluSrc() {
    return this->aluSrc;
}

bool Control::getRegWrite() {
    return this->regWrite;
}