# targets: pre-reqs
	# actions
# compile the program

default: hello-c.c
	gcc -Wall -o hello-by-makefile hello-c.c

go: hello-by-makefile
	./hello-by-makefile

# cleaning things up
clean: hello-by-makefile
	rm hello-by-makefile
