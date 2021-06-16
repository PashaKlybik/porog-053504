#include <conio.h>
#include <locale.h>
#include <stdio.h>

int main()
{
	setlocale(LC_ALL, "rus");
	char str[128], ch;
	printf("Введите строку: \n");
	int i = 0;
	int brackets = 0;
	while ((ch = getchar()) != '\n')
	{
		if (ch == '(')
		{
			brackets++;
			str[i] = ch;
			i++;
			continue;
		}
		if (ch == ')')
		{
			brackets--;
			str[i] = ch;
			i++;
			continue;
		}
		if (brackets > 0)
		{
			continue;
		}
		str[i] = ch;
		i++;
	}
	str[i] = '\0';
	printf("%s\n", str);
	if (brackets > 0)
	{
		printf("У вас не закрыто %d скобок", brackets);
	}
	else if (brackets < 0)
	{
		printf("У вас не открыто %d скобок", brackets * -1);
	}
}
