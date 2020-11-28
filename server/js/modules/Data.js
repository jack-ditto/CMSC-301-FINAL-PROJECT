import $ from 'jquery'

class Data {

    constructor() {

        this.pcOutput = $('#pc-output');
        this.topLeftAluOutput = $('#top-left-alu-output');
        this.controlInput = $('#control-input');
        this.readRegisterOneInput = $('#read-register-1-input');
        this.readRegisterTwoInput = $('#read-register-2-input');
        this.writeRegisterInput = $('#write-register-input');
        this.signExtendInput = $('#sign-extend-input');
        this.topShiftLeftTwoInput = $('#top-shift-left-two-input');
        this.topShiftLeftTwoOutput = $('#top-shift-left-two-output');
        this.regDst = $('#reg-dst');
        this.jump = $('#jump');
        this.branch = $('#branch');
        this.memRead = $('#mem-read');
        this.memToReg = $('#mem-to-reg');
        this.aluOp = $('#alu-op');
        this.memWrite = $('#mem-write');
        this.aluSrc = $('#alu-src');
        this.regWrite = $('#reg-write');
        this.funcCode = $('#func-code');
        this.signExtendOutput = $('#sign-extend-output')
        this.bottomShiftLeftTwoOutput = $('#bottom-shift-left-two-output');
        this.writeData = $('#write-data');
        this.mainAluOutput = $('#main-alu-output');
        this.binaryInstruction = $('#binary-instruction');
        this.readDataOne = $('#read-data-1');
        this.readDataTwo = $('#read-data-2');
        this.aluControlOutput = $('#alu-control-output');
        this.zeroFlag = $('#zero-flag');
        this.mux5Output = $('#mux-5-output');
        this.instructionNum = $('#instruction-num');
        this.instructionString = $('#instruction-string');
        this.events();
    }

    events(){
        this.getData();
    }

    getData() {
        $.getJSON('http://127.0.0.1:5000/', (data) => {
            this.pcOutput.html(data.programCounter.get);
            this.topLeftAluOutput.html(data.alu1.result);
            this.controlInput.html(data.instructionMemory.getForControl);
            this.readRegisterOneInput.html(data.instructionMemory.getForRegOne);
            this.readRegisterTwoInput.html(data.instructionMemory.getForRegTwo);
            this.writeRegisterInput.html(data.instructionMemory.getForMuxOne);
            this.signExtendInput.html(data.instructionMemory.getForExtend);
            this.topShiftLeftTwoInput.html(data.instructionMemory.getForShift);
            this.topShiftLeftTwoOutput.html(data.shiftLeftTwo1.get);
            this.regDst.html(data.control.regDst);
            this.jump.html(data.control.jump);
            this.branch.html(data.control.branch);
            this.memRead.html(data.control.memRead);
            this.memToReg.html(data.control.memToReg);
            this.memWrite.html(data.control.memWrite);
            this.aluOp.html(data.control.aluOp);
            this.aluSrc.html(data.control.aluSrc);
            this.regWrite.html(data.control.regWrite);
            this.funcCode.html(data.aluControl.functionCode);
            this.signExtendOutput.html(data.signExtend.get);
            this.bottomShiftLeftTwoOutput.html(data.shiftLeftTwo2.get);
            this.writeData.html(data.dataMemory.data);
            this.mainAluOutput.html(data.alu3.result);
            this.binaryInstruction.html('Instruction: ' + data.instructionMemory.getInstruction)
            this.readDataOne.html('Read Data 1: ' + data.registerFile.data1);
            this.readDataTwo.html('Read Data 2: ' + data.registerFile.data2);
            this.aluControlOutput.html(data.aluControl.get);
            this.zeroFlag.html(data.alu3.zeroFlag);
            this.mux5Output.html(data.mux5.get);
            this.instructionNum.html(data.metaData.instructionNum);
            this.instructionString.html(data.metaData.instructionString);
        })
    }

    // Methods
}

export default Data;