CC = g++	# complier
LD = $(CC)	# command to link objects

EXECS = Main
OBJS = Main.o ConfigParser.o # all objects

INCDIR = -I ASMParser	# additional dirs to look

CCFLAGS = -Wall -std=c++17 $(INCDIR) -g -c	# compiler options
LDFLAGS = -Wall -std=c++17 -g			# linker options

Main: $(OBJS)
	$(LD) $(LDFLAGS) $(OBJS) -o Main
Main.o: Main.cpp ConfigParser.h
	$(CC) $(CCFLAGS) Main.cpp
ConfigParser.o: ConfigParser.cpp ConfigParser.h
	$(CC) $(CCFLAGS) ConfigParser.cpp
clean:
	/bin/rm -f $(OBJS) $(EXECS)