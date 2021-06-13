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
	char name[30];
	char city[20];
	char education[20];
	char workplace[20];
	char interests[20];
	int userid;
};

struct list {
	struct node* head;
	struct node* tail;
	struct node* buf1;
	struct node* buf2;
};


struct list* createlist(struct list* lst, char* Name, char* City, char* Education, char* Workplace, char* Interests, int Userid)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	struct node* p = lst->tail;
	temp->userid = Userid;
	for (int i = 0; i < strlen(Name); i++)
	{
		temp->name[i] = Name[i];
	}
	temp->name[strlen(Name)] = '\0';
	for (int i = 0; i < strlen(City); i++)
	{
		temp->city[i] = City[i];
	}
	temp->city[strlen(City)] = '\0';
	for (int i = 0; i < strlen(Education); i++)
	{
		temp->education[i] = Education[i];
	}
	temp->education[strlen(Education)] = '\0';
	for (int i = 0; i < strlen(Workplace); i++)
	{
		temp->workplace[i] = Workplace[i];
	}
	temp->workplace[strlen(Workplace)] = '\0';
	for (int i = 0; i < strlen(Interests); i++)
	{
		temp->interests[i] = Interests[i];
	}
	temp->interests[strlen(Interests)] = '\0';
	temp->counter = 0;
	for (int i = 0; i < 30; i++) {
		temp->id[i] = 0;
	}

	if (lst->head == NULL) {
		lst->head = temp;
		lst->tail = temp;
		lst->head->next = NULL;
		lst->head->prev = NULL;
	}
	else {
		p = lst->tail;
		lst->tail->next = temp;
		lst->tail = lst->tail->next;
		lst->tail->next = NULL;
		lst->tail->prev = p;
	}
	
	return lst;
}

struct list* deletelem(list* lst, int usid)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp = lst->head;
	temp->prev = NULL;
	lst->buf1 = temp;
	while (temp->next != NULL && temp->next->userid != usid)
	{
		temp = temp->next;
	}
	if (temp->next != NULL) {
		temp->next = temp->next->next;
		lst->head = lst->buf1;

		struct node* p;
		p = lst->head;
		do {
			if (p->next == NULL) {
				lst->tail = p;
			}
			p = p->next;
		} while (p != NULL);
	}
	else {
		printf("\nEnter correct id!\n");
	}
	return lst;
}

struct list* addlink(list* lst, int id1, int id2) {
	
	struct node* temp1 = (struct node*)malloc(sizeof(struct node));
	temp1 = lst->head;
	lst->buf1 = temp1;
	while (temp1->next != NULL && temp1->userid != id1)
	{
		temp1 = temp1->next;
	}

	
	temp1->id[temp1->counter] = id2;
	temp1->counter++;

	lst->head = lst->buf1;

	return lst;
}

void showlinks(list* lst, int id) {
	struct node* temp1 = (struct node*)malloc(sizeof(struct node));
	struct node* temp2 = (struct node*)malloc(sizeof(struct node));
	int i = 0;
	temp1 = lst->head;
	while (temp1->next != NULL && temp1->userid != id)
	{
		temp1 = temp1->next;
	}
	printf("\n----------------\n");
	printf("Friends:\n");
	while (temp1->id[i] != 0) {
		temp2 = lst->head;
		while (temp2->next != NULL && temp2->userid != temp1->id[i])
		{
			temp2 = temp2->next;
		}
		printf("%d. %s\n", temp1->id[i], temp2->name);
		i++;
	}
	printf("\n----------------\n");
}

void delete_first(list* lst)
{
	lst->head = lst->head->next;
}

void listprint(struct list* lst)
{
	struct node* p;
	p = lst->head;
	do {
		printf("\n----------------\n");
		printf("User's id: %d", p->userid);
		printf("\nUsername: %s", p->name);
		printf("\nUser's workplace: %s", p->workplace);
		printf("\nUser's city: %s", p->city);
		printf("\nUser's education: %s", p->education);
		printf("\nUser's interests: %s", p->interests);
		printf("\n----------------\n");
		p = p->next;
	} while (p != NULL);
}

void searchinterests(struct list* lst, char* arr)
{
	struct node* p;
	p = lst->head;
	printf("\n----------------\n");
	do {
		if (!strcmp(arr, p->interests)) {
			printf("\n%d. %s",p->userid, p->name);
		}
		p = p->next;
	} while (p != NULL);
	printf("\n----------------\n");
}

void searchworkplace(struct list* lst, char* arr)
{
	struct node* p;
	p = lst->head;
	printf("\n----------------\n");
	do {
		if (!strcmp(arr, p->workplace)) {
			printf("\n%d. %s",p->userid, p->name);
		}
		p = p->next;
	} while (p != NULL);
	printf("\n----------------\n");
}

