#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void trap(int sig) {
	printf("Trap executed\n");
}

int main() {
	pid_t pid;
	pid = fork();

	if (pid == 0) {
		// child process doesn't work at all
		printf("Child executes!\n");
		signal(SIGUSR1, trap);
		perror("signal() error");
		int i;
		for (i = 0; i < 1e7; i++)
			// do smtn

		exit(0);
	} else {
		kill(pid, SIGUSR1);
		int status;
		int child_pid = wait(&status);
		printf("Process %d exited with status %d\n", child_pid, status);
		printf("Btw, %d is the code of %s\n", status, strsignal(status));
	}
}
