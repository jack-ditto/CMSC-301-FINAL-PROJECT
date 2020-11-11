#include <map>
#include <string>

using namespace std;

class RegisterFile{
  private:
    map<int,long> regMap;
    bool regWrite;
    int readRegister1;
    int readRegister2;
    int writeRegister;
    long writeData;
    long readData1;
    long readData2;

  public:
    RegisterFile(map<int,long> registerMap);
    void setWriteRegister(string);
    void setReadReg1(string);
    void setReadReg2(string);
    long getData1();
    long getData2();
    long getWriteData();
    void setRegWrite(bool val);
    bool getRegWrite();
    void toString();
};
