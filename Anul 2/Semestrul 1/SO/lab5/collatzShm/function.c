#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <string.h>

#define SIZE 4096

int main(int argc, char* argv[])
{
	int n = atoi(argv[1]);
	int mem = atoi(argv[2]);
	int shmFd = shm_open("myshm", O_RDWR, S_IRWXU);

	if (shmFd < 0) {
		perror("File Function");
		return errno;
	}

	void* shmPtr = mmap(NULL, SIZE, PROT_WRITE, MAP_SHARED, shmFd, mem);
	if (shmPtr == MAP_FAILED) {
		perror("whatever1");
		return errno;
	}

	void* auxShmPtr = NULL;

	int nrElems = 1;
	while (n != 1) {
		if (n % 2 == 0) {
			n /= 2;
		}
		else { 
			n = 3 * n + 1;
		}

		sprintf(auxShmPtr, "%d", n);
		nrElems++;
		void* aux = realloc(auxShmPtr, nrElems * sizeof(int));
		auxShmPtr = aux;
		auxShmPtr += sizeof(int);
	}

	sprintf(auxShmPtr, "%d", n);
	memcpy(shmPtr, auxShmPtr, nrElems * 4);
	
	return 0;
}
