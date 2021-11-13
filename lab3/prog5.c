//pid_t pid
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
			printf("%d ", i);
		printf("\n");
		exit(9);
	} else {
		kill(pid, SIGUSR1);
		int status;
		int child_pid = wait(&status);
		printf("Process %d exited with status %d\n", child_pid, status);
		printf("Btw, %d is the code of %s\n", status, strsignal(status));
	}
}
