#include "Processor.h"
#include <bitset>

Processor::Processor(map<long, vector<string>> instructionMap,
                     map<long, long> memoryMap, map<int, long> registerMap)
{
    // Create instances of all components
    instructionMemory = InstructionMemory(instructionMap);
    dataMemory = DataMemory(memoryMap);
    registerFile = RegisterFile(registerMap);
}

string concatenatePC(string shift, int pc)
{
    string programC = bitset<32>(pc).to_string();
    string result = programC.substr(0, 4) + shift;
    return result;
}

void Processor::step()
{
    // Get PC from program counter
    long pc = programCounter.get();

    programCounter.toString();
    // Pass PC to instruction memory
    instructionMemory.setAddress(pc);

    instructionMemory.toString();
    // passes bits 31-26 of the instruction into the control unit
    control.setInstruction(instructionMemory.getForControl());
    control.toString();
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
    registerFile.printMap();
    this->writeWebInterfaceJson();
}

void Processor::writeWebInterfaceJson()
{

    ofstream outfile;
    outfile.open("webInterfaceOutput.json");

    outfile << "{" << endl;

    outfile << "    \"programCounter\":" << endl;
    outfile << "        {" << endl;
    outfile << "            \"get\":\"" << this->programCounter.get() << "\"" << endl;
    outfile << "        }," << endl;

    outfile << "    \"instructionMemory\":" << endl;
    outfile << "        {" << endl;
    outfile << "            \"getInstruction\":\"" << this->instructionMemory.getInstruction() << "\"," << endl;
    outfile << "            \"getForControl\":\"" << this->instructionMemory.getForControl() << "\"," << endl;
    outfile << "            \"getForShift\":\"" << this->instructionMemory.getForShift() << "\"," << endl;
    outfile << "            \"getForExtend\":\"" << this->instructionMemory.getForExtend() << "\"," << endl;
    outfile << "            \"getForRegOne\":\"" << this->instructionMemory.getForRegOne() << "\"," << endl;
    outfile << "            \"getForRegTwo\":\"" << this->instructionMemory.getForRegTwo() << "\"," << endl;
    outfile << "            \"getForMuxOne\":\"" << this->instructionMemory.getForMuxOne() << "\"," << endl;
    outfile << "            \"getForALUControl\":\"" << this->instructionMemory.getForALUControl() << "\"" << endl;
    outfile << "        }," << endl;

    outfile << "    \"dataMemory\":" << endl;
    outfile << "        {" << endl;
    outfile << "            \"get\":\"" << this->dataMemory.get() << "\"," << endl;
    outfile << "            \"memRead\":\"" << this->dataMemory.getMemRead() << "\"," << endl;
    outfile << "            \"memWrite\":\"" << this->dataMemory.getMemWrite() << "\"," << endl;
    outfile << "            \"address\":\"" << this->dataMemory.getAddress() << "\"," << endl;
    outfile << "            \"data\":\"" << this->dataMemory.getData() << "\"" << endl;
    outfile << "        }," << endl;

    outfile << "    \"registerFile\":" << endl;
    outfile << "        {" << endl;
    outfile << "            \"data1\":\"" << this->registerFile.getData1() << "\"," << endl;
    outfile << "            \"data2\":\"" << this->registerFile.getData2() << "\"," << endl;
    outfile << "            \"writeData\":\"" << this->registerFile.getWriteData() << "\"" << endl;
    outfile << "        }," << endl;

    outfile << "    \"alu1\":" << endl;
    outfile << "        {" << endl;
    outfile << "            \"input1\":\"" << this->alu1.getInput1() << "\"," << endl;
    outfile << "            \"input2\":\"" << this->alu1.getInput2() << "\"," << endl;
    outfile << "            \"opNum\":\"" << this->alu1.getOpNum() << "\"," << endl;
    outfile << "            \"zeroFlag\":\"" << this->alu1.getZeroFlag() << "\"," << endl;
    outfile << "            \"result\":\"" << stol(this->alu1.getResult(), nullptr, 2) << "\"" << endl;
    outfile << "        }," << endl;

    outfile << "    \"alu2\":" << endl;
    outfile << "        {" << endl;
    outfile << "            \"input1\":\"" << this->alu2.getInput1() << "\"," << endl;
    outfile << "            \"input2\":\"" << this->alu2.getInput2() << "\"," << endl;
    outfile << "            \"opNum\":\"" << this->alu2.getOpNum() << "\"," << endl;
    outfile << "            \"zeroFlag\":\"" << this->alu2.getZeroFlag() << "\"," << endl;
    outfile << "            \"result\":\"" << this->alu2.getResult() << "\"" << endl;
    outfile << "        }," << endl;

    outfile << "    \"alu3\":" << endl;
    outfile << "        {" << endl;
    outfile << "            \"input1\":\"" << this->alu3.getInput1() << "\"," << endl;
    outfile << "            \"input2\":\"" << this->alu3.getInput2() << "\"," << endl;
    outfile << "            \"opNum\":\"" << this->alu3.getOpNum() << "\"," << endl;
    outfile << "            \"zeroFlag\":\"" << this->alu3.getZeroFlag() << "\"," << endl;
    outfile << "            \"result\":\"" << this->alu3.getResult() << "\"" << endl;
    outfile << "        }," << endl;

    outfile << "    \"mux1\":" << endl;
    outfile << "        {" << endl;
    outfile << "            \"choice1\":\"" << this->multiplexer1.getChoice1() << "\"," << endl;
    outfile << "            \"choice2\":\"" << this->multiplexer1.getChoice2() << "\"," << endl;
    outfile << "            \"control\":\"" << this->multiplexer1.getControl() << "\"," << endl;
    outfile << "            \"get\":\"" << this->multiplexer1.get() << "\"" << endl;
    outfile << "        }," << endl;

    outfile << "    \"mux2\":" << endl;
    outfile << "        {" << endl;
    outfile << "            \"choice1\":\"" << this->multiplexer2.getChoice1() << "\"," << endl;
    outfile << "            \"choice2\":\"" << this->multiplexer2.getChoice2() << "\"," << endl;
    outfile << "            \"control\":\"" << this->multiplexer2.getControl() << "\"," << endl;
    outfile << "            \"get\":\"" << this->multiplexer2.get() << "\"" << endl;
    outfile << "        }," << endl;

    outfile << "    \"mux3\":" << endl;
    outfile << "        {" << endl;
    outfile << "            \"choice1\":\"" << this->multiplexer3.getChoice1() << "\"," << endl;
    outfile << "            \"choice2\":\"" << this->multiplexer3.getChoice2() << "\"," << endl;
    outfile << "            \"control\":\"" << this->multiplexer3.getControl() << "\"," << endl;
    outfile << "            \"get\":\"" << this->multiplexer3.get() << "\"" << endl;
    outfile << "        }," << endl;

    outfile << "    \"mux4\":" << endl;
    outfile << "        {" << endl;
    outfile << "            \"choice1\":\"" << this->multiplexer4.getChoice1() << "\"," << endl;
    outfile << "            \"choice2\":\"" << this->multiplexer4.getChoice2() << "\"," << endl;
    outfile << "            \"control\":\"" << this->multiplexer4.getControl() << "\"," << endl;
    outfile << "            \"get\":\"" << this->multiplexer4.get() << "\"" << endl;
    outfile << "        }," << endl;

    outfile << "    \"mux5\":" << endl;
    outfile << "        {" << endl;
    outfile << "            \"choice1\":\"" << this->multiplexer5.getChoice1() << "\"," << endl;
    outfile << "            \"choice2\":\"" << this->multiplexer5.getChoice2() << "\"," << endl;
    outfile << "            \"control\":\"" << this->multiplexer5.getControl() << "\"," << endl;
    outfile << "            \"get\":\"" << this->multiplexer5.get() << "\"" << endl;
    outfile << "        }," << endl;

    outfile << "    \"shiftLeftTwo1\":" << endl;
    outfile << "        {" << endl;
    outfile << "            \"input\":\"" << this->shiftLeftTwo1.getInput() << "\"," << endl;
    outfile << "            \"get\":\"" << this->shiftLeftTwo1.get() << "\"" << endl;
    outfile << "        }," << endl;

    outfile << "    \"shiftLeftTwo2\":" << endl;
    outfile << "        {" << endl;
    outfile << "            \"input\":\"" << this->shiftLeftTwo2.getInput() << "\"," << endl;
    outfile << "            \"get\":\"" << this->shiftLeftTwo2.get() << "\"" << endl;
    outfile << "        }," << endl;

    outfile << "    \"control\":" << endl;
    outfile << "        {" << endl;
    outfile << "            \"regDst\":\"" << this->control.getRegDst() << "\"," << endl;
    outfile << "            \"jump\":\"" << this->control.getJump() << "\"," << endl;
    outfile << "            \"branch\":\"" << this->control.getBranch() << "\"," << endl;
    outfile << "            \"memWrite\":\"" << this->control.getMemWrite() << "\"," << endl;
    outfile << "            \"memRead\":\"" << this->control.getMemRead() << "\"," << endl;
    outfile << "            \"memToReg\":\"" << this->control.getMemToReg() << "\"," << endl;
    outfile << "            \"aluOp\":\"" << this->control.getAluOp() << "\"," << endl;
    outfile << "            \"aluSrc\":\"" << this->control.getAluSrc() << "\"," << endl;
    outfile << "            \"regWrite\":\"" << this->control.getRegWrite() << "\"" << endl;
    outfile << "        }," << endl;

    outfile << "    \"aluControl\":" << endl;
    outfile << "        {" << endl;
    outfile << "            \"get\":\"" << this->aluControl.get() << "\"," << endl;
    outfile << "            \"opCode\":\"" << this->aluControl.getOpCode() << "\"," << endl;
    outfile << "            \"functionCode\":\"" << this->aluControl.getFunctionCode() << "\"" << endl;
    outfile << "        }," << endl;

    outfile << "    \"signExtend\":" << endl;
    outfile << "        {" << endl;
    outfile << "            \"get\":\"" << this->signExtend.get() << "\"," << endl;
    outfile << "            \"input\":\"" << this->signExtend.getInput() << "\"" << endl;
    outfile << "        }" << endl;
    outfile << "}";
    outfile.close();
}
