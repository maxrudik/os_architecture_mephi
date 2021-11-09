#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>

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
		printf("Error: To few arguments\n");
		return -1;
	}
	int file3 = open(argv[1], O_RDWR | O_CREAT, strtomode(argv[2]));
	if (file3 < 0) {
		perror("First open error");
		return -1;
	}
	// using lseek to make a hole in sparse file
	lseek(file3, 100, SEEK_SET);
	char *buf1 = "aaaaaa";
	char *buf2 = "bbbbbb";
	char *buf3 = "cccccc";
	if (write(file3, buf1, 6) < 0)
		perror("First write error");
	lseek(file3, 103, SEEK_SET);
	if (write(file3, buf2, 6) < 0)
		perror("Second write error");
	lseek(file3, -3, SEEK_CUR);
	if (write(file3, buf3, 3) < 0)
		perror("Third write error");

	return 0;
}
