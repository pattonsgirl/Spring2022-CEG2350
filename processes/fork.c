#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main ()
{
	printf("Before forking\n");
	fork();
	printf("After forking\n");
}
