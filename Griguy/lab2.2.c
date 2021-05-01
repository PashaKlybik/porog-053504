#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	long double x, e, sisus, fact, sum = 0;
	int counter, i;

	puts("Enter x:");
	scanf("%Lf", &x);
	puts("Enter e > 0:");
	scanf("%Lf", &e);

	sisus = sinl(x);

	counter = 0;
	do {
		counter++;
		fact = 1;
		for (i = 2; i<=2*counter-1; i++) {
			fact /= i;
		}
		sum += powf(-1, counter-1) * powl(x, 2*counter-1) * fact;

	} while (fabsl(sisus - sum) > e);

	printf("sin(x) = %.18Lf\n", sisus);
	printf("Operations number: %d", counter);

	getchar();
	getchar();
	return 0;
}
