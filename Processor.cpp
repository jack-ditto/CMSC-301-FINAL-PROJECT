#include "Processor.h"
#include<bitset>

Processor::Processor(map<long, vector<string>> instructionMap,
    map<long, long> memoryMap, map<int, long> registerMap){
        // Create instances of all components
        instructionMemory = InstructionMemory(instructionMap);
        dataMemory = DataMemory(memoryMap);
        registerFile = RegisterFile(registerMap);
}

string concatenatePC(string shift, int pc){
    string programC = bitset<32>(pc).to_string();
    string result = programC.substr(0, 4) + shift.substr(5, 28);
    return result;
}

void Processor::step(){
    // Get PC from program counter
    long pc = programCounter.get();

    // Pass PC to instruction memory
    instructionMemory.setAddress(pc);

    if(instructionMemory.isEnd()){
        endExecution = true;
        return;
    }

    // passes bits 31-26 of the instruction into the control unit
    control.setInstruction(instructionMemory.getForControl());
    // Pass regist write value into register unit
    registerFile.setRegWrite(control.getRegWrite());
    // Pass bits 25-21 into read register one
    registerFile.setReadReg1(instructionMemory.getForRegOne());
    // Pass bits 20-16 into read register two
    registerFile.setReadReg2(instructionMemory.getForRegTwo());
    // Pass bits 20-16 into top (0) of multiplexor and bits 15-11 for bottom (1) of mux
    multiplexer1.setChoices(instructionMemory.getForRegTwo(), instructionMemory.getForMuxOne());
    // Pass RegDst from control to mux1
    multiplexer1.setControl(control.getRegDst());
    // Pass the result of mux1 to write register
    registerFile.setWriteRegister(multiplexer1.get());

    // Pass bits 15-0 to Sign extend
    signExtend.setInput(instructionMemory.getForExtend());
    // Set values for ALU control
    aluControl.set(control.getAluOp(), instructionMemory.getForALUControl());
    // Set choices of mux2 to read data 2 and sign extend
    multiplexer2.setChoices(registerFile.getData2(), signExtend.get());
    // Set Multiplexor control to output of ALUsrc
    multiplexer2.setControl(control.getAluSrc());
    // Pass ReadData1 and the result of mux2 and alucontrol into ALU3
    alu3.setValues(aluControl.get(), registerFile.getData1(), multiplexer2.get());

    // Pass the result of ALU3 to DataMemory address
    dataMemory.setAddr(alu3.getResult());
    // Pass ReadData2 to DataMemory Write data
    dataMemory.setWriteData(registerFile.getData2());
    // Pass MemRead control bits to DataMemory
    dataMemory.setMemRead(control.getMemRead());
    // Pass MemWrite control bits to DataMemory
    dataMemory.setMemWrite(control.getMemWrite());
    // Set choices of mux3 to result of ALU3 (0) and read data in DatMemory (1)
    multiplexer3.setChoices(alu3.getResult(), dataMemory.get());
    // Set mux3 control bits to MemToReg
    multiplexer3.setControl(control.getMemToReg());
    // Set register file write data to output of multiplexer3
    registerFile.setWriteData(multiplexer3.get());

    // PC + 4, 0 means add
    alu1.setValues(0, bitset<32>(pc).to_string(), "100");
    // Set shiftLeftTwo1 to bits 25-0 from instruction memory
    shiftLeftTwo1.set(instructionMemory.getForShift());
    // Set shiftLetTwo2 to 32b output of sign extend
    shiftLeftTwo2.set(signExtend.get());

    // Set values of alu2 to output of alu1 and shiftleftTwo2
    alu2.setValues(0, alu1.getResult(), shiftLeftTwo2.get());

    // Set choices of mux5 to output of alu1 and alu2
    multiplexer5.setChoices(alu1.getResult(), alu2.getResult());
    // Set control of mux5 to (branch AND zero) flags
    multiplexer5.setControl(control.getBranch() && alu3.getZeroFlag());
    // Set choices of mux4 to output of mux5 and shiftLeftTwo1
    multiplexer4.setChoices(multiplexer5.get(), concatenatePC(shiftLeftTwo1.get(), pc));
    // Set control of mux4 to jump flag
    multiplexer4.setControl(control.getJump());

    string result = multiplexer4.get();

    print();

    // Updates PC to output of mux4
    programCounter.set(result);

}

void Processor::print(){
    instructionMemory.printAssembly();
    programCounter.toString();
    instructionMemory.toString();
    control.toString();
    aluControl.toString();
    registerFile.toString();
    signExtend.toString();
    dataMemory.toString();

    alu1.toString();
    alu2.toString();
    alu3.toString();

    multiplexer1.toString();
    multiplexer2.toString();
    multiplexer3.toString();
    multiplexer4.toString();
    multiplexer5.toString();

    shiftLeftTwo1.toString();
    shiftLeftTwo2.toString();

    if(printMemoryContents){
        instructionMemory.printMap();
        registerFile.printMap();
        dataMemory.printMap();
    }
}

void Processor::setParameters(bool debugMode, bool printMemoryContents){
    this->debugMode = debugMode;
    this->printMemoryContents = printMemoryContents;
}