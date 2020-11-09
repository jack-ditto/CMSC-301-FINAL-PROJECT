#include "DataMemory.h"

//constructor creates a map of data and their corresponding address
//
//parameters - map<int,string>
//
DataMemory::DataMemory(map<int,string> memoryMap){
  for (map<int,string>::iterator it = memoryMap.begin; it != memoryMap.end(); it++){
    memMap.insert(pair<int,string>(it->first,it->second));
  }
}

//setAddr initializes the address string to the input
//
//paramenter - string input
//
void DataMemory::setAddr(string input){address = input;}

//get returns the corresponding data for a give address
//
//paramenters - int address
//
//return - hex string
string DataMemory::get(int addr){return memMap.find(addr);}


//set updates the value of the given map address to a new value
//
//parameters:
//    int addr
//    string value
//
void DataMemory::set(int addr, string value){
  map<int,string>::iterator it = memMap.find(addr);
  it->second = value;
}


void DataMemory::toString(){
  cout << "Contents of DataMemory: " << endl;
  for (map<int,string>::iterator it = memMap.begin; it != memMap.end(); it++){
    cout << it->first << " => " << it->second << endl;
  }
}
