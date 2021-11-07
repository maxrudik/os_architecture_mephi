#include <fcntl.h>
#include <stdio.h>
#include <errno.h>

int main(int argc, char *argv[]) {
	if (argc == 1) {
		printf("Empty input\n");
		return 0;
	}
	int max_size = 0;
	char *filename;
	int i, cur_size, file;
	for (i = 1; i < argc; i++) {
		file = open(argv[i], O_RDONLY);
		cur_size = lseek(file, 0, SEEK_END);
		if (cur_size > max_size) {
			max_size = cur_size;
			filename = argv[i];
		}
	}
	printf("The largest file is %s: %d bytes\n", filename, max_size);
	return 0;
}
