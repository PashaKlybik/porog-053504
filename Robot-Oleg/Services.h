#ifndef LAB7_SERVICES_H
#define LAB7_SERVICES_H
#define TSIZE 128
#include <malloc.h>
#include <string.h>

typedef struct ListOfNecessaryServices {
    char service[TSIZE];
    int cost;
    struct ListOfNecessaryServices* next;
    struct ListOfNecessaryServices* prev;
} ListOfNecessaryServices;

typedef struct ListOfNecessaryServicesList {
    ListOfNecessaryServices* head;
    ListOfNecessaryServices* tail;
} ListOfNecessaryServicesList;

typedef struct NecessaryServices {
    char service[TSIZE];
    struct NecessaryServices* next;
    struct NecessaryServices* prev;
} NecessaryServices;

typedef struct NecessaryServicesList {
    int cost;
    NecessaryServices* head;
    NecessaryServices* tail;
} NecessaryServicesList;


typedef struct UnnecessaryServices {
    char service[TSIZE];
    int cost;
    struct UnnecessaryServices* next;
    struct UnnecessaryServices* prev;
} UnnecessaryServices;

typedef struct UnnecessaryServicesList {
    UnnecessaryServices* head;
    UnnecessaryServices* tail;
} UnnecessaryServicesList;

void AddNecService(NecessaryServicesList* list, char* service);
void AddUnnecService(UnnecessaryServicesList* list, char* service, int cost);
void DeleteUnnecService(UnnecessaryServicesList* list, int i);
ListOfNecessaryServices* FindListOfNecessaryServices(ListOfNecessaryServicesList* list, int j);
int PrintListNecSer(ListOfNecessaryServicesList* list);


#endif //LAB7_SERVICES_H
