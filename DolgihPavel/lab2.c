#include <stdio.h>
#include <locale.h>
#include <string.h>

void recommendations(int n, int *KSISball, int *FREball, int *IEFball, int *FITIYball, int *FKPball)
{
	int KSIScount = 0,FREcount=0,IEFcount=0,FITIYcount=0,FKPcount=0;
	printf("��� �������� ����:%d\n", n);
	for(int i=0;i<4;i++)
	{
		if (n >= KSISball[i])
			KSIScount++;
	}
	switch(KSIScount)
	{
	case 1:printf("�� ������ ��������� �� 1 ������������� �����!\n");
		break;
	case 2:printf("�� ������ ��������� �� 2 ������������� �����!\n");
		break;
	case 3:printf("�� ������ ��������� �� 3 ������������� �����!\n");
		break;
	case 4:printf("�� ������ ��������� �� ��� ������������� �����!\n");
		break;
	default:break;
	}

	for (int i = 0; i < 6; i++)
	{
		if (n >= FREball[i])
			FREcount++;
	}
	switch (FREcount)
	{
	case 1:printf("�� ������ ��������� �� 1 ������������� ���!\n");
		break;
	case 2:printf("�� ������ ��������� �� 2 ������������� ���!\n");
		break;
	case 3:printf("�� ������ ��������� �� 3 ������������� ���!\n");
		break;
	case 4:printf("�� ������ ��������� �� 4 ������������� ���!\n");
		break;
	case 5:printf("�� ������ ��������� �� 5 �������������� ���!\n");
		break;
	case 6:printf("�� ������ ��������� �� ��� ������������� ���!\n");
		break;

	default:break;
	}

	for (int i = 0; i < 4; i++)
	{
		if (n >= IEFball[i])
			IEFcount++;
	}
	switch (IEFcount)
	{
	case 1:printf("�� ������ ��������� �� 1 ������������� ���!\n");
		break;
	case 2:printf("�� ������ ��������� �� 2 ������������� ���!\n");
		break;
	case 3:printf("�� ������ ��������� �� 3 ������������� ���!\n");
		break;
	case 4:printf("�� ������ ��������� �� ��� ������������� ���!\n");
		break;
	
	default:break;
	}

	for (int i = 0; i < 9; i++)
	{
		if (n >= FKPball[i])
			FKPcount++;
	}
	switch (FKPcount)
	{
	case 1:printf("�� ������ ��������� �� 1 ������������� ���!\n");
		break;
	case 2:printf("�� ������ ��������� �� 2 ������������� ���!\n");
		break;
	case 3:printf("�� ������ ��������� �� 3 ������������� ���!\n");
		break;
	case 4:printf("�� ������ ��������� �� 4 ������������� ���!\n");
		break;
	case 5:printf("�� ������ ��������� �� 5 �������������� ���!\n");
		break;
	case 6:printf("�� ������ ��������� �� 6 �������������� ���!\n");
		break;
	case 7:printf("�� ������ ��������� �� 7 �������������� ���!\n");
		break;
	case 8:printf("�� ������ ��������� �� 8 �������������� ���!\n");
		break;
	case 9:printf("�� ������ ��������� �� ��� ������������� ���!\n");
		break;
	default:break;
	}
	

	for (int i = 0; i < 4; i++)
	{
		if (n >= FITIYball[i])
			FITIYcount++;
	}
	switch (FITIYcount)
	{
	case 1:printf("�� ������ ��������� �� 1 ������������� �����!\n");
		break;
	case 2:printf("�� ������ ��������� �� 2 ������������� �����!\n");
		break;
	case 3:printf("�� ������ ��������� �� 3 ������������� �����!\n");
		break;
	case 4:printf("�� ������ ��������� �� ��� ������������� �����!\n");
		break;

	default:break;
	}

	if (KSIScount ==0 && FKPcount == 0 && IEFcount == 0 && FITIYcount == 0 && FREcount == 0)
	{
		printf("��� �� ����� ������� ���� �����!\n");
	}
}
struct faculty
{
	
	char *name;
	int  students;
	int  date;
	int  ball[10];
	char *decan;
	char *specialities;
	char *qualification;
};

void showInfo(struct faculty facl)
{
	printf("-----------------------------%s-----------------------------\n", facl.name);
	printf("���������� ���������:%d\n", facl.students);
	printf("���� �����������:%d\n", facl.date);
	printf("����� ����������:%s\n", facl.decan);
	printf("������������:\n%s\n", facl.qualification);
	printf("�������������:\t\t\t\t\t\t\t\t ��������� ���:\n%s", facl.specialities);
	
}

