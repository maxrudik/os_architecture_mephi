#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Error: To few args\n");
		return -1;
	}
	int file = open(argv[1], O_RDONLY);
	if (file < 0) {
		perror("Open error");
		return -1;
	}
	int curr = lseek(file, -1, SEEK_END);
	char buf;
	while (curr >= 0) {
		read(file, &buf, 1);
		write(1, &buf, 1);
		curr = curr - 1;
		lseek(file, curr, SEEK_SET);
	}
	return 0;
}
