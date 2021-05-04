#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define M_PI 3.14159265358979324

void fact_(long double *fact, int i) {
	if (i <= 1)
		return;

	*fact /= i;
	fact_(fact, i-1);
}

int Rec(const long double *x, const long double *sisus, const long double *e,
		 long double *sum) {

	static int counter = 0, here = 1;
	int i;
	long double fact = 1;

	counter++;
	fact_(&fact, 2*counter-1);
	*sum += powf(-1, counter-1) * powl(*x, 2*counter-1) * fact;

	if (fabsl(*sisus - *sum) > *e) {
		here++;
		sum += Rec(x, sisus, e, sum);
	}
	here--;

	if (!here) {
		printf("sin(x) = %.18Lf\n", *sisus);
		printf("Operations number: %d\n", counter);
	}

}

void Iter(const long double *x, const long double *sisus, const long double *e,
		 long double *sum) {

	int i, counter = 0;
	long double fact = 1;
    do {
		counter++;
		fact = 1;
		for (i = 2; i<=2*counter-1; i++) {
			fact /= i;
		}
		*sum += powf(-1, counter-1) * powl(*x, 2*counter-1) * fact;

	} while (fabsl(*sisus - *sum) > *e);

	printf("sin(x) = %.18Lf\n", *sisus);
	printf("Operations number: %d\n", counter);
}

int main()
{
	long double x, e, sisus, fact, sum_rec = 0, sum_iter = 0;
	int counter, i;

	puts("Enter x (degree):");
	scanf("%Lf", &x);
	puts("Enter e > 0:");
	scanf("%Lf", &e);

	x = x / 180 * M_PI;

	sisus = sinl(x);

	Rec(&x, &sisus, &e, &sum_rec);

	Iter(&x, &sisus, &e, &sum_iter);

	getchar();
	getchar();
	return 0;
}
