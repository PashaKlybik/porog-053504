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
	puts("Введите строку символов:");
	char str[80], ch;

	while ((ch = getchar()) != '\n')
	{
		if (ch == 'ы' && (str[i - 1] == 'ж' || str[i - 1] == 'ш' || str[i - 1] == 'Ж' || str[i - 1] == 'Ш')) {
			str[i] = 'и'; i++; mistakes++;
		}
		else if (ch == 'я' && (str[i - 1] == 'ч' || str[i - 1] == 'щ' ||  str[i - 1] == 'Щ' || str[i - 1] == 'Ч')) {
			str[i] = 'а'; i++; mistakes++;
		}
		else if (ch == 'ю' && (str[i - 1] == 'ч' || str[i - 1] == 'щ' || str[i - 1] == 'Щ' || str[i - 1] == 'Ч')) {
			str[i] = 'у'; i++; mistakes++;
		}
		else { str[i] = ch; i++; }
	}
	str[i] = '\0';

	if (mistakes == 1)
	{
		printf("У вас 1 ошибка\n");
		puts(str);
	}
	else if (mistakes == 2 || mistakes == 3 || mistakes == 4)
	{
		printf("У вас %d ошибки\n", mistakes);
		puts(str);
	}
	else if (mistakes == 0) {
		puts("У вас нет ошибок!"); puts(str);
	}
	else
	{
		printf("У вас %d ошибок\n", mistakes);
		puts(str);
	}
	return 0;
}