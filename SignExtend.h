#include <string>

using namespace std;

class SignExtend{
  private:
    string input;
    string output;

  public:
    SignExtend();
    setInput(string in);
    void extend();
    string get();
    void toString();
};
