#include "Tour.h"

bool fgetsmy (char* buffer, FILE* file){
	if (strlen(buffer) == 0) return fgets(buffer, TS, file) != NULL;
	else return true;
}

bool checkNumberInput(int nextStep, int len) {
	if (nextStep < 1 || nextStep > len) {
		printf("Wrong Input! :()...\nTry again\n");
		return true;
	}
	return false;
}
bool clearInput() {
	while (getchar() != '\n');
	return true;
}

// ------------------------------------------------------------------------------------------------------------------------

List* readFile() {
	FILE* file = fopen("DataBaseOpening.txt", "r");
	if (file == NULL) {
		printf("Cannot open the file. \n\n");
		exit(1);
	}
	char separator[] = " ,'->?!;:";
	List* list = (List*)malloc(sizeof(List));
	list->toursAmount = 0;
	list->head = NULL;
	list->tail = NULL;
	bool isNextTour = true;
	char buffer[TS] = "";
	do {
		int nowString = 0, peopleAmount = 0;
		Tour* tour = (Tour*)malloc(sizeof(Tour));
		tour->selfTour = false;
		tour->next = NULL;
		tour->prev = NULL;
		Collective* collective = (Collective*)malloc(sizeof(Collective));
		collective->head = NULL;
		collective->tail = NULL;
		NecessaryServicesList* necSer = (NecessaryServicesList*)malloc(sizeof(NecessaryServicesList));
		necSer->head = NULL;
		necSer->tail = NULL;
		while (fgetsmy(buffer, file)) {
			int lenbuf = strlen(buffer);
			if (buffer[lenbuf - 1] == '\n') buffer[lenbuf - 1] = '\0';
			if (strlen(buffer) == 0) {
				isNextTour = true;
				break;
			}
			switch (nowString) {
			case 0: {
				char buf[TSIZE];
				int i, j;
				for (i = j = 0; buffer[i] != '\0'; i++) 
					if (buffer[i] != '\'') buf[j++] = buffer[i];
				buf[j] = '\0';
				strcpy(tour->country, buf);
				nowString++;
				break;
			}
			case 1: {
				RouteList* routeList = (RouteList*)malloc(sizeof(RouteList));
				routeList->amount = 0;
				routeList->head = NULL;
				routeList->tail = NULL;
				char* sp = strtok(buffer, "->");
				while (sp) {
					AddRoute(routeList, sp);
					sp = strtok(NULL, "->");
				}
				tour->route = routeList;
				nowString++;
				break;
			}
			case 2: {
				char* sp = strtok(buffer, ".");
				tour->dateArrival.day = atoi(sp);
				sp = strtok(NULL, ".");
				tour->dateArrival.month = atoi(sp);
				nowString++;
				break;
			}
			case 3: {
				char* sp = strtok(buffer, ".");
				tour->dateDeparture.day = atoi(sp);
				sp = strtok(NULL, ".");
				tour->dateDeparture.month = atoi(sp);
				nowString++;
				break;
			}
			case 4: {
				char* sp = strtok(buffer, "/");
				collective->allPositions = atoi(sp);
				nowString++;
				break;
			}
			case 5: {
				if (buffer[0] == '-') {
					char* sp = strtok(buffer, "-,");
					char* id = strtok(NULL, "-,");
					char* profit = strtok(NULL, "-,");
					AddPeople(collective, sp, atoi(id), atoi(profit));
					peopleAmount++;
					break;
				}
				else {
					collective->peopleAmount = peopleAmount;
					tour->collective = collective;
					nowString++;
				}
			}
			case 6: {
				necSer->cost = atoi(buffer);
				nowString++;
				break;
			}
			case 7: {
				char* sp = strtok(buffer, ",");
				while (sp) {
					AddNecService(necSer, sp);
					sp = strtok(NULL, ",");
				}
				tour->necSer = necSer;
				nowString++;
				break;
			}
			case 8: {
				UnnecessaryServicesList* unnecSer = (UnnecessaryServicesList*)malloc(sizeof(UnnecessaryServicesList));
				unnecSer->head = NULL;
				unnecSer->tail = NULL;
				char* sp = strtok(buffer, ",-");
				while (sp) {
					char* cost = strtok(NULL, ",-");
					AddUnnecService(unnecSer, sp, atoi(cost));
					sp = strtok(NULL, ",-");
				}
				tour->unnecSer = unnecSer;
				nowString++;
				break;
			}
			default: break;
			}
			strcpy(buffer, "");
		}
		UpdateTourCost(tour);
		AddTour(list, tour);


		nowString = 0;
		if (fgets(buffer, TS, file) == NULL) {
			isNextTour = false;
			break;
		}
	} while (isNextTour);
	fclose(file);
	return list;
}

