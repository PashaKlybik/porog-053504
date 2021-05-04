#include <stdio.h>
#include <math.h>

double fact(double n);
double recursion(double x, double value, double precision, double *n);

int main()
{
	double e, x, result = 0, expression = 0, n = 1;
	printf("Enter e:\n");
	scanf("%lf", &e);
	printf("\nEnter x:\n");
	scanf("%lf", &x);
	do
	{
	    expression = (pow(-1, n - 1) * (pow(x, 2 * n - 1) / fact(2 * n - 1)));
	    result += expression;
	    n++;
	} while (fabs(expression) > e);
	expression = 0;
	printf("sin(x) = %.10lf\nResult = %.10lf\nn = %.0lf\n", sin(x), result, n - 1);
	n = 1;
	result = recursion(x, expression, e, &n);
	printf("Recursion method - %.10lf\nn = %.0lf", result, n - 1);
}

double fact(double n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return n * fact(n - 1);
    }
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
