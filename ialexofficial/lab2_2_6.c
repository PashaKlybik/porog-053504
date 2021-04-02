#define PI 3.14

#include <stdio.h>
#include <math.h>


unsigned long long fact(unsigned long long n)
{
	unsigned long long res = 1;
	while (n > 1)
	{
		res *= n--;
	}
	return res;
}

long double recursivesin(float x, long double precision, unsigned long long* n)
{
	long double res = (powl(-1, (*n) - 1) * powl(x, 2 * (*n) - 1) / fact(2 * (*n) - 1));
	if (fabs(res) <= precision)
		return 0;
	(*n)++;
	return (res + recursivesin(x, precision, n));
}

long double itersin(long double x, long double precision, unsigned long long *n)
{
	long double res = x;

	while (1) {
		float tmp = pow(-1, (*n)) * pow(x, 2 * (*n) + 1) / fact(2 * (*n) + 1);
		res += tmp;
		if (fabs(tmp) <= precision)
			break;
		(*n)++;
	}
	return res;
}

int main()
{
	char choice = 'y';
	long double precision, radian, rec_res, iter_res;
	unsigned long long finish, coef, numb, counter;
	int x;

	while (choice == 'y')
	{
		printf("Enter X: ");
		scanf(" %d", &x);

		printf("Enter precision: ");
		scanf(" %Lf", &precision);

		radian = x / 180.0 * PI;
		counter = 1;
		iter_res = itersin(radian, precision, &counter);

		printf("Taylor's formula(iterational): %.10Lf\n", iter_res);
		printf("Iterational sin: %llu\n\n", counter);

		counter = 1;
		rec_res = recursivesin(radian, precision, &counter);

		printf("Taylor's formula: %.10Lf\n ", rec_res);
		printf("Recursive sin: %llu\n\n", counter);

		printf("Do you want to continue?(Y/n)\n");
		scanf("\n%c", &choice);
	}
	return 0;
}