// ------------------------------------------------------------------------------------------------------------------------

void AddTour(List* list, Tour* tour) {
	if (!list->head) { list->head = tour; list->tail = tour; }
	else {
		list->tail->next = tour;
		tour->prev = list->tail;
		list->tail = tour;
	}
	list->toursAmount++;
}

void DeleteTour(List* list, int i) {
	if (list->head == NULL) return;
	Tour* current = list->head;
	int j = 1;
	while (j != i && current) {
		current = current->next;
		j++;
	}
	if (current->prev != NULL)
		current->prev->next = current->next;
	if (current->next != NULL)
		current->next->prev = current->prev;

	if (current->prev == NULL)
		list->head = current->next;
	if (current->next == NULL)
		list->tail = current->prev;
	list->toursAmount--;
	freeMemTour(current);
}

// ------------------------------------------------------------------------------------------------------------------------

void freeMemTour(Tour* tour) {
	Route* rtmp = tour->route->head;
	while (rtmp) {
		Route* tmp2 = rtmp->next;
		free(rtmp);
		rtmp = tmp2;
	}
	NecessaryServices* ntmp = tour->necSer->head;
	while (ntmp) {
		NecessaryServices* tmp2 = ntmp->next;
		free(ntmp);
		ntmp = tmp2;
	}
	UnnecessaryServices* untmp = tour->unnecSer->head;
	while (untmp) {
		NecessaryServices* tmp2 = untmp->next;
		free(untmp);
		untmp = tmp2;
	}
	People* ptmp = tour->collective->head;
	while (ptmp) {
		People* tmp2 = ptmp->next;
		free(ptmp);
		ptmp = tmp2;
	}
	free(tour);
}

// ------------------------------------------------------------------------------------------------------------------------

void AddRoute (RouteList* list, char* s) {
	Route* node = (Route*)malloc(sizeof(Route));
	strcpy(node->place, s);
	node->next = NULL;
	node->prev = NULL;
	if (!list->head) { list->head = node; list->tail = node; }
	else {
		list->tail->next = node;
		node->prev = list->tail;
		list->tail = node;
	}
	list->amount++;
}

// ------------------------------------------------------------------------------------------------------------------------

void AddPeople(Collective* list, char* name, int id, int profit) {
	People* node = (People*)malloc(sizeof(People));
	strcpy(node->name, name);
	node->id = id;
	node->profit = profit;
	node->next = NULL;
	node->prev = NULL;
	if (!list->head) { list->head = node; list->tail = node; }
	else {
		list->tail->next = node;
		node->prev = list->tail;
		list->tail = node;
	}
	list->allPositions--;
	list->peopleAmount++;
}

// ------------------------------------------------------------------------------------------------------------------------

void AddNecService(NecessaryServicesList* list, char* service) {
	NecessaryServices* node = (NecessaryServices*)malloc(sizeof(NecessaryServices));
	strcpy(node->service, service);
	node->next = NULL;
	node->prev = NULL;
	if (!list->head) { list->head = node; list->tail = node; }
	else {
		list->tail->next = node;
		node->prev = list->tail;
		list->tail = node;
	}
}

// ------------------------------------------------------------------------------------------------------------------------

