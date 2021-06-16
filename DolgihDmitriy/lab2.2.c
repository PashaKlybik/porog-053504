#include <locale.h>
#include <stdio.h>
#include <math.h>


double recursion(double x, double value, double e, double* n)
{
	double cur = (pow(-1, (*n) - 1) * (pow(x, 2 * (*n) - 1) / factorial(2 * (*n) - 1)));
	value += cur;
	(*n)++;
	if (fabs(cur) < e)
	{
		return value;
	}
	return recursion(x, value, e, n);
}


double factorial(double num)
{
	double n = 1;
	while (num > 1)
	{
		n *= num--;
	}
	return n;
}


int main()
{
	setlocale(0, "rus");
	double e;

	printf("¬ведите погрешность: ");
	scanf_s("%lf", &e);
	double res = 0;
	double x, sum = 0;
	do
	{
		printf("\n¬ведите x: ");
		scanf_s("%lf", &x);
		double n = 1;
		do
		{
			sum = (pow(-1, n - 1) * (pow(x, 2 * n - 1) / factorial(2 * n - 1)));
			res += sum;
			n++;
		} while (fabs(sum) > e);
		sum = 0;
		printf("sin(x) = %.10lf  %.10lf при n = %.0lf\n", sin(x), res, n - 1);
		n = 1;
		res = recursion(x, sum, e, &n);
		printf("–екурсивный метод %.10lf при n = %.0lf", res, n - 1);
	} while (1);
}