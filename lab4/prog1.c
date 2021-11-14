#include <unistd.h>
#include <stdio.h>

int main() {

	int pipe_fd1[2], pipe_fd2[2];
	pipe(pipe_fd1);
	pipe(pipe_fd2);
	int start = 0;
	write(pipe_fd2[1], &start, sizeof(int));
	
	pid_t pid;
	pid = fork();

	if (pid == 0) {
		int buf1, counter1 = 0;
		while (1) {
			read(pipe_fd2[0], &buf1, sizeof(int));
			if (buf1 == counter1) {
				printf("%d recieved: %d\n", getpid(), buf1);
				counter1++;
				write(pipe_fd1[1], &counter1, sizeof(int));
				counter1++;
			}
			sleep(1);
		}
	} else {
		int buf2, counter2 = 1;
		while (1) {
			read(pipe_fd1[0], &buf2, sizeof(int));
			if (buf2 == counter2) {
				printf("%d recieved: %d\n", getpid(), buf2);
				counter2++;
				write(pipe_fd2[1], &counter2, sizeof(int));
				counter2++;
			}
			sleep(1);
		}
	}
} 
