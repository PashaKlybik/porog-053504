#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define MAXARR 150

using namespace std;

struct client
{
    char ID[MAXARR];
    char fullname_name[MAXARR];
    char pasport_number[MAXARR];
    char registration_date[MAXARR];
    char transaction_history[MAXARR];
    struct client* next;
    struct client* prev;
};

struct item
{
    char ID[MAXARR];
    char Client_ID[MAXARR];
    char item_name[MAXARR];
    char cost[MAXARR];
    char deposit_sum[MAXARR];
    char deposit_start_date[MAXARR];
    char deposit_end_date[MAXARR];
    struct item* next;
    struct item* prev;
};

struct client* clients_first_element = NULL;
struct item* items_first_element = NULL;

void read_client_file();
void read_client_list();
void write_client_file();
void client_addelement(struct client* client);
void client_addelement_to_list();
void delete_client_element();
//void reduct_client_element();

void read_item_file();
void read_item_list();
void write_item_file();
void item_addelement(struct item* item);
void item_addelement_to_list();
void delete_item_element(int variant, int int_pawnshop_profit, int int_sum_of_items);
void reduct_item_element(int variant, int int_pawnshop_profit, int int_sum_of_items);

void pawnshop_profit();
void sum_of_items();
void i_sum_of_items();

void print_menu();
void print_menu_1();
void print_menu_2();
void print_menu_2_1();
void print_menu_2_2();
void print_menu_3();
int get_variant(int count);

int main()
{
    setlocale(LC_ALL, "Rus");

    struct client* client = NULL;
    struct item* item = NULL;

    //reading data from file
    read_client_file();
    read_item_file();

    write_client_file();
    write_item_file();

    i_sum_of_items();
    //menu
    int variant;
    int int_pawnshop_profit = 0;
    int int_sum_of_items = 0;

    do
    {
        print_menu();

        variant = get_variant(5); // получаем номер выбранного пункта меню

        switch (variant) 
        {
        case 1:
            do
            {
                print_menu_1();

                variant = get_variant(6); // получаем номер выбранного пункта меню

                switch (variant) 
                {
                case 1:
                    read_client_list();
                    break;

                case 2:
                    client_addelement_to_list();
                    break;

                case 3:
                    delete_client_element();
                    break;

                case 4:
                    //reduct_client_element();
                    break;

                case 5:
                    system("cls");
                    printf(""); //Help
                    break;
                }

            } while (variant != 6);

            break;

        case 2:
            do
            {
                print_menu_2();

                variant = get_variant(6); // получаем номер выбранного пункта меню

                switch (variant) {
                case 1:
                    read_item_list();
                    break;

                case 2:
                    item_addelement_to_list();
                    break;

                case 3:
                    do
                    {
                        print_menu_2_1();

                        variant = get_variant(4); // получаем номер выбранного пункта меню

                        switch (variant) {
                        case 1:
                            delete_item_element(variant, int_pawnshop_profit, int_sum_of_items);
                            break;

                        case 2:
                            delete_item_element(variant, int_pawnshop_profit, int_sum_of_items);
                            break;

                        case 3:
                            system("cls");
                            printf("");//Help
                            break;
                        }

                        if (variant != 4)
                            system("pause");
                    } while (variant != 4);
                    break;

                case 4:
                    do
                    {
                        print_menu_2_2();

                        variant = get_variant(5); // получаем номер выбранного пункта меню

                        switch (variant) {
                        case 1:
                            reduct_item_element(variant, int_pawnshop_profit, int_sum_of_items);
                            break;
                            
                        case 2:
                            reduct_item_element(variant, int_pawnshop_profit, int_sum_of_items);
                            break;

                        case 3:
                            reduct_item_element(variant, int_pawnshop_profit, int_sum_of_items);
                            break;

                        case 4:
                            system("cls");
                            printf("");//Help
                            break;
                        }

                        if (variant != 5)
                            break;
                    } while (variant != 5);
                    break;
                    
                case 5:
                    system("cls");
                    printf("");//Help
                    break;
                }

                if (variant != 6)
                    system("pause");
            } while (variant != 6);
            break;

        case 3:
            do
            {
                print_menu_3();

                variant = get_variant(4); // получаем номер выбранного пункта меню

                switch (variant) {
                case 1:
                    pawnshop_profit();
                    break;

                case 2:
                    sum_of_items();
                    break;

                case 3:
                    printf("");//Help
                    break;
                }

                if (variant != 4)
                    system("pause");
            } while (variant != 4);
            break;

        case 4:
            system("cls");
            printf("Добро пожаловать в меню Ломбард_Вещей. Вы выбрали Помощь.\nВ первом пункте меню вы можете просмотреть список клиентов ломбарда, добавить нового клиента ломбарда, удалить клиента ломбарда и редактировать клиента ломбарда.\nВо втором пункте меню вы можете просмотреть список сданных вещей, добавить новую вещь, удалить вещь и редактировать вещь.\nВ третьем пункте меню вы можете просмотреть текущую прибыль ломбарда и оценочная стоимость всех хранимых вещей.\nВы находитесь в четвёртом пункте меню.\nПятый пункт меню предназначен для выхода из программы");//Help
            break;
        }

        if (variant != 5)
            system("pause"); // задерживаем выполнение, чтобы пользователь мог увидеть результат выполнения выбранного пункта
    } while (variant != 5);
}



