#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

int main()
{
	int m, n;
	int counter = 0;
	int temp = 0;

	printf("enter size (MxN)\nenter M: ");
	scanf_s("%d", &m); printf("enter N: ");
	scanf_s("%d", &n); printf("\n");
	printf("1 = x, O = 0\n");
	m+=2; n+=2;
	int** Xor0 = (int**)malloc(m * sizeof(int*));; // инициализация массива
	for (int i = 0; i < m; i++)
	{
		Xor0[i] = (int*)malloc(n * sizeof(int));
	}
	m-=2; n-=2;
//---------------------------------------------------------------
	for (int i = 0; i < m; i++)
	{
		for (int i = 0; i < n; i++)
		{
			printf("------");
		}
		printf("\n|");
		for (int j = 0; j < n; j++)
		{
			printf(" %d;%d |", i + 1, j + 1);

		}
		printf("\n");
		for (int i = 0; i < n; i++)
		{
			printf("------");
		}
		printf("\n");
	}
	printf("\n");
//---------------------------------------------------------------
	// заполняю 1 & 0
		for (int i = 0; i < m; i++)
		{
			for (int i = 0; i < n; i++)
			{
				printf("------");
			}
			printf("\n|");
			for (int j = 0; j < n; j++)
			{
				printf(" %d;%d |", i + 1, j + 1);
			}
			printf(" ---> ");
			for (int j = 0; j < n; j++)
			{
				scanf_s("%d", &Xor0[i][j]); 
			}
			for (int i = 0; i < n; i++)
			{
				printf("------");
			}
			printf("\n");
		}
		printf("\n");
//---------------------------------------------------------------
		//добавил по краям массива 0, чтобы при 
		// проверке не упиралось в мусор
		m++; n++;
		int dop;
		dop = m - 1;
		while (dop != 0)
		{
			Xor0[dop][n] = 0;
			dop--;
		}
		
		dop = n - 1;
		while (dop != 0)
		{
			Xor0[m][dop] = 0;
			dop--;
		}
		m--; n--;	
//---------------------------------------------------------------
		//Вывод таблицой поле(массив)
		system("cls");
		for (int i = 0; i < m; i++)
		{
			printf("-");
			for (int i = 0; i < n; i++)
			{
				printf("----");
			}
			printf("\n| ");
			for (int j = 0; j < n; j++)
			{
				printf("%d | ", Xor0[i][j]);
			}
			printf("\n");
			for (int i = 0; i < n; i++)
			{
				printf("----");
			}
			printf("-\n");
		}
		printf("\n");
//---------------------------------------------------------------	
	//Проверим горизонталь
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (Xor0[i][j] == 1)
				{
					temp = j;
					while (Xor0[i][temp] > 0 && counter != 5)
					{
						counter++;
						temp++;
					}
					if (counter == 5)
					{
						printf("X win!!!(hor)");
						return 0;
					}
					else counter = 0;
				}
			}
		}
//---------------------------------------------------------------
	//Проверим вертикаль
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (Xor0[i][j] == 1)
				{
					temp = i;
					while (Xor0[temp][j] > 0 && counter != 5)
					{
						temp++;
						counter++;
					}
					if (counter == 5)
					{
						printf("X win!!!(ver)");
						return 0;
					}
					else counter = 0;
				}
			}
		}
//---------------------------------------------------------------
		int temp2 = 0;
	//Проверим главную диагональ
		for (int i = 0, j = 0; i < m && j < n; j++, i++)
		{
				if (Xor0[i][j] == 1)
				{
					temp = i;
					temp2 = j;
					while (Xor0[temp][temp2] > 0 && counter != 5)
					{
						temp++;
						temp2--;
						counter++;
					}
					if (counter == 5)
					{
						printf("X win!!!(gl.d.)");
						return 0;
					}
					else counter = 0;
				}
		}
//---------------------------------------------------------------
	//Проверим побочную диагональ
		for (int i = 0, j = n - 1; i < m && j > 0; j--, i++)
		{
			if (Xor0[i][j] == 1)
			{
				temp = i;
				temp2 = j;
				while (Xor0[temp][temp2] > 0 && counter != 5)
				{
					temp++;
					temp2--;
					counter++;
				}
				if (counter == 5)
				{
					printf("X win!!!(pb.d.)");
					return 0;
				}
				else counter = 0;
			}
		}
//---------------------------------------------------------------
	for (int i = 0; i < m; i++)
	{
		free(Xor0[i]);
	}
	free(Xor0);

	getchar();
	return 0;
}