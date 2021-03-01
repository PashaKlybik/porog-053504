#include <stdio.h>
#include <stdlib.h>
#include <math.h>

	
char itoa(int num) {
	return num + '0';
}
char count_numbers(unsigned long long num, int k) {
	static int counter = 0; // счетчик текущей цифры последовательности
	static unsigned long long size = 10; // для перебора каждой цифры

	while (num / size > 0)
		size *= 10;

	if (num / size == 0) // навсякий
		size /= 10;

	for(unsigned long long i = size; i > 1; i /= 10) {
		if (++counter == k) {
			return itoa(num / i % 10);
		}
	}
	if (++counter == k)
		return itoa(num % 10);

	return 'a'; // красивая буква
}

int main(int argc, char* argv[])
{
	int k;
	char res;

	if(argc == 2)
		k = atoi(argv[1]);
	else
		scanf("%d", &k);

	for (int i = 1; i <= k; i++) {
		res = count_numbers(pow(i, 3), k);
		if (res != 'a') {
			printf("%c\n", res);
			return 0;
		}
	}
	return 1;
}