void client_addelement(struct client* client)
{
    if (clients_first_element == NULL)
        clients_first_element = client;
    else
    {
        struct client* temp = clients_first_element;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = client;
        client->prev = temp;
    }
}

void client_addelement_to_list()
{
    system("cls");

    struct client* client;
    int size = sizeof(struct client);
    client = (struct client*)malloc(sizeof(struct client));
    client->next = NULL;
    client->prev = NULL;

    struct client* temp = clients_first_element;

    printf("Заполните данные нового пользователя, а именно:\n");
    gets_s(client->ID);

    printf("Введите ID клиента:");
    gets_s(client->ID);

    printf("Введите ФИО клиента:");
    gets_s(client->fullname_name);

    printf("Введите номер пасспорта клиента:");
    gets_s(client->pasport_number);

    printf("Введите дату регистрации клиента:");
    gets_s(client->registration_date);

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = client;
    client->prev = temp;

    write_client_file();
    item_addelement_to_list();
    write_item_file();
}

void read_client_file()
{
    FILE* fclients;
    char buffer[MAXARR];

    fclients = fopen("D:\\Clients.txt", "r");
    if (!fclients)
    {
        printf("Файл не найден. Выход из программы");
        return;
    }
    while (fgets(buffer, MAXARR, fclients) != NULL)
    {
        struct client* client;
        int size = sizeof(struct client);
        client = (struct client*)malloc(sizeof(struct client));
        client->next = NULL;
        client->prev = NULL;

        int i = 0;
        int j = 0;

        while(buffer[i] != '\n')
        {
            while(buffer[i] != ';')
            {
                client->ID[j] = buffer[i];
                if (buffer[i + 1] == ';')
                {
                    i += 2;
                    break;
                }
                i++;
                j++;
            }

            j++;
            client->ID[j] = '\0';
            j = 0;

            while (buffer[i] != ';')
            {
                client->fullname_name[j] = buffer[i];
                if (buffer[i + 1] == ';')
                {
                    i += 2;
                    break;
                }
                i++;
                j++;
            }

            j++;
            client->fullname_name[j] = '\0';
            j = 0;

            while (buffer[i] != ';')
            {
                client->pasport_number[j] = buffer[i];
                if (buffer[i + 1] == ';')
                {
                    i += 2;
                    break;
                }
                i++;
                j++;
            }

            j++;
            client->pasport_number[j] = '\0';
            j = 0;

            while (buffer[i] != ';')
            {
                client->registration_date[j] = buffer[i];
                if (buffer[i + 1] == ';' || buffer[i + 1] == '\n' || buffer[i + 1] == '\0')
                {
                    break;
                }
                i++;
                j++;
            }
            i++;
            j++;
            client->registration_date[j] = '\0';

            if (buffer[i] == '\0')
            {
                break;
            }
        }
        client_addelement(client);

    }
    fclose(fclients);
}

