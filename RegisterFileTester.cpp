#include "RegisterFile.h"
#include <iostream>


int main(){

  cout << "Testing RegisterFile:" << endl;
  cout << "--------------------------" << endl;
  cout << endl;

  map<int,long> registerMap;
  registerMap.insert(pair<int,long>(1,34524362));
  registerMap.insert(pair<int,long>(2,890123));
  registerMap.insert(pair<int,long>(5,123466));

  cout << "Testing RegisterFile Constructor:" << endl;
  cout << "--------------------------" << endl;
  RegisterFile regFile = RegisterFile(registerMap);
  cout << endl;
  cout << endl;


  cout << "Testing setWriteRegister() method:" << endl;
  cout << "--------------------------" << endl;
  string value = "00101";
  regFile.setWriteRegister(value);
  cout << endl;
  cout << endl;


  cout << "Testing setReadReg1() method:" << endl;
  cout << "--------------------------" << endl;
  string val = "00001";
  regFile.setReadReg1(val);
  cout << endl;
  cout << endl;


  cout << "Testing setReadReg2() method:" << endl;
  cout << "--------------------------" << endl;
  cout << endl;
  string valTwo = "00010";
  regFile.setReadReg2(valTwo);
  cout << endl;
  cout << endl;


  cout << "Testing getData1() method:" << endl;
  cout << "--------------------------" << endl;
  cout << "Output of getData1(): " << regFile.getData1() << endl;
  cout << "Expected: [34524362]";
  cout << endl;
  cout << endl;
  cout << endl;


  cout << "Testing getData2() method:" << endl;
  cout << "--------------------------" << endl;
  cout << "Output of getData2(): " << regFile.getData2() << endl;
  cout << "Expected: [890123]";
  cout << endl;
  cout << endl;


  cout << "Testing getWriteData() method" << endl;
  cout << "-----------------------------" << endl;
  cout << "Output of getWriteData(): " << regFile.getWriteData() << endl;
  cout << "Expected: [123466]";
  cout << endl;
  cout << endl;


  cout << "Testing setRegWrite() method" << endl;
  cout << "----------------------------" << endl;
  bool tr = true;
  regFile.setRegWrite(tr);
  cout << endl;
  cout << endl;


  cout << "Testing getRegWrite() method" << endl;
  cout << "----------------------------" << endl;
  cout << "Output of getRegWrite(): " << regFile.getRegWrite() << endl;
  cout << "Expected: [1]" << endl;
  cout << endl;
  cout << endl;


  cout << "Testing toString() method" << endl;
  cout << "-------------------------" << endl;
  regFile.toString();


  return 0;
}
