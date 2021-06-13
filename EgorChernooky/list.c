#include "list.h"

struct node *node(int data, struct node *next, struct node *prev){
    struct node *n = malloc(sizeof(struct node));
    if (n == NULL) return NULL;
    n->data = data;
    n->next = next;
    n->prev = prev;
    return n;
}

struct list *list(){
    struct list *l = malloc(sizeof(struct list));
    if (l == NULL) return NULL;
    l->size = 0;
    l->head = NULL;
    l->tail = NULL;
    return l;
}

void pushBack(struct list *l, int value){
    if (l->head == NULL){
        l->head = node(value, NULL, NULL);
        if (l->head == NULL) return;
        l->tail = l->head;
        l->size++;
    } else {
        struct node *new_node = node(value, NULL, l->tail);
        if (new_node == NULL) return;
        l->tail->next = new_node;
        l->tail = new_node;
        l->size++;
    }
}

void popBack(struct list *l){
    if (l->head == NULL) return;
    if (l->size == 1){
        free(l->head);
        l->size--;
        l->head = NULL;
        l->tail = NULL;
        return;
    }
    l->tail = l->tail->prev;
    free(l->tail->next);
    l->tail->next = NULL;
    l->size--;
}

void pushFront(struct list *l, int value){
    if (l->head == NULL){
        l->head = node(value, NULL, NULL);
        if (l->head == NULL) return;
        l->tail = l->head;
        l->size++;
    } else {
        struct node *new_node = node(value, l->head, NULL);
        if (new_node == NULL) return;
        l->head->prev = new_node;
        l->head = new_node;
        l->size++;
    }
}

void popFront(struct list *l){
    if (l->head == NULL) return;
    if (l->size == 1){
        free(l->head);
        l->size--;
        l->head = NULL;
        l->tail = NULL;
        return;
    }
    l->head = l->head->next;
    free(l->head->prev);
    l->head->prev = NULL;
    l->size--;
}

void freeList(struct list *l){
    if (l == NULL) return;
    while (l->size) popBack(l);
    free(l);
}
