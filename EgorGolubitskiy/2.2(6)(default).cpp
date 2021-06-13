#include <stdio.h>
#include<math.h>

int Solution(double x, double eps);
long double Finding_fact(int n);

int main()
{
	float x, eps;

	printf("Enter eps: ");
	scanf_s("%f", &eps);
	printf("Enter x: ");
	scanf_s("%f", &x);

	printf("%d", Solution(x, eps));

}

long double Finding_fact(int n) {
	if (n < 0)
		return 0;
	else if (n == 0)
		return 1;
	else
		return n * Finding_fact(n - 1);
}

int Solution(double x, double eps) {

	long double pr = 0;

	int k, f, n = 0;

	for (int i = 1; fabs(sin(x) - pr) > eps; i++) {
		k = i - 1;
		f = 2 * i - 1;
		pr += pow(-1, k) * pow(x, f) / Finding_fact(2 * i - 1);
		n = i;
	}
	return n;
}