//  variant 5
#include <stdlib.h>
#include <conio.h>
#include <math.h>

int main()
{
	//finding numbers with monotonously changing digits
	int n, ncpy, i, j, domore;
	unsigned short count, a[9];

	printf("Enter anything from 1 to 2147483647\n");
	scanf("%d", &n);

	ncpy = n;

	if (n > 98765432)
		n = 98765432;

	puts("Goes down");
	i = 1;
	while (i <= n) {
		count = 0;
		j = i;
		do {
			a[count] = j % 10;
			j /= 10;
			count++;
		} while (j);

		domore = 0;
		for (j = count - 2; j >= 0; j--) {
			if (a[j] >= a[j+1]) {
				domore = j + 1;
				break;
			}
		}

		if (!domore) {
			printf("%d\n", i);
			i++;
		}
		else {
			i += (int)pow(10, domore-1) * (10 - a[j+1]);
		}
	}

	puts("Goes up");
	i = 1;
	while (i <= n) {
		count = 0;
		j = i;
		do {
			a[count] = j % 10;
			j /= 10;
			count++;
		} while (j);

		domore = 0;
		for (j = count - 2; j >= 0; j--) {
			if (a[j] <= a[j+1]) {
				domore = j + 1;
				break;
			}
		}

		if (!domore) {
			printf("%d\n", i);
			i++;
		}
		else {
			i += (int)pow(10, domore-1) * (a[j+1] - a[j] + 1);
		}
	}

	printf("That's all");
	getchar();
	getchar();
	return 0;
}
