// 4.1(8).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>

int main()
{
    char a;
    int* bufJ;
    bufJ = (int*)malloc(5 * sizeof(int));
    char** str = (char**)malloc(5 * sizeof(char*));
    for (int i = 0; i < 5; i++)
        str[i] = (char*)malloc(80 * sizeof(char));

m1:
    printf("Enter 5 lines (less then 80 characters) :\n");
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; (a = getchar()) != '\n'; j++)
        {
            if (j == 80)
            {
                printf("Your string is more than 80 characters.\nTry ahain.\n");
                goto m1;
            }
            str[i][j] = a;
            bufJ[i] = j;
        }
        str[i][bufJ[i] + 1] = '\0';
    }

    printf("\nRevers Lines:\n");
    for (int i = 4; i >= 0; i--)
    {
        for (int j = bufJ[i] - 1; j >= 0; j--)
            printf("%c", str[i][j]);
        
        printf("\n");
    }

    for (int i = 0; i < 5; i++)
        free(str[i]);
    free(str);
}

