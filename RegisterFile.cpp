#include "RegisterFile.h"
#include <iostream>


//constructor creates a map of registers and their corresponding data
//
//parameters - map<Register,string>
//
RegisterFile::RegisterFile(map<int,long> registerMap){
  for (map<int,long>::iterator it = registerMap.begin(); it != registerMap.end(); it++){
    regMap.insert(pair<int,long>(it->first,it->second));
  }
}


//write sets writeData to input
//
//parameter - string write
//
void RegisterFile::setWriteRegister(string write){
  writeRegister = stoi(write,nullptr,2);
  writeData = regMap.at(writeRegister);
}


//setReadReg1 sets register one to val
//
//parameter - string val
//
void RegisterFile::setReadReg1(string val){
  readRegister1 = stoi(val,nullptr,2);
  readData1 = regMap.at(readRegister1);
}


//setReadReg2 sets register two to val
//
//parameter - string val
//
void RegisterFile::setReadReg2(string val){
  readRegister2 = stoi(val,nullptr,2);
  readData2 = regMap.at(readRegister2);
}


//setRegWrite sets the RegWrite flag
//
//parameter - bool val
//
void RegisterFile::setRegWrite(bool val){regWrite = val;}


//getRegWrite returns the boolean value of RegWrite
//
//return - boolean
bool RegisterFile::getRegWrite(){return regWrite;}


//getData1 returns value of data assocaited with readRegister1
//
//return - long
long RegisterFile::getData1(){return readData1;}


//getData2 returns value of data associated with readRegeister2
//
//return - long
long RegisterFile::getData2(){return readData2;}

//getWriteData
//
//return - long
long RegisterFile::getWriteData(){return writeData;}


void RegisterFile::toString(){
  cout << "Contents of RegisterFile: " << endl;
  cout << "--------------------------" << endl;
  cout << "Read Register 1 contains: " << readRegister1 << endl;
  cout << "Read Register 2 contains: " << readRegister2 << endl;
  cout << "Write Register contains: " << writeRegister << endl;
  cout << "Read Data 1 contains: " << readData1 << endl;
  cout << "Read Data 2 contains: " << readData2 << endl;
  cout << "Write Data contains: " << writeData << endl;
  cout << "regWrite flag set to: " << regWrite << endl;
  cout << "-------------------------" << endl;
}
