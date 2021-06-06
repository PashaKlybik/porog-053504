#define _CRT_SECURE_NO_WARNINGS

#include <conio.h>
#include <stdio.h>
#include <locale.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef enum
{
	male,
	female,
	noMatterSex,
} Sex;

typedef enum
{
	married,
	notMarried,
	noMatterStatus,
} mStatus;

typedef enum
{
	partTime,
	fullTime,
	noMatterBusyness,
} Busyness;

typedef enum
{
	high,
	secondary,
	basic,
	noMatterEducation,
} Education;

typedef struct Applicant
{
	char fullName[32];
	int yearOfBirth;
	char contacts[64];
	Sex sex;
	char specialty[32];
	Education education;
	mStatus maritalStatus;
	char currentCity[32];
	Busyness busyness;
	int desiredSalary;

	struct Applicant* next;
	struct Applicant* previous;
} Applicant;

typedef struct Vacancy
{
	char companyName[32];
	char city[32];
	char position[32];
	char specialty[32];
	Education education;
	Sex sex;
	mStatus maritalStatus;
	int age;
	Busyness busyness;
	int salary;

	struct Vacancy* next;
	struct Vacancy* previous;
} Vacancy;

typedef struct ApplicantsList
{
	Applicant* head;
	Applicant* tail;
} ApplicantsList;

typedef struct
{
	Vacancy* head;
	Vacancy* tail;
}VacanciesList;

VacanciesList* CreateVList();
ApplicantsList* CreateAList();
void DeleteVList(VacanciesList* list);
void DeleteAList(ApplicantsList* list);
VacanciesList* DeleteVNode(VacanciesList* list, int number);
ApplicantsList* DeleteANode(ApplicantsList* list, int number);
VacanciesList* AddVacancy(VacanciesList* vacList);
ApplicantsList* AddApplicant(ApplicantsList* appList);
VacanciesList* AddVacNode(VacanciesList* list, Vacancy *node);
ApplicantsList* AddAppNode(ApplicantsList* list, Applicant *node);
void ShowVacancy(Vacancy* vacancy);
void ShowApplicant(Applicant* applicant);
void ShowAllVacancies(VacanciesList* vacancies);
void ShowAllApplicants(ApplicantsList* applicants);
void FillVacDatabase(VacanciesList* list);
void FillAppDatabase(ApplicantsList* list);
void FillArchiveDatabase(ApplicantsList* list);
VacanciesList* GetVacancies(VacanciesList* list);
ApplicantsList* GetApplicants(ApplicantsList* list);
ApplicantsList* GetArchive(ApplicantsList* list);
Applicant* GetAppNode(ApplicantsList* list, int number);
void CorrectString(char *str);


char* SexString(Sex n);
char* mStatusString(mStatus n);
char* BusynessString(Busyness n);
char* EducationString(Education n);
int ClearInputBuffer();

