#include "DataMemory.h"
#include <iostream>
#include <exception>

//constructor creates a map of data and their corresponding address
//
//parameters - map<long,long>
//
DataMemory::DataMemory(map<long,long> memoryMap){
  memMap = memoryMap;
}


//Empty constructor just initializes DataMemory
DataMemory::DataMemory(){}


//setAddr initializes the address long to the input
//
//paramenter - string input
//
void DataMemory::setAddr(string input){address = input;}


//setMemWrite sets the DataMemory Units MemWrite flag
//
//parameter - bool in
void DataMemory::setMemWrite(bool in){
  MemWrite = in;
  //if writing or reading, check for invalid address and empty string
  if (MemWrite || MemRead){
    if (address == "" || memMap.count(stol(address,nullptr,2)) == 0){
    throw invalid_argument("address is not in the DataMemory");
    }
  }
  if (MemWrite){
    write();
  }
}


//setMemRead sets the DataMemory units MemRead flag
//
//parameter - bool in
void DataMemory::setMemRead(bool in){MemRead = in;}


//get returns the corresponding data for a give address
//
//paramenters - long address
//
//return - corresponding data from map
string DataMemory::get(){
  if (!MemRead){
    return "00000000000000000000000000000000";
  }
  return bitset<32>(memMap.at(stol(address,nullptr,2))).to_string();
}

//set initializes data string to input
//
//parameters - string str
//
void DataMemory::setWriteData(string str){
  data = str;
}


//write updates the value of the given map address to a new value
//
//parameters:
//    long addr
//    long value
//
void DataMemory::write(){
  long addr = stol(address,nullptr,2);
  long d = stol(data,nullptr,2);
  memMap[addr] = d;
}


//toString prints out the contents of DataMemory
void DataMemory::toString(){
  cout << "Contents of DataMemory: " << endl;
  cout << "MemRead: " << MemRead << endl;
  cout << "MemWrite: " << MemWrite << endl;
  cout << "Write Data: " << data << endl;
  cout << "Read Data: " << address << endl;
}


//print outputs the contents of the DataMemory map
//
void DataMemory::printMap(){

  cout << "Print DataMemory Map" << endl;
  cout << "------------------" << endl;
  for (map<long,long>::iterator it = memMap.begin(); it != memMap.end(); it++){
    cout << it->first << " => "<< it->second << endl;
  }
  cout << "------------------" << endl;
}