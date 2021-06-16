#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>

int SummOfEdge(int size) // Функция подсчета суммы ребер
{
	int sum = size * 6;

	return sum;
} 

float Square(int size) // Функция подсчета площади всех граней
{
	float square = ((pow(size, 2) * sqrt(3)) / 4);
	
	return square;
}

float Volume(int size) // Функция подсчета объема 
{
	float volume = ((pow(size, 3) * sqrt(2)) / 12);

	return volume;
}

float Height(int size)
{
	float height = (sqrt(6) / 3) * size;

	return height;
} // Функция подсчета высоты

float Radius(int size) // Функция подсчета радиуса вписанного шара
{
	float radius = size / (2 * sqrt(6));

	return radius;
}

void AuthorName() // Информация о версии и авторе
{
	printf("\n\n=============================================\n");
	printf("Создатель: Зикунов Глеб Андреевич, гр. 053504\nВерсия: 0.0.1\n");
	printf("=============================================\n\n");
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int SizeOfEdge = 0;
	int input = 0;
	while (input != 8)
	{

		printf("\nВыберите пункт меню:"
			"\n1 Ввод длины ребра тетраэдра."
			"\n2 Вывод общей длины всех рёбер тетраэдра."
			"\n3 Вывод площади всех граней тетраэдра."
			"\n4 Вывод объема тетраэдра."
			"\n5 Вывод высоты тетраэдра."
			"\n6 Вывод радиуса вписанного шара."
			"\n7 Информация о версии и авторе программы."
			"\n8 Выход из программы.\n\n");

		scanf("%d", &input);

		switch (input)
		{
			case 1:
			{
				printf("\nВведите длину ребра тетраэдра: ");
				scanf("%d", &SizeOfEdge);
				if (SizeOfEdge <= 0)
				{
					printf("\nНеправильный ввод. Повторите попытку.\n");
				}
				break;
			}

			case 2:
			{
				int Sum = SummOfEdge(SizeOfEdge);
				printf("\nОбщая длина рёбер тетраэдра: %d\n", Sum);
				break;
			}

			case 3:
			{
				float square = Square(SizeOfEdge);
				printf("\nПлощадь всех граней тетраэдра: %f\n", square);
				break;
			}

			case 4:
			{
				float volume = Volume(SizeOfEdge);
				printf("\nОбъём тетраэдра: %f\n", volume);
				break;
			}

			case 5:
			{
				float height = Height(SizeOfEdge);
				printf("\nВысота тетраэдра: %f\n", height);
				break;
			}

			case 6:
			{
				float radius = Radius(SizeOfEdge);
				printf("\nРадиус вписанного шара: %f\n", radius);
				break;
			}

			case 7:
			{
				AuthorName();
				break;
			}

			case 8:
			{
				return 0;
			}

			default:
			{
				printf("\nНеправильный ввод. Повторите попытку.\n");
				break;
			}
		}

	}

	return 0;
}
