#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <pthread.h>
#include <unistd.h>

#define DIM_ROWS 3
#define DIM_COLS 3
#define DIM_AUX 2

int M1[DIM_ROWS][DIM_AUX] = { {1, 4}, {2, 5}, {3, 6} };
int M2[DIM_AUX][DIM_COLS] = { {8, 7, 6}, {5, 4, 3} };
int R[DIM_ROWS][DIM_COLS];

void* compute(void* v)
{
	int* params = (int*)v;
	
	int currentX = params[0];
	int currentY = params[1];

	int i, sum = 0;
	for (i = 0; i < DIM_AUX; ++i) {
		sum += M1[currentX][i] * M2[i][currentY];
	}

	R[currentX][currentY] = sum;
	pthread_exit(0);
}

void display()
{
	printf("\n");

	int i, j;
	for (i = 0; i < DIM_ROWS; ++i) {
		for (j = 0; j < DIM_COLS; ++j)
			printf("%d ", R[i][j]);
		printf("\n");
	}

	printf("\n");
}

int main(int argc, char* argv[])
{
	int i, j;
	for (i = 0; i < DIM_ROWS; ++i) {
		for (j = 0; j < DIM_COLS; ++j) {
			int* params = (int*) malloc(2 * sizeof(int));
			params[0] = i;
			params[1] = j;

			pthread_t thr;
			if (pthread_create(&thr, NULL, compute, params)) {
				perror(NULL);
				return errno;
			}

			if (pthread_join(thr, NULL)) {
				perror(NULL);
				return errno;
			}

			free(params);
		}
	}

	display();
	return 0;
}
