#pragma once

#include "time.h"
#include "stdio.h"
#include "windows.h"

typedef struct Account
{
	int ID;
	char* name;
	double sum;
	double percentage;
	time_t opened;
	int type; // 1 - ���� �� ������������� (������������ ����� ����� ������, ����� �������)
			  // 2 - ���������� (������������ ����� ����� ������ ������ ����� ������������ �������� �������) 
	int months; // �������� ��� ����������� �����
	char* operations; // �������� � ������ ���������
	int isChosenForTransaction;

} Account;

char* TimeToStr(time_t time) // ������������ time_t � char* 
{
	struct tm* date; // ��������� � ������������ ������������ �������
	date = localtime(&time); // ��������� time_t � ���������
	char s[40];
	for (int i = 0; i < 40; i++) s[i] = '\0';
	strftime(s, 40, "%d %B %G", date); // ������� � ������ (������ 13 April 2020)
	char* tmp = (char*)malloc(sizeof(s));
	strcpy(tmp, s); // ������� � char*
	return tmp;
}

int AddMonth(time_t* time) // ���������� ������ ������
{
	struct tm* u = localtime(time);
	u->tm_mon++;
	if (u->tm_mon == 12)
	{
		*time = mktime(u);
		return 1;
	}
	*time = mktime(u);
	return 0;
}
int AddYear(time_t* time) // ���������� ������ ������
{
	struct tm* u = localtime(time);
	u->tm_year++;
	*time = mktime(u);
	return 1;
}

int AddDay(time_t* time) // ���������� ������ ���
{
	struct tm* u = localtime(time);
	u->tm_mday++;
	if (u->tm_mday == 32 && u->tm_mon == 11)
	{
		*time = mktime(u);
		return 1;
	}
	*time = mktime(u);
	return 0;
}

void Print(Account acc)
{
	char* openedStr; // ������, ��� ����� ��������� ��������� ������� ����
	openedStr = TimeToStr(acc.opened);
	if (acc.type == 1)
	{
		printf("ID : %-4d ��� ����� : %-20s  ��� : %-10s  ����� : %-10.2lf  �������� : %-5.2lf  ���� �������� : %-15s", acc.ID, "�� �������������", acc.name, acc.sum, acc.percentage, openedStr);
	}
	else
	{
		printf("ID : %-4d ��� ����� : %-20s  ��� : %-10s  ����� : %-10.2lf  �������� : %-5.2lf  ���� �������� : %-15s  �������� : %d ���.", acc.ID, "����������", acc.name, acc.sum, acc.percentage, openedStr, acc.months);
	}
	printf("\n\n");
}

void Put(Account* acc, double sum) //�������� ������ �� ����
{
	acc->sum += sum;
}

int Withdraw(Account* acc, double sum, time_t currentTime) // ����� ������ �� �����
{
	if (acc->type == 2 && CheckMonths(acc, currentTime) != 1)
		return 0;

	if (sum > acc->sum)
	{
		return 0;
	}
	acc->sum -= sum;
	return 1;
}

int CheckMonths(Account* acc, time_t currentTime)
{
	struct tm* date;
	struct tm date1, date2;
	date = localtime(&(acc->opened));
	date1 = *date;
	date = localtime(&currentTime);
	date2 = *date;
	int months = date2.tm_mon - date1.tm_mon;
	if (months < 0) months *= -1;
	if (months % acc->months == 0) return 1;
	return 0;
}


