#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void trap1(int sig) {
	int i;
	for (i = 0; i < 10; i++) {
		sleep(1);
		printf("Trap1 is working %d\n", i);
	}
	printf("Ha-ha, can't touch me!\n");
}

int main() {
	printf("%d is running\n", getpid());

	struct sigaction sigint_action;
	sigint_action.sa_handler = trap1;
	sigemptyset(&sigint_action.sa_mask);
	// blocks SIGALRM while trap1 executes
	sigaddset(&sigint_action.sa_mask, SIGALRM);
	alarm(3);
	sigaction(SIGINT, &sigint_action, NULL);
	while (1) {
		sleep(1);
	}
	return 0;
}
