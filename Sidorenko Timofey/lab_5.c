
#include <stdio.h>
#include<malloc.h>
#include <string.h>


struct Node
{
    struct Node* pNext;
    char data;
};

struct Stack
{
    struct Node* head;
    int size;
};

struct Stack pushFront(struct Stack*, char);
struct Stack popFront(struct Stack*);

int main() {
        struct Stack lst;
        lst.head = NULL;
        lst.size = 0;
        struct Stack* list = &lst;
        char input[80] ="";
        char input_f[80] ="";
        char output[80] ="";
        int size = 0;
        printf("Enter string\n");
        gets_s(input,80);
        size = strlen(input);
        for (int i = 0; i < size; i++)
        {
            if(input[i]==' '||input[i]=='.'||input[i]==','||input[i]=='!'||input[i]=='?')
                continue;
            input_f[i] = input[i];
            pushFront(list, input[i]);
        }
        struct Node* temp = list->head;
        char current;
        size = lst.size;
        printf("Reverse text: ");
        for (int i = 0; i < size; i++)
        {
            temp = list->head;
            current = temp->data;
            output[i] = current;
            printf("%c",output[i]);
            popFront(list);
        }
        if(strcmp(input_f,output)==0)
        {
            printf("\nThis is a polyndrom");
        }
        else printf("\nThis is not a polyndrom");

    return 0;
}

struct Stack pushFront(struct Stack* list, char chData)
{
    if (list->head == NULL)
    {
        list->head = (struct Node*)malloc(sizeof(struct Node));
        (list->head)->data = chData;
        (list->head)->pNext = NULL;
    }
    else
    {
        struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
        temp->pNext = list->head;
        temp->data = chData;
        list->head = temp;

    }
    list->size += 1;
}
struct Stack popFront(struct Stack* list)
{
    struct Node* temp = list->head;
    list->head = (list->head)->pNext;
    free(temp);
    list->size -= 1;
}

