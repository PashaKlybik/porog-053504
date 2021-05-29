#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define N 200

struct node {
	char data;
	struct node* next;
};
struct node* head = NULL;
struct node* tail = NULL;

void push(char);
char top();
void pop();
int size();
void ept();
int count = 0;

void main(void) {
	setlocale(LC_ALL, "Rus");
	int i, j, s;
	char ch;
	char* text = (char*)malloc(sizeof(char)*N);
	do {
		printf("Enter the string:\n");
		
		i = 0;
		j = 0;
		s = 0;
		for (i; (ch = getchar()) != '\n'; i++) {
			if (ch <= 122 && ch >= 32) {
				if ((ch >= 65 && ch <= 89) || (ch >= 97 && ch <= 122)) {
					text[i] = ch;
					push(ch);
				}
				else i--;
			}
		}
		text[i] = '\0';
		s = size();
		if (s != 0) {
			for (j; j < s; j++) {
				if (text[j] == top() || (text[j] == top() - 32 && text[j] >= 65 && text[j] <= 89) ||( text[j] == top() + 32 && text[j] >= 97)) {
					pop();
				}
				else if (text[j] != top()) {

					break;
				}
			}
			if (j == s)
				printf("It is a palindrome\n");
			if (j != s)
				printf("It is not a palindrome\n");
			ept();
		}
	} while (1);
	free(text);
 } 
void push(char x) {
	struct node* t;

	t = (struct node*)malloc(sizeof(struct node));
	t->data = x;
	t->next = NULL;
	if (head == NULL) {
		head = t;
		tail = t;
		t = NULL;
	}
	else
	{
		 tail->next = t;
		 tail = t;
	}
}

char top() {
	struct node* t;

	t = head;
	while (t != NULL) {
		if (t->next == NULL)
			return t->data;
		t = t->next;
	}

}

void pop() {
	struct node* current=NULL, * previous=NULL;
	struct node* t;
	if (size() == 1)
	{
		t = head;
		head = head->next;
		free( t);
	}
	else
	{
		current = head;
		while (current->next != NULL)
		{
			previous = current;
			current = current->next;
		}
		tail = previous;
		previous->next = NULL;
		free(current);
	}
}

void ept() {
	struct node* t;
	while(head!=NULL)
	{
		pop();
	}
}

int size() {
	struct node* t;
	int k = 0;
	
	t = head;
	while (t!= NULL) {
		t = t->next;
		k++;
	}
	return k;
}

