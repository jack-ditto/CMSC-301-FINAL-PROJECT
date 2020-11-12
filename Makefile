CC = g++	# complier
LD = $(CC)	# command to link objects

EXECS = Main
OBJS = Main.o ConfigParser.o ASMParser.o Instruction.o Opcode.o RegisterTable.o ALU.o ALUControl.o Control.o DataMemory.o InstructionMemory.o Multiplexer.o Processor.o ProgramCounter.o RegisterFile.o ShiftLeftTwo.o SignExtend.o # all objects

INCDIR = -I ASMParser	# additional dirs to look

CCFLAGS = -Wall -std=c++17 $(INCDIR) -g -c	# compiler options
LDFLAGS = -Wall -std=c++17 -g			# linker options

Main: $(OBJS)
	$(LD) $(LDFLAGS) $(OBJS) -o Main
Main.o: Main.cpp ConfigParser.h Processor.h
	$(CC) $(CCFLAGS) Main.cpp
%.o: %.cpp *.h
	$(CC) $(CCFLAGS) $<
%.o: %.cpp
	$(CC) $(CCFLAGS) $<
clean:
	/bin/rm -f $(OBJS) $(EXECS)