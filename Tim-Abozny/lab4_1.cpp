#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check(char str[])
{
    int i, length;

    length = strlen(str);

    for (i = 0; i < length; i++)
        if (str[i] != str[(length - 1) - i]) return 0;
    return 1;
}

int main(void)
{
    char* t;
    int Count;
    char str_array[30][200];
    char endArray[30][200];
    int temp = 0;

    printf("How words?\n");
    scanf_s("%d", &Count); Count++;
    for (int i = 0; i < Count; i++)
    {
        gets_s(str_array[i]);
        t = strtok(str_array[i], " ,");
        printf("\n");
        while (t != NULL)
        {
            if (check(t) != 1)
            {
                strcpy(endArray[temp], t);
                temp++;
            }
            t = strtok(NULL, " ,");
        }
    }
        printf("Your clear string: ");
        for (int i = 0; i < temp; i++)
        {
            printf(" %s ", endArray[i]);
        }

    return 0;
}