void AddUnnecService(UnnecessaryServicesList* list, char* service, int cost) {
	UnnecessaryServices* node = (UnnecessaryServices*)malloc(sizeof(UnnecessaryServices));
	strcpy(node->service, service);
	node->cost = cost;
	node->next = NULL;
	node->prev = NULL;
	if (!list->head) { list->head = node; list->tail = node; }
	else {
		list->tail->next = node;
		node->prev = list->tail;
		list->tail = node;
	}
}

// ------------------------------------------------------------------------------------------------------------------------

void DeleteUnnecService(UnnecessaryServicesList* list, int i) {
	if (list->head == NULL) return;
	UnnecessaryServices* current = list->head;
	int j = 1;
	while (j != i && current) {
		current = current->next;
		j++;
	}
	if (current->prev != NULL)
		current->prev->next = current->next;
	if (current->next != NULL)
		current->next->prev = current->prev;

	if (current->prev == NULL)
		list->head = current->next;
	if (current->next == NULL)
		list->tail = current->prev;
	free(current);
}

// ------------------------------------------------------------------------------------------------------------------------

int PrintListNecSer(ListOfNecessaryServicesList* list) {
	ListOfNecessaryServices* current = list->head;
	printf("List of available necessary services: \n");
	int i = 0;
	while (current) {
		printf("%d. %s (%d)\n", ++i, current->service, current->cost);
		current = current->next;
	}
	return i;
}

// ------------------------------------------------------------------------------------------------------------------------

void PrintTours(List* list) {
	Tour* current = list->head;
	int i = 1;
	while (current) {
		PrintTour(current, i++);
		current = current->next;
	}
}

// ------------------------------------------------------------------------------------------------------------------------

void UpdateTourCost(Tour* tour) {
	tour->cost = tour->necSer->cost;
	UnnecessaryServices* curUnSer = tour->unnecSer->head;
	while (curUnSer) {
		tour->cost += curUnSer->cost;
		curUnSer = curUnSer->next;
	}
}

// ------------------------------------------------------------------------------------------------------------------------

void PrintTour(Tour* tour, int i) {
	tour->selfTour ? printf("----------------- Your") : printf("----------------- Standart");
	printf(" tour #%d --------------\n", i);
	printf("Country: %s\n", tour->country);

	printf("Route: ");
	Route* currentRoute = tour->route->head;
	printf("%s", currentRoute->place);
	currentRoute = currentRoute->next;
	while (currentRoute) {
		printf(" -> ");
		printf("%s", currentRoute->place);
		currentRoute = currentRoute->next;
	}
	printf("\n");

	printf("Arrival Date: %d.%d\n", tour->dateArrival.day, tour->dateArrival.month);
	printf("Departure Date: %d.%d\n", tour->dateDeparture.day, tour->dateDeparture.month);

	printf("Amount of people: %d\n", tour->collective->peopleAmount);
	printf("Amount of positions: %d\n", tour->collective->allPositions);

	printf("Necessary Services: ");
	NecessaryServices* curNecSer = tour->necSer->head;
	printf("%s", curNecSer->service);
	curNecSer = curNecSer->next;
	while (curNecSer) {
		printf(", ");
		printf("%s", curNecSer->service);
		curNecSer = curNecSer->next;
	}
	printf("\n");

	printf("Unnecessary Services: ");
	UnnecessaryServices* curUnSer = tour->unnecSer->head;
	printf("%s (%d$)", curUnSer->service, curUnSer->cost);
	curUnSer = curUnSer->next;
	while (curUnSer) {
		printf(", ");
		printf("%s (%d$)", curUnSer->service, curUnSer->cost);
		curUnSer = curUnSer->next;
	}
	printf("\n");
	printf("Cost of the tour: %d\n\n", tour->cost);
}

// ------------------------------------------------------------------------------------------------------------------------

Tour* ChooseEditTour(List* list, int* numberEdit) {
	int len = list->toursAmount;
	int nextStep = 0;
	do {
		Tour* cur = list->head;
		printf("Choose tour ");
		int i = 1;
		printf("%d (%s)", i++, cur->country);
		cur = cur->next;
		while (cur) {
			printf(", %d (%s)", i++, cur->country);
			cur = cur->next;
		}
		printf(": ");
	} while (!scanf("%d", &nextStep) && clearInput() || checkNumberInput(nextStep, len));
	printf("\n");

	Tour* cur = list->head;
	int j = 1;
	while (j != nextStep) {
		cur = cur->next;
		j++;
	}
	*numberEdit = nextStep;
	return cur;
}

