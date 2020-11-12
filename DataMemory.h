#include <map>
#include <string>

using namespace std;

class DataMemory{
  private:
    bool MemWrite;
    bool MemRead;
    string address;
    string data;
    map<long,long> memMap;

  public:
    DataMemory(map<long,long> memoryMap);
    DataMemory();
    void setAddr(long input);
    long get(long addr);
    void set(long addr, long value);
    void setMemRead(bool in);
    void setMemWrite(bool in);
    long getMemRead();
    long getMemWrite();
    void toString();
};
