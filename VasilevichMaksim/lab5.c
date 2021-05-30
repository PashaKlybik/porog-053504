#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <math.h>

/*
5.1(4)
–азработать функцию, перевод€щую многоразр€дное дес€тичное
число в восьмеричную систему. ƒл€ хранени€ многоразр€дного
числа использовать динамический двунаправленный список
*/

typedef struct Node {
	int digit;
	struct Node* next;
	struct Node* prev;
} Node;
typedef struct List {
	int n;
	Node* head;
	Node* tail;
} List;

List CreateNumber(char* a);
void AddDigit(List* num, int d);
List DecToOct(List* num);
int GetNumber(List* num);
void RemoveBack(List* num);
void print(List* num);
void printInvert(List* num);
void freeList(List* num);

int main(void) {
	long long a;
	char str[21];
	printf("Enter number: ");
	if (!scanf("%20[0-9]", &str)) { printf("Incorrect input"); exit(1); }
	List num = CreateNumber(str);
	print(&num);
	List oct = DecToOct(&num);
	printInvert(&oct);

	freeList(&oct);

	return 0;
}
List CreateNumber(char* a) {
	List num = { 0, NULL, NULL };

	for (int i = 0; i < strlen(a); i++) {
		AddDigit(&num, a[i] - '0');
	}
	return num;
}
void AddDigit(List* num, int d) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->digit = d;
	p->next = NULL;
	p->prev = NULL;
	if (!num->head) { num->head = p; num->tail = p; }
	else {
		num->tail->next = p;
		p->prev = num->tail;
		num->tail = p;
	}
	num->n++;
}

List DecToOct(List* num) {
	int dec = 0, oct = 0, i = 0, ost = 0;
	List octnumInvert = { 0, NULL, NULL };
	do {
		dec = GetNumber(num);
		if (!num->n) { num->head = NULL; num->tail = NULL; }
		//print(num);
		ost = dec % 8;
		dec /= 8;
		char buf[21];
		snprintf(buf, 21, "%d", dec);
		*num = CreateNumber(&buf);
		//print(num);
		AddDigit(&octnumInvert, ost);
		//printInvert(&octnumInvert);
	} while (dec);
	return octnumInvert;
}

int GetNumber(List* num) {
	int dec = 0, i = 0;
	while (num->tail) {
		dec += num->tail->digit * pow(10, i++);
		RemoveBack(num);
	}
	return dec;
}
void RemoveBack(List* num) {
	Node* tmp = num->tail;
	num->tail = num->tail->prev;
	free(tmp);
	num->n--;
}

void print(List* num) {
	printf("Number in dec: ");
	Node* p = num->head;
	while (p) {
		printf("%d", p->digit);
		p = p->next;
	}
	printf("\n");
}
void printInvert(List* num) {
	Node* p = num->tail;
	printf("Number in oct: ");
	while(p) {
		printf("%d", p->digit);
		p = p->prev;
	}
	printf("\n");
}

void freeList(List* num) {
	Node* tmp;
	while (num->head) {
		tmp = num->head;
		num->head = num->head->next;
		free(tmp);
		num->n--;
	}
}