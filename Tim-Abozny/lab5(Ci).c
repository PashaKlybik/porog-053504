#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <locale.h>

typedef struct {
    char info;
    char* next;
} Stack;

char OutStack(Stack** st) {
    char temp = (*st)->info;
    Stack* t;
    t = (*st)->next;
    (*st)->next = t->next;
    (*st)->info = t->info;
    free(t);
    return temp;
}

void InStack(Stack** st, char info) {
    Stack* temp = (Stack*)malloc(sizeof(Stack));
    if ((*st)->next == NULL) {
        (*st)->info = info;
        temp->next = NULL;
        (*st)->next = temp;
    }
    else {
        temp->next = (*st)->next;
        temp->info = (*st)->info;
        (*st)->next = temp;
        (*st)->info = info;
    }
}


typedef struct {
    Stack* info;
    struct list* prev;
    struct list* next;
}list;

void ToList(list** head, Stack* value) {
    if (((*head)->next == NULL) && ((*head)->prev == NULL)) {
        (*head)->info = value;
        (*head)->next = (*head);
        (*head)->prev = (*head);
    }
    else {
        list* temp = (list*)malloc(sizeof(list));

        if ((*head)->next == (*head)) {
            temp->info = (*head)->info;
            temp->next = (*head);
            temp->prev = (*head);
            (*head)->next = temp;
            (*head)->prev = temp;
            (*head)->info = value;
        }
        else {
            list* t = (*head)->next;
            t->prev = temp;
            temp->next = (*head)->next;
            temp->info = (*head)->info;
            temp->prev = (*head);
            (*head)->info = value;
            (*head)->next = temp;
        }
    }
}
int main()
{
    setlocale(0, "rus");
    int CountLists = 10;
    list* spisok = (list*)malloc(sizeof(list));

    spisok->next = NULL;
    spisok->prev = NULL;

    for (int i = 0; i < CountLists; i++) {
        Stack* temp = (Stack*)malloc(sizeof(Stack));

        temp->next = NULL;
        
        for (int j = 0; j < 10; j++) {
            char info = rand() % 26 + 0x61;
            InStack(&temp, info);
        }
        ToList(&spisok, temp);
    }

    list* temp = spisok;

    for (int i = 0; i < CountLists; i++) {
        char arr[10];
        Stack* s = temp->info;
        int t = 0;
        while (s->next != NULL) {
            arr[t] = OutStack(&s);
            t++;
        }
        printf("\n***************\nНеотсортированный стек:\n");
        for (int i = 0; i < 10; i++) {
            printf("%c", arr[i]);
        }


        for (int i = 0; i < 10; i++) { //Сортировка пузырьком
            for (int j = 0; j < 9; j++) {
                if ((int)arr[j] > (int)arr[j + 1]) {
                    char temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }

        printf("\nОтсортированный стек:\n");
        for (int i = 0; i < 10; i++) {
            printf("%c", arr[i]);
            InStack(&s, arr[i]);
        }
        printf("\n");
        temp = temp->next;
    }

    Stack* sorted = (Stack*)malloc(sizeof(Stack));
    sorted->next = NULL;

    char sort[100];
    temp = spisok;
    Stack* t1 = temp->info;
    for (int i = 0, l = 0; i < 10; i++) {
        while (t1->next != NULL) {

            InStack(&sorted, OutStack(&t1));
        }
        temp = temp->next;
        t1 = temp->info;
    }
    int schet = 0;
    printf("\nслитый до сортировки:\n");
    while (sorted->next != NULL) {
        sort[schet] = OutStack(&sorted);
        printf("%c", sort[schet]);
        schet++;
    }
    for (int k = 0; k < 100; k++) {
        for (int t = 0; t < 99; t++) {
            if ((int)sort[t] < (int)sort[t + 1]) {
                char temp = sort[t];
                sort[t] = sort[t + 1];
                sort[t + 1] = temp;
            }
        }
    }
    for (int i = 0; i < 100; i++) {
        InStack(&sorted, sort[i]);
    }
    printf("\nПосле сортировки:\n");
    while (sorted->next != NULL) {
        printf("%c", OutStack(&sorted));
    }
    temp = spisok;
    for (int i = 0; i < CountLists; i++) {
        list* ending = temp;
        temp = temp->next;
        free(ending);;
    }
    printf("\n\nCompleted\n");

    return 0;
}