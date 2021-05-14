#include <stdio.h>
#include <malloc.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

struct Queue {
    struct Node* front;
    struct Node* rear;
};

struct DoublyLinkedList {
    struct Node* front;
    struct Node* rear;
};

void pushToQueue(struct Queue* q, int number);
void pushToList(struct DoublyLinkedList* list, struct Queue* queue1, struct Queue* queue2);
void sortFromLower(struct DoublyLinkedList* list);
void sortFromHigher(struct DoublyLinkedList* list);
void output(struct DoublyLinkedList list);

int main() {
    //create 2 q objects
    struct Queue queue1, queue2;
    queue1.rear = queue1.front = queue2.rear = queue2.front = NULL;

    //filling the first q
    pushToQueue(&queue1, 12);
    pushToQueue(&queue1, 10);
    pushToQueue(&queue1, 8);
    pushToQueue(&queue1, 6);

    //filling the second q
    pushToQueue(&queue2, -9);
    pushToQueue(&queue2, -5);
    pushToQueue(&queue2, -2);
    pushToQueue(&queue2, -1);
    pushToQueue(&queue2, 6);
    pushToQueue(&queue2, 9);

    //create my list
    struct DoublyLinkedList list;
    list.rear = list.front = NULL;
    pushToList(&list, &queue1, &queue2);

    //sort it and output
    sortFromLower(&list);
    printf("\nYour queue in the ascending order: ");
    output(list);

    sortFromHigher(&list);
    printf("\nYour queue in descending order: ");
    output(list);

    return 0;
}

void pushToQueue(struct Queue* q, int number) {
    Node* tmp = (Node*)malloc(sizeof(Node));
    tmp->data = number;
    tmp->next = tmp->prev = NULL;
    if (q->front == NULL && q->rear == NULL) {
        q->front = q->rear = tmp;
    } else {
        q->rear->next = tmp;
        q->rear->next->prev = q->rear;
        q->rear = tmp;
    }

}

void pushToList(struct DoublyLinkedList* list, struct Queue* queue1, struct Queue* queue2) {
    struct Node* tmp1 = queue1->front;
    struct Node* tmp2 = queue2->front;

    while (tmp1 != NULL) {
        if (list->front == NULL && list->rear == NULL) {
            list->front = list->rear = tmp1;
        } else {
            list->rear->next = tmp1;
            list->rear->next->prev = list->rear;
            list->rear = tmp1;
        }
        tmp1 = tmp1->next;
    }
    while (tmp2 != NULL) {
        list->rear->next = tmp2;
        list->rear->next->prev = list->rear;
        list->rear = tmp2;
        tmp2 = tmp2->next;
    }
}

void sortFromLower(struct DoublyLinkedList* list) {
    struct Node* tmp;
    struct Node* check = NULL;
    int swapped;
    do {
        tmp = list->front;
        swapped = 0;
        while (tmp->next != check) {
            if (tmp->data > tmp->next->data) {
                int t = tmp->data;
                tmp->data = tmp->next->data;
                tmp->next->data = t;
                swapped = 1;
            }
            tmp = tmp->next;
        }
    } while (swapped);
}

void sortFromHigher(struct DoublyLinkedList* list) {
    struct Node* tmp;
    struct Node* check = NULL;
    int swapped;
    do {
        tmp = list->front;
        swapped = 0;
        while (tmp->next != check) {
            if (tmp->data < tmp->next->data) {
                int t = tmp->data;
                tmp->data = tmp->next->data;
                tmp->next->data = t;
                swapped = 1;
            }
            tmp = tmp->next;
        }
    } while (swapped);
}

void output(struct DoublyLinkedList list) {
    struct Node* tmp = list.front;
    while (tmp != NULL) {
        printf("%d  ", tmp->data);
        tmp = tmp->next;
    }
}
