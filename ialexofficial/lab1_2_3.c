#include <stdio.h>
#include <stdlib.h>
#include <math.h>


char itoa(int num) {
	return num + '0';
}
int count_numbers(unsigned long long num, unsigned long long k) {
	static unsigned long long counter = 0; // счетчик текущей цифры последовательности
	static unsigned long long size = 10; // для перебора каждой цифры

	while (num / size > 0)
		size *= 10;

	if (num / size == 0) // навсякий
		size /= 10;

	for (unsigned long long i = size; i > 1; i /= 10) {
		if (++counter == k) {
			return num / i % 10;
		}
	}
	if (++counter == k)
		return num % 10;

	return -1;
}

int main(int argc, char* argv[])
{
	unsigned long long k;
	int res;

	if (argc == 2)
		k = atoi(argv[1]);
	else
		scanf("%llu", &k);

	for (unsigned long long i = 1; i <= k; i++) {
		res = count_numbers(pow(i, 3), k);
		if (res != -1) {
			printf("%d\n", res);
			return 0;
		}
	}
	return 1;
}