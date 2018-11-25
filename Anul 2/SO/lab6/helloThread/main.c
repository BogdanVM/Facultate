#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

void* hello(void* v)
{
	char* arg = (char*) v;
	char* myString = (char*) malloc(strlen(arg));

	int i, nr = 0;
	for (i = strlen(arg) - 1; i >= 0; --i) {
		myString[nr++] = arg[i];
	}

	return myString;
}

int main(int argc, char* argv[])
{
	pthread_t myThread;
	if (pthread_create(&myThread, NULL, hello, argv[1])) {
		perror(NULL);
		return errno;
	}

	void* result = NULL;
	if (pthread_join(myThread, &result)) {
		perror(NULL);
		return errno;
	}

	printf("\n%s\n\n", (char*)result);
	return 0;
}
