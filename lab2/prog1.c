#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
	char *first_var = "VAR1=hello";
	char *second_var = "VAR2=world";
	char *new_env[] = {first_var, second_var, NULL};
	execle("exec_prog1", NULL, new_env);
	return 0;
}
