#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

// If parent dies, child lives
// Same thing like in 6 task
int main() {
	pid_t pid;
	pid = fork();

	if (pid == -1) {
		perror("Fork error\n");
		return -1;
	}
	if (pid == 0) {
		printf("%d (child) and %d (parent) are executing\n", getpid(), getppid());
		setpgrp();
		pause();
		exit(1);
	} else {
		pause();
		exit(1);
	}
	return 0;
}
