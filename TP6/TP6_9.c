#include <stdio.h>

#define N 4

void transponer(double mat[N][N]);
void printmat(double mat[N][N]);

int main(void)
{
	double mat[N][N] = {{ 1, 2, -2, 4},
						{ 3, 1, 6, -10},
						{ 10, 11, 342, 1.01},
						{ 1.5, 3, -1.1, 3}};
	
	printmat(mat);
	transponer(mat);
	printmat(mat);
	
	return 0;
}

void transponer(double mat[N][N])
{
	unsigned int fila, col;
	double mat_tr[N][N];
	for(fila = 0; fila < N; fila++)
	{
		for(col = 0; col < N; col++)
			mat_tr[col][fila] = mat[fila][col];
	}
	
	for(fila = 0; fila < N; fila++)
	{
		for(col = 0; col < N; col++)
			mat[fila][col] = mat_tr[fila][col];
	}
}

void printmat(double mat[N][N])
{
	unsigned int fila, col;
	for(fila = 0; fila < N; fila++)
	{
		for(col = 0; col < N; col++)
			printf("%6.2f |", mat[fila][col]);
		
		printf("\n");
	}
	printf("\n\n\n");
	
}
