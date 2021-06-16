#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct{
    char data;
    char *next;
}stack;
void push(stack **start, char data){
    stack *temp = (stack*)malloc(sizeof (stack));
    if((*start)->next == NULL){
        (*start)->data = data;
        temp->next = NULL;
        (*start)->next = temp;
    }
    else{
    temp->next = (*start)->next;
    temp->data = (*start)->data;
    (*start)->next = temp;
    (*start)->data = data;
    }
}
char pop(stack **start){
    char temp = (*start)->data;
    stack *t;
    t = (*start)->next;
    (*start)->next = t->next;
    (*start)->data = t->data;
    free(t);
    return temp;
}

typedef struct {
    stack* data;
    struct list *prev;
    struct list *next;
}list;

void add(list** head, stack *data){
    if(((*head)->next == NULL) && ((*head)->prev == NULL) ){
      //  printf("test 1\n");
        (*head)->data = data;
        (*head)->next = (*head);
        (*head)->prev = (*head);
    }
    else{
    list* temp = (list*)malloc(sizeof (list));

        if((*head)->next == (*head)){
           // printf("test 2\n");
            temp->data = (*head)->data;
            temp->next = (*head);
            temp->prev = (*head);
            (*head)->next = temp;
            (*head)->prev = temp;
            (*head)->data = data;
        }
        else{
       //     printf("test 3\n");
            list *t = (*head)->next;
            t->prev = temp;
            temp->next = (*head)->next;
            temp->data = (*head)->data;
            temp->prev = (*head);
            (*head)->data = data;
            (*head)->next = temp;
        }
    }
}
int main()
{
    const int list_s = 10;
    //***************************
    list *cir = (list*)malloc(sizeof (list));
    cir->next = NULL;
    cir->prev = NULL;
    for(int i = 0; i < list_s; i++){
        stack *temp = (stack*)malloc(sizeof (stack));
        temp->next = NULL;
        for(int j = 0; j < 10; j++){
            char data = rand()%26+0x61;
            push(&temp, data);
        }
        add(&cir, temp);
    }

     list *temp = cir;
    for(int i = 0; i < list_s ; i++){
        char arr[10];
        stack *s = temp->data;
        int t = 0;
        while(s->next!=NULL){
            arr [t] = pop(&s);
            t++;
        }
        printf("\n***************\nNot sorted stack:\n");
        for(int m = 0; m < 10; m++){
            printf("%c", arr[m]);
        }
        //bubble sort
        for(int k = 0; k < 10; k++){
            for(int t = 0; t < 9; t++ ){
               if((int)arr[t] > (int)arr[t+1]) {
                   char temp = arr[t];
                   arr[t] = arr[t+1];
                   arr[t+1] = temp;
               }
            }
        }
        //***************
        printf("\nSorted stack:\n");
        for(int m = 0; m < 10; m++){
            printf("%c", arr[m]);
            push(&s, arr[m]);
        }
        printf("\n");
        temp = temp->next;
    }
    //***************************************************
   stack *sorted = (stack*)malloc(sizeof (stack));
   sorted->next = NULL;

   char sort[list_s*10];
    temp = cir;
    stack *t1 = temp->data;
    for(int i = 0, l= 0; i < 10; i++){
        while(t1->next != NULL){

            push(&sorted, pop(&t1));
        }
        temp = temp->next;
        t1 = temp->data;
    }
    int schet = 0;
printf("\nNot sorted stack:\n");
while(sorted->next != NULL){
   sort[schet] = pop(&sorted);
   printf("%c", sort[schet]);
   schet++;
}
    for(int k = 0; k < 100; k++){
        for(int t = 0; t < 99; t++ ){
           if((int)sort[t] < (int)sort[t+1]) {
               char temp = sort[t];
               sort[t] = sort[t+1];
               sort[t+1] = temp;
           }
        }
    }
for(int i = 0; i < 100 ; i++){
    push(&sorted, sort[i]);
}
printf("\nSorted stack:\n");
while (sorted->next!=NULL) {
  printf("%c", pop(&sorted));
}
temp = cir;
for(int i = 0; i < list_s; i++){
    list *gg = temp;
    temp = temp->next;
    free(gg);;
}
printf("\nProverka\n");

//********************************************************
    return 0;
}
