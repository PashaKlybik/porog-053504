#include <stdio.h>
#include <locale.h>
#include <string.h>

char* IntToStr(char *str, unsigned long long num)
{
	char tmpstr[4096] = "";
	do
	{
		char ch;
		ch = '0' + (num % 10);
		strncat_s(tmpstr, sizeof(tmpstr), &ch, sizeof(ch));
		num -= num % 10;
		num /= 10;
	} while (num != 0);
	for (int i = 0; i < (int)strlen(tmpstr); i++)
	{
		str[i] = tmpstr[(int)strlen(tmpstr) - i - 1];
	}
	return str;
}

int main()
{
	setlocale(0,"Rus");
	unsigned long long number;
	unsigned long long lastF = 0, F = 1, Fn;
	printf("Введите номер цифры последовательности: ");
	scanf_s("%llu", &number);
	char str[4096] = "";
	while(strlen(str) < number - 1)
	{
		char strNumber[32] = "";
		IntToStr(strNumber, F);
		strncat_s(str, sizeof(str), strNumber, strlen(strNumber));
		Fn = F + lastF;
		lastF = F;
		F = Fn;
	}
	printf("\nПоследовательность: %s", str);
	printf("\n%llu цифра последовательности = %c", number, str[number - 1]);
	printf("\nПоследний член: %llu", lastF);
}
