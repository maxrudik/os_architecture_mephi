#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
	pid_t pid;
	pid = fork();
	int return_val;

	if (pid == -1) {
		perror("Fork error\n");
		return -1;
	}
	if (pid == 0) {
		printf("Child message\n");
		exit(return_val);
	} else {
		printf("Parent message\n");
		wait();
	}
	return 0;
}
