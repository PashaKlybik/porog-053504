#include <stdio.h>
#include <math.h>

unsigned long long fact(unsigned long long n)
{
	unsigned long long res = 1;
	while (n > 1)
		res *= n--;
	return res;
}

int main()
{
	unsigned long long n;
	printf("Enter number: ");
	scanf_s("%llu", &n);
	unsigned long long res = 0;
	for (unsigned long long i = 1; i <= n; i++)
	{
		unsigned long long temp = 1;
		for (unsigned long long j = 1; j <= i; j++)
		{
			temp *= fact(j + i) / fact(i);
		}
		res += temp;
	}
	printf("%llu", res);
	return 0;

}
