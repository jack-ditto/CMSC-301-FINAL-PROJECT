#include "Processor.h"

Processor::Processor(map<long, vector<string>> instructionMap,
    map<long, long> memoryMap, map<int, long> registerMap){
        // Create instances of all components
        instructionMemory = InstructionMemory(instructionMap);
        dataMemory = DataMemory(memoryMap);
        registerFile = RegisterFile(registerMap);
}

void Processor::step(){}