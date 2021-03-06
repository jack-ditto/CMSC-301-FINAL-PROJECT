#include <string>
#include <map>
#include <vector>

using namespace std;

class InstructionMemory{
  private:
    long address;
    string instr;
    map<long,vector<string>> instrMap;
    bool endFile = false;

  public:
    InstructionMemory(map<long,vector<string>> instructionsMap);
    InstructionMemory();
    void setAddress(long pc);
    string getForControl();
    string getForShift();
    string getForExtend();
    string getForRegOne();
    string getForRegTwo();
    string getForMuxOne();
    string getForALUControl();
    void toString();
    bool isEnd();
    void printMap();
    void printAssembly();
};
