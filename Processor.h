#ifndef __PROCESSOR_H__
#define __PROCESSOR_H__

#include <iostream>
#include <map>
#include <vector>

#include "ALU.h"
#include "ALUControl.h"
#include "Control.h"
#include "DataMemory.h"
#include "InstructionMemory.h"
#include "Multiplexer.h"
#include "ProgramCounter.h"
#include "RegisterFile.h"
#include "ShiftLeftTwo.h"
#include "SignExtend.h"

using namespace std;

class Processor{
    public:
        Processor(map<long, vector<string>> instructionMap,
            map<long, long> memoryMap, map<int, long> registerMap);
        void step();

    private:
        ProgramCounter programCounter;
        InstructionMemory instructionMemory;
        DataMemory dataMemory;
        RegisterFile registerFile;
        ALU alu1;
        ALU alu2;
        ALU alu3;
        Multiplexer multiplexer1;
        Multiplexer multiplexer2;
        Multiplexer multiplexer3;
        Multiplexer multiplexer4;
        Multiplexer multiplexer5;
        ShiftLeftTwo shiftLeftTwo1;
        ShiftLeftTwo shiftLeftTwo2;
        Control control;
        ALUControl aluControl;
        SignExtend signExtend;
        string concatinatePC(string shift, int pc);
};
#endif