void write_client_file()
{
    FILE* fclients;
    char fbuffer[MAXARR];

    fclients = fopen("D:\\Clients.txt", "w");
    if (!fclients)
    {
        printf("Файл не найден. Выход из программы");
        return;
    }

    int i = 0;
    int j = 0;

    struct client* temp = clients_first_element;

    while (temp != NULL)
    {
        while (fbuffer[i] != '\n')
        {
            while (temp->ID[j] != '\0')
            {
                fbuffer[i] = temp->ID[j];
                if (temp->ID[j + 1] == '\0')
                {
                    break;
                }
                i++;
                j++;
            }

            i++;
            fbuffer[i] = ';';
            j = 0;
            i++;

            while (temp->fullname_name[j] != '\0')
            {
                fbuffer[i] = temp->fullname_name[j];
                if (temp->fullname_name[j + 1] == '\0')
                {
                    break;
                }
                i++;
                j++;
            }

            i++;
            fbuffer[i] = ';';
            j = 0;
            i++;

            while (temp->pasport_number[j] != '\0')
            {
                fbuffer[i] = temp->pasport_number[j];
                if (temp->pasport_number[j + 1] == '\0')
                {
                    break;
                }
                i++;
                j++;
            }

            i++;
            fbuffer[i] = ';';
            j = 0;
            i++;

            while (temp->registration_date[j] != '\0')
            {
                fbuffer[i] = temp->registration_date[j];
                if (temp->registration_date[j + 1] == '\0')
                {
                    break;
                }
                i++;
                j++;
            }
            i++;
            j = 0;
            fbuffer[i] = '\n';
        }
        temp = temp->next;
        i++;
    }
    i--;
    fbuffer[i] = '\0';
    fputs(fbuffer, fclients);
    fclose(fclients);
}

void read_client_list()
{
    system("cls");
    struct client* temp = clients_first_element;
    while (temp != NULL)
    {
        printf("%s\n", temp->ID);
        printf("%s\n", temp->fullname_name);
        printf("%s\n", temp->pasport_number);
        printf("%s\n\n", temp->registration_date);
        temp = temp->next;
    }
    system("pause");
}

void delete_client_element()
{
    int check = 0;

    struct client* prev = nullptr, * next = nullptr;
    struct client* temp = clients_first_element;

    printf("Введите ID клиента, которого надо удалить\n");
    scanf("%d", &check);


    while (temp != NULL) 
    {
        int ID = atoi(temp->ID);
        if (ID == check)
        {
            prev = temp->prev; // узел, предшествующий lst
            next = temp->next; // узел, следующий за lst
            if (prev != NULL)
                prev->next = temp->next; // переставляем указатель
            if (next != NULL)
                next->prev = temp->prev; // переставляем указатель
            free(temp); // освобождаем память удаляемого элемента
            break;
        }
        temp = temp->next;
    }

    write_client_file();
}

void item_addelement(struct item* item)
{
    if (items_first_element == NULL)
        items_first_element = item;
    else
    {
        struct item* temp = items_first_element;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = item;
        item->prev = temp;
    }
}

void item_addelement_to_list()
{
    system("cls");

    struct item* item;
    int size = sizeof(struct item);
    item = (struct item*)malloc(sizeof(struct item));
    item->next = NULL;
    item->prev = NULL;

    struct item* temp = items_first_element;

    printf("Заполните данные нового пользователя, а именно:\n");
    gets_s(item->ID);

    printf("Введите ID вещи:");
    gets_s(item->ID);

    printf("Введите ID клиента вещи:");
    gets_s(item->Client_ID);

    printf("Введите название вещи:");
    gets_s(item->item_name);

    printf("Введите оценочную стоимость вещи:");
    gets_s(item->cost);

    printf("Введите сумму, выданную под залог:");
    gets_s(item->deposit_sum);

    printf("Введите дату регистрации вещи:");
    gets_s(item->deposit_start_date);

    printf("Введите дату окончания хранения вещи:");
    gets_s(item->deposit_end_date);

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = item;
    item->prev = temp;

    write_item_file();
}

