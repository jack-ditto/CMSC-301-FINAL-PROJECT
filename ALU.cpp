#include "ALU.h"

// Constructor
ALU::ALU()
{
    this->operationNum = -1;
    this->result = "";
    this->input1 = "";
    this->input2 = "";
}

// Set operation to be done by ALU
// 0 = ADD
// 1 = SUBTRACT
void ALU::setOperation(int opNum)
{
    if (opNum > 1 || opNum < 0)
    {
        cerr << "Invalid operation number." << endl;
    }
    else
    {
        this->operationNum = opNum;
    }
}

string ALU::getResult()
{
    if (this->operationNum == -1)
    {
        cerr << "No operation specified" << endl;
        return "";
    }

    if (this->operationNum == 0)
    {
        this->addInputs();
    }

    if (this->operationNum == 1)
    {
        this->subtractInputs();
    }

    return this->result;
}

void ALU::setInput1(string input1)
{
    // TODO: error handing
    this->input1 = input1;
}

void ALU::setInput2(string input2)
{
    // TODO: error handing
    this->input2 = input2;
}

void ALU::addInputs()
{
    // Add the inputs together here
    // Store result in this->result
}

void ALU::subtractInputs()
{
    // Subtract the inputs here
    // Store result in this->result
}
