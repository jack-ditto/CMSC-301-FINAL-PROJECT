#ifndef __CONFIGPARSER_H__
#define __CONFIGPARSER_H__

#include <iostream>
#include <fstream>
#include <map>
#include <vector>

using namespace std;

class ConfigParser{
  public:
    ConfigParser(string filename);  // Constructor provide config file name

    map<long, vector<string>> getInstructions();  // get instruction map
    map<long, long> getMemory();                  // get memory map
    map<int, long> getRegisters();                // get register map
    string outputMode();        // get output mode
    string getFileName();       // get output file name
    bool printMemoryContents(); // print memory contents
    bool debugMode();           // get debug mode
    bool writeToFile();         // get write to file

  private:
    map<string, string> configParameters;     // map of config parameters

    map<long, vector<string>> instructionMap; // map of instructions
    map<long, long> memoryMap;                // map of memory
    map<int, long> registerMap;               // map of registers

    void setInstructions();
    void setMemory();
    void setRegisters();
};

#endif