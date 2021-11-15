#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>


int main(int argc, char *argv[]) {

	int pipe_fd1[2] = {atoi(argv[0]), atoi(argv[1])};
	int pipe_fd2[2] = {atoi(argv[2]), atoi(argv[3])};
	printf("Child args: %d %d %d %d\n", pipe_fd1[0], pipe_fd1[1], pipe_fd2[0], pipe_fd2[1]);
	char buf1;
	int file1 = open("prog4_input", O_RDWR);
	while (read(file1, &buf1, 1))
		write(pipe_fd1[1], &buf1, 1);
	close(pipe_fd1[1]);

	close(pipe_fd2[1]);
	while (read(pipe_fd2[0], &buf1, 1))
		write(file1, &buf1, 1);
	
	return 0;
} 
