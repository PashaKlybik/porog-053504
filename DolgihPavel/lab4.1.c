#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
int main()
{
	setlocale(LC_ALL, "Rus");
	system("chcp 1251 > nul");
	int i = 0;
	int mistakes = 0;
	puts("������� ������ ��������:");
	char str[80], ch;

	while ((ch = getchar()) != '\n')
	{
		if (ch == '�' && (str[i - 1] == '�' || str[i - 1] == '�' || str[i - 1] == '�' || str[i - 1] == '�')) {
			str[i] = '�'; i++; mistakes++;
		}
		else if (ch == '�' && (str[i - 1] == '�' || str[i - 1] == '�' ||  str[i - 1] == '�' || str[i - 1] == '�')) {
			str[i] = '�'; i++; mistakes++;
		}
		else if (ch == '�' && (str[i - 1] == '�' || str[i - 1] == '�' || str[i - 1] == '�' || str[i - 1] == '�')) {
			str[i] = '�'; i++; mistakes++;
		}
		else { str[i] = ch; i++; }
	}
	str[i] = '\0';

	if (mistakes == 1)
	{
		printf("� ��� 1 ������\n");
		puts(str);
	}
	else if (mistakes == 2 || mistakes == 3 || mistakes == 4)
	{
		printf("� ��� %d ������\n", mistakes);
		puts(str);
	}
	else if (mistakes == 0) {
		puts("� ��� ��� ������!"); puts(str);
	}
	else
	{
		printf("� ��� %d ������\n", mistakes);
		puts(str);
	}
	return 0;
}