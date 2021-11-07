#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Too few args!\n");
		return 1;		
	}
	int file1 = open(argv[1], O_RDONLY);
	if (file1 < 0) {
		printf("Error from errno: %s\n", strerror(errno));
		//printf("Error from sys_errlist: %s\n", strerror(sys_errlist[sys_nerr - 1]));
		perror("Error from perror");
		return 1;
	}
	close(file1);
	return 0;
}
