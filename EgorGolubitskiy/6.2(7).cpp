#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <malloc.h>
#include <locale.h>


struct node {
	struct node* next;
	struct node* prev;
	int id[30];
	int counter;
	char fullname[30];
	char town[20];
	char education[20];
	char company[20];
	char hobbies[20];
	int userid;
};

struct list {
	struct node* head;
	struct node* tail;
	struct node* b1;
	struct node* b2;
};


struct list* Startlist(struct list* List, char* FullName, char* Town, char* Education, char* Company, char* Interests, int Userid)
{
	struct node* tmp = (struct node*)malloc(sizeof(struct node));
	struct node* ptr = List->tail;
	tmp->userid = Userid;

	for (int i = 0; i < strlen(FullName); i++)
	{
		tmp->fullname[i] = FullName[i];
	}

	tmp->fullname[strlen(FullName)] = '\0';

	for (int i = 0; i < strlen(Town); i++)
	{
		tmp->town[i] = Town[i];
	}

	tmp->town[strlen(Town)] = '\0';

	for (int i = 0; i < strlen(Education); i++)
	{
		tmp->education[i] = Education[i];
	}

	tmp->education[strlen(Education)] = '\0';

	for (int i = 0; i < strlen(Company); i++)
	{
		tmp->company[i] = Company[i];
	}

	tmp->company[strlen(Company)] = '\0';

	for (int i = 0; i < strlen(Interests); i++)
	{
		tmp->hobbies[i] = Interests[i];
	}

	tmp->hobbies[strlen(Interests)] = '\0';
	tmp->counter = 0;

	for (int i = 0; i < 30; i++) {
		tmp->id[i] = 0;
	}

	if (List->head == NULL) {
		List->head = tmp;
		List->tail = tmp;
		List->head->next = NULL;
		List->head->prev = NULL;
	}
	else {
		ptr = List->tail;
		List->tail->next = tmp;
		List->tail = List->tail->next;
		List->tail->next = NULL;
		List->tail->prev = ptr;
	}

	return List;
}

struct list* eraseel(list* List, int usid)
{
	struct node* tmp = (struct node*)malloc(sizeof(struct node));
	tmp = List->head;
	tmp->prev = NULL;
	List->b1 = tmp;
	while (tmp->next != NULL && tmp->next->userid != usid)
	{
		tmp = tmp->next;
	}
	if (tmp->next != NULL) {
		tmp->next = tmp->next->next;
		List->head = List->b1;

		struct node* ptr;
		ptr = List->head;
		do {
			if (ptr->next == NULL) {
				List->tail = ptr;
			}
			ptr = ptr->next;
		} while (ptr != NULL);
	}
	else {
		printf("\nRe-enter id!\n");
	}
	return List;
}

struct list* createlink(list* List, int id1, int id2) {

	struct node* tmp1 = (struct node*)malloc(sizeof(struct node));
	tmp1 = List->head;
	List->b1 = tmp1;
	while (tmp1->next != NULL && tmp1->userid != id1)
	{
		tmp1 = tmp1->next;
	}


	tmp1->id[tmp1->counter] = id2;
	tmp1->counter++;

	List->head = List->b1;

	return List;
}

void seelinks(list* List, int id) {
	struct node* tmp1 = (struct node*)malloc(sizeof(struct node));
	struct node* tmp2 = (struct node*)malloc(sizeof(struct node));
	int i = 0;
	tmp1 = List->head;
	while (tmp1->next != NULL && tmp1->userid != id)
	{
		tmp1 = tmp1->next;
	}
	printf("\n\n\n");
	printf("Acquaintances:\n");
	while (tmp1->id[i] != 0) {
		tmp2 = List->head;
		while (tmp2->next != NULL && tmp2->userid != tmp1->id[i])
		{
			tmp2 = tmp2->next;
		}
		printf("%d. %s\n", tmp1->id[i], tmp2->fullname);
		i++;
	}
	printf("\n\n\n");
}

void erase_first(list* List)
{
	List->head = List->head->next;
}

void toprintlist(struct list* List)
{
	struct node* ptr;
	ptr = List->head;
	do {
		printf("\n\n\n");
		printf("Person's id: %d", ptr->userid);
		printf("\nUsername: %s", ptr->fullname);
		printf("\nPerson's company: %s", ptr->company);
		printf("\nPerson's town: %s", ptr->town);
		printf("\nPerson's education: %s", ptr->education);
		printf("\nPerson's hobbies: %s", ptr->hobbies);
		printf("\n\n\n");
		ptr = ptr->next;
	} while (ptr != NULL);
}

void tofindhobbies(struct list* List, char* array)
{
	struct node* ptr;
	ptr = List->head;
	printf("\n\n\n");
	do {
		if (!strcmp(array, ptr->hobbies)) {
			printf("\n%d. %s", ptr->userid, ptr->fullname);
		}
		ptr = ptr->next;
	} while (ptr != NULL);
	printf("\n\n\n");
}

void tofindcompany(struct list* List, char* array)
{
	struct node* ptr;
	ptr = List->head;
	printf("\n\n\n");
	do {
		if (!strcmp(array, ptr->company)) {
			printf("\n%d. %s", ptr->userid, ptr->fullname);
		}
		ptr = ptr->next;
	} while (ptr != NULL);
	printf("\n\n\n");
}

