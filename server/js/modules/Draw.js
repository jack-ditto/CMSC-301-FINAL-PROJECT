// import $ from 'jquery'

class Draw {
  constructor() {
    //   Init canvas
    // this.canvas = document.getElementById('canvas');
    // this.canvas.width = window.innerWidth;
    // this.canvas.height = window.innerHeight;
    // this.ctx = canvas.getContext('2d');

    // // Draw PC
    // this.drawRectangle('black', 20, 400, 50, 100);
    // this.ctx.font = '20px Monospace';
    // // this.ctx.fillText('PC', 33, 455);
    // this.drawLineFromPcToInstructionMemory('black');

    // // Instruction Memory
    // this.drawRectangle('black', 150, 420, 100, 150);

    // this.drawLineFromPcOutToAlu('black');

    // this.drawAlu('black');
  }

  drawRectangle(color, xOffset, yOffset, width, height) {
    this.ctx.strokeStyle = color;
    this.ctx.beginPath();
    this.ctx.rect(xOffset, yOffset, width, height);
    this.ctx.stroke();
  }

  drawLineFromPcToInstructionMemory(color) {
    this.ctx.beginPath();
    this.ctx.moveTo(70, 450);
    this.ctx.lineTo(150, 450);
    this.ctx.strokeStyle = color;
    this.ctx.lineWidth = '3';
    this.ctx.stroke();
    this.ctx.lineWidth = '1';
  }

  drawLineFromPcOutToAlu(color) {
    this.ctx.beginPath();
    this.ctx.moveTo(100, 450);
    this.ctx.lineTo(100, 250);
    this.ctx.lineTo(200, 250);
    this.ctx.strokeStyle = color;
    this.ctx.lineWidth = '3';
    this.ctx.stroke();
    this.ctx.lineWidth = '1';
  }

  drawAlu(color) {
    this.ctx.beginPath();
    this.ctx.moveTo(200, 180);
    this.ctx.lineTo(200, 220);
    // this.ctx.lineTo(200, 250);
    this.ctx.strokeStyle = color;
    // this.ctx.lineWidth = '3';
    this.ctx.stroke();
    // this.ctx.lineWidth = '1';
  }
}

export default Draw;
