#ifndef __MATRIX_H__
#define __MAREIX_H__
#include<time.h>
#include<windows.h>
#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<locale.h>
struct Column
{
	int* column;
};
typedef struct Column column;
struct catrix
{
	struct Column* string;
};
typedef struct catrix Matrix;
void OutputMatrix(Matrix matrix, int n);
void FreeAll(Matrix matrix, int n);
void GetMatr(Matrix matrix, Matrix matrixbuf, int i, int j, int n);
int Determinant(Matrix matrix, int n);
void MatrixFromFile(FILE *input,Matrix matrix, int n);
void RandomMatrix(Matrix matrix, int n);
#endif // __MATRIX_H__
