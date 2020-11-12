#include "ALUControl.h"


// Default contructor
ALUControl::ALUControl() {
    // TODO: assign default values
}

ALUControl::ALUControl(string aluOp, string inst) {
    this->aluOp = aluOp;
    this->inst = inst;
}

bool ALUControl::get() {

    // Make decision here
    this->output = false;

    return this->output;
}