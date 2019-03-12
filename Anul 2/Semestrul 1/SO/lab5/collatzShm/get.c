#include <stdio.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 4096

int main(int argc, char* argv[])
{   
    int mem = atoi(argv[1]);
    int myFd = shm_open("myshm", O_RDONLY, S_IRWXU );

    if (myFd < 0) {
		perror("File Get");
		return errno;
	}

    void* shmPtr = mmap(NULL, SIZE, PROT_READ, MAP_SHARED, myFd, mem);
    if (shmPtr == MAP_FAILED) {
        perror("whatever2");
        return errno;
    }

    void* data = malloc(SIZE + 1);
    memcpy(data, shmPtr, SIZE);

    printf("%s\n", (char*)data);
    return 0;
}