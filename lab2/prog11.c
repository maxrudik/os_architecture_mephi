#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	char args[] = "ls";
	int i;
	char space[] = " ";
	for (i = 1; i < argc; i++) {
		strcat(args, space);
		strcat(args, argv[i]);
	}
	
	system(args);
	return 0;
}
