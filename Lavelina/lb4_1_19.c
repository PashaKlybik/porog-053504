//(������� 19)������� ����.����� ����� � ��� ������������������ �� 1 �� 8
//��������, �� ���������� ��������.�������� n ���� s1, ..., sn.
//����� �� �� ����������� ���, ����� ���������� ��������, �
//������� ������ ����� ������� ����� si ��������� � ��������� ������
//����������� �����, � ��������� ����� ���������� ����� ��������� �
//������ ������ ������� ����� ? � ������� ������ ������� ��� n ����
//��� ����������.���� ����� ������������ ��������, �� �������
//������� ����.
#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include <stdlib.h>
#include <string.h>
#define N 5

int my_strlen(char* c_str)
{
	int count = 0;
	while (*c_str++) ++count;
	return count;
}

int main()
{
	//  "element", "open", "kengoo", "name", "tick"     // ��� �������� ����� �������� ����� ����� ����� ���������� �� �����������
	
	int n;
	printf("enter 5 words: ");
	//scanf("%d", &n);
	char a[256];
	char* words[256];
	char* str;
	gets_s(a, 255);
	str = strtok(a, " ");
	int k = 0;
	while (str != NULL)
	{
		words[k] = str;
		k++;
		str = strtok(NULL, " ");
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			int en = my_strlen((words[i])) - 1;
			if (words[j][0] == words[i][en])
			{
				char* temp = words[i + 1];
				words[i + 1] = words[j];
				words[j] = temp;
				break;
			}
			else if (words[j][0] != words[i][en] && i + 1 >= N)
			{
				printf("\nIt is not possible to create a chain according to the condition\n");
				return 0;
			}
		}
	printf("Words arter sort: ");
	for (int q = 1; words[q] != NULL; q++)
		printf("%s ", words[q]);
	printf("\n");

	return 0;
}