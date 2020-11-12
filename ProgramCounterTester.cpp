#include <iostream>
#include "ProgramCounter.h"

using namespace std;

int main(){
  ProgramCounter pc;
  cout << "Output of PC using toString:" << endl;
  pc.toString();

  cout << "Output of PC using get(): " << pc.get() << endl;

  cout << "Testing set() method: " << endl;
  pc.set(400004);

  cout << "Output of PC after using set() - with get(): " << pc.get() << endl;

  cout << "Output of PC using toString() after the set() method" << endl;
  pc.toString();

  return 0;
}
