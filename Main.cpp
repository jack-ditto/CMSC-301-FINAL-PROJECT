#include "ConfigParser.h"
#include "Processor.h"

using namespace std;

int main(int argc, char const *argv[])
{
	ConfigParser *parser;

	if(argc < 2){
		cerr << "Need to specify an assembly file to translate."<<endl;
		exit(1);
  	}

	parser = new ConfigParser(argv[1]);

	Processor processor = Processor(parser->getInstructions(), parser->getMemory(), parser->getRegisters());
	return 0;
}
