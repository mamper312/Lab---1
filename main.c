#include "matrix.h"
int main() 
{
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));
	int n = 0;
	clock_t start, end;
	double Det = 0;
	int buffer = 0;
	FILE *input;
	Matrix matrix;
	int A = 0;
again:	printf("������ ������� -- 1\n������� ��������� -- 2\n������ � txt ����� -- 3\n");
	scanf_s("%d", &A);
	system("cls");
	if (A > 3 && A < 1)
		goto again;
	switch (A)
	{
	case 1:
		printf("������� ������ ������� n * n ::  ");
		scanf_s("%d\n", &n);
		matrix.string = (column*)malloc(sizeof(column) * n);
		for (int i = 0; i < n; i++)
		{
			matrix.string[i].column = (double*)malloc(sizeof(double) * n);
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				i++;
				j++;
				printf("������� ������� [  %d  ][  %d  ] === ", i, j);
				i--;
				j--;
				scanf_s("%lf", &matrix.string[i].column[j]);
			}
			printf("\n");
		}
		break;
	case 2:
		n = 5000 + rand() % 5;
		matrix.string = (column*)malloc(sizeof(column) * n);
		for (int i = 0; i < n; i++)
		{
			matrix.string[i].column = (double*)malloc(sizeof(double) * n);
		}
		RandomMatrix(matrix,n);
		break;
	case 3:
		fopen_s(&input, "C:\\Users\\mampe\\Desktop\\���� 1\\input.txt", "r+");
		if (input == NULL)
		{
			return 3;
		}
		fscanf_s(input, "%d", &n);
		matrix.string = (column*)malloc(sizeof(column) * n);
		for (int i = 0; i < n; i++)
		{
			matrix.string[i].column = (double*)malloc(sizeof(double) * n);
		}
		MatrixFromFile(input, matrix, n);
		break;
	}
   // OutputMatrix(matrix, n);
    start = clock();
	Det = MatrixDet(matrix,  n);
	end = clock();
	printf("==================================================================================\n");
  //  OutputMatrix(matrix, n);
	printf("\nDeterminant ===  %f\n", Det);
	printf("\n��� ���������� ������������ ������������ %.4f\n", ((end - start) / CLOCKS_PER_SEC) );
	FreeAll(matrix, n);
	system("pause");
	return 0;
}