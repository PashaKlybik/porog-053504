#include <stdio.h>
#include<math.h>

long double Finding_fact(int n);
float Solution(float x, float eps, int n, float diff);

int main()
{
	float x, eps, diff = 0;
	int n = 1;
	float k = n - 1;
	float f = 2 * n - 1;

	printf("Enter eps: ");
	scanf_s("%f", &eps);
	printf("Enter x: ");
	scanf_s("%f", &x);

	printf("n= %f", Solution(x, eps, n, diff));

}

long double Finding_fact(int n) {
	if (n < 0)
		return 0;
	else if (n == 0)
		return 1;
	else
		return n * Finding_fact(n - 1);
}

float Solution(float x, float eps, int n, float diff) {
	float k = n - 1;
	float f = 2 * n - 1;

	diff += pow(-1, k) * pow(x, f) / Finding_fact(2 * n - 1);
	if (fabs(sin(x) - diff) < eps)
		return n;
	else
		return Solution(x, eps, n + 1, diff);

}