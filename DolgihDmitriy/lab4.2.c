
#define _CRT_SECURE_NO_WARNINGS
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
	char str[80], ch;
	FILE* fp;
	fp = fopen("DATA.txt", "r");

	while (!feof(fp))
	{
		char d;
		fscanf_s(fp, "%c", &ch);
		
		if (i == 0)
		{
			str[i] = toupper(ch);
			i++;
			continue;
		}
		else if (str[i - 1] == '.')
		{
			str[i] = toupper(ch);
			i++;
		}
		else if (str[i - 1] == ' ' && ch == ' ')
		{


		}
		else
		{
			str[i] = tolower(ch);
			i++;
		}
	}
	str[i] = '\0';
	
	
	puts(str);


	return 0;
}