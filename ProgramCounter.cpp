#include <iostream>
#include "ProgramCounter.h"
#include<string>

//Constructor initializes pc to 400000
ProgramCounter::ProgramCounter(): pc(0x400000) {}

//Set updates pc to new parameter
void ProgramCounter::set(string newPC) {pc = stoi(newPC);}

//get returns the current value of pc
int ProgramCounter::get() {return pc;}

//toString prints out contents of pc
void ProgramCounter::toString(){
  cout << "PC is currently: " << pc << endl;
}
