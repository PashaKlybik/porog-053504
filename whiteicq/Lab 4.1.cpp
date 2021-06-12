#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void editString(char* str) // Найти слова где первая и последняя буквы равны и напечатать все первые вхождения
{
	char chars[26];
	for (int i = 'a', pos = 0; i <= 'z'; i++, pos++)
	{
		chars[pos] = i;
	}

	char* tmp = (char*)malloc(strlen(str) + 1);
	int pos = 0;
	for (int i = 0; i <= strlen(str); i++)
	{
		if (str[i] == ' ' || str[i] == '\0')
		{
			tmp[pos] = '\0';
			if (tmp[0] == tmp[strlen(tmp) - 1])
				displayByTask(tmp, chars);
			pos = 0;
		}
		else
		{
			tmp[pos++] = str[i];
		}
	}
	free(tmp);
}
int checkExisting(char s, char* arr) // Проверить, первое ли вхождение буквы
{
	for (int i = 0; i < 26; i++)
	{
		if (arr[i] == s)
		{
			arr[i] = '\0';
			return 1;
		}
	}
	return 0;
}

void displayByTask(char* str, char* chars) // Отобразить все первые вхождения
{

	char* res = (char*)malloc(strlen(str) + 1);
	int pos = 0;

	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == ' ')
		{
			res[pos++] = ' ';
			continue;
		}
		if (checkExisting(str[i], chars))
		{
			res[pos++] = str[i];
		}
	}
	res[pos] = '\0';
	printf("%s ", res);
	free(res);
}

int main()
{
	char input[101];
	printf("Write text\n");
	gets_s(input, 100);

	editString(input);
	return 0;
}
