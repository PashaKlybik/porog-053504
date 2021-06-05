#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "malloc.h"
#include "Windows.h"
#include "List.h"

int CheckInputInt(char buff[]); // проверка на ввод int32
double CheckInputDouble(char buff[]); // проверка на ввод double
void MakeTransaction(List*); // организация ввода данных и оформления в консоли
int Transaction(List*, Account*, Account*, double); // логическая часть со списком
void MakeDeletion(List*); // оформление удаления
void Add(List*); // оформление добавления счета
void MakeShowOperations(List*); // оформление вывода всех операций с аккаунтом за год
void PrintInterface(List*); // печатает текстовый интерфейс
void MakeWriteToFile(List*); // оформление записи в файл
void MakePut(List* list);// добавление денег на счет
void MakeWithdraw(List* list);// снятие денег со счета

int ID = 0; // счетчик ID акканутов
time_t currentTime;

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	List* list = (List*)calloc(1, sizeof(List));
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	currentTime = time(NULL);
	char key = 'q';
	PrintInterface(list);

	do
	{
		key = getchar();
		rewind(stdin);
		// проверка на ввод символов
		while (key != 'a' && key != 't' && key != 's' && key != 'n'
			&& key != 'm' && key != 'z' && key != 'y' && key != 'i'
			&& key != 'w' && key != 'c' && key != 'q' && key != 'p' && key != 'u')
		{
			printf("Invalid input\n");
			key = getchar();
			rewind(stdin);
		}

		switch (key)
		{
		case 'a':
			Add(list);
			break;
		case 't':
			MakeTransaction(list);
			break;
		case 's':
			Sort(list);
			system("cls");
			PrintInterface(list);
			break;
		case 'u':
			if (AddYear(&currentTime))
			{
				ClearOperations(list);
			}
			SkipYear(list);
			system("cls");
			PrintInterface(list);
			break;
		case 'n':
			if (AddMonth(&currentTime))
			{
				ClearOperations(list);
			}
			SkipMonth(list);
			system("cls");
			PrintInterface(list);
			break;
		case 'm':
			if (AddDay(&currentTime))
			{
				ClearOperations(list);
			}
			SkipDay(list);
			system("cls");
			PrintInterface(list);
			break;
		case 'z':
			MakeDeletion(list);
			break;
		case 'y':
			MakeShowOperations(list);
			break;
		case 'w':
			MakeWriteToFile(list);
			break;
		case 'p':
			MakePut(list);
			break;
		case 'i':
			MakeWithdraw(list);
			break;
		case 'c':
			Clear(list); // полная очистка списка
			ID = 0;
			system("cls");
			puts("Уведомления :\n");
			puts("Список успешно очищен\n");
			PrintInterface(list);
			break;
		}
	} while (key != 'q');
	system("cls");
	Clear(list);
	return 0;
}




void MakeTransaction(List* list)
{
	char buff[1000];
	puts("\nВведите ID отправителя : ");
	int fromID = CheckInputInt(buff);
	Account* fromAcc = Find(list, fromID); // находим отправителя
	if (fromAcc != NULL) fromAcc->isChosenForTransaction = 1;
	else
	{
		system("cls");
		puts("Уведомление :\n");
		puts("Ошибка транзакции\n");
		PrintInterface(list);
		return;
	}
	system("cls");
	PrintInterface(list);
	puts("\nВведите ID получателя : ");
	int toID = CheckInputInt(buff);
	Account* toAcc = Find(list, toID); // находим получателя
	if (toAcc != NULL && toID != fromID) toAcc->isChosenForTransaction = 1;
	else
	{
		system("cls");
		puts("Уведомление :\n");
		puts("Ошибка транзакции\n");
		fromAcc->isChosenForTransaction = 0;
		PrintInterface(list);
		return;
	}
	system("cls");
	PrintInterface(list);
	puts("\nВведите сумму : ");
	double sum = CheckInputDouble(buff);
	if (Transaction(list, fromAcc, toAcc, sum))
	{
		system("cls");
		puts("Уведомление :\n");
		puts("Совершена транзакция :\n");
		printf("Отправитель :   ID : %d\n", fromAcc->ID);
		printf("Получатель :   ID : %d\n", toAcc->ID);
		printf("Сумма : %.2lf\n\n", sum);
		PrintInterface(list);
		// дальше идет запись операции в оба аккаунта
		if (fromAcc->operations == NULL)
		{
			fromAcc->operations = (char*)calloc(1, 100);
		}
		else
		{
			fromAcc->operations = (char*)realloc(fromAcc->operations, 100);
		}

		if (toAcc->operations == NULL)
		{
			toAcc->operations = (char*)calloc(1, 100);
		}
		else
		{
			toAcc->operations = (char*)realloc(toAcc->operations, 100);
		}

		char s[100];
		for (int i = 0; i < 100; i++) s[i] = '\0';
		char* ID1 = (char*)malloc(10);
		char* ID2 = (char*)malloc(10);
		char* SUM = (char*)malloc(15);
		_itoa(fromAcc->ID, ID1, 10);
		_itoa(toAcc->ID, ID2, 10);
		sprintf(SUM, "%.2lf", sum);
		strcpy(s, "ID: ");
		strcat(s, ID1);
		strcat(s, " => ID: ");
		strcat(s, ID2);
		strcat(s, " Сумма : ");
		strcat(s, SUM);
		strcat(s, "\n");
		strcat(fromAcc->operations, s);
		strcat(toAcc->operations, s);
	}
	else
	{
		system("cls");
		puts("Уведомление :\n");
		puts("Ошибка транзакции\n");
		PrintInterface(list);
	}
}

