#include "stdio.h"
#include "locale.h"
#include "math.h"

int main(void) {
	char* locale = setlocale(LC_ALL, "");

	unsigned long long int s;
	int again;
	do {
		do {
			int g;
			printf("Введите денежную сумму: ");
			scanf_s("%lld", &s);
		} while (s <= 7);
		long long int p, t, _s = 0;

		while (s % 5 != 0) {
			s--;
			_s++;
		}
		p = s / 5;
		for (t = 0; _s != 0; t++) {
			while (_s < 0 && p != 0) { _s += 5; p--; }
			_s -= 3;
		}
		//6666666666666666    6 666 666 666 666 666

		printf("Пятерки: %lld, Тройки: %lld\n", p, t);
		printf("Еще разок? (1 / 0)\n");
		scanf_s("%d", &again);
	} while (again);
	return 0;
}