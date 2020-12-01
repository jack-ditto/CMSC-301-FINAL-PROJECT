#include "RegisterFile.h"
#include <iostream>


//constructor creates a map of registers and their corresponding data
//
//parameters - map<Register,string>
//
RegisterFile::RegisterFile(map<int,long> registerMap){
  regMap = registerMap;
}


//Empty constructor just initializes RegisterFile
RegisterFile::RegisterFile(){}


//write sets writeData to input
//
//parameter - string write
//
void RegisterFile::setWriteRegister(string write){
  writeRegister = stoi(write,nullptr,2);
}


//setReadReg1 sets register one to val
//
//parameter - string val
//
void RegisterFile::setReadReg1(string val){
  readRegister1 = stoi(val,nullptr,2);
  readData1 = bitset<32>(regMap.at(readRegister1)).to_string();
}


//setReadReg2 sets register two to val
//
//parameter - string val
//
void RegisterFile::setReadReg2(string val){
  readRegister2 = stoi(val,nullptr,2);
  readData2 = bitset<32>(regMap.at(readRegister2)).to_string();
}


void RegisterFile::setWriteData(string in){
  writeData = in;
  if (regWrite){
    long input = stol(in,nullptr,2);
    regMap[writeRegister] = input;
  }
}


//setRegWrite sets the RegWrite flag
//
//parameter - bool val
//
void RegisterFile::setRegWrite(bool val){regWrite = val;}


//getData1 returns value of data assocaited with readRegister1
//
//return - string
string RegisterFile::getData1(){return readData1;}


//getData2 returns value of data associated with readRegeister2
//
//return - string
string RegisterFile::getData2(){return readData2;}

//getWriteData returns data to be written
//
//return - string
string RegisterFile::getWriteData(){return writeData;}


//toString prints out the content of the RegisterFile after a given instruction
//
void RegisterFile::toString(){
  cout << "Contents of RegisterFile: " << endl;
  cout << "--------------------------" << endl;
  cout << "Read Register 1 => 0x" << hex << readRegister1 << endl;
  cout << "Read Register 2 => 0x" << hex << readRegister2 << endl;
  cout << "Write Register => 0x" << hex << writeRegister << endl;
  cout << "Read Data 1 => 0x" << hex << stol(readData1,nullptr,2) << endl;
  cout << "Read Data 2 => 0x" << hex << stol(readData2,nullptr,2) << endl;
  cout << "Write Data => 0x" << hex << stol(writeData,nullptr,2) << endl;
  cout << "regWrite flag => 0x" << hex << regWrite << endl;
  cout << "-------------------------" << endl;
  cout << endl;
}

//printMap prints out the full contents of the RegisterFile
//
void RegisterFile::printMap(){
  cout << "Print RegisterFile Map" << endl;
  cout << "------------------" << endl;
  for (map<int,long>::iterator it = regMap.begin(); it != regMap.end(); it++){
    cout << dec << it->first << " => 0x" << hex << it->second << endl;
  }
  cout << "------------------" << endl;
  cout << endl;
}