//variant 29
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct List
{ 
	struct List* next; 
	struct List* prev; 
	int field;
};

struct List* Init(int);
struct List* AddItem(struct List*, int);
int Check(int, int);
void Clear(struct List*);

int main()
{
	List* head;
	List* sec;

	int num1, num2;

	printf(" Enter the first number: "); 
	scanf_s("%d", &num1);

	head = Init(num1);
	sec = head;

	printf(" Enter the second number: ");
	scanf_s("%d", &num2);
	sec = AddItem(sec, num2);

	printf("\n");
	if (Check(num1, num2))
		printf(" Numbers are mutually prime!\n");
	else printf(" Numbers non-mutually prime!\n");

	Clear(head);
	return 0;
}

struct List* Init(int a) // а- значение первого узла
{
	struct List* lst; 
	lst = (struct List*)malloc(sizeof(struct List));
	lst->field = a;
	lst->next = NULL; 
	lst->prev = NULL; 
	return(lst);
}
struct List* AddItem(List* lst, int number)
{
	struct List* temp, * p;
	temp = (struct List*)malloc(sizeof(List));
	p = lst->next; 
	lst->next = temp; 
	temp->field = number; 
	temp->next = p; 
	temp->prev = lst; 
	if (p != NULL)
		p->prev = temp;
	return(temp);
}

int Check(int num1, int num2)
{
	if (num1 == num2)
	{
		return num1 == 1;
	}
	else
	{
		if (num1 > num2)
		{
			return Check(num1 - num2, num2);
		}
		else
		{
			return Check(num2 - num1, num1);
		}
	}
}

void Clear(List* head)
{
	List* prev = head;
	while (prev->next)
	{
		List* temp;
		temp = prev;
		prev = prev->next;
		free(temp);
	}
	prev = prev->next;
	free(prev);
}
