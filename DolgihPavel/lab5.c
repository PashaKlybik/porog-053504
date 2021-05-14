#include<stdio.h>
#include<stdlib.h>

#define STACK_OVERFLOW  -100
#define STACK_UNDERFLOW -101
#define OUT_OF_MEMORY   -102

typedef int T;
typedef struct Node_tag {
    T value;
    struct Node_tag* next;
} Node_t;


void push(Node_t** head, T value) {
    Node_t* tmp = malloc(sizeof(Node_t));
    if (tmp == NULL) {
        exit(STACK_OVERFLOW);
        // printf("Error push\n");
    }
    tmp->next = *head;
    tmp->value = value;
    *head = tmp;
}


Node_t* pop(Node_t** head) {
    Node_t* out;
    if ((*head) == NULL) {
        exit(STACK_UNDERFLOW);
        //printf("Error pop\n");
    }
    out = *head;
    *head = (*head)->next;
    return out;
}

T peek(const Node_t* head) {
    if (head == NULL) {
        exit(STACK_UNDERFLOW);
    }
    return head->value;
}


void printStack(const Node_t* head) {
    if (head == NULL) {
        exit(STACK_UNDERFLOW);
        //printf("Error print\n");
    }
    printf(">");
    while (head) {
        printf("%d ", head->value);
        head = head->next;
    }
}

void clearStack(Node_t** head) {
    if ((*head) == NULL) {
        exit(STACK_UNDERFLOW);
    }
    Node_t* prev = NULL;
    while ((*head)->next) {
        prev = (*head);
        (*head) = (*head)->next;
        free(prev);
    }

    free(*head);
    (*head) = NULL;

}

Node_t* copyStack(Node_t** head) {
    Node_t* stack2 = NULL;
    Node_t* temp = NULL;
    Node_t* t;

    if ((*head) == NULL)
    {
        exit(STACK_UNDERFLOW);
    }

    while (*head)
    {
        t = pop(head);
        push(&temp, t->value);
        free(t);

    }

    while (temp)
    {
        t = pop(&temp);
        push(head, t->value);
        push(&stack2, t->value);
        free(t);
    }

    return stack2;
}


int main() {

    Node_t* stack1 = NULL;
    Node_t* stack2 = NULL;
    for (int i = 0; i < 10; i++)
    {
        push(&stack1, i);
    }

    stack2 = copyStack(&stack1);
    printf("First stack:");
    printStack(stack1);
    printf("Copied stack:");
    printStack(stack2);
    clearStack(&stack1);
    clearStack(&stack2);

    _getch();
    return 0;
}