void read_item_file()
{
    FILE* fitems;
    char buffer[MAXARR];

    fitems = fopen("D:\\Items.txt", "r");
    if (!fitems)
    {
        printf("Файл не найден. Выход из программы");
        return;
    }
    while (fgets(buffer, MAXARR, fitems) != NULL)
    {
        struct item* item;
        int size = sizeof(struct item);
        item = (struct item*)malloc(sizeof(struct item));
        item->next = NULL;
        item->prev = NULL;

        int i = 0;
        int j = 0;

        while (buffer[i] != '\n')
        {
            while (buffer[i] != ';')
            {
                item->ID[j] = buffer[i];
                if (buffer[i + 1] == ';')
                {
                    i += 2;
                    break;
                }
                i++;
                j++;
            }

            j++;
            item->ID[j] = '\0';
            j = 0;

            while (buffer[i] != ';')
            {
                item->Client_ID[j] = buffer[i];
                if (buffer[i + 1] == ';')
                {
                    i += 2;
                    break;
                }
                i++;
                j++;
            }

            j++;
            item->Client_ID[j] = '\0';
            j = 0;

            while (buffer[i] != ';')
            {
                item->item_name[j] = buffer[i];
                if (buffer[i + 1] == ';')
                {
                    i += 2;
                    break;
                }
                i++;
                j++;
            }

            j++;
            item->item_name[j] = '\0';
            j = 0;

            while (buffer[i] != ';')
            {
                item->cost[j] = buffer[i];
                if (buffer[i + 1] == ';')
                {
                    i += 2;
                    break;
                }
                i++;
                j++;
            }

            j++;
            item->cost[j] = '\0';
            j = 0;

            while (buffer[i] != ';')
            {
                item->deposit_sum[j] = buffer[i];
                if (buffer[i + 1] == ';')
                {
                    i += 2;
                    break;
                }
                i++;
                j++;
            }

            j++;
            item->deposit_sum[j] = '\0';
            j = 0;

            while (buffer[i] != ';')
            {
                item->deposit_start_date[j] = buffer[i];
                if (buffer[i + 1] == ';')
                {
                    i += 2;
                    break;
                }
                i++;
                j++;
            }

            j++;
            item->deposit_start_date[j] = '\0';
            j = 0;

            while (buffer[i] != '\0')
            {
                item->deposit_end_date[j] = buffer[i];
                if (buffer[i + 1] == '\0' || buffer[i + 1] == '\n')
                {
                    break;
                }
                i++;
                j++;
            }
            i++;
            j++;
            item->deposit_end_date[j] = '\0';

            if (buffer[i] == '\0')
            {
                break;
            }
        }

        item_addelement(item);
    }
    fclose(fitems);
}

void write_item_file()
{
    FILE* fitems;
    char fbuffer[MAXARR];

    fitems = fopen("D:\\Items.txt", "w");
    if (!fitems)
    {
        printf("Файл не найден. Выход из программы");
        return;
    }

    int i = 0;
    int j = 0;

    struct item* temp = items_first_element;

    while (temp != NULL)
    {
        while (fbuffer[i] != '\n')
        {
            while (temp->ID[j] != '\0')
            {
                fbuffer[i] = temp->ID[j];
                if (temp->ID[j + 1] == '\0')
                {
                    break;
                }
                i++;
                j++;
            }

            i++;
            fbuffer[i] = ';';
            j = 0;
            i++;

            while (temp->Client_ID[j] != '\0')
            {
                fbuffer[i] = temp->Client_ID[j];
                if (temp->Client_ID[j + 1] == '\0')
                {
                    break;
                }
                i++;
                j++;
            }

            i++;
            fbuffer[i] = ';';
            j = 0;
            i++;

            while (temp->item_name[j] != '\0')
            {
                fbuffer[i] = temp->item_name[j];
                if (temp->item_name[j + 1] == '\0')
                {
                    break;
                }
                i++;
                j++;
            }

            i++;
            fbuffer[i] = ';';
            j = 0;
            i++;

            while (temp->cost[j] != '\0')
            {
                fbuffer[i] = temp->cost[j];
                if (temp->cost[j + 1] == '\0')
                {
                    break;
                }
                i++;
                j++;
            }

            i++;
            fbuffer[i] = ';';
            j = 0;
            i++;

            while (temp->deposit_sum[j] != '\0')
            {
                fbuffer[i] = temp->deposit_sum[j];
                if (temp->deposit_sum[j + 1] == '\0')
                {
                    break;
                }
                i++;
                j++;
            }

            i++;
            fbuffer[i] = ';';
            j = 0;
            i++;

            while (temp->deposit_start_date[j] != '\0')
            {
                fbuffer[i] = temp->deposit_start_date[j];
                if (temp->deposit_start_date[j + 1] == '\0')
                {
                    break;
                }
                i++;
                j++;
            }

            i++;
            fbuffer[i] = ';';
            j = 0;
            i++;

            while (temp->deposit_end_date[j] != '\0')
            {
                fbuffer[i] = temp->deposit_end_date[j];
                if (temp->deposit_end_date[j + 1] == '\0')
                {
                    break;
                }
                i++;
                j++;
            }
            i++;
            j = 0;
            fbuffer[i] = '\n';
        }
        temp = temp->next;
        i++;
    }
    i--;
    fbuffer[i] = '\0';
    fputs(fbuffer, fitems);
    fclose(fitems);
}

