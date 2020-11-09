#include <map>
#include <string>

class RegisterFile{
  private:
    map<Register,string> regMap;
    bool regWrite
    Register readRegister1;
    Register readRegister2;
    Register writeRegister;
    string writeData;
    string readData1;
    string readData2;

  public:
    RegisterFile(map<Register,string> registerMap);
    void write(string);
    void setReadReg1(string);
    void setReadReg2(string);
    string getData1();
    string getData2();
}
