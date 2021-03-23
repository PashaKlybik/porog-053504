#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	system("chcp 1251");
	system("cls");

	int
		Choise = 1,
		counterDelivery = 0,
		Y_N_potato = 0,
		Y_N_carrot = 0,
		Y_N_beet = 0;

	float
		potato = 0.0,
		potPrice = 0.0,
		carrot = 0.0,
		carPrice = 0.0,
		beet = 0.0,
		beetPrice = 0.0,
		vegetablesWeight = 0.0,
		preDiscontPrice = 0.0,
		Discont = 0.0,
		postDiscontPrice = 0.0;

	printf(" 1. Заказ картофеля\n");
	printf(" 2. Заказ моркови\n");
	printf(" 3. Заказ свеклы\n");
	printf(" 4. Корзина. (Стоимость товарных позиций)\n");
	printf(" 5. Расчёт стоимости ( чек )\n");
	printf(" 6. Обратная связь\n");
	printf(" 7. Выход\n");

	while (Choise != 7 && Choise > 0 && Choise < 8)
	{	
		printf("\nEnter number (1-7): ");
		scanf_s("%d", &Choise);
		printf("\n");
			
		switch (Choise)
		{
		case 1://How potato

			printf("Картофель -- 500р/кг\n");
			printf("Килло: ");
			scanf_s("%f", &potato);

			potPrice += 500 * potato;
			preDiscontPrice += 500 * potato;
			vegetablesWeight += potato;
			Y_N_potato = 1;

			break;
		case 2: //How carrot

			printf("Морковь -- 1000р/кг\n");
			printf("Килло: ");
			scanf_s("%f", &carrot);

			carPrice += 1000 * carrot;
			preDiscontPrice += 1000 * carrot;
			vegetablesWeight += carrot;
			Y_N_carrot = 1;

			break;
		case 3: //How beet

			printf("Свекла -- 700р/кг\n");
			printf("Килло: ");
			scanf_s("%f", &beet);

			beetPrice += 700 * beet;
			preDiscontPrice += 700 * beet;
			vegetablesWeight += beet;
			Y_N_beet = 1;

			break;
		case 4: // overPrice info + weight

			if (Y_N_potato == 1)
			{
				printf("\nКг картофеля: %.2f\n", potato);
			}

			if (Y_N_carrot == 1)
			{
				printf("Кг моркови: %.2f\n", carrot);
			}

			if (Y_N_beet == 1)
			{
				printf("Кг свеклы: %.2f\n", beet);
			}

			printf("Cтоимость составляет (p): %.3f\n", preDiscontPrice);

			break;
		case 5: // payCheck

			printf("\n***************Чек***************\n");
			//prePrice
			if (Y_N_potato == 1)
			{
				printf("\nСтоимость картофеля: %.3f", potPrice);
			}

			if (Y_N_carrot == 1)
			{
				printf("\nСтоимость моркови: %.3f", carPrice);
			}

			if (Y_N_beet == 1)
			{
				printf("\nСтоимость свеклы: %.3f\n", beetPrice);
			}

			//+ to price message
			if (Y_N_beet == 1 || Y_N_carrot == 1 || Y_N_potato == 1)
			{
				printf("\nДоставка до дверей: 15 000 р.\n");
				if (counterDelivery == 0)
				{
					preDiscontPrice += 15000;
					counterDelivery++;
				}
			}

			if (Y_N_beet != 1 && Y_N_carrot != 1 && Y_N_potato != 1)
			{
				printf("Вы ничего не заказали *_*\n");
			}

			printf("***************Чек***************\n");

			//discont
			if (vegetablesWeight > 10 && vegetablesWeight <= 25)
			{
				printf("Скидка: 10% !!!\n");
				Discont = preDiscontPrice / 10;
				postDiscontPrice = preDiscontPrice - Discont;
				printf("Общая стоимость: %.3f", postDiscontPrice);
			}

			if (vegetablesWeight > 25 && vegetablesWeight <= 50)
			{
				printf("Скидка: 20% !!!\n");
				Discont = preDiscontPrice / 5;
				postDiscontPrice = preDiscontPrice - Discont;
				printf("Общая стоимость: %.3f", postDiscontPrice);
			}

			if (vegetablesWeight > 50)
			{
				printf("Скидка: 30% !!!\n");
				Discont = preDiscontPrice / 10 * 3;
				postDiscontPrice = preDiscontPrice - Discont;
				printf("Общая стоимость: %.3f", postDiscontPrice);
			}
			else if (vegetablesWeight <= 10 && vegetablesWeight > 0)
			{
				printf("Скидка отсутствует. Вес овощей менее 10 кг *_*\n");
				printf("Общая стоимость: %.3f", postDiscontPrice);
			}

			break;
		case 6:

			printf("Магазин:\t\teVegetables © \n");
			printf("Номер лицензии:\t\t№375172702033\n");
			printf("Контактная информация:\t@Pasha_Klybik\n");

			break;
		case 7:
			printf("Good bye!\n");
			return 0;
		default:
			printf("Incorrect number!\n");
			printf("Let's smoke bamboo!\n");
			break;

		} // end switch

	} // end while

	system("pause");
	return 0;
}