void read_item_list()
{
    system("cls");
    struct item* temp = items_first_element;
    while (temp != NULL)
    {
        printf("%s\n", temp->ID);
        printf("%s\n", temp->Client_ID);
        printf("%s\n", temp->item_name);
        printf("%s\n", temp->cost);
        printf("%s\n", temp->deposit_sum);
        printf("%s\n", temp->deposit_start_date);
        printf("%s\n\n", temp->deposit_end_date);
        temp = temp->next;
    }
    system("pause");
}

void delete_item_element(int variant, int int_pawnshop_profit, int int_sum_of_items)
{
    int check = 0;

    struct item* prev = nullptr, * next = nullptr;
    struct item* temp = items_first_element;
    if(variant == 1)
    {
        printf("Введите ID вещи, которую надо удалить\n");
        scanf("%d", &check);
        
        while (temp != NULL)
        {
            int ID = atoi(temp->ID);
            if (ID == check)
            {
                int_pawnshop_profit += atoi(temp->deposit_sum);
                prev = temp->prev; // узел, предшествующий lst
                next = temp->next; // узел, следующий за lst
                if (prev != NULL)
                    prev->next = temp->next; // переставляем указатель
                if (next != NULL)
                    next->prev = temp->prev; // переставляем указатель
                free(temp); // освобождаем память удаляемого элемента
                break;
            }
            temp = temp->next;
        }

        write_item_file();
    }
    else
    {
        printf("Введите ID вещи, которую надо удалить\n");
        scanf("%d", &check);

        while (temp != NULL)
        {
            int ID = atoi(temp->ID);
            if (ID == check)
            {
                int_pawnshop_profit += atoi(temp->cost);
                int_sum_of_items -= atoi(temp->cost);
                prev = temp->prev; // узел, предшествующий lst
                next = temp->next; // узел, следующий за lst
                if (prev != NULL)
                    prev->next = temp->next; // переставляем указатель
                if (next != NULL)
                    next->prev = temp->prev; // переставляем указатель
                free(temp); // освобождаем память удаляемого элемента
                break;
            }
            temp = temp->next;
        }

        write_item_file();
    }
}

void reduct_item_element(int variant, int int_pawnshop_profit, int int_sum_of_items)
{
    int check = 0;
    struct item* temp = items_first_element;
    int ID = atoi(temp->ID);

    printf("Введите ID клиента, которого надо редактировать\n");
    scanf("%d", &check);

    if (variant == 1)
    {
        while (temp != NULL)
        {
            if (ID == check)
            {
                printf("Введите изменённую оценочную стоимость:");
                scanf("%s", temp->cost);
                int_sum_of_items += atoi(temp->cost);
                break;
            }
        }
        temp = temp->next;
        write_item_file();
    }

    if (variant == 2)
    {
        while (temp != NULL)
        {
            if (ID == check)
            {
                printf("Введите дату окончания хранения вещи:");
                scanf("%s", temp->deposit_end_date);
                break;
            }
        }
        temp = temp->next;
        write_item_file();
    }

    if (variant == 3)
    {
        while (temp != NULL)
        {
            if (ID == check)
            {
                printf("Введите изменённую сумму залога:");
                scanf("%s", temp->deposit_sum);
                break;
            }
        }
        temp = temp->next;
        write_item_file();
    }
}



