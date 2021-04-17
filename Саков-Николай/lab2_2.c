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

int main()
{	
	setlocale(0, "rus");
	double eps;
	printf("Введите погрешность: ");
	scanf_s("%lf", &eps);
	double result = 0;
	double x, exp = 0;
	printf("Введите x: ");
	scanf_s("%lf", &x);
	double n = 1; 
	do
	{
		exp = (pow(-1, n - 1) * (pow(x, 2 * n - 1) / fact(2 * n - 1)));
		result += exp;
		n++;
	} while (fabs(exp) > eps);
	printf("sin(x) = %lf  %lf при n = %lf", sin(x), result, n);
}