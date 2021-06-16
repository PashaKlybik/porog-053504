/* 5.1 (16).Дан стек, каждый элемент которого содержит указатель на
двунаправленный список.В каждом элементе списков хранится
слово.С помощью рекурсивной функции вывести каждое слово в
обратном порядке.На основе списков составить один
упорядоченный по алфавиту стек и распечатать его.*/
#define _CRT_SECURE_NO_WARNINGS
#define STACK_MAX_SIZE 20


#include <conio.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <malloc.h>
#include <locale.h>

struct Stack* NewStack();
void StackPush(struct Stack* stack, struct List* _ptr);
struct List* StackPop(struct Stack* stack);
struct List* AddNode(struct List* list, char* word);
struct List* NewList();
void ShowList(struct Node* node);
void Pop(struct List* list, char *word);
struct List** ShellSort(struct List** list, int size);

struct Stack
{
    struct List *ptr[STACK_MAX_SIZE];
    int size;
};

struct Node
{
    struct Node* previous;
    struct Node* next;
    char word[32];
};

struct List
{
    struct Node* head;
};

int main()
{
    setlocale(0, "rus");
    int listsCount, wordsCount;
    printf("Введите количество списков: ");
    scanf("%d", &listsCount);
    printf("Введитее количество слов в списке: ");
    scanf("%d", &wordsCount);
    struct List** list = malloc(listsCount * sizeof(struct List));
    struct Stack* stack = NewStack();
    for (int i = 0; i < listsCount; i++)
    {
        list[i] = NewList();
        for (int k = 0; k < wordsCount; k++)
        {
            char word[32];
            scanf("%s", word);
            AddNode(list[i], word);
        }
    }
    printf("\n\n\nВывод списков: ");
    for (int i = 0; i < listsCount; i++)
    {
        printf("\nСписок #%d: ", i + 1);
        ShowList(list[i]->head);
    }
    ShellSort(list, listsCount);
    for (int i = listsCount - 1; i >= 0; i--)
    {
        StackPush(stack, list[i]);
    }
    for (int i = 0; i < listsCount; i++)
    {
        printf("\nВывод из стека. #%d: ", i + 1);
        ShowList(StackPop(stack)->head);
    }
    for (int i = 0; i < listsCount; i++)
    {
        while (list[i]->head != NULL)
        {
            struct Node* delptr = list[i]->head;
            list[i]->head = list[i]->head->next;
            free(delptr);
        }
    }
    for (int i = 0; i < listsCount; i++)
    {
        free(list[i]);
    }
    free(list);
    free(stack);
}

struct Stack* NewStack()
{
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->size = 0;
    return stack;
}

void StackPush(struct Stack* stack, struct List *_ptr)
{
    if (stack->size < STACK_MAX_SIZE)
    {
        stack->ptr[stack->size] = _ptr;
        stack->size++;
    }
}

struct List* StackPop(struct Stack* stack)
{
    if (stack->size > 0)
    {
        stack->size--;
        return stack->ptr[stack->size];
    }
    return NULL;
}

struct List* NewList()
{
    struct List* list = (struct List*)malloc(sizeof(struct List));
    list->head = NULL;
    return list;
}

struct List* AddNode(struct List* list, char* word)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if (list->head == NULL)
    {
        list->head = node;
        list->head->next = NULL;
        list->head->previous = NULL;
    }
    else
    {
        node->next = list->head;
        list->head->previous = node;
        list->head = node;
        list->head->previous = NULL;
    }
    for (int i = 0; i < (int)strlen(word); i++)
    {
        list->head->word[i] = word[i];
    }
    list->head->word[(int)strlen(word)] = '\0';
    return list;
}

void ShowList(struct Node* node)
{
    printf("%s ", node->word);
    if (node->next != NULL)
    {
        ShowList(node->next);
    }
}

void Pop(struct List* list, char *word)
{
    for (int i = 0; i < (int)strlen(list->head->word); i++)
    {
        word[i] = list->head->word[i];
    }
    word[strlen(list->head->word)] = '\0';
    struct Node *delptr = list->head;
    list->head = list->head->next;
    list->head->previous = NULL;
    free(delptr);

}

struct List** ShellSort(struct List** list, int size) 
{
    for (int s = size / 2; s > 0; s /= 2) 
    {
        for (int i = 0; i < size; i++) 
        {
            for (int j = i + s; j < size; j += s) 
            {
                if (toupper(list[i]->head->word[0]) > toupper(list[j]->head->word[0]))
                {
                    struct List *temp = list[j];
                    list[j] = list[i];
                    list[i] = temp;
                }
            }
        }
    }
    return list;
}