#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>

#define SIZE 4096

int main(int argc, char* argv[])
{
	printf("\nStarting parent %d\n", getpid());
	int i, j, mem = 0;

	int fd = shm_open("myshm", O_CREAT | O_RDWR, S_IRWXU);
	if (fd < 0) {
		perror(NULL);
		return errno;
	}

	// char fdString[256];
	// sprintf(fdString, "%d", fd);

	if (ftruncate(fd, SIZE * argc) == -1) {
		perror(NULL);
		return errno;
	}

	for (i = 1; i < argc; ++i) {
		char* position = (char*) malloc(2000);
		sprintf(position, "%d", mem);

		pid_t pid = fork();

		if (pid < 0) {
			perror(NULL);
			return errno;
		}

		else if (pid == 0) {
			char* args[] = {"function", argv[i], position, NULL};
			execve("function", args, NULL);
			perror(NULL);	
		}

		else {

			printf("Done Parent %d Me %d\n", getpid(), pid);
			void* myPtr = mmap(0, SIZE, PROT_READ, MAP_SHARED, fd, mem);
			char data[SIZE];
			memcpy(data, myPtr, SIZE);

			printf("\n%s\n", data);
			// char* args[] = {"get", position, NULL};
			// execve("get", args, NULL);
			// perror(NULL);
		}

		mem += SIZE;
	}

	return 0;
}
