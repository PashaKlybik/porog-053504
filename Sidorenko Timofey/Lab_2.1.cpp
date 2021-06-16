// Lab_2.10_C.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <stdio.h>
#include <stdlib.h>

int test_i(int value) {
    int temp;
    do {
        temp = scanf_s("%d", &value);
        while (getchar() != '\n');
        if (temp == 1) break;
        else printf("%s", "Некорректный ввод\n");
    } while (temp != 1);
    return value;
}
long double test_d(long double value) {
    int temp;
    do {
        temp = (int)(scanf_s("%lf", &value));
        while (getchar() != '\n');
        if (temp == 1) break;
        else printf("%s", "Некорректный ввод\n");
    } while (temp != 1);
    return value;
}
double Customs_price(int cost, int year, int volume, int km, double customs_price) {
    if (year < 3) {
        customs_price = 0.6 * volume;   
    }
    if (year >= 3 && year <= 10) {
    
        if (volume < 2500) {
            customs_price = 0.35 * volume;
        }
        if (volume >= 2500) {
            customs_price = 0.6 * volume;
        }
    }
    if (year > 10 && year < 14) {
        customs_price = 0.6 * volume;
    }
    if (year >= 14) {
        customs_price = 2 * volume;
    }
    return  customs_price;
}

int main() {
    system("chcp 1251"); // переходим в консоли на русский язык
    system("cls");
    int change_value = 1;
    printf_s("Для начала работы программы введите цифру, соответсвующему действию\n");
    while (change_value != 0) {
        printf_s("\nВведите 1 для старта программы\n");
        printf_s("\nВведите 2 для вывода информации об авторе\n");
        printf_s("\nВведите 3 для завершения работы\n");
        change_value = test_i(change_value);
        switch (change_value) {
        case 1: {
            double finalprice = 0;
            double rate = 0.5;
            int test_year = 1;
            double customs_price = 0;
            int volume = 0;
            int year = 0, cost = 0, km = 0, distill = 0;
            printf_s("Введите стоимость автомобиля в стране Евросоюза\n");
            cost = test_i(cost);
            printf_s("\nВведите год выпуска автомобиля\n");
            year = 2021 - test_i(year);
            while(test_year != 0)
            {
                if (year < 0) {
                    printf_s("\nНеверный ввод\n");
                    year = test_i(year);
                }
                else test_year = 0;
            }
            printf_s("\nВведите объём двигателя(в см^3)\n");
            volume = test_i(volume);
            printf_s("\nВведите расстояние прогона(км)\n");
            km = test_i(km);
            printf_s("%d", km);
            distill = 0.5 * km;
            printf("\nCтоимость перегона: %d евро", distill);
            customs_price = Customs_price(cost, year, volume, km, rate, customs_price);
            printf("\nCтоимость растаможки: %.0lf евро", customs_price);
            finalprice = cost + distill + customs_price;
            printf("\nИтоговая стоимость автомобиля: %.0lf евро\n", finalprice);
        }break;
        case 2: printf("\nПрограмму разработал студент гр 053504 Сидоренко Тимофей Сергеевич\n"); break;
        case 3: change_value = 0;
        }
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
