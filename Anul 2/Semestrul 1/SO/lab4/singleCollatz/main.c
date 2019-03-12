#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
	pid_t pid = fork();
	if (pid < 0) {
		perror(NULL);
		return errno;
	}

	else if (pid == 0) {
		char* args[] = {"function", argv[1], NULL };
		execve("function", args, NULL);
		perror(NULL);
	}

	else {
		wait(NULL);
		printf("\nChild %d finished\n\n", pid);
	}
}
