#include "RegisterFile.h"


//constructor creates a map of registers and their corresponding data
//
//parameters - map<Register,string>
//
RegisterFile::RegisterFile(map<Register,string> registerMap){
  for (map<Register,string>::iterator it = registerMap.begin; it != registerMap.end(); it++){
    regMap.insert(pair<Register,string>(it->first,it->second));
  }
}


//write sets writeData to input
//
//parameter - string write
//
void RegisterFile::write(string write){writeData = write;}


//setReadReg1 sets register one to val
//
//parameter - string val
//
void RegisterFile::setReadReg1(string val){readRegister1 = val;}


//setReadReg2 sets register two to val
//
//parameter - string val
//
void RegisterFile::setReadReg2(string val){readRegister2 = val;}


//getData1 returns value of data assocaited with readRegister1
//
//return - string
string RegisterFile::getData1(){
  readData1 = regMap.find(readRegister1);
  return readData1;
}


//getData2 returns value of data associated with readRegeister2
//
//return - string
string RegisterFile::getData2(){
  readData2 = regMap.find(readRegister2);
  return readData2;
}


void RegisterFile::toString(){
  cout << "Contents of RegisterFile: " << endl;
  cout << "Read Register 1 contains: " << readRegister1 << endl;
  cout << "Read Register 2 contains: " << readRegister2 << endl;
  cout << "Write Register contains: " << regWrite << endl;
  cout << "Read Data 1 contains: " << readData1 << endl;
  cout << "Read Data 2 contains: " << readData2 << endl;
}
