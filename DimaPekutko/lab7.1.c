#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <json-c/json.h>

#define FILE_BUFFER_SIZE 2048
#define MENU_LENGTH 6

typedef struct user {
	int id;
	const char *name;
	int sex;
	int birthData;
	int height;
	int weight;
	const char *city;
	int badHabits;
	const char *aboutUser;
	const char *partnerReq;
} User;

typedef struct node {
    struct node *next;
    struct node *prev;
    User *data;
} Node;

typedef struct users {
    Node *head;
    Node *tail;
    int length;
} UsersList;

int getch(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}

void flushInput()
{
    // Keep reading from input stream until a newline is read
    int c;
    do
    {
        if ((c = getchar()) == EOF) exit(1);
    } while (c != '\n');
}

int getInt()
{
    int n;
    char c;
    while(1)
    {
        // scanf will return 2 if the conversion is succesful, i.e.
        // if it could scan first an integer and then a character
        if (scanf("%d%c", &n, &c) == 2 && c == '\n') return n;

        // Conversion failed so flush the input stream
        flushInput();
    }
}

void addUserToList(User *user, UsersList *usersList) {
	Node *node = (Node*)malloc(sizeof(Node));
	node->data = user;
    node->next = NULL;
    node->prev = NULL;
    if(!usersList->length) {
        usersList->head = node;
        usersList->tail = node;
    }
    else {
        usersList->tail->next = node;
        node->prev = usersList->tail;
        usersList->tail = node;
    }
    usersList->length++;
}

int deleteUserFromList(UsersList *usersList, int id) {
	Node *current = usersList->head;
    int count = 0;
	while(current) {
		if(current->data->id == id) {
			if(usersList->length == 1) {
				free(current->data);
				free(current);
				usersList->head = NULL;
				usersList->tail = NULL;
				usersList->length = 0;
				return 0;
			}
			else {
				if(count == 0) {
					usersList->head = current->next;
					free(current->data);
					free(current);
					usersList->head->prev = NULL;
					usersList->length--;
					return 0;
				}
				else if(count == (usersList->length-1)) {
					usersList->tail = current->prev;
					free(current->data);
					free(current);
					usersList->tail->next = NULL;
					usersList->length--;
					return 0;
				}
				else {
					Node *leftNode = current->prev;
					Node *rightNode = current->next;
					leftNode->next = current->next;
					rightNode->prev = current->prev;
					free(current->data);
					free(current);
					usersList->length--;
					return 0;
				}
			}
		}
		count++;
    	current = current->next;
	}
	return -1;
}

void fillUsersList(struct json_object *jsonUsers, UsersList *usersList) {
	for(int i = 0; i < json_object_array_length(jsonUsers); i++) {
		User *user = (User*)malloc(sizeof(User));
		struct json_object *jsonId;
		struct json_object *jsonName;
		struct json_object *jsonSex;
		struct json_object *jsonBirthData;
		struct json_object *jsonHeight;
		struct json_object *jsonWeight;
		struct json_object *jsonCity;
		struct json_object *jsonbadHabits;
		struct json_object *jsonAboutUser;
		struct json_object *jsonPartnerReq;
		json_object_object_get_ex(
			json_object_array_get_idx(jsonUsers, i), "id", &jsonId);
		json_object_object_get_ex(
			json_object_array_get_idx(jsonUsers, i), "name", &jsonName);
		json_object_object_get_ex(
			json_object_array_get_idx(jsonUsers, i), "sex", &jsonSex);
		json_object_object_get_ex(
			json_object_array_get_idx(jsonUsers, i), "birthDate", &jsonBirthData);
		json_object_object_get_ex(
			json_object_array_get_idx(jsonUsers, i), "height", &jsonHeight);
		json_object_object_get_ex(
			json_object_array_get_idx(jsonUsers, i), "weight", &jsonWeight);
		json_object_object_get_ex(
			json_object_array_get_idx(jsonUsers, i), "city", &jsonCity);
		json_object_object_get_ex(
			json_object_array_get_idx(jsonUsers, i), "badHabits", &jsonbadHabits);
		json_object_object_get_ex(
			json_object_array_get_idx(jsonUsers, i), "aboutUser", &jsonAboutUser);
		json_object_object_get_ex(
			json_object_array_get_idx(jsonUsers, i), "partnerReq", &jsonPartnerReq);
		user->id = json_object_get_int(jsonId);
		user->name = json_object_get_string(jsonName);
		user->sex = json_object_get_int(jsonSex);
		user->birthData = json_object_get_int(jsonBirthData);
		user->height = json_object_get_int(jsonHeight);
		user->weight = json_object_get_int(jsonWeight);
		user->city = json_object_get_string(jsonCity);
		user->badHabits = json_object_get_int(jsonbadHabits);
		user->aboutUser = json_object_get_string(jsonAboutUser);
		user->partnerReq = json_object_get_string(jsonPartnerReq);
		addUserToList(user, usersList);
	}
}

