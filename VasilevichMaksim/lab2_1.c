#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "locale.h"
#include "math.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define PI 3.1415926535

// ������� 2.2 (6)

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
		printf("1. ����������\n");
		printf("2. �����������\n");
		printf("3. �����\n");
		printf("---------------------\n");
		printf("������� �����: ");
		while (!scanf("%d", &way) || way <= 0 || way >= 4) {
			while (getchar() != '\n');
			printf("����� ����� �� ��� :()....\n");
			printf("������� �����: ");
		}
		if (way == 3) continue;
		while (getchar() != '\n');
		printf("������� x (�������): ");
		while (!scanf("%lf", &x)) {
			while (getchar() != '\n');
			printf("����� ����� �� ��� :()....\n");
			printf("������� x (�������): ");
		}
		while (getchar() != '\n');
		printf("������� e (�� 0 �� 1): ");
		while (!scanf("%lf", &e) || e <= 0 || e >= 1) {
			while (getchar() != '\n');
			printf("����� ����� �� ��� :()....\n");
			printf("������� e (�� 0 �� 1): ");
		}
		while (getchar() != '\n');

		if (way == 1) {
			n = 1;
			left = sin(x * PI / 180);
			right = calculateRec(x * PI / 180, &n, 0, e);
			printf("\n����� ����� = %lf\n", left);
			printf("������ ����� = %lf\n", right);
			printf("����������� ���������� = %lf\n", absMe(left - right));
			printf("n = %d\n", n);
		}
		else if (way == 2) {
			n = 1;
			left = sin(x * PI / 180);
			right = calculateItr(x * PI / 180, &n, 0, e);
			printf("\n����� ����� = %lf\n", left);
			printf("������ ����� = %lf\n", right);
			printf("����������� ���������� = %lf\n", absMe(left - right));
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