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
		sleep(5);
		printf("Parent pid after sleep: %d\n", getppid());
		exit(0);
	} else {
		printf("Real parent pid: %d\n", getpid());
		exit(0);
		// normal case: wait();
	}
	return 0;
}
