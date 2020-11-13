#include "ShiftLeftTwo.h"

// Constructor
ShiftLeftTwo::ShiftLeftTwo()
{
}

string ShiftLeftTwo::get()
{
    this->shiftLeftTwo();
    return this->output;
}

void ShiftLeftTwo::set(string input) {
    this->input = input;
}

void ShiftLeftTwo::shiftLeftTwo() {
    // Perform shift on this->input, set to this->output
}