#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <malloc.h>
#include <locale.h>

struct node {
	node* next;
	node* prev;
	char word[25];
};

struct list {
	node* head;
	node* tail;
};

struct stack {
	list* lst[15];
	int size;
};

struct list* nlst()
{
	list* lst = (struct list*)malloc(sizeof(struct list));
	lst->head = NULL;
	return lst;
}

struct list* spop(struct stack* stck){
	if(stck->size >0){
		stck->size--;
		return stck->lst[stck->size];
	}
}

void spush(struct stack* stck, struct list* lst)
{
	if (stck->size < 15)
	{
		stck->lst[stck->size] = lst;
		stck->size++;
	}
}

struct list* addnode(struct list* lst, char* lstword) {
	struct node* nd = (struct node*)malloc(sizeof(struct node));
	if (lst->head == NULL) {
		lst->head = nd;
		lst->head->next = NULL;
		lst->head->prev = NULL;
	}
	else {
		nd->next = lst->head;
		lst->head->prev = nd;
		lst->head = nd;
		lst->head->prev = NULL;
	}
	for (int i = 0; i < strlen(lstword); i++)
	{
		lst->head->word[i] = lstword[i];
	}
	lst->head->word[strlen(lstword)] = '\0';
	return lst;
}

void show(struct node* nd) {
	while(nd !=NULL){
		printf("%s ", nd->word);
		nd = nd->next;
	}
}


struct list** shekerSort(struct list** list, int size)
{
	int left = 0, right = size - 1; 
	int flag = 1;  
	while ((left < right) && flag > 0)
	{
		flag = 0;
		for (int i = left; i < right; i++) 
		{
			if (toupper(list[i]->head->word[0]) > toupper(list[i+1]->head->word[0])) 
			{           
				struct list* temp = list[i];
				list[i] = list[i + 1];
				list[i + 1] = temp;
				flag = 1;    
			}
		}
		right--; 
		for (int i = right; i > left; i--)  
		{
			if (list[i - 1] > list[i]) 
			{         
				struct list* temp = list[i];
				list[i] = list[i - 1];
				list[i - 1] = temp;
				flag = 1;    // перемещения в этом цикле были
			}
		}
		left++; // сдвигаем левую границу на следующий элемент
	}
	return list;
}

int main() {
	int lists, words;
	printf("Enter list's count: ");
	scanf("%d", &lists);
	printf("Enter word's count: ");
	scanf("%d", &words);
	struct list** lst = (struct list**)malloc(lists * sizeof(struct list));
	struct stack* stck = (struct stack*)malloc(sizeof(struct stack));
	stck->size = 0;
	int check = 1;
	for (int i = 0; i < lists; i++)
	{
		lst[i] = nlst();
		for (int k = 0; k < words; k++)
		{
			if (k % words == 0 || k == 0) {
				printf("\nEnter list N%d: \n", check);
				check++;
			}
			char word[32];
			scanf("%s", word);
			addnode(lst[i], word);
		}
	}
	printf("\n\nYour lists: ");
	for (int i = 0; i < lists; i++)
	{
		printf("\nlist N%d: ", i + 1);
		show(lst[i]->head);
	}
	shekerSort(lst, lists);
	for (int i = lists - 1; i >= 0; i--)
	{
		spush(stck, lst[i]);
	}
	for (int i = 0; i < lists; i++)
	{
		printf("\nOutput from stack N%d: ", i + 1);
		show(spop(stck)->head);
	}
	for (int i = 0; i < lists; i++)
	{
		while (lst[i]->head != NULL)
		{
			struct node* delptr = lst[i]->head;
			lst[i]->head = lst[i]->head->next;
			free(delptr);
		}
	}
	for (int i = 0; i < lists; i++)
	{
		free(lst[i]);
	}
	free(lst);
	free(stck);
	return 0;
}