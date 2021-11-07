#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[], char *envp[]) {

	printf("Child(%d) arguments\n", getpid());
	int i; 
	for (i = 0; i < argc; i++)
		printf("argv[%d]: %s\n", i, argv[i]);
	i = 0;
	while (envp[i++])
		printf("envp[%d]: %s\n", i - 1, envp[i]);
					
	return 0;	
}
