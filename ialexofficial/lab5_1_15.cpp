#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int atoi(char s)
{
	return s - '0';
}
char itoa(int s)
{
	return s + '0';
}
unsigned long long pow(unsigned long long base, unsigned long long exp)
{
	unsigned long long res = 1;
	for (unsigned long long i = 0; i < exp; i++)
	{
		res *= base;
	}
	return res;
}

typedef struct listNode
{
	struct listNode *next, *previous;
	int num, size;
} ListNode;

void initializeList(char str[], ListNode** head);
int getCountOfDiviser(ListNode* head);
int checkDivision(ListNode** head, unsigned long long num);
void clearList(ListNode* head);
unsigned long long getDiv(ListNode* head, int num);

int main()
{
	ListNode* listHead;
	char str[100], choise = 'y';
	while (choise == 'y')
	{
		printf("Write a number\n");
		gets_s(str, 100);
		if (str[0] == '\0')
			gets_s(str, 100);
		initializeList(str, &listHead);
		printf("Answer: %d\n Do you want to continue?(y/n) ", getCountOfDiviser(listHead));
		scanf(" %c", &choise);
	}
	return 0;
}

void initializeList(char str[], ListNode** head)
{
	*head = malloc(sizeof(ListNode));
	(*head)->num = atoi(str[0]);
	(*head)->size = 1;
	(*head)->previous = NULL;
	(*head)->next = NULL;
	ListNode* temp = NULL;
	ListNode* prev = *head;
	for (int i = 1; i < strlen(str); i++)
	{
		temp = malloc(sizeof(ListNode));
		temp->num = atoi(str[i]);
		temp->previous = prev;
		prev->next = temp;
		prev = temp;
		(*head)->size++;
	}
	if(temp != NULL)
		temp->next = NULL;
}

int getCountOfDiviser(ListNode* head)
{
	int res = 0;
	for(unsigned long long currentDivider = 2; currentDivider < getDiv(head, 2) + 1; currentDivider++)
	{
		if (checkDivision(&head, currentDivider))
			res++;
	}
	clearList(head);
	return res + 2;
}
int checkDivision(ListNode** head, unsigned long long num)
{
	unsigned long long rest = 0;
	ListNode* currentNode = *head;
	while (currentNode != NULL)
	{
		rest = ((rest + currentNode->num) % num) * 10;
		currentNode = currentNode->next;
	}
	if (rest == 0) {
		return 1;
	}
	else {
		return 0;
	}
}
unsigned long long getDiv(ListNode* head, int num)
{
	unsigned long long rest = 0, res = 0, level = 0, tmp;
	ListNode* currentNode = head;
	while (currentNode != NULL)
	{
		tmp = (rest + currentNode->num) / num;
		if (tmp != 0) {
			res += tmp * pow(10, head->size - level - 1);
		}
		rest = ((rest + currentNode->num) % num) * 10;
		level++;
		currentNode = currentNode->next;
	}
	return res;
}
void clearList(ListNode* head)
{
	ListNode* tmp = head;
	while (head != NULL)
	{
		head = head->next;
		free(tmp);
		tmp = head;
	}
}