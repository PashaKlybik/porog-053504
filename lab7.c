#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <windows.h>
#include <string.h>
#define CONST 30

int fileCount = 2;


struct Houses {
    char district[CONST];
    char address[CONST];
    int floor;
    int square;
    char design[CONST];
    int price;

    struct Houses* r, * l;
};

struct HousesList {
    int size;
    struct Houses* head, * tail;
};

struct Buyer { // требования покупателя
    int square;
    int price; // цена (можно будет сторговаться, если |price - cash | <= 1000 )
    char district[CONST];
    int cash; // количество денег

    struct buyer* r, * l;
};

struct BuyerList {
    int size;
    struct Buyer* head, * tail;
};

void AddHouse(struct HousesList* ptr, char* district, char* address, int floor, int square, char* design, int price);
void DeleteHouse(struct HousesList* ptr, int index);
void DeleteAllList(struct HousesList* ptr);
void LoadFromFile(struct HousesList* ptr);
void SaveInFile(struct HousesList* ptr);
void PrintHouses(struct Houses* temp);
void ShowHouses(struct HousesList* ptr);
void FindHouses(struct HousesList* ptr);
void Menu();
void set(char* a);
int check(char* a, char* b);


int main()
{
    Menu();
    return 0;
}

void set(char* a) {
    int n = strlen(a);
    a[n - 1] = '\0';
}

int check(char* a, char* b) {
    if (strlen(a) != strlen(b)) {
        return 0;
    }
    int n = strlen(a);
    for (int i = 0; i < n; i++)
        if (a[i] != b[i]) return 0;
    return 1;
}


void AddHouse(struct HousesList* ptr, char* district, char* address, int floor, int square, char* design, int price)
{
    struct Houses* cur;
    cur = (struct Houses*)malloc(sizeof(struct Houses));
    cur->l = ptr->tail;
    cur->r = NULL;

    strcpy_s(cur->district, sizeof(cur->district), district);
    strcpy_s(cur->address, sizeof(cur->address), address);
    cur->floor = floor;
    cur->square = square;
    strcpy_s(cur->design, sizeof(cur->design), design);
    cur->price = price;

    if (ptr->tail)
    {
        ptr->tail->r = cur;
        ptr->tail = ptr->tail->r;
    }
    else
        ptr->head = ptr->tail = cur;
    ptr->size++;

}

void DeleteHouse(struct HousesList* ptr, int index) {

    if (index < 0 || index >= ptr->size) return;
    struct Houses* cur = ptr->head;
    while (index--) {
        cur = cur->r;
    }
    if (cur->l) cur->l->r = cur->r;
    if (cur->r) cur->r->l = cur->l;
    free(cur);
    ptr->size--;
}

void DeleteAllList(struct HousesList* ptr) {
    if (ptr == NULL) return;
    struct Houses* cur = ptr->head;
    while (cur)
    {
        cur = cur->r;
        if (cur->l)
            free(cur->l);
    }
}

void LoadFromFile(struct HousesList* ptr) {
    FILE* file;
    fopen_s(&file, "Houses.txt", "r");
    if (!file) exit(1);

    char district[CONST];
    char address[CONST];
    char floor[CONST];
    char square[CONST];
    char design[CONST];
    char price[CONST];

    while (fgets(district, CONST, file))
    {
        set(district);
        puts(district);
        fflush(stdin);
        fgets(address, CONST, file);
        set(address);
        fflush(stdin);
        fgets(floor, CONST, file);

        fflush(stdin);
        fgets(square, CONST, file);

        fflush(stdin);
        fgets(design, CONST, file);
        set(design);
        fflush(stdin);
        fgets(price, CONST, file);

        fflush(stdin);
        AddHouse(ptr, district, address, atoi(floor), atoi(square), design, atoi(price));

    }
    fflush(stdin);
    fclose(file);
}

