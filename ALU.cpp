#include "ALU.h"

/**
 * Default / common use construtor
 * 
 * Allows for construction of object, sets all values to defaults.
 * Setter methods should be used to assign all the data. 
 */
ALU::ALU()
{
    this->operationNum = -1;
    this->result = "";
    this->input1 = "";
    this->input2 = "";
    this->zeroFlag = false;
}

/**
 * Sets the operation to be performed by the ALU. 
 * 
 * ADD = 0
 * SUBTRACT = 1
 * TODO: add AND and OR operations if nescessary
 * 
 * @param opNum the number corresponding to the desired operation. 
 */
void ALU::setOperation(int opNum)
{
    if (opNum > 2 || opNum < 0)
    {
        cerr << "Invalid operation number." << endl;
    }
    else
    {
        this->operationNum = opNum;
    }
}

/**
 * Executes and gets the result of the ALU
 */
string ALU::getResult()
{
    // if (this->operationNum == -1)
    // {
    //     cerr << "No operation specified" << endl;
    //     return "";
    // }

    if (this->operationNum == 0)
    {
        this->addInputs();
    }

    if (this->operationNum == 1)
    {
        this->subtractInputs();
    } 

    if(this->operationNum == 2) {
        this->subtractInputsSlt();
    }

    return this->result;
}

/**
 * Sets the value of input 1
 * 
 * @param input1 32 bit binary string. 
 */
void ALU::setInput1(string input1)
{
    // TODO: error handing
    this->input1 = input1;
}

/**
 * Sets the value of input 2
 * 
 * @param input2 32 bit binary string. 
 */
void ALU::setInput2(string input2)
{
    // TODO: error handing
    this->input2 = input2;
}

/**
 * Adds the results of input1 and input 2 and stores the resulting 32 bit binary string in result. 
 */
void ALU::addInputs()
{
    // Convert from strings to longs
    long input1Long = stol(this->input1, nullptr, 2);
    long input2Long = stol(this->input2, nullptr, 2);

    // Add longs and convert to 32 bit binary string
    string res = bitset<32>(input1Long + input2Long).to_string();
    this->result = res;
}

/**
 * Subtracts the results of input1 and input 2 (input1 - input2) and 
 * stores the resulting 32 bit binary string in result. 
 */
void ALU::subtractInputs()
{
    // Convert from strings to longs
    long input1Long = stol(this->input1, nullptr, 2);
    long input2Long = stol(this->input2, nullptr, 2);

    // Subtract and check for zero flag
    long sub = input1Long - input2Long;
    if(sub == 0) {
        this->zeroFlag = true;
    }

    // Subtract longs and convert to 32 bit binary string
    string res = bitset<32>(sub).to_string();
    this->result = res;
}

/**
 * Subtract for SLT. 
 */
void ALU::subtractInputsSlt() {
    this->subtractInputs();
    this->result = "0000000000000000000000000000000" + this->result.substr(0, 1);
}

/**
 * Sets all the values nescessary for the ALU to function.
 * 
 * @param opNum integer specifying the desired operation
 * @param input1 32 bit binary string 
 * @param input2 32 bit binary string
 */
void ALU::setValues(int opNum, string input1, string input2)
{
    this->setInput1(input1);
    this->setInput2(input2);
    this->setOperation(opNum);
}

/**
 * Returns the boolean zero flag nescessary for jump instructions. 
 */
bool ALU::getZeroFlag()
{
    return this->zeroFlag;
}

/**
 * Getter for operation number
 */
int ALU::getOpNum() {
    return this->operationNum;
}

/**
 * Getter for input 1
 */
string ALU::getInput1() {
    return this->input1;
}

/**
 * Getter for input 2
 */
string ALU::getInput2() {
    return this->input2;
}

void ALU::toString() {
    cout << "----- ALU -----" << endl;
    cout << "Input 1: " << this->input1 << endl;
    cout << "Input 2: " << this->input2 << endl;
    cout << "Operation Number: " << this->operationNum << endl;
    cout << "Zero flag: " << this->zeroFlag << endl;
    cout << "---------------" << endl;
}