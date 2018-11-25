#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <fcntl.h>

#define KGRN "\x1B[32m"

int main(int argc, char* argv[])
{
	int fileDescriptor1 = open(argv[1], O_RDONLY);
	if (fileDescriptor1 < 0) {
		perror(NULL);
		return errno;
	}

	int fileDescriptor2 = open(argv[2], O_WRONLY|O_CREAT, S_IRWXU);
	if (fileDescriptor2 < 0) {
		perror(NULL);
		return errno;
	}
	
	char c;
	int nread = read(fileDescriptor1, &c, 1);

	while (nread) {
		if (nread < 0) {
			perror(NULL);
			return errno;
		}

		if (write(fileDescriptor2, &c, 1) < 0) {
			perror(NULL);
			return errno;
		}

		nread = read(fileDescriptor1, &c, 1);
	}
	
	return 0;
}
