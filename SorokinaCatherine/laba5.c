#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <math.h>

typedef struct node{
    int digit;
    struct node *next;
    struct node *prev;
} Node;

typedef struct rnumber{
    size_t size;
    Node *head;
    Node *tail;
} RNumber;

RNumber* createRNumber();
void deleteRNumber(RNumber** list);
void pushBack(RNumber *list, int data);
int popBack(RNumber *list);
void findNOK(RNumber *list1, RNumber *list2);

int main() {
    setlocale(LC_ALL, "Rus");

    RNumber *first = createRNumber();
    RNumber *second = createRNumber();

    findNOK(first, second);

    deleteRNumber(&first);
    deleteRNumber(&second);

    return 0;
}

RNumber* createRNumber(){
    RNumber *tmp = (RNumber*) malloc(sizeof(RNumber));
    tmp->size=0;
    tmp->head=tmp->tail=NULL;

    int num, var = 0;
    while(var!=1) {
        printf("Enter ur number: ");
        var = scanf("%d", &num);
        if(var!=1)
            fflush(stdin);
    }
    char number[20];
    sprintf(number, "%d", num);

    for (int i = 0; number[i]!='\0'; i++) {
        int d = number[i] - 48;
        pushBack(tmp, d);
    }

    return tmp;
}
void deleteRNumber(RNumber **list){
    Node *tmp=(*list)->head;
    Node *next = NULL;
    while (tmp){
        next = tmp->next;
        free(tmp);
        tmp=next;
    }
    free(*list);
    (*list) = NULL;
}

void pushBack(RNumber *list, int data){
    Node *tmp = (Node*)malloc(sizeof(Node));
    if (tmp==NULL){
        exit(1);
    }
    tmp->digit = data;
    tmp->next = NULL;
    tmp->prev=list->tail;
    if (list->tail){
        list->tail->next=tmp;
    }
    list->tail = tmp;

    if (list->head == NULL){
        list->head = tmp;
    }
    list->size++;
}
int popBack(RNumber *list){
    Node *next;
    int *tmp;
    int res;
    if (list->tail == NULL){
        exit(2);
    }
    next = list->tail;
    list->tail = list->tail->prev;
    if (list->tail){
        list->tail->next=NULL;
    }
    if (next == list->head){
        list->head = NULL;
    }
    res = next->digit;
    free(next);
    list->size--;
    return res;
}

void findNOK(RNumber *list1, RNumber *list2){
    int num1 = 0, num2 = 0, temp;
    Node *tmp;
    tmp = list1->tail;
    for (int i = 0; tmp!=NULL; i++) {
        num1 += (tmp->digit) * powf(10,i);
        tmp = tmp->prev;
    }
    tmp = list2->tail;
    for (int i = 0; tmp!=NULL; i++) {
        num2 += (tmp->digit) * powf(10,i);
        tmp = tmp->prev;
    }

    if(num1<num2){
        temp = num1;
        num1 = num2;
        num2 = temp;
    }

    while (num2){
        num1%=num2;
        temp = num1;
        num1 = num2;
        num2 = temp;
    }

    printf("Your NOK: %d", num1);

}
