#include "ConfigParser.h"
#include "ASMParser.h"
#include <algorithm> // for removing blank spaces

/**
 * Processes a line removing comments and spaces
 *
 * @param line line needed to be processed
 * @return string - processed line
 */
string preprocess(string line){
    line.erase(remove_if(line.begin(), line.end(), ::isspace), line.end()); // removes whitespaces
    //removes comments
    size_t index = line.find("#");
    if(index != string::npos)
        line = line.substr(0, index);
    return line;
}

/**
 * Constructor for processing config files
 *
 * @param filename name of the file to be processed
 */
ConfigParser::ConfigParser(string filename){
    ifstream in;
    in.open(filename.c_str());

    if(!in){
        std::cerr << "BAD Config FILE!!!" << std::endl;
        exit(1);
    }
    else{
        string line;
        while(getline(in, line)){
            line = preprocess(line);
            if(line.empty() || line[0] == '#')
                continue;
            // process config parameters
            size_t index = line.find("=");
            configParameters[line.substr(0, index)] = line.substr(index + 1, line.length());
        }

        // for (const auto &p : configParameters) {
        //     std::cout << "key[" << p.first << "] = " << p.second << '\n';
        // }

        // set all the maps
        setInstructions();
        setMemory();
        setRegisters();
    }
}

/**
 * Set the instruction map
 */
void ConfigParser::setInstructions(){
    ASMParser *parser;
    parser = new ASMParser(configParameters["program_input"]);

    if(parser->isFormatCorrect() == false){
        cerr << "Format of asm file is incorrect " << endl;
        exit(1);
    }

    instructionMap = parser->getInstructionMap();
    // for (const auto &p : instructionMap) {
    //     std::cout << "key[" << hex << p.first << "] = " << p.second.at(0) << " ; " << p.second.at(1) << '\n';
    // }
    delete parser;
}

/**
 * Set the memory map
 */
void ConfigParser::setMemory(){
    ifstream in;
    in.open(configParameters["memory_contents_input"].c_str());

    if(!in){
        std::cout << "BAD memory FILE!!!" << std::endl;
        exit(1);
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

/**
 * Set the register map
 */
void ConfigParser::setRegisters(){
    ifstream in;
    in.open(configParameters["register_file_input"].c_str());

    if(!in){
        std::cout << "BAD register FILE!!!" << std::endl;
        exit(1);
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

/**
 * Get instruction map
 * @return map<long, vector<string>>
 */
map<long, vector<string>> ConfigParser::getInstructions(){ return instructionMap; }

/**
 * Get memory map
 * @return map<long, long>
 */
map<long, long> ConfigParser::getMemory(){ return memoryMap; }

/**
 * Get register map
 * @return map<int, long>
 */
map<int, long> ConfigParser::getRegisters(){ return registerMap; }

/**
 * Get output mode
 * @return string output mode
 */
string ConfigParser::outputMode(){ return configParameters["output_mode"]; }

/**
 * Get output file name
 * @return string output file name
 */
string ConfigParser::getFileName(){ return configParameters["output_file"]; }

/**
 * Print memory contents
 * @return true if print memory contents
 */
bool ConfigParser::printMemoryContents(){
    if(configParameters["print_memory_contents"] == "true")
        return true;
    else
        return false;
}

/**
 * Debug mode
 * @return true if print debug info
 */
bool ConfigParser::debugMode(){
    if(configParameters["debug_mode"] == "true")
        return true;
    else
        return false;
}

/**
 * write to file
 * @return true if write output to a file
 */
bool ConfigParser::writeToFile(){
    if(configParameters["write_to_file"] == "true")
        return true;
    else
        return false;
}