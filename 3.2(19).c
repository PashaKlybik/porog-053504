// 3.2(19).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include<stdbool.h>


int main()
{
    int n, m, chosen_i, chosen_j;
    bool check = false;
    printf("Enter n: ");
    scanf_s("%d", &n);
    printf("Enter m: ");
    scanf_s("%d", &m);

    char** cake = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++)
        cake[i] = (char*)malloc(m * sizeof(char*));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
             cake[i][j] = '*';

    while (check == false)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                printf("%c", cake[i][j]);
            }
            printf("\n");
        }

    exit1:
        printf("Enter i: ");
        scanf_s("%d", &chosen_i);
        printf("Enter j: ");
        scanf_s("%d", &chosen_j);
        if (chosen_i >= n || chosen_j >= m)
        {
            printf("Values should be:\ni < n\nj < m\n");
            goto exit1;
        }

        for (int i = 0; i <= chosen_i; i++)
            for (int j = chosen_j; j < m; j++)
                if (j == m - 1 && i == n - 1)
                {
                    check = true;
                    printf("You died.\n");
                    break;
                }
                else
                    cake[i][j] = " ";
                
    }

    for (int i = 0; i < n; i++) 
        free(cake[i]);
    free(cake);
}

