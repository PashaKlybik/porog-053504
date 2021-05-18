#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "locale.h"
#include "math.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define PI 3.1415926535

// задание 2.2 (6)

long double left = 0.0;
long double right = 0.0;

long double calculateRec(long double x, int *n, long double sum, long double e);
long double calculateItr(long double x, int* n, long double sum, long double e);
long double absMe(long double x);

int main(void) {
	char* locale = setlocale(LC_ALL, "");
	int way = 0;
	long double x = 0.0;
	double e = 0.0001;
	int n = 1;

	do {
		printf("---------------------\n");
		printf("1. Рекурсивно\n");
		printf("2. Итерационно\n");
		printf("3. Выйти\n");
		printf("---------------------\n");
		printf("Введите число: ");
		while (!scanf("%d", &way) || way <= 0 || way >= 4) {
			while (getchar() != '\n');
			printf("Чтото пошло не так :()....\n");
			printf("Введите число: ");
		}
		if (way == 3) continue;
		while (getchar() != '\n');
		printf("Введите x (градусы): ");
		while (!scanf("%lf", &x)) {
			while (getchar() != '\n');
			printf("Чтото пошло не так :()....\n");
			printf("Введите x (градусы): ");
		}
		while (getchar() != '\n');
		printf("Введите e (от 0 до 1): ");
		while (!scanf("%lf", &e) || e <= 0 || e >= 1) {
			while (getchar() != '\n');
			printf("Чтото пошло не так :()....\n");
			printf("Введите e (от 0 до 1): ");
		}
		while (getchar() != '\n');

		if (way == 1) {
			n = 1;
			left = sin(x * PI / 180);
			right = calculateRec(x * PI / 180, &n, 0, e);
			printf("\nЛевая часть = %lf\n", left);
			printf("Правая часть = %lf\n", right);
			printf("Погрешность вычислений = %lf\n", absMe(left - right));
			printf("n = %d\n", n);
		}
		else if (way == 2) {
			n = 1;
			left = sin(x * PI / 180);
			right = calculateItr(x * PI / 180, &n, 0, e);
			printf("\nЛевая часть = %lf\n", left);
			printf("Правая часть = %lf\n", right);
			printf("Погрешность вычислений = %lf\n", absMe(left - right));
			printf("n = %d\n", n);
		}

	} while (way != 3);

	return 0;
}
long long fact(long long x);
long double calculateRec(long double x, long long *n, long double sum, long double e) {
	if (absMe(left - sum) < e) {
		return sum;
	}
	sum += (long double)pow(-1, *n - 1) * (long double)pow(x, 2 * *n - 1) / fact(2 * *n - 1);
	(*n)++;
	return  calculateRec(x, n, sum, e);
}
long long fact(long long x) {
	if (x == 0)
		return 1;
	return x * fact(x-1);
}
long double absMe(long double a) {
	if (a < 0)
		return -a;
	return a;
}
long double calculateItr(long double x, int* n, long double sum, long double e) {
	for (; absMe(left - sum) >= e; (*n)++) {
		sum += pow(-1, *n - 1) * pow(x, 2 * *n - 1) / fact(2 * *n - 1);
	}
	return sum;
}