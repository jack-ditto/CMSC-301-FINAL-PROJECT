#include <map>
#include <string>
#include <bitset>

using namespace std;

class RegisterFile{
  private:
    map<int,long> regMap;
    bool regWrite;
    int readRegister1;
    int readRegister2;
    int writeRegister;
    string writeData;
    string readData1;
    string readData2;

  public:
    RegisterFile(map<int,long> registerMap);
    RegisterFile();
    void setWriteRegister(string);
    void setReadReg1(string);
    void setReadReg2(string);
    void setWriteData(string in);
    string getData1();
    string getData2();
    string getWriteData();
    void setRegWrite(bool val);
    void toString();
};
