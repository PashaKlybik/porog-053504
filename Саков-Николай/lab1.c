#include <stdio.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL,"Rus");
	int number;
	int lastF = 0, F = 1, Fn;
	printf("Введите номер члена последовательности: ");
	scanf_s("%d", &number);
	for (int i = 0; i < number; i++)
	{
		printf("%d ", F);
		Fn = F + lastF;
		lastF = F;
		F = Fn;
	}
	printf("\n%d член последовательности = %d", number, lastF);
}
