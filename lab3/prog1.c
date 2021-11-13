#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void trap1(int sig) {
	//signal() does not block default signal handler
	//printf("Ha-ha, can't touch me!\n");
	signal(SIGINT, SIG_DFL);
}

int main() {
	printf("%d is running\n", getpid());
	signal(SIGINT, trap1);
	while (1)
		sleep(1);
	return 0;
}
