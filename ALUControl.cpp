#include "ALUControl.h"


// Default contructor
ALUControl::ALUControl() {
    // TODO: assign default values
}


bool ALUControl::get() {

    // Make decision here
    this->output = false;

    return this->output;
}

void ALUControl::set(string aluOp, string inst) {
    this->aluOp = aluOp;
    this->inst = inst;
}