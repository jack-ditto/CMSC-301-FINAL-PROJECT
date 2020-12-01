#include "ConfigParser.h"
#include "Processor.h"

using namespace std;


class stream_redirection
{
    std::ostream& from;
    std::ofstream to;
    std::streambuf *const saved;
public:
    stream_redirection(std::ostream& from, const std::string& filename)
        : from{from},
          to{filename},
          saved{from.rdbuf(to.rdbuf())}
    {}
    stream_redirection(const stream_redirection&) = delete;
    void operator=(const stream_redirection&) = delete;
    ~stream_redirection()
    {
        from.rdbuf(saved);
    }
};


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

	std::ofstream out("out.txt");
    std::streambuf *coutbuf = std::cout.rdbuf();
    std::cout.rdbuf(out.rdbuf());

	try{
		while (!processor.finishedExecution()){
			processor.step();
			if(parser->outputMode() == "single_step")
				cin.get(wait);
		}
	}catch(const std::invalid_argument& e){
		std::cout << e.what() << std::endl;
	}

	std::cout.rdbuf(coutbuf); //reset to standard output again
	out.close();

	delete parser;
	return 0;
}
