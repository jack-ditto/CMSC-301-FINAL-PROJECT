#include "Multiplexer.h"

int Multiplexer::counter = 1;

/**
 * Default / typical use constructor
 */
Multiplexer::Multiplexer()
{
    id = Multiplexer::counter;
    Multiplexer::counter++;
}

/**
 * Set the control line for the multiplexer. 0 = choice1, 1 = choice2
 * 
 * @param control int control line value
 */
void Multiplexer::setControl(int control)
{
    // TODO: input validation
    this->control = control;
}

/**
 * Sets both choices
 * 
 * @param choice1 string value (usually binary) for choice 1
 * @param choice2 string value (usually binary) for choice 2
 */
void Multiplexer::setChoices(string choice1, string choice2)
{
    // TODO: input validation
    this->choice1 = choice1;
    this->choice2 = choice2;
}

/**
 * Decide and return decision
 */
string Multiplexer::get()
{

    // Make decision and set output
    this->decide();

    return this->output;
}

/**
 * Choice choice1 or choice2 based on control line
 */
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

/**
 * Getter for choice 1
 */
string Multiplexer::getChoice1() {
    return this->choice1;
}

/**
 * Getter for choice 2
 */
string Multiplexer::getChoice2() {
    return this->choice2;
}

/**
 * Getter for control
 */
int Multiplexer::getControl() {
    return this->control;
}

void Multiplexer::toString() {
    cout << "Contents of Multiplexer " << id << ":" << endl;
    cout << "------------------------" << endl;
    cout << "Choice 1 => 0x" << hex << stol(this->choice1,nullptr,2) << endl;
    cout << "Choice 2 => 0x" << hex << stol(this->choice2,nullptr,2) << endl;
    cout << "Control => 0x" << hex << this->control << endl;
    cout << "Output => 0x" << hex << stol(this->output,nullptr,2) << endl;
    cout << "------------------------" << endl;
    cout << endl;
}