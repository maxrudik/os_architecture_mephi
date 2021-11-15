#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>


int main() {

	int pipe_fd[2];
	pipe(pipe_fd);
	
	pid_t pid;
	pid = fork();

	if (pid == 0) {
		char buf1;
		int file1 = open("prog2_input", O_RDWR);
		while (read(file1, &buf1, 1))
			write(pipe_fd[1], &buf1, 1);
		close(pipe_fd[1]);

	} else {
		char buf2;
		int file2 = open("prog2_output", O_RDWR);
		close(pipe_fd[1]);
		while (read(pipe_fd[0], &buf2, 1))
			write(file2, &buf2, 1);
	}
} 
