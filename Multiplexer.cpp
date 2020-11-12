#include "Multiplexer.h"

Multiplexer::Multiplexer()
{}

void Multiplexer::setControl(int control)
{   
    // TODO: input validation
    this->control = control;
}

void Multiplexer::setChoices(string choice1, string choice2)
{
    // TODO: input validation
    this->choice1 = choice1;
    this->choice2 = choice2;
}

string Multiplexer::get()
{

    // Make decision and set output
    this->decide();

    return this->output;
}

void Multiplexer::decide()
{

    // Set output according to control
    if (control == 0)
    {
        this->output = this->choice1;
    }

    if (control == 1)
    {
        this->output = this->choice2;
    }
}