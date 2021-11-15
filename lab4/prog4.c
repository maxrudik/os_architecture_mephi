#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

int main() {

	int pipe_fd1[2], pipe_fd2[2];
	pipe(pipe_fd1);
	pipe(pipe_fd2);
	
	pid_t pid;
	pid = fork();
	if (pid == 0) {
		char argv_tosend1[5], argv_tosend2[5];
		char argv_tosend3[5], argv_tosend4[5];
		
		sprintf(argv_tosend1, "%d", pipe_fd1[0]);
		sprintf(argv_tosend2, "%d", pipe_fd1[1]);
		sprintf(argv_tosend3, "%d", pipe_fd2[0]);
		sprintf(argv_tosend4, "%d", pipe_fd2[1]);
		execl("exec_prog4",
			argv_tosend1,
			argv_tosend2,
			argv_tosend3,
			argv_tosend4,
			NULL);
	} else {
		char buf2;
		int file2 = open("prog4_output", O_RDWR);
		close(pipe_fd1[1]);
		while (read(pipe_fd1[0], &buf2, 1))
			write(file2, &buf2, 1);

		char response[] = "Return message";
		write(pipe_fd2[1], response, strlen(response));
		close(pipe_fd2[1]);
	}
} 
