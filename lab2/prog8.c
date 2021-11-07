#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main() {
	pid_t pid;
	pid = fork();
	int input_file = open("file", O_RDONLY);

	if (pid == -1) {
		perror("Fork error\n");
		return -1;
	}
	if (pid == 0) {
		int file1 = open("prog8_output1", O_RDWR | O_CREAT | O_TRUNC);
		char buf1;
		while (read(input_file, &buf1, 1))
			write(1, &buf1, 1);
			//write(file1, &buf1, 1);
		exit(1);
	} else {
		int file2 = open("prog8_output2", O_RDWR | O_CREAT | O_TRUNC);
		char buf2;
		while (read(input_file, &buf2, 1))
			write(1, &buf2, 1);
			//write(file2, &buf2, 1);
		wait();
	}
	return 0;
}