int main()
{
	setlocale(0, "rus");
	system("chcp 1251");
	system("cls");
	VacanciesList *vacList = CreateVList();
	ApplicantsList *appList = CreateAList();
	ApplicantsList *archiveList = CreateAList();
	appList = GetApplicants(appList);
	vacList = GetVacancies(vacList);
	archiveList = GetArchive(archiveList);
	short choise;
	do
	{
		printf("Выберите номер действия:\n\n1. Добавить\n2. Показать список\n3. Занести в БД\n4. Удалить\n5. Занести претендента в архив\n6. Поиск\n7. Подобрать\n8. Выход\n\n");
		scanf("%hd", &choise);
		system("cls");
		if (choise == 1)
		{
			printf("Добавить\n1. Претендента\n2. Вакансию\n");
			scanf("%hd", &choise);
			system("cls");
			if (choise == 1)
			{
				appList = AddApplicant(appList);
			}
			else if (choise == 2)
			{
				vacList = AddVacancy(vacList);
			}
		}
		else if (choise == 2)
		{
			printf("Показать список\n1. Претендентов\n2. Вакансии\n");
			scanf("%hd", &choise);
			system("cls");
			if (choise == 1)
			{
				ShowAllApplicants(appList);
			}
			else if (choise == 2)
			{
				ShowAllVacancies(vacList);
			}
		}
		else if (choise == 3)
		{
			printf("Занести в БД\n1. Претендентов\n2. Вакансии\n");
			scanf("%hd", &choise);
			system("cls");
			if (choise == 1)
			{
				FillAppDatabase(appList);
			}
			else if (choise == 2)
			{
				FillVacDatabase(vacList);
			}
		}
		else if (choise == 4)
		{
			printf("Удалить\n1. Претендента\n2. Вакансию\n");
			scanf("%hd", &choise);
			system("cls");
			if (choise == 1)
			{
				ShowAllApplicants(appList);
				printf("\nВведите номер претендента (0 для отмены): ");
				scanf("%hd", &choise);
				appList = DeleteANode(appList, choise);
				if (choise > 0)
				{
					printf("Вы удалили %d претендента", choise);
				}
			}
			else if (choise == 2)
			{
				ShowAllVacancies(vacList);	
				printf("\nВведите номер вакансии (0 для отмены): ");
				scanf("%hd", &choise);
				system("cls");
				DeleteVNode(vacList, choise);
				if (choise > 0)
				{
					printf("Вы удалили %d претендента\n", choise);
				}
			}
		}
		else if (choise == 5)
		{
			ShowAllApplicants(appList);
			printf("\nВведите номер претендента для переноса в архив (0 для отмены): ");
			scanf("%hd", &choise);
			system("cls");
			Applicant *node = GetAppNode(appList, choise);
			Applicant *aNode = malloc(sizeof(Applicant));
			*aNode = *node;
			archiveList = AddAppNode(archiveList, aNode);
			appList = DeleteANode(appList, choise);
			FillArchiveDatabase(archiveList);
			FillAppDatabase(appList);
		}
		else if (choise == 6)
		{
			printf("1. Поиск претендента\n2. Поиск вакансии\n");
			char searchString[64];
			scanf("%hd", &choise);
			system("cls");
			if (choise == 1)
			{
				printf("Введите ФИО: ");
				ClearInputBuffer();
				gets(searchString);
				system("cls");
				Applicant *cur = appList->head;
				int i = 1;
				while (cur != NULL)
				{
					if (strstr(cur->fullName, searchString))
					{
						printf("#%d", i);
						ShowApplicant(cur);
					}
					i++;
					cur = cur->next;
				}
			}
			else if (choise == 2)
			{
				printf("Введите специальность: ");
				ClearInputBuffer();
				gets(searchString);
				system("cls");
				Vacancy* cur = vacList->head;
				int i = 1;
				while (cur != NULL)
				{
					if (strstr(cur->specialty, searchString))
					{
						printf("#%d", i);
						ShowVacancy(cur);
					}
					i++;
					cur = cur->next;
				}
			}
		}
		else if (choise == 7)
		{
			printf("1. Подбор вакансии\n2. Подбор претендента\n");
			scanf("%hd", &choise);
			system("cls");
			if (choise == 1)
			{
				int appNumber;
				Applicant* cur = appList->head;
				ShowAllApplicants(appList);
				printf("Выберите претендента для которого хотите подобрать вакансию: ");
				scanf("%d", &appNumber);
				int i = 1;
				while (cur != NULL)
				{
					if (i == appNumber)
					{
						break;
					}
					cur = cur->next;
					i++;
				}
				Vacancy* vcur = vacList->head;
				while (vcur != NULL)
				{
					if (strstr(vcur->specialty, cur->specialty) && (cur->education == vcur->education || vcur->education == 3) && (cur->sex == vcur->sex || vcur->sex == 2) && (cur->maritalStatus == vcur->maritalStatus || vcur->maritalStatus == 2))
					{
						ShowVacancy(vcur);
					}
					vcur = vcur->next;
				}
			}
			else if (choise == 2)
			{
				int vacNumber;
				Vacancy* cur = vacList->head;
				ShowAllVacancies(vacList);
				printf("Выберите вакансию для которой хотите подобрать претендентов: ");
				scanf("%d", &vacNumber);
				system("cls");
				int i = 1;
				while (cur != NULL)
				{
					if (i == vacNumber)
					{
						break;
					}
					cur = cur->next;
					i++;
				}
				Applicant* acur = appList->head;
				while (acur != NULL)
				{
					if (strstr(acur->specialty, cur->specialty) && strstr(acur->currentCity, cur->city) && (cur->education == acur->education || cur->education == 3) && (cur->sex == acur->sex || cur->sex == 2) && (cur->maritalStatus == acur->maritalStatus || cur->maritalStatus == 2))
					{
						ShowApplicant(acur);
					}
					acur = acur->next;
				}
			}
		}
	} while (choise != 8);
	DeleteAList(appList);
	DeleteVList(vacList);
}

