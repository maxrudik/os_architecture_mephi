#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>


int main() {

	int pipe_fd1[2], pipe_fd2[2];
	pipe(pipe_fd1);
	pipe(pipe_fd2);
	
	pid_t pid;
	pid = fork();

	if (pid == 0) {
		char buf1;
		int file1 = open("prog3_input", O_RDWR);
		while (read(file1, &buf1, 1))
			write(pipe_fd1[1], &buf1, 1);
		close(pipe_fd1[1]);

		close(pipe_fd2[1]);
		while (read(pipe_fd2[0], &buf1, 1))
			write(file1, &buf1, 1);

	} else {
		char buf2;
		int file2 = open("prog3_output", O_RDWR);
		close(pipe_fd1[1]);
		while (read(pipe_fd1[0], &buf2, 1))
			write(file2, &buf2, 1);

		char response[] = "Return message";
		write(pipe_fd2[1], response, strlen(response));
		close(pipe_fd2[1]);
	}
} 
