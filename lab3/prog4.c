//pid_t pid
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
	pid_t pid;
	pid = fork();

	if (pid == 0) {
		int i;
		for (i = 0; i < 1e7; i++)
			printf("%d ", i);
		printf("\n");
		exit(0);
	} else {
		int status;
		int child_pid = wait(&status);
		printf("Process %d exited with status %d\n", child_pid, status);
		// wait() returns -1 O_o
	}
}
