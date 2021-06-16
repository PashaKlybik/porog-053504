#include "Routes.h"

void AddRoute (RouteList* list, char* s) {
    Route* node = (Route*)malloc(sizeof(Route));
    strcpy(node->place, s);
    node->next = NULL;
    node->prev = NULL;
    if (!list->head) { list->head = node; list->tail = node; }
    else {
        list->tail->next = node;
        node->prev = list->tail;
        list->tail = node;
    }
    list->amount++;
}

