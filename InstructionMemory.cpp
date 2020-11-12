#include "InstructionMemory.h"
#include <iostream>
#include <vector>
//#include <fsteam>

//constructor creates a map of instructions and their corresponding address
//
//parameters - map<long,vector<string>>
//
InstructionMemory::InstructionMemory(map<long,vector<string>> instructionsMap){
  for (map<long,vector<string>>::iterator it = instructionsMap.begin(); it != instructionsMap.end(); it++){
    InstrMap.insert(pair<long,vector<string>>(it->first,it->second));
  }
}


//Empty constructor just initializes InstructionMemory
InstructionMemory::InstructionMemory(){}


//
void InstructionMemory::setAddress(long pc){address = pc;}


//getForControl returns the bits 31-26 for the control unit
//
//Parameter - long address
//
//Return - binary string
string InstructionMemory::getForControl(){
  vector<string> temp = InstrMap.at(address);
  string str = temp.at(1);
  return str.substr(0,6);
}


//getForShift returns the bits 25-0 for the shift left 2 unit
//
//Parameter - long address
//
//Return - binary string
string InstructionMemory::getForShift(){
  vector<string> temp = InstrMap.at(address);
  string str = temp.at(1);
  return str.substr(6,25);
}


//getForExtend returns the bits 15-0 for the sign extend unit
//
//Parameter - long address
//
//Return - binary string
string InstructionMemory::getForExtend(){
  vector<string> temp = InstrMap.at(address);
  string str = temp.at(1);
  return str.substr(16,16);
}


//getForRegOne returns the bits 25-21 for read register 1
//
//Parameter - long address
//
//Return - binary string
string InstructionMemory::getForRegOne(){
  vector<string> temp = InstrMap.at(address);
  string str = temp.at(1);
  return str.substr(6,5);
}


//getForRegTwo returns the bits 20-16 for read register 2 and the top part
// of the multiplexor
//
//Parameter - long address
//
//Return - binary string
string InstructionMemory::getForRegTwo(){
  vector<string> temp = InstrMap.at(address);
  string str = temp.at(1);
  return str.substr(11,5);
}


//getForMuxOne returns the bits 15-11 for the bottom of the multiplexor
//
//Parameter - long address
//
//Return - binary string
string InstructionMemory::getForMuxOne(){
  vector<string> temp = InstrMap.at(address);
  string str = temp.at(1);
  return str.substr(16,5);
}



//toString prints out the contents of InstructionMemory
void InstructionMemory::toString(){
  cout << "Contents of InstructionMemory: " << endl;
  for (map<long,vector<string>>::iterator it = InstrMap.begin(); it != InstrMap.end(); it++){
    vector<string> temp = it->second;
    string inst = temp.at(1);
    cout << it->first << " => " << inst << endl;
  }
}
