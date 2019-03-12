#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main(int argc, char* argv[])
{
	int i;
	
	printf("\nStarting Parent %d\n", getpid());	
	for (i = 1; i < argc; ++i) {
		pid_t pid = fork();
		if (pid < 0) {
			perror(NULL);
			return errno;
		}

		else if (pid == 0) {
			char* args[] = {"function", argv[i], NULL};
			execve("./function", args, NULL);
			perror(NULL);
		}

		else {
			wait(NULL);
			printf("Done Parent %d Me %d\n", getpid(), pid);
		}
	}
	
	printf("\n");
	return 0;
}
