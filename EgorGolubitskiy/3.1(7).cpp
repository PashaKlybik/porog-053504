#define _CRT_SECURE_NO_WARNINGS
#define EMPTY -100
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <stdlib.h>

using namespace std;

int main()
{

    system("chcp 1251");
    system("cls");

    int* arr;
    int x = 0, y = 0, str, col, v, t = 0;

    bool leave = false;

    printf_s("Введите количество строк: ");
    scanf_s("%d", &str);
    printf_s("Введите количество столбцов: ");
    scanf_s("%d", &col);

    arr = (int*)malloc(str * col * sizeof(int));

    for (x = 0; x < str; x++)
    {
        for (y = 0; y < col; y++)
        {
            *(arr + x * str + y) = EMPTY;
        }
    }


    while (!leave)
    {
        printf_s("\nВведите индекс элемента x, y и его значение: ");
        scanf_s("%d %d %d", &x, &y, &v);

        while (x >= str || y >= col)
        {
            printf_s("\nВы ввели некорректные индексы, пожалуйста, повторите ввод: ");
            scanf_s("%d %d %d", &x, &y, &v);
        }

        if (x == 0 && y == 0 && v == 0)
        {
            leave = true;
        }
        else
        {
            if (*(arr + x * str + y) != EMPTY)
            {
                printf_s("\nУ элемента с данным индексом уже есть значение.\nЧтобы заменить значение, нажмите 1. Чтобы продолжить, нажите 0.\n");
                int enter;
                scanf_s("%d", &enter);
                if (enter == 1)
                {
                    *(arr + x * str + y) = v;
                }
            }
            else
            {
                *(arr + x * str + y) = v;
            }
        }
    }

    for (x = 0; x < str; x++)
    {
        for (y = 0; y < col; y++)
        {

            if (*(arr + x * str + y) == EMPTY)
            {
                printf_s("\nДанный элемент массива не имеет значения - a[%d] [%d] .\nНажмите 0, чтобы продолжить, или 1, чтобы ввести значение: \n", x, y);
                int enter;
                scanf_s("%d", &enter);

                if (enter == 1)
                {
                    printf_s("\nВведите значение пропущенного элемента: ");
                    scanf_s("%d", &v);
                    *(arr + x * str + y) = v;
                }
            }
        }
    }

    for (x = 0; x < str; x++)
    {
        for (y = 0; y < col; y++)
        {
            if (*(arr + x * str + y) == EMPTY)
            {
                printf_s("    * ");
            }
            else
            {
                printf("%5d ", *(arr + x * str + y));
            }
        }
        printf("\n");
    }

    return 0;
}