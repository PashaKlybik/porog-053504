#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>

using namespace std;

int main()
{
    int n, *len_arifm, *len_geom, ans_arifm = 1, ans_geom = 1, i;
    int* p;
    system("chcp 1251");
    system("cls");
    printf("Введите размер массива: ");
    scanf("%d", &n);
    p = (int*)malloc(n * sizeof(int));
    len_arifm = (int*)malloc(n * sizeof(int));
    len_geom = (int*)malloc(n * sizeof(int));
    len_arifm[1] = 2;
    len_geom[1] = 2;
    for (i = 0; i < n; i++)
    {
        printf("a[%d] = ", i);
        scanf("%d", &p[i]);
    }
    for (i = 2; i < n; ++i)
    {
        if (p[i] - p[i - 1] == p[i - 1] - p[i - 2])
            len_arifm[i] = len_arifm[i - 1] + 1;
        else len_arifm[i] = 2;
        if (p[i - 1] * p[i - 1] == p[i] * p[i - 2])
            len_geom[i] = len_geom[i - 1] + 1;
        else len_geom[i] = 2;
        if (len_arifm[i] > len_arifm[ans_arifm])
            ans_arifm = i;
        if (len_geom[i] > len_geom[ans_geom])
            ans_geom = i;
    }
    printf("Наибольшая арифмитическая прогрессия:\n ");
    for (i = ans_arifm - len_arifm[ans_arifm] + 1; i <= ans_arifm; ++i)
        printf("%d\n", p[i]);
    printf("Длина: %d\n", len_arifm[ans_arifm]);
    printf("Наибольшая геометрическая прогрессия:\n ");
    for (i = ans_geom - len_geom[ans_geom] + 1; i <= ans_geom; ++i)
        printf("%d\n", p[i]);
    printf("Длина: %d\n", len_geom[ans_geom]);
    if (len_arifm[ans_arifm] > len_geom[ans_geom])
        printf("Самая длинная прогрессия арифметическая\n");
    else if (len_arifm[ans_arifm] == len_geom[ans_geom])
        printf("прогрессии равны\n");
    else if (len_arifm[ans_arifm] < len_geom[ans_geom])
        printf("самая длинная прогрессия геометрическая\n");
    free(p);
    free(len_arifm);
    free(len_geom);
    system("pause");
    return 0;
}