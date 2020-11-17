#include <string>
#include <iostream>
#include "ALU.h"
#include <bitset>

#define RED "\033[31m"    /* Red */
#define GREEN "\033[32m"  /* Green */
#define YELLOW "\033[33m" /* Yellow */
#define RESET "\033[0m"

using namespace std;

int main()
{

    // ######## Testing Constructor #############
    cout << "############ Testing ALU #############" << endl
         << endl;

    // ######### Constructor ################
    cout << "Testing Constructor..." << endl;
    ALU *testAlu = new ALU();
    cout << GREEN << "Success." << RESET << endl
         << endl;
    // ######################################

    // ######### setValues() ################
    cout << "Testing setValues()..." << endl;

    // Test values
    int addOpNum = 0;
    int subOpNum = 1;
    string input1 = bitset<32>(17).to_string();
    string input2 = bitset<32>(23).to_string();
    string subRes = bitset<32>(17 - 23).to_string();
    string addRes = bitset<32>(17 + 23).to_string();

    testAlu->setValues(addOpNum, input1, input2);
    cout << GREEN << "Success." << RESET << endl
         << endl;
    // ######################################

    // ######### getOpNum() #################
    cout << "Testing getOpNum()..." << endl;
    if (testAlu->getOpNum() == addOpNum)
    {
        cout << GREEN << "Success." << RESET << endl
             << endl;
    }
    else
    {
        cout << RED << "Failed." << RESET << endl;
        cout << "Expected: " << addOpNum << endl;
        cout << "Got: " << testAlu->getOpNum() << endl
             << endl;
    }
    // #######################################

    // ######### getInput1() #################
    cout << "Testing getInput1()..." << endl;
    if (testAlu->getInput1() == input1)
    {
        cout << GREEN << "Success." << RESET << endl
             << endl;
    }
    else
    {
        cout << RED << "Failed." << RESET << endl;
        cout << "Expected: " << input1 << endl;
        cout << "Got: " << testAlu->getInput1() << endl
             << endl;
    }
    // #######################################

    // ######### getInput2() #################
    cout << "Testing getInput2()..." << endl;
    if (testAlu->getInput2() == input2)
    {
        cout << GREEN << "Success." << RESET << endl
             << endl;
    }
    else
    {
        cout << RED << "Failed." << RESET << endl;
        cout << "Expected: " << input2 << endl;
        cout << "Got: " << testAlu->getInput2() << endl
             << endl;
    }
    // #######################################

    // ######### getResult() #################
    cout << "Testing getResult()..." << endl;
    testAlu->setValues(addOpNum, input1, input2);
    string resp1 = testAlu->getResult();
    testAlu->setValues(subOpNum, input1, input2);
    string resp2 = testAlu->getResult();

    if (resp1 == addRes && resp2 == subRes)
    {
        cout << GREEN << "Success." << RESET << endl
             << endl;
    }
    else
    {
        cout << RED << "Failed." << RESET << endl;
        cout << "Expected: " << addRes << endl;
        cout << "Got: " << resp1 << endl;
        cout << "Expected: " << subRes << endl;
        cout << "Got: " << resp2 << endl
             << endl;
    }
    // ########################################

    // ######### getZeroFlag()... #############
    cout << "Testing getZeroFlag()..." << endl;

    input1 = bitset<32>(24).to_string();
    input2 = bitset<32>(24).to_string();
    subRes = bitset<32>(0).to_string();

    testAlu->setValues(subOpNum, input1, input2);
    string zeroFlagSubRes = testAlu->getResult();

    if(testAlu->getResult() == subRes && testAlu->getZeroFlag()) {
        cout << GREEN << "Success." << RESET << endl
             << endl;
    } else {
        cout << RED << "Failed." << RESET << endl;
        cout << "Expected (subtraction): " << subRes << endl;
        cout << "Got: " << testAlu->getResult() << endl;
        cout << "Expected (zero flag): " << 1 << endl;
        cout << "Got: " << testAlu->getZeroFlag() << endl
             << endl;
    }

    // ########################################

    return 0;
}