#include <iostream>
#include "ProgramCounter.h"


//Constructor initializes pc to 400000
ProgramCounter::ProgramCounter(): pc(400000) {}

//Set updates pc to new parameter
void ProgramCounter::set(int newPC) {pc = newPC;}

//get returns the current value of pc
int ProgramCounter::get() {return pc;}

//toString prints out contents of pc
void ProgramCounter::toString(){
  cout << "PC is currently: " << pc << endl;
}
