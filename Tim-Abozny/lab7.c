#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#define SizeStr 80              // максимальный размер логина и пароля
#define TranzFile "history.txt"     // файл где все транзакции
#define AccFile "accounts.txt"      // файл где все аккаунты
#define StartMoney 2000         // начальный баланс в банкомате
struct account {
    char log[SizeStr];          // логин аккаунта
    char pass[SizeStr];         //  пароль аккаунта
    int ballance;               // баланс пользователя
    struct account* next;        // для списка пользователей
};
void readIzFile(struct account** First, struct account** Last)   // считываем из файла базу об аккаунтах
{
    struct account* List = NULL;
    FILE* f = fopen(AccFile, "r");
    if (f == NULL)return;
    do {
        List = (struct account*)calloc(1, sizeof(struct account));
        fscanf(f, "%s", List->log);
        if (feof(f)) break;
        fscanf(f, "%s", List->pass);
        fscanf(f, "%d", &(List->ballance));
        if (!(*First))
        {
            (*First) = List;
            *Last = List;
            List->next = NULL;
        }
        else
        {
            (*Last)->next = List;
            List->next = NULL;
            (*Last) = List;
        }
        List = List->next;
    } while (!feof(f));
}
int vvInt()               // ввод int
{
    int n1; int k = 0;
    do
    {
        n1 = scanf("%d", &k);                                                 // ввод размера матрицы
        if (!n1 && k < 0)
        {
            rewind(stdin);                                                 // очистка буфер
            printf("Ошибка ввода!!! Повторите ввод\n");
        }
    } while (!n1 && k < 0);
    return k;
}
void getstr(char* str, int k)
{
    if (!str) return;   // передан указатель на невыделенную под строку память
    int i = 0;
    fflush(stdin);
    // в цикле символы заносятся в строку из буфера клавиатуры
    // до тех пор пока не будет нажата клавиша ENTER
    while ((*(str + i) = (char)getchar()) != '\n')
    {
        if (k <= 0) break;
        i++;
        k--;
    }
    str[i] = '\0';    // добавляем в конец строки символ '\0'
    //  return str;            // выход из функции
}     // функция ввода строки
int findErr(struct account* head, char* log) {
    while (head) {
        if (strcmp(head->log, log) == 0)
            return 1;
        head = head->next;
    }
    return 0;
}
void dep(struct account* Acc, int depos)             // функция изменения баланса в банкомате и занесения в историю о депозите
{
    FILE* f = fopen(TranzFile, "r+");
    int befSum;
    fscanf(f, "%d", &befSum);
    rewind(f);
    befSum = befSum + depos;
    fprintf(f, "%d\n", befSum);              // меняем баланс в банкомате
    fclose(f);
    fopen(TranzFile, "a+");   // дописываем в историю
    fprintf(f, "%s %s %d\n", Acc->log, " депозит ", depos);
    fclose(f);
}
void depNew(struct account* Acc)
{
    FILE* f = fopen(TranzFile, "r+");
    int befSum = StartMoney;
    if (!f)                        // если такого файла не существует
    {
        f = fopen(TranzFile, "w+");   // создаем новый
        befSum = befSum + (Acc->ballance);
        fprintf(f, "%d\n", befSum);
        fprintf(f, "%s %s %d\n", Acc->log, " депозит ", Acc->ballance);
        fclose(f);
    }
    else
    {
        fclose(f);
        dep(Acc, Acc->ballance);
    }
}   // депозит если создается новый аккаунт
void creat(struct account** head, struct account** last)   // функция создания нового аккаунта
{
    struct account* NewAc = (struct account*)malloc(1 * sizeof(struct account));
    if (!NewAc)
    {
        printf("Произошла ошибка!\n");
        return;
    }
    int rez;       // переменная для результата
    do
    {
        rewind(stdin);
        printf("Введите логин: ");
        getstr(NewAc->log, SizeStr);
        rez = findErr((*head), NewAc->log);
        if (rez == 1)
            printf("Аккаунт с таким логином уже существует!\n");
    } while (rez != 0);
    printf("Введите пароль: ");
    getstr(NewAc->pass, SizeStr);
    printf("Введите депозит: ");
    NewAc->ballance = vvInt();
    depNew(NewAc);
    if (!(*head))
    {
        (*head) = NewAc;
        *last = NewAc;
        NewAc->next = NULL;
    }
    else
    {
        (*last)->next = NewAc;
        NewAc->next = NULL;
        (*last) = NewAc;
    }        // добавления аккаунта в очередь
    printf("Вы создали новый аккаунт!\n");
}
void printO(struct account* head)     // вывод очереди на экран
{
    if (!head)
    {
        printf("База пуста!\n");
        return;
    }
    while (head)
    {
        printf("%s %s %d\n", head->log, head->pass, head->ballance);
        head = head->next;
    }
}
void printFile(struct account* head)
{
    FILE* f = fopen(AccFile, "w+");
    while (head)
    {
        fprintf(f, "%s %s %d \n", head->log, head->pass, head->ballance);
        head = head->next;
    }
    fclose(f);
}
void getsAcc(struct account* List, struct account** Acc, char* log)    // функция для возврата указателя на аккаунт в который входим
{
    while (List)
    {
        if (strcmp(List->log, log) == 0)
        {
            *Acc = List;
            return;
        }
        List = List->next;
    }
}
void reDep(struct account** Acc)
{
    int sum;
    do {
        printf("Введите сумму снятия наличных: ");
        sum = vvInt();
        if (sum > (*Acc)->ballance)
        {
            printf("Ой! У вас нет столько! :(\n");
            break;
        }
        else
            (*Acc)->ballance = (*Acc)->ballance - sum;
        FILE* f = fopen(TranzFile, "r+");
        int befSum;
        fscanf(f, "%d", &befSum);
        rewind(f);
        befSum = befSum - sum;
        fprintf(f, "%d\n", befSum);              // меняем баланс в банкомате
        fclose(f);
        fopen(TranzFile, "a+");   // дописываем в историю
        fprintf(f, "%s %s %d\n", (*Acc)->log, " снятие ", sum);
        printf("Вы сняли с баланса: %d. Остаток: %d\n", sum, (*Acc)->ballance);
        fclose(f);
        break;
    } while (1);
}     // функция снятия наличных
void tranzit(struct account* head, struct account** Acc)
{
    rewind(stdin);
    struct account* Friend;
    char log[SizeStr];
    printf("Введите логин друга: ");
    getstr(log, SizeStr);
    int rez = findErr(head, log);
    if (rez == 0)
    {
        printf("Человека с таким логином нет!\n");
        return;
    }
    int sum;
    do {
        printf("Введите сумму перевода: ");
        sum = vvInt();
        if (sum > (*Acc)->ballance)
            printf("Ой! У вас нет столько! :(\n");
        else
            break;
    } while (1);
    getsAcc(head, &Friend, log);
    (*Acc)->ballance = (*Acc)->ballance - sum;
    Friend->ballance = Friend->ballance + sum;
    FILE* f = fopen(TranzFile, "a+");
    fprintf(f, "%s %s%s %d\n", (*Acc)->log, " перевод:", Friend->log, sum);
    fprintf(f, "%s %s%s %d\n", Friend->log, " депоз:", (*Acc)->log, sum);
    printf("Вы перевели %s сумму: %d. Ваш баланс: %d\n", Friend->log, sum, (*Acc)->ballance);
    fclose(f);
}
void history(char* str)
{
    FILE* f = fopen(TranzFile, "r+");
    if (!f) return;
    char buffer[2 * SizeStr];
    char logFile[SizeStr];
    int i = 0;
    while (!feof(f))
    {
        i = 0;
        fscanf(f, "%s", buffer);
        while (buffer[i] != ' ' && buffer[i] != '\n' && buffer[i] != '\0')
        {
            logFile[i] = buffer[i];
            i++;
        }
        logFile[i] = '\0';
        if (strcmp(logFile, str) == 0)
        {
            printf("%s ", buffer);
            fscanf(f, "%s", buffer);
            printf("%s ", buffer);
            fscanf(f, "%s", buffer);
            printf("%s\n", buffer);
        }

    }
    fclose(f);
}
void open(struct account* head)
{
    rewind(stdin);
    struct account* Acc;
    int vibor;
    char log[SizeStr];
    char pass[SizeStr];
    int rez;
    printf("Введите логин: ");
    getstr(log, SizeStr);
    rez = findErr(head, log);
    if (rez == 0)
    {
        printf("Аккаунта с таким именем не существует!\n");
        return;
    }
    printf("Введите пароль: ");
    getstr(pass, SizeStr);
    getsAcc(head, &Acc, log);
    int sum = 0;
    if (strcmp(pass, Acc->pass) == 0)
    {
        printf("Пароль верный!\n");
        do {
            printf("Выберите: \n 1 - Пополнить баланс \n 2 - Снять наличные \n 3 - Перевод другу \n 4 - Просмотреть историю \n 5 - Просмотр баланса \n 6 - Выход \n");
            vibor = vvInt();
            switch (vibor) {
            case 1:
                printf("Введите сумму: ");
                sum = vvInt();
                Acc->ballance = Acc->ballance + sum;
                printf("Вы пополнили баланс на: %d. Ваш баланс: %d\n", sum, Acc->ballance);
                dep(Acc, sum);
                break;
            case 2:
                reDep(&Acc);
                break;
            case 3:
                tranzit(head, &Acc);
                break;
            case 4:
                history(Acc->log);
                break;
            case 5:
                printf("Ваш баланс: %d\n", Acc->ballance);
                break;
            default:
                vibor = 33;
            }
        } while (vibor != 33);
    }
    else
        printf("Ой! Вы ввели не верный пароль\n");
}
int main() {
    setlocale(0, "rus");
    struct account* head = NULL;        // для создания очереди между аккаунтами
    struct account* last = NULL;        // для создания очереди между аккаунтами
    printf("Здравствуйте!\n");
    readIzFile(&head, &last);
    printO(head);
    int vibor;     // переменная для выбора
    do {
        printf(" 1 - Войти в аккаунт\n 2 - Создать новый аккаунт\n 3 - Вывод базы пользователей \n Выход: Любая клавиша \n");
        vibor = vvInt();
        switch (vibor) {
        case 1:
            open(head);             // функция входа в существующий аккаунт
            break;
        case 2:
            creat(&head, &last);     // функция создания нового аккаунта
            break;
        case 3:
            printO(head);      // вывод всех аккаунтов
            break;
        default: vibor = 33;
        }
        printFile(head); // после ПОЛНОЙ работы с базой пользователей записываем информацию в файл
    } while (vibor != 33);
    return 0;
}