UsersList *searchByFields(UsersList *usersList) {
		UsersList *searchesList = (UsersList*)malloc(sizeof(UsersList));
		Node *current = usersList->head;
		char *name;
				char name1[30];
				int sex;
				int minBD;
				int maxBD;
				int minHeight;
				int maxHeight;
				int minWeight;
				int maxWeight;
				char* city;
				char city1[30];
				int badHabits;
				printf("Name:\n");
				scanf("%s", name1);
				printf("Sex:\n");
				sex = getInt();
				printf("Min birthday date:\n");
				minBD = getInt();
				printf("Max birthday date:\n");
				maxBD = getInt();
				printf("Min height:\n");
				minHeight = getInt();
				printf("Max height:\n");
				maxHeight = getInt();
				printf("Min weight:\n");
				minWeight = getInt();
				printf("Max weight:\n");
				maxWeight = getInt();
				printf("City:\n");
				scanf("%s", city1);
				name = name1; city = city1;
		while(current) {
			if(strlen(name) && strcmp(name, current->data->name)) {
				// printf("name");
				current = current->next; 
				continue;
			}
			if(sex && sex != current->data->sex) {
				// printf("sex");
				current = current->next; 
				continue;
			}
			if((minBD && maxBD) && (minBD > current->data->birthData || maxBD < current->data->birthData)) {
				// printf("BD");
				current = current->next; 
				continue;
			}
			if((minHeight && maxHeight) && (minHeight > current->data->height || maxHeight < current->data->height)) {
				// printf("h");
				current = current->next; 
				continue;
			}
			if((minWeight && maxWeight) && (minWeight > current->data->weight|| maxWeight < current->data->weight)) {
				// printf("w");
				current = current->next; 
				continue;
			}
			if(strlen(city) && strcmp(city, current->data->city)) {
				// printf("city");
				current = current->next; 
				continue;
			}
			// if(badHabits && badHabits != current->data->badHabits) {
			// 	// printf("bh");
			// 	current = current->next; 
			// 	continue;
			// }
			addUserToList(current->data, searchesList);
			current = current->next;
		}
		return searchesList;
}

void printPairProb(User *firstUser, User *secondUser, int prob) {
	printf(
		"%d:%s\t%d%%\t%d:%s\n", 
		firstUser->id, firstUser->name, prob, secondUser->id, secondUser->name
	);
}

void printAutoSearch(UsersList *usersList) {
	UsersList *searchesList = (UsersList*)malloc(sizeof(UsersList));
	Node *current = usersList->head;
    Node *subCurrent;
	int pairProb;
	while(current) {
		subCurrent = current;
		while(subCurrent) {
			pairProb = 100;
			if(current->data->id != subCurrent->data->id) {
				int birthDataOffset = 
					abs(current->data->birthData-subCurrent->data->birthData);
				int heightOffset =
					abs(current->data->height-subCurrent->data->height);
				int weightOffset =
					abs(current->data->weight-subCurrent->data->weight);
				int cityConcidence = 1;
				for(int i = 0; i < 50; i++) {
					if(current->data->city[i] != subCurrent->data->city[i]) {
						cityConcidence = 0;
						break;
					}
					if(current->data->city[i] == '\0') 
						break;
				}
				int badHabitsConfidence =
					current->data->badHabits == subCurrent->data->badHabits ? 1 : 0;
				
				if(birthDataOffset > 10) {
					pairProb -= 20;
				}
				if(heightOffset > 10) {
					pairProb -= 20;
				}
				if(weightOffset > 10) {
					pairProb -= 20;
				}
				if(!cityConcidence) {
					pairProb -= 20;
				}
				if(!badHabitsConfidence) {
					pairProb -= 20;
				}
				printPairProb(current->data, subCurrent->data, pairProb);
			}
			subCurrent = subCurrent->next;
		}
    	current = current->next;
    }
}

