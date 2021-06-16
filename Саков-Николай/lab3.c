/*3.2 (28).Элементы массива a(n, m) ниже главной диагонали равны нулю.
Выше и на главной диагонали нулевых элементов нет.Строки и
столбцы случайным образом перемешаны.Перестановкой строк и
столбцов восстановить исходный массив.*/
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <math.h>

void RowSwap(int** mass, int count, int row1, int row2);
void ColumnSwap(int** mass, int count, int column1, int column2);
void ShowMass(int** mass, int n, int m);
int main()
{
    setlocale(LC_ALL, "rus");  
    srand(0);
    int n, m;
    printf("Введите размер массива n, m: ");
    scanf_s("%d %d", &n, &m);
    int** mass = (int**)malloc(n * sizeof(int*));
    int** massCopy = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
    {
        mass[i] = (int*)malloc(m * sizeof(int));
        massCopy[i] = (int*)malloc(m * sizeof(int));
    }
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < m; k++)
        {
            if (i > k)
            {
                mass[i][k] = 0;
            }
            else
            {
                mass[i][k] = rand() % 9 + 1;
            }
            massCopy[i][k] = mass[i][k];
            printf("%d  ", mass[i][k]);
        }
        printf("\n");
    }
    printf("\nПеремешиваем строки и столбцы\n");
    for (int i = 0; i < rand() % 100 + 200; i++)
    {
        ColumnSwap(mass, n, rand() % m, rand() % m);
        RowSwap(mass, m, rand() % n, rand() % n);
    }
    printf("\n");
    ShowMass(mass, n, m);
    printf("\nВосстанавливаем массив\n");
    for (int i = 0; i < n; i++)
    {
        int zeroCount = 0;
        for (int k = 0; k < m; k++)
        {
            if (mass[i][k] == 0)
            {
                if (k > zeroCount)
                {
                    ColumnSwap(mass, n, k, zeroCount);
                    printf("\nМеняем местами %d и %d столбцы\n", k, zeroCount);
                    ShowMass(mass, n, m);
                }
                zeroCount++;
            }
        }
        if (i > zeroCount && zeroCount != m)
        {
            RowSwap(mass, m, i, zeroCount);
            printf("\nМеняем местами %d и %d строки\n", i, zeroCount);
            ShowMass(mass, n, m);
            printf("\n");
            i--;
        }
    }
    ShowMass(mass, n, m);
    //===================================================================
    printf("\nВосстановим ненулевые элементы\n");
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < m; k++)
        {
            if (mass[i][k] != 0)
            {
                if (mass[i][k] != massCopy[i][k])
                {
                    for (int l = 0; l < m; l++)
                    {
                        if (mass[i][k] == massCopy[i][l] && mass[i][k] != mass[i][l])
                        {
                            ColumnSwap(mass, n, k, l);
                            printf("\nМеняем местами %d и %d столбцы\n", k, l);
                            ShowMass(mass, n, m);
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        free(mass[i]);
        free(massCopy[i]);
    }
    free(mass);
    free(massCopy);
}

void RowSwap(int** mass, int count, int row1, int row2)
{
    int* temp = malloc(count * sizeof(int));
    for (int i = 0; i < count; i++)
    {
        temp[i] = mass[row1][i];
        mass[row1][i] = mass[row2][i];
        mass[row2][i] = temp[i];
    }
    free(temp);
}

void ColumnSwap(int** mass, int count, int column1, int column2)
{
    int* temp = malloc(count * sizeof(int));
    for (int i = 0; i < count; i++)
    {
        temp[i] = mass[i][column1];
        mass[i][column1] = mass[i][column2];
        mass[i][column2] = temp[i];
    }
    free(temp);
}

void ShowMass(int** mass, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < m; k++)
        {
            printf("%d  ", mass[i][k]);
        }
        printf("\n");
    }
}