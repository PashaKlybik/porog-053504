
#ifndef LAB7_TOUR_H
#define LAB7_TOUR_H
#define TSIZE 128
#define TS 256

#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "Services.h"
#include "Routes.h"
#include "People.h"

typedef struct Date {
    int day;
    int month;
} Date;

typedef struct Tour {
    bool selfTour;
    char country[TSIZE];
    int cost;
    RouteList* route;
    NecessaryServicesList* necSer;
    UnnecessaryServicesList* unnecSer;
    Date dateArrival;
    Date dateDeparture;
    Collective* collective;
    struct Tour* next;
    struct Tour* prev;
} Tour;

typedef struct List {
    int toursAmount;
    Tour* head;
    Tour* tail;
} List;

bool clearInput();
bool checkNumberInput(int nextStep, int len);
List* readFile();
void SaveFile(List* list);

void AddTour(List* list, Tour* tour);
void DeleteTour(List* list, int i);
void PrintTours(List* list);
void PrintTour(Tour* tour, int i);
Tour* ChooseEditTour(List* list, int* numberEdit);
void EditTour(Tour* tour);
void UpdateTourCost(Tour* tour);
Tour* CreateMyTour(ListOfNecessaryServicesList* list_necser);

void SmartPrintfChar2(char* message, char s[]);
char* SmartPrintfChar(char* message);
int* SmartPrintfInt(char* message, int len);

void freeMemTour(Tour* tour);

#endif //LAB7_TOUR_H
