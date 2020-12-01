#include <string>

using namespace std;

class SignExtend{
  private:
    string input;
    string output;

  public:
    SignExtend();
    void setInput(string in);
    string get();
    void toString();
    string getInput();
};
