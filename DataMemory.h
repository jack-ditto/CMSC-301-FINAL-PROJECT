#include <map>
#include <string>

using namespace std;

class DataMemory{
  private:
    bool MemWrite;
    bool MemRead;
    string address;
    string data;
    map<int,string> memMap;

  public:
    DataMemory();
    void setAddr(string input);
    string get(int addr);
    void set(int addr, string value);
};
