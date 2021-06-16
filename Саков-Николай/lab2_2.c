#include <locale.h>
#include <stdio.h>
#include <math.h>

double fact(double num)
{
	double n = 1;
	while (num > 1)
	{
		n *= num--;
	}
	return n;
}

double recursion(double x, double value, double precision, double *n)
{
	double cur = (pow(-1, (*n) - 1) * (pow(x, 2 * (*n) - 1) / fact(2 * (*n) - 1)));
	value += cur;
	(*n)++;
	if (fabs(cur) < precision)
	{
		return value;
	}
	return recursion(x, value, precision, n);
}

int main()
{	
	setlocale(0, "rus");
	double eps;
	printf("Введите погрешность: ");
	scanf_s("%lf", &eps);
	double result = 0;
	double x, exp = 0;
	do
	{
		printf("\nВведите x: ");
		scanf_s("%lf", &x);
		double n = 1; 
		do
		{
			exp = (pow(-1, n - 1) * (pow(x, 2 * n - 1) / fact(2 * n - 1)));
			result += exp;
			n++;
		} while (fabs(exp) > eps);
		exp = 0;
		printf("sin(x) = %.10lf  %.10lf при n = %.0lf\n", sin(x), result, n - 1);
		n = 1;
		result = recursion(x, exp, eps, &n);
		printf("Рекурсивный метод %.10lf при n = %.0lf", result, n - 1);
	} while (1);
}