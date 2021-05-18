#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE* fl = fopen("C:\\Users\\progr\\Desktop\\fileTest.txt", "a+t");
    char data[350] = "";
    char temp[5] = "";
    int sum = 0;
    int wordsCounter = 0;
    int allData = 0;

    fgets(data, 250, fl);

    int k = 0, j = 0;
    for (int i = 0; i < strlen(data); i++)
    {
        if (data[i] == ' ' &&
            (data[i - 1] != '1' || data[i - 1] != '2' || data[i - 1] != '3' ||
             data[i - 1] != '4' || data[i - 1] != '5' || data[i - 1] != '6' ||
             data[i - 1] != '7' || data[i - 1] != '8' || data[i - 1] != '9'))
        {
            wordsCounter++;
        }
    }

    for (int i = 0; i < strlen(data); i++)
    {
        if ((data[i] == '1' || data[i] == '2' || data[i] == '3' ||
            data[i] == '4' || data[i] == '5' || data[i] == '6' ||
            data[i] == '7' || data[i] == '8' || data[i] == '9'))
        {
            k++;
            sum += data[i] - '0';
        }
    } allData = wordsCounter - k;
    if (allData == sum)
    {
        fprintf(fl, "\n%s\n", "True! Sum of numbers = words count o__o ");
    }
    else
    {
        fprintf(fl, "\n%s\n", "False! Sum of numbers != words count *__* ");
    }

    fclose(fl);
    return 0;
}