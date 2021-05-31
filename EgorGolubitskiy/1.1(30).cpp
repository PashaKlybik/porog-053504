#include <iostream>
#include <stdio.h>
#include <conio.h> 


void main()
{
    bool checker = true;
    int x = 0;
    while (checker)
    {
        printf_s("Enter number\n");
        scanf_s("%d", &x);
        if (x > 0 && x < 181)
        {
            checker = false;
        }
        else
        {
            printf("Number dont pass the diapasone test!\n");
            checker = true;
        }
    }
    int mass[180];
    int number = 10;
    for (int i = 0; i < 180; i++)
    {
        int unitnum = number % 10;
        int decnum = number / 10;
        if (i % 2 == 0)
        {
            mass[i] = decnum;
        }
        else
        {
            mass[i] = unitnum;
            number++;
        }
    }

    printf_s("k = %d ", mass[x - 1]);
}