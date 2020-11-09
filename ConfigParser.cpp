#include "ConfigParser.h"
#include "ASMParser.h"
#include <algorithm> // for removing blank spaces

string preprocess(string line){
    line.erase(remove_if(line.begin(), line.end(), ::isspace), line.end()); // removes whitespaces
    size_t index = line.find("#");
    if(index != string::npos)
        line = line.substr(0, index);
    return line;
}

ConfigParser::ConfigParser(string filename){
    ifstream in;
    in.open(filename.c_str());

    if(in.bad()){
        std::cout << "BAD FILE!!!" << std::endl;
    }
    else{
        string line;
        while(getline(in, line)){
            line = preprocess(line);
            if(line.empty() || line[0] == '#')
                continue;
            size_t index = line.find("=");
            configParameters[line.substr(0, index)] = line.substr(index + 1, line.length());
        }

        for (const auto &p : configParameters) {
            std::cout << "key[" << p.first << "] = " << p.second << '\n';
        }

        setInstructions();
        setMemory();
        setRegisters();
    }
}

void ConfigParser::setInstructions(){
    // ASMParser *parser;
    // parser = new ASMParser(configParameters["program_input"]);
}
void ConfigParser::setMemory(){}
void ConfigParser::setRegisters(){}