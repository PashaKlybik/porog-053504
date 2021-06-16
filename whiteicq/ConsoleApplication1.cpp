#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#pragma warning(disable:4996)

typedef struct
{
    int number;
    int bin;
} structure;

structure BinGet(int firstNumber, int lastNumber)
{
    structure t;
    int bin = 0, count = 0, temp_num = firstNumber, j = 0, i, temp_count, x;
    for (i = firstNumber; i <= lastNumber; i++)
    {
        x = i;
        temp_count = 0;
        while (x >= 1)
        {
            if (x % 2 == 1) {
                temp_count++;
            }
            x /= 2;
            j++;
        }
        if (count < temp_count)
        {
            temp_num = i;
            count = temp_count;
        }
        else if (count == temp_count) {
            if (i >= temp_num) {
                temp_num = i;
            }
        }
        j = 0;
    }
    int k = 1;
    t.number = temp_num;
    while (temp_num >= 1)
    {
        bin += (temp_num % 2) * k;
        temp_num /= 2;
        k *= 10;
    }
    t.bin = bin;
    return t;
}

int main()
{
    printf("Enter your first number: ");
    int firstNumber, lastNumber;
    scanf("%d %d", &firstNumber, &lastNumber);
    structure x = BinGet(firstNumber, lastNumber);
    printf("%d/%d\n", x.number, x.bin);
    return 0;
}