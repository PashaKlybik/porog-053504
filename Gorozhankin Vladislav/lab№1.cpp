#include <stdio.h>
#include<stdlib.h>
#include<cmath>
#include<locale.h>
using namespace std;
/*var.17(Найти и распечатать все натуральные трехзначные числа, равные
сумме кубов своих цифр.*/
int main()
{
    setlocale(LC_ALL, "Russian");
    int i, ed, des, sot;
    printf("Числа: \n");
    for (i = 100; i < 1000; i++)
    {
        ed = i / 100;
        des = (i - ed * 100) / 10;
        sot = i - ed * 100 - des * 10;
        if (i == pow(sot, 3) + pow(des, 3) + pow(ed, 3))
        {
            printf("%d\n", i);
        }
    }
    return 0;
}