// Lab№3.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void SurviveNumberOne(bool check, int mas[], int n, int m, int x, int k, int counter) {
    bool one = true;
    m = 2;
    x = k + m - 1;
    while (one) {
        for (int i = 0; i < n; i++)
        {
            mas[i] = i + 1;
        }
        counter = 0;
        check = false;
        for (int j = 0; j < n; j++)
        {
            if (check) {
                j = 0;
                check = false;
            }
            if (mas[j] == 0) {
                x++;
            }
            if (j == x) {
                mas[j] = 0;
                k = j + 1;
                x = k + m - 1;
                counter++;
            }
            if (n - 1 == j) {
                if (x >= n) {
                    x = abs(x - n);
                    j = 0;
                    k = 0;
                    check = true;
                }
            }
            if (counter == n - 1) {
                break;
            }
        }
        if (counter == n - 1 && mas[0] != 0)
        {
            one = false;
            printf_s("\nNumber one is survive, if m = %d\n", m);

        }
        else m++;
    }
}

void Initialize(bool check, int mas[],int n,int m,int x,int k,int counter) {
    for (int j = 0; j < n; j++)
    {
        if (check) {
            j = 0;
            check = false;
        }
        if (mas[j] == 0) {
            x++;
        }
        if (j == x) {
            mas[j] = 0;
            k = j + 1;
            x = k + m - 1;
            counter++;

        }
        if (n - 1 == j) {
            if (x >= n) {
                x = abs(x - n);
                j = 0;
                k = 0;
                check = true;
            }
        }
        if (counter == n - 1) {
            break;
        }

    }
}
int main() {
    int* mas;
    bool check = true;
    bool choose = true;
    int* mas_c;
    int temp = 0;
    int temp_p = 0;
    int n, m,x, k=0,counter = 0;
    while (choose){
        printf_s("Enter n: ");
        do {
            temp_p = (int)(scanf_s("%d", &n));
            while (getchar() != '\n');
            if (temp_p == 1) break;
            else printf("%s", "Enter is not correct\n");
        } while (temp_p != 1);
        mas = (int*)malloc(n * sizeof(int));
        printf_s("Enter m: ");
        do {
            temp_p = (int)(scanf_s("%d", &m));
            while (getchar() != '\n');
            if (temp_p == 1) break;
            else printf("%s", "Enter is not correct\n");
        } while (temp_p != 1);
        if (n == 1 && m == 1)
        {
            printf_s("Suicide");
            printf_s("\nContinue? 1-yes, 2-no\n");
            scanf_s("%d", &temp);
            if (temp == 2) choose = false;
            else continue;
        }
        for (int i = 0; i < n; i++)
        {
            mas[i] = i + 1;
        }
        x = k + m - 1;
        Initialize(check, mas,n,m,x,k,counter);
        counter = 0;
        for (int i = 0; i < n; i++) {
            if (mas[i] != 0)
                printf_s("The survivor is number %d", mas[i]);
        }
        SurviveNumberOne(check, mas, n, m, x, k, counter);
        printf_s("\nContinue? 1-yes, 2-no\n");
        scanf_s("%d",&temp);
        if (temp == 2) choose = false;
    }
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
