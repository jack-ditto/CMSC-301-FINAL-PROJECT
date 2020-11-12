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
        std::cout << "BAD Config FILE!!!" << std::endl;
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

        // for (const auto &p : configParameters) {
        //     std::cout << "key[" << p.first << "] = " << p.second << '\n';
        // }

        setInstructions();
        setMemory();
        setRegisters();
    }
}

void ConfigParser::setInstructions(){
    ASMParser *parser;
    parser = new ASMParser(configParameters["program_input"]);

    if(parser->isFormatCorrect() == false){
        cerr << "Format of input file is incorrect " << endl;
        exit(1);
    }

    instructionMap = parser->getInstructionMap();
    for (const auto &p : instructionMap) {
        std::cout << "key[" << hex << p.first << "] = " << p.second.at(0) << " ; " << p.second.at(1) << '\n';
    }
}

void ConfigParser::setMemory(){
    ifstream in;
    in.open(configParameters["memory_contents_input"].c_str());

    if(in.bad()){
        std::cout << "BAD memory FILE!!!" << std::endl;
    }
    else{
        string line;
        while(getline(in, line)){
            line = preprocess(line);
            if(line.empty() || line[0] == '#')
                continue;
            size_t index = line.find(":");
            long address = stol(line.substr(0, index), nullptr, 16);
            long contents = stol(line.substr(index + 1, line.length()), nullptr, 16);
            memoryMap[address] = contents;
        }

        // for (const auto &p : memoryMap) {
        //     std::cout << "key[" << hex << p.first << "] = "<< hex << p.second << '\n';
        // }
    }
}

void ConfigParser::setRegisters(){
    ifstream in;
    in.open(configParameters["register_file_input"].c_str());

    if(in.bad()){
        std::cout << "BAD register FILE!!!" << std::endl;
    }
    else{
        string line;
        while(getline(in, line)){
            line = preprocess(line);
            if(line.empty() || line[0] == '#')
                continue;
            size_t index = line.find(":");
            int address = stoi(line.substr(0, index), nullptr, 10);
            long contents = stol(line.substr(index + 1, line.length()), nullptr, 16);
            registerMap[address] = contents;
        }

        // for (const auto &p : registerMap) {
        //     std::cout << "key[" << p.first << "] = " << p.second << '\n';
        // }
    }

}

map<long, vector<string>> ConfigParser::getInstructions(){
    return instructionMap;
}

map<long, long> ConfigParser::getMemory(){
    return memoryMap;
}

map<int, long> ConfigParser::getRegisters(){
    return registerMap;
}

string ConfigParser::outputMode(){
    return configParameters["output_mode"];
}