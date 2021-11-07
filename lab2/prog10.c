#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, char *argv[], char *envp[]) {
	pid_t pid;
	pid = fork();
	int input_file = open("file", O_RDONLY);

	if (pid == -1) {
		perror("Fork error\n");
		return -1;
	}
	if (pid == 0) {
		char *envp_arr[] = {"envp_1", "envp_2", NULL};
		execle("exec_prog10", "argv_1", "argv_2", NULL, envp_arr);
	} else {
		printf("Parent(%d) arguments\n", getpid());
		int i;
		for (i = 0; i < argc; i++)
			printf("argv[%d]: %s\n", i, argv[i]);
		i = 0;
		while (envp[i++])
			printf("envp[%d]: %s\n", i - 1, envp[i]);
		wait();
	}
	return 0;
}
