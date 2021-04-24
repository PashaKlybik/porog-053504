#define _CRT_SECURE_NO_WARNINGS
#define NO_VALUE -100
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <stdlib.h>

using namespace std;

int main()
{
    int* a; 
    int i = 0, j = 0, n, m, v, t = 0;

    system("chcp 1251");
    system("cls");

    printf_s("Введите количество строк: ");
    scanf_s("%d", &n);
    printf_s("Введите количество столбцов: ");
    scanf_s("%d", &m);
   
    a = (int*)malloc(n * m * sizeof(int));
  
    bool exit = false;

    for (i = 0; i < n; i++)  // цикл по строкам
    {
        for (j = 0; j < m; j++)  // цикл по столбцам
        {
            *(a + i * n + j) = NO_VALUE;
        }
    }


    while (!exit)
    {
        printf_s("\nВведите индекс элемента i, j и значение по этому адресу: ");
        scanf_s("%d %d %d", &i, &j, &v);

        while(i >= n || j >= m)
        {
            printf_s("\nВведённые вами индексы не существуют, пожалуйста, повторите ввод: ");
            scanf_s("%d %d %d", &i, &j, &v);
        }

        if (i == 0 && j == 0 && v == 0)
        {                
            exit = true;
        }
        else 
        {
            if (*(a + i * n + j) != NO_VALUE)
            {
                printf_s("\nВы пытаетесь заменить элемент с заданным ему значением.\nВведите 1 чтобы заменить или 0 чтобы продолжить.\n");
                int s;
                scanf_s("%d", &s);
                if (s == 1) 
                {
                    *(a + i * n + j) = v;
                }
                else 
                {

                }
            }
            else 
            {
                *(a + i * n + j) = v;
            }
        }
    }

    for (i = 0; i < n; i++)  // цикл по строкам
    {
        for (j = 0; j < m; j++)  // цикл по столбцам
        {

            if (*(a + i * n + j) == NO_VALUE)
            {
                printf_s("\nНе все элементы массива имеют значение, а именно: a[%d] [%d] .\nВведите 1 чтобы присвоить значение или 0 чтобы продолжить.\n", i, j);
                int s;
                scanf_s("%d", &s);

                if (s == 1)
                {
                    printf_s("\nВведите значение пропущенного элемента: ");
                    scanf_s("%d", &v);
                    *(a + i * n + j) = v;
                }

                if (s == 0)
                {

                }
            }
        }
    }

    for (i = 0; i < n; i++)  // цикл по строкам
    {
        for (j = 0; j < m; j++)  // цикл по столбцам
        {
            if (*(a + i * n + j) == NO_VALUE) 
            {
                printf_s("    * ");
            }
            else 
            {
                printf("%5d ", *(a + i * n + j)); // 5 знакомест под элемент массива
            }
        }
        printf("\n");
    }
 
    return 0;
}