#include "ALUControl.h"
#include <string>
#include <iostream>

#define RED "\033[31m"    /* Red */
#define GREEN "\033[32m"  /* Green */
#define YELLOW "\033[33m" /* Yellow */
#define RESET "\033[0m"

using namespace std;

int main()
{

    // ######## Testing Constructor #############
    cout << "############ Testing ALU Control #############" << endl
         << endl;

    // ######### Constructor ################
    cout << "Testing Constructor..." << endl;
    ALUControl *testAluControl = new ALUControl();
    cout << GREEN << "Success." << RESET << endl
         << endl;
    // ######################################

    // ######### set() ################
    cout << "Testing set()..." << endl;

    string opCode = "1234";
    string functionCode = "54321";

    testAluControl->set(opCode, functionCode);

    if (testAluControl->getOpCode() == opCode && testAluControl->getFunctionCode() == functionCode)
    {
        cout << GREEN << "Success." << RESET << endl;
    }
    else
    {
        cout << RED << "Failed." << RESET << endl;
        cout << "Expected (opcode): " << opCode << endl;
        cout << "Got: " << testAluControl->getOpCode() << endl;
        cout << "Expected (func): " << functionCode << endl;
        cout << "Got: " << testAluControl->getFunctionCode() << endl;
    }
    cout << endl;
    // ######################################

    // ######### get() ################
    cout << "Testing get()..." << endl;

    // Needed instructions:
    // - ADD
    // - SUB
    // - ADDI
    // - SLT
    // - LW
    // - SW
    // - BEQ
    // - J


    // ADD
    opCode = "000000";
    functionCode = "100000";
    int expectedOpNum = 0;
    testAluControl->set(opCode, functionCode);

    cout << "ADD => ";
    if (testAluControl->get() == expectedOpNum)
    {
        cout << GREEN << "Success." << RESET << endl;
    }
    else
    {
        cout << RED << "Failed." << RESET << endl;
        cout << "\tExpected: " << expectedOpNum << endl;
        cout << "\tGot: " << testAluControl->get() << endl;
    }

    // ADDI
    opCode = "000000";
    functionCode = "100010";
    expectedOpNum = 1;
    testAluControl->set(opCode, functionCode);

    cout << "SUB => ";
    if (testAluControl->get() == expectedOpNum)
    {
        cout << GREEN << "Success." << RESET << endl;
    }
    else
    {
        cout << RED << "Failed." << RESET << endl;
        cout << "\tExpected: " << expectedOpNum << endl;
        cout << "\tGot: " << testAluControl->get() << endl;
    }

    // ADDI
    opCode = "001000";
    functionCode = "";
    expectedOpNum = 0;
    testAluControl->set(opCode, functionCode);

    cout << "ADDI => ";
    if (testAluControl->get() == expectedOpNum)
    {
        cout << GREEN << "Success." << RESET << endl;
    }
    else
    {
        cout << RED << "Failed." << RESET << endl;
        cout << "\tExpected: " << expectedOpNum << endl;
        cout << "\tGot: " << testAluControl->get() << endl;
    }

    // SLT
    opCode = "000000";
    functionCode = "101010";
    expectedOpNum = 2;
    testAluControl->set(opCode, functionCode);

    cout << "SLT => ";
    if (testAluControl->get() == expectedOpNum)
    {
        cout << GREEN << "Success." << RESET << endl;
    }
    else
    {
        cout << RED << "Failed." << RESET << endl;
        cout << "\tExpected: " << expectedOpNum << endl;
        cout << "\tGot: " << testAluControl->get() << endl;
    }

    // LW
    opCode = "100011";
    functionCode = "";
    expectedOpNum = 0;
    testAluControl->set(opCode, functionCode);

    cout << "LW => ";
    if (testAluControl->get() == expectedOpNum)
    {
        cout << GREEN << "Success." << RESET << endl;
    }
    else
    {
        cout << RED << "Failed." << RESET << endl;
        cout << "\tExpected: " << expectedOpNum << endl;
        cout << "\tGot: " << testAluControl->get() << endl;
    }

    // SW
    opCode = "101011";
    functionCode = "";
    expectedOpNum = 0;
    testAluControl->set(opCode, functionCode);

    cout << "SW => ";
    if (testAluControl->get() == expectedOpNum)
    {
        cout << GREEN << "Success." << RESET << endl;
    }
    else
    {
        cout << RED << "Failed." << RESET << endl;
        cout << "\tExpected: " << expectedOpNum << endl;
        cout << "\tGot: " << testAluControl->get() << endl;
    }

    // J
    opCode = "000010";
    functionCode = "";
    expectedOpNum = -1;
    testAluControl->set(opCode, functionCode);

    cout << "J => ";
    if (testAluControl->get() == expectedOpNum)
    {
        cout << GREEN << "Success." << RESET << endl;
    }
    else
    {
        cout << RED << "Failed." << RESET << endl;
        cout << "\tExpected: " << expectedOpNum << endl;
        cout << "\tGot: " << testAluControl->get() << endl;
    }

    // BEQ
    opCode = "000100";
    functionCode = "";
    expectedOpNum = 1;
    testAluControl->set(opCode, functionCode);

    cout << "BEQ => ";
    if (testAluControl->get() == expectedOpNum)
    {
        cout << GREEN << "Success." << RESET << endl;
    }
    else
    {
        cout << RED << "Failed." << RESET << endl;
        cout << "\tExpected: " << expectedOpNum << endl;
        cout << "\tGot: " << testAluControl->get() << endl;
    }

    cout << endl;
    // ######################################

    return 0;
}