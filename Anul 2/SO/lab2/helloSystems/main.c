#include <unistd.h>
#include <errno.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
	if (write(1, "\nHelloWorld\n\n", 13) < 0) {
		perror(NULL);
		return errno;
	}

	return 0;
}