void pawnshop_profit()
{
    system("cls");

    struct item* temp = items_first_element;

    int int_pawnshop_profit = 0;

    while (temp != NULL)
    {
        int cost = atoi(temp->deposit_sum);
        int_pawnshop_profit += cost;
        temp = temp->next;
    }

    printf("Прибыль ломбарда равна %d рублей.\n", int_pawnshop_profit);
    system("pause");
}

void i_sum_of_items()
{
    struct item* temp = items_first_element;

    int sum_of_items = 0;

    while (temp != NULL)
    {
        int cost = atoi(temp->cost);
        sum_of_items += cost;
        temp = temp->next;
    }
}

void sum_of_items()
{
    system("cls");
 
    struct item* temp = items_first_element; 

    int sum_of_items = 0;

    while (temp != NULL)
    {
        int cost = atoi(temp->cost);
        sum_of_items += cost;
        temp = temp->next;
    }

    printf("Оценочная стоимость всех хранимых вещей равна %d рублей.\n", sum_of_items);
    system("pause");
}

void print_menu() 
{
    system("cls");  // очищаем экран
    printf("Здравствуйте.\nВы находитесь в меню Ломбард_Вещей.\nПожалуйста, выберите следующие пункты меню:\n\n");
    printf("1. Клиентская база.\n");
    printf("2. Список хранимых вещей.\n");
    printf("3. Просмотр бюджета ломбарда.\n");
    printf("4. Помощь.\n");
    printf("5. Выйти из программы.\n");
    printf(">");
}

void print_menu_1()
{
    system("cls");  // очищаем экран
    printf("Выбран пункт меню 1:\n");
    printf("1. Просмотр клиентов.\n");
    printf("2. Добавление нового клиента.\n");
    printf("3. Удаление клиента.\n");
    printf("4. Редактирование клиента.\n");
    printf("5. Помощь.\n");
    printf("6. Вернуться в меню.\n");
    printf(">");
}

void print_menu_2()
{
    system("cls");  // очищаем экран
    printf("Выбран пункт меню 2:\n");
    printf("1. Просмотр списка вещей.\n");
    printf("2. Добавление вещи.\n");
    printf("3. Удаление вещи.\n");
    printf("4. Редактирование вещи.\n");
    printf("5. Помощь.\n");
    printf("6. Вернуться в меню.\n");
    printf(">");
}

void print_menu_2_1()
{
    system("cls");  // очищаем экран
    printf("Выбран подпункт меню 2.1:\n");
    printf("1. Вещь возвращена.\n");
    printf("2. У вещи истёк срок хранения и не выплачен процент.\n");
    printf("3. Помощь.\n");
    printf("4. Вернуться.\n");
    printf(">");
}

void print_menu_2_2()
{
    system("cls");  // очищаем экран
    printf("Выбран подпункт меню 2.2:\n");
    printf("1. Редактирование цены.\n");
    printf("2. Редактирование срока хранения.\n");
    printf("3. Редактирование залога.\n");
    printf("4. Помощь.\n");
    printf("5. Вернуться.\n");
    printf(">");
}

void print_menu_3()
{
    system("cls");  // очищаем экран
    printf("Выбран пункт меню 4:\n");
    printf("1. Прибыль ломбарда.\n");
    printf("2. Ценовая сумма всех вещей ломбарда.\n");
    printf("3. Помощь.\n");
    printf("4. Вернуться в меню.\n");
    printf(">");
}

int get_variant(int count) 
{
    int variant;
    char s[100]; // строка для считывания введённых данных
    scanf("%s", s); // считываем строку

    // пока ввод некорректен, сообщаем об этом и просим повторить его
    while (sscanf(s, "%d", &variant) != 1 || variant < 1 || variant > count) 
    {
        printf("Неверно выбранный пункт меню. Повторите ввод: "); // выводим сообщение об ошибке
        scanf("%s", s); // считываем строку повторно
    }

    return variant;
}