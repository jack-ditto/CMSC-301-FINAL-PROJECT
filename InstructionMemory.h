#include <string>
#include <map>

using namespace std;

class InstructionMemory{
  private:
    int address;
    string instr;
    map<int,string> InstrMap;

  public:
    InstructionMemory(map<int,string> instructionsMap);
    string getForControl(int address);
    string getForShift(int address);
    string getForExtend(int address);
    string getForRegOne(int address);
    string getForRegTwo(int address);
    string getForMuxOne(int address);
    void toString();
};
