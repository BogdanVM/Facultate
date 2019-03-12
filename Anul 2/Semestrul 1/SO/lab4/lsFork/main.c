#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
	pid_t pid = fork();

	if (pid < 0) {
		perror(NULL);
		return errno;
	}

	else if (pid == 0) {

		printf("\nParent PID = %d, Child PID = %d\n", getppid(), getpid());
		char* args[] = { "ls", NULL };
		execve("/bin/ls",  args, NULL);
		perror(NULL);
	}

	else {
		wait(NULL);
		printf("\nChild %d finished\n\n", pid);
	}

	return 0;
}
