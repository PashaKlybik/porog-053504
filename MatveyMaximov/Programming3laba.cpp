

//#include <iostream>
#include <stdio.h>
#include <stdlib.h>

void DeleteArray(int** arr, int a) {
	for (int i = 0; i < a; i++) {
		delete[] arr[i];
	}
	delete[] arr;
}

void Print(int** arr, int a) {
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < a; j++) {
			printf("%4.0d", arr[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	bool key = true;
	int n, k = 0;
	printf("Enter the size of the matrix :\n");
	scanf_s("%d", &n);
	int** arr = new int* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[n];
	}
	printf("fill the elements of the matrix : \n");
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			printf("a[%d][%d]=", i, j);
			scanf_s("%d", &arr[i][j]);
		}
	}

	printf("Stock matrix : \n");
	Print(arr, n);

	printf("Modefied matrix : \n");
	for (int i = 0; i < n - 1; ++i) {
		for (int k = i + 1; k < n; k++) {
			double multi = arr[k][i] / arr[i][i];
			for (int j = 0; j < n; j++) {
				double point = arr[k][j];
				double mulres = (multi * arr[i][j]);
				arr[k][j] = point - mulres;
			}
		}
		printf("\n");
	}
	Print(arr, n);
	printf("\n");

	int rang = 0;
	key = true;

	for (int i = 0; i < n; ++i){
		key = false;
		for(int j = 0; j < n; ++j){
			if (arr[i][j] != 0.0)
			{
				key = true;
			}
		}
		if (key)
		{
			rang++;
		}
	}

	printf("rang = %d", rang);
	printf("\n");
	return 0;
}
