#define _SRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include"stdlib.h"
#include<math.h>
#include <locale.h>

void Menu()
{
	printf(" --------------------------------Welcome to menu----------------------------\n");
	printf(" 1.---> ���� ��������� ������� ������������\n");
	printf(" 2.---> ���������� ��� ������������\n");
	printf(" 3.---> ����� ��������� ������������\n");
	printf(" 4.---> ����� ������� ������������\n");
	printf(" 5.---> ��������� � ������� ������� ��������� � ��������� ������ ������������ ����������� \n");
	printf(" 6.---> ���������� � ������ � ������ ���������\n");
	printf(" 7.---> ����� �� ���������\n");
}

void Information()
{
	printf("���������� �� ������ ���������:\n������ ������� , ������� 1 ����� ���������� ����, ������������� ���� , ������ 053504\n");
}

int  main()
{
	double a, b, c, p;
	double x3, x1, x2, y3, y1, y2;
	int zn = 0;
	int m = 1;
	setlocale(LC_ALL, "Rus");

	while (zn != 7)
	{
		Menu();
		scanf_s("%d", &zn);
		switch (zn)
		{
		case 1:
			
			while (m) {
				
				printf("������� ���������� ������ ������������:\n");
				printf("x1=");
				scanf_s("%lf", &x1);
				printf("y1=");
				scanf_s("%lf", &y1);
				printf("\nx2=");
				scanf_s("%lf", &x2);
				printf("y2=");
				scanf_s("%lf", &y2);
				printf("\nx3=");
				scanf_s("%lf", &x3);
				printf("y3=");
				scanf_s("%lf", &y3);
				a = sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));
				b = sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3));
				c = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));

				if (a + b > c && a + c > b && c + b > a) {
					m = 0;
					printf("�����������  ����������!\n");

				}
				else
				{
					printf("������������ �� ����������!���������� ������ ���������� ������ ��� ���\n");
				}

			}break;

		case 2:
			printf("������ ������:\n");
			printf("a=%lf\n", a);
			printf("b=%lf\n", b);
			printf("c=%lf\n", c);
			if (a == b == c) printf("����������� ��������������\n");

			else if (round(a * a) == (b * b) + (c * c) || round(b * b) == (a * a) + (c * c) || round(c * c) == (b * b) + (a * a)) printf("����������� �������������\n");
			
			else if(a!=b && b!=c) printf("����������� ������������� ����\n"); 
			if ((a == b && a != c) || (a == c && a != b) || (c == b && b != a)) printf("����������� ��������������\n"); break;


		case 3:
			printf("�������� ������������ ����� %lg\n", p = a + c + b); break;
		case 4:
			if (a == b == c) printf("�������  ��������������� ������������ ����� %lg\n", (sqrt(3.0) * pow(a, 2)) / 4);
			else if (a * a == (b * b) + (c * c) || b * b == (a * a) + (c * c) || c * c == (b * b) + (a * a))
			{
				if (a > b && a > c) printf("�������  �������������� ������������ ����� %lg\n", (b * c) / 2);
				else if (b > a && b > c) printf("�������  �������������� ������������ ����� %lg\n", (a * c) / 2);
				else printf("�������  �������������� ������������ ����� %lg\n", (a * b) / 2);
			}
			else if ((a == b && a != c) || (a == c && a != b) || (c == b && b != a))
			{
				if (a == b) printf("�������  ��������������� ������������ ����� %lg\n", ((b * b - (c / 2) * (c / 2)) * c) / 2);
				else if (a == c) printf("�������  ��������������� ������������ ����� %lg\n", ((c * c - (b / 2) * (b / 2)) * b) / 2);
				else if (b==c) printf("�������  ��������������� ������������ ����� %lg\n", ((b * b - (a / 2) * (a / 2)) * a) / 2);
			}
			else  printf("������� ������������ ������������� ���� ����� %lg\n", sqrt((p / 2) * (p / 2 - a) * (p / 2 - c) * (p / 2 - b))); break;
		case 5:
			printf("������ ��������� � ��������� �����������:\n");
			if (a == b == c) printf("%lg\t%lg\n", a / 1.73, a / 3.46);
			else if (a * a == (b * b) + (c * c) || b * b == (a * a) + (c * c) || c * c == (b * b) + (a * a))
			{
				if (a > b && a > c) printf(" %lg\t%lg\n", a / 2, (b + c - a) / 2);
				else if (b > a && b > c) printf(" %lg\t%lg\n", b / 2, (c + a - b) / 2);
				else printf(" %lg\t%lg\n", c / 2, (a + b - c) / 2);
			}
			else if ((a == b && a != c) || (a == c && a != b) || (c == b && b != a))
			{
				if (a == b) printf(" %lg\t%lg\n", a * a / sqrt(4 * a * a - c * c), (((b * b - (c / 2) * (c / 2)) * c) / 2) / (p / 2));
				else if (a == c) printf(" %lg\t%lg\n", a * a / sqrt(4 * a * a - b * b), (((c * c - (b / 2) * (b / 2)) * b) / 2) / (p / 2));
				else printf(" %lg\t%lg\n", b * b / sqrt(4 * b * b - a * a), (((b * b - (a / 2) * (a / 2)) * a) / 2) / (p / 2));
			}
			else printf(" %lg\t%lg\n", a * b * c / (4 * sqrt((p / 2) * (p / 2 - a) * (p / 2 - c) * (p / 2 - b))), sqrt((p / 2) * (p / 2 - a) * (p / 2 - c) * (p / 2 - b)) / (p / 2)); break;
		case 6:
			Information(); break;
		case 7: return 0;
		default:printf("������������ ���� , ���������� ��� ���!\n");
		}
	}

	return 0;
}
