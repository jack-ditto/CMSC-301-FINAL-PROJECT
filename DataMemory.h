#include <map>
#include <string>
#include <bitset>

using namespace std;

class DataMemory{
  private:
    bool MemWrite;
    bool MemRead;
    string address;
    string data;
    map<long,long> memMap;
    void write();

  public:
    DataMemory(map<long,long> memoryMap);
    DataMemory();
    void setAddr(string input);
    string get();
    void set(long addr, long value);
    void setMemRead(bool in);
    void setMemWrite(bool in);
    void toString();
    void setWriteData(string str);
    bool getMemWrite();
    bool getMemRead();
    string getAddress();
    string getData();
    void printMap();
};