void printUsersList(UsersList *usersList) {
	Node *current = usersList->head;
    while(current) {
    	printf("\033[32;41;1m\tUser:\033[0m\n");
    	printf("id:%d\n", current->data->id);
    	printf("name:%s\n", current->data->name);
    	printf("sex:%d\n", current->data->sex);
    	printf("birth year:%d\n", current->data->birthData);
    	printf("height:%d\n", current->data->height);
    	printf("weight:%d\n", current->data->weight);
    	printf("city:%s\n", current->data->city);
    	printf("bad habits:%d\n", current->data->badHabits);
    	printf("about user:%s\n", current->data->aboutUser);
    	printf("partner requirments:%s\n", current->data->partnerReq);
    	current = current->next;
    }
    printf("\n");
}

void clearUsersList(UsersList *usersList) {
	Node *current = usersList->head;
    while(current) {
    	Node *next = current->next;
    	free(current->data);
		free(current);
		current = next;
    }
    printf("\n");
}

struct json_object *getUsers(char fileBuffer[]) {
	struct json_object *parsed_json;
	struct json_object *users;

	parsed_json = json_tokener_parse(fileBuffer);
	json_object_object_get_ex(parsed_json, "users", &users);
	return users;
}

int getLastUserId(UsersList *usersList) {
	Node *current = usersList->head;
    while(current) {
    	if(current->next == NULL)
			return current->data->id;
    	current = current->next;
    }
	return 0;
}

User *getUserById(UsersList *usersList, int id) {
	Node *current = usersList->head;
    while(current) {
    	if(current->data->id == id)
			return current->data;
    	current = current->next;
    }
	return NULL;
}

void deleteUserFromFile(int id) {
	char command[50];
	snprintf(command, 256, "%s%d", "node deleter ", id);
	system(command);
}

void putInArchive(User *firstUser, User *secondUser, char fileBuffer[]) {
	FILE *archFile;
	archFile = fopen("archive.json", "w+");
	struct json_object *json_users = getUsers(fileBuffer);
	for(int i = 0; i < json_object_array_length(json_users); i++) {
		struct json_object *jsonId;
		int id;
		json_object_object_get_ex(
			json_object_array_get_idx(json_users, i), "id", &jsonId);
		id = json_object_get_int(jsonId);
		if(firstUser->id == id || secondUser->id == id) {
			struct json_object *jsonObj = json_object_array_get_idx(json_users, i);
			const char *jsonObjStr = json_object_get_string(jsonObj);
			fputs(jsonObjStr, archFile);
		}
	}
	fclose(archFile);
}

void drawMenu(char **menu, int index) {
	for(int i = 0; i < MENU_LENGTH; i++) {
		if(index == i)
			printf("\033[36;41;1m\t%s\033[0m\n", menu[i]);
		else
			printf("\033[37;40;3m\t%s\033[0m\n", menu[i]);
	}
	printf("\n");
}

