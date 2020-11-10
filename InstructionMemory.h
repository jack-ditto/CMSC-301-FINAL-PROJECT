#include <string>
#include <map>
using namespace std;

class InstructionMemory
{

public:
	void instrMem();
	string get(int address);

private:
	string address;
	string instr;
	map<int, string> instructionMap;
}
