#include <locale.h>
#include <iostream> 

bool EndProgram(bool lastchecker) {
	lastchecker = false;
	return lastchecker;
}

void ShowInfo() {
	printf("\t\tИнформация о банке:\nГлавный офис: ул. Веры Хоружей, 31А, Минск (подъезд 1, этаж 1, 2).\nСайт: priorbank.by.\nВремя работы: пн-чт 08:30–17:30; пт 08:30–16:15.\nКонтактные номера: +375 17 289-90-90, +375 17 289-90-60.\n");
}

float CountBenefits(float dol, float eur, float russr) {
	float e, n = 0;
	int k;
	e = 2.662 - dol;
	if (e > n) {
		n = e;
		k = 1;
	}
	printf("Рассчет прибыли за операции с каждой валютой:\n\tДоллар: %f", e);
	e = 3.172 - eur;
	if (e > n) {
		n = e;
		k = 2;
	}
	printf("\n\tЕвро: %f", e);
	e = 3.48 - 100 * russr;
	if (e > n) {
		n = e;
		k = 3;
	}
	printf("\n\tРоссийские рубли: %f", e);
	e = (1.197 - eur / dol) * 2.64;
	if (e > n) {
		n = e;
		k = 4;
	}
	printf("\n\tЕвро в доллары: %f", e);
	printf("\nСамая выгодная операция для банка");
	switch (k) {
	case 1:
		printf(" 'Доллары'.\n");
		break;
	case 2:
		printf(" 'Евро'.\n");
		break;
	case 3:
		printf(" 'Российские рубли'.\n");
		break;
	case 4:
		printf(" 'Евро в доллары'.\n");
		break;
	}
	return n;
}

float ShowInOtherCurrencies(float s, float dol, float eur, float russr) {
	float e;
	e = s / dol;
	printf("Доллары: %f\n", e);
	e = s / eur;
	printf("Евро: %f\n", e);
	e = s / russr;
	printf("Русские рубли: %f\n", e);
	return 0;
}

void ShowTable() {
	printf("\tДоллары покупка - 2.628, продажа - 2,662.\n\tЕвро покупка - 3.123, продажа - 3.172.\n\tРоссийские рубли(100) покупка - 3.36, продажа - 3.48.\n\tЕвро в доллары покупка - 1.177, продажа - 1.197.\n");
}

int main()
{
	setlocale(LC_ALL, "Rus");
	float sum = 0;
	bool wish = true;
	bool checkerbig = true;
	bool checkersmall = true;
	printf("\n\t\t\tМеню:\n\n1) Чтобы ввести сумму в белорусских рублях, нажмите 1.\n2) Если вы хотите увидеть чему равна ваша сумма в долларах США, евро и российский рублях, нажмите 2.\n3) Чтобы вывести таблицу курсов валют, нажмите 3.\n4) Чтобы определить наиболее выгодную операцию, нажмите 4\n5) Если вы хотите узнать контакты банка, нажмите 5.\n6) Чтобы выйти из программы, нажмите 6.\n\n");
	int k;
	float dollar = 2.64, euro = 3.14, russrub = 0.03;
	while (checkerbig) {
		bool checkersmall = true;
		while (checkersmall) {
			printf("Введите номер операции:");
			scanf_s("%d", &k);
			if (k > 0 && k < 7) {
				checkersmall = false;
			}
			else {
				printf("Вы ввели некорректный номер, повторите ввод.\n");
			}
		}
		if (k == 1) {
			checkersmall = true;
			while (checkersmall) {
				printf("Введите сумму в белорусских рублях:");
				scanf_s("%f", &sum);
				if (sum > 0) {
					checkersmall = false;
				}
				else {
					printf("Вы ввели некорректную сумму, повторите ввод:");
				}
			}
		}

		if (sum != 0) {
			bool checkerbig = false;
			switch (k)
			{
			case 2:
				ShowInOtherCurrencies(sum, dollar, euro, russrub);
				break;
			case 3:
				ShowTable();
				break;
			case 4:
				CountBenefits(dollar, euro, russrub);
				break;
			case 5:
				ShowInfo();
			case 6:
				return 0;
			}
		}
		else {
			printf("Сперва введите сумму в белорусских рублях.\n");
		}
	}
}