void searchcity(struct list* lst, char* arr)
{
	struct node* p;
	p = lst->head;
	printf("\n----------------\n");
	do {
		if (!strcmp(arr, p->city)) {
			printf("\n%d. %s", p->userid, p->name);
		}
		p = p->next;
	} while (p != NULL);
	printf("\n----------------\n");
}

void searcheducation(struct list* lst, char* arr)
{
	struct node* p;
	p = lst->head;
	printf("\n----------------\n");
	do {
		if (!strcmp(arr, p->education)) {
			printf("\n%d. %s", p->userid, p->name);
		}
		p = p->next;
	} while (p != NULL);
	printf("\n----------------\n");
}

void listprintnames(struct list* lst)
{
	struct node* p;
	p = lst->head;
	do {
		printf("\n----------------\n");
		printf("%d. %s", p->userid, p->name);
		p = p->next;
	} while (p != NULL);
}

int main() {
	FILE* file;
	char arr[80];
	int i = 0, z = 0, counter = 0;
	list* users = (struct list*)malloc(sizeof(struct list) * 10);
	users->head = NULL;
	char name[32], city[32], workplace[32], interests[32], education[32], search[32];
	int id = 1, choice, choice1, delid, link1, link2, showlink;
	while (1) {
		printf("What would you like to do?\n1 - Add user\n2 - Show users\n3 - Delete user(id)\n4 - Add friend(id) \n5 - Show friends(id)\n6 - Search users\n7 - Add generated users(5 people)\n8 - Exit\nInput: "); 
		scanf("%d", &choice);
		if(choice == 1){
			printf("Enter name: ");
			scanf("%s", name);
			printf("Enter city: ");
			scanf("%s", city);
			printf("Enter education: ");
			scanf("%s", education);
			printf("Enter workplace: ");
			scanf("%s", workplace);
			printf("Enter interests: ");
			scanf("%s", interests);
			users = createlist(users, name, city, workplace, education, interests, id);
			id++;
		}
		if (choice == 2 && id > 1) {
			listprint(users);
		}
		if (choice == 3) {
			while (1) {
				printf("Enter id: ");
				scanf("%d", &delid);
				if (delid < id && delid > 0) {
					if (delid == 1) {
						delete_first(users);
					}
					else {
						users = deletelem(users, delid);
					}
					break;
				}
				else {
					if (id != 1) {
						printf("\nEnter correct id!\n");
					}
				}
			}
		}
		if (choice == 4) {
			while (1) {
				listprintnames(users);
				printf("\nEnter id of the first user: ");
				scanf("%d", &link1);
				printf("Enter id of the second user: ");
				scanf("%d", &link2);
				if (link1 < id && link1 > 0 && link1 < id && link1 > 0) {
					users = addlink(users, link1, link2);
					users = addlink(users, link2, link1);
					break;
				}
				else {
					printf("\nEnter correct id!\n");
				}
			}
		}
		if (choice == 5) {
			listprintnames(users);
			while (1) {
				printf("\nEnter id: ");
				scanf("%d", &showlink);
				if (showlink > 0 && showlink < id) {
					showlinks(users, showlink);
					break;
				}
				else {
					printf("\nEnter correct id!\n");
				}
			}
		} 
		if (choice == 6) {
			while (1) {
				printf("\n1 - Search by interests\n2 - Search by city\n3 - Search by workplace\n4 - Search by education\n5 - Back\nInput: ");
				scanf("%d", &choice1);
				if (choice1 == 1) {
					printf("\nEnter string for search: ");
					scanf("%s", search);
					searchinterests(users, search);
				}
				if (choice1 == 2) {
					printf("\nEnter string for search: ");
					scanf("%s", search);
					searchinterests(users, search);
				}
				if (choice1 == 3) {
					printf("\nEnter string for search: ");
					scanf("%s", search);
					searchinterests(users, search);
				}
				if (choice1 == 4) {
					printf("\nEnter string for search: ");
					scanf("%s", search);
					searchinterests(users, search);
				}
				if (choice1 == 5) {
					break;
				}
			}
		}
		if (choice == 7) {
			fopen_s(&file, "fscanf.txt", "r");

			while ((arr[i] = fgetc(file)) != EOF) {
				if (arr[i] == '\n' || arr[i] == ' ') {
					arr[i] = '\0';
					if (z == 0) {
						strcpy(name, arr);
					}
					if (z == 1) {
						strcpy(city, arr);
					}
					if (z == 2) {
						strcpy(education, arr);
					}
					if (z == 3) {
						strcpy(workplace, arr);
					}
					if (z == 4) {
						strcpy(interests, arr);
					}
					z++;
					if (z == 5) {
						users = createlist(users, name, city, workplace, education, interests, id);
						z = 0;
						id++;
					}
					i = 0;
				}
				else i++;
			}
			arr[i] = '\0';
		}
		if(choice == 8){
			break;
		}
	}
	return 0;
}