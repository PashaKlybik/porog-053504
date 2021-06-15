#include "Services.h"

void AddNecService(NecessaryServicesList* list, char* service) {
    NecessaryServices* node = (NecessaryServices*)malloc(sizeof(NecessaryServices));
    strcpy(node->service, service);
    node->next = NULL;
    node->prev = NULL;
    if (!list->head) { list->head = node; list->tail = node; }
    else {
        list->tail->next = node;
        node->prev = list->tail;
        list->tail = node;
    }
}

void AddUnnecService(UnnecessaryServicesList* list, char* service, int cost) {
    UnnecessaryServices* node = (UnnecessaryServices*)malloc(sizeof(UnnecessaryServices));
    strcpy(node->service, service);
    node->cost = cost;
    node->next = NULL;
    node->prev = NULL;
    if (!list->head) { list->head = node; list->tail = node; }
    else {
        list->tail->next = node;
        node->prev = list->tail;
        list->tail = node;
    }
}

void DeleteUnnecService(UnnecessaryServicesList* list, int i) {
    if (list->head == NULL) return;
    UnnecessaryServices* current = list->head;
    int j = 1;
    while (j != i && current) {
        current = current->next;
        j++;
    }
    if (current->prev != NULL)
        current->prev->next = current->next;
    if (current->next != NULL)
        current->next->prev = current->prev;

    if (current->prev == NULL)
        list->head = current->next;
    if (current->next == NULL)
        list->tail = current->prev;
    free(current);
}

ListOfNecessaryServices* FindListOfNecessaryServices(ListOfNecessaryServicesList* list, int j) {
    ListOfNecessaryServices* current = list->head;
    int i = 1;
    while (i != j) {
        current = current->next;
        i++;
    }
    return current;
}


int PrintListNecSer(ListOfNecessaryServicesList* list) {
    ListOfNecessaryServices* current = list->head;
    printf("List of available necessary services: \n");
    int i = 0;
    while (current) {
        printf("%d. %s (%d)\n", ++i, current->service, current->cost);
        current = current->next;
    }
    return i;
}


