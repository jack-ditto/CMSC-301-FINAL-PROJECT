#include "ConfigParser.h"
#include "Processor.h"

using namespace std;

int main(int argc, char const *argv[])
{
	ConfigParser *parser;
	char wait;

	if(argc < 2){
		cerr << "Need to specify an assembly file to translate."<<endl;
		exit(1);
  	}

	parser = new ConfigParser(argv[1]);
	Processor processor = Processor(parser->getInstructions(), parser->getMemory(), parser->getRegisters());
	processor.setParameters(parser->debugMode(), parser->printMemoryContents(), parser->writeToFile(), parser->getFileName());

	try{
		while (!processor.finishedExecution()){
			processor.step();
			if(parser->outputMode() == "single_step")
				cin.get(wait);
		}
	}catch(const std::invalid_argument& e){
		std::cout << e.what() << std::endl;
	}

	delete parser;
	return 0;
}
