#include <iostream>
#include "SignExtend.h"

SignExtend::SignExtend(){}

//setInput sets the input instance variable
void SignExtend::setInput(string in){input = in;}

//get method returns the extended input
string SignExtend::get(){
  string first = input.substr(0,1);
  if (first == "1"){
    output = "1111111111111111" + input;
  }else{
    output = "0000000000000000" + input;
  }
  return output;
}

//toString method prints out input and output of sign extend
void SignExtend::toString(){
  cout << "Contents of SignExtend: " << endl;
  cout << "------------------------------" << endl;
  cout << "Input => 0x" << hex << input << endl;
  cout << "Output => 0x" << hex << output << endl;
  cout << "------------------------------" << endl;
  cout << endl;
}