int ClearInputBuffer() 
{
	int ch;
	while (((ch = getchar()) != EOF) && (ch != '\n'));
	return ch;
}

void CorrectString(char* str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			str[i] = '\0';
		}
		i++;
	}
}

char* SexString(Sex n)
{
	switch (n)
	{
	case 0:
		return "мужской";
	case 1:
		return "женский";
	case 2:
		return "не важно";
	}
	return "ошибка";
}

char* mStatusString(mStatus n)
{
	switch (n)
	{
	case 0:
		return "женат/замужем";
	case 1:
		return "не женат/не замужем";
	case 2:
		return "не важно";
	}
	return "ошибка";
}

char* BusynessString(Busyness n)
{
	switch (n)
	{
	case 0:
		return "частичная";
	case 1:
		return "полная";
	case 2:
		return "не важно";
	}
	return "ошибка";
}

char* EducationString(Education n)
{
	switch (n)
	{
	case 0:
		return "высшее";
	case 1:
		return "среднее";
	case 2:
		return "базовое";
	case 3:
		return "не важно";
	}
	return "ошибка";
}

VacanciesList* CreateVList()
{
	VacanciesList* list = malloc(sizeof(VacanciesList));
	list->head = NULL;
	list->tail = NULL;
	return list;
}

ApplicantsList* CreateAList()
{
	ApplicantsList* list = malloc(sizeof(ApplicantsList));
	list->head = NULL;
	list->tail = NULL;
	return list;
}

void DeleteVList(VacanciesList* list)
{
	Vacancy* node = list->head;
	while (node != NULL)
	{
		Vacancy* delptr = node;
		node = node->next;
		free(delptr);
	}
	free(list);
}

void DeleteAList(ApplicantsList* list)
{
	Applicant* node = list->head;
	while (node != NULL)
	{
		Applicant* delptr = node;
		node = node->next;
		free(delptr);
	}
	free(list);
}

VacanciesList* DeleteVNode(VacanciesList *list, int number)
{
	Vacancy* node = list->head;
	int counter = 1;
	while (node != NULL)
	{
		if (number == counter)
		{
			Vacancy* previous = node->previous;
			Vacancy* next = node->next;
			previous->next = next;
			next->previous = previous;
			free(node);
			return list;
		}
		node = node->next;
		counter++;
	}
	return list;
}

ApplicantsList* DeleteANode(ApplicantsList* list, int number)
{
	Applicant* node = list->head;
	int counter = 1;
	while (node != NULL)
	{
		if (number == counter)
		{
			Applicant* previous = node->previous;
			Applicant* next = node->next;
			if (previous != NULL)
			{
				previous->next = next;
			}
			else
			{
				list->head = next;
			}
			if (next != NULL)
			{
				next->previous = previous;
			}
			else
			{
				list->tail = next;
			}
			free(node);
			return list;
		}
		node = node->next;
		counter++;
	}
	return list;
}

Applicant* GetAppNode(ApplicantsList* list, int number)
{
	Applicant* node = list->head;
	int counter = 1;
	while (node != NULL)
	{
		if (number == counter)
		{
			return node;
		}
		node = node->next;
		counter++;
	}
	return NULL;
}

