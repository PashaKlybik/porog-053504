#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "locale.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <iostream>
#define BUFFER_SIZE 256


bool check_input(char str[BUFFER_SIZE]);
// организация стека под массив символов
void pushch(char* s, int* top, char f);
char peekch(char* s, int top);
void popch(char* s, int* top);
int sizech(char* s, int top);
bool isEmptych(int top);
bool isFullch(int top);
// организация стека под массив чисел
void pushi(float* s, int* top, float f);
float peeki(float* s, int top);
void popi(float* s, int* top);
int sizei(float* s, int top);
bool isEmptyi(int top);
bool isFulli(int top);
// работа с ОПЗ
char* Converting(char* input, char* stack, int* top);
float Calculate(char* input, float* stack, int* top);
bool isOperation(char s);
bool CompareOperators(char s, char f);
float DoOperation(float a, float b, char s);

float funct() {
	return 0.01785674;
}
//----------------------------------------------------
int main(void) {
	setlocale(LC_ALL, "Rus");
	char* str = (char*)malloc(BUFFER_SIZE * sizeof(char));

	do {
		printf("Введите строку: ");
		fgets(str, BUFFER_SIZE, stdin);
		str[strlen(str)-1] = '\0';
	} while (check_input(str));
	printf("Строка: %s\n", str);

	// обратная польская запись

	// стек символов
	char* stackch = (char*)malloc(BUFFER_SIZE * sizeof(char));
	int topch = -1;
	char* output = Converting(str, stackch, &topch);
	printf("ОПЗ: %s\n", output);

	float* stacki = (float*)malloc(BUFFER_SIZE * sizeof(float));
	int topi = -1;
	float result = Calculate(output, stacki, &topi);
	float result2 = funct();
	printf("Result: %f", result);
	/*

	pushch(stackch, &topch, 'a');
	char f1 = peekch(stackch, topch);
	popch(stackch, &topch);
	bool df = isEmptych(topch);
	*/

	free(str);
	free(output);
	free(stackch);
	free(stacki);
}

// --------------------------------------
bool check_input(char str[BUFFER_SIZE]) {
	// проверка на другие символы
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] >= '0' && str[i] <= '9' || str[i] == '(' || str[i] == ')' || str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
			continue;
		else {
			printf("Неверный ввод...\n");
			return true;
		}
	}

	// проверка на присутствие оператора
	bool oper = true;
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') { oper = false; break; }
	}
	if(oper) { printf("Неверный ввод...\n"); return true; }

	// проверка на колво скобок
	int g = 0;
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == '(') g++;
		if (str[i] == ')') g--;
		if (g < 0) { g = 0; break; }
	}
	if (g) { printf("Неверный ввод...\n"); return true; }

	// 
	if(str[0] == '/' || str[0] == '*' || str[0] == '+') { printf("Неверный ввод...\n"); return true; }

	// проверка на следование операторов
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == '(' || str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
			if (str[i+1] == ')' || str[i+1] == '+' || str[i+1] == '*' || str[i+1] == '/' || str[i+1] == '\0') { printf("Неверный ввод...\n"); return true; }
			//if (str[i] == '(' && str[i+1] == '-') { continue; }
			// перед ( должен быть оператор
			if(str[i] == '(' && !(str[i-1] == '+' || str[i - 1] == '-' || str[i - 1] == '*' || str[i - 1] == '/')) { 
				printf("Неверный ввод...\n"); return true; }
		}
		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
			if (str[i + 1] == '-') { printf("Неверный ввод...\n"); return true; }
		}
	}
	return false;
}
// --------------------------------------
float Calculate(char* input, float* stack, int* top) {
	float x, y;
	char* number = (char*)malloc(BUFFER_SIZE * sizeof(char));
	number[0] = '\0';
	int lenoutput = 0;
	int lennumber = 0;
	int f = strlen(input);

	for (int i = 0; i < strlen(input); i++) {
		char s = input[i];
		if (input[i] == '-' && input[i+1] >= '0' && input[i+1] <= '9') 
		{ number[lennumber++] = s; number[lennumber] = '\0'; }
		else if (s >= '0' && s <= '9') 
		{ number[lennumber++] = s; number[lennumber] = '\0'; }
		else if (isOperation(s)) {
			if (lennumber) {
				pushi(stack, top, atoi(number));  lennumber = 0; number[0] = '\0';
			}
			x = peeki(stack, *top);  popi(stack, top);
			y = peeki(stack, *top);  popi(stack, top);
			pushi(stack, top, DoOperation(y, x, s));
		}
		else {
			if (lennumber) {
				pushi(stack, top, atoi(number)); lennumber = 0; number[0] = '\0';
			}
		}
	}
	return peeki(stack, *top);
}