int main() {
	FILE *dataFile;
	char fileBuffer[FILE_BUFFER_SIZE];
	dataFile = fopen("data.json", "r");
	fread(fileBuffer, FILE_BUFFER_SIZE, 1, dataFile);
	struct json_object *jsonUsers = getUsers(fileBuffer);
	UsersList usersList;
	usersList.head = NULL;
	usersList.tail = NULL;
	usersList.length = 0;

	fillUsersList(jsonUsers, &usersList);

	char *mainMenu[MENU_LENGTH] = {
		 "Find by parameters", 
		 "Automated search", 
		 "Print all users", 
		 "Create date invitation",
		 "Delete user by id",
		 "Put pair to archive"
	};
	int mainMenuIndex = 0;
	int symbolCode;

	while(1) {
		system("clear");
		printf("\033[30;47;9mMarriage Agency\033[0m\n\n");
		drawMenu(mainMenu, mainMenuIndex);
		symbolCode = getch();

		//top
		if(symbolCode == 119) {
			mainMenuIndex--;
			if(mainMenuIndex < 0)
				mainMenuIndex = MENU_LENGTH-1;
		}
		//down
		if(symbolCode == 115) {
			mainMenuIndex++;
			if(mainMenuIndex > MENU_LENGTH-1)
				mainMenuIndex = 0;
		}
		//enter
		if(symbolCode == 10) {
			system("clear");
			if(mainMenuIndex == 0) {
				UsersList *searchResults = searchByFields(&usersList);
				printf("\033[32;44;1mSEARCH RESULTS(%d):\033[0m\n", searchResults->length);
				printUsersList(searchResults);
				free(searchResults);
				getch();
			}
			else if(mainMenuIndex == 1) {
				printf("\033[32;44;1mAll Pairs Probabilities:\033[0m\n\n");
				printAutoSearch(&usersList);
			}
			else if(mainMenuIndex == 2) {
				printf("\033[32;44;1mAll Users:\033[0m\n");
				printUsersList(&usersList);
			}
			else if(mainMenuIndex == 3) {
				int firstId, secondId;
				User *firstUser, *secondUser;
				printf("\033[32;44;1mCreate date invitations to users:\033[0m\n\n");
				printf("First user id: ");
				firstId = getInt();
				printf("Second user id: ");
				secondId = getInt();
				firstUser = getUserById(&usersList, firstId);
				secondUser = getUserById(&usersList, secondId);
				if(firstUser == NULL || secondUser == NULL) {
					printf("\nNo user founded!\n");
					getch();
					continue;
				}
				else {
					char invitationText[256];
					printf("\nDate invitation for %s and %s\n", firstUser->name, secondUser->name);
					printf("City of date: %s\n", firstUser->city);
					printf("Type invitation text: \n");
					fgets(invitationText, 256, stdin);
					system("clear");
					printf("Invitation to %s:\n", firstUser->name);
					printf("\033[30;47;3m\tDear %s\033[0m\n", firstUser->name);
					printf("\033[30;47;3m\tYou invited on the date with %s!\033[0m\n", secondUser->name);
					printf("\033[30;47;3m\tDate Location - %s\033[0m\n", firstUser->city);
					printf("\033[30;47;3m\tTime - 10.05.2021\033[0m\n");
					printf("\033[30;47;3m\t%s\033[0m", invitationText);
					printf("\033[34;47;3m\tYour's Marriage Agency\033[0m\n");
					printf("\n");
					printf("Invitation to %s:\n", secondUser->name);
					printf("\033[30;47;3m\tDear %s\033[0m\n", secondUser->name);
					printf("\033[30;47;3m\tYou invited on the date with %s!\033[0m\n", firstUser->name);
					printf("\033[30;47;3m\tDate Location - %s\033[0m\n", firstUser->city);
					printf("\033[30;47;3m\tTime - 10.05.2021\033[0m\n");
					printf("\033[30;47;3m\t%s\033[0m", invitationText);
					printf("\033[34;47;3m\tYour's Marriage Agency\033[0m\n");
					printf("\033[37;41;1m\nSended!\033[0m\n");
				}
				getch();
			}
			else if(mainMenuIndex == 4) {
				int id;
				printf("\033[32;44;1mType user's id which you want to delete:\n\n\033[0m");
				id = getInt();
				printf("\n");
				if(deleteUserFromList(&usersList, id)) {
					printf("\033[31;10;1mUser can not be found!\033[0m");
				}
				else {
					deleteUserFromFile(id);
					printf("\033[31;10;1mUser deleted!\033[0m");
				}
			}
			else if(mainMenuIndex == 5) {
				int firstId, secondId;
				User *firstUser, *secondUser;
				printf("\033[32;44;1mCreate date invitations to users:\033[0m\n\n");
				printf("First user id: ");
				firstId = getInt();
				printf("Second user id: ");
				secondId = getInt();
				firstUser = getUserById(&usersList, firstId);
				secondUser = getUserById(&usersList, secondId);
				if(firstUser == NULL || secondUser == NULL) {
					printf("\nNo user founded!\n");
					getch();
					continue;
				}
				else {
					putInArchive(firstUser, secondUser, fileBuffer);
					printf("This pair moved to archive.");
				}
			}
			getch();
		}
		//quit
		if(symbolCode == 113) {
			printf("Good Bye!\n");
			break;
		}
	}
	clearUsersList(&usersList);
	fclose(dataFile);
	return 0;
}
