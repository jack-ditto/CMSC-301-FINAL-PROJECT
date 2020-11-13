#include "DataMemory.h"
#include <iostream>

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
  return bitset<32>(memMap.at(stol(address))).to_string();
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
  long addr = stol(address);
  long d = stol(data);
  memMap[addr] = d;
}



//toString prints out the contents of DataMemory
void DataMemory::toString(){
  cout << "Contents of DataMemory: " << endl;
  cout << "MemRead: " << MemRead << endl;
  cout << "MemWrite: " << MemWrite << endl;
  cout << "Write Data: " << data << endl;
  cout << "Read Data: " << address << endl;

  /*for (map<long,long>::iterator it = memMap.begin; it != memMap.end(); it++){
    cout << it->first << " => " << it->second << endl;
  }*/
}
