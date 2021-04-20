#include <stdio.h>
#include <math.h>

long long int factor(int n);
int summa(int n, float x, float eps);

void main(void)
{
	int n = 0;
	float x, eps = 0.001;

	printf("Enter x: ");
	scanf_s("%f", &x);
	printf("sinx=%f\n", sin(x));
	printf("n=%d\n", summa(n, x, eps));
	
}
long long int factor(int n) {
	long int fact = 1;
	for (int i = 1; i <= n; i++)
		fact *= i;
	return fact;
}
int summa(int n, float x, float eps) {
	float summa = 0;
	int k, l;
	do {
		n++;
		k = 2 * n - 1; l = n - 1;
		summa += pow(x, k) * pow(-1, l) / factor(k);
	
	} while (fabs(sin(x) - summa) > eps);
	printf("summa=%f\n", summa);
	return n;
}