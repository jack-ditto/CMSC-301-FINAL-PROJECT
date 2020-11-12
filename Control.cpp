#include "Control.h"

// Default constructor
Control::Control() {}

void Control::setInstruction(string instruction) {
    // Set the various instance variables here
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

bool Control::getAluOp() {
    return this->aluOp;
}

bool Control::getAluSrc() {
    return this->aluSrc;
}

bool Control::getRegWrite() {
    return this->regWrite;
}