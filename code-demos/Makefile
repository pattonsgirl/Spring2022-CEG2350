# This is an example of a Makefile for Java in Linux
#       I recommend to compare this to the Makefile-C example given
#               since it has more thorough comments

# define java compiler & java program
#   Note: it would be better to do an absolute path to javac & java
JCC = javac
JV = java

# define compilation flag(s)
#   -g compiles with debugging information
JFLAGS = -g

# default action of my makefile (because this is first)
#       pre-req is that demo.java exists
default: Main.java
	$(JCC) $(JFLAGS) Main.java

# defining target (or command to be used with make) to run my program
execute: Main.class
	$(JV) Main

# defining target to delete my compiled program
delete: 
	rm Main.class
