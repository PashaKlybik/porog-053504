#ifndef LAB7_ROUTES_H
#define LAB7_ROUTES_H
#define TSIZE 128
#include <string.h>
#include <malloc.h>

typedef struct Route {
    char place[TSIZE];
    struct Route* next;
    struct Route* prev;
} Route;

typedef struct RouteList {
    int amount;
    Route* head;
    Route* tail;
} RouteList;


void AddRoute(RouteList* list, char* s);

#endif //LAB7_ROUTES_H
