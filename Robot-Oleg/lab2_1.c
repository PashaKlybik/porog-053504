#include <stdio.h>
#include <math.h>



void menu() {
	printf("\n1. Ввод радиуса шара.\n2. Вывод площади поверхности шара.\n3. Вывод объема шара.\n4. Вывод длины ребра вписанного правильного тетраэдра.\n5. Вывод площади сечения, проведенного на расстоянии k от центра шара.\n6. Информация о версии и авторе программы.\n7. Выход из программы.\n");
}



int main() {
	int choise = 0;
	int radius = 1;
	int k = 0;
	while (1){
		menu();
		printf("сделайте выбор: ");
		scanf("%d", &choise);
		switch (choise) {
			case 1:
				printf("введите новый радиус: ");
				scanf("%d", &radius);
				if (radius <= 0) radius = 1;
				printf("новый радиус - %d", radius);
				break;
			case 2:
				printf("площадь поверхности шара - %f", M_PI*pow(radius, 2));

				break;
			case 3:
				printf("объём шара - %f", 4.0/3.0 * M_PI*pow(radius, 3));
				break;
			case 4:
				printf("длина ребра правильного тетраэдера вписанного в шар - %f", pow(6, 1/2)/radius*4);
				break;
			case 5:
				scanf("%d", &k);
				printf("площади сечения, проведенного на расстоянии k от центра шар - %f", (pow(radius,2)-pow(k,2))*M_PI);
				break;
			case 6:
				printf("Автор: robot, версия: 0.1");
				break;
			case 7:
				return 0;
		}
	}
}

