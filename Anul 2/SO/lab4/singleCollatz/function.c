#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int n = atoi(argv[1]);
	printf("\n%d: %d ", n, n);

	while (n >= 2) {
		if (n % 2 == 0) {
			n /= 2;
			printf("%d ", n);
		}

		else {
			n = 3 * n + 1;
			printf("%d ", n);
		}
	}

	printf("\n");
	return 0;
}
