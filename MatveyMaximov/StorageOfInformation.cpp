#include "StorageOfInformation.h"

void AddParts(List* (&list), char _Author[N], char _Name[N], char _Requisities[N], int _CountOfTheCopies, double _PriceOfAcceptance, double _PriceOfSale) {
	Data* p = (Data*)malloc(sizeof(Data));
	int j = 0;
	while (_Author[j] != '\n') {
		p->_parts.Author[j] = _Author[j];
		j++;
	}
	p->_parts.Author[j] = '\0';
	j = 0;
	while (_Name[j] != '\n') {
		p->_parts.Name[j] = _Name[j];
		j++;
	}
	p->_parts.Name[j] = '\0';
	j = 0;
	while (_Requisities[j] != '\n') {
		p->_parts.Requisities[j] = _Requisities[j];
		j++;
	}
	p->_parts.Requisities[j] = '\0';
	j = 0;
	p->_parts.CountOfTheCopies = _CountOfTheCopies;
	p->_parts.PriceOfAcceptance = _PriceOfAcceptance;
	p->_parts.PriceOfSale = _PriceOfSale;
	p->next = p->prev = NULL;
	if (list->head == NULL) {
		list->head = list->tail = p;
	}
	else {
		list->tail->next = p;
		p->prev = list->tail;
		list->tail = p;
	}
	list->count++;
}

void ReadingParts(List* (&list)) {
	FILE* fp;
	fp = fopen("C:\\Users\\user\\Desktop\\lab7pre.txt", "r+");
	if (fp == NULL) {
		printf("Cannot open file. \n\n");
		exit(1);
	}
	else {
		printf("File open. \n\n");
		while (fp != NULL) {
			Data* p = (Data*)malloc(sizeof(Data));
			fscanf(fp, "%s", p->_parts.Author);
			fscanf(fp, "%s", p->_parts.Name);
			fscanf(fp, "%s", p->_parts.Requisities);
			fscanf(fp, "%d", &p->_parts.CountOfTheCopies);
			fscanf(fp, "%lf", &p->_parts.PriceOfAcceptance);
			fscanf(fp, "%lf", &p->_parts.PriceOfSale);
			p->next = p->prev = NULL;
			if (list->head == NULL) {
				list->head = list->tail = p;
			}
			else {
				list->tail->next = p;
				p->prev = list->tail;
				list->tail = p;
			}
			list->count++;
			break;
		}
	}
	fclose(fp);
}

void PrintList(List* list) {
	Data* p = list->head;
	printf("\n");
	while (p != NULL) {
		int i = 0;
		while (i < 50) {
			printf("-");
			i++;
		}
		printf("\n\n");
		printf("Author of the book is : %s \n", p->_parts.Author);
		printf("Name of the book is : %s \n", p->_parts.Name);
		printf("Requisities of the book are : %s \n", p->_parts.Requisities);
		printf("Count of the book copies is : %d \n", p->_parts.CountOfTheCopies);
		printf("Price of the book acceptance is : %lf \n", p->_parts.PriceOfAcceptance);
		printf("Total sale price of theese books is : %lf \n", p->_parts.PriceOfSale);
		p = p->next;
	}
}

void SellPartsForOrders(List* (&list), Reporting* (&report), char name[N], int countparts) {
	Data* p = list->head;
	int j = 0;
	char buffer[N];
	while (name[j] != '\n') {
		name[j] = name[j];
		j++;
	}
	name[j] = '\0';
	j = 0;
	strcpy(buffer, name);
	while (strcmp(buffer, p->_parts.Name) != 0) {
		p = p->next;
	}
	if (strcmp(buffer, p->_parts.Name) == 0) {
		Ordering* r = (Ordering*)malloc(sizeof(Ordering));
		p->_parts.CountOfTheCopies -= countparts;
		j = 0;
		while (p->_parts.Name[j] != '\0') {
			r->CurrentName[j] = p->_parts.Name[j];
			j++;
		}
		r->CurrentName[j] = '\0';
		r->CurrentCountOfTheCopies = countparts;
		r->CurrentPrice = (double)(countparts * (p->_parts.PriceOfSale));
		r->next = r->prev = NULL;
		if (report->head == NULL) {
			report->head = report->tail = r;
		}
		else {
			report->tail->next = r;
			r->prev = report->tail;
			report->tail = r;
		}
		report->counter++;
	}
	else {
		printf("No any declaration of theese name");
	}
}

int CountPartsOnStorage(List* list) {
	Data* p = list->head;
	int buf1 = 0;
	while (p != NULL) {
		buf1 += (int)(p->_parts.CountOfTheCopies);
		p = p->next;
	}
	return buf1;
}

double AllPriceOfParts(List* list) {
	Data* p = list->head;
	double buf2 = 0;
	while (p != NULL) {
		buf2 += (double)(p->_parts.PriceOfSale);
		p = p->next;
	}
	return buf2;
}

int CountOfOrders(Reporting* report) {
	return (int)report->counter;
}

int CountOfSoldParts(Reporting* report) {
	Ordering* r = report->head;
	int buf3 = 0;
	while (r != NULL) {
		buf3 += (int)(r->CurrentCountOfTheCopies);
		r = r->next;
	}
	return buf3;
}

double TotalProfit(List* list, Reporting* report) {
	Data* p = list->head;
	Ordering* r = report->head;
	double pre = 0, post = 0, delta = 0;
	while (r != NULL) {
		while (p != NULL) {
			if (strcmp(r->CurrentName, p->_parts.Name) == 0) {
				pre += r->CurrentCountOfTheCopies * p->_parts.PriceOfAcceptance;
				post += r->CurrentCountOfTheCopies * p->_parts.PriceOfSale;
			}
			else {
				p = p->next;
			}
			break;
		}
		r = r->next;
		p = list->head;
	}
	delta = post - pre;
	return delta;
}

void DeleteList(List* (&list)) {
	while (list->head) {
		Data* old_head = list->head;
		list->head = list->head->next;
		free(old_head);
	}
}

void DeleteReport(Reporting* (&report)) {
	while (report->head) {
		Ordering* old_head = report->head;
		report->head = report->head->next;
		free(old_head);
	}
}

void SavingList(List* list) {
	FILE* fp;
	fp = fopen("C:\\Users\\user\\Desktop\\lab7pre.txt", "w");
	if (fp == NULL) {
		printf("Cannot open file. \n\n");
		exit(1);
	}
	else {
		printf("File open. \n\n");
		Data* p = list->head;
		while (p != NULL) {
			fprintf(fp, "%s\n", p->_parts.Author);
			fprintf(fp, "%s\n", p->_parts.Name);
			fprintf(fp, "%s\n", p->_parts.Requisities);
			fprintf(fp, "%d\n", p->_parts.CountOfTheCopies);
			fprintf(fp, "%lf\n", p->_parts.PriceOfAcceptance);
			fprintf(fp, "%lf", p->_parts.PriceOfSale);
			p = p->next;
		}
	}
	fclose(fp);
}