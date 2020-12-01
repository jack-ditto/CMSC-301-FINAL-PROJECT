#include "Control.h"
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
    Control *testControl = new Control();
    cout << GREEN << "Success." << RESET << endl
         << endl;
    // ######################################

    // ######### setInstruction() ################
    cout << "Testing setInstruction()..." << endl;
    int regDst;
    int jump;
    int branch;
    int memRead;
    int memToReg;
    string aluOp;
    int memWrite;
    int aluSrc;
    int regWrite;
    string instr;

    // Ah jesus, this is gonna be a long test

    // Instructions:
    // - ADD 000000
    // - SUB 000000
    // - ADDI 001000
    // - SLT 000000
    // - LW 100011
    // - SW 101011
    // - BEQ 000100
    // - J 000010

    // ADD / SUB / SLT
    instr = "000000";
    testControl->setInstruction(instr);
    regDst = 1;
    jump = 0;
    branch = 0;
    regWrite = 1;
    aluSrc = 0;
    aluOp = instr;
    memWrite = 0;
    memRead = 0;
    memToReg = 0;

    cout << "\tADD/SUB/SLT => ";
    if (testControl->getRegDst() == regDst && testControl->getRegWrite() == regWrite && testControl->getAluSrc() == aluSrc && testControl->getAluOp() == instr && testControl->getMemWrite() == memWrite && testControl->getMemRead() == memRead && testControl->getMemToReg() == memToReg && testControl->getJump() == jump && testControl->getBranch() == branch)
    {
        cout << GREEN << "Success." << RESET << endl;
    }
    else
    {
        cout << RED << "Failed." << RESET << endl;
        cout << "\t\tExpected:" << endl;
        cout << "\t\t\tregDst - " << regDst << endl;
        cout << "\t\t\tjump - " << jump << endl;
        cout << "\t\t\tbranch - " << branch << endl;
        cout << "\t\t\tRegWrite - " << regWrite << endl;
        cout << "\t\t\taluSrc - " << aluSrc << endl;
        cout << "\t\t\taluOp - " << aluOp << endl;
        cout << "\t\t\tmemWrite - " << memWrite << endl;
        cout << "\t\t\tmemRead - " << memRead << endl;
        cout << "\t\t\tmemToReg - " << memToReg << endl;

        cout << "\t\tGot:" << endl;
        cout << "\t\t\tregDst - " << testControl->getRegDst() << endl;
        cout << "\t\t\tjump - " << testControl->getJump() << endl;
        cout << "\t\t\tbranch - " << testControl->getBranch() << endl;
        cout << "\t\t\tRegWrite - " << testControl->getRegWrite() << endl;
        cout << "\t\t\taluSrc - " << testControl->getAluSrc() << endl;
        cout << "\t\t\taluOp - " << testControl->getAluOp() << endl;
        cout << "\t\t\tmemWrite - " << testControl->getMemWrite() << endl;
        cout << "\t\t\tmemRead - " << testControl->getMemRead() << endl;
        cout << "\t\t\tmemToReg - " << testControl->getMemToReg() << endl;

    }

    // ADDI
    instr = "001000";
    testControl->setInstruction(instr);
    regDst = 0;
    jump = 0;
    branch = 0;
    regWrite = 1;
    aluSrc = 1;
    aluOp = instr;
    memWrite = 0;
    memRead = 0;
    memToReg = 0;

    cout << "\tADDI => ";
    if (testControl->getRegDst() == regDst && testControl->getRegWrite() == regWrite && testControl->getAluSrc() == aluSrc && testControl->getAluOp() == instr && testControl->getMemWrite() == memWrite && testControl->getMemRead() == memRead && testControl->getMemToReg() == memToReg && testControl->getJump() == jump && testControl->getBranch() == branch)
    {
        cout << GREEN << "Success." << RESET << endl;
    }
    else
    {
        cout << RED << "Failed." << RESET << endl;
        cout << "\t\tExpected:" << endl;
        cout << "\t\t\tregDst - " << regDst << endl;
        cout << "\t\t\tjump - " << jump << endl;
        cout << "\t\t\tbranch - " << branch << endl;
        cout << "\t\t\tRegWrite - " << regWrite << endl;
        cout << "\t\t\taluSrc - " << aluSrc << endl;
        cout << "\t\t\taluOp - " << aluOp << endl;
        cout << "\t\t\tmemWrite - " << memWrite << endl;
        cout << "\t\t\tmemRead - " << memRead << endl;
        cout << "\t\t\tmemToReg - " << memToReg << endl;

        cout << "\t\tGot:" << endl;
        cout << "\t\t\tregDst - " << testControl->getRegDst() << endl;
        cout << "\t\t\tjump - " << testControl->getJump() << endl;
        cout << "\t\t\tbranch - " << testControl->getBranch() << endl;
        cout << "\t\t\tRegWrite - " << testControl->getRegWrite() << endl;
        cout << "\t\t\taluSrc - " << testControl->getAluSrc() << endl;
        cout << "\t\t\taluOp - " << testControl->getAluOp() << endl;
        cout << "\t\t\tmemWrite - " << testControl->getMemWrite() << endl;
        cout << "\t\t\tmemRead - " << testControl->getMemRead() << endl;
        cout << "\t\t\tmemToReg - " << testControl->getMemToReg() << endl;
    }

    // LW
    instr = "100011";
    testControl->setInstruction(instr);
    regDst = 0;
    jump = 0;
    branch = 0;
    regWrite = 1;
    aluSrc = 1;
    aluOp = instr;
    memWrite = 0;
    memRead = 1;
    memToReg = 1;

    cout << "\tLW => ";
    if (testControl->getRegDst() == regDst && testControl->getRegWrite() == regWrite && testControl->getAluSrc() == aluSrc && testControl->getAluOp() == instr && testControl->getMemWrite() == memWrite && testControl->getMemRead() == memRead && testControl->getMemToReg() == memToReg && testControl->getJump() == jump && testControl->getBranch() == branch)
    {
        cout << GREEN << "Success." << RESET << endl;
    }
    else
    {
        cout << RED << "Failed." << RESET << endl;
        cout << "\t\tExpected:" << endl;
        cout << "\t\t\tregDst - " << regDst << endl;
        cout << "\t\t\tjump - " << jump << endl;
        cout << "\t\t\tbranch - " << branch << endl;
        cout << "\t\t\tRegWrite - " << regWrite << endl;
        cout << "\t\t\taluSrc - " << aluSrc << endl;
        cout << "\t\t\taluOp - " << aluOp << endl;
        cout << "\t\t\tmemWrite - " << memWrite << endl;
        cout << "\t\t\tmemRead - " << memRead << endl;
        cout << "\t\t\tmemToReg - " << memToReg << endl;

        cout << "\t\tGot:" << endl;
        cout << "\t\t\tregDst - " << testControl->getRegDst() << endl;
        cout << "\t\t\tjump - " << testControl->getJump() << endl;
        cout << "\t\t\tbranch - " << testControl->getBranch() << endl;
        cout << "\t\t\tRegWrite - " << testControl->getRegWrite() << endl;
        cout << "\t\t\taluSrc - " << testControl->getAluSrc() << endl;
        cout << "\t\t\taluOp - " << testControl->getAluOp() << endl;
        cout << "\t\t\tmemWrite - " << testControl->getMemWrite() << endl;
        cout << "\t\t\tmemRead - " << testControl->getMemRead() << endl;
        cout << "\t\t\tmemToReg - " << testControl->getMemToReg() << endl;
    }

    // SW
    instr = "101011";
    testControl->setInstruction(instr);
    regDst = -1;
    jump = 0;
    branch = 0;
    regWrite = 0;
    aluSrc = 1;
    aluOp = instr;
    memWrite = 1;
    memRead = 0;
    memToReg = -1;

    cout << "\tSW => ";
    if (testControl->getRegDst() == regDst && testControl->getRegWrite() == regWrite && testControl->getAluSrc() == aluSrc && testControl->getAluOp() == instr && testControl->getMemWrite() == memWrite && testControl->getMemRead() == memRead && testControl->getMemToReg() == memToReg && testControl->getJump() == jump && testControl->getBranch() == branch)
    {
        cout << GREEN << "Success." << RESET << endl;
    }
    else
    {
        cout << RED << "Failed." << RESET << endl;
        cout << "\t\tExpected:" << endl;
        cout << "\t\t\tregDst - " << regDst << endl;
        cout << "\t\t\tjump - " << jump << endl;
        cout << "\t\t\tbranch - " << branch << endl;
        cout << "\t\t\tRegWrite - " << regWrite << endl;
        cout << "\t\t\taluSrc - " << aluSrc << endl;
        cout << "\t\t\taluOp - " << aluOp << endl;
        cout << "\t\t\tmemWrite - " << memWrite << endl;
        cout << "\t\t\tmemRead - " << memRead << endl;
        cout << "\t\t\tmemToReg - " << memToReg << endl;

        cout << "\t\tGot:" << endl;
        cout << "\t\t\tregDst - " << testControl->getRegDst() << endl;
        cout << "\t\t\tjump - " << testControl->getJump() << endl;
        cout << "\t\t\tbranch - " << testControl->getBranch() << endl;
        cout << "\t\t\tRegWrite - " << testControl->getRegWrite() << endl;
        cout << "\t\t\taluSrc - " << testControl->getAluSrc() << endl;
        cout << "\t\t\taluOp - " << testControl->getAluOp() << endl;
        cout << "\t\t\tmemWrite - " << testControl->getMemWrite() << endl;
        cout << "\t\t\tmemRead - " << testControl->getMemRead() << endl;
        cout << "\t\t\tmemToReg - " << testControl->getMemToReg() << endl;
    }

    // BEQ
    instr = "000100";
    testControl->setInstruction(instr);
    regDst = -1;
    jump = 0;
    branch = 1;
    regWrite = 0;
    aluSrc = 0;
    aluOp = instr;
    memWrite = 0;
    memRead = 0;
    memToReg = -1;

    cout << "\tBEQ => ";
    if (testControl->getRegDst() == regDst && testControl->getRegWrite() == regWrite && testControl->getAluSrc() == aluSrc && testControl->getAluOp() == instr && testControl->getMemWrite() == memWrite && testControl->getMemRead() == memRead && testControl->getMemToReg() == memToReg && testControl->getJump() == jump && testControl->getBranch() == branch)
    {
        cout << GREEN << "Success." << RESET << endl;
    }
    else
    {
        cout << RED << "Failed." << RESET << endl;
        cout << "\t\tExpected:" << endl;
        cout << "\t\t\tregDst - " << regDst << endl;
        cout << "\t\t\tjump - " << jump << endl;
        cout << "\t\t\tbranch - " << branch << endl;
        cout << "\t\t\tRegWrite - " << regWrite << endl;
        cout << "\t\t\taluSrc - " << aluSrc << endl;
        cout << "\t\t\taluOp - " << aluOp << endl;
        cout << "\t\t\tmemWrite - " << memWrite << endl;
        cout << "\t\t\tmemRead - " << memRead << endl;
        cout << "\t\t\tmemToReg - " << memToReg << endl;

        cout << "\t\tGot:" << endl;
        cout << "\t\t\tregDst - " << testControl->getRegDst() << endl;
        cout << "\t\t\tjump - " << testControl->getJump() << endl;
        cout << "\t\t\tbranch - " << testControl->getBranch() << endl;
        cout << "\t\t\tRegWrite - " << testControl->getRegWrite() << endl;
        cout << "\t\t\taluSrc - " << testControl->getAluSrc() << endl;
        cout << "\t\t\taluOp - " << testControl->getAluOp() << endl;
        cout << "\t\t\tmemWrite - " << testControl->getMemWrite() << endl;
        cout << "\t\t\tmemRead - " << testControl->getMemRead() << endl;
        cout << "\t\t\tmemToReg - " << testControl->getMemToReg() << endl;
    }

    // J
    instr = "000010";
    testControl->setInstruction(instr);
    regDst = -1;
    jump = 1;
    branch = 0;
    regWrite = 0;
    aluSrc = -1;
    aluOp = instr;
    memWrite = 0;
    memRead = 0;
    memToReg = -1;

    cout << "\tJ => ";
    if (testControl->getRegDst() == regDst && testControl->getRegWrite() == regWrite && testControl->getAluSrc() == aluSrc && testControl->getAluOp() == instr && testControl->getMemWrite() == memWrite && testControl->getMemRead() == memRead && testControl->getMemToReg() == memToReg && testControl->getJump() == jump && testControl->getBranch() == branch)
    {
        cout << GREEN << "Success." << RESET << endl;
    }
    else
    {
        cout << RED << "Failed." << RESET << endl;
        cout << "\t\tExpected:" << endl;
        cout << "\t\t\tregDst - " << regDst << endl;
        cout << "\t\t\tjump - " << jump << endl;
        cout << "\t\t\tbranch - " << branch << endl;
        cout << "\t\t\tRegWrite - " << regWrite << endl;
        cout << "\t\t\taluSrc - " << aluSrc << endl;
        cout << "\t\t\taluOp - " << aluOp << endl;
        cout << "\t\t\tmemWrite - " << memWrite << endl;
        cout << "\t\t\tmemRead - " << memRead << endl;
        cout << "\t\t\tmemToReg - " << memToReg << endl;

        cout << "\t\tGot:" << endl;
        cout << "\t\t\tregDst - " << testControl->getRegDst() << endl;
        cout << "\t\t\tjump - " << testControl->getJump() << endl;
        cout << "\t\t\tbranch - " << testControl->getBranch() << endl;
        cout << "\t\t\tRegWrite - " << testControl->getRegWrite() << endl;
        cout << "\t\t\taluSrc - " << testControl->getAluSrc() << endl;
        cout << "\t\t\taluOp - " << testControl->getAluOp() << endl;
        cout << "\t\t\tmemWrite - " << testControl->getMemWrite() << endl;
        cout << "\t\t\tmemRead - " << testControl->getMemRead() << endl;
        cout << "\t\t\tmemToReg - " << testControl->getMemToReg() << endl;
    }
    cout << endl;
    // ######################################

    return 0;
}