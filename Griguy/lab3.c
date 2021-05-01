//variant 12
#include <stdio.h>
#include <stdlib.h>

int main()
{                  //latin square of size n
	int n, i, j;
	int *arr;
	puts("Enter n > 0:");
	scanf("%d", &n);

	arr = (int*)calloc(n, sizeof(int));
	for (i = 0; i <= n-1; i++) {
		arr[i] = i + 1;
	}

	for (i = 1; i <= n; i++) {
		for (j = 0; j < n; j++) {
			printf("%3d", arr[j]++);
		}
		arr[n-i] -= n;
		putchar('\n');
	}

	free(arr);

	getchar();
	getchar();
	return 0;
}
