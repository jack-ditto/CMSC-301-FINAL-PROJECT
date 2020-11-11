#include <string>
#include <map>
#include <vector>

using namespace std;

class InstructionMemory{
  private:
    long address;
    string instr;
    map<long,vector<string>> InstrMap;

  public:
    InstructionMemory(map<long,vector<string>> instructionsMap);
    string getForControl(long address);
    string getForShift(long address);
    string getForExtend(long address);
    string getForRegOne(long address);
    string getForRegTwo(long address);
    string getForMuxOne(long address);
    void toString();
};
