#include "matrix.h"
void OutputMatrix(Matrix matrix,int n) 
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{

			printf("%.0f   ", matrix.string[i].column[j]);
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
int MatrixDet(Matrix matrix, int n)
{
	double koef = 0;
	double Det = 1;
	int y = 2;
	int y1 = 2;
	for (int i = 0; i < (n-1); i++)
	{
		y--;
		while (y < n)
		{
			koef = matrix.string[y].column[i] / matrix.string[i].column[i];
			for (int j = 0; j < n; j++)
			{
				matrix.string[y].column[j] -= (matrix.string[i].column[j] * koef);
			}
			y++;
		}
		y1++;
		y = y1;
	}
	for (int i = 0; i < n; i++)
	{
		Det *= matrix.string[i].column[i];
	}
	return Det;
}