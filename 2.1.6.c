#include <stdio.h>
#include <math.h>

long double factor(long long int a);
float sum(int n, float x, float eps,float pr);

void main(void)
{
	int n=1, k, l, yes=0;
	float x, eps = 0.1, pr = 0;
    printf("Enter x: ");
	scanf_s("%f", &x);
	printf("sinx=%f\n", sin(x));
	printf("n=%f\n", sum(n, x, eps, pr));
}
long double factor(long long int a) {
	if (a < 0)
		return 0;
	if (a == 0)
		return 1;
	else
		return a * factor(a - 1);
}
float sum(int n, float x, float eps, float pr) {
	int k, l;
	k = 2 * n - 1; l = n - 1;
	pr += pow(x, k) * pow(-1, l) / factor(k);
	if (fabs(pr - sin(x)) <= eps) {
		printf("pr=%f\n", pr);
		return n;
	}
	else
		return sum(n + 1, x, eps, pr);
}