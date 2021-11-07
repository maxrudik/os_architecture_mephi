#include <fcntl.h>
#include <stdio.h>
#include <string.h>

mode_t strtomode(const char *perm) {
	mode_t mode = 0;

	if (perm[0] == 'r')
		mode |= 0400;
	if (perm[1] == 'w')
		mode |= 0200;
	if (perm[2] == 'x')
		mode |= 0100;
	if (perm[3] == 'r')
		mode |= 0040;
	if (perm[4] == 'w')
		mode |= 0020;
	if (perm[5] == 'x')
		mode |= 0010;
	if (perm[6] == 'r')
		mode |= 0004;
	if (perm[7] == 'w')
		mode |= 0002;
	if (perm[8] == 'x')
		mode |= 0001;
	return mode;
}

int main(int argc, char *argv[]) {
	if (argc != 3) {
		printf("Error: To few args\n");
		return -1;
	}
	int file2 = open(argv[1], O_RDONLY | O_CREAT, strtomode(argv[2]));
	if (file2 < 0) {
		perror("First create error");
		return -1;
	}
	if (write(file2, "string1") < 0) {
		perror("Write error");
	}
	write(file2, "string2");
	close(file2);

	file2 = open(argv[1], O_RDONLY);
	if (file2 < 0) {
		perror("Second open error");
		return -1;
	}
	char *buf[7];
	read(file2, &buf, 7);
	printf("Data readed: %s\n", buf);
	close(file2);

	file2 = open(argv[1], O_RDWR);
	if (file2 < 0) {
		perror("Last open error");
		return -1;
	}
	close(file2);

	return 0;	
}
