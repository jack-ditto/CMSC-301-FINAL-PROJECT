#ifndef __CONFIGPARSER_H__
#define __CONFIGPARSER_H__

#include <iostream>
#include <fstream>
#include <map>
#include <vector>

using namespace std;

class ConfigParser{
  public:
    // Specify a text file config.
    ConfigParser(string filename);

  private:
    map<string, string> configParameters;

    map<int, vector<string>> instructionMap; // vector for assembly and machine
    map<int, string> memoryMap;
    map<int, string> registerMap;

    void setInstructions();
    void setMemory();
    void setRegisters();
};

#endif