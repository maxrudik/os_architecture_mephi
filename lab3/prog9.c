#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void trap(int sig) {
	int i;
	for (i = 0; i < 1e3; i++)
		printf("IT'S A TRAP\n");
}

int main() {
	pid_t pid;
	pid = fork();

	if (pid == 0) {
		signal(SIGALRM, SIG_DFL);
		perror("signal() error");
		// works withouc changing signal handler 
		// if handler is being set, does not execute
		alarm(1);
		int i;
		for (i = 0; i < 1e6; i++)
			printf("%d ", i);	

		exit(0);
	} else {
		//kill(pid, SIGUSR1);
		int status;
		int child_pid = wait(&status);
		printf("Process %d exited with status %d\n", child_pid, status);
		printf("Btw, %d is the code of %s\n", status, strsignal(status));
	}
}