// ------------------------------------------------------------------------------------------------------------------------

void EditTour(Tour* tour) {
	int nextStep = 0;
	do {
		//while (getchar() != '\n');
		printf("1. Delete unnecessary service 2. Add unnecessary service 3. Exit: ");
	} while (!scanf("%d", &nextStep) || checkNumberInput(nextStep, 3));
	switch (nextStep) {
	case 1: {
		int choose = 0, i;
		do {
			UnnecessaryServices* cur = tour->unnecSer->head;
			printf("Choose unnecessary service ");
			i = 0;
			printf("%d (%s)", ++i, cur->service);
			cur = cur->next;
			while (cur) {
				printf(", %d (%s)", ++i, cur->service);
				cur = cur->next;
			}
			printf(": ");
		} while (!scanf("%d", &choose) && clearInput() || checkNumberInput(choose, i));
		printf("\n");

		DeleteUnnecService(tour->unnecSer, choose);
		printf("Deleted!\n");
		UpdateTourCost(tour);
		break;
	}
	case 2: {
		char service[TS];
		int cost;
		printf("Enter service: ");
		while (!scanf("%s", &service) || !strlen(service)) {
			while (getchar() != '\n');
			printf("Wrong Input! :()...\nTry again\n");
			printf("Enter service: ");
		}

		printf("Enter cost ($): ");
		while (!scanf("%d", &cost)) {
			while (getchar() != '\n');
			printf("Wrong Input! :()...\nTry again\n");
			printf("Enter cost ($): ");
		}

		AddUnnecService(tour->unnecSer, service, cost);
		printf("Added!\n");
		UpdateTourCost(tour);

		break;
	}
	case 3: return;
	default: return;
	}
}

// ------------------------------------------------------------------------------------------------------------------------

char* SmartPrintfChar(char* message) {
	printf(message);
	char s[TS];
	while (!scanf("%s", s) || !strlen(s)) {
		while (getchar() != '\n');
		printf("Wrong Input! :()...\nTry again\n");
		printf(message);
	}
	return s;
}

void SmartPrintfChar2(char* message, char s[]) {
	printf(message);
	while (!scanf("%s", s) || !strlen(s)) {
		while (getchar() != '\n');
		printf("Wrong Input! :()...\nTry again\n");
		printf(message);
	}
}

// ------------------------------------------------------------------------------------------------------------------------

int* SmartPrintfInt(char* message, int len) {
	printf(message);
	int number;
	while (!scanf("%d", &number) && clearInput() || checkNumberInput(number, len)) {
		printf(message);
	}
	return number;
}

// ------------------------------------------------------------------------------------------------------------------------

