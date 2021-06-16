#include <stdio.h>
#include <locale.h>
#include <string.h>
#include<time.h>
#include<stdlib.h>
void ones(int **A)
{
	const int N = 12;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			A[i][j] = 9;

		}
	}
	int m, n, dir;
	int tr = 1;
	for (int i = 0; i < 4; i++)
	{
		tr = 1;
		while (tr) {

			m = rand() % 10 + 1;
			n = rand() % 10 + 1;
			if (A[m][n] == 0 || A[m][n] == 1)
			{
				tr = 1;
			}
			else {
				A[m][n - 1] = 0;
				A[m][n + 1] = 0;
				A[m - 1][n - 1] = 0;
				A[m - 1][n] = 0;
				A[m - 1][n + 1] = 0;
				A[m + 1][n - 1] = 0;
				A[m + 1][n] = 0;
				A[m + 1][n + 1] = 0;
				A[m][n] = 1;
				tr = 0;
			}
		}
	}
}
void twos(int **A)
{
	int m, n, dir;
	int tr = 1;
	for (int i = 0; i < 3; i++)
	{
		tr = 1;
		while (tr) {
			m = rand() % 10 + 1;
			n = rand() % 10 + 1;

			if (A[m][n] == 0 || A[m][n] == 1 || A[m][n] == 2)
			{
				tr = 1;
				continue;

			}
			dir = rand() % 4;
			if (dir == 0)
			{
				if (n == 1 || A[m][n - 1] == 0)
				{
					tr = 1;
					continue;
				}
				else
				{
					A[m][n] = 2;
					A[m][n - 1] = 2;
					A[m - 1][n - 1] = 0;
					A[m + 1][n + 1] = 0;
					A[m - 1][n + 1] = 0;
					A[m + 1][n - 1] = 0;
					A[m - 1][n] = 0;
					A[m + 1][n] = 0;
					A[m][n + 1] = 0;
					A[m][n - 2] = 0;
					A[m - 1][n - 2] = 0;
					A[m + 1][n - 2] = 0;
					tr = 0;

				}
			}
			else if (dir == 1)
			{
				if (m == 1 || A[m - 1][n] == 0)
				{
					tr = 1;
					continue;
				}
				else
				{
					A[m][n] = 2;
					A[m - 1][n] = 2;
					A[m - 1][n - 1] = 0;
					A[m + 1][n + 1] = 0;
					A[m - 1][n + 1] = 0;
					A[m + 1][n - 1] = 0;
					A[m + 1][n] = 0;
					A[m][n - 1] = 0;
					A[m][n + 1] = 0;
					A[m - 2][n] = 0;
					A[m - 2][n - 1] = 0;
					A[m - 2][n + 1] = 0;
					tr = 0;
				}
			}
			else if (dir == 2)
			{
				if (n == 10 || A[m][n + 1] == 0)
				{
					tr = 1;
					continue;
				}
				else
				{
					A[m][n + 1] = 2;
					A[m][n] = 2;
					A[m - 1][n - 1] = 0;
					A[m + 1][n + 1] = 0;
					A[m - 1][n + 1] = 0;
					A[m + 1][n - 1] = 0;
					A[m - 1][n] = 0;
					A[m + 1][n] = 0;
					A[m][n - 1] = 0;
					A[m - 1][n + 2] = 0;
					A[m][n + 2] = 0;
					A[m + 1][n + 2] = 0;
					tr = 0;
				}
			}
			else if (dir == 3)
			{
				if (m == 10 || A[m + 1][n] == 0)
				{
					tr = 1;
					continue;
				}
				else
				{
					A[m][n] = 2;
					A[m + 1][n] = 2;
					A[m - 1][n - 1] = 0;
					A[m + 1][n + 1] = 0;
					A[m - 1][n + 1] = 0;
					A[m + 1][n - 1] = 0;
					A[m - 1][n] = 0;
					A[m][n - 1] = 0;
					A[m][n + 1] = 0;
					A[m + 2][n - 1] = 0;
					A[m + 2][n] = 0;
					A[m + 2][n + 1] = 0;
					tr = 0;
				}
			}
		}
	}
}
void threes(int **A)
{
	int m, n, dir;
	int tr = 1;
	for (int i = 0; i < 2; i++)
	{
		tr = 1;
		while (tr) {
			m = rand() % 10 + 1;
			n = rand() % 10 + 1;
			if (A[m][n] == 0 || A[m][n] == 1 || A[m][n] == 2 || A[m][n] == 3)
			{
				tr = 1;
				continue;

			}
			dir = rand() % 4;

			if (dir == 0)
			{
				if (n == 1 || n == 2 || A[m][n - 1] == 0 || A[m][n - 2] == 0)
				{
					tr = 1;
					continue;
				}
				else
				{
					A[m][n] = 3;
					A[m][n - 1] = 3;
					A[m][n - 2] = 3;
					A[m - 1][n - 1] = 0;
					A[m + 1][n + 1] = 0;
					A[m - 1][n + 1] = 0;
					A[m + 1][n - 1] = 0;
					A[m - 1][n] = 0;
					A[m + 1][n] = 0;
					A[m][n + 1] = 0;
					A[m - 1][n - 2] = 0;
					A[m + 1][n - 2] = 0;
					A[m + 1][n - 3] = 0;
					A[m][n - 3] = 0;
					A[m - 1][n - 3] = 0;
					tr = 0;

				}
			}
			else if (dir == 1)
			{
				if (m == 1 || m == 2 || A[m - 1][n] == 0 || A[m - 2][n] == 0)
				{
					tr = 1;
					continue;
				}
				else
				{
					A[m][n] = 3;
					A[m - 1][n] = 3;
					A[m - 2][n] = 3;
					A[m - 1][n - 1] = 0;
					A[m + 1][n + 1] = 0;
					A[m - 1][n + 1] = 0;
					A[m + 1][n - 1] = 0;
					A[m + 1][n] = 0;
					A[m][n - 1] = 0;
					A[m][n + 1] = 0;
					A[m - 2][n - 1] = 0;
					A[m - 2][n + 1] = 0;
					A[m - 3][n - 1] = 0;
					A[m - 3][n] = 0;
					A[m - 3][n + 1] = 0;
					tr = 0;
				}
			}
			else if (dir == 2)
			{
				if (n == 9 || n == 10 || A[m][n + 1] == 0 || A[m][n + 2] == 0)
				{
					tr = 1;
					continue;
				}
				else
				{
					A[m][n + 1] = 3;
					A[m][n] = 3;
					A[m][n + 2] = 3;
					A[m - 1][n - 1] = 0;
					A[m + 1][n + 1] = 0;
					A[m - 1][n + 1] = 0;
					A[m + 1][n - 1] = 0;
					A[m - 1][n] = 0;
					A[m + 1][n] = 0;
					A[m][n - 1] = 0;
					A[m - 1][n + 2] = 0;
					A[m + 1][n + 2] = 0;
					A[m + 1][n + 3] = 0;
					A[m][n + 3] = 0;
					A[m - 1][n + 3] = 0;
					tr = 0;
				}
			}
			else if (dir == 3)
			{
				if (m == 9 || m == 10 || A[m + 1][n] == 0 || A[m + 2][n] == 0)
				{
					tr = 1;
					continue;
				}
				else
				{
					A[m][n] = 3;
					A[m + 1][n] = 3;
					A[m + 2][n] = 3;
					A[m - 1][n - 1] = 0;
					A[m + 1][n + 1] = 0;
					A[m - 1][n + 1] = 0;
					A[m + 1][n - 1] = 0;
					A[m - 1][n] = 0;
					A[m][n - 1] = 0;
					A[m][n + 1] = 0;
					A[m + 2][n - 1] = 0;
					A[m + 3][n] = 0;
					A[m + 3][n - 1] = 0;
					A[m + 3][n + 1] = 0;
					A[m + 2][n + 1] = 0;
					tr = 0;
				}
			}
		}
	}
}
void fours(int **A)
{
	int m, n, dir;
	int tr = 0;
	for (int i = 0; i < 1; i++)
	{
		tr = 1;
		while (tr) {
			m = rand() % 10 + 1;
			n = rand() % 10 + 1;
			if (A[m][n] == 0 || A[m][n] == 1 || A[m][n] == 2 || A[m][n] == 3)
			{
				tr = 1;
				continue;

			}
			else
			{
				dir = rand() % 2;
				if (dir == 0)
				{
					if (n == 1 || n == 2 || n == 3 || A[m][n - 1] == 0 || A[m][n - 2] == 0 || A[m][n - 3] == 0)
					{
						tr = 1;
						continue;
					}
					else
					{
						A[m][n] = 4;
						A[m][n - 1] = 4;
						A[m][n - 2] = 4;
						A[m][n - 3] = 4;
						A[m - 1][n - 1] = 0;
						A[m + 1][n + 1] = 0;
						A[m - 1][n + 1] = 0;
						A[m + 1][n - 1] = 0;
						A[m - 1][n] = 0;
						A[m + 1][n] = 0;
						A[m][n + 1] = 0;
						A[m - 1][n - 2] = 0;
						A[m + 1][n - 2] = 0;
						A[m + 1][n - 3] = 0;
						A[m - 1][n - 3] = 0;
						A[m][n - 4] = 0;
						A[m - 1][n - 4] = 0;
						A[m + 1][n - 4] = 0;
						tr = 0;
					}
				}
				else if (dir == 1)
				{
					if (m == 1 || m == 2 || m == 3 || A[m - 1][n] == 0 || A[m - 2][n] == 0 || A[m - 3][n] == 0)
					{
						tr = 1;
						continue;
					}
					else
					{

						A[m][n] = 4;
						A[m - 1][n] = 4;
						A[m - 2][n] = 4;
						A[m - 3][n] = 4;
						A[m - 1][n - 1] = 0;
						A[m + 1][n + 1] = 0;
						A[m - 1][n + 1] = 0;
						A[m + 1][n - 1] = 0;
						A[m + 1][n] = 0;
						A[m][n - 1] = 0;
						A[m][n + 1] = 0;
						A[m - 2][n - 1] = 0;
						A[m - 2][n + 1] = 0;
						A[m - 3][n - 1] = 0;
						A[m - 3][n + 1] = 0;
						A[m - 4][n] = 0;
						A[m - 4][n - 1] = 0;
						A[m - 4][n + 1] = 0;
						tr = 0;
					}

				}
			}
		}
	}
}
void PrintMas(int **A)
{
	for (int i = 1; i < 11; i++)
	{
		for (int j = 1; j < 11; j++)
		{
			if (A[i][j] != 1 && A[i][j] != 0 && A[i][j] != 2 && A[i][j] != 3 && A[i][j] != 4)A[i][j] = 0;
			printf("%d   ", A[i][j]);
		}
		printf("\n\n");
	}
}
int main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	int k=1;
	const int N = 12;
	int** A = malloc(N * sizeof(int*));
	for (int i = 0; i < N; i++)
	{
		A[i] = malloc(N * sizeof(int));
	}
	while (k) {
		printf("Enter 1 to build sea fight!\n");
		printf("Enter 0 to quit\n");
		scanf_s("%d", &k);
		printf("\n");
		switch (k)
		{
			case 1:
				ones(A);
				twos(A);
				threes(A);
				fours(A);
				PrintMas(A);
				break;
			case 0:
				break;
				return 0;
			default:
				printf("Incorrect input!\n");
				break;
		}
	}
	for (int i = 0; i < N; i++)
	{
		free(A[i]);
	}
	free(A);
	system("pause");
	getch();
	return 0;
}