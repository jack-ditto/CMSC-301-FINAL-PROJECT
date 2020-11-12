CC = g++	# complier
LD = $(CC)	# command to link objects

EXECS = Main
OBJS = Main.o ConfigParser.o ASMParser.o Instruction.o Opcode.o RegisterTable.o # all objects

INCDIR = -I ASMParser	# additional dirs to look

CCFLAGS = -Wall -std=c++17 $(INCDIR) -g -c	# compiler options
LDFLAGS = -Wall -std=c++17 -g			# linker options

Main: $(OBJS)
	$(LD) $(LDFLAGS) $(OBJS) -o Main
Main.o: Main.cpp ConfigParser.h
	$(CC) $(CCFLAGS) Main.cpp
ConfigParser.o: ConfigParser.cpp ConfigParser.h
	$(CC) $(CCFLAGS) ConfigParser.cpp
ASMParser.o: ASMParser.cpp ASMParser.h
	$(CC) $(CCFLAGS) ASMParser.cpp
Instruction.o: Instruction.cpp Instruction.h
	$(CC) $(CCFLAGS) Instruction.cpp
Opcode.o: Opcode.cpp Opcode.h
	$(CC) $(CCFLAGS) Opcode.cpp
RegisterTable.o: RegisterTable.cpp RegisterTable.h
	$(CC) $(CCFLAGS) RegisterTable.cpp
clean:
	/bin/rm -f $(OBJS) $(EXECS)