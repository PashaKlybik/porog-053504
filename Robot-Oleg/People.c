#include "People.h"


void AddPeople(Collective* list, char* name, int id, int profit) {
    People* node = (People*)malloc(sizeof(People));
    strcpy(node->name, name);
    node->id = id;
    node->profit = profit;
    node->next = NULL;
    node->prev = NULL;
    if (!list->head) { list->head = node; list->tail = node; }
    else {
        list->tail->next = node;
        node->prev = list->tail;
        list->tail = node;
    }
    list->allPositions--;
    list->peopleAmount++;
}
