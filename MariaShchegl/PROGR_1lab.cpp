#include <stdio.h>  
#include <stdlib.h> 
#include<string.h>
#include <locale.h>
#include<stdbool.h>

int main() {

    setlocale(LC_ALL, "rus");
    int n;
    printf("Введите число:");
    scanf_s("%d", &n);
    char ch[20];
    bool flag1 = false;
    bool flag2 = false;
    for (int i = 0; i != strlen(ch) - 1; i++)
    {
        if (ch[i] > ch[i + 1])
            flag1 = true;

        if (ch[i] < ch[i + 1])
            flag2 = true;

        if (flag2 && flag1) break;
    }
    if (flag2 && flag1)
        printf("Все цифры упорядочены не по возрастанию и не по убыванию \n");
    else
        if (!flag1)
            printf("Все цифры упорядочены по возрастанию \n");
        else
            printf("Все цифры упорядочены по убыванию \n ");

}