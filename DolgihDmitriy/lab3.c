#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include"stdlib.h"
#include"math.h"
// Вывод системы уравнений
void sysout(double** a, double* y, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%lf*x%d", a[i][j] , j);
            if (j < n - 1)
                printf(" + ");
        }
        printf(" = %lf  \n", y[i]);
    }
    return;
}
double* gauss(double** a, double* y, int n)
{
    double* x, max;
    int k, index;
    const double eps = 0.00001;  // точность
    x = malloc(n*sizeof(double));
    k = 0;
    while (k < n)
    {
        // Поиск строки с максимальным a[i][k]
        max = abs(a[k][k]);
        index = k;
        for (int i = k + 1; i < n; i++)
        {
            if (abs(a[i][k]) > max)
            {
                max = abs(a[i][k]);
                index = i;
            }
        }
        // Перестановка строк
        if (max < eps)
        {
            // нет ненулевых диагональных элементов
            printf( "Решение получить невозможно из-за нулевого столбца ");
            printf("%d матрицы A\n", index);
            return 0;
        }
        for (int j = 0; j < n; j++)
        {
            double temp = a[k][j];
            a[k][j] = a[index][j];
            a[index][j] = temp;
        }
        double temp = y[k];
        y[k] = y[index];
        y[index] = temp;
        // Нормализация уравнений
        for (int i = k; i < n; i++)
        {
            double temp = a[i][k];
            if (abs(temp) < eps) continue; // для нулевого коэффициента пропустить
            for (int j = 0; j < n; j++)
                a[i][j] = a[i][j] / temp;
            y[i] = y[i] / temp;
            if (i == k)  continue; // уравнение не вычитать само из себя
            for (int j = 0; j < n; j++)
                a[i][j] = a[i][j] - a[k][j];
            y[i] = y[i] - y[k];
        }
        k++;
    }
    // обратная подстановка
    for (k = n - 1; k >= 0; k--)
    {
        x[k] = y[k];
        for (int i = 0; i < k; i++)
            y[i] = y[i] - a[i][k] * x[k];
    }
    return x;
}
int main()
{
    double** a, * y, * x;
    int n;
    system("chcp 1251");
    system("cls");
    printf( "Введите количество уравнений: ");
    scanf_s("%d", &n); 
    a = malloc(n*sizeof(double*));
    y = malloc(n*sizeof(double));
    for (int i = 0; i < n; i++)
    {
        a[i] = malloc(n*sizeof(double));
        for (int j = 0; j < n; j++)
        {
             printf("a[%d][%d]= ", i, j);
             scanf_s("%lf",& a[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
         printf("y[%d]= ", i);
         scanf_s("%lf",& y[i]);
    }
    sysout(a, y, n);
    x = gauss(a, y, n);
    for (int i = 0; i < n; i++)
         printf("x[%d]=%lf\n", i, x[i]);
    //cin.get(); cin.get();
    free(x);
    for (int i = 0; i < n; i++)
    {
        free(a[i]);
    }
    free(a);
    free(y);
    return 0;
}