#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

void printInput(int** input, int width, int height) //Вывод массива
{
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++)
			cout << input[i][j] << " ";
		printf("\n");
	}
	printf("\n");
}

int main()
{
	int n;
	printf("Input number of cols: \n");
	scanf("%d", &n);
	printf("\n");
	srand(time(0));

	int **input = (int**)malloc(n * sizeof(int*)); // Выделение памяти и заполнение случайными числами
	for (int i = 0; i < n; i++)
	{
		input[i] = (int*)malloc(n * sizeof(int));
		for (int j = 0; j < n; j++)
		{
			input[i][j] = rand() % 10;
		}
	}

	printf("Source array: \n");
	printInput(input, n, n - 1);

	int iOfMax = 0;
	int currMax = 0;
	for (int i = 0; i < n - 1; i++) //Поиск наибольшего элемента
	{
		for (int j = 0; j < n; j++)
		{
			if (currMax < input[i][j])
			{
				currMax = input[i][j];
				iOfMax = i;
			}
		}
	}

	for (int i = n - 2; i > iOfMax; i--)
	{
		for (int j = 0; j < n; j++)
		{
			input[i + 1][j] = input[i][j];
		}
	}

	for (int i = 0; i < n; i++) //Заполнение строки нулями
	{
		input[iOfMax + 1][i] = 0;
	}
	
	printf("Source array with a string of zeros: \n");
	printInput(input, n, n);

	int** main = (int**)malloc(n * sizeof(int*)); //Выделение памяти и отображение элементов массива относительно главной диагонали
	for (int i = 0; i < n; i++)
	{
		main[i] = (int*)malloc(n * sizeof(int));
		for (int j = 0; j < n; j++)
		{
			main[i][j] = input[j][i];
		}
	}

	printf("Mirror output relative to the main diagonal: \n");
	printInput(main, n, n);

	int** extra = (int**)malloc(n * sizeof(int*)); //Выделение памяти и отображение элементов массива относительно побочной диагонали
	for (int i = 0; i < n; i++)
	{
		extra[i] = (int*)malloc(n * sizeof(int));
		for (int j = 0; j < n; j++)
		{
			extra[i][j] = input[n - j - 1][n - i - 1];
		}
	}

	printf("Mirror output relative to the side diagonal: \n");
	printInput(extra, n, n);

	//Очищение памяти

	for (int i = 0; i < n; i++)
		free(input[i]);
	free(input);

	for (int i = 0; i < n; i++)
		free(extra[i]);   
	free(extra);

	for (int i = 0; i < n; i++)
		free(main[i]);
	free(main);

	return 0;
}