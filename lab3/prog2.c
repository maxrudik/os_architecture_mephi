#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void trap1(int sig) {
	printf("Ha-ha, can't touch me!\n");
	// signal() makes second SIGINT behave normally
	signal(SIGINT, SIG_DFL);
}

int main() {
	printf("%d is running\n", getpid());

	struct sigaction sigint_action;
	sigint_action.sa_handler = trap1;
	sigemptyset(&sigint_action.sa_mask);

	sigaction(SIGINT, &sigint_action, NULL);
	while (1) {
		sleep(1);
	}
	return 0;
}
