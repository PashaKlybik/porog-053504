#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include "locale.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// задание 3.2 (7)


int enterSmth(int x, char* message);
int enterSmth_predel(int x, char* message, int predel);
int enterSmth_2predels(int x, char* message, int predel1, int predel2);
bool isFull(int* q, int* w, bool** bol, int n, int m);
void print(int n, int m, int** arr, bool** bol);
int main(void) {
	char* locale = setlocale(LC_ALL, "");

	int n = 0, m = 0;
	n = enterSmth_predel(n, "Введите количество строк: ", 0);
	m = enterSmth_predel(m, "Введите количество столбцов: ", 0);
	int** arr = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		arr[i] = (int*)malloc(m * sizeof(int));
	}
	if (arr == NULL) {
		printf("Произошла ошибка. Запросили слишком много памяти\n");
		return 0;
	}
	bool** bol = (bool**)malloc(n * sizeof(bool*));
	for (int i = 0; i < n; i++) {
		bol[i] = (bool*)malloc(m * sizeof(bool));
	}

	int i = 0, j = 0, a = 0;
	do {
		i = enterSmth_2predels(i, "Введите номер строки: ", -1, n);
		j = enterSmth_2predels(j, "Введите номер столбца: ", -1, m);
		a = enterSmth(a, "Введите число: ");
		// -------------- ввели числа -----------------

		if (!i && !j && !a) {
			int q, w;
			while (isFull(&q, &w, bol, n, m)) {
				printf("Есть невведенные элементы, один из них [%d][%d]\n", q, w);
				char is[5];
				printf("Желаете продолжить ввод (yes) или вывести массив (no): ");
				while (!scanf("%s", &is) || strcmp(is, "yes") != 0 || strcmp(is, "no") != 0) {
					if (strcmp(is, "yes") == 0) break;
					if (strcmp(is, "no") == 0) break;
					while (getchar() != '\n');
					printf("Неправильный ввод. Попробуйте еще раз :()\n");
					printf("Желаете продолжить ввод (yes) или вывести массив (no): ");
				}
				while (getchar() != '\n');
				if (!strcmp(is, "yes")) break;
				else if (!strcmp(is, "no")) {
					print(n, m, arr, bol);
					return 0;
				}
				else
					printf("Ooooops. System error :)\n");
			}
		}
		// ----------------------------------------------
		else if (!bol[i][j]) {
			char is[5];
			printf("Вы уже заполнили этот элемент. Хотите его перезаписать (yes / no): ");
			while (!scanf("%s", &is) || strcmp(is, "yes") != 0 || strcmp(is, "no") != 0) {
				if (strcmp(is, "yes") == 0) break;
				if (strcmp(is, "no") == 0) break;
				while (getchar() != '\n');
				printf("Неправильный ввод. Попробуйте еще раз :()\n");
				printf("Хотите перезаписать элемент (yes / no): ");
			}
			while (getchar() != '\n');
			if (!strcmp(is, "yes")) arr[i][j] = a;
			else if (!strcmp(is, "no"));
			else
				printf("Ooooops. System error :)\n");
		}
		// ----------------------------------------------
		else if (bol[i][j]) {
			arr[i][j] = a;
			bol[i][j] = false;
		}
		// ----------------------------------------------
		else
			printf("Ooooops. System error :)\n");
		// ----------------------------------------------
		} while (1);

		for(int i = 0; i < n; i++)
			free(arr[i]);
		free(arr);
		for (int i = 0; i < n; i++)
			free(bol[i]);
		free(bol);
	return 0;
}

int enterSmth_predel(int x, char* message, int predel) {
	printf(message);
	while (!scanf("%d", &x) || x <= predel) {
		while (getchar() != '\n');
		printf("Неправильный ввод. Попробуйте еще раз :()\n");
		printf(message);
	}
	while (getchar() != '\n');
	return x;
}
int enterSmth(int x, char* message) {
	printf(message);
	while (!scanf("%d", &x)) {
		while (getchar() != '\n');
		printf("Неправильный ввод. Попробуйте еще раз :()\n");
		printf(message);
	}
	while (getchar() != '\n');
	return x;
}
bool isFull(int* q, int* w, bool** bol, int n, int m) {
	for (*q = 0; *q < n; (*q)++) {
		for (*w = 0; *w < m; (*w)++) {
			if (bol[*q][*w]) return true;
		}
	}
	return false;
}
void print(int n, int m, int** arr, bool** bol) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (bol[i][j]) printf("*\t");
			else printf("%d\t", arr[i][j]);
		}
		printf("\n");
	}
}
int enterSmth_2predels(int x, char* message, int predel1, int predel2) {
	printf(message);
	while (!scanf("%d", &x) || x <= predel1 || x >= predel2) {
		while (getchar() != '\n');
		printf("Неправильный ввод. Попробуйте еще раз :()\n");
		printf(message);
	}
	while (getchar() != '\n');
	return x;
}