VacanciesList* AddVacancy(VacanciesList* vacList)
{
	Vacancy* vNode = malloc(sizeof(Vacancy));
	printf("==========Заполните следующие поля==========\n\n");
	printf("Название компании: ");
	ClearInputBuffer();
	gets(vNode->companyName);
	printf("Город: ");
	gets(vNode->city);
	printf("Должность: ");
	gets(vNode->position);
	printf("Cпециальность: ");
	gets(vNode->specialty);
	printf("Образование (0 - высшее, 1 - среднее, 2 - базовое, 3 - не важно): ");
	scanf("%d", &vNode->education);
	printf("Пол (0 - мужской, 1 - женский, 2 - не важно): ");
	scanf("%d", &vNode->sex);
	printf("Семейное положение (0 - женат/замужем, 1 - не женат/не замужем): ");
	scanf("%d", &vNode->maritalStatus);
	printf("Возраст: ");
	scanf("%d", &vNode->age);
	printf("Занятость (0 - частичная/1 - полная): ");
	scanf("%d", &vNode->busyness);
	printf("Уровень оплаты: ");
	scanf("%d", &vNode->salary);
	if (vacList->head == NULL)
	{
		vacList->head = vNode;
		vacList->head->next = NULL;
		vacList->head->previous = NULL;
		vacList->tail = vacList->head;
	}
	else
	{
		vacList->tail->next = vNode;
		vNode->previous = vacList->tail;
		vacList->tail = vNode;
		vacList->tail->next = NULL;
	}
	return vacList;
}

ApplicantsList* AddApplicant(ApplicantsList* appList)
{
	Applicant* aNode = malloc(sizeof(Applicant));
	printf("==========Заполните следующие поля==========\n\n");
	ClearInputBuffer();
	printf("ФИО: ");
	gets(aNode->fullName);
	printf("Год рождения: ");
	scanf("%d", &aNode->yearOfBirth);
	printf("Контакты: ");
	ClearInputBuffer();
	gets(aNode->contacts);
	printf("Пол (0 - мужской, 1 - женский): ");
	scanf("%d", &aNode->sex);
	printf("Специальность: ");
	ClearInputBuffer();
	gets(aNode->specialty);
	printf("Образование (0 - высшее, 1 - среднее, 2 - базовое): ");
	scanf("%d", &aNode->education);
	printf("Семейное положение (0 - женат/замужем, 1 - не женат/не замужем): ");
	scanf("%d", &aNode->maritalStatus);
	printf("Город проживания: ");
	ClearInputBuffer();
	gets(aNode->currentCity);
	printf("Занятость (0 - частичная/1 - полная): ");
	scanf("%d", &aNode->busyness);
	printf("Желаемый уровень з/п: ");
	scanf("%d", &aNode->desiredSalary);
	if (appList->head == NULL)
	{
		appList->head = aNode;
		appList->head->next = NULL;
		appList->head->previous = NULL;
		appList->tail = appList->head;
	}
	else
	{
		appList->tail->next = aNode;
		aNode->previous = appList->tail;
		appList->tail = aNode;
		appList->tail->next = NULL;
	}
	return appList;
}

VacanciesList* AddVacNode(VacanciesList* list, Vacancy* node)
{
	if (list->head == NULL)
	{
		list->head = node;
		list->head->next = NULL;
		list->head->previous = NULL;
		list->tail = list->head;
	}
	else
	{
		list->tail->next = node;
		node->previous = list->tail;
		list->tail = node;
		list->tail->next = NULL;
	}
	return list;
}

ApplicantsList* AddAppNode(ApplicantsList* list, Applicant* node)
{
	if (list->head == NULL)
	{
		list->head = node;
		list->head->next = NULL;
		list->head->previous = NULL;
		list->tail = list->head;
	}
	else
	{
		list->tail->next = node;
		node->previous = list->tail;
		list->tail = node;
		list->tail->next = NULL;
	}
	return list;
}

