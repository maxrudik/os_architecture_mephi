#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

// usage:
// ./prog5 & (background job)
// ps aux | grep -w Z

int main() {
	pid_t pid;
	pid = fork();

	if (pid == -1) {
		perror("Fork error\n");
		return -1;
	}
	if (pid == 0) {
		printf("%d exits (child)\n", getpid());
		exit(1);
	} else {
		printf("%d sleeps (parent)\n", getpid());
		sleep(100);
		printf("%d exits (parent)\n", getpid());
		exit(1);
	}
	return 0;
}
