#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main() {
	pid_t pid;
	pid = fork();

	if (pid == 0) {
		int i;
		for (i = 0; i < 1e7; i++)
			pause();

		exit(0);
	} else {
		kill(pid, SIGUSR1);
		// same effect with simple
		int status;
		int child_pid = wait(&status);
		printf("Process %d exited with status %d\n", child_pid, status);
		printf("Btw, %d is the code of %s\n", status, strsignal(status));
	}
}
