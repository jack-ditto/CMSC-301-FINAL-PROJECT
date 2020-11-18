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
    string result = programC.substr(0, 4) + shift;
    return result;
}

void Processor::step(){
    // Get PC from program counter
    long pc = programCounter.get();

    programCounter.toString();
    // Pass PC to instruction memory
    instructionMemory.setAddress(pc);

    instructionMemory.toString();
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
    std::cout << "regdst is: " << dec << control.getRegDst() << std::endl;
    // Pass the result of mux1 to write register
    registerFile.setWriteRegister(multiplexer1.get());
    registerFile.toString();

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

    std::cout << "ALU output: " << alu3.getResult() << std::endl;

    // Pass the result of ALU3 to DataMemory address
    dataMemory.setAddr(alu3.getResult());
    // Pass ReadData2 to DataMemory Write data
    dataMemory.setWriteData(registerFile.getData2());
    // Pass MemRead control bits to DataMemory
    dataMemory.setMemRead(control.getMemRead());
    // Pass MemWrite control bits to DataMemory
    dataMemory.setMemWrite(control.getMemWrite());

    dataMemory.toString();
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
    // Set choices of mux4 to output of alu1 and alu2
    multiplexer4.setChoices(alu1.getResult(), alu2.getResult());
    // Set control of mux4 to (branch AND zero) flags
    multiplexer4.setControl(control.getBranch() && alu3.getZeroFlag());
    // Set choices of mux5 to output of mux4 and shiftLeftTwo1
    multiplexer5.setChoices(multiplexer4.get(), concatenatePC(shiftLeftTwo1.get(), pc));
    // Set control of mux5 to jump flag
    multiplexer5.setControl(control.getJump());
    // Updates PC to output of mux5
    programCounter.set(multiplexer5.get());
}