void tofindtown(struct list* List, char* array)
{
	struct node* ptr;
	ptr = List->head;
	printf("\n\n\n");
	do {
		if (!strcmp(array, ptr->town)) {
			printf("\n%d. %s", ptr->userid, ptr->fullname);
		}
		ptr = ptr->next;
	} while (ptr != NULL);
	printf("\n\n\n");
}

void tofindeducation(struct list* List, char* array)
{
	struct node* ptr;
	ptr = List->head;
	printf("\n\n\n");
	do {
		if (!strcmp(array, ptr->education)) {
			printf("\n%d. %s", ptr->userid, ptr->fullname);
		}
		ptr = ptr->next;
	} while (ptr != NULL);
	printf("\n\n\n");
}

void printnames(struct list* List)
{
	struct node* ptr;
	ptr = List->head;
	do {
		printf("\n\n\n");
		printf("%d. %s", ptr->userid, ptr->fullname);
		ptr = ptr->next;
	} while (ptr != NULL);
}

int main() {
	FILE* file;
	char array[80];
	int i = 0, z = 0, counter = 0;
	list* users = (struct list*)malloc(sizeof(struct list) * 10);
	users->head = NULL;
	char fullname[32], town[32], company[32], hobbies[32], education[32], search[32];
	int id = 1, choice1, choice2, eraseid, link1, link2, showlink;
	while (1) {
		printf("What action would you choose?\n1 - Create new user\n2 - See all users\n3 - Delete user(id)\n4 - Add new acquaintances(id) \n5 - Show acquaintances(id)\n6 - Find user\n7 - Create 5 generated users\n8 - Leave\nNumber: ");
		scanf("%d", &choice1);
		if (choice1 == 1) {
			printf("Enter fullname: ");
			scanf("%s", fullname);
			printf("Enter town: ");
			scanf("%s", town);
			printf("Enter education: ");
			scanf("%s", education);
			printf("Enter company: ");
			scanf("%s", company);
			printf("Enter hobbies: ");
			scanf("%s", hobbies);
			users = Startlist(users, fullname, town, company, education, hobbies, id);
			id++;
		}
		if (choice1 == 2 && id > 1) {
			toprintlist(users);
		}
		if (choice1 == 3) {
			while (1) {
				printf("Enter id: ");
				scanf("%d", &eraseid);
				if (eraseid < id && eraseid > 0) {
					if (eraseid == 1) {
						erase_first(users);
					}
					else {
						users = eraseel(users, eraseid);
					}
					break;
				}
				else {
					if (id != 1) {
						printf("\nRe-enter id!\n");
					}
				}
			}
		}
		if (choice1 == 4) {
			while (1) {
				printnames(users);
				printf("\nEnter id of the first user: ");
				scanf("%d", &link1);
				printf("Enter id of the second user: ");
				scanf("%d", &link2);
				if (link1 < id && link1 > 0 && link1 < id && link1 > 0) {
					users = createlink(users, link1, link2);
					users = createlink(users, link2, link1);
					break;
				}
				else {
					printf("\nRe-enter id!\n");
				}
			}
		}
		if (choice1 == 5) {
			printnames(users);
			while (1) {
				printf("\nEnter id: ");
				scanf("%d", &showlink);
				if (showlink > 0 && showlink < id) {
					seelinks(users, showlink);
					break;
				}
				else {
					printf("\nRe-enetr id!\n");
				}
			}
		}
		if (choice1 == 6) {
			while (1) {
				printf("\n1 - Search by hobbies\n2 - Search by town\n3 - Search by company\n4 - Search by education\n5 - Back\nNumber: ");
				scanf("%d", &choice2);
				if (choice2 == 1) {
					printf("\nEnter field to find: ");
					scanf("%s", search);
					tofindhobbies(users, search);
				}
				if (choice2 == 2) {
					printf("\nEnter field to find: ");
					scanf("%s", search);
					tofindhobbies(users, search);
				}
				if (choice2 == 3) {
					printf("\nEnter field to find: ");
					scanf("%s", search);
					tofindhobbies(users, search);
				}
				if (choice2 == 4) {
					printf("\nEnter field to find: ");
					scanf("%s", search);
					tofindhobbies(users, search);
				}
				if (choice2 == 5) {
					break;
				}
			}
		}
		if (choice1 == 7) {
			fopen_s(&file, "users.txt", "r");

			while ((array[i] = fgetc(file)) != EOF) {
				if (array[i] == '\n' || array[i] == ' ') {
					array[i] = '\0';
					if (z == 0) {
						strcpy(fullname, array);
					}
					if (z == 1) {
						strcpy(town, array);
					}
					if (z == 2) {
						strcpy(education, array);
					}
					if (z == 3) {
						strcpy(company, array);
					}
					if (z == 4) {
						strcpy(hobbies, array);
					}
					z++;
					if (z == 5) {
						users = Startlist(users, fullname, town, company, education, hobbies, id);
						z = 0;
						id++;
					}
					i = 0;
				}
				else i++;
			}
			array[i] = '\0';
		}
		if (choice1 == 8) {
			break;
		}
	}
	return 0;
}