void ShowVacancy(Vacancy *vacancy)
{
	printf("\n=====================================\n\n");
	printf("Название компании: %s\n", vacancy->companyName);
	printf("Город: %s\n", vacancy->city);
	printf("Должность: %s\n", vacancy->position);
	printf("Cпециальность: %s\n", vacancy->specialty);
	printf("Образование: %s\n", EducationString(vacancy->education));
	printf("Пол: %s\n", SexString(vacancy->sex));
	printf("Семейное положение: %s\n", mStatusString(vacancy->maritalStatus));
	printf("Возраст: %d\n", vacancy->age);
	switch (vacancy->busyness)
	{
	case 0:
		printf("Занятость: частичная\n");
		break;
	case 1:
		printf("Занятость: полная\n");
		break;
	}
	printf("Уровень оплаты: %d\n", vacancy->salary);
	printf("\n=====================================\n\n");
}

void ShowApplicant(Applicant* applicant)
{
	printf("\n=====================================\n\n");
	printf("ФИО: %s\n", applicant->fullName);
	printf("Год рождения: %d\n", applicant->yearOfBirth);
	printf("Контакты: %s\n", applicant->contacts);
	switch (applicant->sex)
	{
	case male:
		printf("Пол: мужской\n");
		break;
	case female:
		printf("Пол: женский\n");
		break;
	}
	printf("Специальность: %s\n", applicant->specialty);
	printf("Образование: %s\n", EducationString(applicant->education));
	switch (applicant->maritalStatus)
	{
	case married:
		printf("Семейное положение: женат/замужем\n");
		break;
	case notMarried:
		printf("Семейное положение: не женат/замужем\n");
		break;
	}
	printf("Город проживания: %s\n", applicant->currentCity);
	switch (applicant->busyness)
	{
	case partTime:
		printf("Занятость: частичная\n");
		break;
	case fullTime:
		printf("Занятость: полная\n");
		break;
	}
	printf("Желаемый уровень з/п: %d\n", applicant->desiredSalary);
	printf("\n=====================================\n\n");
}

void ShowAllVacancies(VacanciesList* list)
{
	Vacancy* cur = list->head;
	int counter = 1;
	while (cur != NULL)
	{
		printf("# %d", counter++);
		ShowVacancy(cur);
		cur = cur->next;
	}
}

void ShowAllApplicants(ApplicantsList* list)
{
	Applicant* cur = list->head;
	int counter = 1;
	while (cur != NULL)
	{
		printf("# %d", counter++);
		ShowApplicant(cur);
		cur = cur->next;
	}
}

void FillVacDatabase(VacanciesList* list)
{
	FILE* fp = fopen("D:\\Лабы\\Прогр-е\\lab7\\lab7\\lab7\\Vacancies.txt", "w");
	Vacancy* cur = list->head;
	printf("%d", cur->sex);
	while (cur != NULL)
	{
		fprintf(fp, "%s\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n", cur->companyName, cur->city, cur->position, cur->specialty, cur->education, cur->sex, cur->maritalStatus, cur->age, cur->busyness, cur->salary);
		cur = cur->next;
	}
	fclose(fp);
}

void FillAppDatabase(ApplicantsList* list)
{
	FILE* fp = fopen("D:\\Лабы\\Прогр-е\\lab7\\lab7\\lab7\\Applicants.txt", "w");
	Applicant* cur = list->head;
	while (cur != NULL)
	{
		fprintf(fp, "%s\n%d\n%s\n%d\n%s\n%d\n%d\n%s\n%d\n%d\n", cur->fullName, cur->yearOfBirth, cur->contacts, cur->sex, cur->specialty, cur->education, cur->maritalStatus, cur->currentCity, cur->busyness, cur->desiredSalary);
		cur = cur->next;
	}
	fclose(fp);
}

void FillArchiveDatabase(ApplicantsList* list)
{
	FILE* fp = fopen("D:\\Лабы\\Прогр-е\\lab7\\lab7\\lab7\\Archive.txt", "w");
	Applicant* cur = list->head;
	while (cur != NULL)
	{
		fprintf(fp, "%s\n%d\n%s\n%d\n%s\n%d\n%d\n%s\n%d\n%d\n", cur->fullName, cur->yearOfBirth, cur->contacts, cur->sex, cur->specialty, cur->education, cur->maritalStatus, cur->currentCity, cur->busyness, cur->desiredSalary);
		cur = cur->next;
	}
	fclose(fp);
}