void SaveInFile(struct HousesList* ptr) {
    FILE* file;
    fopen_s(&file, "HousesOutput.txt", "w");
    struct Houses* temp = ptr->head;

    if (!file || !(temp))
        exit(1);
    while (temp)
    {
        char floor[6], square[6], price[6];
        _itoa_s(temp->floor, floor, sizeof(floor), 10);
        _itoa_s(temp->square, square, sizeof(square), 10);
        _itoa_s(temp->price, price, sizeof(price), 10);
        fputs(temp->district, file);
        fputs("\n", file);
        fputs(temp->address, file);
        fputs("\n", file);
        fputs(floor, file);
        fputs("\n", file);
        fputs(square, file);
        fputs("\n", file);
        fputs(temp->design, file);
        fputs("\n", file);
        fputs(price, file);
        fputs("\n", file);
        temp = temp->r;
    }
    fclose(file);
}

void PrintHouses(struct Houses* temp) {
    char floor[6], square[6], price[6];
    _itoa_s(temp->floor, floor, sizeof(floor), 10);
    _itoa_s(temp->square, square, sizeof(square), 10);
    _itoa_s(temp->price, price, sizeof(price), 10);
    puts("\n");
    puts("District :");
    puts(temp->district);
    puts("Address : ");
    puts(temp->address);
    puts("Floor : ");
    puts(floor);
    puts("Square : ");
    puts(square);
    puts("Design");
    puts(temp->design);
    puts("Price : ");
    puts(price);
    puts("\n");
    puts("----------------------------------------------------------------");
}

void ShowHouses(struct HousesList* ptr) {
    struct Houses* temp = ptr->head;
    int counter = 0;
    while (temp)
    {
        printf("%d%c", counter++, '.');
        PrintHouses(temp);
        temp = temp->r;
    }
    puts("\n");
}

void FindHouses(struct HousesList* ptr) {
    struct Houses* temp = ptr->head;
    int a = ptr->size;
    char district[CONST];
    int square;
    int price;
    puts("Enter district : ");
    scanf("%s", district);
    puts("Enter square : ");
    scanf("%d", &square);
    puts("Enter price : ");
    scanf("%d", &price);
    int counter = 0;
    while (a--)
    {
        if ((check(district, temp->district) == 1) && square >= temp->square && price >= temp->price)
        {
            printf("%d%c", counter++, '.');
            PrintHouses(temp);
        }
        temp = temp->r;
    }
}

void Menu() {

    struct HousesList* HousesBase;
    HousesBase = (struct HousesList*)malloc(sizeof(struct HousesList));
    HousesBase->size = 0;
    HousesBase->head = HousesBase->tail = NULL;
    LoadFromFile(HousesBase);
    ShowHouses(HousesBase);
    while (1)
    {
        puts("Choose what you gonna do : 1.Find a House , 2.Buy a House, 3.Add House to a sold, 4.Show list , 5.Exit");
        puts("Enter choice : ");
        int type;
        scanf("%d", &type);
        puts("");
        switch (type)
        {
        case 1:
            FindHouses(HousesBase);
            break;
        case 2:
        {
            int* index;
            puts("Enter the index : ");
            scanf("%d", &index);
            DeleteHouse(HousesBase, index);
            break;

        }
        case 3:
        {
            char district[CONST];
            char address[CONST];
            int floor;
            int square;
            char design[CONST];
            int price;

            puts("Enter district : ");
            scanf("%s", district);
            puts("Enter address : ");
            scanf("%s", address);
            puts("Enter floor");
            scanf("%d", &floor);
            puts("Enter square : ");
            scanf("%d", &square);
            puts("Enter design : ");
            scanf("%s", design);
            puts("Enter price : ");
            scanf("%d", &price);
            AddHouse(HousesBase, district, address, floor, square, design, price);
            break;
        }
        case 4: { ShowHouses(HousesBase); SaveInFile(HousesBase); } break;
        case 5: puts("Bye, have a great time"); exit(0); break;
        default: break;

        }
    }
}