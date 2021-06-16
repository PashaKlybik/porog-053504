#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <Windows.h>
#include <clocale>
#include <ctime>
#pragma warning(disable: 4996)
#define N 100

using namespace std;

// Прием партии книг на склад
typedef struct parts{
	char Author[N];
	char Name[N];
	char Requisities[N];
	int CountOfTheCopies;
	double PriceOfAcceptance;
	double PriceOfSale;
}Parts;

// Оформление заказа
typedef struct ordering {
	char CurrentName[N];
	int CurrentCountOfTheCopies;
	double CurrentPrice;
	ordering* next;
	ordering* prev;
}Ordering;

// Отчетность
typedef struct reporting {
	int counter;
	Ordering _ordering;
	Ordering* head;
	Ordering* tail;
}Reporting;

// Вся структура данных
typedef struct data {
	Parts _parts;
	data* next;
	data* prev;
}Data;

// Функции для работы со стуктурами
typedef struct list {
	int count;
	Data* head;
	Data* tail;
}List;

void AddParts(List* (&list), char _Author[N], char _Name[N], char _Requisities[N], int _CountOfTheCopies, double _PriceOfAcceptance, double _PriceOfSale);

void ReadingParts(List* (&list));

void PrintList(List* list);

void SellPartsForOrders(List* (&list), Reporting* (&report), char name[N], int countparts);

int CountPartsOnStorage(List* list);

double AllPriceOfParts(List* list);

int CountOfOrders(Reporting* report);

int CountOfSoldParts(Reporting* report);

double TotalProfit(List* list, Reporting* report);

void DeleteList(List* (&list));

void DeleteReport(Reporting* (&report));

void SavingList(List* list);


