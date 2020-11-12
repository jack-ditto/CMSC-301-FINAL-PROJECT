#include "ShiftLeftTwo.h"

// Constructor
ShiftLeftTwo::ShiftLeftTwo()
{
}

string ShiftLeftTwo::get(string input)
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