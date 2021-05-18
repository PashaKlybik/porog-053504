//(вариант 13)Дан целочисленный массив a(n, m).Упорядочить по неубыванию
//элементы на главной диагонали и диагоналях, параллельных ей.
//Перестановка элементов допускается только в пределах
//соответствующей диагонали.
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

void Output(int** arr, int onesize)
{
    for (int i = 0; i < onesize; i++)
    {
        for (int j = 0; j < onesize; j++)
        {
            printf("%3d", arr[i][j]);
        }
        printf("\n");
    }
}

int Sort(int** arrr, int onesize)
{
    int tmp, temp, y, i = 0, j = 0;
    for (i = 0; i < onesize - 1; i++) //сортировка элементов гл диагонали и ниже нее
    {
        for (j = 0; j < onesize - 1 - i && j < onesize - 1; j++)
        {
            tmp = j;
            for (y = j + 1; y < onesize - i && y < onesize; y++)
                if (arrr[i + y][y] < arrr[i + tmp][tmp])
                    tmp = y;
            temp = arrr[i + j][j]; 
            arrr[i + j][j] = arrr[i + tmp][tmp]; 
            arrr[i + tmp][tmp] = temp;
        }
    }
    for (i = 1; i < onesize - 1; i++) //сортировка элементов выше гл диагонали
    {
        for (j = 0; j < onesize - 1 && j + i < onesize - 1; j++)
        {
            tmp = j;
            for (y = j + 1; y < onesize && y + i < onesize; y++)
                if (arrr[tmp][i + tmp] > arrr[y][i + y])
                    tmp = y;
            temp = arrr[j][j + i]; 
            arrr[j][j + i] = arrr[tmp][tmp + i]; 
            arrr[tmp][tmp + i] = temp;
        }

    }
    return arrr;
}
int main()
{

    int** b = NULL;  
    int i = 0, j = 0, size = 0;
    int tmp, temp, y;
    system("chcp 1251");
    system("cls");
    printf("Введите размерность матрицы: ");
    scanf_s("%d", &size);
    
    b = (int**)malloc(size * sizeof(int*));

    for (i = 0; i < size; i++)  
    {
        b[i] = (int*)malloc(size * sizeof(int));
        for (j = 0; j < size; j++)  
        {
            b[i][j] = rand() % (100 - 1 + 1) + 1;

        }
    }
    
    Output(b, size);
    Sort(b, size);
    printf("Матрица отсортированных элементов:\n");
    Output(b, size);
    
    for (i = 0; i < size; i++)  
        free(b[i]);   
    free(b);

    return 0;
}