Tour* CreateMyTour(ListOfNecessaryServicesList* list_necser) {
	Tour* tour = (Tour*)malloc(sizeof(Tour));
	tour->cost = 0;
	tour->next = NULL;
	tour->prev = NULL;
	strcpy(tour->country, SmartPrintfChar("Enter country: "));


	printf("---- Entering dates ----\n");
	tour->dateArrival.day = SmartPrintfInt("Enter arrival day: ", 31);
	tour->dateArrival.month = SmartPrintfInt("Enter arrival month: ", 12);
	tour->dateDeparture.day = SmartPrintfInt("Enter departure day: ", 31);
	tour->dateDeparture.month = SmartPrintfInt("Enter departure month: ", 12);


	printf("---- Entering route ----\n");
	RouteList* route_list = (RouteList*)malloc(sizeof(RouteList));
	route_list->amount = 0;
	route_list->head = NULL;
	route_list->tail = NULL;
	do {
		char place[TS];
		SmartPrintfChar2("Continue - 0 or Enter place: ", place);
		if (!strcmp(place, "0")) break;
		AddRoute(route_list, place);
	} while (true);
	tour->route = route_list;



	printf("---- Entering positions ----\n");
	Collective* collective = (Collective*)malloc(sizeof(Collective));
	collective->allPositions = SmartPrintfInt("Enter amount of all positions: ", 100);
	collective->peopleAmount = 0;
	collective->head = NULL;
	collective->tail = NULL;
	tour->collective = collective;


	printf("---- Entering necessary services ----\n");
	NecessaryServicesList* necSer = (NecessaryServicesList*)malloc(sizeof(NecessaryServicesList));
	necSer->cost = 0;
	necSer->head = NULL;
	necSer->tail = NULL;
	do {
		int len = PrintListNecSer(list_necser);
		int choice_necser = SmartPrintfInt("Continue - 8 or Choose service: ", len+1);
		if (choice_necser == 8) break;
		ListOfNecessaryServices* tmp = FindListOfNecessaryServices(list_necser, choice_necser);
		AddNecService(necSer, tmp->service);
		necSer->cost += tmp->cost;
		NecessaryServices* current = necSer->head;
		printf("Your choice: ");
		while (current) {
			printf("%s, ", current->service);
			current = current->next;
		}
		printf("\n");
	} while (true);
	tour->necSer = necSer;


	printf("---- Entering unneccesary services ----\n");
	UnnecessaryServicesList* unnecSer = (UnnecessaryServicesList*)malloc(sizeof(UnnecessaryServicesList));
	unnecSer->head = NULL;
	unnecSer->tail = NULL;
	do {
		char service[TS];
		SmartPrintfChar2("Continue - 0 or Enter service: ", service);
		if (!strcmp(service, "0")) break;
		int cost = SmartPrintfInt("Enter cost ($): ", 100000);
		AddUnnecService(unnecSer, service, cost);
	} while (true);
	tour->unnecSer = unnecSer;


	UpdateTourCost(tour);
	return tour;
}

// ------------------------------------------------------------------------------------------------------------------------

ListOfNecessaryServices* FindListOfNecessaryServices(ListOfNecessaryServicesList* list, int j) {
	ListOfNecessaryServices* current = list->head;
	int i = 1;
	while (i != j) {
		current = current->next;
		i++;
	}
	return current;
}

// ------------------------------------------------------------------------------------------------------------------------

void SaveFile(List* list) {
	FILE* file = fopen("DataBaseSaving.txt", "w");
	if (file == NULL) {
		printf("Connot open the file");
		exit(1);
	}
	printf("File is opened\n");
	Tour* tour = list->head;
	while (tour) {
		fprintf(file, "'%s'\n", tour->country);

		Route* currentRoute = tour->route->head;
		fprintf(file, "%s", currentRoute->place);
		currentRoute = currentRoute->next;
		while (currentRoute) {
			fprintf(file, "->%s", currentRoute->place);
			currentRoute = currentRoute->next;
		}
		fprintf(file, "\n");

		fprintf(file, "%d.%d\n", tour->dateArrival.day, tour->dateArrival.month);
		fprintf(file, "%d.%d\n", tour->dateDeparture.day, tour->dateDeparture.month);
		fprintf(file, "%d\n", tour->collective->allPositions);

		People* people = tour->collective->head;
		while (people) {
			fprintf(file, "-%s,%d,%d\n", people->name, people->id, people->profit);
			people = people->next;
		}

		fprintf(file, "%d\n", tour->cost);

		NecessaryServices* necser = tour->necSer->head;
		fprintf(file, "%s", necser->service);
		necser = necser->next;
		while (necser) {
			fprintf(file, ",%s", necser->service);
			necser = necser->next;
		}
		fprintf(file, "\n");

		UnnecessaryServices* unnecser = tour->unnecSer->head;
		fprintf(file, "%s-%d", unnecser->service, unnecser->cost);
		unnecser = unnecser->next;
		while (unnecser) {
			fprintf(file, ",%s-%d", unnecser->service, unnecser->cost);
			unnecser = unnecser->next;
		}
		fprintf(file, "\n");
		fprintf(file, "\n");
		tour = tour->next;
	}

	fclose(file);
	printf("File is closed\n");
}

