#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "Tour.h"
#define TSIZE 128
#define TS 256


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


typedef struct Date {
	int day;
	int month;
} Date;


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

// reading file
bool clearInput();
bool checkNumberInput(int nextStep, int len);
List* readFile();
void SaveFile(List* list);

void AddTour(List* list, Tour* tour);
void DeleteTour(List* list, int i);

void AddRoute(RouteList* list, char* s);
void AddPeople(Collective* list, char* name, int id, int profit);
void AddNecService(NecessaryServicesList* list, char* service);
void AddUnnecService(UnnecessaryServicesList* list, char* service, int cost);
void DeleteUnnecService(UnnecessaryServicesList* list, int i);

void PrintTours(List* list);
void PrintTour(Tour* tour, int i);
Tour* ChooseEditTour(List* list, int* numberEdit);
void EditTour(Tour* tour);
void UpdateTourCost(Tour* tour);
Tour* CreateMyTour(ListOfNecessaryServicesList* list_necser);

void SmartPrintfChar2(char* message, char s[]);
char* SmartPrintfChar(char* message);
int* SmartPrintfInt(char* message, int len);

ListOfNecessaryServices* FindListOfNecessaryServices(ListOfNecessaryServicesList* list, int j);
void freeMemTour(Tour* tour);