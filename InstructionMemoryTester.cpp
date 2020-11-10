#include <iostream>
#include "InstructionMemory.h"
#include <vector>

int main(){
  cout << "Testing InstructionMemory:" << endl;
  cout << "--------------------------" << endl;

  cout << "Testing Constructor" << endl;
  map<long,vector<string>> instructionsMap;
  vector<string> entryOne;
  entryOne.push_back("add $1, $2, $3");
  entryOne.push_back("00210000000500000600000000000000");
  instructionsMap.insert(pair<long,vector<string>>(400000,entryOne));
  InstructionMemory instrMemory = InstructionMemory(instructionsMap);

  cout << "testing getForControl" << endl;
  cout << "---------------------" << endl;
  cout << "Output of getForControl: " << instrMemory.getForControl(400000) << endl;
  cout << "Expected Output: [002100]" << endl;
  cout << endl;

  cout << "testing getForShift" << endl;
  cout << "---------------------" << endl;
  cout << "Output of getForShift: " << instrMemory.getForShift(400000) << endl;
  cout << "Expected Output: [00000500000600000000000000]" << endl;
  cout << endl;


  cout << "testing getForExtend" << endl;
  cout << "---------------------" << endl;
  cout << "Output of getForExtend: " << instrMemory.getForExtend(400000) << endl;
  cout << "Expected Output: [0600000000000000]" << endl;
  cout << endl;


  cout << "testing getForRegOne" << endl;
  cout << "---------------------" << endl;
  cout << "Output of getForRegOne: " << instrMemory.getForRegOne(400000) << endl;
  cout << "Expected Output: [00000]" << endl;
  cout << endl;


  cout << "testing getForRegTwo" << endl;
  cout << "---------------------" << endl;
  cout << "Output of getForRegTwo: " << instrMemory.getForRegTwo(400000) << endl;
  cout << "Expected Output: [50000]" << endl;
  cout << endl;


  cout << "testing getForMuxOne" << endl;
  cout << "---------------------" << endl;
  cout << "Output of getForMuxOne: " << instrMemory.getForMuxOne(400000) << endl;
  cout << "Expected Output: [06000]" << endl;
  cout << endl;


  cout << "testing toString" << endl;
  cout << "---------------------" << endl;
  instrMemory.toString();


  return 0;
}
