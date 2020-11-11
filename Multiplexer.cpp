#include "Multiplexer.h"

Multiplexer::Multiplexer(int control, string choice1, string choice2) {
    
    // TODO: Input validation
    this->choice1 = choice1;
    this->choice2 = choice2;
    this->control = control;
}

string Multiplexer::get() {
    
    // Make decision and set output
    this->decide();

    return this->output;
}

void Multiplexer::decide() {

    // Set output according to control
    if(control == 0) {
        this->output = this->choice1;
    } 

    if(control == 1) {
        this->output = this->choice2;
    }
}