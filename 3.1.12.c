#include <stdio.h>

void main(void) 
{
	int n;

	do  {
		printf("Enter positive  n: ");
		scanf_s("%d", &n);
		while (getchar() != '\n');
	} while (n <= 0 || n >= 61);
		int** sq = (int**)malloc(n * sizeof(int*));
		for (int i = 0; i < n; i++) {
			sq[i] = (int*)malloc(n * sizeof(int));
		}
		for (int i = 0; i < n; i++) {
			int a = i + 1;
			for (int j = 0; j < n; j++) {
				sq[i][j] = a;
				a++;
				if (a > n) a = 1;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printf("%d ", sq[i][j]);
			}
			printf("\n");
		}
		for (int i = 0; i < n; i++) {
			free(sq[i]);
		}
		free(sq);
	


}