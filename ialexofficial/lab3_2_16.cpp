#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int** readArray(int m, int n) {
	int** arr = malloc(sizeof(int*) * m);
	for (int i = 0; i < m; i++)
	{
		arr[i] = malloc(sizeof(int) * n);
		int j = 0;
		while(j < n)
		{
			scanf("%d", &arr[i][j]);
			if (arr[i][j] != 0 && arr[i][j] != 1)
				printf("Must be 0 or 1");
			else
				j++;
		}
	}
	return arr;
}
void clearArray(int** arr, int m, int n) {
	for (int i = 0; i < m; i++)
	{
		free(arr[i]);
	}
	free(arr);
}

int main()
{
	int n, m;
	printf("Size m x n: ");
	do {
		printf("Must be higher then 4\n");
		scanf(" %d %d", &m, &n);
	} while (n < 5 || m < 5);
	printf("Array of 0 and 1: ");
	int** arr = readArray(m, n);
	for (int i = 0; i < m; i++)
	{
		int count = 0;
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1)
				count++;
			else
				count = 0;
			if (count == 5) {
				printf("Won");
				clearArray(arr, m, n);
				return 0;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		int count = 0;
		for (int j = 0; j < m; j++) {
			if (arr[j][i] == 1)
				count++;
			else
				count = 0;
			if (count == 5) {
				printf("Won");
				clearArray(arr, m, n);
				return 0;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		int count = 0;
		for (int j = 0, k = i; j < m && k < n; j++, k++) {
			if (arr[j][k] == 1)
				count++;
			else
				count = 0;
			if (count == 5) {
				printf("Won");
				clearArray(arr, m, n);
				return 0;
			}
		}
		count = 0;
		for (int j = i, k = 0; j < m && k < n; j++, k++) {
			if (arr[j][k] == 1)
				count++;
			else
				count = 0;
			if (count == 5) {
				printf("Won");
				clearArray(arr, m, n);
				return 0;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		int count = 0;
		for (int j = 0, k = n - i - 1; j < m && k >= 0; j++, k--) {
			if (arr[k][j] == 1)
				count++;
			else
				count = 0;
			if (count == 5) {
				printf("Won");
				clearArray(arr, m, n);
				return 0;
			}
		}
		count = 0;
		for (int j = i, k = n - 1; j < m && k >= 0; j++, k--) {
			if (arr[j][k] == 1)
				count++;
			else
				count = 0;
			if (count == 5) {
				printf("Won");
				clearArray(arr, m, n);
				return 0;
			}
		}
	}
	/*
	1 0 0 0 0
	1 1 0 1 0
	0 1 1 0 0
	1 1 0 0 0
	1 0 0 0 1
	1 0 0 0 0
	*/
	printf("Didn't win");
	clearArray(arr, m, n);
	return 0;
}