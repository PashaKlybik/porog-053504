// Programming 7 laba.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "StorageOfInformation.h"

int _stateMenu;
void Menu() {
    printf("Choose correct variant : \n");
    printf("1 - Enter correct data \n");
    printf("2 - Output data \n");
    printf("3 - Ordering \n");
    printf("4 - Total count of books in storage \n");
    printf("5 - Total price of books in storage \n");
    printf("6 - Total count of orders in storage \n");
    printf("7 - Total count of sold books in storage \n");
    printf("8 - Total profit in storage \n");
    printf("9 - Save file \n");
    printf("10 - Exit the program \n");
    printf("Your choice : ");
    scanf_s("%d", &_stateMenu);
}

int main()
{
    Menu();

    int actions = 0, CountOfTheCopies_ = 0;
    char filename[N], Author_[N], Name_[N], Requisities_[N],buf[N];
    double PriceOfAcceptance_, PriceOfSale_;

    List* res = (List*)malloc(sizeof(List));
    res->count = 0;
    res->head = NULL;
    res->tail = NULL;

    Reporting* rep = (Reporting*)malloc(sizeof(Reporting));
    rep->counter = 0;
    rep->head = NULL;
    rep->tail = NULL;

    while (_stateMenu != 0) {
        switch (_stateMenu) {
        case 10:
            if (rep && res) {
                DeleteList(res);
                DeleteReport(rep);
                printf("All data is free ... \n");
            }
            system("pause");
            system("cls");
            //Menu();
            break;
        case 1:
            system("cls");

            printf("Choose variant : 1 - Manual entry or 2 - Reading from file :");
            scanf_s("%d", &actions);

            system("cls");

            if (actions == 1) {
                gets_s(buf);
                printf("Enter author of the book : ");
                fgets(Author_, N, stdin);
                printf("Enter name of the book : ");
                fgets(Name_, N, stdin);
                printf("Enter requisities of the book : ");
                fgets(Requisities_, N, stdin);
                printf("Enter count of the book copies : ");
                scanf_s("%d", &CountOfTheCopies_);
                printf("Enter price of the book acceptance : ");
                scanf_s("%lf", &PriceOfAcceptance_);
                printf("Enter total sale price of theese books : ");
                scanf_s("%lf", &PriceOfSale_);

                AddParts(res, Author_, Name_, Requisities_, CountOfTheCopies_, PriceOfAcceptance_, PriceOfSale_);
            }
            else if (actions == 2) {
                ReadingParts(res);
                //PrintList(res);
            }
            system("pause");
            system("cls");
            Menu();
            break;

        case 2:
            if (res) {
                PrintList(res);
            }
            else {
                printf("No any data... \n");
            }
            system("pause");
            system("cls");
            Menu();
            break;
        case 3:
            if (res) {
                char name[N];
                int countparts = 0;
                gets_s(buf);
                printf("Enter book name :");
                fgets(name, N, stdin);
                printf("Enter book count :");
                scanf_s("%d", &countparts);
                SellPartsForOrders(res, rep, name, countparts);
            }
            system("pause");
            system("cls");
            Menu();
            break;
        case 4:
            if (res) {
                int buff1 = CountPartsOnStorage(res);
                printf("Total count of books in storage is : %d", buff1);
                getchar();
                printf("\n");
            }
            system("pause");
            system("cls");
            Menu();
            break;
        case 5:
            if (res) {
                double buff2 = AllPriceOfParts(res);
                printf("Total price of books in storage is : %lf", buff2);
                getchar();
                printf("\n");
            }
            system("pause");
            system("cls");
            Menu();
            break;
        case 6:
            if (rep) {
                int buff3 = CountOfOrders(rep);
                printf("Total count of orders in storage is : %d", buff3);
                getchar();
                printf("\n");
            }
            system("pause");
            system("cls");
            Menu();
            break;
        case 7:
            if (rep) {
                int buff4 = CountOfSoldParts(rep);
                printf("Total count of sold books in storage is : %d", buff4);
                getchar();
                printf("\n");
            }
            system("pause");
            system("cls");
            Menu();
            break;
        case 8:
            if (res && rep) {
                double delta = TotalProfit(res, rep);
                printf("Total profit in storage is : %lf", delta);
                getchar();
                printf("\n");
            }
            system("pause");
            system("cls");
            Menu();
            break;
        case 9:
            if (res) {
                SavingList(res);
            }
            system("pause");
            system("cls");
            Menu();
            break;
        }
    }
}
