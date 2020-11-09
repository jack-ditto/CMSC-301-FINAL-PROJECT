#include "ConfigParser.h"

using namespace std;

int main(int argc, char const *argv[])
{
	ConfigParser *parser;

	if(argc < 2){
		cerr << "Need to specify an assembly file to translate."<<endl;
		exit(1);
  	}

	parser = new ConfigParser(argv[1]);
	return 0;
}