ApplicantsList* GetApplicants(ApplicantsList* list)
{
	char buffer[250];
	FILE* fp = fopen("D:\\Лабы\\Прогр-е\\lab7\\lab7\\lab7\\Applicants.txt", "r+");
	Applicant* node = NULL;
	int i = 1;
	while (fgets(buffer, 250, fp) != NULL)
	{
		CorrectString(buffer);
		switch (i % 10)
		{
		case 1:
			node = malloc(sizeof(Applicant));
			strcpy(node->fullName, buffer);
			break;
		case 2:
			node->yearOfBirth = atoi(buffer);
			break;
		case 3:
			strcpy(node->contacts, buffer);

			break;
		case 4:
			node->sex = atoi(buffer);
			break;
		case 5:
			strcpy(node->specialty, buffer);
			break;
		case 6:
			node->education = atoi(buffer);
			break;
		case 7:
			node->maritalStatus = atoi(buffer);
			break;
		case 8:
			strcpy(node->currentCity, buffer);
			break;
		case 9:
			node->busyness = atoi(buffer);
			break;
		case 0:
			node->desiredSalary = atoi(buffer);
			list = AddAppNode(list, node);
		}
		i++;
	}
	fclose(fp);
	return list;
}

VacanciesList* GetVacancies(VacanciesList* list)
{
	char buffer[250];
	FILE* fp = fopen("D:\\Лабы\\Прогр-е\\lab7\\lab7\\lab7\\Vacancies.txt", "r+");
	Vacancy* node = NULL;
	int i = 1;
	while (fgets(buffer, 250, fp) != NULL)
	{
		CorrectString(buffer);
		switch (i % 10)
		{
		case 1:
			node = malloc(sizeof(Applicant));
			strcpy(node->companyName, buffer);
			break;
		case 2:
			strcpy(node->city, buffer);
			break;
		case 3:
			strcpy(node->position, buffer);
			break;
		case 4:
			strcpy(node->specialty, buffer);
			break;
		case 5:
			node->education = atoi(buffer);
			break;
		case 6:
			node->sex = atoi(buffer);
			break;
		case 7:
			node->maritalStatus = atoi(buffer);
			break;
		case 8:
			node->age = atoi(buffer);
			break;
		case 9:
			node->busyness = atoi(buffer);
			break;
		case 0:
			node->salary = atoi(buffer);
			list = AddVacNode(list, node);
			break;
		}
		i++;
	}
	fclose(fp);
	return list;
}

ApplicantsList* GetArchive(ApplicantsList* list)
{
	char buffer[250];
	FILE* fp = fopen("D:\\Лабы\\Прогр-е\\lab7\\lab7\\lab7\\Archive.txt", "r+");
	Applicant* node = NULL;
	int i = 1;
	while (fgets(buffer, 250, fp) != NULL)
	{
		CorrectString(buffer);
		switch (i % 10)
		{
		case 1:
			node = malloc(sizeof(Applicant));
			strcpy(node->fullName, buffer);
			break;
		case 2:
			node->yearOfBirth = atoi(buffer);
			break;
		case 3:
			strcpy(node->contacts, buffer);

			break;
		case 4:
			node->sex = atoi(buffer);
			break;
		case 5:
			strcpy(node->specialty, buffer);
			break;
		case 6:
			node->education = atoi(buffer);
			break;
		case 7:
			node->maritalStatus = atoi(buffer);
			break;
		case 8:
			strcpy(node->currentCity, buffer);
			break;
		case 9:
			node->busyness = atoi(buffer);
			break;
		case 0:
			node->desiredSalary = atoi(buffer);
			list = AddAppNode(list, node);
		}
		i++;
	}
	fclose(fp);
	return list;
}