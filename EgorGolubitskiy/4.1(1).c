// 4.1(1).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <malloc.h>

int main()
{
    int n, count = 0, count_words = 0;
    char** str, ch;

    printf("Enter n: ");
    scanf_s("%d", &n);
    n++;
    str = (char**)malloc(sizeof(char*) * n);
    for (int i = 0; i < n; i++)
    {
        str[i] = (char**)malloc(sizeof(char*) * 80);
    }

    for (int i = 0; i < n; i++)
    {
        while ((ch = getchar()) != '\n')
        {
            if (ch == ' ')
                count_words++;

            str[i][count] = ch;
            count++;
        }
        if (str[i][count - 1] == ' ')
            str[i][count - 1] = '\0';
        else
        {
            count_words++;
            str[i][count] = '\0';
        }
        count = 0;
    }
    count_words--;

    char** arr_of_words;

    arr_of_words = (char**)malloc(sizeof(char*) * count_words);
    for (int i = 0; i < count_words; i++)
        arr_of_words[i] = (char*)malloc(sizeof(char) * 80);

    int* count_of_simbols = (int*)malloc(sizeof(int*) * count_words);
    for (int i = 0; i < count_words; i++)
        count_of_simbols[i] = 0;

    count = 0;
    int count2 = 1, count3 = 0;
    for (int i = 0; i < count_words; i++)
    {
        while (str[count2][count] != '\0')
        {
            if (str[count2][count] == ' ')
            {
                arr_of_words[i][count3] = '\0';
                i++;
                count++;
                count3 = 0;
            }
            else
            {
                arr_of_words[i][count3] = str[count2][count];
                count_of_simbols[i]++;
                count++;
                count3++;
            }
        }
        arr_of_words[i][count3] = '\0';
        count2++;
        count = 0;
        count3 = 0;
    }

    for (int i = 0; i < count_words - 1; i++)
    {
        for (int j = (count_words - 1); j > i; j--)
        {
            if (count_of_simbols[j - 1] > count_of_simbols[j])
            {
                int temp = count_of_simbols[j - 1];
                count_of_simbols[j - 1] = count_of_simbols[j];
                count_of_simbols[j] = temp;

                char* buf = arr_of_words[j - 1];
                arr_of_words[j - 1] = arr_of_words[j];
                arr_of_words[j] = buf;
            }
        }
    }

    for (int i = 0; i < count_words; i++)
    {
        puts(arr_of_words[i]);
    }



    for (int i = 0; i < n; i++)
        free(str[i]);
    for (int i = 0; i < count_words; i++)
        free(arr_of_words[i]);

    free(str);
    free(count_of_simbols);
    free(arr_of_words);
}