void MakePut(List* list)
{
	char buff[1000];
	puts("\nВведите ID счета на который хотите положить деньги : ");
	int toID = CheckInputInt(buff);
	Account* toAcc = Find(list, toID); // находим аккаунт
	if (toAcc != NULL) toAcc->isChosenForTransaction = 1;
	else
	{
		system("cls");
		puts("Уведомление :\n");
		puts("Ошибка транзакции\n");
		PrintInterface(list);
		return;
	}
	system("cls");
	PrintInterface(list);
	puts("\nВведите сумму : ");
	double sum = CheckInputDouble(buff);
	Put(toAcc, sum);
	system("cls");
	puts("Уведомление :\n");
	puts("Совершена транзакция :\n");
	printf("Получатель : ID : %d\n", toAcc->ID);
	printf("Сумма : %.2lf\n\n", sum);
	PrintInterface(list);

	if (toAcc->operations == NULL)
	{
		toAcc->operations = (char*)calloc(1, 100);
	}
	else
	{
		toAcc->operations = (char*)realloc(toAcc->operations, 100);
	}

	char s[100];
	for (int i = 0; i < 100; i++) s[i] = '\0';
	char* SUM = (char*)malloc(15);
	sprintf(SUM, "%.2lf", sum);
	strcat(s, "Пополнение баланса. Сумма пополнения : ");
	strcat(s, SUM);
	strcat(s, "\n");
	strcat(toAcc->operations, s);
}

void MakeWithdraw(List* list)
{
	char buff[1000];
	puts("\nВведите ID счета c которого хотите снять деньги : ");
	int fromID = CheckInputInt(buff);
	Account* fromAcc = Find(list, fromID); // находим аккаунт
	if (fromAcc != NULL) fromAcc->isChosenForTransaction = 1;
	else
	{
		system("cls");
		puts("Уведомление :\n");
		puts("Ошибка транзакции\n");
		PrintInterface(list);
		return;
	}
	system("cls");
	PrintInterface(list);
	puts("\nВведите сумму : ");
	double sum = CheckInputDouble(buff);
	if (Withdraw(fromAcc, sum, currentTime))
	{
		system("cls");
		puts("Уведомление :\n");
		puts("Совершена транзакция :\n");
		printf("Cнятие со счета ID : %d\n", fromAcc->ID);
		printf("Сумма снятия: %.2lf\n\n", sum);
		PrintInterface(list);
		if (fromAcc->operations == NULL)
		{
			fromAcc->operations = (char*)calloc(1, 100);
		}
		else
		{
			fromAcc->operations = (char*)realloc(fromAcc->operations, 100);
		}
		char s[100];
		for (int i = 0; i < 100; i++) s[i] = '\0';
		char* SUM = (char*)malloc(15);
		sprintf(SUM, "%.2lf", sum);
		strcat(s, "Снятие со счета. Сумма снятия : ");
		strcat(s, SUM);
		strcat(s, "\n");
		strcat(fromAcc->operations, s);
	}
	else
	{
		system("cls");
		puts("Уведомление :\n");
		puts("Ошибка транзакции\n");
		PrintInterface(list);
	}
}

int Transaction(List* list, Account* fromAcc, Account* toAcc, double sum)
{
	fromAcc->isChosenForTransaction = 0;
	toAcc->isChosenForTransaction = 0;
	if (Withdraw(fromAcc, sum, currentTime))
	{
		Put(toAcc, sum);
		return 1;
	}
	return 0;
}

