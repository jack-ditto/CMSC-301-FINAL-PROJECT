#include "InstructionMemory.h"
#include <iostream>
//#include <fsteam>

//constructor creates a map of instructions and their corresponding address
//
//parameters - map<int,string>
//
InstructionMemory::InstructionMemory(map<int,string> instructionsMap){
  for (map<int,string>::iterator it = instructionsMap.begin; it != instructionsMap.end(); it++){
    InstrMap.insert(pair<int,string>(it->first,it->second));
  }
}


//getForControl returns the bits 31-26 for the control unit
//
//Parameter - int address
//
//Return - binary string
string InstructionMemory::getForControl(int address){
  string temp = InstrMap.find(address);
  return temp.substr(0,6);
}


//getForShift returns the bits 25-0 for the shift left 2 unit
//
//Parameter - int address
//
//Return - binary string
string InstructionMemory::getForShift(int address){
  string temp = InstrMap.find(address);
  return temp.substr(6,25);
}


//getForExtend returns the bits 15-0 for the sign extend unit
//
//Parameter - int address
//
//Return - binary string
string InstructionMemory::getForExtend(int address){
  string temp = InstrMap.find(address);
  return temp.substr(16,16);
}


//getForRegOne returns the bits 25-21 for read register 1
//
//Parameter - int address
//
//Return - binary string
string InstructionMemory::getForRegOne(int address){
  string temp = InstrMap.find(address);
  return temp.substr(6,5);
}


//getForRegTwo returns the bits 20-16 for read register 2 and the top part
// of the multiplexor
//
//Parameter - int address
//
//Return - binary string
string InstructionMemory::getForRegTwo(int address){
  string temp = InstrMap.find(address);
  return temp.substr(11,5);
}


//getForMuxOne returns the bits 15-11 for the bottom of the multiplexor
//
//Parameter - int address
//
//Return - binary string
string InstructionMemory::getForMuxOne(int address){
  string temp = InstrMap.find(address);
  return temp.substr(16,5);
}



//toString prints out the contents of InstructionMemory
void InstructionMemory::toString(){
  cout << "Contents of InstructionMemory: " << endl;
  for (map<int,string>::iterator it = InstrMap.begin; it != InstrMap.end(); it++){
    cout << it->first << " => " << it->second << endl;
  }
}
