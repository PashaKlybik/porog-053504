#include <stdio.h>
#include<malloc.h>
#include<math.h>

struct Node
{
    struct Node* pNext;
    struct Node* pPrev;
    int data;
};

struct List
{
    struct Node* head;
    int size;
};

struct List pushBack(struct List*, int);
struct List removeAt(struct List*, int);
struct List popFront(struct List*);
struct List clearList(struct List*);

int length(char*);
void DecToOct(struct List*);

int main() {
    struct List dig;
    dig.head = NULL;
    dig.size = 0;
    struct List *digit = &dig;
    char str[21];
    int size = 0;

    printf("Enter string of numbers\n");
    scanf("%20[0-9]", str);
    size = length(str);
    for (int i = 0; i < size; i++)
    {
        pushBack(digit, str[i] -48);
    }
    DecToOct(digit);

    return 0;
}

struct List pushBack(struct List *l, int infData)
{
    if(l->head == NULL)
    {
        l->head = (struct Node*) malloc (sizeof(struct Node));
        l->head->pNext = NULL;
        l->head->data = infData;
        l->head->pPrev = NULL;
    }
    else
    {
        struct Node* elem = l->head;

        while(elem->pNext != NULL)
        {
            elem = elem->pNext;
        }
        elem->pNext = (struct Node*) malloc (sizeof(struct Node));
        (elem->pNext)->data = infData;
        (elem->pNext)->pNext = NULL;
        (elem->pNext)->pPrev = elem;
    }

    l->size+=1;
}

struct List popFront(struct List* l)
{
    struct Node *proto = l->head;
    l->head = (l->head)->pNext;
    if(l->head!= NULL)
    {
        l->head->pPrev = NULL;
    }

    free(proto);
    l->size-= 1;
}

struct List clearList(struct List* l)
{
    while(l->size)
    {
        popFront(l);
    }
}

struct List removeAt(struct List* l, int index)
{
    index = index - 1;
    if( index == 0)
    {
        popFront(l);
    }
    else
    {
        struct Node* prev = l->head;

        for(int i =0; i < index-1 && prev->pNext != NULL; i++ )
        {
            prev = prev->pNext;
        }
        struct Node* del = prev->pNext;

        if( prev->pNext != NULL)
        {
            prev->pNext = del->pNext;
            (del->pNext)->pPrev = prev;
        }
        free(del);
        l->size -= 1;
        if(l->size == 0)
        {
            l->head = NULL;
        }
    }

}

int length(char* str)
{
    int i =0;
    while(str[i])
    {
        i++;
    }
    return i;
}

void DecToOct(struct List *l)
{
    unsigned long long int dec =0, op = 0;
    struct Node* proto= l->head;
    int *mass = (int*) malloc ((l->size+1)*sizeof(int));
    for (int i = l->size -1; i >= 0; i--) {
        dec+= proto->data * pow(10, i);
        proto = proto->pNext;
    }
    mass[l->size] = 0;
    int z=0;
    while(dec!= 0)
    {
        op = dec/8;
        mass[z] = (dec % 8);
        z++;
        dec = op;
    }
    for (int i = l->size; i >=0; i--)
    {
        printf("%d", mass[i]);
    }
    clearList(l);

}
