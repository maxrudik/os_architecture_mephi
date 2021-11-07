#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>

void copy_full() {
	char buf;
	while (read(0, &buf, 1)) {
		write(1, &buf, 1);
	}
}

int main(int argc, char *argv[]) {
	if (argc != 1 && argc != 3) {
		printf("Error: Ivalid args number\n");
		return -1;
	}
	int file1, file2;
	if (argc == 3) {
		file1 = open(argv[1], O_RDWR);
		file2 = open(argv[2], O_RDWR | O_TRUNC | O_CREAT, 0666);
		if (file1 < 0 || file2 < 0) {
			perror("Open error");
			return -1;
		}
		dup2(file1, 0);
		dup2(file2, 1);
	}	
	copy_full();
	return 0;
}
