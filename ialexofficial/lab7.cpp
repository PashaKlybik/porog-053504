#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define ERROR_FILE_OPEN -3

typedef struct hotelInfo
{
	char companyName[30],
		city[30],
		hotelName[30],
		hotelAdress[30],
		roomType[30];
	int roomCount, cost;
} HotelStruct;

typedef struct list
{
	struct list* next, * prev;
	HotelStruct info;
} List;

void addListNode(List** head, HotelStruct info);
void clearList(List** head);
void displayList(List* head);
void copyList(List* head, List** res);
List* findByString(List* head, char* input);
int checkOccurence(HotelStruct hotel, char* str);
void deleteNode(List** node);
void backPtr(List** head);

void writeListToFile(List* head, FILE** file);
void readListFromFile(List** head, FILE* file);

HotelStruct addHotel();


int main()
{
	FILE* file = NULL;
	int number = 0;

	file = fopen("C:\\Users\\Asus\\Desktop\\input.bin", "rb");
	if (file == NULL) {
		printf("Error opening file");
		getch();
		exit(ERROR_FILE_OPEN);
	}
	List* head = NULL;

	char choise;
	while (1)
	{
		printf("1.Read from file\n2.Add new hotel\n3.Write to file\n4.Show table\n5.Find\nAnother to exit\n");
		scanf("\n%c", &choise);
		if (choise == '1')
		{
			clearList(&head);
			readListFromFile(&head, file);
		}
		else if (choise == '2')
		{
			addListNode(&head, addHotel());
		}
		else if (choise == '3')
		{
			writeListToFile(head, &file);
		}
		else if (choise == '4')
		{
			displayList(head);
		}
		else if (choise == '5')
		{
			char* buffer = malloc(200);
			printf("Write search info: ");
			gets(buffer);
			gets(buffer);
			List* res = findByString(head, buffer);
			displayList(res);
			clearList(&res);
			free(buffer);
		}
		else
		{
			break;
		}
	}
	fclose(file);
	return 0;
}


void addListNode(List** head, HotelStruct info)
{
	if (*head == NULL) {
		*head = malloc(sizeof(List));
		(*head)->next = NULL;
		(*head)->prev = NULL;
		(*head)->info = info;
		return;
	}
	List* tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = malloc(sizeof(List));
	tmp->next->info = info;
	tmp->next->prev = head;
	tmp->next->next = NULL;
}
void clearList(List** head)
{
	if (*head == NULL)
		return;
	List* tmp = *head;
	while ((*head)->next != NULL)
	{
		*head = (*head)->next;
		free(tmp);
		tmp = *head;
	}
	free(tmp);
	*head = NULL;
}
void displayList(List* head)
{
	if (head == NULL) {
		printf("\nEmpty\n\n");
		return;
	}
	while (head != NULL)
	{
		printf("Company name: %s\n", head->info.companyName);
		printf("City: %s\n", head->info.city);
		printf("Hotel name: %s\n", head->info.hotelName);
		printf("Adress: %s\n", head->info.hotelAdress);
		printf("Room info: %s\n", head->info.roomType);
		printf("Room cost: %d\n", head->info.cost);
		printf("Room count: %d\n\n", head->info.roomCount);
		head = head->next;
	}
}
HotelStruct addHotel()
{
	HotelStruct hotel;
	printf("Write company name: ");
	gets(hotel.companyName);
	gets(hotel.companyName);
	printf("Write city: ");
	gets(hotel.city);
	printf("Write hotel name: ");
	gets(hotel.hotelName);
	printf("Write adress: ");
	gets(hotel.hotelAdress);
	printf("Write room type: ");
	gets(hotel.roomType);
	printf("Write room cost: ");
	scanf("%d", &hotel.cost);
	printf("Write room count: ");
	scanf("%d", &hotel.roomCount);
	return hotel;
}
void writeListToFile(List* head, FILE** file)
{
	fclose(*file);
	*file = fopen("C:\\Users\\Asus\\Desktop\\input.bin", "wb");
	while (head != NULL)
	{
		fwrite(&head->info, sizeof(HotelStruct), 1, *file);
		head = head->next;
	}
	fclose(*file);
	*file = fopen("C:\\Users\\Asus\\Desktop\\input.bin", "rb");
}
void readListFromFile(List** head, FILE* file)
{
	fseek(file, 0, SEEK_SET);
	*head = malloc(sizeof(List));
	(*head)->prev = NULL;
	(*head)->next = NULL;
	while (1)
	{
		fread(&(*head)->info, sizeof(HotelStruct), 1, file);
		if (!feof(file)) {
			(*head)->next = malloc(sizeof(List));
			(*head)->next->prev = *head;
		}
		else {
			if ((*head)->prev == NULL) { // File is empty
				free(*head);
				*head = NULL;
				return;
			}
			head = &(*head)->prev;
			List* tmp = (*head)->next;
			(*head)->next = NULL;
			free(tmp);
			break;
		}
		head = &(*head)->next;
	}
}
List* findByString(List* head, char* input)
{
	if (head == NULL)
		return NULL;

	List* res;
	copyList(head, &res);
	backPtr(&res);

	char* tempString = malloc(strlen(input) + 1);
	int pos = 0;
	List* deletingNode = NULL;
	List* tmp;
	for (int i = 0; i <= strlen(input); i++)
	{
		if (input[i] == ',' || input[i] == '\0')
		{
			tmp = res;
			tempString[pos] = '\0';
			while (tmp != NULL)
			{
				if (!checkOccurence(tmp->info, tempString)) {
					deletingNode = tmp;
				}
				tmp = tmp->next;
				if (deletingNode == res)
					res = res->next;
				deleteNode(&deletingNode);
				deletingNode = NULL;
			}
			free(tempString);
			tempString = malloc(strlen(input) + 1);
			pos = 0;
		}
		else
		{
			tempString[pos++] = input[i];
		}
	}
	free(tempString);
	return res;
}
int checkOccurence(HotelStruct hotel, const char* str)
{
	int res = 0;
	if (
		!strcmp(hotel.companyName, str) ||
		!strcmp(hotel.hotelAdress, str) ||
		!strcmp(hotel.hotelName, str) ||
		!strcmp(hotel.roomType, str) ||
		!strcmp(hotel.city, str)
	) {
		res = 1;
	}
	return res;
}
void copyList(List* head, List** res)
{
	if (head == NULL)
		return;
	List* tmp = head;
	(*res) = malloc(sizeof(List));
	(*res)->next = (*res)->prev = NULL;
	while (tmp != NULL)
	{
		(*res)->info = tmp->info;
		(*res)->prev = malloc(sizeof(List));
		tmp = tmp->next;
		(*res)->prev->next = *res;
		res = &(*res)->prev;
	}
	res = &(*res)->next;
	tmp = (*res)->prev;
	(*res)->prev = NULL;
	free(tmp);
}
void deleteNode(List** node)
{
	if (*node == NULL)
		return;
	if ((*node)->prev != NULL) {
		(*node)->prev->next = (*node)->next;
	}
	if ((*node)->next != NULL) {
		(*node)->next->prev = (*node)->prev;
	}

	free(*node);
}
void backPtr(List** head)
{
	if (*head == NULL)
		return;
	while ((*head)->prev != NULL)
		*head = (*head)->prev;
}