void MakeDeletion(List* list)
{
	char buff[1000];
	printf("\nВведите ID счета, который необходимо удалить : ");
	int ID = CheckInputInt(buff);
	int index = FindIndex(list, ID);
	if (index == -1)
	{
		system("cls");
		puts("Уведомление : \n");
		puts("ID не найден\n");
		PrintInterface(list);
		return;
	}
	else
	{
		Account* acc = Find(list, ID);
		system("cls");
		puts("Уведомление : \n");
		printf("Удален счет ID : %d\nСумма : %.2lf\n", ID, acc->sum);
		if (acc->type == 1) puts("Тип : До востребования\n");
		else puts("Тип : Депозитный\n");
		Delete(list, index);
		PrintInterface(list);
	}
}

void Add(List* list)
{
	char buff[1000];
	Account acc;
	puts("\nВведите тип счета (1 - до востребования, 2 - депозитный) : ");
	acc.type = CheckInputInt(buff);
	while (acc.type != 1 && acc.type != 2)
	{
		puts("Invalid input");
		acc.type = CheckInputInt(buff);
	}
	puts("\nВведите имя : ");
	acc.name = (char*)calloc(40, sizeof(char));
	gets(acc.name);
	puts("\nВведите начальную сумму на счете : ");
	acc.sum = CheckInputDouble(buff);
	puts("\nВведите проценты : ");
	acc.percentage = CheckInputDouble(buff);

	if (acc.type == 2)
	{
		puts("\nВведите интервал в месяцах для снятия средств : ");
		acc.months = CheckInputInt(buff);
	}
	else
	{
		acc.months = 0;
	}
	acc.opened = currentTime;
	acc.ID = ID;
	ID++;
	acc.operations = NULL;
	PushBack(list, acc);
	system("cls");
	PrintInterface(list);
}

void MakeShowOperations(List* list)
{
	char buff[1000];
	printf("\nВведите ID счета, операции за год которого посмотреть : ");
	int ID = CheckInputInt(buff);
	Account* acc = Find(list, ID);
	if (acc == NULL)
	{
		system("cls");
		puts("Уведомление : \n");
		puts("ID не найден\n");
		PrintInterface(list);
		return;
	}
	else
	{
		system("cls");
		puts("Уведомление : \n");
		printf("Операции с ID : %d\n", acc->ID);
		if (acc->operations == NULL) puts("None");
		else puts(acc->operations);
		printf("\n");
		PrintInterface(list);
	}

}

int CheckInputInt(char buff[]) { // проверка на ввод int32
	int find_char, i, n;
	while (1) {
		find_char = 0;
		gets_s(buff, 1000);
		for (i = 0; i < strlen(buff); i++) {
			if (buff[i] < '0' || buff[i] > '9') {
				find_char = 1;
				break;
			}
		}
		if (find_char == 0) n = atoi(buff);
		if (find_char == 0 && n < _CRT_INT_MAX) {
			break;
		}
		else printf("Invalid input\n");
	}
	return n;
}

double CheckInputDouble(char buff[]) {
	int find_char, i;
	double n;

	while (1) {
		find_char = 0;
		gets_s(buff, 1000);
		for (i = 0; i < strlen(buff); i++) {
			if ((buff[i] < '0' || buff[i] > '9') && buff[i] != '.') {
				find_char = 1;
				break;
			}
		}
		if (find_char == 0) n = atof(buff);

		if (find_char == 0 && n < _CRT_INT_MAX && n > 0) {
			break;
		}
		else printf("Invalid input!\n");
	}
	return n;
}

void MakeWriteToFile(List* list)
{
	FILE* fptr = fopen("File.txt", "w");
	WriteToFile(list, fptr);
	fclose(fptr);
	system("cls");
	puts("Уведомление :\n");
	puts("Данные успешно сохранены в файл\n");
	PrintInterface(list);
}

void PrintInterface(List* list)
{
	printf("Текущая дата : %s \n\n", TimeToStr(currentTime));
	PrintList(list);
	puts("\n'a' - добавить счет");
	puts("'t' - провести транзакцию");
	puts("'P' - пополнить баланс счета");
	puts("'i' - снять деньги со счета");
	puts("'s' - отсортировать по сумме");
	puts("'u' - пропустить год");
	puts("'n' - пропустить месяц");
	puts("'m' - пропустить день");
	puts("'z' - удалить счет по ID");
	puts("'y' - посмотреть операции с аккаунтом за год");
	puts("'w' - сохранить информацию в файл");
	puts("'c' - очистить список");
	puts("'q' - выход");
}