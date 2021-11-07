#include <sys/stat.h>
#include <string.h>
#include <stdio.h>

// symbol device:	/dev/ppp
// block device:	/dev/vda

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Error: To few arguments");
		return -1;
	}
	struct stat file_stat;
	if (stat(argv[1], &file_stat) < 0) {
		perror("Get stat error");
		return -1;
	}
	printf("File permissions: %d\n", file_stat.st_mode);
	printf("File uid: %d\n", file_stat.st_uid);
	printf("File gid: %d\n", file_stat.st_gid);
	printf("Access time: %d\n", file_stat.st_atim);
	printf("Modification time: %d\n", file_stat.st_mtim);
	printf("Status change time: %d\n", file_stat.st_mtim);
	return 0;
}
