#include "matrix.h"
void OutputMatrix(Matrix matrix,int n) 
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{

			printf("%d   ", matrix.string[i].column[j]);
		}
		printf("\n");
	}
}
void RandomMatrix(Matrix matrix,int n)
{
	for (int i = 0; i < n; i++) 
	{ 
		for (int j = 0; j < n; j++) 
		{
			matrix.string[i].column[j] = (-15 + rand() % 30);
		}
	}
}
void MatrixFromFile(FILE *input, Matrix matrix, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			fscanf_s(input,"%lf",&matrix.string[i].column[j]);
		}
	}
}
void FreeAll(Matrix matrix, int n)
{
	for (int i = 0; i < n; i++)
	{
		free(matrix.string[i].column);
	}
	free(matrix.string);
}
void GetMatr(Matrix matrix, Matrix matrixbuf, int i, int j, int n)
{
	int di = 0, dj = 0;
	for (int ki = 0; ki < (n - 1); ki++) 
	{ 
		if (ki == i)
		{
			di = 1;
		}
		for (int kj = 0; kj < (n - 1); kj++)
		{ 
			if (kj == j)
			{
				dj = 1;
			}
			matrixbuf.string[ki].column[kj] = matrix.string[ki + di].column[kj + dj];
		}
	}
}

int Determinant(Matrix matrix, int n)
{
	int i = 0, j = 0, k = 1, m = n - 1;
	int Det = 0;
	Matrix matrixbuf;
	matrixbuf.string = (column*)malloc(sizeof(column) * n);
	for (int i = 0; i < n; i++)
	{
		matrixbuf.string[i].column = (int*)malloc(sizeof(int) * n);
	}
	if (n < 1)
	{
		printf("Невозможно посчитать");
	}
	if (n == 1) 
	{
		Det = matrix.string[0].column[0];
		return Det;
	} 
	if (n == 2)
	{
		Det = matrix.string[0].column[0] * matrix.string[1].column[1] - (matrix.string[1].column[0] * matrix.string[0].column[1]);
		return Det;
	}
	if (n > 2)
	{
		for (i; i < n; i++) 
		{
			GetMatr(matrix, matrixbuf, i, 0, n);
			Det = Det + k * matrix.string[i].column[0] * Determinant(matrixbuf, m);
			k = -k;
		}
		FreeAll(matrixbuf, n);
	}
	return Det;
}