int main()
{
	setlocale(LC_ALL, "Rus");

	int n = 0, avg = 0, language = 0, phisics = 0, math = 0;
	struct faculty RE, KSIS, ITIY, KP, IEF;
	RE.name = "���";
	RE.ball[0] = 281; RE.ball[1] = 260; RE.ball[2] = 271; RE.ball[3] = 282; RE.ball[4] = 235; RE.ball[5] = 248;
	RE.students = 1200;
	RE.date = 1964;
	RE.decan = "���������� ��������� ����������";
	RE.qualification = "1.������� ����������� �������\n2.������� �� ����������������\n3.������� �� ����������� ��������\n4.�������-�����������";
	RE.specialities = "1.�����- � ��������������� ���������� � �������\t\t\t\t\t281\n2.�������������� � ������������� � �����������\t\t\t\t\t260\n3.������������ (��������������� ���������������� ��������)\t\t\t271\n4.���������������� ������ ����������\t\t\t\t\t\t282\n5.����������� � �������������-����������� ������� ���������� ���������\t\t235\n6.����������������\t\t\t\t\t\t\t\t248\n";
	KSIS.name = "�����";
	KSIS.ball[0] = 327; KSIS.ball[1] = 358; KSIS.ball[2] = 352; KSIS.ball[3] = 318;
	KSIS.students = 2000;
	KSIS.date = 1964;
	KSIS.decan = "������� ������� ����������";
	KSIS.qualification = "1.�������-�����������\n2.�������-��������� �����������\n3.�������-�������������.";
	KSIS.specialities = "1.�������������� ������, ������� � ����\t\t\t\t\t\t327\n2.����������� ����������� �������������� ����������\t\t\t\t358\n3.����������� � ���������� ����������������\t\t\t\t\t352\n4.����������� �������������� ��������\t\t\t\t\t\t318\n";
	ITIY.students = 1900;
	ITIY.date = 1964;
	ITIY.name = "�����";
	ITIY.ball[0] = 347; ITIY.ball[1] = 337; ITIY.ball[2] = 317; ITIY.ball[3] = 301; ITIY.ball[4] = 365;
	ITIY.decan = "����� ������ �������";
	ITIY.qualification = "1.������� �� �������������� ����������� � ����������\n2.������� �� �������������� �����������\n3.�������-�������������\n4.������� �� ����������������\n5.�������-��������� �����������-������������";
	ITIY.specialities = "1.������������������ ������� ��������� ����������\t\t\t\t347\n2.������������� ���������\t\t\t\t\t\t\t337\n3.�������������� ���������� � ���������� � ����������� ��������\t\t\t317\n4.������������ �����������\t\t\t\t\t\t\t301\n5.�������������� ������� � ���������� (� ������� ���������)\t\t\t365\n";
	KP.students = 1400;
	KP.ball[0] = 312; KP.ball[1] = 308; KP.ball[2] = 331; KP.ball[3] = 307, KP.ball[4] = 309; KP.ball[5] = 336; KP.ball[6] = 314; KP.ball[7] = 329; KP.ball[8] = 351;
	KP.name = "���";
	KP.decan = "����������� ������� ����������";
	KP.date = 1973;
	KP.qualification = "1.������� �� ����������������\n2.������� ����������� �������\n3.�������-�������������\n4.�������-�������������\n5.������� �� ����������� ��������\n6.�����������.������-��������";
	KP.specialities = "1.�������������� � ������������ ����������-����������� ����������� �������\t312\n2.������������� � ������������ �������������� ���������������� �������\t\t308\n3.��������������� ��������� �������\t\t\t\t\t\t331\n4.����������-�����������  ����������-���������� �������\t\t\t\t307\n5.����������� �����������\t\t\t\t\t\t\t309\n6.���������-��������������� ����������� �������������� ����������\t\t336\n7.����������� ������� ������������\t\t\t\t\t\t314\n8.�������������� ������� � ���������� (� ����������� ������������ ������������)\t329\n9.�������������� ������� � ���������� (� ������-�����������)\t\t\t351\n";
	IEF.name = "���";
	IEF.decan = "������� ����� ��������";
	IEF.date = 1994;
	IEF.ball[0] = 333; IEF.ball[1] = 326; IEF.ball[2] = 366; IEF.ball[3]=363;
	IEF.students = 1300;
	IEF.qualification = "1.�������-�����������-���������\n2.���������-�����������\n3.��������� �����������-��������\n4.����������-�����������";
	IEF.specialities = "1.�������������� ������� � ���������� (� ���������)\t\t\t\t333\n2.�������������� ������� � ���������� (� ���������)\t\t\t\t326\n3.����������� ���������\t\t\t\t\t\t\t\t366\n4.��������� ������������ �������\t\t\t\t\t\t363\n";


	while (n != 7)
	{
	
	
	printf("------------------------------------------����------------------------------------------\n");
	printf("1-����� ���������� � ���������� ����\n");
	printf("2-����� ���������� � ���������� ����\n");
	printf("3-����� ���������� � ���������� ��\n");
	printf("4-����� ���������� � ���������� ���\n");
	printf("5-����� ���������� � ���������� ��\n");
	printf("6-�������� ������������\n");
	printf("7-����� �� ���������\n");
	scanf_s("%d", &n);
	
	
		switch (n)
		{
		case 1:
			showInfo(KSIS);
			break;
		case 2:
			showInfo(ITIY);
			break;
		case 3:
			showInfo(RE);
			break;
		case 4:
			showInfo(IEF);
			break;
		case 5:
			showInfo(KP);
			break;
		case 6:
			do
			{
				printf("������� ��� ���� �� �������� �����:\n");
				scanf_s("%d", &language);
				if (language < 0 || language>100) printf("������.��������� �������!\n");
				
			} while (language < 0 || language>100);
			
			do
			{
				printf("������� ��� ���� �� ������:\n");
				scanf_s("%d", &phisics);
				if (phisics < 0 || phisics>100) printf("������.��������� �������!\n");

			} while (phisics < 0 || phisics>100);

			do
			{
				printf("������� ��� ���� �� ����������:\n");
				scanf_s("%d", &math);
				if (math < 0 || math>100) printf("������.��������� �������!\n");

			} while (math < 0 || math>100);
			
			do
			{
				printf("������� ��� ������� ����:\n");
				scanf_s("%d", &avg);
				if (avg < 0 || avg>100) printf("������.��������� �������!\n");

			} while (avg < 0 || avg>100);
			
			n = avg + language + phisics + math;
			recommendations(n, KSIS.ball, RE.ball, IEF.ball, ITIY.ball, KP.ball);
			break;
		case 7:
			return 0;
		default:
			printf("�������� ��������, ��������� ����!\n");
		}
	}
	
	return 0;
}