char* Converting(char* input, char* stack, int* top) {
	//char output[BUFFER_SIZE], number[BUFFER_SIZE];
	char* output = (char*)malloc(BUFFER_SIZE * sizeof(char));
	char* number = (char*)malloc(BUFFER_SIZE * sizeof(char));
	int lenoutput = 0;
	int lennumber = 0;

	for (int i = 0; i < strlen(input); i++) {
		char s = input[i];
		if (input[i] == '-' && i == 0) number[lennumber++] = s;
		else if (input[i] == '-' && input[i - 1] == '(') number[lennumber++] = s;
		else if (s >= '0' && s <= '9') number[lennumber++] = s;
		else if (isOperation(s)) {
			if (lennumber) {
				int i = 0;
				while(lennumber != i)
					output[lenoutput++] = number[i++];
				output[lenoutput++] = ' ';
				lennumber = 0;
			}
			while (!isEmptych(*top) && CompareOperators(s, peekch(stack, *top))) { // &stack - ???
				char op = peekch(stack, *top);   popch(stack, top); // pop(, top) - ???
				output[lenoutput++] = op;
				output[lenoutput++] = ' ';
			}
			if (s == ')') {
				while (peekch(stack, *top) != '(') {
					char op = peekch(stack, *top);   popch(stack, top);
					output[lenoutput++] = op;
					output[lenoutput++] = ' ';
				}
				popch(stack, top);
				continue;
			}
			pushch(stack, top, s);
		}
	}
	if (lennumber) {
		int i = 0;
		while (lennumber != i)
			output[lenoutput++] = number[i++];
		output[lenoutput++] = ' ';
	}

	while (!isEmptych(*top)) {
		char op = peekch(stack, *top);   popch(stack, top);
		output[lenoutput++] = op;
		output[lenoutput++] = ' ';
	}
	output[lenoutput] = '\0';
	free(number);
	return output;
}

// --------------------------------------
// работа с ОПЗ
bool isOperation(char s) {
	switch (s) {
	case '+': return true; break;
	case '-': return true; break;
	case '*': return true; break;
	case '/': return true; break;
	case '(': return true; break;
	case ')': return true; break;
	default: return false;
	}
}
bool CompareOperators(char s, char f) {
	int sPri = 0, fPri = 0;

	if (s == '+' || s == '-') sPri = 1;
	else if (s == '*' || s == '/') sPri = 2;
	else if (s == '(' || s == ')') return false;
	else exit(1);

	if (f == '+' || f == '-') fPri = 1;
	else if (f == '*' || f == '/') fPri = 2;
	else if (f == '(' || f == ')') return false;
	else exit(1);

	return fPri >= sPri;
}
float DoOperation(float a, float b, char s) {
	switch (s) {
	case '+': return a + b; break;
	case '-': return a - b; break;
	case '*': return a * b; break;
	case '/': return a / b; break;
	default: return false;
	}
}

// --------------------------------------
// стек массив символов
void pushch(char* s, int* top, char f) {
	if (isFullch(*top)) exit(1);
	s[++(*top)] = f;
}
char peekch(char* s, int top) {
	if (!isEmptych(top)) return s[top];
	else exit(1);
}
void popch(char* s, int* top) {
	if (isEmptych(*top)) exit(1);
	(*top)--;
}
int sizech(char* s, int top) {
	return top + 1;
}
bool isEmptych(int top) {
	return top == -1;
}
bool isFullch(int top) {
	return top == BUFFER_SIZE - 1;
}

// --------------------------------------
// стек массив чисел
void pushi(float* s, int* top, float f) {
	if (isFullch(*top)) exit(1);
	s[++(*top)] = f;
}
float peeki(float* s, int top) {
	if (!isEmptych(top)) return s[top];
	else exit(1);
}
void popi(float* s, int* top) {
	if (isEmptych(*top)) exit(1);
	(*top)--;
}
int sizei(float* s, int top) {
	return top + 1;
}
bool isEmptyi(int top) {
	return top == -1;
}
bool isFulli(int top) {
	return top == BUFFER_SIZE - 1;
}