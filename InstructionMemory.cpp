#include "InstructionMemory.h"
#include <iostream>
#include <vector>


//constructor creates a map of instructions and their corresponding address
//
//parameters - map<long,vector<string>>
//
InstructionMemory::InstructionMemory(map<long,vector<string>> instructionsMap){
  instrMap = instructionsMap;
}


//Empty constructor initializes InstructionMemory
//
InstructionMemory::InstructionMemory(){}


//setAddress sets the address instance variable to the current pc
//
void InstructionMemory::setAddress(long pc){
  if (instrMap.count(pc) == 0){
    endFile = true;
  }else{
      address = pc;
      instr = instrMap.at(address)[1];
  }
}


//isEnd returns bool for eof
//
bool InstructionMemory::isEnd(){return endFile;}


//getForControl returns the bits 31-26 for the control unit
//
//Return - string getForControl
//
string InstructionMemory::getForControl(){
  vector<string> temp = instrMap.at(address);
  string str = temp.at(1);
  return str.substr(0,6);
}


//getForShift returns the bits 25-0 for the shift left 2 unit
//
//Return - string getForShift
//
string InstructionMemory::getForShift(){
  vector<string> temp = instrMap.at(address);
  string str = temp.at(1);
  return str.substr(6,26);
}


//getForExtend returns the bits 15-0 for the sign extend unit
//
//Return - string getForExtend
//
string InstructionMemory::getForExtend(){
  vector<string> temp = instrMap.at(address);
  string str = temp.at(1);
  return str.substr(16,16);
}


//getForRegOne returns the bits 25-21 for read register 1
//
//Return - string getForRegOne
//
string InstructionMemory::getForRegOne(){
  vector<string> temp = instrMap.at(address);
  string str = temp.at(1);
  return str.substr(6,5);
}


//getForRegTwo returns the bits 20-16 for read register 2 and the top part
// of the multiplexor
//
//Return - strin getForRegTwo
//
string InstructionMemory::getForRegTwo(){
  vector<string> temp = instrMap.at(address);
  string str = temp.at(1);
  return str.substr(11,5);
}


//getForMuxOne returns the bits 15-11 for the bottom of the multiplexor
//
//Return - string getForMuxOne
//
string InstructionMemory::getForMuxOne(){
  vector<string> temp = instrMap.at(address);
  string str = temp.at(1);
  return str.substr(16,5);
}


//getForALUControl returns the bits 5-0 for alu control
//
//Return - string getForALUControl
//
string InstructionMemory::getForALUControl(){
  vector<string> temp = instrMap.at(address);
  string str = temp.at(1);
  return str.substr(26,6);
}


//printMap prints out the contents of InstructionMemory
//
void InstructionMemory::printMap(){
  cout << "Print InstructionMemory Map: " << endl;
  cout << "-------------------------------" << endl;
  for (map<long,vector<string>>::iterator it = instrMap.begin(); it != instrMap.end(); it++){
    vector<string> temp = it->second;
    string inst = temp.at(1);
    cout << hex << "0x" << hex << it->first << " => " << "0x" << hex << stol(inst,nullptr,2) << endl;
  }
  cout << endl;
}


//toString prints out the contents of InstructionMemory
//
void InstructionMemory::toString(){
  cout << "Contents of InstructionMemory: " << endl;
  cout << "-------------------------------" << endl;
  cout << "Address => 0x" << hex << address << endl;
  cout << "Instruction => 0x" << hex << stol(instr,nullptr,2) << endl;
  cout << "-------------------------------" << endl;
  cout << endl;
}


//printAssembly prints out the assembly instruction
//
void InstructionMemory::printAssembly(){
  cout << endl;
  cout << "Assembly Instruction => " << instrMap.at(address)[0] << endl;
  cout << endl;
  cout << "---------------------------------" << endl;
}
