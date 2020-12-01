#include "ShiftLeftTwo.h"

int ShiftLeftTwo::counter = 0;

/**
 * Default constructor
 */
ShiftLeftTwo::ShiftLeftTwo()
{
    this->unitNum = 1;
    id = ShiftLeftTwo::counter;
    ShiftLeftTwo::counter++;
}

/**
 * Constructor that specifies which ShiftLeftTwo unit this is. 
 * Basically, 
 *  unitNum 0 = conversion from 26 bits to 28 bits
 *  unitNum 1 = 32 bits to 32 bits
 */
ShiftLeftTwo::ShiftLeftTwo(int unitNum)
{
    this->unitNum = unitNum;
}

/**
 * Execute and return the shift left two function
 */
string ShiftLeftTwo::get()
{
    this->shiftLeftTwo();
    return this->output;
}

/**
 * Set the binary string to be shifted left two
 */
void ShiftLeftTwo::set(string input)
{
    this->input = input;
}

/**
 * Perform shift left two operation. 
 * Default output size is 32 bits, unless set in construction. 
 */
void ShiftLeftTwo::shiftLeftTwo()
{
    long inputLong = stol(this->input, nullptr, 2);
    inputLong = inputLong << 2;

    string bitString = "";

    if(this->unitNum == 0) {
        bitString = bitset<28>(inputLong).to_string();
    } else if(this->unitNum == 1) {
        bitString = bitset<32>(inputLong).to_string();
    }
    
    this->output = bitString;
}


/**
 * print out contents of ShiftLeftTwo
 *
 */
void ShiftLeftTwo::toString()
{
    cout << "Contents of ShiftLeftTwo " << id << ":" << endl;
    cout << "--------------------------" << endl;
    cout << "Input => 0x" << hex << input << endl;
    cout << "Output => 0x" << hex << output << endl;
    cout << "--------------------------" << endl;
    cout << endl;
}