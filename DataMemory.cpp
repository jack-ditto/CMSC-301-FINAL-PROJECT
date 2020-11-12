#include "DataMemory.h"
#include <iostream>

//constructor creates a map of data and their corresponding address
//
//parameters - map<long,long>
//
DataMemory::DataMemory(map<long,long> memoryMap){
  for (map<long,long>::iterator it = memoryMap.begin(); it != memoryMap.end(); it++){
    memMap.insert(pair<long,long>(it->first,it->second));
  }
}


//setAddr initializes the address long to the input
//
//paramenter - long input
//
void DataMemory::setAddr(long input){address = input;}


//setMemWrite sets the DataMemory Units MemWrite flag
//
//parameter - bool in
void DataMemory::setMemWrite(bool in){MemWrite = in;}


//setMemRead sets the DataMemory units MemRead flag
//
//parameter - bool in
void DataMemory::setMemRead(bool in){MemRead = in;}



//getMemWrite gets the DataMemory Units MemWrite flag
long DataMemory::getMemWrite(){return MemWrite;}


//getMemRead gets the DataMemory units MemRead flag
long DataMemory::getMemRead(){return MemRead;}


//get returns the corresponding data for a give address
//
//paramenters - long address
//
//return - corresponding data from map
long DataMemory::get(long addr){return memMap.at(addr);}


//set updates the value of the given map address to a new value
//
//parameters:
//    long addr
//    long value
//
void DataMemory::set(long addr, long value){
  map<long,long>::iterator it = memMap.find(addr);
  it->second = value;
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
