#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
	pid_t pid;
	pid = fork();

	if (pid == -1) {
		perror("Fork error\n");
		return -1;
	}
	if (pid == 0) {
		printf("Child message\n");
		printf("Pid: %d\n", getpid());
		printf("Ppid: %d\n", getppid());
		printf("Group pid: %d\n", getpgid(0));
		exit(0);
	} else {
		printf("Parent message\n");
		printf("Pid: %d\n", getpid());
		printf("Ppid: %d\n", getppid());
		printf("Group pid: %d\n", getpgid(0));
		printf("Exit status: %d\n", wait());
	}
	return 0;
}
