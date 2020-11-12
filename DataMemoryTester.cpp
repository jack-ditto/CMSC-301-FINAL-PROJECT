#include "DataMemory.h"
#include <iostream>
#include <vector>

int main(){
  cout << "Testing InstructionMemory:" << endl;
  cout << "--------------------------" << endl;
  cout << endl;

  map<long,long> memoryMap;
  memoryMap.insert(pair<long,long>(12,12));
  memoryMap.insert(pair<long,long>(34567,890123));

  cout << "Testing InstructionMemory Constructor:" << endl;
  cout << "--------------------------" << endl;
  DataMemory DatMem = DataMemory(memoryMap);
  cout << endl;

  /*cout << "Testing setAddr() method:" << endl;
  cout << "--------------------------" << endl;


  cout << endl;*/

  cout << "Testing get() method:" << endl;
  cout << "--------------------------" << endl;
  cout << "Output of get(12): " << DatMem.get(12) << endl;
  cout << "Expected Output: [12]" << endl;
  cout << "Output of get(34567): " << DatMem.get(34567) << endl;
  cout << "Expected Output: [890123]" << endl;
  cout << endl;

  cout << "Testing setMemRead() method:" << endl;
  cout << "--------------------------" << endl;
  bool one = true;
  DatMem.setMemRead(one);

  cout << "Testing setMemWrite() method:" << endl;
  cout << "--------------------------" << endl;
  bool two = false;
  DatMem.setMemWrite(two);
  cout << endl;

  cout << "Testing getMemRead() method:" << endl;
  cout << "--------------------------" << endl;
  cout << "Output of getMemRead(): " << DatMem.getMemRead() << endl;
  cout << "Expected: [1]" << endl;
  cout << endl;

  cout << "Testing getMemWrite() method:" << endl;
  cout << "--------------------------" << endl;
  cout << "Output of getMemWrite: " << DatMem.getMemWrite() << endl;
  cout << "Expected: [0]" << endl;
  cout << endl;


  cout << "Testing set() method:" << endl;
  cout << "--------------------------" << endl;
  DatMem.set(12,14);
  cout << "New output for get(12): " << DatMem.get(12) << endl;
  cout << "Expected: [14]" << endl;

  return 0;
}
