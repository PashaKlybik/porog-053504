
#ifndef LAB7_PEOPLE_H
#define LAB7_PEOPLE_H
#define TSIZE 128
#include <malloc.h>
#include <string.h>

typedef struct People {
    char name[TSIZE];
    int id;
    int profit;
    struct People* next;
    struct People* prev;
} People;

typedef struct Collective {
    int peopleAmount;
    int allPositions;
    struct People* head;
    struct People* tail;
} Collective;

void AddPeople(Collective* list, char* name, int id, int profit);

#endif //LAB7_PEOPLE_H
