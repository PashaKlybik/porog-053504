#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <malloc.h>

int myStrlen(char* str) {
    int i = 0;
    int counter = 0;
    while (str[i] != '\0') {
        if ((str[i] - 48) < 10 && (str[i] - 48) >= 0) {
            counter++;
            i++;
        }
        else {
            break;
        }
    }
    return counter;
}

int myallmonth(int dayint, int yearint, int monthint, int allmonth) {
    allmonth = 0;
    switch (monthint)
    {
    case 12:
        allmonth += 31;
    case 11:
        allmonth += 30;
    case 10:
        allmonth += 31;
    case 9:
        allmonth += 30;
    case 8:
        allmonth += 31;
    case 7:
        allmonth += 31;
    case 6:
        allmonth += 30;
    case 5:
        allmonth += 31;
    case 4:
        allmonth += 30;
    case 3:
        allmonth += 31;
    case 2:
        if ((yearint % 4 == 0 && dayint < 30)) {
            allmonth += 29;
        }
        else {
            allmonth += 28;
        }
    case 1:
        allmonth += 31;
        break;
    }
    return allmonth;
}

int main()
{
    setlocale(LC_ALL, "rus");
    system("color 0D");
    char input = '0';
    int s = 0;
    char fulldata[9];
    char month[3], day[3], year[5];
    int monthint = 0, dayint = 0, yearint = 0;
    int alldays, allmonth = 0, check = 0;
    do {
        for (int i = 0; i < 9; i++) {
            fulldata[i] = 0;
        }
        s = 0;
        while (s < 70) {
            printf("*");
            s++;
        }
        printf("\nWhat would you like to do??\n1 - Enter date \n2 - Display the day of the week of the entered date (the day from the beginning of the year)  \n3 - Display the number of days from the birth of Christ  \n4 - Information about program's version and author \n5 - Exit");
        printf("\nInput ");
        scanf_s("%c", &input);
        while ((getchar()) != '\n');
        if ((input - 48 >= 1) && (input - 48 <= 5)) {
            if (input == '1') {
                 printf("\nInput date (in format ее.ее.ееее(dd.mm.yyyy)) ");
                 fgets(fulldata, 9, stdin);
                 while ((getchar()) != '\n');
                 day[0] = fulldata[0];
                 day[1] = fulldata[1];
                 day[2] = 0;
                 month[0] = fulldata[2];
                 month[1] = fulldata[3];
                 month[2] = 0;
                 year[0] = fulldata[4];
                 year[1] = fulldata[5];
                 year[2] = fulldata[6];
                 year[3] = fulldata[7];
                 year[4] = 0;
                 dayint = atoi(day);
                 yearint = atoi(year);
                 monthint = atoi(month);
                 if (monthint < 13 && dayint < 32 && monthint != 0 && dayint !=0 && yearint != 0 && myStrlen(fulldata) == 8 ) {
                     switch (monthint)
                     {
                     case 1: 
                         printf("\n%c%c January ", fulldata[0], fulldata[1]);
                         printf("%c%c%c%c\n", fulldata[4], fulldata[5], fulldata[6], fulldata[7]);
                         printf("%c%c.%c%c.%c%c\n", fulldata[0], fulldata[1], fulldata[2], fulldata[3], fulldata[6], fulldata[7]); break;
                     case 2:
                         if ((yearint % 4 == 0 && dayint < 30) || ((yearint % 4 == 1 || yearint % 4 == 2 || yearint % 4 == 3) && dayint < 29)) {
                             printf("\n%c%c February ", fulldata[0], fulldata[1]);
                             printf("%c%c%c%c\n", fulldata[4], fulldata[5], fulldata[6], fulldata[7]);
                             printf("%c%c.%c%c.%c%c\n", fulldata[0], fulldata[1], fulldata[2], fulldata[3], fulldata[6], fulldata[7]);
                         }
                         else printf("\nEnter correct date!\n");  break;
                     case 3:
                         printf("\n%c%c March ", fulldata[0], fulldata[1]);
                         printf("%c%c%c%c\n", fulldata[4], fulldata[5], fulldata[6], fulldata[7]);
                         printf("%c%c.%c%c.%c%c\n", fulldata[0], fulldata[1], fulldata[2], fulldata[3], fulldata[6], fulldata[7]); break;
                     case 4:
                         if (dayint < 31) {
                             printf("\n%c%c April ", fulldata[0], fulldata[1]);
                             printf("%c%c%c%c\n", fulldata[4], fulldata[5], fulldata[6], fulldata[7]);
                             printf("%c%c.%c%c.%c%c\n", fulldata[0], fulldata[1], fulldata[2], fulldata[3], fulldata[6], fulldata[7]);
                         }else printf("\nEnter correct date!\n");  break;
                     case 5:
                         printf("\n%c%c May ", fulldata[0], fulldata[1]);
                         printf("%c%c%c%c\n", fulldata[4], fulldata[5], fulldata[6], fulldata[7]);
                         printf("%c%c.%c%c.%c%c\n", fulldata[0], fulldata[1], fulldata[2], fulldata[3], fulldata[6], fulldata[7]); break;
                     case 6:
                         if (dayint < 31) {
                             printf("\n%c%c June ", fulldata[0], fulldata[1]);
                             printf("%c%c%c%c\n", fulldata[4], fulldata[5], fulldata[6], fulldata[7]);
                             printf("%c%c.%c%c.%c%c\n", fulldata[0], fulldata[1], fulldata[2], fulldata[3], fulldata[6], fulldata[7]);
                         } else printf("\nEnter correct date!\n");  break;
                     case 7:
                         printf("\n%c%c July ", fulldata[0], fulldata[1]);
                         printf("%c%c%c%c\n", fulldata[4], fulldata[5], fulldata[6], fulldata[7]);
                         printf("%c%c.%c%c.%c%c\n", fulldata[0], fulldata[1], fulldata[2], fulldata[3], fulldata[6], fulldata[7]); break;
                     case 8:
                         printf("\n%c%c August ", fulldata[0], fulldata[1]);
                         printf("%c%c%c%c\n", fulldata[4], fulldata[5], fulldata[6], fulldata[7]);
                         printf("%c%c.%c%c.%c%c\n", fulldata[0], fulldata[1], fulldata[2], fulldata[3], fulldata[6], fulldata[7]); break;
                     case 9:
                         if (dayint < 31) {
                             printf("\n%c%c September ", fulldata[0], fulldata[1]);
                             printf("%c%c%c%c\n", fulldata[4], fulldata[5], fulldata[6], fulldata[7]);
                             printf("%c%c.%c%c.%c%c\n", fulldata[0], fulldata[1], fulldata[2], fulldata[3], fulldata[6], fulldata[7]);
                         } else printf("\nEnter correct date!\n");  break;
                     case 10:
                         printf("\n%c%c October ", fulldata[0], fulldata[1]);
                         printf("%c%c%c%c\n", fulldata[4], fulldata[5], fulldata[6], fulldata[7]);
                         printf("%c%c.%c%c.%c%c\n", fulldata[0], fulldata[1], fulldata[2], fulldata[3], fulldata[6], fulldata[7]); break;
                     case 11:
                         if (dayint < 31) {
                             printf("\n%c%c November ", fulldata[0], fulldata[1]);
                             printf("%c%c%c%c\n", fulldata[4], fulldata[5], fulldata[6], fulldata[7]);
                             printf("%c%c.%c%c.%c%c\n", fulldata[0], fulldata[1], fulldata[2], fulldata[3], fulldata[6], fulldata[7]);
                         } else printf("\nEnter correct date!\n");  break;
                     case 12:
                         printf("\n%c%c December ", fulldata[0], fulldata[1]);
                         printf("%c%c%c%c\n", fulldata[4], fulldata[5], fulldata[6], fulldata[7]);
                         printf("%c%c.%c%c.%c%c\n", fulldata[0], fulldata[1], fulldata[2], fulldata[3], fulldata[6], fulldata[7]); break;
                     default:
                         break;
                     }
                     check++;
                 }
                 else {
                 printf("\nEnter correct date!\n");
                 }    
            }
            if (input == '2') {
                if (check != 0) {
                    alldays = (yearint / 4) + yearint * 365 + dayint + myallmonth(dayint, yearint, monthint, allmonth);
                    switch (alldays % 7) {
                    case 5: printf("It's Monday"); break;
                    case 6: printf("It's Tuesday"); break;
                    case 0: printf("It's Wednesday"); break;
                    case 1: printf("It's Thursday"); break;
                    case 2: printf("it's Friday"); break;
                    case 3: printf("It's Saturday"); break;
                    case 4: printf("It's Sunday"); break;
                    }
                    printf("\nDay from begining of the year: %d\n", myallmonth(dayint, yearint, monthint, allmonth) + dayint);
                }
                else {
                    printf("\nEnter date!\n");
                }
            }
            if (input == '4') {
                printf("\n   DATA PROGRAM \nAuthor: Sokolovsky Arkady\nE-mail: fakemail@gmail.com\nProgram version: 4.20Beta\n");
            }
            if (input == '5') {
                return 0;
            }
            if (input == '3') {
                if (check != 0) {
                    alldays = (yearint / 4) + yearint * 365 + dayint + myallmonth(dayint, yearint, monthint, allmonth);
                    printf("\nTotal number of days : %d\n", alldays);
                } 
                else {
                    printf("\Enter date!\n");
                }
            }
            
        }
        else {
            printf("\nEnter correct date!\n");
        }
    } while (true);

    return 0;
}

