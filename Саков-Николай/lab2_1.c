#include <stdio.h>
#include <locale.h>
#include <string.h>
int day, month, year;

void InputDate()
{
    printf("Введите день, месяц, год: ");
    scanf_s("%d %d %d", &day, &month, &year);
}

void OutputDateFirst()
{
    char monthName[16];
    switch (month)
    {
    case 1:
        strcpy_s(monthName, sizeof(monthName), "января");
        break;
    case 2:
        strcpy_s(monthName, sizeof(monthName), "февраля");
        break;
    case 3:
        strcpy_s(monthName, sizeof(monthName), "марта");
        break;
    case 4:
        strcpy_s(monthName, sizeof(monthName), "апреля");
        break;
    case 5:
        strcpy_s(monthName, sizeof(monthName), "мая");
        break;
    case 6:
        strcpy_s(monthName, sizeof(monthName), "июня");
        break;
    case 7:
        strcpy_s(monthName, sizeof(monthName), "июля");
        break;
    case 8:
        strcpy_s(monthName, sizeof(monthName), "августа");
        break;
    case 9:
        strcpy_s(monthName, sizeof(monthName), "сентября");
        break;
    case 10:
        strcpy_s(monthName, sizeof(monthName), "октября");
        break;
    case 11:
        strcpy_s(monthName, sizeof(monthName), "ноября");
        break;
    case 12:
        strcpy_s(monthName, sizeof(monthName), "декабря");
        break;
    default:
        strcpy_s(monthName, sizeof(monthName), "Error");
        break;
    }
    printf("%d %s %d г.\n", day, monthName, year);
}

void OutputDateSecond()
{
    if (month < 10)
    {
        if (year % 1000 < 10)
            printf("%d.0%d.0%d", day, month, year % 1000);
        else
            printf("%d.0%d.%d", day, month, year % 1000);
    }
    else
    {
        if (year % 1000 < 10)
            printf("%d.%d.0%d", day, month, year % 1000);
        else
            printf("%d.%d.%d", day, month, year % 1000);
    }
}

void DayOfWeek()
{
    int monthCode, YearCode, dayWeek;
    char dayOfWeek[16];
    switch (month)
    {
        case 1:
        case 10:
            monthCode = 1;
            break;
        case 5:
            monthCode = 2;
            break;
        case 8:
            monthCode = 3;
            break;
        case 2:
        case 3:
        case 11:
            monthCode = 4;
            break;
        case 6:
            monthCode = 5;
            break;
        case 9:
        case 12:
            monthCode = 6;
            break;
        case 4:
        case 7:
            monthCode = 0;
            break;
    }
    YearCode = (6 + year % 100 + (year % 100) / 4) % 7;
    dayWeek = (day + monthCode + YearCode) % 7;
    if (year % 4 == 0)
    {
        if (day <= 29 && month <= 2)
        {
            dayWeek--;
        }
    }
    switch (dayWeek)
    {
        case 0:
            strcpy_s(dayOfWeek, sizeof(dayOfWeek), "Суббота");
            break;
        case 1:
            strcpy_s(dayOfWeek, sizeof(dayOfWeek), "Воскресенье");
            break;
        case 2:
            strcpy_s(dayOfWeek, sizeof(dayOfWeek), "Понедельник");
            break;
        case 3:
            strcpy_s(dayOfWeek, sizeof(dayOfWeek), "Вторник");
            break;
        case 4:
            strcpy_s(dayOfWeek, sizeof(dayOfWeek), "Среда");
            break;
        case 5:
            strcpy_s(dayOfWeek, sizeof(dayOfWeek), "Четверг");
            break;
        case 6:
            strcpy_s(dayOfWeek, sizeof(dayOfWeek), "Пятница");
            break;
        case -1:
            strcpy_s(dayOfWeek, sizeof(dayOfWeek), "Пятница");
            break;
    }
    unsigned short dayInYear = 0;
    for (int i = 1; i < month; i++)
    {
        switch (i)
        {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
                dayInYear += 31;
                break;
            case 2:
                if (year % 4 != 0)
                {
                    dayInYear += 28;
                }
                else
                {
                    dayInYear += 29;
                }
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                dayInYear += 30;
                break;
        }
    }
    dayInYear += day;
    printf("\nДень недели - %s \nПорядковый день в году - %d", dayOfWeek, dayInYear);
}
void DaysBirthOfChrist()
{
    int amount;
    amount = (year * 365) + (year / 4);
    unsigned short dayInYear = 0;
    for (int i = 1; i < month; i++)
    {
        switch (i)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
            dayInYear += 31;
            break;
        case 2:
            if (year % 4 != 0)
            {
                dayInYear += 28;
            }
            else
            {
                dayInYear += 29;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            dayInYear += 30;
            break;
        }
    }
    dayInYear += day;
    amount += dayInYear;
    printf("\nДней от Рождества Христова - %d", amount);
}

void ProgramInfo()
{
    printf("\nРазработано Пупкиным Валерой\nВерсия: 1.0");
}


int main()
{
    
    setlocale(LC_ALL, "rus");
    int ch = 0;
    InputDate();
    while (ch != 7)
    {
        printf("\nВыберите действие: \n1. Ввести дату\n2. Вывод даты в форме: 1 января 2010 г\n3. Вывод даты в форме: 01.01.10\n4. Вычисление по дате дня недели и порядкового номера дня в году\n5. Вывод количества дней, прошедших от Рождества Христова до введенной даты\n6. Информация о версии и авторе программы\n7. Выход из программы\n");
        scanf_s("%d", &ch);
        switch (ch)
        {
        case 1:
            InputDate();
            break;
        case 2:
            OutputDateFirst();
            break;
        case 3:
            OutputDateSecond();
            break;
        case 4:
            DayOfWeek();
            break;
        case 5:
            DaysBirthOfChrist();
            break;
        case 6:
            ProgramInfo();
            break;
        case 7:
            break;
        }
    }
}