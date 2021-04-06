// Lab_4_18_C.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Str_lenght(char str[80]) 
{
    int size = 0;
    for (int i = 0; i < 80; i++) {
        if(str[i] != '\0') size++;
        else break;
    }
    return size;
}
int StoI(long long n, char str[80],int i,int str_size)
{
    int a = str[i] - 48;
    int b = str_size - (i + 1);
    n = n + (a * pow(10, b));
    if (str_size == i+1) return n;
    else
    {
        i++;
        return StoI(n, str, i, str_size);
    }
}
int main()
{
    long long n = 0; int k = 0;
    int temp=1;
    char str[80];
    printf_s("Enter str: ");
    while (temp) {
        gets(str);
        for (int i = 0; i < 80; i++)
        {
            if (str[i] < 48 || str[i]>57) 
            {
                printf_s("Not correct number\n");
                break;
            }
            else 
            {
                temp = 0;
                break;
            }
        }
    }
    int str_size = Str_lenght(str);
    printf_s("This str convert to Int: %d", StoI(n, str, 0, str_size));
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
