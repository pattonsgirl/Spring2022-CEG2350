# constants
# specify compiler - what if different versions exist?  can specify which for this project
CC=gcc
# compiler flags
#	-I defines path where header file should be looked for (in current directory)
#	-Wall = warnings, all
CFLAGS= -I . -Wall
# List of header files
HFILES=header.h
# program name
PROGRAM=finale

# dependencies also define what make should check.  Checks source code changes, but header should be included
# rebuild object files if changes to c or h files
%.o: %.c $(HFILES)
	# $@ says output to %.o, which will take names gathered from list of .c files, which $< refers to
	$(CC) $(CFLAGS) -c -o $@ $< 

linkit: main.o morecode.o
	$(CC) -o $(PROGRAM) main.o morecode.o

runit: $(PROGRAM)
	./$(PROGRAM)
cleanit:
	rm $(PROGRAM) *.o
