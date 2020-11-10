#include <iostream>
#include <string>
#include "SignExtend.h"

using namespace std;

int main(){
  //Constructor
  cout << "Testing constructor: " << endl;
  string tOne = "0101000000000001";
  string tTwo = "1010111111111110";
  SignExtend one = SignExtend(tOne);
  SignExtend two = SignExtend(tTwo);

  //extend
  cout << "Extending SignExtend one" << endl;
  cout << "Extending SignExtend two" << endl;
  one.extend();
  two.extend();

  //toString
  cout << "Displaying contents of one using toString() method" << endl;
  one.toString();
  cout << "Displaying contents of two using toString() method" << endl;
  two.toString();

  //get
  cout << "Testing the get method:" << endl;
  cout << "Ouput of SignExtend one with get is: " << one.get() << endl;
  cout << "Ouput of SignExtend two with get is: " << two.get() << endl;

  return 0;
}
